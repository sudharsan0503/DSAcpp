#include<bits/stdc++.h>
using namespace std;

int n;

void solve(){
    cin>>n;
    int p[n-1],c[n-1],r[n-1]; //we take n-1 as there is no use of last city
    for(int i=0;i<n;i++){
        cin>>p[i]>>c[i]>>r[i];
    }
    int ans=0;
    //{price,remaining}
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<n;i++){
        pq.push({-p[i],r[i]});
        int to_cover =c[i];
        cout<<"Covered:"<<c[i]<<"\n";
        while(!pq.empty() && to_cover>0){
            auto best=pq.top();
            pq.pop();

            int price=-best.first;
            int remaining=best.second;

            int used=min(remaining,to_cover);
            remaining-=used;
            ans+=price*used;
            cout<<"Used"<<price<<","<<used<<endl;
            if(remaining>0){
                pq.push({-price,remaining});
            }
        }
        if(pq.empty() && to_cover>0){
            ans=-1;
            break;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}