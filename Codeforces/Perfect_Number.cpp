/**
* @file Perfect Number.cpp
* @author GabrielCampelo
* Created on 2026-01-02 at 13:51:58
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

bool perfect(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
        if (sum > 10) return false;
    }
    return sum == 10;
}

int main() { _
    int k;
    cin >> k;

    int cnt = 0;

    for (int i = 19; ; i++) {
        if (perfect(i)) cnt++;
        if (cnt == k) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}