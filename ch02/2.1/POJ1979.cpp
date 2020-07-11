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

int n, m;
int ans = 0;
string s[25];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y) {
    ans++;
    for(int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(0 <= tx && tx < n && 0 <= ty && ty < m && s[tx][ty] == '.') {
            s[tx][ty] = '#';
            dfs(tx, ty);
        }
    }
}

int main() {
    //freopen("E:\\myprogram\\data.in", "r", stdin);
    //freopen("E:\\myprogram\\data.out", "w", stdout);
    while(cin >> m >> n && n != 0 && m != 0){
        ans = 0;
        for(int i = 0; i < n; i++) cin >> s[i];
        int sx, sy;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s[i][j] == '@') sx = i, sy = j;
            }
        }
        dfs(sx, sy);
        cout << ans << endl;
    }
    return 0;
}