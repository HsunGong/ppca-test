
with open('tmp.out') as f:
    data = []
    for l in f.readlines():
        data.append(l.strip('\n').split(' '))
    # print(data)
    
    dd = []
    dd.append([int(i) for i in data[0]])
    dd.append([int(i) for i in data[1]])

    print([dd[0][i]^dd[1][i] for i in range(len(dd[0]))])