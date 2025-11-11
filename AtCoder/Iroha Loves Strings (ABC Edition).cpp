/**
* @file Iroha Loves Strings (ABC Edition).cpp
*
* Created on 2025-11-10 at 13:29:02
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
    int n, l;
    cin >> n >> l;

    vector<string> vec(n);

    for (int i = 0; i < n; i++)  {
        cin >> vec[i];
    }

    sort(all(vec));
    
    for (int i = 0; i < n; i++) {
        cout << vec[i];
    }

    cout << endl;

    return 0;
}