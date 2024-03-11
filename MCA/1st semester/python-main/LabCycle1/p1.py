a=int(input("enter first year"))
b=int(input("second first year"))
for i in range(a,b):
         if(i%4==0)and(i%100!=0)and(i%400==0):
                  print(i)
