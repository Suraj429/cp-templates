const ll seg_tree_size = 4 * 1e5;
ll tree[seg_tree_size];

//v is vertex, v = 1 initially
void build(ll arr[], ll v, ll l, ll r){ 
    if(l == r)
        tree[v] = arr[l];
    else{
        ll m = l + (r - l) / 2;
        build(arr, v * 2, l, m);
        build(arr, v * 2 + 1, m + 1, r);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

//'s' is starting and 'e' is ending range for the query, v = 1, 0 based indexing
ll sum_range(ll arr[], ll v, ll s, ll e, ll l, ll r){
    if(s > e)
        return 0;
    if(s == l && e == r){
        return tree[v];
    }
    ll m = l + (r - l) / 2;
    return sum_range(arr, v * 2, s, min(e, m), l, m) + sum_range(arr, v * 2 + 1, max(s, m + 1), e, m + 1, r);
}
