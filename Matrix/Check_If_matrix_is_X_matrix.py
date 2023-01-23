class Solution:
    def isDiagonal(self,a,b,n):
        return (a==b) or (a+b) == n-1 
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        for i in range(n):
            for j in range(n):
                if(self.isDiagonal(i,j,n)) :
                    if(grid[i][j]==0):
                        return False
                else :
                    if grid[i][j]!=0:
                        return False
        return True
