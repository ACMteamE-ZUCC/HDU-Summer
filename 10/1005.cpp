//
// Created by andor on 2016/8/18.
//

#include <bits/stdc++.h>

using namespace std;

int a[200010];
//pair<int,int> ans[200010];
int ans1[200010];
int ans2[200010];
int sum[200010];
bool vis[200010];

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        //b.clear();
        memset(sum, 0, sizeof(sum));
        memset(vis, 1, sizeof(vis));
        memset(ans1, INT32_MAX, sizeof(ans1));
        memset(ans2, -INT32_MAX, sizeof(ans2));
        //fill(begin(ans), end(ans), make_pair(INT32_MAX, -INT32_MAX));
        for (int i = 1; i < n; ++i)
            cin >> a[i];
        for (int i = 1; i <= m; ++i) {
            int x, y;
            cin >> x >> y;
            for (int j = x; j < y; ++j) {
                if (vis[j]) {
                    ans1[j] = i;
                    vis[j] = 0;
                }
                ans2[j] = i;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = ans1[i]; j <= ans2[i]; ++j) {
                sum[j] += a[i];
            }
        }
        for (int i = 1; i <= m; ++i) {
            cout << sum[i] << "\n";
        }
    }
    return 0;
}