//
// Created by andor on 2016/8/9.
//

#include <bits/stdc++.h>

using namespace std;

template<typename T>
bool cmp(const pair<T, T> &pair_1, const pair<T, T> &pair_2) {
    return (pair_1.first < pair_2.first);
}
//struct classCompPair {
//    bool operator()(const pair<T, T> &pair_1, const pair<T, T> &pair_2) const {
//        return (pair_1.first < pair_2.first);
//    }
//};


int main() {
//    set<pair<int, int>, classCompPair<int>> a;
//    set<pair<int, int>, classCompPair<int>> b;
    vector<pair<int, int>> a;
    vector<pair<int, int>> b;
    int t;
    int n;
    int nn = 0;
    ios::sync_with_stdio(false);
    while (cin >> t && t) {
        a.clear();
        n = 0;
        b.clear();
        cout << "Case #" << ++nn << ":\n";
        while (t--) {
            string opt, where;
            cin >> opt >> where;
            if (where == "A") {
                if (opt == "push") {
                    int x;
                    cin >> x;
                    a.emplace_back(make_pair(++n, x));
                }
                else if (opt == "pop") {
                    auto x = a.end();
                    x--;
                    cout << (*x).second << "\n";
                    a.erase(x);
                }
                else if (opt == "merge") {
                    string xx;
                    cin >> xx;
                    vector<pair<int, int>> c;
                    c.resize(a.size() + b.size());
                    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin(), cmp<int>);
                    a.swap(c);
                    b.clear();
                }
            }
            else if (where == "B") {
                if (opt == "push") {
                    int x;
                    cin >> x;
                    b.emplace_back(make_pair(++n, x));
                }
                else if (opt == "pop") {
                    auto x = b.end();
                    x--;
                    cout << (*x).second << "\n";
                    b.erase(x);
                }
                else if (opt == "merge") {
                    string xx;
                    cin >> xx;
                    vector<pair<int, int>> c;
                    c.resize(a.size() + b.size());
                    merge(b.begin(), b.end(), a.begin(), a.end(), c.begin(), cmp<int>);
                    b.swap(c);
                    a.clear();
                }
            }
        }
    }
    return 0;
}