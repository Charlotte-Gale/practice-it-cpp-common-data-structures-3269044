#include <iostream>
#include <queue>

class CallCenter
{
private:
  std::queue<int> callQueue;
  
public:
  void receive_call(const int id)
  {
    callQueue.push(id);
  }

  int process_call()
  {
    if (!callQueue.empty())
    {
      int call_id = callQueue.front();
      callQueue.pop();
      return call_id;
    }
    return -1;
  }
};

int main()
{
  CallCenter center;

  center.receive_call(1);
  center.receive_call(2);
  center.receive_call(3);

  int call_id;
  while((call_id = center.process_call()) != -1)
  {
    std::cout << "Successfully processed call " << call_id << "." << std::endl;
  }

  return 0;
}