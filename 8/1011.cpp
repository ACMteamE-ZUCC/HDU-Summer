//
// Created by andor on 2016/8/11.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int count1 = 0;
        stack<char> a;
        int n;
        cin >> n;
        string c;
        cin >> c;
        for (string::size_type i = 0; i < c.length(); i++) {
            if (c[i] == '(') {
                a.push(c[i]);
            } else if (c[i] == ')') {
                if (!a.empty()) {
                    char c1 = a.top();
                    if (c1 == '(') {
                        a.pop();
                    } else {
                        a.push(c[i]);
                        count1++;
                    }
                } else {
                    a.push(c[i]);
                    count1++;
                }
            }
        }
        bool flag = 1;
        string ss;
        while (!a.empty()) {
            ss += a.top();
            a.pop();
        }
        if (ss == "(())")
            flag = 0;
        if ((count1 >= 2 && flag) || n == 2 || n % 2 == 1) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    return 0;
}