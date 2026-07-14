#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;
vector<int> topo;
vector<int> dp;

void dfs(int node){

    vis[node]=1;

    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }

    topo.push_back(node);
}

void solve(){

    int n,e;
    cin>>n>>e;

    g.resize(n+1);
    vis.assign(n+1,0);
    dp.assign(n+1,1);

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
    }

    // Topological sort
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    int finalAns=0;

    // topo currently contains reverse topological order
    // Example: 3 2 1 for graph 1->2->3
    // Perfect for longest path DP

    for(auto node:topo){

        for(auto v:g[node]){
            dp[node]=max(dp[node],1+dp[v]);
        }

        finalAns=max(finalAns,dp[node]);
    }

    cout<<"Topological Order: ";

    reverse(topo.begin(),topo.end());

    for(auto node:topo){
        cout<<node<<" ";
    }

    cout<<"\n";

    cout<<"Longest Path Length (nodes) = "<<finalAns<<"\n";
}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}