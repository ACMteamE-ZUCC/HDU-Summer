//
// Created by andor on 2016/8/11.
//

#include <bits/stdc++.h>

using namespace std;

vector<double> ba;

int main() {
    double t;
    scanf("%lf", &t);
    while (t--) {
        double n, c;
        scanf("%lf %lf", &n, &c);
        while (n--) {
            double pos, v, d;
            scanf("%lf %lf %lf", &v, &pos, &d);
            ba.emplace_back(v);
        }
        c *= 2.0;
        sort(ba.begin(), ba.end());
        double q;
        scanf("%lf", &q);
        while (q--) {
            double tt, ni;
            scanf("%lf %lf", &tt, &ni);
            double ans = sqrt(ba[ni - 1] * ba[ni - 1] + c * tt);
            printf("%.3f\n", ans);
        }
    }
    return 0;
}