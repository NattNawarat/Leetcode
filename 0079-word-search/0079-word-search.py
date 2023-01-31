class Solution:
    def travel(self,Row,Col,wordIndex)->bool:
        
        
        #print(Row,Col,wordIndex)
        # Print visit
        """for i in range(0,self.n):
            for j in range(0,self.m):
                print(1*self.visit[i][j],end="")
            print()
        """
        
        if self.visit[Row][Col] == True:
            #print(f"VISIT {Row} {Col}")
            return False
        
        if wordIndex == len(self.word)-1:
            #print("Correct",Row,Col,wordIndex,len(self.word),self.word)
            return True
        
        #print(f"set visit TRUE {Row} {Col}")
        self.visit[Row][Col] = True
        
        
        if Row + 1 < self.n:
            if self.word[wordIndex+1] == self.board[Row+1][Col]:
                if self.travel(Row+1,Col,wordIndex+1):
                    return True
        if Row - 1 >= 0:
            if self.word[wordIndex+1] == self.board[Row-1][Col]:
                if self.travel(Row-1,Col,wordIndex+1):
                    return True
        if Col + 1 < self.m:
            if self.word[wordIndex+1] == self.board[Row][Col+1]:
                if self.travel(Row,Col+1,wordIndex+1):
                    return True
        if Col - 1 >= 0:
            if self.word[wordIndex+1] == self.board[Row][Col-1]:
                if self.travel(Row,Col-1,wordIndex+1):
                    return True
        
        #print(f"set visit FALSE {Row} {Col}")
        self.visit[Row][Col] = False
        return False
        
                        
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.word = word
        self.n = len(board)
        self.m = len(board[0])
        self.board = board
        self.visit = [[False] * self.m for i in range (self.n)]
        for i in range(0,self.n):
            for j in range(0,self.m):
                if board[i][j] == word[0]:
                    if self.travel(i,j,0):
                        return True
        return False