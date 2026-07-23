//Directed graph
//1-unvisited, 2-visiting,3-completed

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<int>color;
vector<int>parent;

bool is_cycle=0;
vector<int>any_cycle;

void dfs(int node,int par){
    parent[node]=par;
    color[node]=2;
    for(auto v:g[node]){
         if(is_cycle) return;
         if(color[v]==1){
            //node -v is forward edge
            dfs(v,node);
         }
         else if(color[v]==2){
            int temp=node;
                while(temp!=v){
                    any_cycle.push_back(temp);
                    temp=parent[temp];
                }
            any_cycle.push_back(v);
            reverse(any_cycle.begin(),any_cycle.end());
            any_cycle.push_back(v);   // close cycle repeat the node

            is_cycle=true;
            return;
        }
        else if(color[v]==3){
            //node -v is cross edge
        }
    }
    color[node]=3;
}

int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    color.assign(n+1,1);
    parent.assign(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(color[i]==1){
            dfs(i,-1);
        }
    }

}