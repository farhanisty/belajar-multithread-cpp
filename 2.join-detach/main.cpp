#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

int saldo = 0;

void tambahSaldo(int *saldo, int penambahan)
{
  this_thread::sleep_for(chrono::seconds(10));
  *saldo += 100000;

  cout << "\nSaldo berhasil ditambahkan\nSaldo akhir = " << *saldo;
}

int main()
{
  int saldo = 0;
  thread t(tambahSaldo, &saldo, 200000);
  if(t.joinable())
    t.detach();
  
  cout << "Saldo awal = " << saldo << endl;
  cout << "loading ";
  while(saldo == 0) {
    this_thread::sleep_for(chrono::seconds(1));
    cout << ".";
  }
  
  return 0;
}
