#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node,
         vector<vector<int>>& adj,
         vector<int>& vis,
         vector<int>& path)
         {
    vis[node]=1;
    path[node]=1;

    for(int x:adj[node])
    {
        if(!vis[x])
        {
            if(dfs(x,adj,vis,path))
                return true;
        }
        else if(path[x])
        {
            return true;
        }
    }
    path[node]=0;

    return false;
}
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
    }

    vector<int> vis(n,0);
    vector<int> path(n,0);

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,adj,vis,path))
            {
                cout<<"Cycle Exists";
                return 0;
            }
        }
    }

    cout<<"No Cycle Exists";
}