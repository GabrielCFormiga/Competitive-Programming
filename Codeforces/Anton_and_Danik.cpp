/**
* @file Anton_and_Danik.cpp
* https://codeforces.com/contest/734/problem/A
*
* Created on 2025-04-09 at 16:44:25
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

    int cntA = 0, cntD = 0;
    for (auto c : str) {
        if (c == 'A') cntA++;
        else cntD++;
    }

    if (cntA > cntD) cout << "Anton" << endl;
    else if (cntD > cntA) cout << "Danik" << endl;
    else cout << "Friendship" << endl;
    
    return 0;
}