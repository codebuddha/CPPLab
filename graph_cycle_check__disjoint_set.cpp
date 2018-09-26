#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct Node{
    int num, rank = 0;
    struct Node *p = this;
};
int main()
{
    int n,m;
    cin >> n;
    vector<Node> v(n);
    vector<pair<int,int>> edges;
    for(int i=1; i<=n; i++)
    {
        v[i-1].num = i;
    }
    vector<vector<int>> adj(n);
    cout << "Enter edges in order\nEnter 0 to finish";
    do{
        int x,y; cin >> x >> y;
        if(x == 0 || y == 0) break;
        edges.push_back(make_pair(x-1,y-1));
    }while(true);

    m = edges.size();
    int cycle=0;
    for(auto &i:edges)
    {
        auto &first = v[i.first].p; auto &second = v[i.second].p;
        if(first == second)
        {
            cout << "Cycle detected\n";
            cycle++;
        }
        if(first->rank == second->rank)
        {
            second->p = first;
            v[i.second].p = first;
            first->rank ++;
        }
        else
        {
            if(first->rank < second->rank)
            {
                first->p = second;
                v[i.first].p = second;
                first->rank = 0;
            }    
            else
            {
                second->p = first;
                v[i.second].p = first;
                second->rank = 0;
            }    
        }
        cout << "-----------------------------------------------\n";
        cout << "edge: " << i.first+1 <<" " <<  i.second+1 << "\n";
        cout << "vertex" << "\t" << "rank" << "\t" << "parent" << "\n";
        for(auto &i:v)
        {
            cout << i.num << "\t" << i.rank << "\t" << i.p->num << "\n";
        }
        cout << "-----------------------------------------------\n";
    }

    cout << cycle << endl;
    return 0;
}