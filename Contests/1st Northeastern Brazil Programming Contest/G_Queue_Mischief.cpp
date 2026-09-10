/**
* @file G_Queue_Mischief.cpp
* @author GabrielCampelo
* Created on 2026-08-24 at 15:25:53
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
    deque<char> dq;
    ll a = 0, b = 0, ans = 0;
    int q;
    cin >> q;

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            // INSERE C NO FINAL
            char c;
            cin >> c;

            if (c == 'B') {
                ans += a;
                b++;
            } else {
                a++;
            }

            dq.emplace_back(c);
        } else if (op == 2) {
            // INSERE C NO INICIO
            char c;
            cin >> c;

            if (c == 'B') {
                b++;
            } else {
                ans += b;
                a++;
            }

            dq.emplace_front(c);
        } else if (op == 3) {
            // REMOVE NO FINAL
            char c;
            c = dq.back();
            dq.pop_back();

            if (c == 'B') {
                ans -= a;
                b--;
            } else {
                a--;
            }

        } else {
            // REMOVE NO INICIO
            char c;
            c = dq.front();
            dq.pop_front();

            if (c == 'B') {
                b--;
            } else {
                ans -= b;
                a--;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}