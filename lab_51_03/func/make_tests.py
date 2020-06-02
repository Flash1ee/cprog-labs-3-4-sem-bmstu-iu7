import random
x = open("pos_01_in.txt",'w')
y = open("pos_01_out.txt",'w')
mas =[random.randint(-500, 500) for i in range(10)]
x.write(" ".join(map(str, mas)))
y.write(" ".join(map(str, sorted(mas))))
y.write(" ")
x.close()
y.close()

x = open("pos_02_in.txt",'w')
y = open("pos_02_out.txt",'w')
mas =[random.randint(-500, 500) for i in range(30)]
x.write(" ".join(map(str, mas)))
y.write(" ".join(map(str, sorted(mas))))
y.write(" ")
x.close()
y.close()

x = open("pos_03_in.txt",'w')
y = open("pos_03_out.txt",'w')
mas =[random.randint(-500, 500) for i in range(50)]
x.write(" ".join(map(str, mas)))
y.write(" ".join(map(str, sorted(mas))))
y.write(" ")
x.close()
y.close()

