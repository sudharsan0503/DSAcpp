#include<bits/stdc++.h>
using namespace std;

int n;

bool cmp(int a,int b){
    return a>b;
}

void solve(){
      cin>>n;
      vector<int>a(n),b(n);
      for(int i=0;i<n;i++) cin>>a[i];
      for(int i=0;i<n;i++) cin>>b[i];
      sort(a.begin(),a.end());
      sort(b.begin(),b.end(),cmp);
      int mini=0;
      for(int i=0;i<n;i++){
        mini+=(a[i]*b[i]);
      }
      cout<<mini<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}