//leetcode

//solution using BFS Kahn's Algorithmn for directed graphs

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        //converting to adjacency list first and calculatin indegree of each course that is
        //the number of incoming edges

        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
            indeg[course]++;
        }

        queue<int> q;

        //if there exists a course with no prerequisites take it imediately
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        //history of completed courses
        int completed = 0;
    
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            completed++;

            for (int next : adj[node]) {
                indeg[next]--;
                if (indeg[next] == 0)
                    q.push(next);
            }
        }

        return completed == numCourses;
    }
};