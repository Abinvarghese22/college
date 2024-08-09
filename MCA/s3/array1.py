import numpy as np
array_4x4 = np.array([
    [10, 20, 30, 20],
    [18, 23, 25, 35],
    [48, 58, 68, 78],
    [47, 57, 67, 77]
])
print("Full array:")
print(array_4x4)
print()
print("Rows excluding the first:")
print(array_4x4[1:])
print()
print("Rows excluding the first and excluding the last column:")
print(array_4x4[1:, :-1])
print()
print("1st and 2nd columns in the 2nd and 3rd rows:")
print(array_4x4[1:3, 0:2])

