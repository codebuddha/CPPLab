#include <iostream>
#include <vector>
#include <queue>
using vvi = std::vector<std::vector<int>>;
int main()
{
    int n;
    std::cin >> n;
    vvi adj (n); int x,y;
    do{
        std::cin >> x >> y;
        adj[x].push_back(y); 
    }while(x>=0 && y>=0);
    std::queue<int> Q;
    std::vector<bool> visited(n);
    Q.push(0); visited[0] = true;
    while(!Q.empty())
    {
        int x = Q.front();
        std::cout << x << " -> ";
        Q.pop();
        visited[x] = true;
        for(auto &j:adj[x])
            if(!visited[j])
                Q.push(j);
    }
    std::cout << "Fin.\n";
}