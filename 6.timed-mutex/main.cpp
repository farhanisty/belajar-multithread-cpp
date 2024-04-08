#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

int myAmount = 0;
std::timed_mutex m;

// =============== using try_lock_for ==================
// void increment(int i) {
//   if(m.try_lock_for(chrono::seconds(1))) {
//     ++myAmount;
//     this_thread::sleep_for(chrono::seconds(3));
//     cout << "Thread " << i << " entered" << endl;
//     m.unlock();
//   } else {
//     cout << "Thread " << i << " couldn't enter" << endl;
//   }
// }

// =============== using try_lock_until =================
void increment(int i) 
{
  auto now = chrono::steady_clock::now();
  if(m.try_lock_until(now + chrono::seconds(1000))) {
    ++myAmount;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Thread " << i << " entered" << endl;
    m.unlock();
  } else {
    cout << "Thread " << i << " couldn't enter" << endl;
  }
}

int main()
{
  thread t1(increment, 1);
  thread t2(increment, 2);

  t1.join();
  t2.join();

  cout << "amount " << myAmount << endl;

  return 0;
}
