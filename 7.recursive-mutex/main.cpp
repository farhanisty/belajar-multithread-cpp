#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

int buffer = 0;
std::recursive_mutex m;

void recursion(char c, int loopFor)
{
  if(loopFor == 0) {
    return;
  }

  m.lock();
  
  cout << c << " " << buffer++ << endl;
  recursion(c, --loopFor);

  m.unlock();
}

int main()
{
  thread t1(recursion, 'Y', 5);
  thread t2(recursion, 'T', 10);

  t1.join();
  t2.join();

  return 0;
}
