class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {     
        
        /*set的成员函数
            begin()--返回指向第一个元素的迭代器;
            end()--返回指向最后一个元素的迭代器;
            size()--集合中元素的数目;
            find()--返回一个指向被查找到元素的迭代器;
        */
        
        set<int> record(nums1.begin(), nums1.end());
        
        set<int> resultSet;
        for (int i = 0; i < nums2.size(); i++){
            if (record.find(nums2[i]) != record.end())
                resultSet.insert(nums2[i]);
        }
        
        return vector<int>(resultSet.begin(), resultSet.end());
        }
    
};
