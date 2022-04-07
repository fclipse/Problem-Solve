import sys
s = sys.stdin.readline().strip('\n')
lst_s = list(map(str, s))

index = 0
start = 0
word = []
while index < len(s):
    if lst_s[index] == '<':
        while lst_s[index] != '>':
            index += 1
    elif lst_s[index] != ' ':
        start = index
        while lst_s[index] != ' ' and lst_s[index] != '<':  # 처음에 여기서 or 씀. 조건을 확실히 생각 후 여사건을 배제할건지, 아니면 그냥 조건인지를 꼭 생각!
            word.append(s[index])
            index += 1
            if index == len(s):
                break
        lst_s[start:index] = word[::-1]
        start = 0
        word = []
        if index < len(s) and lst_s[index] == '<':  # index error일어남. while문 두개 겹쳐있어서 증감을 두 군데서 해주다 보니까 헷갈린듯.
            index -= 1
    index += 1
print(''.join(lst_s))