#include<bits/stdc++.h>
using namespace std;

long long n,t;
int arr[300005]; 

int check(long long mid){
 long long total_machines=0;
 for(int i=0;i<n;i++){
    total_machines+=(mid/arr[i]);
    if(total_machines>=t) return 1;
 }
 return 0;
}

int main(){
    cin>>n>>t;
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    long long low=0,high=1e18,ans=-1;
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