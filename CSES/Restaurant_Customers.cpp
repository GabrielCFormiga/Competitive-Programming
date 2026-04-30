/**
* @file Restaurant_Customers.cpp
* @author GabrielCampelo
* Created on 2026-04-28 at 14:46:59
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

template <typename T>
struct CoordinateCompression {
    vector<T> d;

    CoordinateCompression(const vector<T> &vec) {
        d = vec;
        sort(d.begin(), d.end());
        d.erase(unique(d.begin(), d.end()), d.end());
    }

    int get_id(T x) {
        return lower_bound(d.begin(), d.end(), x) - d.begin();
    }

    T get_value(int id) {
        return d[id];
    }
};

int main() { _
    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);
    vector<int> coords;

    for (int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
        coords.pb(vec[i].first);
        coords.pb(vec[i].second);
    }

    CoordinateCompression cc(coords);

    vector<int> arrival(coords.size());
    vector<int> leaving(coords.size());
    
    for (int i = 0; i < n; i++) {
        arrival[cc.get_id(vec[i].first)]++;
        leaving[cc.get_id(vec[i].second)]++; 
    }
    
    int mx = 0;
    int curr = 0;

    for (int i = 0; i < coords.size(); i++) {
        curr = curr + arrival[i] - leaving[i];
        mx = max(mx, curr);
    }

    cout << mx << endl;

    return 0;
}