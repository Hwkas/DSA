#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to get all the seives upto 10 or num which one is greater.
vector<int> sieve(int num)
{
	num = (num < 10) ? 10 : num; // setting minimun no to get prime numbers upto

	vector<bool> v(num + 1, true);
	vector<int> prime_no;

	for (int i = 2; i < num; i++)
	{
		if (v[i])
		{
			prime_no.push_back(i);
			for (int j = i * 2; j < num; j += i)
			{
				v[j] = false;
			}
		}
	}

	return prime_no;
}

// Function to print the primes no. b/w a given range.
void print_primes(long long left, long long right, vector<int> initia_primes)
{
	vector<bool> final_primes(right - left + 1, true);

	for (int i = 0; i < initia_primes.size(); i++)
	{
		int curr_prime = initia_primes[i];
		long long start = (left / curr_prime) * curr_prime;
		if (start < left)
		{
			start += curr_prime;
		}

		for (int j = start; j <= right; j += curr_prime)
		{
			final_primes[j - left] = false;
		}
		if (start == curr_prime)
		{ // i chase if the current no. is a prime no.
			final_primes[start - left] = true;
		}
	}

	for (int k = 0; k < final_primes.size(); k++)
	{
		if (final_primes[k] && (k + left > 1))
		{
			cout << k + left << " ";
		}
	}
}

int main()
{
	int t;

	cout << "Enter the no. of test cases: ";
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		long long m, n;

		cout << "Enter the value of Lower bound & Upper bound: ";
		cin >> m >> n;

		vector<int> initial_primes = sieve(sqrt(n));

		print_primes(m, n, initial_primes);
	}
	return 0;
}