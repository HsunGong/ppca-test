from random import shuffle
import numpy


## False
# k = [5, 10, 12]
# for i in range(0, 3):
#     with open("./data/false" + str(i) + ".in", "w") as f:
#         arr = numpy.random.randint(low=0, high=1<<k[i], size=1<<k[i])
#         # arr = numpy.arange(0, 1<<k)
#         shuffle(arr)

#         f.write(str(k[i]))
#         f.write('\n')
#         for a in arr:
#             f.write(str(a))
#             f.write(' ')
#         f.write('\n')


## True
# k = [5, 8, 9, 10, 11, 11, 12]
# for i in range(len(k)):
#     with open("./data/true" + str(i) + ".in", "w") as f:
#         # arr = numpy.random.randint(low=0, high=1<<k[i], size=1<<k[i])
#         arr = numpy.arange(0, 1<<k[i])
#         shuffle(arr)

#         f.write(str(k[i]))
#         f.write('\n')
#         for a in arr:
#             f.write(str(a))
#             f.write(' ')
#         f.write('\n')

## True-2
k = [5, 8, 9, 10, 11, 11, 12]
for i in range(len(k)):
    with open("./data/true" + str(i) + ".in", "w") as f:
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