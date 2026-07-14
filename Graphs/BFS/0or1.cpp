#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

vector<vector<pair<int,int>>>g;
vector<int>dist;
vector<int>visited;

void zor1(int src,int n){
    visited.assign(n+1,0);
    dist.assign(n+1,INF);
    deque<int>q;

    dist[src]=0;
    q.push_front(src);
    
    while(!q.empty()){
       int x= q.front();
       q.pop_front();

       if(visited[x]) continue;
       visited[x]=1;

       for(auto v:g[x]){
        int neigh=v.first;
        int cost=v.second;
        if(dist[neigh]>dist[x]+cost){
            dist[neigh]=dist[x]+cost;
            if(cost==0) q.push_front(neigh);
            else if(cost==1) q.push_back(neigh);
        }
       }
    }
}

void solve(){
    int n,e;
    cin>>n>>e;
    g.resize(n+1);
    for(int i=1;i<=e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    int src;
    cin>>src;
    zor1(src,n);

    cout<<"Distance:\n";
    for(int i=1;i<=n;i++){
        cout<<i<<":"<<dist[i]<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}