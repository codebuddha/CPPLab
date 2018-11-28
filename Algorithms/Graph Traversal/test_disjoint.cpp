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
int maxrank = 0;
struct node{
    int rank, data, pidx, idx;
    void display()
    {
        printf("rank %d idx %d par %d", rank, idx, pidx);
        if(rank == 1) cout << " *";
        cout << "\n";
    }
};
void makeset(node &a)
{
    a.pidx = a.idx;
    a.rank = 1;
}
int findset(node &a, vector<node> &vec)
{
    node tmp = a;
    while(tmp.pidx != tmp.idx)
        tmp = vec[tmp.pidx];
    return tmp.idx;
}
void compress_children_path(vector<node> &vec, int src, int dst)
{
    for(auto &i: vec)
        if(i.pidx == src)
        {
            i.pidx = dst;
            // printf("changing parent of %d from %d to %d\n", i.idx, src, dst);
        }   
}
bool unionset(node &a, node &b, vector<node> &vec)
{
    int pa = findset(a, vec), pb = findset(b, vec);
    if(pa == pb)
        return false;
    if(vec[pa].rank >= vec[pb].rank)
    {
        b.pidx = pa;
        b.rank = 0;
        vec[pa].rank = 1;
        compress_children_path(vec, pb, pa);
    }
    else
    {
        a.pidx = pb;
        a.rank = 0;
        vec[pb].rank = 1;
        compress_children_path(vec, pa, pb);
    } 
    return true;  
}
bool is_cycle(vector<node> &vec, vector<std::pair<int,int>> &edges)
{
    bool flag = true;
    for(auto &i:edges)
    {
        // cout << i.first << " U " << i.second << "\n";
        flag = unionset(vec[i.first], vec[i.second], vec);
        if(!flag)   
            break;
    }
    return !flag;
}
int count_cycles(vector<node> &vec, vector<std::pair<int,int>> &edges)
{
    int cnt=0;
    for(auto &i:edges)
    {
        // cout << "union of " << i.first << " and " << i.second << "\n";
        if(!unionset(vec[i.first], vec[i.second], vec))
            cnt++;
    }
    return cnt;   
}
int count_components(vector<node> &vec, vector<std::pair<int,int>> &edges)
{
    bool flag = true;
    int cnt = 0;
    for(auto &i:edges)
    {
        cnt = 0;
        // cout << i.first << " U " << i.second << " ";
        flag = unionset(vec[i.first], vec[i.second], vec);
        for(auto &i: vec)
            if(i.rank == 1)
                cnt++;
        cout << cnt;
        if(!flag)   
            cout << " cycle";
        cout << "\n";
    }
    return cnt;  
}
int main()
{
    int n, e;
    node vt;
    // cin >> n >> e;
    n = 8; e = 10;
    vector<node> vec;
    vector<std::pair<int, int>> edges;
    for(int i=0; i<n; i++)
    {
        vt.data = i; vt.idx = i; vt.rank = 1;
        makeset(vt);
        vec.push_back(vt);
    }
    edges.push_back({0,1});
    edges.push_back({2,3});
    edges.push_back({0,2});
    edges.push_back({1,2});
    edges.push_back({2,7});
    edges.push_back({4,5});
    edges.push_back({5,6});
    edges.push_back({4,6});
    edges.push_back({3,7});
    edges.push_back({2,4});

    for(auto &i: vec)
        makeset(i);
    cout << "# components " << count_components(vec, edges) << "\n";
    for(auto &i: vec)
        makeset(i);
    cout << "# cycles " << count_cycles(vec, edges) << "\n";
}