/**
* @file Chat_room.cpp
* https://codeforces.com/problemset/problem/58/A
*
* Created on 2025-03-01 at 01:44:53
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

    char cmp[5] = {'h','e', 'l', 'l', 'o'};

    int j = 0;
    for (int i = 0; i < str.size(); i++) {
        if (j < 5) {
            if (cmp[j] == str[i]) j++;
        } else break;
    }

    cout << (j == 5 ? "YES" : "NO") << endl;
    
    return 0;
}