const ll seg_tree_size = 4 * 1e5;
ll tree[seg_tree_size];

//v is vertex, v = 1 initially
void build(int arr[], int v, int l, int r){ 
    if(l == r)
        tree[v] = arr[l];
    else{
        int m = l + (r - l) / 2;
        build(arr, v * 2, l, m);
        build(arr, v * 2 + 1, m + 1, r);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

//'s' is starting and 'e' is ending range for the query, v = 1, 0 based indexing
int sum_range(int arr[], int v, int s, int e, int l, int r){
    if(s > e)
        return 0;
    if(s == l && e == r){
        return tree[v];
    }
    int m = l + (r - l) / 2;
    return sum_range(arr, v * 2, s, min(e, m), l, m) + sum_range(arr, v * 2 + 1, max(s, m + 1), e, m + 1, r);
}


//EG
    int dummy_arr[] = {1, 2, 3, 5};
    ll dummy_siz = 4;
    build(arr, 1, 0, dummy_siz - 1);
    cout << sum_range(dummy_arr, 1, 0, 3, 0, dummy_siz - 1); //range from starting to end

