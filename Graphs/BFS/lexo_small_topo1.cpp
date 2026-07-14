#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<int>indeg;
vector<int>topo;

//if DAG, then toposize=n, if graph contains cycle,then toposize!=n. it can be 0 or less than n
//so this can also be used detect a cycle or not

void kahn(int n){
   priority_queue<int>q;
   //use min priority q instead of q. add minus(-) to all to make min
   for(int i=1;i<=n;i++){
    if(indeg[i]==0)q.push(-i);
   }
  
   while(!q.empty()){
      int cur=-q.top();
      q.pop();
      topo.push_back(cur);
      for(auto v:g[cur]){
         indeg[v]--;
         if(indeg[v]==0) q.push(-v);
      }
   }

}

void solve(){
    int n,e;
    cin>>n>>e;
    g.resize(n+1);
    indeg.assign(n+1,0);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
    }

    kahn(n);

    for(auto v:topo){
        cout<<v<<" ";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}