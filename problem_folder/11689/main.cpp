#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000000000001
// #define SIZE 100
using namespace std;

// globals
// bool available[SIZE] = {true};
vector<bool> available(SIZE, 0);

// functions
bool isPrime(long long n);

int main() {
	fastio;
    long long n;
    cin >> n;
    // solving
    long long ans = n;
    // vector<int> dividers;
    for (int i = 2; i * i <= n; i++){
        if(n % i == 0){
            if(isPrime(i)){
                // -2 => n은 마지막에 한 번만 빼줘야하고, i 자체도 카운트 해줘야 하기 때문.
                ans -= n / i - 2;
            }
            
            if(isPrime(n / i)){
                ans -= i - 2;
            }
        }
    }
    ans--;

    // output
    cout << ans;
	return 0;
}

bool isPrime(long long n){
    if(available[n]){
        if(2 * n < SIZE && available[2 * n]){
            for (long long i = 2 * n; i < SIZE; i += n){
                available[i] = false;
            }
        }
        return true;
    }else{
        return false;
    }
}