#include <iostream>
#include <queue>

void heapify(int arr[], int n, int i)
{
    // Iterative
    while (i < n)
    {
        int largest = i;
        int leftIndex = i * 2;
        int rightIndex = i * 2 + 1;

        if ((leftIndex < n) && (arr[largest] < arr[leftIndex]))
        {
            largest = leftIndex;
        }
        if ((rightIndex < n) && (arr[largest] < arr[rightIndex]))
        {
            largest = rightIndex;
        }
        if (largest != i)
        {
            std::swap(arr[i], arr[largest]);
            i = largest;
        }
        else
        {
            return;
        }
    }

    // Recursive
    // int largest = i;
    // int leftIndex = i * 2;
    // int rightIndex = i * 2 + 1;

    // if ((leftIndex < n) && (arr[largest] < arr[leftIndex]))
    // {
    //     largest = leftIndex;
    // }
    // if ((rightIndex < n) && (arr[largest] < arr[rightIndex]))
    // {
    //     largest = rightIndex;
    // }
    // if (largest != i)
    // {
    //     std::swap(arr[i], arr[largest]);
    //     heapify(arr, n, largest);
    // }
}

void heapSort(int arr[], int n)
{
    while (n > 1)
    {
        std::swap(arr[1], arr[n - 1]);
        n--;
        heapify(arr, n, 1);
    }
}

void print(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {-1, 70, 60, 55, 45, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k;
    std::cout << "Enter the value of k to find the Kth smallest element: " << std::endl;
    std::cin >> k;

    if (k > n - 1)
    {
        throw std::out_of_range("The value of k is greater then the size of Array.");
    }

    // Solution 1
    // heapSort(arr, n);
    // std::cout << "Kth smallest element is: " << arr[k] << std::endl;

    // Solution 2
    std::priority_queue<int> max_heap;

    int i = 1;
    for (; i <= k; i++)
    {
        max_heap.push(arr[i]);
    }

    for (; i < n; i++)
    {
        if (max_heap.top() > arr[i])
        {
            max_heap.pop();
            max_heap.push(arr[i]);
        }
    }
    std::cout << "Kth smallest element is: " << max_heap.top() << std::endl;

    return 0;
}