#include<bits/stdc++.h>
using namespace std;

int n,k;
int arr[30000000]; 

int check(long long mid){
 long long last_painter_time_left=0;
 long long num_painter_spawned=0;
 for(int i=0;i<n;i++){
    if(last_painter_time_left>=arr[i]){
        last_painter_time_left-=arr[i];
    }else{
       num_painter_spawned++;
       if(num_painter_spawned>k) return 0;
       last_painter_time_left=mid;
       if(last_painter_time_left>=arr[i]){
        last_painter_time_left-=arr[i];
       }else{
        return 0;
       }
    }
 }
 return 1;
}

int main(){
    cin>>n>>k;
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    long long low=0,high=sum,ans=-1;
    while(low<=high){
       long long mid=low+(high-low)/2;
       if(check(mid)==1){
        ans=mid;
        high=mid-1;
       }else{
        low=mid+1;
       }
    }
    cout<<ans<<endl;
    return 0;
}