list1 = [4,7,54,76,88]
list2 = [37,9,45,67,4,76]
print("list1 :",list1)
print("lis2:",list2)
print("length of list1 :",len(list1))
print("length of list2 :",len(list2))
if len(list1)==len(list2):
    print("length of lists are same")
else:
    print("lenths are not same")
    print("sum of list1:",sum(list1))
    print("sum of list2:",sum(list2))
    if sum(list1)==sum(list2):
        print("sum of lists are same")
    else:
        print("sum of lists are not same")
        check = any(item in list1 for item in list2)
        print("any value occur in both : ", check)
