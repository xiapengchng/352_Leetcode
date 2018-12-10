class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n=s.size();
        if(n==0)
            return 0;
        int i;
        i=n-1;
        while(s[i]==' ')
            i--;
        int j;
        for(j=i;j>=0;j--){
            if(s[j]!=' ')
                ;
            else
                break;
        }
        return i-j;
    }
};
