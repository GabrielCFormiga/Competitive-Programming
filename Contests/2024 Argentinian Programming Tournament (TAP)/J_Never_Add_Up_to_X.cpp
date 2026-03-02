/**
* @file J_Never_Add_Up_to_X.cpp
* @author GabrielCampelo
* Created on 2026-03-01 at 100:22:12
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

int n, x;

void print (vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << (i == vec.size() - 1 ? endl : ' ');
    }
}

bool valid (vector<int> &vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i] == -1 || vec[i + 1] == -1) return false;
        if (vec[i] + vec[i + 1] == x) return false;
    }
    return true;
}

int main() { _
    cin >> n >> x;

    vector<int> vec(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        mp[vec[i]]++;
    }

    sort(all(vec));

    int a = -1, b = -1, ia = -1, ib = -1;
    for (int i = 0; i < n - 1; i++) {
        if (vec[i] + vec[i + 1] == x) {
            a = vec[i];
            ia = i;
            b = vec[i + 1];
            ib = i + 1;
            break;
        }
    }

    if (a == -1) {
        print(vec);
        return 0;
    } 

    if (a != b) {
        vector<int> ans(n);
        ans[0] = vec[ia];
        int add = 0;
        for (int i = 1; i < n; i++) {
            if (i - 1 == ia) add = 1;
            ans[i] = vec[i - 1 + add];
        }
        if (valid(ans)) {
            print(ans);
            return 0;
        }
 
        ans[n - 1] = vec[ia];
        add = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i == ia) add = 1;
            ans[i] = vec[i + add];
        }
        if (valid(ans)) {
            print(ans);
            return 0;
        }
        
        // swap a
        swap(vec[0], vec[ia]);
        if (valid(vec)) {
            print(vec);
            return 0;
        }
        swap(vec[0], vec[ia]);
        swap(vec[n - 1], vec[ia]);
        if (valid(vec)) {
            print(vec);
            return 0;
        }
        swap(vec[n - 1], vec[ia]);
 
        // swap b
        swap(vec[0], vec[ib]);
        if (valid(vec)) {
            print(vec);
            return 0;
        }
        swap(vec[0], vec[ib]);
        swap(vec[n - 1], vec[ib]);
        if (valid(vec)) {
            print(vec);
            return 0;
        }
        swap(vec[n - 1], vec[ib]);



        vector<int> rvec;
        rvec.assign(vec.rbegin(), vec.rend());
        map<int, int> mpp = mp;

        // change a
        int i;
        for (i = 0; i < n; i++) {
            if (mp[a] == 0) break;
            ans[i] = a;
            mp[a]--;
        }

        int p = 0;
        for (int k = i; k < n; k++) {
            while (vec[p] == a) p++;
            ans[k] = vec[p++];
        }

        if (ans[ib - 1] == a) {
            swap(ans[ia], ans[n - 1]);
        }

        if (valid(ans)) {
            print(ans);
            return 0;
        } 

        // change b
        int ra = -1, rb = -1, ria = -1, rib = -1;
        for (int i = 0; i < n - 1; i++) {
            if (rvec[i] + rvec[i + 1] == x) {
                ra = rvec[i];
                ria = i;
                rb = rvec[i + 1];
                rib = i + 1;
                break;
            }
        }

        i;
        for (i = 0; i < n; i++) {
            if (mpp[a] == 0) break;
            ans[i] = a;
            mpp[a]--;
        }

        p = 0;
        for (int k = i; k < n; k++) {
            while (rvec[p] == a) p++;
            ans[k] = rvec[p++];
        }

        if (ans[rib - 1] == a) {
            swap(ans[ria], ans[n - 1]);
        }

        if (valid(ans)) {
            print(ans);
            return 0;
        } 

        cout << '*' << endl;
        return 0;
    }

    // a == b
    vector<int> ans(n, - 1);
    for (int i = 0; i < n; i += 2) {
        if (mp[a] == 0) break;
        ans[i] = a;
        mp[a]--;
    }

    auto it = mp.begin();
    for (int i = 0; i < n; i++) {
        if (ans[i] != -1) continue;
        while (it != mp.end() && it->second == 0) it++;
        if (it == mp.end()) break;
        ans[i] = it->first;
        it->second--;
    }

    if (valid(ans)) {
        print(ans);
        return 0;
    } 

    a = -1, b = -1, ia = -1, ib = -1;
    for (int i = 0; i < n - 1; i++) {
        if (ans[i] + ans[i + 1] == x) {
            a = ans[i];
            ia = i;
            b = ans[i + 1];
            ib = i + 1;
            break;
        }
    }

    if (a != b) {
        // swap a
        // a to bg
        for (int pos = 1; pos < n && pos <= 100; pos += 1) {
            swap(ans[pos], ans[ia]);
            if (valid(ans)) {
                print(ans);
                return 0;
            }
            swap(ans[pos], ans[ia]);
        } 

        for (int pos = n - 1; n - pos <= 100 && pos >= 0; pos--) {
            swap(ans[pos], ans[ia]);
            if (valid(ans)) {
                print(ans);
                return 0;
            }
            swap(ans[pos], ans[ia]);
        }

        for (int pos = ia + 1, cnt = 0; pos < n && cnt <= 100; pos += 1, cnt++) {
            swap(ans[pos], ans[ia]);
            if (valid(ans)) {
                print(ans);
                return 0;
            }
            swap(ans[pos], ans[ia]);
        } 

        for (int pos = ia - 1, cnt = 0; cnt <= 100 && pos >= 0; pos--, cnt++) {
            swap(ans[pos], ans[ia]);
            if (valid(ans)) {
                print(ans);
                return 0;
            }
            swap(ans[pos], ans[ia]);
        }

        // swap b
        for (int pos = n - 1; n - pos <= 100 && pos >= 0; pos--) {
            swap(ans[pos], ans[ib]);
            if (valid(ans)) {
                print(ans);
                return 0;
            }
            swap(ans[pos], ans[ib]);
        }

        for (int pos = 1; pos < n && pos <= 100; pos += 1) {
            swap(ans[pos], ans[ib]);
            if (valid(ans)) {
                print(ans);
                return 0;
            }
            swap(ans[pos], ans[ib]);
        }

        for (int pos = ib - 1, cnt = 0; cnt <= 100 && pos >= 0; pos--, cnt++) {
            swap(ans[pos], ans[ib]);
            if (valid(ans)) {
                print(ans);
                return 0;
            }
            swap(ans[pos], ans[ib]);
        }

        for (int pos = ib + 1, cnt = 0; pos < n && cnt <= 100; pos += 1, cnt++) {
            swap(ans[pos], ans[ib]);
            if (valid(ans)) {
                print(ans);
                return 0;
            }
            swap(ans[pos], ans[ib]);
        }
    }

    cout << '*' << endl;

    return 0;
}