/**
* @file Get_together.cpp
* https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A
*
* Created on 2024-11-14 at 15:06:22
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

/* 
    (|xi - x|)/vi <= t ->
    
    |xi - x| <= t*vi ->

    xi - t*vi <= x <= xi + t*vi
 */

#define MAX_N 100100

ll n;
pair<ll, ll> ar[MAX_N]; // {xi, vi}
 
bool good(double t) {
    double left_limit = -1e9, right_limit = 1e9;

    for (ll i = 0; i < n; i++) {
        left_limit = max(left_limit, ar[i].first - t * ar[i].second);
        right_limit = min(right_limit, ar[i].first + t * ar[i].second);
    }

    // cout << "t = " << t << " left_limit = " << left_limit << " right_limit = " << right_limit << endl;
    return right_limit >= left_limit;
}

int main() { _
    cin >> n;

    for (ll i = 0; i < n; i++) {
        cin >> ar[i].first >> ar[i].second;
    }
    
    double l = 0, r = 2e9 + 100;
    double m;

    cout << fixed << setprecision(10);

    for (ll i = 0; i < 100; i++) {
        m = (l + r) / 2;

        if (good(m)) r = m;
        else l = m;
    }

    cout << l << endl;

    return 0;
}