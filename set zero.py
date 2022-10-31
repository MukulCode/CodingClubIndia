def setZeroes(row, column, matrix):
     
        if len(matrix) == 0 or len(matrix[0]) == 0: return

        row = [False] * len(matrix)
        column = [False] * len(matrix[0])

        for rowIndex in range(len(matrix)):
            for colIndex in range(len(matrix[0])):
                if matrix[rowIndex][colIndex] == 0:
                    row[rowIndex] = True
                    column[colIndex] = True

        for rowIndex in range(len(matrix)):
            for colIndex in range(len(matrix[0])):
                if row[rowIndex] == True or column[colIndex] == True:
                    matrix[rowIndex][colIndex] = 0

        return matrix

m: int = int(input("Enter number of rows: "))
n: int = int(input("Enter number of columns: "))
matrix: list = [[int(input()) for i in range(n)] for j in range(m)]
print(setZeroes(m,n,matrix))
