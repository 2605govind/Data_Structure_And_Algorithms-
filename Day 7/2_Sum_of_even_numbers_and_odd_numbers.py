n = int(input())
arr = []

for i in range(n):
    a = int(input())
    arr.append(a)

even = 0
odd = 0
for i in range(0, n):
    if arr[i] % 2 == 0:
        even += arr[i]
    
    elif arr[i] % 2 == 1:
        odd += arr[i]
        
        

print("The sum of the even numbers in the array is",even)
print("The sum of the odd numbers in the array is",odd)