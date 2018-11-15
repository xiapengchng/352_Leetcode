
bool compare(pair<int,int> &p1,pair<int,int>&p2)
{
    if(p1.second<p2.second)
        return true;
    else if(p1.second==p2.second&&p1.first<p2.first)
        return true;
    else
        return false;
}
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),compare);
        vector<pair<int, int>> result;
        for(int i=0;i<people.size();i++)
        {
            
            if(people[i].second==0)
                result.push_back(people[i]);
            else
            {
                int times=0;
                int find_flag=0;
                for(int j=0;j<result.size();j++)
                {
                    if(result[j].first>=people[i].first)
                    {
                        times++;
                    }
                    if(times>people[i].second)
                    {
                        result.insert(result.begin()+j,people.begin()+i,people.begin()+i+1);
                        find_flag=1;
                        break;
                    }
                }
                if(find_flag==0)
                {
                    result.push_back(people[i]);
                }
                    
            }
        }
        return result; 
    }
};
