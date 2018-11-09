class Solution {
public:
    char strs[500]={0};
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        bra(0,0,0,n,res);
        return res;
    }
    void bra(int pos,int open,int close,int num,vector<string>& res){
        if(close==num){
            res.push_back(strs);
        }
        else{
            if(open>close){
                strs[pos]=')';
                //cout<<pos<<endl;
                bra(pos+1,open,close+1,num,res);
            }
            if(open<num){
                strs[pos]='(';
                //cout<<pos<<endl;
                bra(pos+1,open+1,close,num,res);
            }
        }
    }

}
