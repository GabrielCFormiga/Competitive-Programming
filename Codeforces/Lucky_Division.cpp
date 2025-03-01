/**
* @file Lucky_Division.cpp
* https://codeforces.com/problemset/problem/122/A
*
* Created on 2025-03-01 at 01:49:48
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

    bool alm_lucky = false;
    int MASK, num, fat;

    for (int i = 1; i <= 3; i++) {
        MASK = (1 << i) - 1;

        for (int s = MASK; s > 0; s = (s - 1) & MASK) {
            num = 0;
            fat = 1;

            for (int j = 0; j < i; j++) {
                if (s & (1 << j)) num += 7 * fat;
                else num += 4 * fat;
                fat *= 10;
            }

            if (n % num == 0) {
                alm_lucky = true;
                break;
            }
        }

        if (alm_lucky) break;

        // case with only 4's
        num = 0;
        fat = 1;

        for (int j = 0; j < i; j++) {
            num += 4 * fat;
            fat *= 10;
        }

        if (n % num == 0) {
            alm_lucky = true;
            break;
        }
    }

    if (alm_lucky) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}