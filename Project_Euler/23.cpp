// Project Euler No. 23
// (28123 이하의) 두 과잉수의 합으로 나타낼 수 없는 모든 양의 정수의 합은?
// Time Complexity O(n^2)
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

#define MAX 30000
using namespace std;
int complete(int);

int main(){
    int overNum[MAX] = {0};     // 과잉수 저장하는 배열
    int integers[MAX] = {0};    // 과잉수로 만들 수 있는 정수들 저장하는 배열
    int index = 0, sum = 0, cnt = 0; // index -> 30000 미만의 과잉수 개수, sum -> 두 과잉수로 나타낼 수 없는 정수의 합 저장
    // 파일 입출력 설정
    // ofstream ofs("./completeNumbers.txt");
    // if(ofs.fail()){
    //     cout << "File Opening Failed\n";
    //     return -1;
    // }
    // ofs << "Hello, World!\n";
    // ofs << 1234 << endl;
    // ofs << 'a' << endl;
    
    // 과잉수 배열 초기화, 30000 미만의 과잉수 모두 저장
    for(int i = 1; i < MAX; i++)
        if(complete(i) > i)
            overNum[index++] = i;
    // 과잉수 배열 출력
    // for(int i = 0; i < index; i++){
    //     //     printf("%d ", overNum[i]);
    //     ofs << overNum[i] << " ";
    //     if(i % 20 == 0 && i > 0)
    //         ofs << endl;
    // }
    
    // 과잉수 두개로 나타낼 수 있는 모든 정수 구함. -> integers에 저장.
    for(int i = 0; i < index; i++){
        for(int j = i; j < index; j++){
            if(overNum[j] + overNum[i] < MAX && !integers[overNum[j] + overNum[i]])
                integers[overNum[j] + overNum[i]] = 1;
        }
    }

    // 과잉수 두개로 구할 수 없는 정수 합 구함.
    for(int i = 0; i < MAX; i++){
        if(!integers[i]){
            printf("%d ", i);
            sum += i;
            cnt ++;
        }
    }
    cout << endl << "과잉수 개수 : " << index << endl;
    cout << "과잉수 2개로 만들 수 없는 수 개수 : " << cnt << endl;
    cout << sum;
    cout << endl;
    return 0;
}
// 자기를 제외한 모든 약수의 합을 반환하는 함수
int complete(int n){
    int sum = -n;
    for(int i = 1; i <= sqrt(n); i++)
        if(n % i == 0 && i != n / i)    // n이 완전제곱수일때는 i 두번 더해짐.
            sum += i + n / i;
    return sum;
}