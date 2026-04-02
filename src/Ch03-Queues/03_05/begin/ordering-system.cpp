#include <iostream>
#include <queue>

class MerchOrderSystem
{
private:
  std::queue<int> highPriorityQueue;
  std::queue<int> orderQueue;

public:
  void place_order(int orderID, bool isPriority = false)
  {
    if(isPriority)
    {
      highPriorityQueue.push(orderID);
    }
    else
    {
      orderQueue.push(orderID);
    }
  }

  int fulfill_order()
  {
    if (!highPriorityQueue.empty())
    {
      int order_id = highPriorityQueue.front();
      highPriorityQueue.pop();
      return order_id;
    }
    else if (!orderQueue.empty())
    {
      int order_id = orderQueue.front();
      orderQueue.pop();
      return order_id;
    }
    return -1;
  }
};

int main()
{
  MerchOrderSystem system;

  system.place_order(1);
  system.place_order(2);
  system.place_order(3, true);
  system.place_order(4);

  int orderID;
  while ((orderID = system.fulfill_order()) != -1)
  {
    std::cout << "Order #" << orderID << " has been fulfilled." << std::endl;
  }

  return 0;
}