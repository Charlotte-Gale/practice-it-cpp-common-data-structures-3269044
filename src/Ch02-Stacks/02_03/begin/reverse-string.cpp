#include <iostream>
#include <stack>
#include <string>

std::string reverseString(const std::string &input)
{
  std::stack<char> charStack;

  for (char c : input) 
  {
    charStack.push(c);
  }

  std::string reversedString;

  while (!charStack.empty())
  {
    reversedString += charStack.top();
    charStack.pop();
  }

  return reversedString;
}

int main()
{
  std::string str = "Hello, World!";
  std::string revStr = reverseString(str);

  std::cout << reverseString("Hello, World!") << std::endl;

  std::cout << "Original String: " << str << std::endl;
  std::cout << "Reversed String: " << revStr << std::endl;

  return 0;
}