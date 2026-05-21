#include<iostream>
#include<vector>
using namespace std;

int solve(int src,
          int dest,
          int k,
          vector<vector<pair<int,int>>>& adj)
{
    if(k==0 && src==dest)
        return 0;

    if(k==0)
        return 9999;

    int ans=9999;

    for(auto x:adj[src])
    {
        int v=x.first;
        int w=x.second;

        int temp=solve(v,dest,k-1,adj);

        if(temp!=9999)
        {
            ans=min(ans,w+temp);
        }
    }

    return ans;
}

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
    }

    int src,dest,k;

    cin>>src>>dest>>k;

    int ans=solve(src,dest,k,adj);

    if(ans==9999)
        cout<<"No Path";
    else
        cout<<ans;
}