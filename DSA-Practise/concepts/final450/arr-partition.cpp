#include <iostream>
/* #include <algorithm> */
using namespace std;

void debug_arr(int arr[], int n){
    for (int i=0; i< n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void rearr(int arr[], int n){
    int pos = 0, neg = n -1;
    while(pos < neg) {
        while(arr[pos] < 0) pos++;
        while(arr[neg] > 0) neg--;
        if (pos < neg) {
            swap(arr[pos++], arr[neg--]);
        }
        cout << pos << " " << neg << " ";
        debug_arr(arr, n);

    }
}

int main(){
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(int);
    rearr(arr, n);
}
