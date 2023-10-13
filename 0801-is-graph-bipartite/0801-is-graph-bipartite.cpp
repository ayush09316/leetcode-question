class Solution {
public:
    bool check(vector<vector<int>>& graph,int color,vector<int>&visited,int start){
        visited[start]=color;
        for(auto it: graph[start]){
            if(visited[it]==-1){
                if(check(graph,!color,visited,it)==false) return false;
            }
            else if(visited[it]==color) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>visited(graph.size(),-1);

       for(int start=0;start<graph.size();start++){
           if(visited[start]==-1){
               if(check(graph,0,visited,start)==false){
                   return false;
               }
           }
       }
       return true;
    }
};