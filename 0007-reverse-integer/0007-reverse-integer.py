class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        num = x
        MAX_INT = 2147483647
        MIN_INT = -2147483648
        ans = 0
        while(num != 0):
            new_digit = 0
            if(x < 0):
                new_digit = (num % -10)
            else:
                new_digit = num % 10
            #print(num,ans,new_digit)
            if (ans > MAX_INT//10):
                return 0
            if ((ans == MAX_INT//10) and (new_digit >= 7)):
                return 0
            
            if (ans < -(MIN_INT//-10)):
                return 0
            if ((ans == -(MIN_INT//-10)) and (new_digit <= -8)):
                return 0
            
            if(x < 0):
                num = -(num//-10)
            else:
                num = num //10
            ans = (ans * 10) + new_digit
        return ans