const ll MAXN = 1e5;
pair<int, int> t[4*MAXN];

ll INF = 1e9;

//Store max in pairs 
pair<ll, ll> combine(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

//v = 1
void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

//range is l and r, 0 based indexing
pair<ll, ll> get_max(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return t[v];
    ll tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, min(r, tm)), 
                   get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}