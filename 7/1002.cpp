//
// Created by andor on 2016/8/9.
//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    else return gcd(y, x % y);
}

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    while (cin >> n >> m && (n || m)) {
        ll x = n * (m - 1);
        ll y = m * m;
        ll z = gcd(x, y);
        x /= z;
        y /= z;
        cout << x << "/" << y << "\n";
    }
    return 0;
}