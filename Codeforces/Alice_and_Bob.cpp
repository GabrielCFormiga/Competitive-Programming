/**
* @file a.cpp
* @author GabrielCampelo
* Created on 2025-11-14 at 11:37:29
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

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n, a;
        cin >> n >> a;

        int ans1 = a - 1;
        int cnt1 = 0;
        int ans2 = a + 1;
        int cnt2 = 0;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
            if (abs(ans1 - vec[i]) < abs(a - vec[i])) cnt1++;
            if (abs(ans2 - vec[i]) < abs(a - vec[i])) cnt2++;
        }

        if (cnt1 > cnt2) cout << ans1 << endl;
        else cout << ans2 << endl;
    } 
    
    return 0;
}