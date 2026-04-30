/**
* @file F_Froginald_the_frog.cpp
* @author GabrielCampelo
* Created on 2026-03-15 at 12:30:42
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;
using llu = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;
const int MAX_PRECOMP = 1e5 + 10;

using Matrix = vector<vector<int>>;
 
Matrix multiply(Matrix a, Matrix b) {
    Matrix ret = {
        {0, 0},
        {0, 0}
    };
 
    // K^3 (Matrix KxK)
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ret[i][j] = (ret[i][j] + 1ll * a[i][k] * b[k][j]) % MOD;
            }
        }
    }
 
    return ret;
}

unordered_map<int, int> memo;
int precomp[MAX_PRECOMP];

int fib(int n) {
    if (n < MAX_PRECOMP) return precomp[n];
    if (memo.count(n)) return memo[n];

    Matrix M = {
        {1, 0},
        {0, 1}
    };
    Matrix a = {
        {0, 1},
        {1, 1}
    };
 
    int og = n;

    // a^n
    while (n) {
        if (n % 2 == 1) M = multiply(M, a);
        a = multiply(a, a);
        n /= 2;
    }
 
    return memo[og] = M[1][0];
}

int main() { _
    // for (int i = 1; i < 10; i++) {
    //     cout << "FIB(" << i << ") = " << fib(i) << endl;
    // }
    // return 0;
    precomp[0] = precomp[1] = precomp[2] = 1;
    for (int i = 3; i < MAX_PRECOMP; i++) {
        precomp[i] = (precomp[i - 1] + precomp[i - 2]) % MOD;
    }

    int n, m;
    cin >> n >> m;

    vector<int> holes(m);
    vector<int> rocks;
    rocks.pb(0);
    bool possible = true;

    for (int i = 0; i < m; i++) {
        cin >> holes[i];
    }

    // radix sort holes
    sort(all(holes));

    for (int i = 0; i < m; i++) {
        if (holes[i] != 1) rocks.pb(holes[i] - 1);
        rocks.pb(-1);
        rocks.pb(holes[i] + 1);

        if (i > 0 && holes[i] == holes[i - 1] + 1) possible = false;
    }
    if (rocks.back() != n) rocks.pb(n);
    
    if (!possible) {
        cout << 0 << endl;
        return 0;
    }

    // cout << "ROCKS: ";
    // for (int i = 0; i < rocks.size(); i++) {
    //     cout << setw(2) << rocks[i] << ' ';
    // }
    // cout << endl;

    vector<int> cnt(rocks.size());
    cnt[0] = 1;

    int i = 1;
    while (i < rocks.size()) {
        if (rocks[i] == -1) {
            // hole
            cnt[i + 1] = cnt[i - 1];
            i = i + 2;
        } else {
            // fibonacci
            cnt[i] = 1ll * fib(rocks[i] - rocks[i - 1] + 1) * cnt[i - 1] % MOD;
            i++;
        }
    }

    // cout << "HOLES: ";
    // for (int i = 0; i < rocks.size(); i++) {
    //     cout << setw(2) << cnt[i] << ' ';
    // }
    // return 0;

    cout << cnt.back() << endl;

    return 0;
}