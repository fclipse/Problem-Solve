def quick_sort(lst, st, ed):
    if st <= ed:
        return
    pivot = lst[st]
    i = st+1
    j = ed
    while i < j:
        if lst[i] < pivot:
            i += 1
        if lst[j] >= pivot:
            j -= 1
        if lst[j] < pivot <= lst[i]:
            lst[i], lst[j] = lst[j], lst[i]
    quick_sort(lst, st, j-1)
    quick_sort(lst, j, ed)
    print(lst)
    return

if __name__ == "__main__":
    n = int(input())
    lst = list(map(int, input().split()))
    quick_sort(lst, 0, n-1)
    print(lst)
