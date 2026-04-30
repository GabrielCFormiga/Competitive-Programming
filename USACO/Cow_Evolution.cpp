#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size() 

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

void setIO(string name = "") {
    if(sz(name)) {
        (void)freopen((name + ".in").c_str(), "r", stdin);
        (void)freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main(){ _
    //setIO("evolution");

    int n;
    cin >> n;
    vector<vector<string>> leaves(n);
    vector<string> characteristics;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while(k--) {
            string str;
            cin >> str;
            leaves[i].pb(str);
            if(find(characteristics.begin(), characteristics.end(), str) == characteristics.end()) {
                characteristics.pb(str);
            }
        }
    }

    cout << "yes" << endl;



    return 0;
}
