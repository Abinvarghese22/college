fruits={"apple":2,"orange":1, "pinapple":31,"waterlemon":61,"grapes":10}
l=list(fruits.items())
l.sort()
print("Ascending order is :",l)
l=list(fruits.items())
l.sort(reverse=True)
print("Descending order is:",l)
