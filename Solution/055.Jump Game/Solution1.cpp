class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1)
            return true;
        if(nums[0]==0)
            return false;
        bool pos[nums.size()]={false};
        if(nums.size()==2)
            return true;
        pos[nums.size()-1]=true;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]==0)
                pos[i]=false;
            else
            {
                int step=nums[i];
                if(step+i>=nums.size()-1)
                    pos[i]=true;
                else
                {
                    while(step>0)
                    {
                        if(pos[step+i]==true)
                        {
                            pos[i]=true;
                            break;
                        }
                        step--;
                    }
                }
            }
        }
        return pos[0];
        
    }
};
