#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int count = 0;
mutex m;

void increaseCount()
{
  for(int i = 0;i < 100000;i++) {
    if(m.try_lock()) {
      ++count;
      m.unlock();
    }
  }
}

int main()
{
  thread t1(increaseCount);
  thread t2(increaseCount);

  t1.join();
  t2.join();
  
  cout << count;
}
