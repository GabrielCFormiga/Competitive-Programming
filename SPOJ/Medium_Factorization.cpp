/**
* @file Medium_Factorization.cpp
* https://www.spoj.com/problems/FACTCG2/
*
* Created on 2025-04-06 at 12:46:32
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

#define MAX_N 10000001

int main() { _
    vector<int> sp(MAX_N);
    for (int i = 2; i < MAX_N; i += 2) sp[i] = 2;
    for (ll i = 3; i < MAX_N; i += 2) {
        if (sp[i] == 0) {
            sp[i] = i;
            for (ll j = i * i; j < MAX_N; j += i) if (sp[j] == 0) sp[j] = i;
        }
    }

    int n;
    while (cin >> n) {
        cout << 1;
        while (n != 1) {
            cout << " x " << sp[n];
            n /= sp[n];
        }
        cout << endl;
    } 
    
    return 0;
}