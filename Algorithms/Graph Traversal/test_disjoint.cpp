/*
 * test_disjoint.cpp
 * Created on: 28-11-2018
 * Author: Abhirup
*/
#include<iostream>
#include<stdio.h>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
struct node{
    int rank, data, pidx, idx;
    void display()
    {
        printf("rank %d idx %d par %d\n", rank, idx, pidx);
    }
};
void makeset(node &a)
{
    a.pidx = a.idx;
}
int findset(node &a, vector<node> &vec)
{
    node tmp = a;
    while(tmp.pidx != tmp.idx)
        tmp = vec[tmp.pidx];
    return tmp.idx;
}
void unionset(node &a, node &b, vector<node> &vec)
{
    int pa = findset(a, vec), pb = findset(b, vec);
    if(pa == pb)
    {
        cout << "same parent.\n";
        return;
    }
    if(a.rank >= b.rank)
    {
        b.pidx = pa;
        b.rank = 0;
        vec[pa].rank = 1;
    }
    else
    {
        a.pidx = pb;
        a.rank = 0;
        vec[pb].rank = 1;
    }   
}
int main()
{
    int n, e;
    node vt;
    // cin >> n >> e;
    n = 3; e = 3;
    vector<node> vec;
    vector<std::pair<int, int>> edges;
    for(int i=0; i<n; i++)
    {
        vt.data = i; vt.idx = i; 
        makeset(vt);
        vec.push_back(vt);
    }
    edges.push_back({1,2});
    edges.push_back({1,0});
    edges.push_back({0,2});

    for(auto &i: vec)
    {
        i.display();
    }
    std::cout << '\n';

    for(auto &i:edges)
    {
        cout << "union of " << i.first << " and " << i.second << "\n";
        unionset(vec[i.first], vec[i.second], vec);
        for(auto &i: vec)
        {
            i.display();
        }
        std::cout << '\n';
    }

    
}