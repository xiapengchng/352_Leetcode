ass Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(k<=0||k>n)
            return result;
        if(k==1)
        {
            for(int i=1;i<=n;i++)
            {
                vector<int> temp;
                temp.push_back(i);
                result.push_back(temp);
            }
            return result;
        }
        if(k==n)
        {
            vector<int> temp;
            for(int i=1;i<=n;i++)
            {
                
                temp.push_back(i);
            }
            result.push_back(temp);
            return result;
        }
        vector<vector<int>> n_get=combine(n-1,k-1);
        for(int i=0;i<n_get.size();i++)
        {
            n_get[i].push_back(n);
            //cout<<i<<n_get[i].size();
        }
        vector<vector<int>> n_not=combine(n-1,k);
        n_get.insert(n_get.end(),n_not.begin(),n_not.end());
        
        return n_get;
        
    }
};
