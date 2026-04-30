// WA 33

/**
* @file ee.cpp
*
* Created on 2025-06-10 at 17:11:37
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

#define MAX_N 100100

pair<int, int> ar[MAX_N];

int main() { _
    int n, d;
    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        cin >> ar[i].first >> ar[i].second;
    }

    sort(ar, ar + n);

    int mx = 0, mx_l = 0, mx_r = 0, sum = 0, l = 0, r = 0;

    while (r < n) {
        if (ar[r].first - ar[l].first <= d) {
            sum += ar[r].second;
            if (sum > mx) {
                mx = sum;
                mx_l = l;
                mx_r = r;
            }
            r++;
        } else {
            while (l < r && ar[r].first - ar[l].first > d) {
                sum -= ar[l].second;
                l++;
            }
        }
    }

    // cout << mx << ' ' << mx_l << ' ' << mx_r;
    int ans = mx;

    for (int i = mx_l; i <= mx_r; i++) ar[i].second = 0;

    mx = 0, mx_l = 0, mx_r = 0, sum = 0, l = 0, r = 0;

    while (r < n) {
        if (ar[r].first - ar[l].first <= d) {
            sum += ar[r].second;
            if (sum > mx) {
                mx = sum;
                mx_l = l;
                mx_r = r;
            }
            r++;
        } else {
            while (l < r && ar[r].first - ar[l].first > d) {
                sum -= ar[l].second;
                l++;
            }
        }
    }

    // cout << mx << ' ' << mx_l << ' ' << mx_r;

    ans += mx;

    cout << ans << endl;
    
    return 0;
}