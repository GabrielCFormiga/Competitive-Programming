/**
* @file Multiplication_Table.cpp
* https://codeforces.com/edu/course/2/lesson/6/5/practice/contest/285084/problem/B
*
* Created on 2024-11-23 at 20:31:16
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
    1  2  3  4  5  6  7  8...
    2  4  6  8 10 12 14 16...
    3  6  9 12 15 18 21 24...
    4  8 12 16 20 24 28 32...
    5 10 15 20 25 30 35 40...
    6 12 18 24 30 36 42 48...
    7 14 21 28 35 42 49 56...
    */
ll n, k;

bool f(ll x) {
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += min(x / i, n);
        if (x >= i && x <= n * i && x % i == 0) sum--;
    }

    return sum < k;
}

int main() { _
    cin >> n >> k;


    ll l = 1, r = n * n;
    ll m;

    while (l < r) {
        m = l + (r - l + 1) / 2;

        if (f(m)) l = m;
        else r = m - 1;
    }

    cout << l << endl;

    return 0;
}