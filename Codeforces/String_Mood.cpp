/**
* @file String_Mood.cpp
* @author GabrielCampelo
* Created on 2026-02-23 at 20:04:36
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;
using llu = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

using Matrix = vector<vector<ll>>;

Matrix multiply(Matrix &a, Matrix &b) {
    Matrix ret = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ret[i][k] = (ret[i][k] + a[i][j] * b[j][k]) % MOD; 
            }
        }
    }
    return ret;
}

int main() { _
    ll n;
    cin >> n;

    Matrix a = {
        {19, 7},
        {6, 20}
    };

    Matrix ret = {
        {1, 0},
        {0, 1}
    };

    while (n) {
        if (n % 2 == 1) {
            ret = multiply(ret, a);
        }
        a = multiply(a, a);
        n /= 2;
    }

    cout << ret[0][0] << endl;

    return 0;
}