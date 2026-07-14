#include <bits/stdc++.h>
using namespace std;

int n,x;
int arr[100100];

int check(int mid){
   if(arr[mid]<arr[0]) return 1;
   else return 0; 
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>x;
  
  //lowerbound
  int low=0;
  int high=n-1;
  int ans=0;

   while(low<=high){
    int mid=(low+high)/2;
    if(check(mid)==1){
        ans=mid;
        high=mid-1;
    }else{
       low=mid+1;
    }
   }  
   cout<<ans<<endl;
}