#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // solving
    vector<int> cache(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            cache[i] = max(cache[i], cache[i - j - 1] + arr[j]);
        }
    }

    // output
    cout << cache[n];

	return 0;
}