#include <queue>
#include <vector>
#include <climits>

class Solution {
public:
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        // Directions: down, up, right, left
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        
        // Min-heap to store {cost, {row, col}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        
        // Distance matrix initialized to infinity
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        // Start from the top-left cell
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0, 0}});
        
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int currentCost = current.first;
            int row = current.second.first;
            int col = current.second.second;
            
            // If reached the bottom-right cell, return the cost
            if (row == n - 1 && col == m - 1) {
                return currentCost;
            }
            
            
           
            
            // Explore all four directions
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                
                // Check if the new cell is within bounds
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newCost = currentCost + grid[nr][nc];
                    
                    // If found a cheaper path, update and push to the heap
                    if (newCost < dist[nr][nc]) {
                        dist[nr][nc] = newCost;
                        pq.push({newCost, {nr, nc}});
                    }
                }
            }
        }
        
        // If no path found (shouldn't happen for valid grids)
        return -1;
    }
};
