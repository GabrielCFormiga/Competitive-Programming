/**
* @file Iroha's Obsession.cpp
*
* Created on 2025-11-10 at 13:31:21
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
    int n;
    int k;
    cin >> n >> k;

    vector<bool> dislike(10);

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        dislike[x] = true;
    }

    for (int i = n; i < 100 * n; i++) {
        int aux = i;
        bool ans = true;
        while (aux > 0) {
            int digit = aux % 10;
            aux = aux / 10;
            if (dislike[digit]) {
                ans = false;
                break;
            }
        }
        if (ans) {
            cout << i <<endl;
            return 0;
        }
    }
    
}