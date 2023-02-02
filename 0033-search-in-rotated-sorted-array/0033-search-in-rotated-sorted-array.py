class Solution(object):
    def unpivotNums(self,unrotatedIndex):
        Index = (unrotatedIndex+self.minIndex)%len(self.nums)
        return self.nums[Index]
    
    def findMinimum(self,nums,l,r):
        # like merge sort but return minum value and index instead
        if l == r:
            return (nums[l],l)
        if l == r-1:
            if nums[l] < nums[r]:
                return (nums[l],l)
            else :
                return (nums[r],r)
            
        mid = (l+r)//2
        minLeft = self.findMinimum(nums,l,mid)
        minRight = self.findMinimum(nums,mid+1,r)
        
        if minLeft[0] < minRight[0]:
            return minLeft
        else:
            return minRight
        
    def BinarySearch(self,nums,target):
        l = 0
        r = len(nums)-1
        while (r-l > 1):
            mid = (l+r)//2
            leftNumber = self.unpivotNums(l)
            rightNumber = self.unpivotNums(r)
            midNumber = self.unpivotNums(mid)
            if midNumber == target:
                return (mid+self.minIndex)%len(self.nums)
            else:
                if midNumber < target:
                    l = mid
                else:
                    r = mid
        if self.unpivotNums(l) == target:
            return (l+self.minIndex)%len(self.nums)
        if self.unpivotNums(r) == target:
            return (r+self.minIndex)%len(self.nums)
        
        return -1
        
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        self.nums = nums
        self.minIndex = self.findMinimum(nums,0,n-1)[1]
        return self.BinarySearch(nums,target)
        return -1

# find where is minimum value is? O(log(n))
# use some function to convert index where the minimum value is to 0 and n for maximum value O(1)
# find value in binary manner O(log(n))