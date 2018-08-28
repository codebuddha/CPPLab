#include <iostream>
using namespace std;
class Rectangle
{
    public:
    float l, w;
    void setlength(float x){l = x;}
    void setwidth(float x){w = x;}
    float perimeter(){return 2*(l+w);}
    float area(){return l*w;}
    int sameArea(Rectangle &x)
    {
        return x.area() == area();
    }
};
int main()
{
    Rectangle a, b;
    a.setlength(6); a.setwidth(3.5);
    b.setlength(3); b.setwidth(10.5);
    cout << "Rectangle 1: " << "length = " << a.l << " width = " << a.w << endl;
    cout << "Rectangle 2: " << "length = " << b.l << " width = " << b.w << endl;
    cout << "Rectangles have " << (a.sameArea(b)? "same" : "different") << " areas\n";
    return 0;
}