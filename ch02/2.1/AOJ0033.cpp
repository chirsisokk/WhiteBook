/*-----这题水死了,更像是个贪心-----*/
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

int T;
int a[15];
int B[15], C[15];

bool dfs(int pos) {
    if(pos >= 10) {
        return true;
    }
    if(a[pos] > B[B[0]]) {
        B[++B[0]] = a[pos];
        return dfs(pos + 1);
    }
    else if(a[pos] > C[C[0]]) {
        C[++C[0]] = a[pos];
        return dfs(pos + 1);
    }
    return false;
}

int main() {
    freopen("E:\\myprogram\\data.in", "r", stdin);
    //freopen("E:\\myprogram\\data.out", "w", stdout);
    cin >> T;
    while(T--) {
        for(int i = 0; i < 10; i++) cin >> a[i];
        for(int i = 0; i < 15; i++) B[i] = 0, C[i] = 0;
        if(dfs(0)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}