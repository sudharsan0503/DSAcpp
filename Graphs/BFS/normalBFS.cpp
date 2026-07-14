#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> dist;
vector<int> visited;

void bfs(int src,int n){
    visited.assign(n+1,0);
    dist.assign(n+1,-1);

    queue<int> q;

    dist[src]=0;
    visited[src]=1;
    q.push(src);

    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(auto neigh:g[x]){
            if(!visited[neigh]){
                visited[neigh]=1;
                dist[neigh]=dist[x]+1;
                q.push(neigh);
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

    bfs(src,n);

    cout<<"Distance:\n";
    for(int i=1;i<=n;i++){
        cout<<i<<":"<<dist[i]<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}