# Python 3 program to find a pair with product in given array.
 
# Function to find greatest number
def greatest( arr , size):
 
    result = -1
    for i in range(size):
        for j in range(size - 1):
            for k in range(j + 1, size):
                if (arr[j] * arr[k] == arr[i]):
                    result = max(result, arr[i])
    return result
 
# Driver code
if __name__ == "__main__":
     
    arr = [10, 3, 5, 30, 35]
    size = len(arr)
 
    print(greatest(arr, size))

#First OpenSource for Hackroberfest by Venkat Raghaveendra