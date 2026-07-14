#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> g;
vector<int> visited;

bool bfs(int src){
    queue<pair<int,int>> q; // {node, parent}

    visited[src] = 1;
    q.push({src, -1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto x : g[node]){
            int v = x.second;

            if(!visited[v]){
                visited[v] = 1;
                q.push({v, node});
            }
            else if(v != parent){
                return true;
            }
        }
    }

    return false;
}

bool hasCycle(int n){
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(bfs(i))
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

    if(hasCycle(n))
        cout<<"Cycle present\n";
    else
        cout<<"Cycle not there\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}