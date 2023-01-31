class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n = len(haystack)
        m = len(needle)
        longestPrefix = [0] * m 
        # calculate 
        i = 0
        j = 1 
        while j < m:
            if needle[j] == needle[i]:
                i+=1
                longestPrefix[j] = i
                j+=1
            else :
                if i == 0:
                    longestPrefix[j] = 0
                    j += 1
                else:
                    i = longestPrefix[i-1]
        print(longestPrefix)
        needleIndex = 0
        haystackIndex = 0
        answerIndex = -1
        while (haystackIndex < n):
            print(haystackIndex,needleIndex)
            if haystack[haystackIndex] == needle[needleIndex]:
                needleIndex += 1 
                haystackIndex += 1 
            else:
                if needleIndex == 0:
                    haystackIndex += 1
                if needleIndex > 0:
                    needleIndex = longestPrefix[needleIndex-1]
            if needleIndex == m:
                return haystackIndex-m
        return answerIndex
"""
LPS
onionions
onions
0 0 0 1 2 0
"""
        