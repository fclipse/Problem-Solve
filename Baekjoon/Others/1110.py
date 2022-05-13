a = int(input())
new = 100
cnt = 0
sum = 0

while a != new :
    cnt += 1
    if cnt == 1:
        new = a
    sum = new // 10 + new % 10
    new = (new % 10) * 10 + sum % 10

print(cnt)