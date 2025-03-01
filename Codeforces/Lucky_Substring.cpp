/**
* @file Lucky_Substring.cpp
* https://codeforces.com/contest/122/problem/B
*
* Created on 2025-03-01 at 02:16:05
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

    int cnt4 = 0, cnt7 = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '4') cnt4++;
        if (s[i] == '7') cnt7++;
    }

    if (cnt4 == 0 && cnt7 == 0) cout << -1;
    else if (cnt4 >= cnt7) cout << 4;
    else cout << 7;
    cout << endl;

    return 0;
}