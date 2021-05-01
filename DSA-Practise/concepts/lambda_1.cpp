#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    // https://www.bfilipek.com/2020/05/lambdasadvantages.html
    std::vector<int> vec;
    int n; std::cin >> n;
    vec.resize(n);
    for (auto &i: vec)
        std::cin >> i;

    // 1. more readable
    const auto val = std::count_if(
            vec.begin(), vec.end(), [](int x){return x > 3 && x < 6;});
    std::cout << val;

    // 2. saving state
    size_t cnt = 0;
    std::sort(vec.begin(), vec.end(),
            [&cnt](int a, int b){
                ++cnt;
                return a < b;
            });
    std::cout << "To sort, needed " << cnt << " comparisons.\n";

    // 3. allow multiple overloads - understand TEMPLATES first

}
