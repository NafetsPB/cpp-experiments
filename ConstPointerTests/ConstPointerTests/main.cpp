#include <iostream>

auto main() -> int
{
   std::cout << "Hello, World!" << std::endl;

   int myint = 0;
   int mysecondint = 1337;
   int *pMyInt = &myint;

   const int *pConstInt = &myint;
   const int * const pConstConstInt = &myint;

   std::cout << "myint = " << myint << std::endl;

   std::cout << "I can change pMyInt without problem:" << std::endl;

   *pMyInt = 42;

   std::cout << "myint = " << myint << std::endl;

   // *pConstInt = 1337; // This is not allowed!

   std::cout << "I cannot change the content of pConstInt but I can change the pointer itself:" << std::endl;

   pConstInt = &mysecondint;

   std::cout << "pConstInt is now = " << *pConstInt << std::endl;

   // These actions are not allowed at all because pConstConstInt is not a modifyable lvalue:
   // pConstConstInt = &mysecondint;
   // *pConstConstInt = 99;

   std::cout << "By using pConstConstInt I cannot change anything." << std::endl;

   std::cout << "Finished. Press a key to continue." << std::endl;

   // Auf einen Tastendruck warten, damit das Terminal mit der Ausgabe nicht sofort wieder geschlossen wird
   std::getchar();

   return 0;
}
