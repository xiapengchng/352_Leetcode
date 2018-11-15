class Solution {       //netwon method
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        double x0 = x;
        double t = x;
        x0 = x0 / 2 + t / (2 * x0);
        while(fabs(x0 * x0) - t > 0.00001)
        {
            x0 = x0 / 2 + t / (2 * x0);
        }
        return int(x0);
    }
};
