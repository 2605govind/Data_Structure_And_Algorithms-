n = int(input())
arr = []

for i in range(n):
    a = int(input())
    arr.append(a)

arr.sort()    
print("The Sorted array is:")

for i in range(0, n):
    print(arr[i])