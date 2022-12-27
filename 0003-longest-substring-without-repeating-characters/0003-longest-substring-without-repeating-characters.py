class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}
        l = 0
        r = 0
        n = len(s)
        Max = 0
        while (r < n):
            #print(l,r,s[r])
            if s[r] in seen:
                #print("HIT")
                # clean hash table to 
                start = l
                end = seen[s[r]]+1
                for i in range(start,end):
                    seen.pop(s[i],None)
                l = end
                continue
                
            seen[s[r]] = r
            Max = max(Max,r-l+1)
            r+=1
        return Max
        