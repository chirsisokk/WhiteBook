#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define PII pair<int, int>
#define debug std::cout << "---debug---" << std::endl;
using namespace std;
const int maxn = 1e5 + 7;
const int mod = 1e9 + 7;

int n, m, N, ans = 0;
char a[1005][1005];
int dis[1005][1005];
int pt[15][2];
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int sx, int sy, int ex, int ey) {
    memset(dis, -1, sizeof(dis));
    queue<PII> q;
    q.push({sx, sy});
    dis[sx][sy] = 0;
    while(!q.empty()) {
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int X = tx + d[i][0];
            int Y = ty + d[i][1];
            if(0 <= X && X < n && 0 <= Y && Y < m && a[X][Y] != 'X' && dis[X][Y] == -1) {
                q.push({X, Y});
                dis[X][Y] = dis[tx][ty] + 1;
            }
        }
    }
    return dis[ex][ey];
}

int main() {
    freopen("E:\\myprogram\\data.in", "r", stdin);
    //freopen("E:\\myprogram\\data.out", "w", stdout);
    cin >> n >> m >> N;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'S') {
                pt[0][0] = i; pt[0][1] = j;
            }
            if('0' <= a[i][j] && a[i][j] <= '9') {
                pt[a[i][j] - '0'][0] = i; pt[a[i][j] - '0'][1] = j;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += bfs(pt[i - 1][0], pt[i - 1][1], pt[i][0], pt[i][1]);
    }
    cout << ans << endl;
    return 0;
}