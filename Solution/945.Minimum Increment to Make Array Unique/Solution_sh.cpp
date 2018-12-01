//思路最简单的一种写法，先排序，每一个元素至少比前一个元素大1.复杂度O(NlonN)

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, need = 0;
        for(int a : A)
        {
            res += max(need - a, 0);
            need = max(a, need) + 1;
        }
        return res;
    }
};

//在A[i]和A[i-1]的空隙中插入重复的数字，复杂度O(N)
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        vector<int> count(100000);
        for(int x : A) count[x]++;
        
        int ans = 0, taken = 0;
        
        for(int x = 0; x < 100000; x++)
        {
            if(count[x] >= 2)
            {
                taken += count[x] - 1;
                ans -= x * (count[x] - 1);
            }
            else if(taken > 0 && count[x] == 0)
            {
                taken--;
                ans += x;
            }
        }
        return ans;
    }
};