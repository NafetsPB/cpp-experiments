#include <iostream>

auto main() -> int
{
   std::cout << "This is a (const) pointer (const) test program." << std::endl;

   int myint = 0;
   int mysecondint = 1337;
   int *pMyInt = &myint;

   const int *pConstInt = &myint;
   int * const pIntConst = &myint;
   const int * const pConstConstInt = &myint;

   std::cout << "---------------------------------------------------------------------" << std::endl;
   std::cout << "myint = " << myint << std::endl;

   std::cout << "I can change pMyInt without problem:" << std::endl;

   *pMyInt = 42;

   std::cout << "myint = " << myint << std::endl;

   std::cout << "---------------------------------------------------------------------" << std::endl;

   // *pConstInt = 1337; // This is not allowed!

   std::cout << "I cannot change the content of pConstInt but I can change the pointer itself:" << std::endl;

   pConstInt = &mysecondint;

   std::cout << "pConstInt is now = " << *pConstInt << std::endl;
   std::cout << "myint = " << myint << std::endl;

   std::cout << "---------------------------------------------------------------------" << std::endl;

   // pIntConst = &secondint; This is not allowed!

   std::cout << "I cannot change the pointer of pIntConst but I can change the value to where it points to:" << std::endl;

   *pIntConst = 88;

   std::cout << "pIntConst is now = " << *pIntConst << std::endl;
   std::cout << "myint = " << myint << std::endl;

   std::cout << "---------------------------------------------------------------------" << std::endl;

   // These actions are not allowed at all because pConstConstInt is not a modifiable lvalue:
   // pConstConstInt = &mysecondint;
   // *pConstConstInt = 99;

   std::cout << "By using pConstConstInt I cannot change anything." << std::endl;

   std::cout << "---------------------------------------------------------------------" << std::endl;

   std::cout << "Finished. Press a key to continue." << std::endl;

   // Wait for a key/input before closing the console window.
   std::getchar();

   return 0;
}
