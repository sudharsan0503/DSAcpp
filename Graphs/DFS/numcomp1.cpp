#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<int>visited;

void dfs(int node){
    visited[node]=1;
    for(auto v:g[node]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

void num_comp(int n,int e){
   int comp=0;
   for(int i=1;i<=n;i++){
    if(!visited[i]){
        dfs(i);
        comp++;
    }
   }
   cout<<"The number of components is:"<<comp<<endl;
}

void solve(){
    int n,e;
    cin>>n>>e;
    visited.resize(n+1);
    g.resize(n+1);
    for(int i=0;i<e;i++){
        int e1,e2;
        cin>>e1>>e2;
        g[e1].push_back(e2);
        g[e2].push_back(e1);
    }
    num_comp(n,e);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}