class Solution {
public:
    bool Cyclic(int i,vector<bool>& visited,vector<bool>& currVisited,vector<int> adj[]){
        visited[i]=true;
        currVisited[i]=true;
        
        for(auto x:adj[i]){
            if(!visited[x]){
                if(Cyclic(x,visited,currVisited,adj)) return true;  
            }
            
            else if(visited[x]==true && currVisited[x]==true) return true;
        }
        currVisited[i]=false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<bool> visited(V,false),currVisited(V,false);
        vector<int>adj[V];
        for(auto x:prerequisites){
            int a=x[0];
            int b=x[1];
            adj[a].push_back(b);
        }

        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(Cyclic(i,visited,currVisited,adj)) return false;
            }
        }
        return true;
    }
};