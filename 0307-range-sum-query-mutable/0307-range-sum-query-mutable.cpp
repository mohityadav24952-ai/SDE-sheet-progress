class NumArray {
    vector<int> seg_tree;
    vector<int> nums_copy;
    int n;

    // 1. Build Function
    void builtTree(int i, vector<int> &nums, int l, int r) {
        if (l == r) {
            seg_tree[i] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        builtTree(2 * i + 1, nums, l, mid);
        builtTree(2 * i + 2, nums, mid + 1, r);
        seg_tree[i] = seg_tree[2 * i + 1] + seg_tree[2 * i + 2];
    }

    // 2. Query Function
    int query(int i, int l, int r, int s, int e) {
        if (s > r || e < l) return 0;          
       if (s <= l && r <= e) return seg_tree[i];
        int mid = l + (r - l) / 2;
        return query(2 * i + 1, l, mid, s, e) + 
               query(2 * i + 2, mid + 1, r, s, e);
    }

    // 3. Update Function
    void updateTree(int i, int l, int r, int ind, int value) {
        if (l == r) { 
            seg_tree[i] = value;
            return;
        }
        int mid = l + (r - l) / 2;
        if (ind <= mid) {
            updateTree(2 * i + 1, l, mid, ind, value);
        } else {
            updateTree(2 * i + 2, mid + 1, r, ind, value);
        }
        seg_tree[i] = seg_tree[2 * i + 1] + seg_tree[2 * i + 2];
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n > 0) {
            seg_tree.resize(4 * n, 0);
            builtTree(0, nums, 0, n - 1);
        }
    }
    
    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};