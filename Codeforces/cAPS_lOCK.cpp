/**
* @file cAPS_lOCK.cpp
* @author GabrielCampelo
* Created on 2026-02-21 at 23:22:51
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;
using llu = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    string s;
    cin >> s;

    bool upper = true;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] <= 'z' && s[i] >= 'a') {
            upper = false;
            break;
        }
    }

    if (upper) {
        for (char c : s) {
            if (c <= 'z' && c >= 'a' ) {
                cout << (char)(c - 'a' + 'A');
            } else {
                cout << (char)(c - 'A' + 'a');
            }
        }
        cout << endl;
    } else {
        cout << s << endl;
    }
    
    return 0;
}