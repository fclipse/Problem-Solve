#include <iostream>
using namespace std;

int* quickSort(int* arr, int size);
int main(){
    ios::sync_with_stdio(false);
    int n, k, i;
    scanf("%d %d", &n, &k);
    int* arr = new int[n];
    for(i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    quickSort(arr, n);
    printf("%d", arr[n-k]);

    delete[] arr;
    return 0;
}

int* quickSort(int *arr, int size){
    int l = 0, r = 0, m = 0, pivot;
    int i;
    if(size <= 1)
        return arr;
    pivot = arr[size/2];
    // 개수 먼제 셈 -> 메모리 동적할당
    for(i = 0; i < size; i++){
        if(arr[i] > pivot){
            r++;
        }else if(arr[i] < pivot){
            l++;
        }else{
            m++;
        }
    }
    int* left = new int[l]{};
    int* right = new int[r]{};
    int* mid = new int[m]{};
    // pivot 기준으로 정리
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