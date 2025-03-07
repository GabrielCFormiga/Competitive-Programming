/**
* @file Subarray_Sums_II.cpp
* https://cses.fi/problemset/task/1661
*
* Created on 2025-03-06 at 14:56:40
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

    map<ll, int> sums;

    sums[0] = 1;

    ll prefix = 0, aux, cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        prefix += aux;
        cnt += sums[prefix - x];
        sums[prefix]++;
    }

    cout << cnt << endl;

    return 0;
}