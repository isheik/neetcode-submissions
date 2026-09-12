/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // sort by start time
        // check whether the current range overwrap with the next range
        // if not, switch the current range to next
        // if overwrap, return false
        
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.start < b.start;
        });

        int i=0;

        while(i + 1 < intervals.size()) {
            if(intervals[i].end > intervals[i+1].start) {
                return false;
            }
            i++;
        }

        return true;
    }
};
