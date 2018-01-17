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

   // Create a Shared Pointer

   auto SharedPointerToMyStruct = make_shared<MyStruct>(2, 2.2f);

   // Create a Weak Pointer

   auto WeakPointer = std::shared_ptr<MyStruct>(SharedPointerToMyStruct);

   if (SharedPointerToMyStruct)
      cout << "Shared Pointer owns MyStruct" << endl;

   if (WeakPointer)
      cout << "Weak Pointer also points to MyStruct but does not own it." << endl;

   // Release and/or Destruct

/*
   WeakPointer.reset();

   if (WeakPointer)
      cout << "Weak Pointer still valid after reset()" << endl;
   else if (SharedPointerToMyStruct)
      cout << "Weak Pointer invalid, Shared Pointer still there." << endl;
*/

   if (SharedPointerToMyStruct)
   {
      delete std::get_deleter<MyStruct>(SharedPointerToMyStruct);
      SharedPointerToMyStruct.reset();
   }

   if (SharedPointerToMyStruct)
      cout << "Shared Pointer still valid after delete()." << endl;
   else
      cout << "Shared Pointer is null after delete()." << endl;

   if (WeakPointer)
      cout << "Weak Pointer still valid after reset()" << endl;
   else if (SharedPointerToMyStruct)
      cout << "Weak Pointer invalid, Shared Pointer still there." << endl;

   WeakPointer.reset();

   if (!WeakPointer)
      cout << "Weak Pointer is null after reset()" << endl;
   
   // Wait for any key to be pressed before exiting the application
   cout << "\n----\nPress any key to exit." << endl;
   std::getchar();

   return 0;
}