#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>>g;
vector<int>color;

bool dfs(int node,int c){
    color[node]=c;

    for(auto x:g[node]){
       int v=x.second;
       if(color[v]==-1){
        if(dfs(v,!c)==false)
          return false;
       }
       else if(color[v]==c)//same color also false
          return false;
    }
    return true;
}

bool bipartite(int n){
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(dfs(i,0)==false) return false;
        }
    }
    return true;
}

void solve(){
    int n,e;
    cin>>n>>e;
    g.resize(n+1);
    color.assign(n+1,-1);
    
    for(int i=1;i<=e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({w,b});
        g[b].push_back({w,a});
    }

    bool flag=bipartite(n);

    flag?cout<<"The g is bipartite\n":cout<<"Not bipartite\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}