class Solution {
public:
    int mySqrt(int x) {
        int low=1,hi=x,mi;
        if(x==0)
            return 0;
        if(x==1)
            return 1;
        while(low<hi){
            mi=(low+hi)/2;
            if(x/mi<=mi)
                hi=mi;
            else 
                low=mi+1;
        }
        return low==x/low?low:low-1;
    }
};