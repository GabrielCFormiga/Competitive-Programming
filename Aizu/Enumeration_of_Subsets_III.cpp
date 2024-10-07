/**
* @file Enumeration_of_Subsets_III.cpp
* https://judge.u-aizu.ac.jp/onlinejudge/submission.jsp#submit/ITP2_11_C
*
* Created on 2024-10-07 at 02:02:29
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
    int n, k;
    cin >> n >> k;

    int mask = 0;
    while (k--) {
        int x;
        cin >> x;
        mask |= (1 << x);
    }

    stack<int> ans;
    for (int s = mask; s > 0; s = (s - 1) & mask) {
        ans.push(s);
    }

    cout << "0:\n";
    while (!ans.empty()) {
        int subset = ans.top();
        ans.pop();

        cout << subset << ':';
        for (int j = 0; j < n; j++) {
            if (subset & (1 << j)) 
                cout << " " << j;
        }
        cout << endl;
    }

    return 0;
}