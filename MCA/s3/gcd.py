num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))
a, b = num1, num2
while b != 0:
    a, b = b, a % b
print("The GCD of", num1, "and", num2, "is:", a)
