/**
* @file Word.cpp
* https://codeforces.com/contest/59/problem/A
*
* Created on 2025-04-11 at 01:01:25
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
    string s;
    cin >> s;

    int lower = 0, upper = 0;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') upper++;
        else lower++;
    }

    if (lower >= upper) {
        for (auto c : s) {
            if (c >= 'A' && c <= 'Z') cout << (char)(c - 'A' + 'a');
            else cout << c;
        }
        cout << endl;
    } else {
        for (auto c : s) {
            if (c >= 'a' && c <= 'z') cout << (char)(c - 'a' + 'A');
            else cout << c;
        }
        cout << endl;
    }
    
    return 0;
}