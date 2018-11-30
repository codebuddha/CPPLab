/*
 * prim.cpp
 * Created on: 01-12-2018
 * Author: Abhirup
*/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using std::vector;
using std::cin;
using std::cout;
using vi = vector<int>;
using std::pair;

void prim(vector<vector<pair<int,int>>> &alist, int s)
{
    std::priority_queue< pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> pq;
    vi parent(alist.size(), -1);
    vi dist(alist.size(), INT16_MAX);
    vector<bool> isPresent (alist.size(), false);
    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        isPresent[u] = true;
        for(auto &j: alist[u])
        {
            int w = j.second, v = j.first;
            if(dist[v] > w && !isPresent[v])
            {
                dist[v] = w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
        for(int i=0; i<isPresent.size(); i++)
            if(isPresent[i]) cout << i << " ";
        cout << "**\n";
    }
    cout << "parents:\n";
    for(int i=0; i<parent.size(); i++)
        std::cout << i << "(" << parent[i] << ") ";
    std::cout << '\n';
    cout << "mst paths:\n";
    for(auto &i: dist)
        std::cout << i << ' ';
    std::cout << '\n';
}
int main()
{
    int n = 9, e = 14;
    vector<vector<pair<int,int>>> alist(n);
    // 0 1 4 
    // 0 7 8 
    // 1 7 11 
    // 6 7 1 
    // 7 8 7 
    // 1 2 8 
    // 2 8 2 
    // 6 8 6  
    // 2 5 4 
    // 5 6 2  
    // 2 3 7 
    // 3 5 14 
    // 5 4 10 
    // 3 4 9 
    for(int i=0; i<e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        alist[x].push_back({y, w});
        alist[y].push_back({x, w});
    }
    cout << "graph:\n";
    for(auto &i: alist)
    {
        for(auto &j: i)
            std::cout << j.first << "(" << j.second << ") ";
        std::cout << '\n';
    }
    cout << "shortest paths:\n";
	prim(alist, 0);
}
// parents:
// 0(-1) 1(0) 2(1) 3(2) 4(3) 5(2) 6(5) 7(6) 8(2)
// mst paths:
// 0 4 8 7 9 4 2 1 2