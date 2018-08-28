#include <iostream>
void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}
int main()
{
    int a,b;
    std::cin >> a >> b;
    swap(a,b);
    std::cout << a << " " << b;
}