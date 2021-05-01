#include <iostream>
#include <math.h>
using namespace std;
int arrangeCoins(int n) {
    double sol1 = (-1 + sqrt(1 + 4 * 2 * n))/2;
    //double sol2 = (-1 - sqrt(1 + 4 * 2 * n))/2;
    return  sol1;

}
int main() {
    for(int i=2; i<=10; i++) {
        cout << i << " ";
        cout << arrangeCoins(i) << "\n";
    }
}
