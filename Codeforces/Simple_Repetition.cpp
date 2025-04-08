/**
* @file Simple_Repetition.cpp
* https://codeforces.com/contest/2093/problem/C
*
* Created on 2025-04-08 at 19:56:18
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
    int tt;
    cin >> tt;
 
    while (tt--) {
        int x, k;
        cin >> x >> k;
 
        bool is_prime_x = (x == 1 ? false: true);
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                is_prime_x = false;
                break;
            }
        }
 
        int kk = 1;
        for (int i = 1; i <= k; i++) kk *= 10;
        kk = (kk - 1) / 9;
 
        bool is_prime_kk = (kk == 1 ? false : true);
        for (int i = 2; i * i <= kk; i++) {
            if (kk % i == 0) {
                is_prime_kk = false;
                break;
            }
        }
 
        if ((is_prime_x && k == 1) || (x == 1 && is_prime_kk)) cout << "yes" << endl;
        else cout << "no" << endl;
    } 
    
    return 0;
}