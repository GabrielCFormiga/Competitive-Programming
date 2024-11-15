/**
* @file Many_Formulas.cpp
* https://atcoder.jp/contests/arc061/tasks/arc061_a
*
* Created on 2024-11-15 at 15:09:36
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
    string n;
    cin >> n;

    int len = n.size();
    
    // 0 1 2 
    // 1 2 5     -> len
    //   0   1
    // 1 + 2 + 5 -> len - 1 '+'s
           
    reverse(all(n));

    ll ans = 0;  
    for (int mask = 0; mask < (1LL << (len - 1)); mask++) {
        ll sum = n[0] -'0';
        int mult = 1;
        
        for (int j = 1; j < len; j++) {
            if (mask & (1LL << (j - 1))) {
                sum += n[j] - '0';
                mult = 1;
            } else {
                sum += (n[j] - '0') * pow(10, mult);
                mult++;
            }
        }
        
        ans += sum;
    }

    cout << ans << endl;

    return 0;
    }