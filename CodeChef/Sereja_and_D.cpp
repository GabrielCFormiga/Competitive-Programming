/**
* @file Sereja_and_D.cpp
* @author GabrielCampelo
* Created on 2026-02-23 at 15:56:17
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
    int n;
    cin >> n;

    vector<int> vec(n);
    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    for (int i = 0; i < n - 1; i++) {
        diff[i] = vec[i + 1] - vec[i];
    }
    SparseTable<int> st(diff);

    int m;
    cin >> m;
    while (m--) {
        int t, d;
        cin >> t >> d;

        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        
        int l = 0, r = n;
        int m;
        while (l < r) {
            m = l + (r - l + 1) / 2;
            if (vec[m] <= t) l = m;
            else r = m - 1;
        }

        int k = r;

        l = 0, r = k;
        while (l < r) {
            m = l + (r - l) / 2;
            if (st.query(m, k - 1) <= d) r = m;
            else l = m + 1;
        }

        cout << l + 1 << endl;
    }
    
    return 0;
}