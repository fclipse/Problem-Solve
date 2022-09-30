// Baekjoon No.
// Time Complexity
// #

#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, min_height, index, start, end;
    long long int max_size, tmp_size;
    int i;
    cin >> n;
    while (n > 0) {
        vector<int> heights(n);
        for (i = 0; i < n; i++)
            cin >> heights[i];

        // solving
        max_size = heights[0];
        for (index = 1; index < n; index++) {
            if (max_size < heights[index])
                max_size = heights[index];
            end = index;

            min_height = heights[index];
            while (min_height * (static_cast<long long>(index) + 1) > max_size) {
                while (index > 0 && heights[index - 1] >= heights[index])   // 크거나 같으면 계속 go
                    index--;
                if (index < end)    // 정산
                    tmp_size = heights[index] * (static_cast<long long>(end) - index + 1);

                if (index > 0 && heights[index - 1] < heights[index])
                    min_height = heights[index - 1];
                
            }
            

        }

        // output
        cout << max_size;

        cin >> n;
    }
    return 0;
}