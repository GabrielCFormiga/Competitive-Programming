/**
* @file H_Parallel_Checking.cpp
* @author GabrielCampelo
* Created on 2025-12-16 at 01:27:25
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
ll n, t;
vector<ll> vec;

bool f(ll d) {
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        sum += (vec[i] + d - 1) / d;
        if (sum > t) return false;
    }

    return true;
}

int main() { _
    cin >> n >> t;

    vec.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    ll l = 1, r = 1e12;
    ll m;

    while (l < r) {
        m = l + (r - l) / 2;

        if (f(m)) r = m;
        else l = m + 1;
    }

    cout << l << endl;
    
    return 0;
}