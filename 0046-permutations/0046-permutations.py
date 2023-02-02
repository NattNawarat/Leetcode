class Solution(object):
    def insertCharacter(self,nums,used,combination):
        
        if len(combination) == len(nums):
            self.answer.append(combination)
            
        for i,num in enumerate(nums):
            if not used[i]: 
                newCombination = combination + [nums[i]]
                newUsed = used[:]
                newUsed[i] = True
                # add that nums[i] into combination and call the same function again
                self.insertCharacter(nums,newUsed,newCombination)
                
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.answer = []
        for i,num in enumerate(nums):
            initUsed = [False]*len(nums)
            initUsed[i] = True
            self.insertCharacter(nums,initUsed,[nums[i]]) 
        
        return self.answer