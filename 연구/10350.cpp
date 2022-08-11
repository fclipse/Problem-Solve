#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, k;
    short int i, j;
    scanf("%d %d", &n, &k);
    vector<short int> money(n, 0);
    for(i = 0; i < n; i++){
        scanf(" %d", &money[i]);
    }
    
    return 0;
}