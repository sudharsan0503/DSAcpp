#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,x;
    cin>>n>>x;
    int arr[n],prefix[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        prefix[i]=arr[i];
        if(i>0){
            prefix[i]+=prefix[i-1];
        }
    }

    //sub_array_sum(l,r)=p[r]-p[l-1]
    //p[r]-p[l-1]=x
    //p[l-1]=p[r]-x
    //if l=0,l=-1 edge case. so freq[0]=1;
    

    int count=0;
    map<int,int> freq;
    freq[0]=1;//edge case
    for(int r=0;r<n;r++){
        count+= freq[prefix[r]-x];
        freq[prefix[r]]++;
    }
    cout<<count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}