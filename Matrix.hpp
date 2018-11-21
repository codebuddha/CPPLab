#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::move;

template<typename T>
class Matrix{
public:
    vector<vector<T>> mat;
    int m, n;
    Matrix(int m, int n, T x)
    {
        this->m = m; this->n = n;
        mat.resize(m, vector<T>(n, x));
    }
    Matrix operator+(Matrix &a)
    {
        Matrix<T> c (mat.size(), mat[0].size(), 0);
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat[0].size(); j++)
                c.mat[i][j] = mat[i][j] + a.mat[i][j];
        return c;
    }
    Matrix operator-(Matrix &a)
    {
        Matrix<T> c (mat.size(), mat[0].size(), 0);
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat[0].size(); j++)
                c.mat[i][j] = mat[i][j] + a.mat[i][j];
        return c;
    }
    Matrix operator()(int r1, int r2, int c1, int c2)
    {
        Matrix<T> c (r2-r1, c2-c1, 0);
        for(int i=r1; i<r2; i++)
            for(int j=c1; j<c2; j++)
                c.mat[i-r1][j-c1] = mat[i][j];
        return c;
    }
    void assign(Matrix &&a)
    {
        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat[0].size(); j++)
                mat[i][j] = a.mat[i][j];
    }
    void assign(Matrix &&a, int r1, int r2, int c1, int c2)
    {
        for(int i=0; i<r2-r1; i++)
            for(int j=0; j<c2-c1; j++)
                mat[i+r1][j+c1] = a.mat[i][j];
    }
    void show()
    {
        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[0].size(); j++)
                cout << mat[i][j] << " ";
            cout << '\n';
        }
    }
    Matrix topleft_pad_even(int t, T x)
    {
        Matrix<T> c (m + t, n + t, x);
        c.assign(move(*this), t, c.m, t, c.n);
        return c;
    }
};
int main()
{
    Matrix<int> 
        a(5, 5, 1),
    // a.show();
        b(5, 5, 3);
    Matrix<int> c = a + b;
    c.show();
    cout << '\n';
    Matrix<int> d = c(1, 3, 1, 3);
    d.show();
    cout << '\n';
    a.assign(move(d), 2, 4, 1, 3);
    a.show();
    cout << '\n';
    d = a.topleft_pad_even(2, 0);
    d.show();
    cout << '\n';
}
