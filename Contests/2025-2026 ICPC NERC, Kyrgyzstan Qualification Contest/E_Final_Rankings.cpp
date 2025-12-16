/**
* @file E_Final_Rankings.cpp
* @author GabrielCampelo
* Created on 2025-12-16 at 02:11:30
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

ll n, p;
vector<vector<ll>> vec;
vector<pair<ll, pair<ll, ll>>> penalty; // {probs, {penaly, id}}

int main() { _
    cin >> n >> p;
    
    penalty.resize(n);

    for (int i = 0; i < n; i++) {
        penalty[i].second.second = i + 1;
    }

    vec.assign(n, vector<ll>(p));

    int q;
    cin >> q;   
    
    while (q--) {
        ll min, id, prob, res;
        cin >> min >> id >> prob >> res;

        if (vec[id -1][prob - 1] == -1) continue;
        
        if (res == 1) {
            penalty[id - 1].first++;
            penalty[id - 1].second.first += 20 * vec[id -1][prob - 1] + min;
            vec[id -1][prob - 1] = -1;
        } else {
            vec[id - 1][prob - 1]++;
        }
    }

    sort(all(penalty), [&](pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b) {
        if (a.first == b.first) {
            if (a.second.first == b.second.first) {
                return a.second.second < b.second.second;
            } else {
                return a.second.first < b.second.first;
            }
        } else {
            return a.first > b.first;
        }        
    });

    int rank = 1;
    cout << rank << ' ' << penalty[0].second.second << ' ' << penalty[0].first << ' ' << penalty[0].second.first << endl;

    for (int i = 2; i <= n; i++) {
        if (!(penalty[i - 1].second.first == penalty[i - 2].second.first && penalty[i - 1].first == penalty[i - 2].first)) {
            rank = i;
        } 
        cout << rank << ' ' << penalty[i - 1].second.second << ' ' << penalty[i - 1].first << ' ' << penalty[i - 1].second.first << endl;
    }

    return 0;
}