#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main(){ _
    freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

    int tt, n, taux;
    cin >> tt >> n;
    taux = tt;
    tt--;
    vector<int> cows(n);
    vector<pair<int, int>> p;
    vector<int> consist;
    for(int i = 0; i < n; i++){
        cin >> cows[i];
    }        
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            p.pb(make_pair(cows[i], cows[j]));
            consist.pb(1);
        }
    }  
    
    
    while(tt--){
        pair<int, int> pcheck;
        for(int i = 0; i < n; i++){
            cin >> cows[i];
        }        
        for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            pcheck = make_pair(cows[i], cows[j]);
            for(int k = 0; k < p.size(); k++){
                if(pcheck == p[k]){
                    consist[k]++;
                    break;
                }
            }
        }
    } 
    }

    int count = 0;
    for(int i = 0; i < consist.size(); i++){
        if(consist[i] == taux) count++;
    }
    cout << count << endl;

    return 0;
}