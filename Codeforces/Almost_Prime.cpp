/**
* @file Almost_Prime.cpp
* @author GabrielCampelo
* Created on 2026-02-19 at 12:26:39
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;
using llu = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n;
    cin >> n;

    int cnt = 0;

    for (int i = 6; i <= n; i++) {
        int x = i;
        int diff = 0;
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                diff++;
                while (x % j == 0) x /= j;
            }
        }
        if (x > 1) diff++;
        if (diff == 2) cnt++;
    }

    cout << cnt << endl;

    return 0;
}