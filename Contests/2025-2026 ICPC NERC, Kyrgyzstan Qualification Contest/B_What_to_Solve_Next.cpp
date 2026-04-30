/**
* @file B_What_to_solve_next.cpp
* @author GabrielCampelo
* Created on 2025-12-16 at 01:33:40
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
    int n, p;
    cin >> n >> p;

    vector<int> solved(p), one_attempt(p), incorrect(p);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            char c;
            cin >> c;
            int k;
            cin >> k;

            if (c == '+') {
                solved[j]++;
                one_attempt[j]++;
                incorrect[j] += k;
            } else if (k > 0) {
                one_attempt[j]++;
                incorrect[j] += k;
            }
        }
    }

    for (int j = 0; j < p; j++) {
        cout << solved[j] << ' ' << one_attempt[j] << ' ' << incorrect[j] << endl;
    }

    return 0;
}