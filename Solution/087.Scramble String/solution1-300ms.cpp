#define n 45
class Solution {
public:
    bool flags[n][n][n][n]={0};
    bool F[n][n][n][n]={0};
    bool isScramble(string s1, string s2) {
        int n1,n2,i,j;
        n1=s1.size();
        n2=s2.size();
        if(n1==0||n2==0||n1!=n2)
            return false;
        //初始化
        for(i=0;i<n1;i++)
            for(j=0;j<n1;j++){
                flags[i][i][j][j]=true;
                if(s1[i]==s2[j])
                    F[i][i][j][j]=true;
                else
                    F[i][i][j][j]=false;
            }
        return Func(0,n1-1,0,n1-1);
    }
    bool Func(int s1_lo,int s1_hi,int s2_lo,int s2_hi)
    {
        //F[s1_lo][s1_hi][s2_lo][s2_hi]
        if(flags[s1_lo][s1_hi][s2_lo][s2_hi]==true)
            return F[s1_lo][s1_hi][s2_lo][s2_hi];
        int i;
        bool tag1,tag2;
        tag1=false;tag2=false;
        for(i=0;i<s1_hi-s1_lo;i++)
        {
            tag1=Func(s1_lo,s1_lo+i,s2_lo,s2_lo+i)&&Func(s1_lo+i+1,s1_hi,s2_lo+i+1,s2_hi);
            if(tag1)
                break;
            tag2=Func(s1_lo,s1_lo+i,s2_hi-i,s2_hi)&&Func(s1_lo+i+1,s1_hi,s2_lo,s2_hi-i-1);
            if(tag2)
                break;
        }
        F[s1_lo][s1_hi][s2_lo][s2_hi]=tag1||tag2;
        flags[s1_lo][s1_hi][s2_lo][s2_hi]=true;
        //cout<<s1_lo<<" "<<s1_hi<<" "<<s2_lo<<" "<<s2_hi<<" "<<(tag1||tag2)<<endl;
        return tag1||tag2;
    }
};