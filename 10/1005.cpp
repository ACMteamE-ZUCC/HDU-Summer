//
// Created by andor on 2016/8/18.
//

#include <bits/stdc++.h>

using namespace std;


typedef int BIT_c;
const int BIT_MAX = 200010;
BIT_c BIT[BIT_MAX];
inline int lowbit(const int &n) {
    return n & (-n);
}
inline int op_upper(const int &n) {
    return n + lowbit(n);
}
inline int op_lower(const int &n) {
    return n - lowbit(n);
}
int bit_add(int ith, BIT_c dlt) {
    while (ith <= BIT_MAX) {
        BIT[ith] += dlt;
        ith = op_upper(ith);
    }
    return 0;
}
BIT_c bit_sum(int ith) {
    BIT_c ans = 0;
    while (ith > 0) {
        ans += BIT[ith];
        ith = op_lower(ith);
    }
    return ans;
}
int bit_init() {
    memset(BIT, 0, sizeof(BIT));
    return 0;
}



int a[200010];
//pair<int,int> ans[200010];
int ans1[200010];
int ans2[200010];
//int sum[200010];
bool vis[200010];

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        //b.clear();
        //memset(sum, 0, sizeof(sum));
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
        /*for (int i = 1; i < n; ++i) {
            for (int j = ans1[i]; j <= ans2[i]; ++j) {
                sum[j] += a[i];
            }
        }*/
        bit_init();
        for (int i = 1; i < n; ++i) {
            bit_add(ans1[i],a[i]);
            bit_add(ans2[i]+1,-a[i]);
        }
        for (int i = 1; i <= m; ++i) {
            cout << bit_sum(i) << "\n";
        }
    }
    return 0;
}
