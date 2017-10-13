#include <iostream>

using namespace std;

void WaitForChar()
{
   cout << "Weiter mit beliebiger Taste..." << endl;
   getchar();
}

void IncrementIntVal(int iValue)
{
   iValue++;
}

void IncrementIntRef(int& iReference)
{
   iReference++;
}

int IncrementAfterIntReturnVal(int iValue)
{
   return iValue++;
}

int IncrementAfterIntReturnRef(int& iValue)
{
   return iValue++;
}

int IncrementBeforeIntReturnVal(int iValue)
{
   return ++iValue;
}

int IncrementBeforeIntReturnRef(int& iValue)
{
   return ++iValue;
}

void IncrementAfterIntPtr(int *pInt)
{
   if (pInt)
      *pInt++;
}

void IncrementBeforeIntPtr(int *pInt)
{
   if (pInt)
      ++(*pInt);
}

// ------------------ MAIN ------------------

auto main() -> int
{
   int iIndex {0};

   cout << "Initialer Wert: " << iIndex << endl;

   IncrementIntVal(iIndex);

   cout << "Wert nach IncrementIntVal: " << iIndex << endl;

   IncrementIntRef(iIndex);

   cout << "Wert nach IncrementIntRef: " << iIndex << endl;

   iIndex = IncrementAfterIntReturnVal(iIndex);

   cout << "Wert nach IncrementAfterIntReturnVal: " << iIndex << endl;

   iIndex = IncrementAfterIntReturnRef(iIndex);

   cout << "Wert nach IncrementAfterIntReturnRef: " << iIndex << endl;

   iIndex = IncrementBeforeIntReturnVal(iIndex);

   cout << "Wert nach IncrementBeforeIntReturnVal: " << iIndex << endl;

   iIndex = IncrementBeforeIntReturnRef(iIndex);

   cout << "Wert nach IncrementBeforeIntReturnRef: " << iIndex << endl;

   IncrementAfterIntPtr(&iIndex);

   cout << "Wert nach IncrementAfterIntPtr: " << iIndex << endl;
   
   IncrementBeforeIntPtr(&iIndex);

   cout << "Wert nach IncrementBeforeIntPtr: " << iIndex << endl;

   WaitForChar();

   return 0;
}