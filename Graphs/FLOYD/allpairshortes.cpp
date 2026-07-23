#include<bits/stdc++.h>
using namespace std;

int N;
long long dist[505][505];
int orders[505];
int active[505];

vector<long long>ans;

void getInput(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>dist[i][j];
        }
    }

    for(int i=1;i<=N;i++) {
        cin>>orders[i];
    }
}

void floyRelax(int k){
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
       dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    }
  }
}

long long getCurrentSum() {
    long long sum = 0;
    for(int i = 1; i <= N; i++) {
        if(!active[i]) continue;
        for(int j = 1; j <= N; j++) {
            if(!active[j]) continue;
            sum += dist[i][j];
        }
    }
    return sum;
}

void processGraph(){
  for(int i=N;i>=1;i--){
    int k=orders[i];
    active[k]=1;
    floyRelax(k);
    ans.push_back(getCurrentSum());
  }
}

void printanswer(){
    reverse(ans.begin(),ans.end());
    for(long long x:ans){
        cout<<x<<" ";
    }
}

void solve(){
    cin>>N;
    getInput();
    processGraph();
    printanswer();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}