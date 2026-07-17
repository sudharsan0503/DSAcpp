#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   //extend and add
    int ans=0;
    int prev_sum=0;
    for(int i=0;i<n;i++){
        prev_sum=(prev_sum)+((i+1)*arr[i]);
        ans+=prev_sum;
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}