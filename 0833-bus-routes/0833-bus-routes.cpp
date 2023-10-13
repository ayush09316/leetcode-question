class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int,unordered_set<int>> m;
        // bus-stop to bus-no
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                m[routes[i][j]].insert(i);
            }
        }
        queue<pair<int,int>> q; 
        q.push({S,0});
        unordered_set<int> set;
        set.insert(S);
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int cur_stop = p.first;
            int bus_taken = p.second;

            if(cur_stop == T) return bus_taken;

            for(int bus_no : m[cur_stop]){ 
                for(int route:routes[bus_no]){
                    if(set.find(route) == set.end()){
                        q.push({route,bus_taken + 1});
                    }
                }
                
                routes[bus_no].clear();
            }
        }
        return -1;

    }
};