#include <iostream>
#include <stdexcept>

class MaxHeap
{
    int arr[100];
    int index;

    /**
     * @brief Re-Organises the node to its correct position after insertion.
     *
     * This function re-organises the nodes to make the heap a valid Max Heap.
     *
     * @param index The index of the last inserted node in the array.
     */
    void organizeUp(int index)
    {
        // Iterative Solution
        while ((index > 1) && (arr[index] > arr[index / 2]))
        {
            std::swap(arr[index], arr[index / 2]);
            index = index / 2;
        }

        // Recursive Solution
        // if ((index <= 1) || (arr[index] <= arr[index / 2]))
        // {
        //     return;
        // }
        // std::swap(arr[index], arr[index / 2]);
        // organizeUp(index / 2);
    }

    /**
     * @brief Re-Organises the node to its correct position after deletion.
     *
     * This function re-organises the nodes to make the heap a valid Max Heap.
     *
     * @param i The i is set ot '1' by default when we delete the root node.
     */
    void organizeDown(int i = 1)
    {
        // Iterative Solution
        while (i <= index)
        {
            int largest = i;
            int leftIndex = i * 2;
            int rightIndex = i * 2 + 1;

            if ((leftIndex <= index) && (arr[largest] < arr[leftIndex]))
            {
                largest = leftIndex;
            }
            if ((rightIndex <= index) && (arr[largest] < arr[rightIndex]))
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

        // Recursive Solution
        // int largest = i;
        // int leftIndex = i * 2;
        // int rightIndex = i * 2 + 1;

        // if ((leftIndex <= index) && (arr[largest] < arr[leftIndex]))
        // {
        //     largest = leftIndex;
        // }
        // if ((rightIndex <= index) && (arr[largest] < arr[rightIndex]))
        // {
        //     largest = rightIndex;
        // }
        // if (largest != i)
        // {
        //     std::swap(arr[i], arr[largest]);
        //     organizeDown(largest);
        // }
    }

public:
    MaxHeap()
    {
        arr[0] = -1;
        index = 0;
    }

    void insert(int data)
    {
        arr[++index] = data;
        organizeUp(index);
    }

    void deleteNode()
    {
        if (index == 0)
        {
            throw std::out_of_range("Heap is empty.");
        }
        arr[1] = arr[index--];
        organizeDown();
    }

    void print()
    {
        std::cout << "Printing the Heap Array: ";
        for (int i = 1; i <= index; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

void heapify(int arr[], int n, int i)
{
    // Same code as that of organizeDown
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

    heapSort(arr, n);
    print(arr, n);
    return 0;
}