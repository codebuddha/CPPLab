/*
 * dijkstra.cpp
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

void dijkstra(vector<vector<pair<int,int>>> &alist, int s)
{
    std::priority_queue< pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> pq;
    vi dist(alist.size(), INT16_MAX);
    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for(auto &j: alist[u])
        {
            int w = j.second, v = j.first;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(auto &i: dist)
        std::cout << i << ' ';
    std::cout << '\n';
}
int main()
{
    int n = 5, e = 7;
    vector<vector<pair<int,int>>> alist(n);
	// 0 1 1
	// 0 4 7
	// 1 2 3
	// 1 3 4
	// 1 4 5
	// 2 3 6
	// 3 4 8
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
	dijkstra(alist, 2);
}