import statistics
import math
import time
print("The value of pi is:",math.pi)
seconds=time.time()
print("Seconds since path epoch=",seconds)
li=[1,2,3,3,2,2,2]
print("The average of list values is:",end="")
print(statistics.mean(li))
local_time=time.ctime(seconds)
print("Local time",local_time)
