#include <iostream>
#include <vector>
#include <tuple>

inline void upper_case(std::tuple<std::string,std::string> &str)
{
	int size = std::get<1>(str).size();
	for(int i=0;i<size;i++)
		std::get<0>(str).push_back(tolower(std::get<1>(str)[i]));
}

void radixsort(std::vector<std::tuple<std::string,std::string>> &list)
{
	int len = std::get<0>(list[0]).size(), n = list.size();
	std::vector<std::tuple<std::string,std::string>> temp(n);
	for(int i=len-1;i>=0;i--)
	{
		int count[26]={0};
		for(auto &j: list)
			count[std::get<0>(j)[i]-'a']++;
		for(int j=1;j<26;j++)
			count[j]+=count[j-1];
		for(int j=n-1;j>=0;j--)
		{
			temp[count[std::get<0>(list[j])[i]-'a']-1] = list[j];
			count[std::get<0>(list[j])[i]-'a']--;
		}
		for(int j=0;j<n;j++)
			list[j]=temp[j];
	}
}

int main()
{
	int n, i;
	std::cout<<"\nEnter the size of list: ";
	std::cin>>n;
	std::vector<std::tuple<std::string, std::string>> list(n);
	std::cout<<"Enter the list of strings(of same length):\n";
	for(auto &i: list)
	{
		std::cin>>std::get<1>(i);
		upper_case(i);
	}
	radixsort(list);
	std::cout<<"\nSorted list of strings:\n";
	for(auto &i: list)
		std::cout<<std::get<1>(i)<<std::endl;
}
