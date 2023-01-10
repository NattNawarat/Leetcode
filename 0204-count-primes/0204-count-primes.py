class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <2 :
            return 0
        isPrime = [True]*n
        isPrime[0] = False
        isPrime[1] = False
        count = 0
        for i in range(2,n):
            if not isPrime[i]:
                continue
            count += 1
            if(i < int(n**0.5)+1):
                isPrime[i*i:n:i] = [False] * ((n-1-i*i)//i + 1)
        return count