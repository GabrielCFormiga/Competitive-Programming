/**
* @file Around_Square.cpp
*
* Created on 2025-10-27 at 16:02:14
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
    int n;
    cin >> n;

    int ans = 1;

    while ((ans + 1) * (ans + 1) <= n) {
        ans++;
    }

    cout << ans * ans << endl;

    return 0;
}