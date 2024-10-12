/**
* @file Compatibility_Queries.cpp
* https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/compatibility-queries-0c068f8f/
*
* Created on 2024-10-12 at 02:29:23
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

#define MAX_N 1000000
#define MASK ((1 << 20) - 1)

int n, q;
int ar[MAX_N];
ll dp[MAX_N + 1]; // dp[i] := soma de elementos compativeis com i

inline void fast_scan(int &num) {
    num = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9') c = getchar_unlocked();
    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = getchar_unlocked();
    }
}

int main() { _
    fast_scan(n);
    for (int i = 0; i < n; i++) {
        fast_scan(ar[i]);
    }
    sort(ar, ar + n);

    for (int i = 0; i < n; i++) {
        int qtd = 1;
        while (i < n - 1 && ar[i + 1] == ar[i]) {
            qtd++;
            i++;
        }

        int b = ar[i] ^ MASK; // bits desligados de ar[i]
        for (int m = b; m > 0; m = (m - 1) & b) {
            if (m <= MAX_N) dp[m] += ar[i] * qtd;
        }
    }

    fast_scan(q);
    while (q--) {
        int x;
        fast_scan(x);
        cout << dp[x] << endl;
    }
    
    return 0;
}
