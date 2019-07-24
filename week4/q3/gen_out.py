import subprocess as sub
import time

from os import path, listdir, makedirs, remove

names = []

if path.isdir('./data'):
    fs = listdir('./data')
    for f in fs:
        if path.splitext(f)[1] == '.in':
            names.append('./data/' + path.splitext(f)[0])
else:
    raise "not found"

name = sorted(names)
for name in names:
    with open(name + '.in', 'r') as f:
        f2 = open(name + '.out', 'w+')
        tick = time.time()
        try:
            sub.run('./a.out', stdin=f, stdout=f2, timeout=1.0)
        except sub.TimeoutExpired as exp:
            pass
        print(name, time.time() - tick)
        
