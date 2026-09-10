/**
* @file E_The_Scale_Riddle.cpp
* @author GabrielCampelo
* Created on 2026-08-24 at 15:53:59
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

    int l = 1, r = n;

    while (l < r) {
        int len = r - l + 1;
        if (len == 2) {
            // ESPECIAL
            cout << "? 1";
            cout << " " << l << " " << r;
            cout << endl;

            char c;
            cin >> c;

            if (c == 'E') {
                r = l;
                break;
            } else {
                l = r;
                break;
            }
        } 

        len = len / 3;

        cout << "? " << len;
        for (int i = 0; i < len; i++) {
            cout << " " << l + i;
        }
        for (int i = 0; i < len; i++) {
            cout << " " << l + len + i;
        }
        cout << endl;

        char c;
        cin >> c;

        if (c == 'E') {
            // ESQUERDA
            l = l;
            r = l + len - 1;
        } else if (c == 'D') {
            // DIREITA
            l = l + len;
            r = l + len - 1;
        } else {
            // EMPATE
            l = l + 2 * len;
            r = r;
        }
    }
    
    cout << "! " << l << endl;

    return 0;
}