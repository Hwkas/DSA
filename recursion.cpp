#include <iostream>
using namespace std;

// inline recursive function
inline int factorial(int n){
    return n==0? 1 : n * factorial(n-1);
}

// normal recursive function
// int factorial(int n){
//     if(n==0){
//         return 1;
//     }
//     return n * factorial(n-1);
// }


int main(){

    cout<<"Enter the number to find it's factorial: ";
    int n;
    cin>>n;
    
    cout<<"The factorial of n is: "<<factorial(n)<<endl;

}
