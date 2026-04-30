/**
* @file Full_House_3 .cpp
* https://atcoder.jp/contests/abc398/tasks/abc398_b
*
* Created on 2025-03-22 at 09:06:30
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
    vector<int> cnt(13 + 1);

    int par = 0, trinca = 0;

    for (int i = 0; i < 7; i++) {
        int x;
        cin >> x;
        cnt[x]++;

        if (cnt[x] == 2) par++;
        else if (cnt[x] == 3) {
            par--;
            trinca++;
        }
    }

    if (trinca >= 2 || (trinca == 1 && par >= 1)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}