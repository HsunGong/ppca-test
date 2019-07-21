from random import shuffle
import random as rand
import numpy
from os import path, listdir, makedirs, remove

def init():
    if path.isdir('./data'):
        fs = listdir('./data')
        for f in fs:
            # print(f)
            remove('./data/'+ f)
    else:
        makedirs('data')


def gen(size=5): # size = 5
    # True
    cnt=0
    k = numpy.array([64,128,256,512,640,400,800]) # -1
    r = numpy.random.choice(range(1,1000), size=100, replace=False)
    k = numpy.concatenate((k, r), axis=0) # 5 tiems
    k = k[0:10*size]
    numpy.random.shuffle(k)

    for i in range(10):
        with open("./data/data-" + str(i) + ".in", "w") as f:
            f.write(str(size) + '\n')
            s = '{}\n{}\n{}\n{}\n{}\n'.format(k[cnt],k[cnt+1],k[cnt+2],k[cnt+3],k[cnt+4])
            f.write(s)
        cnt += 5

from os.path import splitext

def list():
    # get name
    files = set(['./data/' + splitext(i)[0] for i in listdir('./data')])

    with open('file-name', 'w') as f:
        for file in files:
            f.write(file)
            f.write('\n')

if __name__ == "__main__":
    init()
    gen(5) # single file will run this test for how many times
    # list()