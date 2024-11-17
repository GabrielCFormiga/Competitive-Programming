/**
* @file Books.cpp
* https://codeforces.com/problemset/problem/279/B
*
* Created on 2024-11-17 at 16:47:58
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

int n, t;
int books[MAX_N];

int main() { _
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> books[i];

    int ans = 0;
    int l = 0, r = 0, sum = 0;

    while (r < n) {
        sum += books[r];

        while (sum > t && l <= r) {
            sum -= books[l];
            l++;
        }

        ans = max(ans, r - l + 1);
        r++;
    }
    
    cout << ans << endl;
    
    return 0;
}