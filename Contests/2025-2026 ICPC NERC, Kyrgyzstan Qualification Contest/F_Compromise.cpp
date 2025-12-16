/**
* @file F_Compromise.cpp
* @author GabrielCampelo
* Created on 2025-12-16 at 03:09:08
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int l = 0, r = n - 1;

    vector<char> ans(n);

    while (l <= r) {
        int mn = INF;
        char c_mn;
        for (char c = 'a'; c <= 'z'; c++) {
            int d = abs(c - s[l]) + abs(c - t[l]) + abs(c - t[r]) + abs(c - s[r]);
            if (d < mn) {
                mn = d;
                c_mn = c;
            }
        }
        ans[l++] = c_mn;
        ans[r--] = c_mn;
    }

    for (char c : ans) {
        cout << c;
    }
    cout << endl;
    
    return 0;
}