class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        dp = [-1]*len(nums)
        for i in range(len(nums)):
            prev1 = dp[i-3] if i-3 >=0 else 0
            prev2 = 0 if i - 2 < 0 else dp[i-2]
            dp[i] = max(prev1,prev2) + nums[i]
        print(dp)
        return max(dp[-1],dp[-2])