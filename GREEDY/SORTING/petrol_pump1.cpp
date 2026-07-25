#include<bits/stdc++.h>
using namespace std;

int n;

void solve(){
    cin>>n;
    vector<int>p(n),c(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
        cin>>c[i];
    }
    int min_price_till_now=INT_MAX;
    int cost=0;
    for(int i=0;i<n;i++){
        min_price_till_now=min(min_price_till_now,p[i]);
        cost += (c[i]*min_price_till_now);
    }
    cout<<"Total cost is:"<<cost<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}