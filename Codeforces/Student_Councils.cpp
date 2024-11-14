/**
* @file Student_Councils.cpp
* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/G
*
* Created on 2024-11-14 at 02:09:27
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
// #define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll n, k;
vector<ll> groups;

bool f(ll x) {
    ll sum = 0;
    for (int i = 0; i < n; i++) sum += min(x, groups[i]);
    return sum >= x * k;
}

int main() { // _
    cin >> k >> n;

    groups.resize(n);
    for (int i = 0; i < n; i++) cin >> groups[i];

    ll l = 0, r = 1e9 * n / k;
    ll m, ans;

    while (l < r) {
        m = l + (r - l + 1) / 2;

        if (f(m)) l = m;
        else r = m - 1;
    }

    cout << l << endl;

    return 0;
}