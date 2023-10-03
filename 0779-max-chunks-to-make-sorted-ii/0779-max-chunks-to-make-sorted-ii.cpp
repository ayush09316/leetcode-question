class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> rightmin(n+1,INT_MAX);
        for(int i=n-1;i>=0;i--){
            rightmin[i] = min(arr[i],rightmin[i+1]);
        }
        
        int count = 0;
        int leftmax = INT_MIN;
        for(int i=0;i<n;i++){
            leftmax = max(leftmax,arr[i]);
            if(leftmax <= rightmin[i+1])  count++;
        }
        return count++;
    }
};