class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==0)
            return 0;
        return f(nums,nums.size()-k,0,nums.size()-1);
    }
    void ex(int &a,int &b){
        int t=a;
        a=b;
        b=t;
    }
    int pivot(vector<int>& a,int lo,int hi){
        int mi=(lo+hi)/2;
        if(a[lo]>a[mi])
            ex(a[lo],a[mi]);
        if(a[lo]>a[hi])
            ex(a[lo],a[hi]);
        if(a[mi]>a[hi])
            ex(a[mi],a[hi]);
        ex(a[lo],a[mi]);
        return a[lo];
    }
    int f(vector<int>& a, int k,int lo,int hi){
        if(lo==hi){
            return a[lo];
        }
        int piv=pivot(a,lo,hi);
        int LO=lo,HI=hi;
        while(LO<HI){
            while(LO<HI&&piv<=a[HI])
                HI--;
            a[LO]=a[HI];
            while(LO<HI&&a[LO]<=piv)
                LO++;
            a[HI]=a[LO];
        }
        a[LO]=piv;
        if(LO==k)
            return piv;
        else if(LO<k)
            return f(a,k,LO+1,hi);
        else
            return f(a,k,lo,LO-1);
    }
};
