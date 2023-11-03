class Solution {
public:
     bool condition(long long int mid, int a, int b, int c, int n){
        long long int ab, ac, bc, abc,count = 0;
        ab = (((long)a*b)/__gcd(a,b));
        bc = (((long)b*c)/__gcd(b,c));
        ac = (((long)a*c)/__gcd(a,c));
        abc = (((long)a*bc)/__gcd((long long)a,bc));
        count += (mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc);
        return count>=n;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        //  are there n-1 smallest numbers when n = mid?
        long long int left = 1, right = 1e12, mid;
        while(left<right){
            mid = (left) + (right-left)/2;
            if(condition(mid,a,b,c,n))right = mid;
            else left = mid+1;
        }
        return left;
    }
};