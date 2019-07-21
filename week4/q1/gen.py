def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m


from random import shuffle
import random as rand
import numpy
from os import path, listdir, makedirs, remove

if path.isdir('./data'):
    fs = listdir('./data')
    for f in fs:
        # print(f)
        remove('./data/'+ f)
else:
    makedirs('data')



# True
cnt=0
k = [49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60]
for i in range(len(k)):
    cnt += 1
    with open("./data/data-" + str(k[i]) + "-" + str(cnt) + ".in", "w") as f:
        p = numpy.random.randint(1000, size=4)
        s = '{} {} {} {} {}\n'.format(k[i], p[0], p[1], p[2], p[3])
        print(s)
        f.write(s)
