static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if(people.size()<=1)
            return people.size();
        sort(people.begin(),people.end());
        int first_index=0,last_index=people.size()-1;
        int result;
        while(first_index<last_index&&first_index<people.size())
        {

            if(people[first_index]+people[last_index]<=limit)
            {
                result++;
                first_index++;
                last_index--;
            }
            else
            {
                result++;
                last_index--;
            }

        }
        if(first_index==last_index)
            {
                
                result++;
            }
        return result;
        
    }
};
