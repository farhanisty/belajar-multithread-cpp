#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

mutex m;
int buffer = 0;

void task(const char* threadNumber, int loopFor)
{
  // unique_lock<mutex> lock(m);
  
  unique_lock<mutex> lock(m, defer_lock);
  lock.lock(); // manualy lock mutex if using defer_lock strategy

  for(int i = 0; i < loopFor; i++) {
    buffer++;
    cout << "thread " << threadNumber << " " << buffer << endl;
  }
}

int main()
{
  thread t1(task, "T1", 10);
  thread t2(task, "T2", 20);

  t1.join();
  t2.join();
  
  return 0;
}
