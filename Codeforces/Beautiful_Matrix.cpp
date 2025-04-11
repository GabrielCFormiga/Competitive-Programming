/**
* @file Beautiful_Matrix.cpp
* https://codeforces.com/contest/263/problem/A
*
* Created on 2025-04-09 at 19:01:43
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
    int n = 5;
    int x, ans;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> x;
            if (x == 1) {
                ans = abs(3 - i) + abs (3 - j);
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}