#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<ll> f(n + 1);

    f[1] = 2;
    f[2] = 3;

    vector<ll> finv(3 * n);

    finv[2] = 1;
    finv[3] = 2;
    
    for (int i = 3; i <= n; i++) {
        if (finv[i] != 0) {
            f[i] = 3 * finv[i];
        } else {
            f[i] = f[i - 1] + 1;
        }
        finv[f[i]] = i;
    }

    cout << f[n] << endl;
}