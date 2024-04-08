#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

mutex m;
int buffer = 0;

// =========== Without Lock Guard ============ //

// void task(const char* threadNumber, int loopFor)
// {
//   m.lock();
//   
//   for(int i = 0; i< loopFor; i++) {
//     buffer++;
//     cout << threadNumber << " " << buffer << endl;
//   }
//
//   m.unlock(); // must to unlock explicitly
// }

// ================= With Lock Guard ================== //

void task(const char* threadNumber, int loopFor)
{
  lock_guard<mutex> lock(m);
  for(int i = 0; i< loopFor; i++) {
    buffer++;
    cout << threadNumber << " " << buffer << endl;
  }
}

int main()
{
  thread t1(task, "T1", 10);
  thread t2(task, "T2", 10);

  t1.join();
  t2.join();

  return 0;
}
