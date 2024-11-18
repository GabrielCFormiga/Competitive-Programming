/**
* @file Counting_Sort.cpp
* https://codeforces.com/group/OyefIGO3t4/contest/447260/problem/E
*
* Created on 2024-11-17 at 23:43:04
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

const int MOD = 1e6;

int main() { _
    int n, A, B, a0;
    cin >> n >> A >> B >> a0;

    vector<int> vec(n + 1);
    vec[0] = a0;
    for (int i = 1; i <= n; i++) {
        vec[i] = ((ll) A * vec[i - 1] + B) % MOD + 1;
    }

    sort(vec.begin() + 1, vec.end());

    for (int i = 1; i <= n; i++) cout << vec[i] << (i == n ? endl : ' ');

    return 0;
}