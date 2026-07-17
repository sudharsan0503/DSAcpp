#include<bits/stdc++.h>
using namespace std;

void solve(){
      int n;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++){
        cin>>arr[i];
      }

      int min_price_so_far=INT_MAX;
      int best=0;
      for(int j=0;j<n;j++){
        best= max(best ,arr[j]-min_price_so_far);
        min_price_so_far=min(arr[j],min_price_so_far);
      }
      cout<<best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}