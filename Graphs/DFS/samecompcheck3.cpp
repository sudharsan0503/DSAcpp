#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<int>visited;

void dfs(int node,int color){
    visited[node]=color;
    for(auto v:g[node]){
        if(!visited[v]){
            dfs(v,color);
        }
    }
}

void num_comp(int n,int e){
   int comp=0;
   int color=1;
   for(int i=1;i<=n;i++){
    if(!visited[i]){
        dfs(i,color);
        comp++;
        color++;
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
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(visited[a]==visited[b]){
            cout<<a<<"and"<<b<<"are same component\n";
        }else{
            cout<<"They are not same component\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}