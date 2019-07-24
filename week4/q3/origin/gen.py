from os import path, listdir, makedirs, remove
import os

files = []
if path.isdir('./data'):
    fs = listdir('./data')
    for f in fs:
        if path.splitext(f)[1] == '.in':
            files.append('./data/' + f)
else:
    raise "Not found"

import subprocess as sub
import time

files = sorted(files)

easy = []
diff = []
for file in files:
    with open(file, 'r') as f:
        tick = time.time()
        try:
            sub.run('../a.out', stdin=f, stdout=sub.DEVNULL, timeout=1.0)
        except sub.TimeoutExpired as exp:
            pass
        if time.time() - tick <= 1:
            easy.append(file)
        else:
            diff.append(file)
        print(time.time() - tick)


if path.isdir('../data'):
    fs = listdir('../data')
    for f in fs:
        # print(f)
        remove('../data/'+ f)
else:
    makedirs('../data')


size = 8

datas = []
for file in easy:
    with open(file, 'r') as f:
        data = f.read()
        datas.append(data)


cnt = 0
f_cnt = 1
for d in datas:
    with open('../data/data-' + str(f_cnt) + '.in', 'a+') as f:
        f.write(d)

    cnt += 1
    if cnt == size:
        cnt = 0
        f_cnt += 1

datas = []
for file in diff:
    with open(file, 'r') as f:
        data = f.read()
        datas.append(data)

for d in datas:
    with open('../data/data-' + str(f_cnt) + '.in', 'a+') as f:
        f.write(d)
    cnt += 1

    if cnt == size:
        cnt = 0
        f_cnt += 1
    