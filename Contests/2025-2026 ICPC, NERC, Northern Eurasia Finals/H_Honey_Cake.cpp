/**
* @file H_Honey_Cake.cpp
* @author GabrielCampelo
* Created on 2025-12-17 at 07:04:55
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

/*
    ------    
    in:
    10 20 6
    40

    out:
    4 3 1
    ------

    10 * 20 * 6 = 1200
    1200 / 40 = 300

    assim, a * b * c = 300
*/

int main() { _
    int w, h, d, n;
    cin >> w >> h >> d >> n;

    vector<int> divw, divh;
    unordered_set<int> divd;

    for (int i = 1; i * i <= w; i++) {
        if (w % i == 0) {
            if (i * i == w) divw.pb(i);
            else {
                divw.pb(i);
                divw.pb(w / i);
            }
        }
    }
    
    for (int i = 1; i * i <= h; i++) {
        if (h % i == 0) {
            if (i * i == h) divh.pb(i);
            else {
                divh.pb(i);
                divh.pb(h / i);
            }
        }
    }

    for (int i = 1; i * i <= d; i++) {
        if (d % i == 0) {
            if (i * i == d) divd.insert(i);
            else {
                divd.insert(i);
                divd.insert(d / i);
            }
        }
    }

    sort(all(divw));
    sort(all(divh));

    // apply cut in w
    vector<pair<int, int>> cutw; // {blocks, cuts}

    for (int i = 0; i < divw.size(); i++) {
        if (divw[i] > n) break;
        cutw.pb({divw[i], divw[i] - 1});
    }
    
    // applu cut in h
    vector<pair<int, pair<int, int>>> cutwh; // {blocks, {cuts, cuts}}

    for (int i = 0; i < cutw.size(); i++) {
        for (int j = 0; j < divh.size(); j++) {
            if (1ll * divh[j] * cutw[i].first > n) break;
            if (n % (divh[j] * cutw[i].first) == 0) cutwh.pb({divh[j] * cutw[i].first, {cutw[i].second, divh[j] - 1}});
        }
    }

    for (int i = 0; i < cutwh.size(); i++) {
        if (divd.count(n / cutwh[i].first)) {
            cout << cutwh[i].second.first << ' ' << cutwh[i].second.second << ' ' << (n / cutwh[i].first) - 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}