def remove_duplicates_preserve_order(lst):
    seen = set()
    new_lst = []
    for item in lst:
        if item not in seen:
            seen.add(item)
            new_lst.append(item)
    return new_lst

n = int(input())
arr = []


for i in range(n):
    a = int(input())
    arr.append(a)

arr = remove_duplicates_preserve_order(arr)    


for i in arr:
    print(i)
