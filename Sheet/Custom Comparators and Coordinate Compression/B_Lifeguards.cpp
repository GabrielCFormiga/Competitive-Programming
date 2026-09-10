/**
* @file B_Lifeguards.cpp
*
* Created on 2026-09-10 at 01:18:47
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

void setIO(string name = "") {
    if(name.size()) {
        (void)freopen((name + ".in").c_str(), "r", stdin);
        (void)freopen((name + ".out").c_str(), "w", stdout);
    }
}

template <typename T>
struct CoordinateCompression {
    vector<T> d;
    int n;

    CoordinateCompression(const vector<T> &vec) {
        d = vec;
        sort(d.begin(), d.end());
        d.erase(unique(d.begin(), d.end()), d.end());
        n = d.size();
    }

    int get_id(T x) {
        return lower_bound(d.begin(), d.end(), x) - d.begin();
    }

    T get_value(int id) {
        return d[id];
    }
};

int main() { _
    setIO("lifeguards");

    int n;
    cin >> n;

    vector<pair<int, int>> shifts(n);
    vector<int> coords;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        shifts[i] = {a, b};
        coords.pb(a);
        coords.pb(b);
    }

    CoordinateCompression<int> cc(coords);

    vector<vector<int>> L(cc.n), R(cc.n);

    for (int i = 0; i < n; i++) {
        L[cc.get_id(shifts[i].first)].pb(i);
        R[cc.get_id(shifts[i].second)].pb(i);
    }

    int total = 0;
    set<int> curr;
    vector<int> alone(n);

    for (int cow : L[0]) {
        curr.insert(cow);
    }

    for (int i = 1; i < cc.n; i++) {
        if (curr.size() > 0) total += cc.get_value(i) - cc.get_value(i - 1);    
        
        if (curr.size() == 1) alone[*curr.begin()] += cc.get_value(i) - cc.get_value(i - 1); 

        for (int cow : L[i]) {
            curr.insert(cow);
        }
        
        for (int cow : R[i]) {
            curr.erase(cow);
        }
    }

    int mn = INF;
    for (int m : alone) {
        mn = min(mn, m);
    }

    cout << total - mn << endl;
    
    return 0;
}