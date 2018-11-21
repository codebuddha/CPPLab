#include <iostream>
#include <vector>
#include <bitset>
using std::vector;
using std::cout;
using std::cin;
int MAX=9999;
int tsp(vector<vector<int>> &adjm, int pos, int visited, vector<vector<int>> &state)
{
    if(visited == (1<<adjm.size())-1)//covered all vertices
        return adjm[pos][0];//back to start, ie, 0
    if(state[pos][visited] != MAX)//already visited position
        return state[pos][visited];
    for(int i=0; i<adjm.size(); i++)
    {
        if(i==pos // same position  
        || (visited & (1<<i)))// or, already visited state
            continue;
        
        int distance = adjm[pos][i] + tsp(adjm, i, visited | (1<<i), state);
        if(distance < state[pos][visited])
            {
                state[pos][visited] = distance;
                cout << "changed at pos:" << pos << " mask:" << std::bitset<8>(visited) << '\n';
            }
    }
    return state[pos][visited];
}
int main()
{
    int n;
    vector<vector<int>> adjm = {
        // {0, 1, 15, 6},
        // {2, 0, 7, 3},
        // {9, 6, 0, 12},
        // {10, 4, 8, 0}
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
    }; 
    n = adjm.size();
    vector<vector<int>> state(adjm.size());
    for(auto &parents: state)
        parents = vector<int> ((1<<adjm.size())-1, MAX);

    cout << tsp(adjm, 0, 1, state) <<"\n";
}