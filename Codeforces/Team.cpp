/**
* @file Team.cpp
* https://codeforces.com/contest/231/problem/A
*
* Created on 2025-04-09 at 16:59:21
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
    int tt;
    cin >> tt;

    int a, b, c;
    int ans = 0;
    while (tt--) {
        cin >> a >> b >> c;
        int sum = a + b + c;
        if (sum > 1) ans++;
    }

    cout << ans << endl;
    
    return 0;
}