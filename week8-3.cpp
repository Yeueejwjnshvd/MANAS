#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge
{
    int u,v,w;
};

bool cmp(Edge a,Edge b)
{
    return a.w>b.w;
}

int find(int x,int parent[])
{
    if(parent[x]==x)
        return x;

    return parent[x]=find(parent[x],parent);
}

int main()
{
    int n,e;
    cin>>n>>e;

    vector<Edge> edges;

    int parent[100];

    for(int i=0;i<n;i++)
        parent[i]=i;

    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        edges.push_back({u,v,w});
    }

    sort(edges.begin(),edges.end(),cmp);

    int cost=0;

    for(auto x:edges)
    {
        int a=find(x.u,parent);
        int b=find(x.v,parent);

        if(a!=b)
        {
            cost+=x.w;

            parent[a]=b;
        }
    }

    cout<<"Maximum Cost = "<<cost;
}