/**
* @file Maximum_modulo_equality.cpp
* @author GabrielCampelo
* Created on 2026-02-22 at 19:41:04
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

template <typename T>
struct SparseTable {
    vector<vector<T>> st;
    int n, k; // k = 24 is enough for n <= 10^7

    T op(T a, T b) { 
        return __gcd(a, b); 
    }

    SparseTable(const vector<T> &vec) {
        n = vec.size();
        k = __lg(n) + 1;
        st.assign(k + 1, vector<T>(n));
        for (int j = 0; j < n; j++) st[0][j] = vec[j];
        for (int i = 1; i <= k; i++) 
            for (int j = 0; j + (1 << i) <= n; j++) 
                st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }

    T query(int l, int r) {
        int i = __lg(r - l + 1);
        return op(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;

        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        vector<int> diff(n - 1);
        for (int i = 0; i < n - 1; i++) {
            diff[i] = abs(vec[i] - vec[i + 1]);
        }

        SparseTable<int> st(diff);

        bool first = true;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            if (first) first = false;
            else cout << ' ';

            if (l == r) {
                cout << 0;
            } else {
                cout << st.query(l, r - 1);
            }
        }
        cout << endl;
    } 
    
    return 0;
}