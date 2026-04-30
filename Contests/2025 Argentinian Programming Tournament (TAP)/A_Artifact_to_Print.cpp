/**
* @file A_Artifact_to_print.cpp
* @author GabrielCampelo
* Created on 2026-02-08 at 08:26:21
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
    char tap[3] = {'T', 'A', 'P'};
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (j == 3) break;
        if (s[i] == tap[j]) j++;
    }
    if (j == 3) cout << 'S' << endl;
    else cout << 'N' << endl;

    return 0;
}