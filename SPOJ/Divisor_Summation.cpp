/**
* @file Divisor_Summation.cpp
* @author GabrielCampelo
* Created on 2026-02-21 at 21:21:01
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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << 0 << endl;
            continue;
        }

        ll sum = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int d = n / i;
                sum += i;
                if (d != i) sum += d;
            }
        }

        cout << sum << endl;
    } 
    
    return 0;
}