class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0)
            return 0;
        int people=0;
        sort(g.begin(),g.end());
        for(int i=0;i<s.size();i++)
        {
            if(g.size()==0)
                return people;
            if(s[i]>=g[0])
            {
                vector<int>::iterator result=lower_bound(g.begin(),g.end(),s[i]);
                people++;
                if(result==g.end()||*result!=s[i])
                    g.erase(result-1);
                else 
                    g.erase(result);
            }
            
        }
        return people;
    }
};
