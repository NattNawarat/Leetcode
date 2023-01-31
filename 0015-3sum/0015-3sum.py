class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums = sorted(nums)
        answerMap = {} #use key to eliminate duplicate
        for i in range(2,n):
            # pick first number as nums[i]
            # hash map to tell if we have third number we're looking for
            seen = {}
            for j in range(0,i):
                twoSum = nums[i]+nums[j]
                if (-twoSum in seen.keys()):
                    answerMap[(nums[i],nums[j],-twoSum)] = True
                seen[nums[j]] = True
        return list(answerMap.keys())
                    