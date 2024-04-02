#include <iostream>
#include <stdexcept>

class MinHeap
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
        while ((index > 1) && (arr[index] < arr[index / 2]))
        {
            std::swap(arr[index], arr[index / 2]);
            index = index / 2;
        }

        // Recursive Solution
        // if ((index <= 1) || (arr[index] >= arr[index / 2]))
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
            int smallest = i;
            int leftIndex = i * 2;
            int rightIndex = i * 2 + 1;

            if ((leftIndex <= index) && (arr[smallest] > arr[leftIndex]))
            {
                smallest = leftIndex;
            }
            if ((rightIndex <= index) && (arr[smallest] > arr[rightIndex]))
            {
                smallest = rightIndex;
            }
            if (smallest != i)
            {
                std::swap(arr[i], arr[smallest]);
                i = smallest;
            }
            else
            {
                return;
            }
        }

        // Recursive Solution
        // int smallest = i;
        // int leftIndex = i * 2;
        // int rightIndex = i * 2 + 1;

        // if ((leftIndex <= index) && (arr[smallest] > arr[leftIndex]))
        // {
        //     smallest = leftIndex;
        // }
        // if ((rightIndex <= index) && (arr[smallest] > arr[rightIndex]))
        // {
        //     smallest = rightIndex;
        // }
        // if (smallest != i)
        // {
        //     std::swap(arr[i], arr[smallest]);
        //     organizeDown(smallest);
        // }
    }

public:
    MinHeap()
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
        int smallest = i;
        int leftIndex = i * 2;
        int rightIndex = i * 2 + 1;

        if ((leftIndex < n) && (arr[smallest] > arr[leftIndex]))
        {
            smallest = leftIndex;
        }
        if ((rightIndex < n) && (arr[smallest] > arr[rightIndex]))
        {
            smallest = rightIndex;
        }
        if (smallest != i)
        {
            std::swap(arr[i], arr[smallest]);
            i = smallest;
        }
        else
        {
            return;
        }
    }

    // Recursive
    // int smallest = i;
    // int leftIndex = i * 2;
    // int rightIndex = i * 2 + 1;

    // if ((leftIndex < n) && (arr[smallest] > arr[leftIndex]))
    // {
    //     smallest = leftIndex;
    // }
    // if ((rightIndex < n) && (arr[smallest] > arr[rightIndex]))
    // {
    //     smallest = rightIndex;
    // }

    // if (smallest != i)
    // {
    //     std::swap(arr[i], arr[smallest]);
    //     heapify(arr, n, smallest);
    // }
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
    MinHeap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteNode();

    h.print();

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = (n - 1) / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    print(arr, n);
    return 0;
}