#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

vector<vector<int>>g;
vector<int>visited;
vector<int>dist;

void sssp(int src,int n){
    visited.assign(n+1,0);
    dist.assign(n+1,INF);
    queue<int>q;
    
    dist[src]=0;
    q.push(src);

    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(visited[x]) continue;
        visited[x]=1;
        for(auto v:g[x]){
            if(dist[v]>dist[x]+1){
                dist[v]=dist[x]+1;
                q.push(v);
            }
        }
    }
}

void solve(){
    int n,e;
    cin>>n>>e;
    g.resize(n+1);
    for(int i=1;i<=e;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int src;
    cin>>src;
    sssp(src,n);

    cout<<"The distance from single source is\n";
    for(int i=1;i<=n;i++){
        cout<<i<<":"<<dist[i]<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}