class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses); // Adjacency list
        vector<int> indeg(numCourses);     // In-degree of each node

        // Build graph and track in-degrees
        for (auto& p : prerequisites) {
            int a = p[0], b = p[1];
            g[b].push_back(a); // b -> a means b is a prerequisite of a
            ++indeg[a];
        }

        queue<int> q;
        // Add nodes with 0 in-degree (no prerequisites)
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            ans.push_back(i);

            for (int j : g[i]) {
                if (--indeg[j] == 0) {
                    q.push(j); // Now j has no remaining prerequisites
                }
            }
        }

        // If we couldn't process all courses → cycle exists
        return ans.size() == numCourses ? ans : vector<int>();
    }
};