string mut(string num1, string num2) {       
    if(num2=="0"||num1=="0")
        return "0";
    int n2=num2[0]-'0';
    if(n2==0)
        return "0";
    int i=num1.size()-1;
    int carry=0;
    int num_zero=num2.size()-1;
    string result;
    result.clear();
    while(i>=0||carry!=0)
    {
        
        int n1=i>=0?num1[i]-'0':0;
        n1=n1*n2+carry;
        carry=n1/10;
        i--;
    
        result.push_back(n1%10+'0');
        //cout<<result<<endl;
    }
    reverse(result.begin(),result.end());
    //cout<<num_zero<<"num_zero"<<endl;
    while(num_zero>0)
    {
        result.push_back(0+'0');
        num_zero--;
    }
    //string t(result.begin()+1,result.end());
    return result;
}
string add_x(string num1,string num2)
{
    string result;
    int carry=0;
    int i=num1.size()-1;
    int j=num2.size()-1;
    while(i>=0||j>=0||carry!=0)
    {
        int n1=i>=0?num1[i]-'0':0;
        int n2=j>=0?num2[j]-'0':0;
        int add_re=n1+n2+carry;
        carry=add_re/10;
        result.push_back(add_re%10+'0');
        i--;
        j--;
    }
    reverse(result.begin(),result.end());
    return result;
}
class Solution {
public:
    string multiply(string num1, string num2) {       
        if(num2=="0"||num1=="0")
            return "0";
        string result="0";
        for(int i=num2.size()-1;i>=0;i--)
        {
            string temp2(num2.begin()+i,num2.end());
           // cout<<temp2<<endl;
            string mut_re=mut(num1,temp2);
           // cout<<mut_re<<endl;
            result=add_x(result,mut_re);
            
        }
        return result;
    }
};
