// Baekjoon No. 1259 - solved 220815
// Time Complexity O(n)
#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    string word;
    int res, i, length;
    while(1){
        res = 1;
        cin >> word;
        length = word.length();
        for(i = 0; i < length / 2; i++){
            if(word.at(i) != word.at(length - i - 1))
                res = 0;
        }
        if(!word.compare("0"))
            break;
        if(res)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    
    return 0;
}