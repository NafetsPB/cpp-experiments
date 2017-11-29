#include <iostream>
#include <memory>

using namespace std;

struct MyStruct
{
   unsigned int iID     {0};
   float        fValue  {0.0};

   // The following two-argument constructor is required
   // for make_unique() so that it can forward its arguments

   MyStruct(unsigned int id, float value)
           : iID{ id }, fValue{ value }
   {

   }
};

auto main() -> int
{
   auto UniquePointerToInt      = make_unique<int>(456);

   auto UniquePointerToMyStruct = make_unique<MyStruct>(1, 4.2f);
   auto MovedPointerToMyStruct  = move(UniquePointerToMyStruct);

   // After the move() the unique pointer is being moved to the new
   // unique pointer named MovedPointerToMyStruct, meaning that the
   // original one (UniquePointerToMyStruct) is a nullptr!

   if (UniquePointerToMyStruct)
      cout << "UniquePointerToMyStruct owns MyStruct" << endl;

   if (MovedPointerToMyStruct)
      cout << "MovedPointerToMyStruct owns MyStruct" << endl;

   // Wait for any key to be pressed before exiting the application
   std::getchar();

   return 0;
}