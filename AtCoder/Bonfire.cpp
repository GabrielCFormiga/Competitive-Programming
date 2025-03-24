/**
* @file Bonfire.cpp
*
* Created on 2025-03-22 at 09:19:46
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
    int n, C, R;
    string str;
    set<pair<int, int>> smoke;

    cin >> n >> R >> C >> str;

    pair<int, int> takahashi = {R, C};
    pair<int, int> fire = {0, 0};
    smoke.insert(fire);

    for (char c : str) {
        if (c == 'N') {
            fire.first++;
            takahashi.first++;
        } else if (c == 'S') {
            fire.first--;
            takahashi.first--;
        } else if (c == 'E') {
            fire.second--;
            takahashi.second--;
        } else {
            fire.second++;
            takahashi.second++;
        }

        if (smoke.find(fire) == smoke.end()) smoke.insert(fire);
    
        cout << (smoke.find(takahashi) != smoke.end());
    }

    cout << endl;

    return 0;
}