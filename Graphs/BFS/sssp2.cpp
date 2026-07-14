//same as ssp1, but instead of 1, we get weight as input and do
#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

vector<vector<pair<int,int>>>g;
vector<int>visited;
vector<int>dist;

void sssp(int src,int n){
    visited.assign(n+1,0);
    dist.assign(n+1,INF);

    queue<int> q;

    dist[src]=0;
    q.push(src);

    while(!q.empty()){
        int x=q.front();
        q.pop();

        if(visited[x]) continue;
        visited[x]=1;

        for(auto v:g[x]){
            int node = v.first;
            int wt = v.second;

            if(dist[node] > dist[x] + wt){
                dist[node] = dist[x] + wt;   // weight instead of +1
                q.push(node);                // push node
            }
        }
    }
}


void solve(){
    int n,e;
    cin>>n>>e;
    g.resize(n+1);
    for(int i=1;i<=e;i++){
        int a,b,w; //w is weight
        cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
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