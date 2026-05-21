#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;

    vector<vector<int>> adj(n);

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n,-1);
    queue<int> q;
    q.push(0);
    color[0]=0;
     
    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        for(int x:adj[node])
        {
            if(color[x]==-1)
            {
                color[x]=1-color[node];
                q.push(x);
            }
            else if(color[x]==color[node])
            {
                cout<<"Not Bipartite";
                return 0;
            }
        }
    }

    cout<<"Yes Bipartite";
}