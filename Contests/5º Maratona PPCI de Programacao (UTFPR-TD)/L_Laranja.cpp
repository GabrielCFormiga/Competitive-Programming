/**
* @file L_Laranja.cpp
* @author GabrielCampelo
* Created on 2026-07-25 at 10:56:30
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
    
    vector<ll> fat(13);
    fat[0] = 1;
    for (int i = 1; i <= 12; i++) {
        fat[i] = fat[i - 1] * i;
    }

    int curr = 0;
    while (n--) {
        int g, c;
        cin >> g >> c;
        curr = curr + g - c;

        if (curr > 12) {
            cout << -1 << endl;
            continue;
        }

        ll ans = 0;

        for (int x = 0; x <= 4; x++) {
            for (int y = 0; y <= 4; y++) {
                for (int z = 0; z <= 4; z++) {
                    if (x + y + z > curr) break;
                    if (x + y + z < curr) continue;

                    ans += fat[curr] / fat[x] / fat[y] / fat[z];
                }
            }   
        }

        cout << ans << endl;
    }
    
    return 0;
}