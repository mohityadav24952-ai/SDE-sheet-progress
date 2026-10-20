class NumArray {
public:
    vector<int> seg_tree;
    int n;
    
    void buildtree(int i, int l, int r, vector<int>& nums) {
        if(l == r) {
            seg_tree[i] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildtree(2 * i + 1, l, mid, nums);
        buildtree(2 * i + 2, mid + 1, r, nums);
        seg_tree[i] = seg_tree[2 * i + 1] + seg_tree[2 * i + 2];
    }
    
    int query(int i, int l, int r, int s, int e) {
      
        if(l > e || r < s) return 0; 
        
       
        if(l >= s && r <= e) return seg_tree[i]; 
        
      
        int mid = l + (r - l) / 2;
        return query(2 * i + 1, l, mid, s, e) + query(2 * i + 2, mid + 1, r, s, e);
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        if(n > 0) {
            seg_tree.resize(4 * n);
            buildtree(0, 0, n - 1, nums);
        }
    }
    
    int sumRange(int left, int right) {
        if(n == 0) return 0;
        return query(0, 0, n - 1, left, right);
    }
};