/**
* @file B_Beautiful_String.cpp
* @author GabrielCampelo
* Created on 2025-11-18 at 01:03:54
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

        string s;
        cin >> s;

        bool find = false;

        for (int MASK = (1 << n) - 1; MASK >= 0; MASK--) {
            bool nondec = true;
            char prev = '0';
            char curr;
            vector<int> ans;
            string x = "";
            for (int j = 0; j < n; j++) {
                if (MASK & (1 << j)) {
                    ans.pb(j + 1);
                    curr = s[j];
                    if (curr < prev) {
                        nondec = false;
                        break;
                    } else {
                        prev = curr;
                    }
                } else {
                    x += s[j];
                }
            }
            
            if (!nondec) continue;

            bool ispal = true;

            int l = 0, r = x.size() - 1;
            while (l < r) {
                if (x[l] != x[r]) {
                    ispal = false;
                    break;
                }
                l++;
                r--;
            }

            if (ispal) {
                find = true;
                cout << ans.size() << endl;
                for (int i = 0; i < ans.size(); i++) {
                    cout << ans[i] << (i == ans.size() - 1 ? endl : ' ');
                }
                break;
            }
        }

        if (!find) cout << -1 << endl;
    } 
    
    return 0;
}