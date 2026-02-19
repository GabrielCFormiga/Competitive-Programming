/**
* @file Sum_of_Subarray_Minimums.cpp
* @author GabrielCampelo
* Created on 2026-02-19 at 05:31:46
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

int main() { _
    int n;
    cin >> n;
    
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }

    stack<pair<int, int>> st; // {h, ind}
    st.push({0, 0});

    vector<int> left(n + 1);
    for (int i = 1; i <= n; i++) {
        while (st.top().first >= vec[i]) st.pop();
        left[i] = st.top().second;
        st.push({vec[i], i});
    }

    while (!st.empty()) st.pop();
    st.push({0, n + 1});

    vector<int> right(n + 1);
    for (int i = n; i >= 1; i--) {
        while (st.top().first > vec[i]) st.pop();
        right[i] = st.top().second;
        st.push({vec[i], i});
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = (sum + 1ll * vec[i] * (i - left[i]) % MOD * (right[i] - i) % MOD) % MOD;
    }

    cout << sum << endl;

    return 0;
}