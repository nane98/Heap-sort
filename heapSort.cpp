#include <iostream>
#include <vector>
using namespace std;

template <typename T = int>
void heap(std::vector<T>& arr, int i, int length)
{
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(right >= length)
    {
        return;
    }
    if(arr[left] > arr[right] && arr[left] > arr[i])
    {
        std::swap(arr[i], arr[left]);
        heap(arr, left, length);
    }
    else
    {
        if(arr[right] > arr[i])
        {
            std::swap(arr[i], arr[right]);
            heap(arr, right, length);
        }
    }
}

template <typename T = int>
void heapSort(std::vector<T>& arr)
{
    int length = arr.size();
    int i = (length/2) - 1;
    for(; i>=0; --i)
    {
        heap(arr, i, length-1);
    }
    for (int i = length-1; i > 0; --i) 
    {
        std::swap(arr[i], arr[0]);
        heap(arr, 0, i);
    }
}
template <typename T = int>
void print(T& arr)
{
    for(int i=0; i<arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> v = {2, 5, 6, 4, 7, 9, -4, 3, 6, 7};
    print(v);
    heapSort(v);
    print(v);
    return 2;
}