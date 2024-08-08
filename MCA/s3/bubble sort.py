input_string = input("Enter a list of numbers separated by spaces: ")
arr = list(map(int, input_string.split()))
n = len(arr)
print("Unsorted list:",arr)
for i in range(n):
    for j in range(0, n-i-1):
        if arr[j] > arr[j+1]:
            arr[j], arr[j+1] = arr[j+1], arr[j]
print("Sorted list:", arr)
