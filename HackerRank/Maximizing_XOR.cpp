/**
* @file Maximizing_XOR .cpp
* https://www.hackerrank.com/challenges/maximizing-xor/problem
*
* força bruta passa, mas tem uma versão mais difícil desse problema -> https://codeforces.com/problemset/problem/276/D
*
* Created on 2024-11-15 at 14:58:41
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
    int l, r;
    cin >> l >> r;

    int ans = 0;
    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            ans = max(ans, i^j);
        }
    }
    
    cout << ans << endl;

    return 0;
}