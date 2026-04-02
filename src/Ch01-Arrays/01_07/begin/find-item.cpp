#include <iostream>
#include <string>

template <typename T>
int findItem(const T arr[], size_t size, T target)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == target) return i;
    }

    return -1;
}

int main()
{
    int intNumbers[]{4, 7, 12, 3, 9, 17, 29};
    size_t intSize = sizeof(intNumbers) / sizeof(intNumbers[0]);
    int targetInt = 17;
    size_t intIndex = findItem(intNumbers, intSize, targetInt);

    std::string strArray[] = {"apple", "banana", "cherry", "orange"};
    size_t strSize = sizeof(strArray) / sizeof(strArray[0]);
    std::string targetStr = "kiwi";
    size_t strIndex = findItem(strArray, strSize, targetStr);

    if (intIndex != -1)
    {
        std::cout << "The target integer " << targetInt << " is found at index " << intIndex << "." << std::endl;
    }
    else
    {
        std::cout << "The target integer " << targetInt << " is not found in the array." << std::endl;
    }

    if (strIndex != -1)
    {
        std::cout << "The target string \"" << targetStr << "\" is found at index " << strIndex << "." << std::endl;
    }
    else
    {
        std::cout << "The target string \"" << targetStr << "\" is not found in the array." << std::endl;
    }

    return 0;
}
