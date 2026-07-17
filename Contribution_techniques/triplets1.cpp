#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum_triplets=0;
    long long triplets_per_element=(long long)(n - 1)*(n - 2)/2;
    for(int i=0;i<n;i++){
        sum_triplets+=(arr[i]*triplets_per_element);
    }
    cout<<sum_triplets;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}