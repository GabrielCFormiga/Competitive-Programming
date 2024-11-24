/**
* @file K-th_Number_in_the_Union_of_Segments.cpp
* https://codeforces.com/edu/course/2/lesson/6/5/practice/contest/285084/problem/A
*
* Created on 2024-11-23 at 19:58:54
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

typedef long long ll;

#define MAX_N 50

int n, k;
pair<ll, ll> segs[MAX_N];

bool good(ll &x) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (x > segs[i].first) {
            sum += min(x - segs[i].first, segs[i].second - segs[i].first + 1);
            if (sum > k) return false;
        }
    }

    return sum <= k;
}

int main() { _
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> segs[i].first >> segs[i].second;
    }
    
    ll l = -2000000000, r = 2000000000;
    ll m;

    while (l < r) {
        m = l + (r - l + 1) / 2;

        if (good(m)) l = m;
        else r = m - 1;
    }

    cout << l << endl;

    return 0;
}