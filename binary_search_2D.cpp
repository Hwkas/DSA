#include <iostream>
using namespace std;

// // Sol 1 - explained in brief
// int main(){

//     int matrix[3][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

//     int target = 0;

//     int m = 3;    // no. of rows
//     int n = 4;   // no. of columns

//     int start = 0;
//     int end = m*n-1;

//     int mid = start + (end-start)/2;
//     int row = mid/n; //getting row index
//     int col = mid%n; //getting col index

//     while(start<=end){
//         if(matrix[row][col]==target){
//             cout<<"Foud"<<endl;
//             return 0;
//         }
//         else if(matrix[row][col] > target){
//             end = mid - 1;
//         }
//         else{
//             start = mid + 1;
//         }
//         mid = start + (end-start)/2;
//         row = mid/n; //getting row index
//         col = mid%n; //getting col index
//     }
//     cout<<"Not Found"<<endl;
//     return 0;

// }


// Sol 2
int main(){

    int matrix[3][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    int target = -1;

    int row = 3;    // no. of rows
    int col = 4;   // no. of columns

    int start = 0;
    int end = row*col-1;

    int mid = start + (end-start)/2;

    while(start<=end){
        if(matrix[mid/col][mid%col]==target){ 
            cout<<"Foud"<<endl;
            return 0;
        }
        else if(matrix[mid/col][mid%col] > target){
            end = mid - 1; 
        }
        else{
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    cout<<"Not Found"<<endl;
    return 0;

}