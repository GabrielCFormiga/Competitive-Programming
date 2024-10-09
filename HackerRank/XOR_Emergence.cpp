/**
* @file XOR_Emergence.cpp
* https://www.hackerrank.com/contests/algoritmos-2018-i-contest-1/challenges/xor-emergence/problem
*
* Created on 2024-10-08 at 16:20:37
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

#define MOD 1000000007

// O(n)
int bin_to_int(string s) {
    int ans = 0;
    int pot = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1') ans += pot;
        pot *= 2;
    }
    return ans;
}

int main() { _
    int n, q;
    cin >> n >> q;

    // O(n)
    vector<int> vec(n);
    for (int i = n - 1; i >= 0; i--) {
        cin >> vec[i];
    }

    // O(n * 2^n)
    vector<int> dp((1 << n));
    for (int i = 1; i < (1 << n); i++) {
        int aux = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) aux ^= vec[j];
        }
        dp[i] = aux;
    }

    // O(q * (n + 2^n))
    string query;
    while (q--) {
        cin >> query;
        int mask = bin_to_int(query);

        ll sum  = 0;
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
            sum = (sum + dp[submask]) % MOD; 
        }
        cout << sum << endl;
    }
    
    return 0;
}