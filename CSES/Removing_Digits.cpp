/**
* @file Removing Digits.cpp
* @author GabrielCampelo
* Created on 2025-12-01 at 17:51:36
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

#define MAX_N 1000100

int n;
int dp[MAX_N];

int main() { _
    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i] = INF;
        int aux = i;
        while (aux > 0) {
            dp[i] = min(dp[i], dp[i - aux % 10] + 1);
            aux /= 10;
        }
    }
    
    cout << dp[n] << endl;

    return 0;
}