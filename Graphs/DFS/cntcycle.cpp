//Directed graph
//1-unvisited, 2-visiting,3-completed

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<int>color;
vector<int>parent;

bool is_cycle=0;
vector<int>any_cycle;
vector<int>cntcycle;
vector<int>prefixorder;

void dfs(int node,int par){
    parent[node]=par;
    color[node]=2;
    for(auto v:g[node]){
        //if(v==parent[node])continue;//if undirected
         if(color[v]==1){
            //node -v is forward edge
            dfs(v,node);
         }else if(color[v]==2){
            //node -v is back edge
            if(is_cycle==0){
               int temp=node;
               while(temp!=v){
                any_cycle.push_back(temp);
                temp=parent[temp];
               }
               any_cycle.push_back(temp);
               reverse(any_cycle.begin(),any_cycle.end());
            }
            cntcycle[node]++;
            cntcycle[parent[v]]--;
            is_cycle=1;
         }else if(color[v]==3){
            //node -v is cross edge
         }
    }
    color[node]=3;
    prefixorder.push_back(node);
}

int main(){
    int n,m;
    cin>>n>>m;

    g.resize(n+1);
    color.assign(n+1,1);
    parent.assign(n+1,0);
    cntcycle.assign(n+1,0);
    map<pair<int,int>,int>edgcnt;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(x==y){
            //self loop
        }
        if(x>y)swap(x,y);
        edgcnt[{x,y}]++;
        // if(edgcnt[{x,y}]>1){
        //   //multiple edge cycle
        // }else{
        //     g[x].push_back(y);
        //     g[y].push_back(x);
        // }
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(color[i]==1){
            dfs(i,0);
        }
    }
    for(auto v:any_cycle) cout<<v<<" ";
    for(auto v:prefixorder) cntcycle[parent[v]]+=cntcycle[v];
    int cntnode=0;
    for(int i=1;i<=n;i++){
        if(cntcycle[i]>0)cntnode++;
    }
    cout<<cntnode<<"\n";
    return 0;
}