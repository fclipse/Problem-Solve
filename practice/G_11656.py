s = input()
lst = [s[-1]]
length = len(s)
for i in range(length - 1):
    lst.append(s[length - i - 2] + lst[i])

lst.sort()
for i in lst:
    print(i)