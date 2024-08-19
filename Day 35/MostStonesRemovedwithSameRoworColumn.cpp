#include <vector>
#include <algorithm>
using namespace std;

class Disjoint {
    vector<int> parent, rank;

public:
    Disjoint(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;
        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        Disjoint ds(maxRow + maxCol + 1);

        for (auto& stone : stones) {
            int u = stone[0];             
            int v = stone[1] + maxRow + 1; 
            ds.unionByRank(u, v);
        }

        unordered_set<int> uniqueComponents;
        for (auto& stone : stones) {
            int parent = ds.findParent(stone[0]);
            uniqueComponents.insert(parent);
        }

        return n - uniqueComponents.size();
    }
};
