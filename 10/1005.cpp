//
// Created by andor on 2016/8/18.
//

#include <bits/stdc++.h>

using namespace std;

int a[200010];
//vector<pair<int,int>> b;
pair<int, int> ans[200010];
int sum[200010];

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        //b.clear();
        memset(sum, 0, sizeof(sum));
        fill(begin(ans), end(ans), make_pair(INT32_MAX, -INT32_MAX));
        for (int i = 1; i < n; ++i)
            cin >> a[i];
        for (int i = 1; i <= m; ++i) {
            int x, y;
            cin >> x >> y;
            for (int j = x; j < y; ++j) {
                ans[j].first = ans[j].first < i ? ans[j].first : i;
                ans[j].second = i;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = ans[i].first; j <= ans[i].second; ++j) {
                sum[j] += a[i];
            }
        }
        for (int i = 1; i <= m; ++i) {
            cout << sum[i] << "\n";
        }
    }
    return 0;
}