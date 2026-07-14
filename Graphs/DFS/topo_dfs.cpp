#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<int>vis;

vector<int>topo;

void dfs(int node){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
    topo.push_back(node);
}

int dp[100100];//longest path
int rec(int node){
    if(dp[node]!=-1) return dp[node];
    int ans=1;
    for(auto v:g[node]){
        ans=max(ans,1+rec(v));
    }
    return dp[node]=ans;
}

signed main(){
    int n,e;
    cin>>n>>e;
    g.resize(n+1);
    vis.assign(n+1,0);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }

    //longest path for dag
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,rec(i));
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    reverse(topo.begin(),topo.end());
    for(auto v:topo){
        cout<<v;
    }

}