//
// Created by andor on 2016/7/26 0026.
//

#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];
int dp0[1005][1005];

void init() {
    fill(begin(dp[2]), end(dp0[2]), 1);
    for (int k = 0; k < 1001; ++k) {
        dp0[k][2] = 1;
    }
    dp[3][2] = 1;
    dp[2][3] = 1;
    dp[4][4] = -1;
    for (int i = 4; i < 1001; ++i) {
        for (int j = 4; j < 1001; ++j) {
            if (dp[i - 2][j - 1] == -1 || dp[i - 1][j - 2] == -1)
                dp[i][j] = 1;
            else if (dp[i - 2][j - 1] == 0 || dp[i - 1][j - 2] == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }
    }
    for (int i = 3; i < 1001; ++i) {
        for (int j = 3; j < 1001; ++j) {
            if (dp0[i - 1][j] == -1 || dp0[i][j - 1] == -1 || dp0[i - 1][j - 1] == -1)
                dp0[i][j] = 1;
            else
                dp0[i][j] = -1;
        }
    }
}

int main() {
    int t;
    init();
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        int n, m, c;
        cin >> c >> n >> m;
        int flag = 0;
        switch (c) {
            case 1: {
                flag = dp0[n][m];
                break;
            }
            case 2: {
                if (n == m)
                    flag = -1;
                else
                    flag = 1;
                break;
            }
            case 3: {
#if 0
                n--;
                m--;
                int n0 = n % 3;
                int m0 = m-n+n0;
                if (n0 == 2 && m0 == 1)
                    flag = 1;
                else if (n0 == 1 && m0 == 2)
                    flag = 1;
                else if (n0 == 0 && m0 == 0)
                    flag = -1;
                else
                    flag = 0;
#endif
                flag = dp[n][m];
                break;
            }
            case 4: {
                if (n == m)
                    flag = 1;
                else
                    flag = 0;
                break;
            }
            default:
                break;
        }
        switch (flag) {
            case 1:
                cout << "B\n";
                break;
            case -1:
                cout << "G\n";
                break;
            case 0:
                cout << "D\n";
                break;
            default:
                break;
        }
    }
    return 0;
}