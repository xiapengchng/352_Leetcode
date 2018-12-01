class Solution {
public:
    bool isHappy(int n) {    
    
    unordered_set<int> record;
    
    while(true){
        string s = to_string(n);
        int sum = 0;
        
        for(int i = 0; i < s.size(); i++){
            // 字符串转int花了好多时间，其实很简单，就是s[i]-'0'，以后记住
            sum = sum + pow(s[i]-'0',2);
        }
        if(record.find(sum) != record.end() && sum != 1){
            return false;
            break;
        }
        else if(sum == 1){
            return true;
            break;
        }
        else
            record.insert(sum);
            n = sum; 
    }   
    }
};
