#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int n;

void bfs(){

    int ans = INT_MAX;

    for(int src = 1; src <= n; src++){

        vector<int> dist(n + 1, -1);

        queue<pair<int,int>> q;

        dist[src] = 0;
        q.push({src, -1});

        while(!q.empty()){

            int node = q.front().first;
            int par  = q.front().second;
            q.pop();

            for(auto v : g[node]){

                if(dist[v] == -1){

                    dist[v] = dist[node] + 1;
                    q.push({v, node});
                }
                else{

                    // Ignore the edge we came from
                    if(v == par){
                        continue;
                    }

                    ans = min(ans, dist[node] + dist[v] + 1);
                }
            }
        }
    }

    if(ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
}

void solve(){

    int m;
    cin >> n >> m;

    g.resize(n + 1);

    for(int i = 0; i < m; i++){

        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs();
}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}