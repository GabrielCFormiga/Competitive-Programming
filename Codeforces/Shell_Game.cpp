/**
* @file Shell_Game.cpp
* https://codeforces.com/problemset/problem/777/A
*
* Created on 2025-03-06 at 04:19:32
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

/* 
    caso 4 2
    fim: 0 0 *
    desfaz 4: 0 * 0 -> x = 1
    desfaz 3: * 0 0 -> x = 0
    desfaz 2: * 0 0 -> x = 0
    desfaz 1: 0 * 0 -> x = 1
 */

int main() { _
    int n, x;
    cin >> n >> x;

    n %= 6;

    if (n == 0) {
        cout << x << endl;
        return 0;
    }

    do {
        if (n % 2 == 1 && x != 2) {
            // swap 0 1
            x = 1 - x;
        } else if (n % 2 == 0 && x != 0) {
            // swap 1 2
            x = 3 - x;
        }
        n--;
    } while (n > 0);

    cout << x << endl;

    return 0;
}