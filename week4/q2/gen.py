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


def gen():
    # True
    k = numpy.random.randint(2, 1000, size=10)
    for i in range(10):
        with open("./data/data-" + str(i) + ".in", "w") as f:
            f.write(str(k[i]))

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
    gen()
    # list()