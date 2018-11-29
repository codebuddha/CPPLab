/*
 * min_cost_2d_path.cpp
 * Created on: 29-11-2018
 * Author: Abhirup
*/
#include<vector>
#include<iostream>
#include<cmath>
using std::vector;
using std::cin;
using std::cout;
using vi = vector<int>;
using vvi = vector<vi>;
vvi calc_path(vvi &mat)
{
    vvi arr(mat.size(), vi(mat[0].size(), 0));
    arr[0][0] = mat[0][0];
    
    //1st row and 1st column
    for(int i=1; i<mat.size(); i++)
        arr[i][0] = arr[i-1][0] + mat[i][0];
    for(int j=1; j<mat[0].size(); j++)
        arr[0][j] = arr[0][j-1] + mat[0][j];

    //rest
    for(int i=1; i<mat.size(); i++)
    {
        for(int j=1; j<mat[0].size(); j++)
            arr[i][j] = mat[i][j] + std::min(arr[i-1][j], arr[i][j-1]);
    }
    cout << "minimum paths are:\n";
    for(auto &i: arr)
    {
        for(auto &j: i)
            std::cout << j << ' ';
        std::cout << '\n';
    }
    return arr;
}
int main()
{
    vvi v = {
        {1,3,5,8}, 
        {4,2,1,7},
        {4,3,2,3}
    };
    cout << "2d map:\n";
    for(auto &i: v)
    {
        for(auto &j: i)
            std::cout << j << ' ';
        std::cout << '\n';
    }
    cout << "\n";
    auto paths = calc_path(v);
}
// 2d map:
// 1 3 5 8
// 4 2 1 7
// 4 3 2 3

// minimum paths are:
// 1 4 9 17
// 5 6 7 14
// 9 9 9 12