#include <iostream>
using namespace std;

int *quickSort(int *arr, int st, int ed);
void swap(int*, int*);
int main(){
    ios::sync_with_stdio(false);
    int n, i;
    scanf("%d", &n);
    int* arr = new int[n]{};
    for(i = 0; i < n; i++)
        scanf(" %d", &arr[i]);
    
    quickSort(arr, 0, n-1);

    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    delete[] arr;
    return 0;
}

int *quickSort(int *arr, int st, int ed){
    if(st >= ed)
        return arr;
    int i, j, pivot;
    pivot = arr[st];
    i = st + 1, j = ed;

    while(i < j){
        if(arr[i] < pivot)
            i++;
        if(arr[j] >= pivot)
            j--;
        if(arr[i] >= pivot && arr[j] < pivot){
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[st], &arr[j]);
    quickSort(arr, st, j-1);
    quickSort(arr, j, ed);
    return arr;
}

void swap(int *n, int* m){
    int tmp = *n;
    *n = *m;
    *m = tmp;
    return;
}