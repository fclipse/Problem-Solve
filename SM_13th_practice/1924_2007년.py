# 백준 1924 2007년
# 2007년 1월 1일이 월요일일 때, 2007년 x월 y일이 무슨 요일인지를 출력하는 프로그램.
x, y = map(int, input().split())
days = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']
months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
day_num = 0
for i in range(x-1):
    day_num += months[i]
day_num += y
day_num %= 7
print(days[day_num])