#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main(){ 
    freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);


    int n, m;
    cin >> n >> m;
    vector<string> scow(n), pcow(n);
    // A C G T
    // 0 1 2 3
    for(int i = 0; i < n; i++){
        cin >> scow[i];
    }
    for(int i = 0; i < n; i++){
        cin >> pcow[i];
    }

    int count = 0;
    for(int i = 0; i < m; i++){
        bool can = 1;

        for(int j = 0; j < n; j++){
            string str1 = scow[j];  
            for(int j = 0; j < n; j++){
                string str2 = pcow[j];
                if(str1[i] == str2[i]) can = 0;
                if(!can) break;
            }
            if(!can) break;
        }

        if(can) count++;

    }
    


    cout << count << endl;


    return 0;
}

