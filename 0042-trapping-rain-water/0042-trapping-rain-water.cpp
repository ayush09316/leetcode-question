class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0 , right=n-1;
        int leftMax=height[0] , rightMax=height[n-1];
        int water=0;

        while(left<=right){
            leftMax=max(leftMax,height[left]);
            rightMax= max(rightMax,height[right]);

            if(leftMax<=rightMax) water+= leftMax - height[left++];
            else water+= rightMax - height[right--];
        }
        
        return water;
            
        
    }
};