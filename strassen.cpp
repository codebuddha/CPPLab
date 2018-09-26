#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
template<typename T>
class Matrix
{   public:
    int n, m;
    std::vector<std::vector<T>> arr;
    Matrix(int i)
    {
        n = i; m = i;
        arr.resize(n, std::vector<T>(n));
    }
    Matrix(int i, int j, T x)
    {
        n = i; m = j;
        arr.resize(n, std::vector<T>(m, x));
    }
    void size_update()
    {
        n = arr.size(); m = arr[0].size();
    }
    Matrix operator+(Matrix &a)
    {
        Matrix<T> tmp(n, m, 0);
        for(int i=0 ;i<n; i++)
            for(int j=0; j<m; j++)
                tmp.arr[i][j] = arr[i][j] + a.arr[i][j];
        return tmp;
    }
    Matrix operator-(Matrix &a)
    {
        Matrix<T> tmp(n, m, 0);
        for(int i=0 ;i<n; i++)
            for(int j=0; j<m; j++)
                tmp.arr[i][j] = arr[i][j] - a.arr[i][j];
        return tmp;
    }
    Matrix operator()(int r1, int r2, int c1, int c2)
    {
        Matrix<T> tmp (r2-r1, c2-c1, 0);
        for(int i = r1; i < r2; i++)
        {
            for(int j = c1; j < c2; j++)
                tmp.arr[i-r1][j-c1] = arr[i][j];
        }
        return tmp;
    }
    void assign(Matrix &&a, int r1, int r2, int c1, int c2)
    {
        for(int i=0; i<a.n; i++)
            for(int j=0; j<a.m; j++)
                arr[i+r1][j+c1] = a.arr[i][j];
    }
    void assign(Matrix &&a)
    {
        for(int i=0; i<a.n; i++)
            for(int j=0; j<a.m; j++)
                arr[i][j] = a.arr[i][j];
    }
    void display()
    {
        for(auto i: arr)
        {
            for(auto j: i)
                cout << j << "\t";
        cout << "\n";
        }     
        cout << "\n";
    }
    Matrix matmul(Matrix &a);
};
template<typename T>
Matrix<T> pad_even(Matrix<T> &x, int t)
{
    Matrix<T> tmp(x.n + t);
    tmp.assign(move(x), t, x.n, t, x.n);
    return tmp;
}
template<typename T>
Matrix<T> pad_odd(Matrix<T> &x, int t)
{
    auto tmp = x(t, x.n, t, x.n);
    return tmp;
}
template<typename T>
Matrix<T> matmul(Matrix<T> &&X, Matrix<T> &&Y)
{ 
    Matrix<T> Z (X.n);
    int n = X.n;
    if(X.n == 2 && Y.n == 2)
    {
        Z.arr[0][0] = X.arr[0][0]*Y.arr[0][0] + X.arr[0][1]*Y.arr[1][0];
        Z.arr[0][1] = X.arr[0][0]*Y.arr[0][1] + X.arr[0][1]*Y.arr[1][1];
        Z.arr[1][0] = X.arr[1][0]*Y.arr[0][0] + X.arr[1][1]*Y.arr[1][0];
        Z.arr[1][1] = X.arr[1][0]*Y.arr[0][1] + X.arr[1][1]*Y.arr[1][1];
        return Z;
    }
    Matrix<T> A(n/2), B(n/2), C(n/2), D(n/2), E(n/2), F(n/2), G(n/2), H(n/2);
    A.assign(X(0,n/2,0,n/2)); B.assign(X(0,n/2,n/2,n)); 
    C.assign(X(n/2,n,0,n/2)); D.assign(X(n/2,n,n/2,n));
    E.assign(Y(0,n/2,0,n/2)); F.assign(Y(0,n/2,n/2,n)); 
    G.assign(Y(n/2,n,0,n/2)); H.assign(Y(n/2,n,n/2,n));
    auto p1 = matmul(move(A), F-H), p2 = matmul(A+B, move(H)), p3 = matmul(C+D, move(E)), p4 = matmul(move(D), G-E);
    auto p5 = matmul(A+D, E+H), p6 = matmul(B-D, G+H), p7 = matmul(A-C, E+F);

    Z.assign(p5+p4-p2+p6, 0, n/2, 0, n/2);
    Z.assign(p1+p2, 0, n/2, n/2, n);
    Z.assign(p3+p4, n/2, n, 0, n/2);
    Z.assign(p1+p5-p3-p7, n/2, n, n/2, n);
    return Z;
}
int main()
{
    int n;
    cin >> n;
    Matrix<int> m1 (n, n, 0); 
    for(int i = 0; i < n*n; i++)
        cin >> m1.arr[i/n][i%n];
    Matrix<int> m2 (n, n, 0); 
    for(int i = 0; i < n*n; i++)
        cin >> m2.arr[i/n][i%n];

    int t = pow(2, ceil(log2(m1.n))) - m1.n;
    m1 = pad_even(m1, t);
    m2 = pad_even(m2, t);
    auto res = matmul(move(m1), move(m2));
    res = pad_odd(res, t);
    cout << "Result=\n";res.display();
}
