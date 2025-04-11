/**
* @file Black_Square.cpp
* https://codeforces.com/contest/431/problem/A
*
* Created on 2025-04-11 at 03:39:52
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
    vector<int> a(4);
    for (int i = 0; i < 4; i++) cin >> a[i];

    string str;
    cin >> str;

    int ans = 0;
    for (char c : str) {
        ans += a[c - '1'];
    }

    cout << ans << endl;
    
    return 0;
}