from copy import copy
class Solution:
    def trap(self, heights: List[int]) -> int:
        ansarray = [0]*len(heights)
        rightarray = ansarray.copy()
        leftarray = ansarray.copy()

        i = len(heights)-1
        tempmax = heights[-1]
        while i >= 0:
            if tempmax < heights[i]:
                tempmax = heights[i]
            rightarray[i] = tempmax
            i -= 1
        j = 0   
        tempmax = heights[0]
        while j < len(heights):
            if heights[j] > tempmax:
                tempmax = heights[j]
            leftarray[j] = tempmax
            j+=1

        print("left :",leftarray)
        print("right: ",rightarray)
        for x in range(len(heights)):
            diff = min(leftarray[x],rightarray[x])
            curr = diff-heights[x]
            ansarray[x] = curr
        return sum(ansarray)
        


