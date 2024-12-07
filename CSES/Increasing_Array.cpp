/**
* @file Increasing_Array.cpp
* https://cses.fi/alon/task/1094
*
* Created on 2024-12-06 at 09:45:05
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

int main() { _
    int n, curr, prev = 0;

    cin >> n;

    ll ans = 0;
    while (n--) {
        cin >> curr;

        if (curr < prev) ans += prev - curr;
        else prev = curr;
    }

    cout << ans << endl;

    return 0;
}