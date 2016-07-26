//
// Created by andor on 2016/7/26 0026.
//

#include <bits/stdc++.h>

using namespace std;

class point {
public:
    int x;
    int y;

    point(int x, int y) : x(x), y(y) {}

    point() {}

    friend int operator-(const point p1, const point p2);

    friend bool operator>(const point p1, const point p2);
};

int operator-(const point p1, const point p2) {
    int sum = 0;
    sum += abs(p1.x - p2.x);
    sum += abs(p1.y - p2.y);
    return sum;
}
bool operator>(const point p1, const point p2) {
#if 1
    if (p1.x == p2.x)
        return p1.y < p1.y;
    return p1.x < p2.x;
#endif
    return (p1.x + p1.y) < (p2.x + p2.y);
}
set<point> p;

int main() {
    int t;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        int pp, n;
        cin >> pp >> n;
        while (pp--) {
            int x, y;
            cin >> x >> y;
            p.emplace(point(x, y));
        }

    }
    return 0;
}