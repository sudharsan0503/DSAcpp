#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> g;
vector<int> color;

bool bfs(int src){
    queue<int> q;

    color[src] = 0;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto x : g[node]){
            int v = x.second;

            if(color[v] == -1){
                color[v] = !color[node];
                q.push(v);
            }
            else if(color[v] == color[node]){
                return false;
            }
        }
    }

    return true;
}

bool bipartite(int n){
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(!bfs(i))
                return false;
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

    if(bipartite(n))
        cout<<"The graph is bipartite\n";
    else
        cout<<"Not bipartite\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}