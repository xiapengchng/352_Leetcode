class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        auto iter=nums.begin();
        int ref=val,cnt=0;
        while(iter!=nums.end()){
            if(*iter==ref){
                nums.erase(iter);
            }
            else{
                iter++;
                cnt++;
            }
        }
        return cnt;
    }
};