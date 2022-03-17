n = int(input())
# brute force방법 x. 10 ** 4 자리 이상의 수는 버거움.
arr = [0] * 10
length = len(str(n))
piece = (length - 1) * (10 ** (length- 2))