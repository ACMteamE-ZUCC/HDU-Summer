//
// Created by andor on 2016/8/4.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int ans = 0, x;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            if (x % 8 == 0)
                ans ^= (x - 1);
            else if (x % 8 == 7)
                ans ^= (x + 1);
            else
                ans ^= x;
        }
        if (ans != 0)
            puts("First player wins.");
        else
            puts("Second player wins.");
    }
    return 0;
}