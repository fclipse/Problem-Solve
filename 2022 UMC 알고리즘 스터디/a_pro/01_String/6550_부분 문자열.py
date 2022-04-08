# 문자열을 진행하면서 찾는 문자열의 첫 글자가 그 문자와 같으면 찾는 문자열을 하나씩 지움
# EOF 에러를 해결해야 했음.
# try, except 구문을 이용해서 가능함.
import sys
from collections import deque
try:
    while 1:
        s, t = sys.stdin.readline().split()
        lst_s = ''.join(s)
        lst_t = ''.join(t)
        lst_s = deque(lst_s)
        
        for i in lst_t:
            if i == lst_s[0]:
                lst_s.popleft()
                if len(lst_s) == 0:
                    break
        if lst_s == deque():
            print('Yes')
        else:
            print('No')
except:
    exit()