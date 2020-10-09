'''
import random
N = [10,100,1000,2000,5000]
x = open("pos_01_in.txt","w")
for i in range(len(N)):
    count = N[i]
    for j in range(count):
        arr = [random.randint(-10,10000) for i in range(count)]
        arr_in_str = ' '.join([str(k) for k in arr])
        x.write(arr_in_str)
        x.write("\n")
x.close()
'''
import random
N = [10,1000,10000,15000]
for i in range(len(N)):
    count = N[i]
    x = 'pos_0'+str(count)+'_in.txt'
    file = open(x,"w")
    file.write(str(count)+'\n')
    arr = [random.randint(-10,10000) for i in range(count)]
    arr = sorted(arr,reverse = True)
    print(x)
    arr_in_str = ' '.join([str(k) for k in arr])
    file.write(arr_in_str)
    file.write("\n")
    file.close()
'''
import random
N = [1000]
x = open("pos_03_in.txt","w")
for i in range(len(N)):
    count = N[i]
    for j in range(count):
        arr = [random.randint(-10,10000) for i in range(count)]
        arr_in_str = ' '.join([str(k) for k in arr])
        x.write(arr_in_str)
        x.write("\n")
x.close()
import random
N = [2000]
x = open("pos_04_in.txt","w")
for i in range(len(N)):
    count = N[i]
    for j in range(count):
        arr = [random.randint(-10,10000) for i in range(count)]
        arr_in_str = ' '.join([str(k) for k in arr])
        x.write(arr_in_str)
        x.write("\n")
x.close()

import random
N = [5000]
x = open("pos_05_in.txt","w")
for i in range(len(N)):
    count = N[i]
    for j in range(count):
        arr = [random.randint(-10,10000) for i in range(count)]
        arr_in_str = ' '.join([str(k) for k in arr])
        x.write(arr_in_str)
        x.write("\n")
x.close()
'''
