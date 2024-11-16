#include <bits/stdc++.h>
// #define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// using namespace std;

// int kth(std::vector<int> &a, int k);

// int main() {
// 	fastio;
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     // solving
    

// 	return 0;
// }

int kth(std::vector<int> &a, int k){
    for (int i = 0; i < a.size(); i++){
    }
    
    sort(a.begin(), a.end());
    return a[k - 1];
}