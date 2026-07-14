#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

vector<int>visited;
vector<vector<pair<int,int>>>g;
vector<int>dist;

void dijikstra(int src,int n){
    visited.assign(n+1,0);
    dist.assign(n+1,INF);

    priority_queue<pair<int,int>> pq;

    dist[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        int x = pq.top().second;
        pq.pop();

        if(visited[x]) continue;
        visited[x]=1;

        for(auto v:g[x]){
            int neigh=v.first;
            int cost=v.second;

            if(dist[neigh] > dist[x] + cost){
                dist[neigh] = dist[x] + cost;
                pq.push({-dist[neigh], neigh});
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
  dijikstra(src,n);
  
  cout<<"Dijikstra distance\n:";
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