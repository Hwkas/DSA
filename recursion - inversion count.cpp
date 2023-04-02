#include <iostream>
using namespace std;

int merge(int arr[], int start, int mid, int end)
{
    int left_pointer = start;
    int right_pointer = mid + 1;
    int inversions = 0;
    if (arr[mid] <= arr[right_pointer])
    {
        return inversions;
    }

    while (left_pointer <= mid && right_pointer <= end)
    {
        if (arr[left_pointer] > arr[right_pointer])
        {
            int temp_element = arr[right_pointer];

            for (int i = right_pointer; i > left_pointer; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[left_pointer] = temp_element;
            mid++; // increasing mid, to adjust it with the elements position with the rigth shift
            right_pointer++;
            /*
            beacuse if arr[left_pointer] > arr[right_pointer],
            then all the remaingin element of left array will also be greater then arr[right_pointer]
            */
            inversions += mid - left_pointer;
        }
        left_pointer++;
    }
    return inversions;
}

int merge_sort(int arr[], int start, int end)
{
    int ans = 0;
    if (start == end)
    {
        return ans;
    }

    int mid = start + (end - start) / 2;

    // left half
    ans += merge_sort(arr, start, mid);

    // right half
    ans += merge_sort(arr, mid + 1, end);

    ans += merge(arr, start, mid, end);
    return ans;
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;
    cout << merge_sort(arr, 0, n - 1) << " " << endl;
    return 0;
}