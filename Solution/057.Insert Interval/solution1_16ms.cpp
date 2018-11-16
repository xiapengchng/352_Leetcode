tion for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int int_flag=0;
        if(intervals.size()==0)
        {
            result.push_back(newInterval);
            return result;
        }
        for(int i=0;i<intervals.size();i++)
        {
            if(int_flag==1)
                result.push_back(intervals[i]);
            if(newInterval.end<intervals[i].start&&int_flag==0)
            {
                result.push_back(newInterval);
                result.push_back(intervals[i]);
                int_flag=1;
                continue;
            }
            if(newInterval.start>intervals[i].end&&int_flag==0)
            {
                result.push_back(intervals[i]);
                continue;
            }
            if(newInterval.end<=intervals[i].end&&newInterval.start>=intervals[i].start&&int_flag==0)
            {
                result.push_back(intervals[i]);
                int_flag=1;
                continue;
            }
            if(newInterval.start<=intervals[i].start&&newInterval.end>=intervals[i].end)
            {
                continue;
            }
            if(newInterval.start>=intervals[i].start&&newInterval.end>=newInterval.end)
            {
                newInterval.start=intervals[i].start;
                continue;
            }
            if(newInterval.end>=intervals[i].start&&newInterval.end<=intervals[i].end)
            {
                newInterval.end=intervals[i].end;
                
                continue;
            }

            
        }
        if(result.size()==0)
        {
            result.push_back(newInterval);
            return result;
        }
        if(newInterval.start>result[result.size()-1].end)
            result.push_back(newInterval);
        return result;
        
    }
};
