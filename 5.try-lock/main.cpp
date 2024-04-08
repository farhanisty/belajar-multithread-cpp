#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

int x = 0, y = 0;
mutex m1, m2;

void sleepFor(int seconds) {
  this_thread::sleep_for(chrono::seconds(seconds));
}

void incrementCount(int &var, mutex& m, const char* desc)
{
  for(int i = 0; i < 5; i++) {
    m.lock();
    ++var;
    
    cout << desc << var << "\n";
    
    m.unlock();
    sleepFor(3);
  }
}

void consume() {
  int useCount = 5;
  int result = 0;
  
  while(true) {
    int lockResult = try_lock(m1, m2);
    if(lockResult == -1) {
      if(x != 0 && y != 0) {
        --useCount;
        result = x + y;
        x = 0;
        y = 0;

        cout << "result = " << result << "\n";
      }

      m1.unlock();
      m2.unlock();

      if(useCount == 0) break;
    }
  }
}

int main()
{
  thread t1(incrementCount, std::ref(x), std::ref(m1), "T");
  thread t2(incrementCount, std::ref(y), std::ref(m2), "Y");
  thread t3(consume);
  
  t1.join();
  t2.join();
  t3.join();
  
  return 0;
}
