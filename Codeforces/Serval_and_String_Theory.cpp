/**
* @file Serval_and_String_Theory.cpp
* https://codeforces.com/contest/2085/problem/A
*
* Created on 2025-03-22 at 11:19:12
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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;

        string str;
        cin >> str;

        if (n == 1) {
            cout << "no" << endl;
            continue;
        }

        bool pal = true;
        bool diff = false;
        int l = 0, r = n - 1;

        int pos = 1;
        while (l < r) {
            if (str[pos] != str[pos - 1]) diff = true;
            pos++;

            if (str[l++] != str[r--]) {
                pal = false;
                break;
            }
        }

        if (pal && diff && k) {
            cout << "yes" << endl;
            continue;
        }

        l = 0, r = n - 1;

        int cnt = 0;
        bool universal = false;
        while (l < r) {
            if (str[l] < str[r]) {
                universal = true;
                break;
            } else if (str[r] < str[l]) {
                // faça troca otima, procure um menor, ou igual
                cnt++;
                universal = true;
                break;
            }
            l++;
            r--;
        }

        if (universal && cnt <= k) cout << "yes" << endl;
        else cout << "no" << endl;
    } 
    
    return 0;
}