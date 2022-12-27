class RandomizedSet:

    def __init__(self):
        self.index = {} # index of value in values array
        self.values = [] # values
        self.n = -1 # last index of values
        
    def insert(self, val: int) -> bool:
        #print(f"insert {val}")
        if val in self.index.keys():
            #print(self.values)
            return False
        self.n += 1;
        self.values.append(val)
        self.index[val] = self.n
        #print(self.values)
        return True
        
    def remove(self, val: int) -> bool:
        #print(f"remove {val}")
        if val in self.index.keys():
            index = self.index[val]
            self.index[self.values[self.n]] = index # swap index of last value to value to delete
            self.values[index],self.values[self.n] = self.values[self.n],self.values[index]   # swap last value with value to delete
            self.values.pop() # pop delete value
            self.n = self.n-1
            self.index.pop(val,None) # pop delete value index
            #print(self.values)
            return True
        else:
            #print(self.values)
            return False

    def getRandom(self) -> int:
        #print("get")
        i = random.randrange(0, self.n+1)
        return self.values[i]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()