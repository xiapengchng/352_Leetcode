#include<math>
class Solution {
public:
    int reverse(int x) {

        long long result=0;
        int sig=1;

        if(x<0)
        {
            sig=-1;
            x=-1*x;
        }
        while(x/10)
        {
            int temp=x%10;
            result+=temp;
            result*=10;
            x=x/10;
        }
        result+=x;
        result*=sig;
        if(result<INT_MIN||result>INT_MAX)
            return 0;
        //result=result/10;
        return result;
    }
};
