//
// Created by andor on 2016/8/14.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    ios::sync_with_stdio(false);
    int cnt = 0;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        set<char> a;
        a.clear();
        for (auto ss:s) {
            a.emplace(ss);
        }
        cout << "Case #" << ++cnt << ": " << a.size() << "\n";
    }
    return 0;
}