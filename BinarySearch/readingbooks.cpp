#include<bits/stdc++.h>
using namespace std;

long long arr[2000000];
int N;

int check(long long mid){
   long long time=0;
   int stud=0;
  for(int i=0;i<N;i++){
     if(time>=arr[i]) time-=arr[i];
     else{
        stud++;
        if(stud>2) return 0;
        time=mid;
        if(time>=arr[i]) time-=arr[i];
        else return 0;
     }
  }
  return 1;
}

int main(){
    cin>>N;
    long long sum=0;
    for(int i=0;i<N;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    long long low=0,high=sum,ans=-1;
    while(low<=high){
        long long mid=low+((high-low)/2);
        if(check(mid)==1){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans;
    return 0;
}