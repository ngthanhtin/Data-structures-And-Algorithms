class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        duplicate = 0
        for i in range(len(nums)-1):
            if nums[i+1] == nums[i]:
                duplicate = 1
            else:
                if duplicate:
                    duplicate = 0
                else:
                    return nums[i]
        
        return nums[-1]