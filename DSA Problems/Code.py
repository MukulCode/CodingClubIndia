arr=[-1,-1,-1]
pos=0
neg=0
zero=0
step=0
for i in range(len(arr)):
    if arr[i]==0:
        zero=zero+1
    elif arr[i]<0:
        neg=neg+1
        step=step+(-1-arr[i])
    else:
        pos=pos+1
        step=step+(arr[i]-1)
if(neg%2==0):
    step=step+zero

else:
    if(zero>0):
        step=step+zeo
    else:
        step=step+2
print(step)
        
