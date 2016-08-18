//
// Created by andor on 2016/8/18.
//

#include <bits/stdc++.h>

using namespace std;
int a[100010];

int main() {
    int t;
    //ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        for (int i = 1; i <= m; ++i) {
            cin >> a[i];
        }
        while (n--) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            if (r1 > r2) {
                swap(l1, l2);
                swap(r1, r2);
            }
            int len1 = r1 - l1 + 1;
            int len2 = r2 - l2 + 1;
            int mid = len1 + len2;
            bool flag;
            flag = (mid % 2 == 1);
            mid /= 2;
//            if(flag)
//                mid++;
            double ans = 0;
            if (l2 > r1) {
                if (mid <= len1) {
                    if (flag)
                        ans = a[mid + l1];
                    else {
                        ans = a[mid + l1 - 1];
                        if (++mid > len1)
                            ans += a[l2];
                        else
                            ans += a[mid + l1];
                        ans /= 2.0;
                    }
                } else {
                    if (flag)
                        ans = a[mid - len1 + l2];
                    else {
                        ans = a[mid + l2 - len1] + a[mid + l2 - 1 - len1];
                        ans /= 2;
                    }
                }
            } else if (l2 <= r1) {
                if (l1 < l2) {
                    int len3 = r1 - l2 + 1;
                    len1 -= len3;
                    len2 -= len3;
                    if (flag) {
                        if (mid + 1 <= len1)
                            ans = a[mid + l1];
                        else if (mid + 1 <= len3 * 2 + len1) {
                            int x = (mid - len1 + 1) / 2;
                            if ((mid - len1 + 1) % 2) {
                                x++;
                            }
                            ans = a[l1 + len1 + x];
                        } else
                            ans = a[l1 + mid - len3 + 1];
                    } else {

                    }
                }
            }
            printf("%.1f\n", ans);
        }
    }
    return 0;
}