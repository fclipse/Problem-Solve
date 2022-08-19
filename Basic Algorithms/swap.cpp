#include <iostream>
using namespace std;

void swap(int *n, int *m){
    int tmp = *n;
    *n = *m;
    *m = tmp;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    int a, b;
    scanf("%d %d", &a, &b);

    printf("pre swap\n");
    printf("%d %d\n", a, b);
    
    swap(&a, &b);
    
    printf("post swap\n");
    printf("%d %d\n", a, b);
    return 0;
}