class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        int low = 1;
        int high = x;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(mid <= x/mid)
            {
                if((mid+1) > x/(mid+1))
                    return mid;
                else
                    low = mid;
            }
            else
                high = mid;
        }
    }
};