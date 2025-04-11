/**
* @file Boy_or_Girl.cpp
* https://codeforces.com/contest/236/problem/A
*
* Created on 2025-04-11 at 00:56:53
* @author GabrielCampelo
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
    vector<bool> vec(26);
    string str;
    cin >> str;

    int cnt = 0;
    for (char c : str) {
        if (!vec[c - 'a']) {
            vec[c - 'a'] = true;
            cnt++;
        }
    }

    if (cnt % 2 == 0) cout << "CHAT WITH HER!" << endl;
    else cout << "IGNORE HIM!" << endl;

    return 0;
}