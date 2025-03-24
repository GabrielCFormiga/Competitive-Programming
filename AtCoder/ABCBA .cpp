/**
* @file ABCBA .cpp
* https://atcoder.jp/contests/abc398/tasks/abc398_f
*
* Created on 2025-03-22 at 10:24:01
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
    string str;
    cin >> str;

    int n;
    for (n = str.size(); n >= 2; n--) {
        int r = str.size() - 1;
        int l = str.size() - n;

        bool pal = true;

        while (l < r) {
            if (str[l++] != str[r--]) {
                pal = false;
                break;
            }
        }
        
        if (pal) break;
    }

    cout << str;
    for (int i = str.size() - n - 1; i >= 0; i--) cout << str[i];
    cout << endl; 

    return 0;
}