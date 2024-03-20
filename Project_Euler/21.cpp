// Project.Euler No. 21 / solved at 220730
// Time Complexity O(n^1.5)
#include <iostream>
#include <cmath>
using namespace std;
int d(int n);

int main(){
    int np = 0, sum = 0, end;
    cin >> end;                         // end 까지의 우애수 합을 구함.
    for(int i = 1; i <= end; i++){
        np = d(i);                      // d(a) == b
        if(d(np) == i && np != i){      // d(b) == a 이고 a != b일때
            sum += i + np;              // 쌍의 합을 더해줌.
            printf("%d %d\n", i, np);   // 각 쌍의 정보 출력
        }
    }
    sum /= 2;   // 쌍의 합을 더하므로 작은 수와 큰 수 두 번씩 더해짐.
    cout << sum << endl;
    return 0;
}

// n을 제외한 모든 수의 약수의 합을 반환하는 함수
int d(int n){
    int sum = 0;
    if(n > 1) sum ++;   // d(1) = 0 이므로, 나머지 수는 1씩 더해줘야함.
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            sum += i;
            sum += n / i;
        }
    }
    return sum;
}