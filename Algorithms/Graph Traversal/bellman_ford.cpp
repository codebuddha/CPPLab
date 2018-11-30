
/*
 * bellman_ford.cpp
 * Created on: 30-11-2018
 * Author: Abhirup
*/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>

using std::vector;
using std::cin;
using std::cout;
using vi = vector<int>;
using vvi = vector<vi>;
int maxval = 999;
vi shortest_path(vvi &mat, vvi &list, int s)
{
    vi arr(mat.size(), maxval);
    arr[s] = 0;

    int iter = 0;
    while(iter < mat.size()-1)
    {
        cout << "iteration " << iter << "\n";
        for(int i=0; i<list.size(); i++)
        {
            for(auto &j: list[i])
            {
                arr[j] = std::min(arr[j], arr[i] + mat[i][j]);
            }
        }
        for(auto &i: arr)
            std::cout << i << ' ';
        std::cout << '\n';
        iter++;
    }
    return arr;
    // arr[i] = std::min(arr[i], arr[iter] + mat[iter][i]);
}
int main()
{
    int n, e;
    n = 5; e = 8;
    vvi alist(n), amat(n, vi(n,maxval));
    for(int i=0; i<e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        alist[x].push_back(y);
        amat[x][y] = w;
    }
    shortest_path(amat, alist, 0);
    
}
// 0 1 -1
// 0 2 4
// 1 2 3
// 1 3 2
// 1 4 2
// 3 2 5
// 3 1 1
// 4 3 -3
