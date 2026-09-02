/**
* @file B_Good_Spotlights.cpp
* @author GabrielCampelo
* Created on 2026-08-24 at 14:29:58
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

vector<string> seq = {
    "000",
    "001",
    "010",
    "011",
    "100",
    "101",
    "110",
    "111",
};

int main() { _
    string s;
    cin >> s;

    do {
        if (seq[0] != s) continue;

        bool valid = true;

        for (int i = 1; i < 8; i++) {
            int diff = 0;
            if (seq[i - 1][0] != seq[i][0]) diff++;
            if (seq[i - 1][1] != seq[i][1]) diff++;
            if (seq[i - 1][2] != seq[i][2]) diff++;
            if (diff != 1) {
                valid = false;
                break;
            }
        }

        if (valid) {
            int diff = 0;
            if (seq[7][0] != s[0]) diff++;
            if (seq[7][1] != s[1]) diff++;
            if (seq[7][2] != s[2]) diff++;
            if (diff == 1) {
                // exibo a resposta
                for (auto x : seq) {
                    cout << x << endl;
                }
                cout << s << endl;
                exit(0);
            }
        } 

    } while (next_permutation(seq.begin(), seq.end()));
    
    return 0;
}