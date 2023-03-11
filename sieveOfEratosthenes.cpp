#include <iostream>
#include <vector>
using namespace std;

// Sieve of Eratosthenes Algorith
int main(){

    cout<<"Enter the range upto which to want to get the cout of prime numbers: ";
    int n = 0;
    cin>>n;
    int count = 0;
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for(int i=2; i<n; i++){
        if(prime[i]){
            count++;
            for(int j=i*2; j<n; j=j+i){
                prime[j] = false;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
