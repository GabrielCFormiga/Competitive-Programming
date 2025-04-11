/**
* @file Buy_a_Shovel.cpp
* https://codeforces.com/contest/732/problem/A
*
* Created on 2025-04-11 at 13:26:53
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
    int k, r;
    cin >> k >> r;

    int ans = 1;
    int sum = k;
    while (sum % 10 != 0 && sum % 10 != r) {
        sum = (sum + k) % 10;
        ans++;
    }

    cout << ans << endl;

    return 0;
}