class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
                                
        //creating a 2d matrix to track reachability
        vector<vector<bool>> reachable(numCourses,
                                       vector<bool>(numCourses, false));
        for (auto& p : prerequisites) {
            int prereq = p[0];
            int course = p[1];
            reachable[prereq][course] = true;
        }

        //floyd warshall algorithm
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {

                    if (reachable[i][k] && reachable[k][j]) {
                        reachable[i][j] = true;
                    }
                }
            }
        }

        vector<bool> ans;
        
        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];
            ans.push_back(reachable[u][v]);
        }

        return ans;
    }
};