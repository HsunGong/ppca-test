cnt = 0

ans = []

x = 1
while x < 1e9:
    ans.append([x, 2])
    cnt += 1
    x *= 2


# x = 1
# while x < 1e9:
#     ans.append([x, 4])
#     cnt += 1
#     x *= 4

x = 1
while x < 1e9:
    ans.append([x, 8])
    cnt += 1
    x *= 8

# x = 2
# while x < 1e9:
#     ans.append([x, 4])
#     cnt += 1
#     x *= 4

# x = 2
# while x < 1e9:
#     ans.append([x, 8])
#     cnt += 1
#     x *= 8

# x = 2
# while x < 1e9:
#     ans.append([x, 32])
#     cnt += 1
#     x *= 32

# x = 4
# while x < 1e9:
#     ans.append([x, 16])
#     cnt += 1
#     x *= 16

x = 4
while x < 1e9:
    ans.append([x, 4])
    cnt += 1
    x *= 4

# x = 4
# while x < 1e9:
#     ans.append([x, 8])
#     cnt += 1
#     x *= 8

# x = 4
# while x < 1e9:
#     ans.append([x, 32])
#     cnt += 1
#     x *= 32

# x = 8
# while x < 1e9:
#     ans.append([x, 16])
#     cnt += 1
#     x *= 16

x = 16
while x < 1e9:
    ans.append([x, 2])
    cnt += 1
    x *= 2

x = 16
while x < 1e9:
    ans.append([x, 32])
    cnt += 1
    x *= 32

# x = 8
# while x < 1e9:
#     ans.append([x, 32])
#     cnt += 1
#     x *= 32

# x = 64
# while x < 1e9:
#     ans.append([x, 16])
#     cnt += 1
#     x *= 16

# x = 128
# while x < 1e9:
#     ans.append([x, 256])
#     cnt += 1
#     x *= 256

x = 64
while x < 1e9:
    ans.append([x, 512])
    cnt += 1
    x *= 512

# x = 16
# while x < 1e9:
#     ans.append([x, 32])
#     cnt += 1
#     x *= 32

x = 16
while x < 1e9:
    ans.append([x, 16])
    cnt += 1
    x *= 16

print(cnt)
for a in ans:
    print(a[0], a[1])