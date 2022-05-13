# 220413 해결
# 마지막 s 크기가 <= 100000일때는 실패. 시간초과인듯.
# c++로 구현해야 하나? 다른 방법이 있을까?
# --> 딕셔너리로 t 배열 자리의 알파벳마다 숫자 정해놓고, s에서 글자마다 t에 있는 인덱스를 찾아보기
# 그러다 인덱스 크기가 이전 자리의 인덱스보다 작거나 같으면 n += 1
# 딕셔너리 인덱스 찾아가는 속도가 O(1)일때 총 시간복잡도는 O(n)
s = input()
t = input()
success = 1
n = 1
alphabets_index_t = dict()
if set(s) - set(t): # t에 없는 단어가 s에 있다면 성공할 수 없음.
    success = 0

if success:
    for i, word in enumerate(t):
        if word not in alphabets_index_t:
            alphabets_index_t[word] = i
    
    index_s = 1
    while index_s < len(s):
        if alphabets_index_t[s[index_s-1]] >= alphabets_index_t[s[index_s]]:    # s[index_s-1]글자가 t에 있는 s[index_s]보다 뒤에 있다면 1번 더 돌아야함.
            n += 1
        index_s += 1
    print(n)
else:
    print(-1)