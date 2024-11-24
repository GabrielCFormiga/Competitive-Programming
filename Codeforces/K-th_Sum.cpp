/**
* @file K-th_Sum.cpp
* https://codeforces.com/edu/course/2/lesson/6/5/practice/contest/285084/problem/C
*
* Created on 2024-11-23 at 21:08:22
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

#define MAX_N 100100

ll n, k;
int a[MAX_N], b[MAX_N];
int ans;

bool f(int x) {
    // bool possible = false; // verifica se x existe
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= x) break;

        int l = -1, r = n - 1;
        while (l < r) {
            int m = l + (r - l + 1) / 2;
            
            if (b[m] < x - a[i]) {
                // if (b[m] + a[i] == x) possible = true;
                l = m;
            }
            else r = m - 1;
        }

        cnt += l + 1;
    }

    // if (cnt < k && possible) ans = x;
    return cnt < k;
}

int main() { _
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i]; 
    for (int i = 0; i < n; i++) cin >> b[i];    

    sort(a, a + n);
    sort(b, b + n);

    int l = 0, r = 2e9;
    int m;

    while (l < r) {
        m = l + (r - l + 1) / 2;

        if (f(m)) l = m;
        else r = m - 1;
    }

    cout << l << endl;

    return 0;
}