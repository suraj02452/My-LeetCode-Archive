class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }

        queue<int> q;
        for (int c = 0; c < numCourses; c++)
            if (indeg[c] == 0) q.push(c);

        int taken = 0;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            taken++;
            for (int nxt : graph[c])
                if (--indeg[nxt] == 0) q.push(nxt);
        }
        return taken == numCourses;
    }
};