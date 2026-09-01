#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;

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

vector<pair<int, int>> convites; // {k, p}
vector<pair<char, pair<int, int>>> respostas; // {op, {l, r}}

vector<int> amigos;
vector<int> coords;

vector<int> p;
vector<ll> rankk;

int find(int x) {
    return p[x] == x ? p[x] : p[x] = find(p[x]);
}

void union_set(int v, int u) {
    // v depende de u
    v = find(v);
    u = find(u);

    if (u == v) return;

    if (rankk[u] >= rankk[v]) {
        p[v] = u;
        rankk[u] += rankk[v];
    } else {
        p[u] = v;
        rankk[v] += rankk[u];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
  
    int f, n;
    cin >> f >> n;

    convites.resize(n);
    respostas.resize(n);

    for (int i = 0; i < n; i++) {
        int k, p;
        cin >> k >> p;
        amigos.push_back(k);
        convites[i] = {k, p};
    }

    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;

        if (op == 'A') {
            // aceitou
            int a, t;
            cin >> a >> t;
            respostas[i] = {op, {a, a + t}};
            coords.push_back(a);
            coords.push_back(a + t);
        } else if (op == 'D') {
            // recusou
            respostas[i] = {op, {0, 0}};
        } else {
            // condicional
            int k;
            cin >> k;
            amigos.push_back(k);
            respostas[i] = {op, {k, 0}};
        }
    }

    CoordinateCompression<int> cc_coords(coords);
    CoordinateCompression<int> cc_amigos(amigos);

    vector<ll> l(cc_coords.d.size()), r(cc_coords.d.size());  
    vector<pair<int, int>> amigos_lr(cc_amigos.d.size(), {-1, -1}); // {-1, -1} se depende de outro ou se nao vai

    // atualiza l e r aqui
    // DSU para os amigos
    p.resize(cc_amigos.d.size());
    rankk.resize(cc_amigos.d.size());

    for (int i = 0; i < cc_amigos.d.size(); i++) {
        p[i] = i;
        rankk[i] = 0;
    }
    // setar os convidados que cada convidado pode levar
    for (int i = 0; i < n; i++) {
        int id = cc_amigos.get_id(convites[i].first);
        int p = convites[i].second;
        rankk[id] = p;
    }

    for (int i = 0; i < n; i++) {
        char op = respostas[i].first;

        if (op == 'A') {
            // aceitou
            int l = cc_coords.get_id(respostas[i].second.first);
            int r = cc_coords.get_id(respostas[i].second.second);
            int id = cc_amigos.get_id(convites[i].first);

            amigos_lr[id] = {l, r};

        } else if (op == 'D') {
            // recusou
            
        } else {
            // condicional
            int id1 = cc_amigos.get_id(convites[i].first);
            int id = cc_amigos.get_id(respostas[i].second.first);
            // id1 depende de id

            union_set(id1, id);
        }
    }

    for (int i = 0; i < cc_amigos.d.size(); i++) {
        if (amigos_lr[i].first != -1) {
            l[amigos_lr[i].first] += rankk[find(i)];
            r[amigos_lr[i].second] += rankk[find(i)];
        }
    }

    // calculo de ans
    ll ans = 0;
    ll curr = 0;
    for (int i = 0; i < l.size(); i++) {
        curr = curr + l[i] - r[i];
        ans = max(ans, curr);
    }

    cout << ans << endl;
}