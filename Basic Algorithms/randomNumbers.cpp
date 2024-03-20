#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    srand((unsigned)time(NULL));
    int count, rangeSt, rangeEd, length;
    printf("Type - count, rangeSt, rangeEd (int)\n: ");
    scanf("%d %d %d", &count, &rangeSt, &rangeEd);

    if(rangeSt > rangeEd){  // swap
        length = rangeEd;
        rangeEd = rangeSt;
        rangeSt = length;
    }
    while(rangeSt == rangeEd){
        printf("Error - rangeSt should be different from rangeEd\n");
        scanf("%d %d %d", &count, &rangeSt, &rangeEd);
    }
    // 시작과 끝나는 두 수를 포함
    length = rangeEd - rangeSt + 1;
    for(int i = 0; i < count; i++)
        printf("%d ", (rand() % length) + rangeSt);
    
    return 0;
}