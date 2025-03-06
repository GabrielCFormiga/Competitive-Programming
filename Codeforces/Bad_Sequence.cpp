/**
* @file Bad_Sequence.cpp
* https://codeforces.com/problemset/problem/1214/C
*
* Created on 2025-03-06 at 14:11:13
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

    if (n % 2 == 1 || count(str.begin(), str.end(), '(') != n / 2) {
        cout << "No" << endl;
        return 0;
    }
    
    vector<char> vec;

    for (auto c : str) {
        if (c == '(') {
            vec.pb(c);
        } else {
            if (!vec.empty()) vec.pop_back();
        }
    }

    cout << (vec.size() <= 1 ? "Yes" : "No") << endl;

    return 0;
}