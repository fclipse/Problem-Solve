#include <iostream>
#include <vector>
using namespace std;

void print_arr(vector<int> arr, int n);
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    int n, i, j, max_sum = -1000, tmp, index, length;
    cin >> n;
    vector<int>arr(n);
    index = 0;
    // 입력
    cin >> arr[0];
    if(arr[0] > max_sum) max_sum = arr[0];
    for(i = 1; i < n; i++){
        cin >> tmp;
        if(tmp > max_sum)   max_sum = tmp;
        if(arr[index] * tmp >= 0){  // >0이면 부호 같을 때, ==0이면 둘 중 하나가 0일때 -> 더해도 상관없음.
            arr[index] += tmp;

        }
        else if(arr[index] * tmp < 0){
            arr[++index] = tmp;
        }
    }
    length = index + 1; // 압축된 배열 길이 저장
    print_arr(arr, n);
    cout << "\nmax_sum : " << max_sum;

    
    // DP
    // tmp = arr[0];
    // for(i = 1; i < n; i++){
    //     if(arr[i] >= 0){
    //         tmp += arr[i];
    //     }else{
    //         if(max_sum < tmp)
    //             max_sum = tmp;
    //         tmp = 0;
    //     }
            
    // }
    // if(max_sum < tmp)
    //     max_sum = tmp;
    // cout << max_sum;
    return 0;
}
void print_arr(vector<int> arr, int n){
    cout <<"\n배열 출력\n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout <<"\n";
    return;
}