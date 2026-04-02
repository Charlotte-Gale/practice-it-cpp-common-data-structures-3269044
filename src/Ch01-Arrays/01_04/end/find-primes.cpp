#include <iostream>
#include <vector>

bool isPrime(int num)
{
    if (num < 2) return false;

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0) return false;
    }

    return true;
}

void findPrimes(const int arr[], size_t size, std::vector<int> &primes)
{
    for (size_t i = 0; i < size; i++) 
    {
        if (isPrime(arr[i]))
        {
            primes.push_back(arr[i]);
        }
    }
}

int main()
{
    int numbers[] {4, 7, 12, 3, 9, 17, 29};
    
    size_t size = sizeof(numbers) / sizeof(numbers[0]);
    std::vector<int> primes;

    findPrimes(numbers, size, primes);

    if (primes.empty())
    {
        std::cout << "No prime numbers found in the array.";
    }
    else
    {
        std::cout << "The prime numbers in the array are:";
        for (int prime : primes)
        {
            std::cout << " " << prime;
        }
        std::cout << std::endl;
    }
    return 0;
}
