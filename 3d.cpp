#include <iostream>
#include <vector>
#include <tuple>

template<typename T>
std::tuple<T, T, T> operator+(std::tuple<T, T, T>& a, std::tuple<T, T, T>& b)
{
    std::tuple<T, T, T> c;
    std::get<0>(c) = std::get<0>(a) + std::get<0>(b);
    std::get<1>(c) = std::get<1>(a) + std::get<1>(b);
    std::get<2>(c) = std::get<2>(a) + std::get<2>(b);
    return c;
}
int main()
{
    std::cout << "first: ";
    std::tuple<float, float, float> a, b, c;
    std::cin >> std::get<0>(a) >> std::get<1>(a) >> std::get<2>(a);
    std::cin >> std::get<0>(b) >> std::get<1>(b) >> std::get<2>(b);
    c = a + b;
    std::cout << std::get<0>(c) << " " << std::get<1>(c) << " " << std::get<2>(c);
}