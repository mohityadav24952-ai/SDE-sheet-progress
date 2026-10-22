class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        vector<int> ans(m, -1);
        vector<vector<pair<int, int>>> new_queries(n);
        
        // Step 1: Filter trivial queries aur baakiyo ko index 'v' par store karo
        for (int i = 0; i < m; i++) {
            int u = min(queries[i][0], queries[i][1]);
            int v = max(queries[i][0], queries[i][1]);
            
            if (u == v || heights[u] < heights[v]) {
                ans[i] = v;
            } else {
                // required height aur original query ka index store karo
                new_queries[v].push_back({max(heights[u], heights[v]), i}); 
            }
        }
        
        // Step 2: Sahi wala Min-Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        
        // Step 3: Left to right sweep
        for (int i = 0; i < n; i++) {
            // Agar heap top ki required height current building height se choti hai, meeting point mil gaya!
            while (!minheap.empty() && minheap.top().first < heights[i]) {
                ans[minheap.top().second] = i;
                minheap.pop();
            }
            
            // Is building par pending hui saari queries heap me daal do
            for (auto& q : new_queries[i]) {
                minheap.push(q);
            }
        }
        
        return ans;
    }
};