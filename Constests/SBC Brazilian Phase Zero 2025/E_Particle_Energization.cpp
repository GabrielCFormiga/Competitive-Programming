/**
* @file e.cpp
*
* Created on 2025-05-24 at 14:23:58
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
    ll y, k;
    cin >> y >> k;

    vector<ll> divs;

    for (int i = 2; i * i <= y; i++) {
        if (y % i == 0) {
            divs.push_back(i);
            if (i*i != y) divs.push_back(y/i);
        }
    }

    sort(all(divs)); 
    divs.pb(y);  
    
    ll x = 1;
    ll curr_gcd = 1;
    ll next_gcd = divs[0];

    int pos = 0;
    
    while (k > 0) {
        ll steps_to = (next_gcd - x) / curr_gcd;
        
        if (steps_to >= k) {
            x += curr_gcd * k;
            break; 
        } else {
            x = next_gcd;
            k -= steps_to;
            curr_gcd = next_gcd;
            pos++;
        }

        if (pos == divs.size()) {
            x += y * k;
            break;
        }

        while (pos < divs.size()) {
            if ((divs[pos] - x) % curr_gcd == 0) {
                next_gcd = divs[pos];
                break;
            } else {
                pos++;
            }
        }    
    }

    cout << x << endl;

    return 0;
}