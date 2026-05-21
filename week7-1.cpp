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

    int src;
    cin>>src;

    vector<int> dist(n,9999);

    priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
    > pq;
    

    dist[src]=0;

    pq.push({0,src});

    while(!pq.empty())
    {
        int d=pq.top().first;
        int node=pq.top().second;

        pq.pop();

        for(auto x:adj[node])
        {
            int v=x.first;
            int w=x.second;

            if(dist[node]+w < dist[v])
            {
                dist[v]=dist[node]+w;

                pq.push({dist[v],v});
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<"Distance from "
            <<src<<" to "
            <<i<<" = "
            <<dist[i]<<endl;
    }
}