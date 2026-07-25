#include<bits/stdc++.h>
using namespace std;

int n;

struct prob{
    int s,d,t;
};

bool cmp(prob a ,prob b){
    return 1LL * a.t * b.d < 1LL* b.t * a.d;
}

void solve(){
    cin>>n;
    vector<prob> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].s>>arr[i].d>>arr[i].t;
    }
    sort(arr.begin(),arr.end(),cmp);
    long long ans=0;
    long long time_till_now=0;
    for(int i=0;i<n;i++){
        time_till_now+=arr[i].t;
        ans+=(arr[i].s)-(arr[i].d*time_till_now);
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}