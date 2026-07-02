class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        // Max Heap
        // {bachi hui health, {row, col}}
        priority_queue<pair<int, pair<int, int>>> pq;

        // Har cell par ab tak ki maximum health store karega
        vector<vector<int>> best(n, vector<int>(m, -1));

        // Starting cell ki health
        int startHealth = health;

        if (grid[0][0] == 1)
            startHealth--;

        // Agar start me hi health khatam ho gayi
        if (startHealth < 1)
            return false;

        pq.push({startHealth, {0, 0}});
        best[0][0] = startHealth;

        // 4 Directions
        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};

        while (!pq.empty()) {

            // Current state nikalo
            int currHealth = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            // Destination mil gaya
            if (row == n - 1 && col == m - 1)
                return true;

            // Agar isse better health pehle aa chuki hai
            if (currHealth < best[row][col])
                continue;

            // 4 Directions explore karo
            for (int i = 0; i < 4; i++) {

                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                // Boundary check
                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m) {

                    // Agar cell unsafe hai to health 1 kam hogi
                    int newHealth = currHealth - grid[newRow][newCol];

                    // Health bachni chahiye
                    if (newHealth >= 1 && newHealth > best[newRow][newCol]) {

                        best[newRow][newCol] = newHealth;
                        pq.push({newHealth, {newRow, newCol}});
                    }
                }
            }
        }

        // Destination tak nahi pahunch paye
        return false;
    }
};