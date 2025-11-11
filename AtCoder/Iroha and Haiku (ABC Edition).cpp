/**
* @file Iroha and Haiku (ABC Edition).cpp
*
* Created on 2025-11-10 at 13:26:30
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
    int cnt5 = 0;
    int cnt7 = 0;

    int x;

    for (int i = 0; i < 3; i++) {
        cin >> x;
        if (x == 5) cnt5++;
        if (x == 7) cnt7++;
    }
    
    if (cnt5 == 2 && cnt7 == 1) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}