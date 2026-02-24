/**
* @file Ant_colony.cpp
* @author GabrielCampelo
* Created on 2026-02-23 at 10:31:23
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
struct SparseTableGCD {
    vector<vector<T>> st;
    int n, k; // k = 24 is enough for n <= 10^7

    T op(T a, T b) { 
        return __gcd(a, b); 
    }

    SparseTableGCD(const vector<T> &vec) {
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

template <typename T>
struct SparseTableMin {
    vector<vector<T>> st;
    int n, k; // k = 24 is enough for n <= 10^7

    T op(T a, T b) { 
        return std::min(a, b); 
    }

    SparseTableMin(const vector<T> &vec) {
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
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        mp[vec[i]].pb(i);
    }

    SparseTableGCD<int> stGCD(vec);
    SparseTableMin<int> stMin(vec);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int ans = r - l + 1;
        int gcd = stGCD.query(l, r);
        int mn = stMin.query(l, r); 

        if (gcd == mn) {
            // ans -= qtd de valores == Min em [l, r]

            // valor mas a esquerda >= l
            int left = 0, right = mp[mn].size() - 1;
            int mid;
            while (left < right) {
                mid = left + (right - left) / 2;
                if (mp[mn][mid] >= l) right = mid;
                else left = mid + 1;
            }
            int lb = left;

            // valor mais a direta <= r
            left = 0, right = mp[mn].size() - 1;
            while (left < right) {
                mid = left + (right - left + 1) / 2;
                if (mp[mn][mid] <= r) left = mid;
                else right = mid - 1;
            }
            int up = left;

            ans -= up - lb + 1;
        } 
        cout << ans << endl;
    }

    return 0;
}