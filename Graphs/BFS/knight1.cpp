#include <bits/stdc++.h>
using namespace std;

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
    Sx--;
    Sy--;
    Fx--;
    Fy--;

    vector<vector<int>> visited(N, vector<int>(N, 0));
    vector<vector<int>> dist(N, vector<int>(N, 0));

    queue<pair<int,int>> q;

    q.push({Sx, Sy});
    visited[Sx][Sy] = 1;

    int dr[] = {-2,-2,-1,-1,1,1,2,2};
    int dc[] = {-1,1,-2,2,-2,2,-1,1};

    while(!q.empty()){
        auto pos = q.front();
        q.pop();

        int r = pos.first;
        int c = pos.second;

        if(r == Fx && c == Fy){
            return dist[r][c];
        }

        for(int i = 0; i < 8; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]){
                visited[nr][nc] = 1;
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    while(test_case--)
    {
        int N, Sx, Sy, Fx, Fy;
        cin >> N >> Sx >> Sy >> Fx >> Fy;

        cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
    }

    return 0;
}
