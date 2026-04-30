/**
* @file Uniqueness .cpp
* https://atcoder.jp/contests/abc398/tasks/abc398_c
*
* Created on 2025-03-22 at 09:13:59
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
    int n;
    cin >> n;

    map<int, int> mp;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) cin >> vec[i];

    mp[vec[0]] = 1;
    for (int i = 1; i < n; i++) {
        if (mp.find(vec[i]) != mp.end()) {
            mp[vec[i]]++;
        } else {
            mp[vec[i]] = 1;
        }
    }

    int mx = 0;

    for (auto x : mp) {
        if (x.second == 1) {
            if (x.first > mx) {
                mx = x.first; 
            }
        }
    }    

    int ans = -1;

    for (int i = 0; i < n; i++) {
        if (vec[i] == mx) {
            ans = i + 1;
            break;
        }
    }
    
    cout << ans << endl;

    return 0;
}