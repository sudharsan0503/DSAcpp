#include<bits/stdc++.h>
using namespace std;

int n;

void selection_sort(vector<int>& arr){
     for(int i=0;i<n-1;i++){
        int miniind=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[miniind]){
                miniind=j;
            }
        }
        swap(arr[i],arr[miniind]);
     }
}

void solve(){
   cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   selection_sort(arr);
   for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}