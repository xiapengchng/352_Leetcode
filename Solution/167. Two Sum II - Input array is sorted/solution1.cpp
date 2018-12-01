class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        
        // 实现1
        // 暴力查找的时间复杂度为O(n2);以下采用二分查找的方法；
        vector<int> arr = {0, 0};
        int size = numbers.size();
        int i = 0;
        int j = 0;
        
        for(i = 0; i < size; i++){
            
            int lo = i + 1;
            int hi = size;
            int e = target - numbers[i];

            while(lo < hi){
                int mi = (lo + hi)>>1;
                if(e < numbers[mi])
                    hi = mi;
                if(numbers[mi] < e)
                    lo = mi + 1;
                if(numbers[mi] == e){
                    j =  mi;
                    break;
                }   
            }
            
            if(j)
                break;  
        }
        
        arr[0] = i + 1; arr[1] = j + 1;               
        return arr;
        
        
        
        /*
        // 优化1 对撞指针
        int l = 0, r = numbers.size() - 1;
        vector<int> arr = {0, 0};
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                arr[0] = l+1;
                arr[1] = r+1;
                return arr;
            }
            
            if(numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
                      
        }
      */  
    }
};
