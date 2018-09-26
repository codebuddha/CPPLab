#include <iostream>
#include <vector>
#include <stack>
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
    std::stack<int> S;
    std::vector<bool> visited(n);
    S.push(0); visited[0] = true;
    while(!S.empty())
    {
        int x = S.top();
        std::cout  << x << " -> ";
        S.pop();
        for(auto&j:adj[x])
            if(!visited[j])
            {
                visited[j] = true;
                S.push(j);
            }
    }
    std::cout << "Fin.\n";
}