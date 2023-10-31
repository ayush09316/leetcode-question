#define pr pair<int, int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        	priority_queue<pr, vector<pr>, greater<pr>>pq;
			vector<int>dist(n+1, INT_MAX);
			
			pq.push(make_pair(0, k));
			dist[k] = 0;
			
			unordered_map<int, vector<pr>>hm;
			for (auto it : times)
				hm[it[0]].push_back(make_pair(it[1], it[2]));
			
			while (!pq.empty()) {
				auto p = pq.top();
				pq.pop();
				
				int u = p.second;
				for (auto it : hm[u]) {
					int v = it.first;
					int w = it.second;
					
					if (dist[v] > dist[u] + w) {
						dist[v] = dist[u] + w;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
			
			int res = 0;
			for (int i = 1; i <= n; i++)
				res = max(res, dist[i]);
			
			return res == INT_MAX ? -1 : res;
    }
};