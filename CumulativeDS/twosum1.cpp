#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int count=0;
    map<int,int>freq;
    for(int j=0;j<n;j++){
        //arr[i]+arr[j]=x
        //arr[i]=x-arr[j]
        //we have to add arr[j],ie,x-arr[i] to frequency
        count += freq[x-arr[j]];//count the freq
        freq[arr[j]]++;//increase the freq of gn elem
    }
    cout<<count;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}