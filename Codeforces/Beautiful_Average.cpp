/**
* @file A_Beautiful_Average.cpp
* @author GabrielCampelo
* Created on 2025-11-18 at 00:57:51
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

        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        
        int ans = 0;

        for (int MASK = (1 << n) - 1; MASK > 0; MASK--) {
            int len = 0;
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (MASK & (1 << j)) {
                    sum += vec[j];
                    len++;
                }
            }
            ans = max(ans, sum / len);
        }

        cout << ans << endl;
    } 
    
    return 0;
}