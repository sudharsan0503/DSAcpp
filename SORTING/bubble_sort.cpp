#include<bits/stdc++.h>
using namespace std;

int n;
//worst case=O(n^2) and best case=O(n)
void bubble_sort(vector<int>& arr){
     for(int i=n-1;i>=0;i--){
        int didswap=0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){ //swap
              int temp=arr[j+1];
              arr[j+1]=arr[j];
              arr[j]=temp;
              didswap=1;
            }
        }
        if(didswap==0){
            cout<<"Its already om sprted order\n";
            break;
        }
     }
}

void solve(){
   cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   
   bubble_sort(arr);

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