/**
* @file Coprime.cpp
* @author GabrielCampelo
* Created on 2026-01-02 at 13:35:32
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
        int n;
        cin >> n;

        vector<int> vec(n + 1);
        vector<int> ind(1001);

        for (int i = 1; i <= n; i++) {
            cin >> vec[i];
            ind[vec[i]] = i;
        }

        int ans = -1;

        for (int i = 1; i <= 1000; i++) {
            if (ind[i] == 0) continue;
            for (int j = i; j <= 1000; j++) {
                if (ind[j] == 0) continue;
                if (__gcd(i, j) == 1) {
                    ans = max(ans, ind[i] + ind[j]);
                }    
            }
        }

        cout << ans << endl;
    } 
    
    return 0;
}