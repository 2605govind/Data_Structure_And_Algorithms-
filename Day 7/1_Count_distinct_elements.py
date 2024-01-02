n = int(input())
arr = []

for i in range(n):
    a = int(input())
    arr.append(a)

count = 1
for i in range(1, n):
    if arr[i - 1] != arr[i]:
        count += 1

print("There are",count,"distinct element in the array.")