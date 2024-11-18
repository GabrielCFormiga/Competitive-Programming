/**
* @file Guess_a_number!.cpp
* https://codeforces.com/problemset/problem/416/A
*
* Created on 2024-11-17 at 21:55:39
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

int main() { _
    ll n;
    cin >> n;

    string sign;
    ll x;
    char answer;
    ll l = -2e9, r = 2e9;
    while (n--) {
        cin >> sign >> x >> answer;

        if (sign == ">") {
            if (answer == 'Y') l = max(l, x + 1);
            else r = min(r, x);
        } else if (sign == ">=") {
            if (answer == 'Y') l = max(l, x);
            else r = min(r, x - 1);
        } else if (sign == "<") {
            if (answer == 'Y') r = min(r, x - 1);
            else l = max(l, x);
        } else if (sign == "<=") {
            if (answer == 'Y') r = min(r, x);
            else l = max(l, x + 1);
        }
    } 

    if (l <= r) cout << l << endl;
    else cout << "Impossible" << endl;
    
    return 0;
}