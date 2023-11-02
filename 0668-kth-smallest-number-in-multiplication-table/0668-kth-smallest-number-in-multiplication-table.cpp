class Solution {
public:
    int check(int m,int n,int k,int mid){
        int cnt=0;
        for(int i=1;i<=m;i++){
            int add= min(mid/i,n);
            if(add==0) break;
            cnt+=add;
        }
        return cnt>=k;
    }
    int findKthNumber(int m, int n, int k) {
        int low=1,high=m*n;
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(m,n,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
       return  low;

    }
};