/**
* @file Maximum_Subarray_Sum.cpp
* https://cses.fi/problemset/task/1643
* Kadane
*
* Created on 2025-03-07 at 09:56:19
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
    int  n;
    cin >> n;

    ll curr = -INF, mx = -INF, aux;

    for (int i = 0; i < n; i++) {
        cin >> aux;

        curr = max(curr + aux, aux);
        mx = max(mx, curr);
    }

    cout << mx << endl;
    
    return 0;
}