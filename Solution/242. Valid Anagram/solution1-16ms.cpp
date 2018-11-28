class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        else{
            map<char, int> record;
            for(int i = 0; i < s.size(); i++){
                if(record.find(s[i]) == record.end())
                    record.insert(make_pair(s[i], 1));
                else
                    record[s[i]]++;
            }

            int num = 0;
            for(int i = 0; i < t.size(); i++){
                if(record.find(t[i]) != record.end()){
                    num++;
                    record[t[i]]--;
                }
                if(record[t[i]] == 0)
                    record.erase(t[i]);
            }

            if(num == s.size())
                return true;
            else
                return false;
        }
    }
};
