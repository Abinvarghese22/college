list=["Hello","datastructure"]
print(list)
a=0
for i in list:
    a=len(i)if len(i)>a else a
print(a)