#include <iostream>
#include <stack>
#include <string>

class BrowserHistory
{
private:
  std::stack<std::string> history;

public:
  void visit(const std::string &url)
  {
    history.push(url);
  }

  void back()
  {
    if (!history.empty())
    {
      history.pop();
    }
  }

  std::string current() const
  {
    if (!history.empty())
    {
      return history.top();
    }
    return "You've reached the end of your browser history.";
  }
};

int main()
{
  BrowserHistory bh;

  bh.visit("explorecalifornia.org");
  bh.visit("pixelford.com");
  bh.visit("landonhotel.com");

  std::cout << "Current Site: " << bh.current() << std::endl;

  bh.back();
  std::cout << "Current Site: " << bh.current() << std::endl;

  bh.back();
  std::cout << "Current Site: " << bh.current() << std::endl;

  bh.back();
  std::cout << "Current Site: " << bh.current() << std::endl;

  return 0;
}