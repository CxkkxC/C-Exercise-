#include <iostream>
using namespace std;
int a[10001];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int temp = i;
        int num = i;
        while(num) {
            temp += num%10;
            num = num/10;
        }
        a[temp] = 1;
    }
    for(int j = 1; j <= n; j++) {
        if(a[j] == 0)
            cout << j << endl;
    }
    return 0;
}
