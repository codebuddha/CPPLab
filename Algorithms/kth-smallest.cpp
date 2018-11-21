#include <iostream>
#include <vector>

inline void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void heapify(std::vector<int> &heap, int pos)
{
	int large=heap[pos], i = pos;
	int left = (2*pos)+1;
	int right = (2*pos)+2;
	if(left<heap.size())
		if(large<heap[left])
		{
			large = heap[left];
			i = left;
		}
	if(right<heap.size())
		if(large<heap[right])
		{
			large = heap[right];
			i = right;
		}
	if(pos!=i)
	{
		swap(heap[pos], heap[i]);
		heapify(heap, i);
	}
}

int kth_small(std::vector<int> &vect, int k)
{
	int n = vect.size();
	std::vector<int> kheap(vect.begin(), vect.begin()+(k+1));
	for(int i=(k-1)/2;i>=0;i--)
		heapify(kheap, i);
	for(int i=k+1;i<n;i++)
		if(kheap[0]>vect[i])
		{
			swap(kheap[0], vect[i]);
			heapify(kheap, 0);
		}
	return kheap[0];
}

int main()
{
	int n, k;
	std::cout<<"Enter the size of array: ";
	std::cin>>n;
	std::vector<int> arr(n);
	std::cout<<"Enter the array: ";
	for(auto &i: arr)
		std::cin>>i;
	std::cout<<"Enter the value of k(0<k<n): ";
	std::cin>>k;
	std::cout<<"The kth smallest element is "<<kth_small(arr, k-1)<<std::endl;
}
