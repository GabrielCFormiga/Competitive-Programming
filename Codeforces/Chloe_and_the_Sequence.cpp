/**
* @file Chloe_and_the_sequence.cpp
* https://codeforces.com/problemset/problem/743/B
*
* Created on 2024-10-10 at 15:35:12
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

/* 
    1: 1                                                                len = 1
    2: 1 2 1                                                            len = 3 
    3: 1 2 1 3 1 2 1                                                    len = 7
    4: 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1                                    len = 15
    5: 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1    len = 31

    se k % 2 == 1 -> o numero eh 1
    se k % 2 == 0 -> podemos fazer uma busca binaria
 */

#define MAX_N 50

ll n, k;
ll len[MAX_N + 1];

ll solve() {
    ll mid = (len[n] + 1) / 2;

    if (k == mid) return n;
    
    n--;
    if (k > mid) k = k - mid;
    return solve();
}

int main() { _
    cin >> n >> k;

    // guarda o comprimento da seguencia n
    len[1] = 1;
    for (int i = 2; i <= n; i++) {
        len[i] = 2 * len[i - 1] + 1;
    }

    if (k % 2 == 1) cout << 1 << endl;
    else {
        cout << solve() << endl;
    }

    return 0;
}

/////////////////////////////////////////////////////////
/**
* Versao otimizada com bitmask
*
* @author demon1999
*/

#include <bits/stdc++.h>
  
ll n, k;
int main() {
    cin >> n >> k;
    for (ll j = n - 1; j > 0; j--) {
        if (k == (1LL << j)) {
            cout << j + 1;
            return 0;
        }
        if (k > (1LL << j))
            k -= (1LL << j);
    }
    cout << 1;
}
/////////////////////////////////////////////////////////