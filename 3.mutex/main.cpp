#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int amount = 0;
mutex m;

void addMoney()
{
  m.lock();
  cout << "saldoku sekarang = " << amount;

  this_thread::sleep_for(chrono::seconds(3));
  
  amount += 10000;
  
  cout << "\nberhasil menambah saldo sebesar 10000\n";
  m.unlock();
}

int main()
{
  thread t1(addMoney);
  thread t2(addMoney);

  t1.join();
  t2.join();
  
  cout << amount;
}
