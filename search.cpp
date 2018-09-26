#include <iostream>
#include <vector>
#include <string>

template<typename T>
int search(std::vector<T>& arr, T&& key)
{
    for(auto i=arr.begin(); i != arr.end(); i++)
    {
        if((*i) == key)
            return std::distance(arr.begin(), i);
    }
}

int main()
{
    std::vector<int> v1 {1, 3, 4, 5, 6};
    std::vector<std::string> v2 {"papa", "chow", "jabbarr", "iem", "gurukul"};
    std::cout << search<int>(v1, 5) << "\n";
    std::cout << search<std::string>(v2, std::string("iem")) << "\n";

}