class Solution:
    def sortString(self,strs):
        sortedStrs = ''.join(sorted(strs))
        return (sortedStrs,strs)
    
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        wordMap = {}
        sortedStrs = list(map(self.sortString,strs))
        for sortedStr in sortedStrs:
            key = sortedStr[0]
            value = sortedStr[1]
            if key in wordMap:
                wordMap[key].append(value)
            else:
                wordMap[key] = [value]
        return list(wordMap.values())