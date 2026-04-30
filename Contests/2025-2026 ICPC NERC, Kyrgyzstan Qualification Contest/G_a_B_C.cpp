/**
* @file G_A_B_C.cpp
* @author GabrielCampelo
* Created on 2025-12-16 at 02:47:13
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

int r = 0;
string a, b, c;
int x, y, z;

int main() { _
    cin >> a >> b >> c;

    vector<string> ca, cb;

    int la = 1, ra = 1;
    if (a.size() == 1) {
        la = 1;
        ra = 9;
    } else if (a.size() == 2) {
        la = 10;
        ra = 99;
    } else if (a.size() == 3) {
        la = 100;
        ra = 999;
    }

    for (int i = la; i <= ra; i++) {
        string si = to_string(i);
        bool valid = true;
        for (int j = 0; j < a.size(); j++) {
            for (int k = 0; k < a.size(); k++) {
                if (a[j] == a[k] && (si[j] != si[k])) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        if (valid) ca.pb(si);
    }

    int lb = 1, rb = 1;
    if (b.size() == 1) {
        lb = 1;
        rb = 9;
    } else if (b.size() == 2) {
        lb = 10;
        rb = 99;
    } else if (b.size() == 3) {
        lb = 100;
        rb = 999;
    }

    for (int i = lb; i <= rb; i++) {
        string si = to_string(i);
        bool valid = true;
        for (int j = 0; j < b.size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                if (b[j] == b[k] && (si[j] != si[k])) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        if (valid) cb.pb(si);
    }

    for (string &sa : ca) {
        for (string &sb : cb) {
            bool valid = true;

            for (int i = 0; i < a.size(); i++) {
                for (int j = 0; j < b.size(); j++) {
                    if (a[i] == b[j] && sa[i] != sb[j]) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
            }

            if (!valid) continue;

            string sc = to_string(stoi(sa) + stoi(sb));

            if (sc.size() != c.size()) continue;

            valid = true;

            for (int i = 0; i < c.size(); i++) {
                for (int j = 0; j < c.size(); j++) {
                    if (c[j] == c[i] && sc[j] != sc[i]) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
            }

            if (!valid) continue;

            for (int i = 0; i < a.size(); i++) {
                for (int j = 0; j < b.size(); j++) {
                    for (int k = 0; k < c.size(); k++) {
                        if (c[k] == a[i] && sc[k] != sa[i]) {
                            valid = false;
                            break;
                        }
                        if (c[k] == b[j] && sc[k] != sb[j]) {
                            valid = false;
                            break;
                        }
                    }
                }
                if (!valid) break;
            }

            if (!valid) continue;

            unordered_map<char, char> mp;
            valid = true;

            for (int i = 0; i < a.size(); i++) {
                char ch = a[i];
                char d  = sa[i];
                if (mp.count(ch) && mp[ch] != d) valid = false;
                mp[ch] = d;
            }

            for (int i = 0; i < b.size(); i++) {
                char ch = b[i];
                char d  = sb[i];
                if (mp.count(ch) && mp[ch] != d) valid = false;
                mp[ch] = d;
            }

            for (int i = 0; i < c.size(); i++) {
                char ch = c[i];
                char d  = sc[i];
                if (mp.count(ch) && mp[ch] != d) valid = false;
                mp[ch] = d;
            }

            if (!valid) continue;

            unordered_set<char> used_digits;
            for (auto &[ch, d] : mp) {
                if (used_digits.count(d)) {
                    valid = false;
                    break;
                }
                used_digits.insert(d);
            }

            if (!valid) continue;

            r++;

            if (r == 1) {
                x = stoi(sa);
                y = stoi(sb);
                z = stoi(sc);
            }
        }
    }

    cout << r << endl;
    if (r > 0) {
        cout << x << endl;
        cout << y << endl; 
        cout << z << endl;
    }
    
    return 0;
}