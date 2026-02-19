/**
* @file Nearest_Smaller_Values.cpp
* @author GabrielCampelo
* Created on 2026-02-19 at 04:21:44
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

int main() { _
    int n;
    cin >> n;

    vector<int> vec(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }

    stack<pair<int, int>> st; // {val, ind}
    st.push({0, 0});

    for (int i = 1; i <= n; i++) {
        while (st.top().first >= vec[i]) st.pop();
        cout << st.top().second << (i == n ? endl : ' ');
        st.push({vec[i], i});
    }

    return 0;
}