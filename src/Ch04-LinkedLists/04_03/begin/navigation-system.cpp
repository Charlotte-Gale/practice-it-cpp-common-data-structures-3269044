#include <iostream>
#include <list>

class Route
{
private:
  std::list<std::string> stops;
  std::list<std::string>::iterator current;

  void wrapAroundForward()
  {
    if (current == stops.end())
    {
      current = stops.begin();
    }
  }

  void wrapAroundBackward()
  {
    if (current == stops.begin())
    {
      current = stops.end();
    }
  }

public:
  Route()
  {
    current = stops.end();
  }

  // Add a new stop to the route
  void add_stop(const std::string &stop)
  {
    bool wasEmpty = stops.empty();

    stops.push_back(stop);

    if (wasEmpty)
    {
      current = stops.begin();
    }

    wrapAroundForward();
  }

  // Advance to the next stop on the route
  void next_stop()
  {
    if (!stops.empty())
    {
      ++current;
      wrapAroundForward();
    }
  }

  // Go back to the previous stop on the route
  void prev_stop()
  {
    if (!stops.empty())
    {
      wrapAroundBackward();
      --current;
    }
  }

  // Display the current stop on the route
  void current_stop()
  {
    if (!stops.empty())
    {
      std::cout << "Current stop: " << *current << "\n";
    }
    else
    {
      std::cout << "No stops in the route\n";
    }
  }
};

int main()
{
  Route route;

  route.add_stop("London");
  route.add_stop("Brighton");
  route.add_stop("Basingstoke");
  route.add_stop("Bristol");

  route.current_stop(); 
  route.next_stop();
  route.current_stop(); 
  route.next_stop();
  route.current_stop(); 
  route.next_stop();
  route.current_stop(); 
  route.prev_stop();
  route.current_stop(); 

  return 0;
}