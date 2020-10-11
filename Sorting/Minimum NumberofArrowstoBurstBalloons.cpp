bool compare(vector<int>a,vector<int>b){
            return a[1]<=b[1];
    }


class Solution { 
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        
        if(points.size()==0){
            return 0;
        }
        
        sort(points.begin(),points.end(),compare);
        
        int countArrow =1;
        int arrowsize = points[0][1];
        int i=1;
        while(i<points.size()){
            if(arrowsize<=points[i][1] && arrowsize >= points[i][0]){
                i++;
                continue;
            }else{
                arrowsize = points[i][1];
                countArrow++;
                i++;
            }
        }
        
        
        return countArrow;
        
        
    }
};