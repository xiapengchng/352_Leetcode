/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval &a1,Interval &a2)
{
    if(a1.end<a2.end)
        return true;
    else if(a1.end==a2.end&&a1.start<a2.start)
        return true;
    else 
        return false;
        
}
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int first=0;
        int next=0;
        int last=intervals.size();
        int total=0;
        while(first<last)
        {
            total++;
            next=first+1;  
            while(next<last&&intervals[first].end>intervals[next].start)
            {
                next++; 
            }
            first=next;
            
        }
        return last-total;
        
    }
};
