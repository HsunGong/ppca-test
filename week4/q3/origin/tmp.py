cnt = 0

ans = []

x = 1
while x < 1e9:
    ans.append([x, 2])
    cnt += 1
    x *= 2

x = 2
while x < 1e9:
    ans.append([x, 4])
    cnt += 1
    x *= 4

x = 8
while x < 1e9:
    ans.append([x, 16])
    cnt += 1
    x *= 16

x = 128
while x < 1e9:
    ans.append([x, 256])
    cnt += 1
    x *= 256



print(cnt)
for a in ans:
    print(a[0], a[1])