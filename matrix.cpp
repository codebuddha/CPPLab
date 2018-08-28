#include <iostream>
#include <vector>
#include <tuple>

template<typename T>
class matrix
{   public:
    int n, m;
    std::vector<std::vector<T>> arr;
    matrix(int i, int j)
    {
        arr.resize(i, std::vector<T>(j));
        n = i; m = j;
    }
    
    matrix operator+(matrix a)
    {
        if(a.n != n && a.m != m)
        {
            std::cout << "type mismatch" << "\n";
            return a;
        }
        matrix res(n,m);
        for(int i=0 ;i<n; i++)
            for(int j=0; j<m; j++)
                res.arr[i][j] = arr[i][j] + a.arr[i][j];
        return res;
    }
};

int main()
{
    int m,n;
    std::cin >> m >> n;
    matrix<int> M(m,n);
    for(auto &i: M.arr)
        for(auto &j: i)
            std::cin >> j;
    std::cout << "reached\n";
    matrix<int> N(m,n);
    for(auto &i: N.arr)
        for(auto &j: i)
            std::cin >> j;
    

    matrix<int> R = M + N;

    for(auto &i : R.arr)
        for(auto &j : i)
            std::cout << j << " ";
    return 0;
}