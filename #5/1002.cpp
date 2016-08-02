//
// Created by andor on 2016/8/2 0002.
//

#include <bits/stdc++.h>

using namespace std;

list<int> a;

int main() {
    int n;
    ios::sync_with_stdio(false);
    while (cin >> n) {
        a.clear();
        for (int i = 1; i <= n; ++i) {
            int aa;
            cin >> aa;
            a.emplace_back(aa);
        }
        int ans = 0;
        int sum = 0;
        for (auto i = a.begin(); i != a.end(); ++i) {
            if (*i < 0) {
                sum = *i;
                auto j = i;
                j--;
                while (sum < 0) {
                    sum += *j;
                    auto x = j;
                    j--;
                    a.erase(x);
                    ans--;
                }
                *i = sum;
                ans++;
            }
            else
                ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}