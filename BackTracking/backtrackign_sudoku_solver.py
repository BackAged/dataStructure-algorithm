from typing import List
class Solution:
    def find_empty_location(self, board, l): 
        for row in range(9): 
            for col in range(9): 
                if(board[row][col]== '.'): 
                    l[0]=row 
                    l[1]=col 
                    return True
        return False

        # in the specified row matches the given number. 
    def used_in_row(self, board,row,num): 
        for i in range(9): 
            if(board[row][i] == num): 
                return True
        return False
        
    # Returns a boolean which indicates whether any assigned entry 
    # in the specified column matches the given number. 
    def used_in_col(self, board,col,num): 
        for i in range(9): 
            if(board[i][col] == num): 
                return True
        return False
    
    # Returns a boolean which indicates whether any assigned entry 
    # within the specified 3x3 box matches the given number 
    def used_in_box(self, board,row,col,num): 
        for i in range(3): 
            for j in range(3): 
                if(board[i+row][j+col] == num): 
                    return True
        return False

    def check_location_is_safe(self, board,row,col,num): 
        
        # Check if 'num' is not already placed in current row, 
        # current column and current 3x3 box 
        return not self.used_in_row(board,row,num) and not self.used_in_col(board,col,num) and not self.used_in_box(board,row - row%3,col - col%3,num)

    
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
         # 'l' is a list variable that keeps the record of row and col in find_empty_location Function     
        l=[0,0] 
            
        # If there is no unassigned location, we are done     
        if(not self.find_empty_location(board,l)): 
            return True
            
        # Assigning list values to row and col that we got from the above Function  
        row=l[0] 
        col=l[1] 
            
        # consider digits 1 to 9 
        for num in range(1,10): 
                
            # if looks promising 
            if(self.check_location_is_safe(board,row,col,num)): 
                    
                # make tentative assignment 
                board[row][col]= str(num)

                # return, if success, ya! 
                if self.solveSudoku(board): 
                    return True

                # failure, unmake & try again 
                board[row][col] = 0
                    
        # this triggers backtracking         
        return False 

grid = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]

s = Solution()

s.solveSudoku(grid)

print(grid)