#include <iostream>
#include <thread>

using namespace std;

// 3. Functor(Function Object)
// class Base
// {
//   public:
//     void operator ()(int x) {
//       while(x --> 0) {
//         cout << x << endl;
//       }
//     }
// };

// 4. Non static member function
// class Base
// {
//   public:
//     void run(int x) 
//     {
//       while(x --> 0) {
//         std::cout << x << std::endl;
//       }
//     }
// };

// 5. Static member function
class Base
{
  public:
    static void run(int x)
    {
      while(x --> 0) {
        std::cout << x << std::endl;
      }
    }
};

// 1. Function 
// void fun(int x) {
//   while(x --> 0) {
//     cout << x << endl;
//   }
// }

int main()
{
  // 2. Lambda
  // auto fun = [](int x) {
  //   while(x --> 0) {
  //     cout << x << endl;
  //   }
  // };
  
  // ----Pemanggilan thread
  // 1. menggunakan fungsi biasa
  // thread t(fun, 10);
  // 2. menggunakan functor
  // thread t((Base()), 10);
  // 3. menggunakan non static member function
  // Base b;
  // std::thread t(&Base::run, &b, 10);
  // 4. menggunakan static member function 
  std::thread t(&Base::run, 10);
  
  t.join();

  return 0;
}
