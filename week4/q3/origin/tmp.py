cnt = 0

ans = []

x = 1
while x < 1e9:
    ans.append([x, 3])
    cnt += 1
    x *= 3

x = 3
while x < 1e9:
    ans.append([x, 9])
    cnt += 1
    x *= 3**2

x = 27
while x < 1e9:
    ans.append([x, 81])
    cnt += 1
    x *= 81

x = 9
while x < 1e9:
    ans.append([x, 27])
    cnt += 1
    x *= 27

x = 81
while x < 1e9:
    ans.append([x, 243])
    cnt += 1
    x *= 243

x = 729
while x < 1e9:
    ans.append([x, 2187])
    cnt += 1
    x *= 2187

x = 6561
while x < 1e9:
    ans.append([x, 19683])
    cnt += 1
    x *= 19683

x = 2187
while x < 1e9:
    ans.append([x, 6561])
    cnt += 1
    x *= 6561

print(cnt)
for a in ans:
    print(a[0], a[1])