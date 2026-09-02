/**
* @file J_The_Brega_Game.cpp
* @author GabrielCampelo
* Created on 2026-08-24 at 15:42:07
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
        return std::max(a, b); 
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
    int n, q;
    cin >> n >> q;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    SparseTable<int> st(vec);

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int len = r - l + 1;
        int mx = st.query(l, r);

        if (len == 1 || len % 2 == 0 || vec[l] == mx || vec[r] == mx) {
            cout << "Adilson" << endl;
        } else {
            cout << "Reginaldo" << endl;
        }
    }

    return 0;
}