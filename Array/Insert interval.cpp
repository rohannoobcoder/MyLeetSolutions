class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>output;
        
        int i=0;
        while(i<intervals.size() && intervals[i][1]< newInterval[0])output.push_back(intervals[i++]);
        
        
        vector<int>to_insert = newInterval;
        
        while(i< intervals.size() && intervals[i][0]<=newInterval[1])
        {
            to_insert[0]= min(intervals[i][0],to_insert[0]);
            to_insert[1]=max(intervals[i][1],to_insert[1]);
            i++;
        }
        
        output.push_back(to_insert);
        
        while(i<intervals.size())
        {
            output.push_back(intervals[i]);
            i++;
        }
        
        return output;
    }
};