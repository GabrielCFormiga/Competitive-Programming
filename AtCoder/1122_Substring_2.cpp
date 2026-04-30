/**
* @file 1122 Substring 2.cpp
* @author GabrielCampelo
* Created on 2025-11-25 at 00:52:57
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
    string s;
    cin >> s;

    int ans = 0;
    int i = 0;
    int len = 1;

    while (i + 1 < s.size()) {
        while (i + 1 < s.size() && s[i + 1] == s[i]){
            len++;
            i++;
        }

        if (i + 1 == s.size()) break;
        else if (s[i] + 1 != s[i + 1]) {
            len = 1;
            i = i + 1;
            continue;
        }

        int aux = len;
        len = 1;
        i = i + 1;
        while (i + 1 < s.size() && s[i + 1] == s[i]) {
            len++;
            i++;
        }

        ans += min(aux, len);
    }

    cout << ans << endl;
    
    return 0;
}