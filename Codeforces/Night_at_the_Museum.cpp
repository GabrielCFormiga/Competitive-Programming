/**
* @file Night_at_the_Museum.cpp
* https://codeforces.com/contest/731/problem/A
*
* Created on 2025-04-11 at 03:44:21
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
    string name;
    cin >> name;

    int ans = 0;
    int curr = 'a';

    for (auto c : name) {
        ans += min(abs(c - curr), 26 - abs(c - curr));
        curr = c;
    }

    cout << ans << endl;

    return 0;
}