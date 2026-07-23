#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>ans;

void solve(){
      cin>>n;
      vector<int>arr,pref,suff;

      arr.resize(n);
      pref.resize(n);
      suff.resize(n);
      ans.resize(n);

      for(int i=0;i<n;i++){
        cin>>arr[i];
      } 

    //pref[i] = product of all elements BEFORE i
    //pref = [1,1,2,6]

      pref[0]=1;
      for(int i=1;i<n;i++){
        pref[i]=pref[i-1]*arr[i-1];
       }

      suff[n-1] = 1;
      for(int i=n-2;i>=0;i--){
        suff[i] = suff[i+1] * arr[i+1];
      }

      for(int i=0;i<n;i++){
        ans[i]=pref[i]*suff[i];
        cout<<ans[i]<<" ";
      }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}