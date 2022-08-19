// 220812
// 포인터와 동적할당 사용해서 구현한 quicksort
// Time Complexity O(nlogn)
// Space Complexity O(n**2)?
#include <iostream>
using namespace std;

int* quickSort(int* arr, int size);
int main(){
    ios::sync_with_stdio(false);
    int n, i;
    scanf("%d", &n);
    int* arr = new int[n];
    for(i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    quickSort(arr, n);
    printf("arr : \n");
    for(i = 0; i < n; i++)
        printf("%2d ", arr[i]);
    
    delete[] arr;
    return 0;
}

int* quickSort(int *arr, int size){
    int l, r, m, pivot;
    int i;
    if(size <= 1)
        return arr;
    pivot = arr[size/2];
    int* left = new int[size]{};
    int* right = new int[size]{};
    int* mid = new int[size]{};

    l = 0; r = 0; m = 0;
    for(i = 0; i < size; i++){
        if(arr[i] > pivot){
            right[r] = arr[i];
            r++;
        }else if(arr[i] < pivot){
            left[l] = arr[i];
            l++;
        }else{
            mid[m] = arr[i];
            m++;
        }
    }

    int* larr = quickSort(left, l);
    int* rarr = quickSort(right, r);
    int* marr = quickSort(mid, m);
    
    for(i = 0; i < l; i++)
        arr[i] = larr[i];
    for(i = 0; i < m; i++)
        arr[i+l] = marr[i];
    for(i = 0; i < r; i++)
        arr[i+l+m] = rarr[i];

    delete[] left;
    delete[] right;
    delete[] mid;

    return arr;
}