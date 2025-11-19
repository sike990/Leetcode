class Solution {
public:
    int maxArea(vector<int>& height) {
        //Why this works
        /*The reason is that if we have two pointers  at the two ends and we do have different heights then suppose we take the area of current and then move the larger one thenno matter how far we will go we will always end up at something smaller than our previous calculation as the max height will be constant(min height) and breadth will go lower and lower so the result will also be smaller than before so the search space is inefficient instead we might find a better solution if we move the smaller one cause we may find something as big as current height and get a greater area*/
        int lef = 0 , rig = height.size()-1;
        int maxarea = 0;
        while(lef < rig){
            int curr = (rig-lef)*(min(height[lef],height[rig]));
            maxarea = max(curr , maxarea);
            if(height[lef] > height[rig])rig--;
            else lef++;
        }
        return maxarea;
    }
};