def selectionSort(arr,n):
    # gets the smallest element in place first
    for i in range(n-1):
        min = i
        for j in range(i+1, n):
            if arr[min] > arr[j]:
                min = j
        arr[i], arr[min] = arr[min], arr[i]


def bubbleSort(arr,n):
    # gets the largest element in place first
    for i in range(n-1):
        swap = False 
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swap = True
        if not swap:
            break


def insertionSort(arr, n):
    # Sol1 - with while loop
    for i in range(1, n):
        key = arr[i]
        j = i-1
        while((j > -1) and (arr[j] > key)):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    # Sol2 with for loop
#         for j in range(i-1, -2, -1):
#             if(arr[j] > key):
#                 arr[j+1] = arr[j]
#             else:
#                 break
#         arr[j+1] = key