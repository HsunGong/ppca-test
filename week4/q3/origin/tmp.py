cnt = 0

ans = []

x = 1
while x < 1e9:
    ans.append([x, 6])
    cnt += 1
    x *= 6

x = 36
while x < 1e9:
    ans.append([x, 36])
    cnt += 1
    x *= 6

x=6
while x < 1e9:
    ans.append([x, 12])
    cnt += 1
    x *= 6

print(cnt)
for a in ans:
    print(a[0], a[1])