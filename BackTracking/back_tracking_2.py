from typing import List

class Solution:
    visited = None
    direction_arr = [(-1, -1),  (-1, 0),  (-1, 1),  (0, -1),  (0, 0),  (0, 1),  (1, -1),  (1, 0),  (1, 1)]

    def helper(self, board, word, wordc, row, col):
        if wordc == word:
            return True
        if self.visited[row][col]:
            return False
        for i in self.direction_arr:
            x, y = i
            rown = row + x
            coln = col + y
            
            if rown >= 0 and rown < len(board) and coln >= 0 and coln < len(board[0]):
                found = self.helper(board, word, wordc + board[rown][coln], rown, coln)
                if found:
                    return True
                else:
                    self.visited[rown][coln] = False
                
        
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.visited = [[False for j in range(len(board[0]))] for i in range(len(board))]
        return self.helper(board, word, "", 0, 0)

board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
word = "ABCCED"
ans = Solution().exist(board, word)

print(ans)