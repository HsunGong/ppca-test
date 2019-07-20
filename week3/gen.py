from random import shuffle
import numpy

cnt = 0

# False
k = [5, 9, 12]
for i in range(0, 3):
    cnt += 1
    with open("./data/data-" + str(k[i]) + "-" + str(cnt) + ".in", "w") as f:
        arr = numpy.random.randint(low=0, high=1<<k[i], size=1<<k[i])
        # arr = numpy.arange(0, 1<<k)
        shuffle(arr)

        f.write(str(k[i]))
        f.write('\n')
        for a in arr:
            f.write(str(a))
            f.write(' ')
        f.write('\n')


# True
k = [5, 8, 9, 9, 11, 11, 12, 12, 12]
for i in range(len(k)):
    cnt += 1
    with open("./data/data-" + str(k[i]) + "-" + str(cnt) + ".in", "w") as f:
        # arr = numpy.random.randint(low=0, high=1<<k[i], size=1<<k[i])
        arr = numpy.arange(0, 1<<k[i])
        shuffle(arr)

        f.write(str(k[i]))
        f.write('\n')
        for a in arr:
            f.write(str(a))
            f.write(' ')
        f.write('\n')

## True-2
k = [5, 8, 9, 9, 11, 11, 12, 12]
for i in range(len(k)):
    cnt += 1
    with open("./data/data-" + str(k[i]) + "-" + str(cnt) + ".in", "w") as f:
        # arr = numpy.random.randint(low=0, high=1<<k[i], size=1<<k[i])
        p = numpy.arange(0, 1<<k[i])
        shuffle(p)
        q = numpy.arange(0, 1<<k[i])
        shuffle(q)

        arr = [p[m]^q[m] for m in range(len(p))]

        f.write(str(k[i]))
        f.write('\n')
        for a in arr:
            f.write(str(a))
            f.write(' ')
        f.write('\n')