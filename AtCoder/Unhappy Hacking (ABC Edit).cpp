/**
* @file Unhappy Hacking (ABC Edit).cpp
*
* Created on 2025-11-12 at 13:19:39
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
    string s;
    cin >> s;

    stack<char> st;

    for (char c : s) {
        if (c != 'B') {
            st.push(c);
        } else if (!st.empty()) {
            st.pop();
        }
    }
    
    string ans = "";

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(all(ans));

    cout << ans << endl;

    return 0;
}