#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;

    vector<vector<pair<int,int>>> adj(n);

    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int vis[100]={0};

    priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
    > pq;

    pq.push({0,0});

    int cost=0;

    while(!pq.empty())
    {
        int w=pq.top().first;
        int node=pq.top().second;

        pq.pop();

        if(vis[node])
            continue;

        vis[node]=1;

        cost+=w;

        for(auto x:adj[node])
        {
            int v=x.first;
            int wt=x.second;

            if(!vis[v])
            {
                pq.push({wt,v});
            }
        }
    }

    cout<<"Minimum Cost = "<<cost;
}