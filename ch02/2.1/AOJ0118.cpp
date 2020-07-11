#include <set>
#include <map>
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

int n, m, ans = 0;
string s[105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int sx, int sy, char ch) {
    s[sx][sy] = '.';
    for(int i = 0; i < 4; i++) {
        int x = sx + dx[i];
        int y = sy + dy[i];
        if(0 <= x && x < n && 0 <= y && y < m && s[x][y] == ch) {
            dfs(x, y, ch);
        }
    }
}

int main() {
    //freopen("E:\\myprogram\\data.in", "r", stdin);
    //freopen("E:\\myprogram\\data.out", "w", stdout);
    while(cin >> n >> m && n != 0 && m != 0) {
        ans = 0;
        for(int i = 0; i < n; i++) cin >> s[i];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s[i][j] != '.') {
                    ans++;
                    dfs(i, j, s[i][j]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}