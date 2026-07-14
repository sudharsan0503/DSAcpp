#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

int N,M;

vector<vector<int>> g;
vector<vector<int>> dist;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int dir[4] = {1,2,3,4};

deque<pair<int,int>> q;

void BFSZorO()
{
    dist[0][0] = 0;
    q.push_front({0,0});

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();

        for(int k=0;k<4;k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            int cost;

            if(g[x][y] == dir[k])
                cost = 0;
            else
                cost = 1;

            if(dist[nx][ny] > dist[x][y] + cost)
            {
                dist[nx][ny] = dist[x][y] + cost;

                if(cost == 0)
                    q.push_front({nx,ny});
                else
                    q.push_back({nx,ny});
            }
        }
    }
}

void solve()
{
    cin >> N >> M;

    g.assign(N, vector<int>(M));
    dist.assign(N, vector<int>(M, INF));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> g[i][j];
        }
    }

    BFSZorO();

    cout << dist[N-1][M-1] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}