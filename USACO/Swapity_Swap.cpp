#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size() 

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

/*Return Value Suppression: The (void) cast before the expression is used to 
explicitly indicate to the compiler that the return value is intentionally ignored. 
This can be done to avoid compiler warnings when a return value is not used, 
especially when it's intended behavior (as in the case of freopen).*/
void setIO(string name = "") {
    if(sz(name)) {
        (void)freopen((name + ".in").c_str(), "r", stdin);
        (void)freopen((name + ".out").c_str(), "w", stdout);
    }
}

// O(N * (k))
int N, K, A1, A2, B1, B2;

int next(int x) {
    if(A1 <= x && x <= A2) // simulate step 1
        x = A1 + A2 - x;
    if(B1 <= x && x <= B2) // simulate step 2
        x = B1 + B2 - x;
    return x;    
}

int main(){ _
    setIO("swap");
    
    cin >> N >> K >> A1 >> A2 >> B1 >> B2;
    vector<int> vec(N + 1);

    for(int i = 1; i <= N; i++) {
        // count = how many turns so far?
        // cur = where are we after count turns
        int count = 1, cur = next(i);
        while(cur != i) {
            count++;
            cur = next(cur);
        }
        int k = K % count; // reduce k
        for(int j = 0; j < k; j++) {
            cur = next(cur);
        }
        vec[cur] = i;
    }

    for(int i = 1; i <= N; i++) {
        cout << vec[i] << endl;
    }

    /* O(N * K)
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        vec[i] = i + 1;
    }

    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    a1--;
    a2--;
    b1--;
    b2--;

    while(k--) {
        reverse(vec.begin() + a1, vec.begin() + a2 + 1);
        reverse(vec.begin() + b1, vec.begin() + b2 + 1);
    }

    for(int i = 0; i < n; i++) {
        cout << vec[i] << endl;
    }
    */

    return 0;
}
