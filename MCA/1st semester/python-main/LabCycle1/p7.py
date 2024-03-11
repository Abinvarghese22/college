x1 = str(input("enter a string :"))
firstchar=x1[0]
x1=x1.replace(firstchar,"$")
x1=firstchar+x1[1:]
print(x1)