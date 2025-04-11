/**
* @file Stones_on_the_Table.cpp
* https://codeforces.com/contest/266/problem/A
*
* Created on 2025-04-11 at 03:26:29
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
    string str;

    cin >> n >> str;

    int cnt = 0;
    
    for (int i = 1; i < str.size(); i++) {
        if (str[i] == str[i - 1]) cnt++;
    }

    cout << cnt << endl;
    
    return 0;
}