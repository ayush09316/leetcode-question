class Solution {
public:
    bool check(vector<int>& a,int x,int k){
        int cnt=0,n=a.size(),ind=0;
        for(int i=1;i<n;i++){
            while(ind<i && (a[i]-a[ind]>x))   ind++;
            cnt+=(i-ind);
        }
        return (cnt>=k)? 1: 0;
    
    }
    int smallestDistancePair(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        int n=a.size();
        int l=0,  h=a[n-1]-a[0];
        while(l<h){
            int mid=l+(h-l)/2;
            if(check(a,mid,k))  h=mid;
            else  l=mid+1;
        }
        return l;
    }
};