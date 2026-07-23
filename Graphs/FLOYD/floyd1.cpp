#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
int dist[404][404];

void solve(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j) dist[i][j]=INF;
            else dist[i][j]=0;
        }
    }

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}