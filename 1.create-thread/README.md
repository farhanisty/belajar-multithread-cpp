# Cara membuat thread di c++

Beberapa hal yang perlu diperhatikan saat membuat thread:

- Thread baru dimasukkan pada c++ 11 (gunakan minimal standar tersebut pada saat melakukan kompilasi menggunakan g++)
- Thread membutuhkan library <thread>

5 cara membuat thread:

1. Function pointer
   
   ```cpp
   #include <thread>
   
   ...
   
   void fun(int x)
   {
       while( x --> 0) {
           std::cout << x << std::endl;
       }
   }
   
   ...
   
   int main()
   {
       std::thread t(fun, 10);
       
       t.join();
   
       return 0;
   }
   ```

2. Lambda
   
   ```cpp
   #include <thread>
   
   ...
   
   int main()
   {
       auto fun = [](int x) {
           while(x --> 0) {
             std::cout << x << std::endl;
           }        
       };
   
       std::thread t(fun, 10);
       
       t.join();
   
       return 0;
   }
   ```

3. Functor(Function Object)
   
   ```cpp
   #include <thread>
   
   ...
   
   class Base
   {
     public:
       void operator ()(int x) {
         while(x --> 0) {
           std::cout << x << std::endl;
         }
       }
   };
   
   ...
   
   int main()
   {
       std::thread t((Base()), 10);
       
       t.join();
   
       return 0;
   }
   ```

4. Non static member function
   
   ```cpp
   #include <thread>
   
   ...
   
   class Base
   {
     public:
       void run(int x) {
         while(x --> 0) {
           std::cout << x << std::endl;
         }
       }
   };
   
   ...
   
   int main()
   {
       Base b;
       std::thread t(&Base::run, &b, 10);
       
       t.join();
   
       return 0;
   }
   ```

5. Static member function
   
   ```cpp
   #include <thread>
   
   ...
   
   class Base
   {
     public:
       static void run(int x) {
         while(x --> 0) {
           std::cout << x << std::endl;
         }
       }
   };
   
   ...
   
   int main()
   {
       std::thread t(&Base::run, 10);
       
       t.join();
   
       return 0;
   }
   ```
