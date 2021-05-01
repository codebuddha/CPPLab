#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> mem;
int numSquares(int n) {
    float sqt_n = sqrt(n);
    int res;
    bool flag = false;
    /* cout << "inst: " << n << "\n"; */
    if (mem[n] > 0) {
        res = mem[n];
        /* cout << "retrieving from memo: " << res << "\n"; */
        flag = true;
    }
    else if (ceil(sqt_n) == sqt_n)
        res = 1;
    /* else if (n <= 3) */
    /*     res = n; */
    else {
        res = n;
        for (int i=1; i<=n; i++) {
            int sqr = i*i;
            if (sqr > n)
                break;
            else {
                res = min(res, 1 + numSquares(n - sqr));
            }
        }
    }
    /* cout << "returning: " << res << "\n"; */
    if (!flag) mem[n] = res;
    return res;
}
int main() {
    int n;
    cin >> n;
    mem.resize(max(4,n+1));
    mem[1] = 1;
    mem[2] = 2;
    mem[3] = 3;
    cout << numSquares(n);
}
