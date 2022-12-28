class Solution(object):
    def addLetter(self,index,combination):
        #print("index",index,len(self.digits))
        if (index == len(self.digits)):
            self.combinations.append(combination)
            return
        
        digit = self.digits[index]
        
        for char in self.digit_table[digit]:
            #print(index+1,combination+char)
            self.addLetter(index + 1,combination+char)
            
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        self.combinations = []
        self.digits = digits
        self.digit_table = {
            '2' : ["a","b","c"],
            '3' : ["d","e","f"],
            '4' : ["g","h","i"],
            '5' : ["j","k","l"],
            '6' : ["m","n","o"],
            '7' : ["p","q","r","s"],
            '8' : ["t","u","v"],
            '9' : ["w","x","y","z"],
        }
        if (len(self.digits) > 0):
            self.addLetter(0,"")
        return self.combinations