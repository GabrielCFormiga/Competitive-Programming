/**
* @file Colorful_Stones_Simplified_Edition.cpp
*
* Created on 2025-06-09 at 18:02:50
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
    string s, t;

    cin >> s >> t;

    int pos = 0;

    for (char c : t) {
        if (c == s[pos]) pos++;
    }

    cout << pos + 1 << endl;

    return 0;
}