//
// Created by andor on 2016/7/26 0026.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        int n, m, c;
        cin >> c >> n >> m;
        int flag = 0;
        switch (c) {
            case 1: {
                int sum = n + m;
                if (sum % 2)
                    flag = 1;
                else
                    flag = -1;
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
                int n0 = n % 3;
                int m0 = m % 3;
                if (n0 == 2 && m0 == 1)
                    flag = 1;
                else if (n0 == 1 && m0 == 2)
                    flag = 1;
                else if (n0 == 0 && m0 == 0)
                    flag = -1;
                else
                    flag = 0;
                break;
            }
            case 4: {
                if (n == m)
                    flag = 1;
                else
                    flag = 0;
                break;
            }
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
        }
    }
    return 0;
}