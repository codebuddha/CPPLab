#include <iostream>
double imp2si(double a, double b)
{
    return a*30.48 + b*2.54;
}
int main()
{
    double a, b;
    std:: cin >> a >> b;
    // b += a*12;
    double c = imp2si(a,b);
    std:: cout << c << " cm."<< std::endl;
}