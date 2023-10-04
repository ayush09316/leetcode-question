class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0 , right=n-1;
        int leftMax=height[0] , rightMax=height[n-1];
        int water=0;

        while(left<=right){
            if(leftMax<rightMax){
                if(height[left]>leftMax) leftMax=height[left];
                else  water+= leftMax-height[left++];
            }
            
            else{
                if(height[right]>rightMax) rightMax=height[right];
                else water+= rightMax-height[right--];
            }
        }
        
        return water;
            
        
    }
};