/**
* @file ll.cpp
*
* Created on 2025-06-10 at 16:00:32
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

    if (n == 2) {
        int k;
        cin >> k;

        vector<int> vec(k);
        for (int i = 0; i < k; i++) cin >> vec[i];

        cin >> k;
        vector<int> aux(k);
        for (int i = 0; i < k; i++) cin >> aux[i];
        for (int i = k - 1; i >= 0; i--) vec.pb(aux[i]); 

        bool possible = true;
        int l = 0;
        while (l < vec.size() && vec[l] == 1) l++;
        for (int i = l; i < vec.size(); i++) {
            if (vec[i] == 1) {
                possible = false;
                break;
            }
        }

        if (possible) cout << 'S' << endl;
        else cout << 'N' << endl;
    } else {
        for (int i = 0; i < n; i++) {
            int k, x;
            cin >> k;
            while (k--) cin >> x;
        }
        cout << 'S' << endl;
    }
    
    return 0;
}