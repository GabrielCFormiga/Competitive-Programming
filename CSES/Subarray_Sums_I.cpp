/**
* @file Subarray_Sums_I.cpp
* https://cses.fi/problemset/task/1660
*
* Created on 2025-03-06 at 14:25:57
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

#define MAX_N 200100

int n, x;
int ar[MAX_N];

int main() { _
    cin >> n >> x;

    int l = 0, r = 0, curr = 0, cnt = 0;

    for (r; r < n; r++) {
        cin >> ar[r];
        curr += ar[r];

        while (curr > x) {
            curr -= ar[l++];
        }

        if (curr == x) cnt++;
    }

    cout << cnt << endl;
    
    return 0;
}