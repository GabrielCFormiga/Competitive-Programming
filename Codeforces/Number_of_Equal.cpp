/**
* @file Number_of_Equal.cpp
* https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
*
* Created on 2024-11-19 at 18:03:01
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

int main() { _
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0;
    ll ans = 0;
    while (i < n) {
        int curr = a[i];
        int cnt_a = 1;
        
        while (i + 1 < n && a[i + 1] == curr) {
            cnt_a++;
            i++;
        }

        int cnt_b = 0;
        while (j < m && b[j] < curr) j++;
        while (j < m && b[j] == curr) {
            j++;
            cnt_b++;
        }

        ans += 1ll * cnt_a * cnt_b;
        i++;
    }

    cout << ans << endl;
    
    return 0;
}