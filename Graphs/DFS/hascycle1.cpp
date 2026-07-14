#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>>g;
vector<int>visited;

bool dfs(int src, int parent){
    visited[src]=1;

    for(auto v:g[src]){
       int x=v.second;
       if(!visited[x]){
        if(dfs(x,src))
          return true;
       }
       else if(visited[x]==1 && x!=parent){
         return true;
       }
    }

    return false;
}

bool hasCycle(int n){
   for(int i=1;i<=n;i++){
    if(!visited[i]){
        if(dfs(i,-1))
          return true;
    }
   }
   return false;
}

void solve(){
    int n,e;
    cin>>n>>e;
    g.resize(n+1);
    visited.assign(n+1,0);

    for(int i=1;i<=e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({w,b});
        g[b].push_back({w,a});
    }

    if (hasCycle(n)) cout<<"Cycle present\n";
    else cout<<"Cycle not there\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}