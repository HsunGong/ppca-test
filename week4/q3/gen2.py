from numpy import random as rand
import numpy as np
from os import path, listdir, makedirs, remove

if path.isdir('./data'):
    fs = listdir('./data')
    for f in fs:
        # print(f)
        remove('./data/'+ f)
else:
    makedirs('data')



# True
cnt=10
k = [99, 100, 100, 100, 100]
for i in range(len(k)):
    cnt += 1
    with open("./data/data-" + str(cnt) + ".in", "w") as f:
        p = np.abs(rand.normal(0, scale=int(1e7), size=k[i])).astype(int)
        q = np.abs(rand.normal(0, scale=int(1e4), size=k[i])).astype(int)
        f.write(str(k[i]) + '\n')
        for t in range(k[i]):
            f.write('{} {}\n'.format(p[t], q[t]))