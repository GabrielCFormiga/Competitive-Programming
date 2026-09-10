/**
* @file D_Crazy_Decoder.cpp
* @author GabrielCampelo
* Created on 2026-08-24 at 16:43:33
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

llu equations[32];
llu s;

int main() { _
    int n, k;
    cin >> n >> k >> s;     
    
    for (int i = 0; i < 32; i++) {
        equations[i] = (1u << i);
    }

    while (n--) {
        llu aux[32];
        for (int i = 0; i < k; i++) {
            aux[i] = 0;
        }
        for (int i = k; i < 32; i++) {
            aux[i] = equations[i - k];
        }

        for (int i = 0; i < 32; i++) {
            equations[i] = equations[i] ^ aux[i];
        }
    }

    vector<int> x(32, -1);

    for (int j = 0; j < 32; j++) {
        llu equation = equations[j];
        int ans = 0;
        if (s & (1 << j)) ans = 1;

        int curr = 0;
        for (int i = 0; i < 32; i++) {
            if (equation & (1 << i)) {
                if (x[i] != -1) {
                    curr = curr ^ x[i];
                } else {
                    // x[i] ^curr = ans
                    x[i] = curr ^ ans;
                    break;
                }
            }
        }
    }

    llu ans = 0;
    llu aux = 1;
    for (int i = 0; i < 32; i++) {
        if (x[i] == 1) {
            ans |= aux;
        }
        aux = aux << 1;
    }
    cout << ans << endl;

    // cout << "EQUATIONS: " << endl;
    // for (int j = 0; j < 32; j++) {
    //     llu equation = equations[j];
    //     bool first = true;

    //     for (int i = 0; i < 32; i++) {
    //         if (equation & (1 << i)) {
    //             if (first) {
    //                 cout << "X" << i;
    //                 first = false;
    //             } else {
    //                 cout << " ^ X" << i;
    //             }
    //         }
    //     }

    //     cout << " = ";
    //     if (s & (1 << j)) cout << 1 << endl;
    //     else cout << 0 << endl;
    // }

    return 0;
}