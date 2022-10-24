# Build a magic square for any odd n number(n*n) using python
# sum of row, column, diagonal in a magic square is n*(n*(n+1)/2)

def magic_square(n):
    magicSquare=[]
    for i in range(n):
        l=[] 
        for j in range(n):
            l.append(0) 
        magicSquare.append(l)
    print(magicSquare)
    
    i=n//2
    j=n-1
    count=1
    num=n*n
    while(count<=num):
        if(i==-1 and j==n):
            i=0
            j=n-2
        else:
            if(i<0):
                i=n-1
                
            if(j==n):
                j=0
                
        if(magicSquare[i][j]!=0):
            j=j-2
            i=i+1
            continue
        else:
            magicSquare[i][j]=count
            count+=1
        
        i=i-1
        j=j+1
        
    print("THE SUM OF ROWS/COLUMNS/DIAGNOALS= ", (n*(n*n+1))/2)
        
    for i in range(n):
            for j in range(n):
               print(magicSquare[i][j], end=" ")
            print()
             
n=int(input("ENTER THE VALUE OF N, ODD NUMBER FOR WHICH YOU WANT TO BUILD MAGIC SQUARE"))             
magic_square(n)