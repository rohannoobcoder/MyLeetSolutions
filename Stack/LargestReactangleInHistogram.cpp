class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stk;
        int max_area=0;
        int top=0;
        int i=0;
        while(i<heights.size())
        {
            if(stk.empty())
            {
                stk.push(i);
                i++;
            }else{
                if(heights[stk.top()] > heights[i])
                {
                    top=stk.top();
                    stk.pop();
                    if(!stk.empty())
                    {
                        int temp_area = heights[top]*(i-stk.top()-1);
                        max_area = max(max_area,temp_area);
                    }
                    else{
                        int temp_area = heights[top]*i;
                        max_area = max(max_area,temp_area);
                    }
                }
                else
                {
                    stk.push(i);
                    i++;
                }
            }
        }
        
        while(!stk.empty())
        {
            top=stk.top();
            stk.pop();
            if(!stk.empty())
            {
                int temp_area = heights[top]*(i-stk.top()-1);
                max_area = max(max_area,temp_area);
            }else{
                    int temp_area = heights[top]*i;
                    max_area = max(max_area,temp_area);
            }
        }
            
        return max_area;
        
    }
};