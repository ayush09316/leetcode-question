class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pres) {
        vector<vector<int>> graph(num);
        vector<int> indegrees(num, 0), v;
        queue<int> toVisit;
        int count = 0;
        for(auto& pair: pres){
            graph[pair[1]].push_back(pair[0]);
            indegrees[pair[0]]++;
        }

        for(int i = 0; i < num; i++) if(!indegrees[i]) toVisit.push(i);

        while(!toVisit.empty())
        {
            int node = toVisit.front();
            toVisit.pop();
            for(auto n: graph[node])
                if(--indegrees[n] == 0) toVisit.push(n);
                
            count++;
            v.push_back(node);
        }
        return count==num? v : (v.clear(), v);
    }
};