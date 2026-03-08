/**
* @file N_Lucky_Number.cpp
* @author GabrielCampelo
* Created on 2026-03-08 at 09:51:00
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

    vector<int> vec(n);
    vector<int> cnt(5);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        cnt[vec[i] % 5]++;
    }

    int x = min(cnt[1], cnt[4]);
    int y = min(cnt[2], cnt[3]);
    cnt[1] -= x;
    cnt[4] -= x;
    cnt[2] -= y;
    cnt[3] -= y;
    int ans = cnt[0] + x + y;

    if (cnt[1] > 0) {
        if (cnt[2] > 0) {
            // (1 e 2)
            // 1) 1 2 2
            int k = min(cnt[1], cnt[2]/2);
            ans += k;
            cnt[1] -= k;
            cnt[2] -= k * 2;
            // 2) 1 1 1 2
            k = min(cnt[1]/3, cnt[2]);
            ans += k;
            cnt[1] -= k * 3;
            cnt[2] -= k;
        } else if (cnt[3] > 0) {
            // (1 e 3)
            // 1) 1 1 3
            int k = min(cnt[1]/2, cnt[3]);
            ans += k;
            cnt[1] -= k * 2;
            cnt[3] -= k;
            // 2) 1 3 3 3
            k = min(cnt[1], cnt[3]/3);
            ans += k;
            cnt[1] -= k;
            cnt[3] -= k * 3;
        }
    } else if (cnt[4] > 0) {
        if (cnt[2] > 0) {
            // (4 e 2)
            // 1) 2 4 4
            int k = min(cnt[4]/2, cnt[2]);
            ans += k;
            cnt[4] -= k * 2;
            cnt[2] -= k;
            // 2) 2 2 2 4
            k = min(cnt[4], cnt[2]/3);
            ans += k;
            cnt[4] -= k;
            cnt[2] -= k * 3;
        } else if (cnt[3] > 0) {
            // (4 e 3)
            // 1) 3 3 4
            int k = min(cnt[4], cnt[3]/2);
            ans += k;
            cnt[4] -= k;
            cnt[3] -= k * 2;
            // 2) 3 4 4 4
            k = min(cnt[4]/3, cnt[3]);
            ans += k;
            cnt[4] -= k * 3;
            cnt[3] -= k;
        }
    }

    ans += cnt[1]/5;
    ans += cnt[2]/5;
    ans += cnt[3]/5;
    ans += cnt[4]/5;
    
    cout << ans << endl;

    return 0;
}