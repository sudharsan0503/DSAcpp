#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

vector<vector<int>>edges;
vector<int>dist;

void bellmanford(int src,int n){
    dist[src]=0;
    for(int i=1;i<=n-1;i++){
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            if(dist[u]!=INF && dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
            }
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    edges.resize(n+1);
    dist.assign(n+1,INF);
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges.push_back({a,b,w});
        edges.push_back({b,a,w});
    }

    int src;
    cin>>src;
    bellmanford(src,n);

    for(int i=1;i<=n;i++){
        cout<<i<<":"<<dist[i]<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}