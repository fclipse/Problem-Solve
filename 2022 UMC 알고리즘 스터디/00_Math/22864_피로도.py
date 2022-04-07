# 좀 까다로웠음
# 한 시간 일할때 a만큼 피로도가 차고 b만큼 일을 함.
# 한 시간 쉴 때 c만큼 피로도가 감소함. 피로도는 음수가 될 수 없음
# 이렇게 해서 24시간동안 최대로 일할 수 있는 양은?
# 그리디 식으로 해서 m > tired일때 일하고 쉬다 최대피로도 - 피로도 >= a일때 다시 일하고 하는 방식.
# a > m인 케이스 --> 일을 시작도 못함.
 
a, b, c, m = map(int, input().split())
tired = 0
hour = 0
work = 0

while hour < 24:
    # 일
    if a > m:   # 이거 추가하니 되었음
        break
    p_hour = hour     
    while a + tired <= m and hour < 24:
        tired += a
        work += b
        hour += 1
        #print('work', tired, work, hour)
    # 휴식
    while hour < 24 and m < tired + a:  # c <= tired 제외.
        tired -= c
        if tired < 0:
            tired = 0
        hour += 1
        #print('rest', tired, work, hour)
    if p_hour == hour: #아무것도 진행할 수 없는 상황
        break
print(work)