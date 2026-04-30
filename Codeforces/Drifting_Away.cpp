/**
* @file b.cpp
* @author GabrielCampelo
* Created on 2025-11-14 at 11:46:22
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
        string s;
        cin >> s;

        bool infinity = false;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '>' && s[i + 1] == '<') {
                infinity = true;
                break;
            }
            if (s[i] == '*' && s[i + 1] == '*') {
                infinity = true;
                break;
            }
            if (s[i] == '*' && s[i + 1] == '<') {
                infinity = true;
                break;
            }
            if (s[i] == '>' && s[i + 1] == '*') {
                infinity = true;
                break;
            }
        }

        if (infinity) {
            cout << -1 << endl;
            continue;
        }

        int ans1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '<') {
                ans1++;
            } else if (s[i] == '>') {
                break;
            } else if (s[i] == '*') {
                ans1++;
                break;
            }
        }

        int ans2 = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '>') {
                ans2++;
            } else if (s[i] == '<') {
                break;
            } else if (s[i] == '*') {
                ans2++;
                break;
            }
        }

        cout << max(ans1, ans2) << endl;
    } 
    
    return 0;
}