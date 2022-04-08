#include <stdio.h>
int main(){
    unsigned int x, y, sum = 0;
    double m;
    scanf("%u %u", &x, &y);
    m = y / (double)x;
    for(int i = 0; i < x; i ++)
        sum += (int)(m*(i+1) - (int)(m*i) + 0.5);
    printf("%d", sum);
}