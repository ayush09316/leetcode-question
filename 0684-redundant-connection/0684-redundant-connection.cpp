class Solution {
public:
   vector<int> parent;
    int findparent(int p){

        if(parent[p] == p) return p;
        parent[p] = findparent(parent[p]);
        return parent[p];
        
    }

    bool unionedge(int p, int q){
        int parentp = findparent(p);
        int parentq = findparent(q);

        if(parentp == parentq)  return false;

        if(parentp < parentq) parent[parentq] = parentp;

        else parent[parentp] = parentq;

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent = vector<int>(n);

        for(int i=0;i<n;i++) parent[i] = i;
        
        for(auto edge: edges){

            if(!unionedge(edge[0]-1, edge[1]-1)) return edge;

        }
        
        return {};
    }
};