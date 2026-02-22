/**
* @file Yet_Another_Array_Problem.cpp
* @author GabrielCampelo
* Created on 2026-02-19 at 16:39:06
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

const int MAX_N = 100100;

int n;
ll ar[MAX_N];

int main() { _
    vector<bool> isprime(200, true);
    vector<int> primes;
    for (int i = 2; i < 200; i++) {
        if (isprime[i]) {
            primes.pb(i);
            for (int j = i * i; j < 200; j += i) {
                isprime[j] = false;
            }
        }
    }

    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            cin >> ar[i];
        }

        int ans = -1;
        for (int p : primes) {
            for (int i = 1; i <= n; i++) {
                if (__gcd(ar[i], (ll)p) == 1) {
                    ans = p;
                    break;    
                }
            }
            if (ans != -1) break;
        }

        cout << ans << endl;
    } 
    
    return 0;
}