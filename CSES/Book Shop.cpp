/**
* @file Book Shop.cpp
* @author GabrielCampelo
* Created on 2025-12-01 at 00:35:54
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

#define MAX_N 1100
#define MAX_X 100100

int n, x;
int prices[MAX_N];
int pages[MAX_N];
int dp[MAX_X];

int main() { _
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = x; j - prices[i] >= 0; j--) {
            dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
        }
    }

    cout << dp[x] << endl;
    
    return 0;
}