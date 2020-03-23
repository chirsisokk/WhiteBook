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

int n, m, ans = maxn;
int s[2], e[2];
int a[25][25];
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int x, int y, int num) {
    if(x == e[0] && y == e[1]) {
        ans = min(ans, num);
        return ;
    }
    if(num >= 10 || num >= ans) {
        return ;
    }
    for(int i = 0; i < 4; i++) {
        int tx = x + d[i][0], ty = y + d[i][1];
        while(1 <= tx && tx <= n && 1 <= ty && ty <= m && a[tx][ty] != 1) {
            if(tx == e[0] && ty == e[1]) {
                ans = min(ans, num + 1);
                return ;
            }
            tx += d[i][0];
            ty += d[i][1];
        }
        //如果移动后的位置出界或者根本没有移动
        if(!(1 <= tx && tx <= n && 1 <= ty && ty <= m) || (tx == x + d[i][0] && ty == y + d[i][1])) continue;
        a[tx][ty] = 0;
        dfs(tx - d[i][0], ty - d[i][1], num + 1);
        a[tx][ty] = 1;
    }
}

int main() {
    freopen("E:\\myprogram\\data.in", "r", stdin);
    //freopen("E:\\myprogram\\data.out", "w", stdout);
    while(cin >> m >> n && n != 0 && m != 0) {
        ans = maxn;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> a[i][j];
                if(a[i][j] == 2) s[0] = i, s[1] = j;
                if(a[i][j] == 3) e[0] = i, e[1] = j;
            }
        }
        dfs(s[0], s[1], 0);
        if(ans == maxn) ans = -1;
        cout << ans << endl;
    }
    return 0;
}