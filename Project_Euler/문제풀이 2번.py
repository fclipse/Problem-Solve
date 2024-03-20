import sys
money_lst = []
for i in range(56):
    money = sys.stdin.readline().strip('원\n')
    money = ''.join(x for x in money if x != ',')
    money_lst.append(int(money))  

for i in range(56):
    