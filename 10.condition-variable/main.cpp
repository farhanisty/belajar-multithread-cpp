#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

condition_variable cv;
mutex m;
long balance;

void addMoney(int money)
{
  lock_guard<mutex> lock(m);
  balance += money;
  cout << "Amount Added Current Balance: " << balance << endl;
  cv.notify_one();
}

void withdraw(int money)
{
  unique_lock<mutex> ul(m);
  cv.wait(ul, [] { return (balance != 0) ? true : false; });

  if(balance >= money) {
    balance -= money;
    cout << "Amount Deducted: " << money << endl;
  } else {
    cout << "Amount Can't Be Deducted, Current Balance Is " << balance << endl;
  }

  cout << "Current Balance is: " << balance <<endl;
}

int main()
{
  thread t1(withdraw, 500);
  thread t2(addMoney, 1000);

  t1.join();
  t2.join();

  return 0;
}
