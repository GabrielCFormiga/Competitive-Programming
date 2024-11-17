/**
* @file Magic_Powder_1.cpp
* https://codeforces.com/problemset/problem/670/D1
*
* Created on 2024-11-17 at 15:44:14
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

#define MAX_N 1010

int n, k;
int a[MAX_N], b[MAX_N];

bool possible(int x) {
    int k_used = 0;

    for (int i = 0; i < n; i++) {
        if (x * a[i] > b[i]) k_used += x * a[i] - b[i];
    }

    return k_used <= k;
}

int main() { _
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int l = 0, r = 2000;
    int m;

    while (l < r) {
        m = l + (r - l + 1) / 2;

        if (possible(m)) l = m;
        else r = m - 1;
    }

    cout << l << endl;

    return 0;
}