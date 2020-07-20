// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            // cout << u << " " << v << endl;
            adj[v].push_back(u);
        }
        vector<int> in_degree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            vector<int> :: iterator it;
            for(it=adj[i].begin();it!=adj[i].end();it++) in_degree[*it]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in_degree[i] == 0) q.push(i);
        }
        int cnt= 0;
        vector<int> ans;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            vector<int> :: iterator it;
            for(it = adj[u].begin();it!=adj[u].end();it++){
                if(--in_degree[*it] == 0) q.push(*it);
            }
            cnt++;
        }
        if(cnt!=numCourses){
            vector<int> temp;
            return temp;
        }
        return ans;
    }
};