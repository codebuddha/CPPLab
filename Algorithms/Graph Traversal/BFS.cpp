/*
 * BFS.cpp
 * Created on: 29-11-2018
 * Author: Abhirup
*/
#include<vector>
#include<iostream>
#include<cmath>
#include<queue>
using std::vector;
using std::cin;
using std::cout;
using vi = vector<int>;
using vvi = vector<vi>;
void bfs(vvi &list, int s)
{
    std::queue<int> Q;
    vector<int> visited (list.size(), 0);
    Q.push(s);
    visited[s] = 1;

    while(!Q.empty())
    {
        int x = Q.front();
        cout << x << " -> ";
        Q.pop();
        for(auto &j: list[x])
        {
            if(!visited[j])
            {
                visited[j] = 1;
                Q.push(j);
            }
        }
    }
    cout << "Fin!\n";
}
int main()
{
    int n,e;
    n = 8, e = 10;
    vvi edges(n);
    for(int i=0; i<e; i++)
    {
        int x,y;
        cin >> x >> y;
        edges[x].push_back(y);
    }
    bfs(edges, 0);
}
// 0 1
// 2 3
// 0 2
// 1 2
// 2 7
// 4 5
// 5 6
// 4 6
// 3 7
// 2 4