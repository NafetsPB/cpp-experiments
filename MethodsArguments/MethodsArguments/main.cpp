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

int IncrementAfterIntReturnRef(int& iReference)
{
   return iReference++;
}

int IncrementAfterIntReturnVal2Steps(int iValue)
{
   iValue++;
   return iValue;
}

int IncrementAfterIntReturnRef2Steps(int& iReference)
{
   iReference++;
   return iReference;
}

int IncrementBeforeIntReturnVal(int iValue)
{
   return ++iValue;
}

int IncrementBeforeIntReturnRef(int& iReference)
{
   return ++iReference;
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

   int iRetVal = IncrementAfterIntReturnVal(iIndex);

   cout << "Wert nach IncrementAfterIntReturnVal: " << iIndex << " Return Value = " << iRetVal << endl;

   iIndex = iRetVal;

   iRetVal = IncrementAfterIntReturnRef(iIndex);

   cout << "Wert nach IncrementAfterIntReturnRef: " << iIndex << " Return Value = " << iRetVal << endl;

   iIndex = iRetVal;

   iRetVal = IncrementAfterIntReturnVal2Steps(iIndex);

   cout << "Wert nach IncrementAfterIntReturnVal2Steps: " << iIndex << " Return Value = " << iRetVal << endl;

   iIndex = iRetVal;

   iRetVal = IncrementAfterIntReturnRef2Steps(iIndex);

   cout << "Wert nach IncrementAfterIntReturnRef2Steps: " << iIndex << " Return Value = " << iRetVal << endl;

   iIndex = iRetVal;

   iRetVal = IncrementBeforeIntReturnVal(iIndex);

   cout << "Wert nach IncrementBeforeIntReturnVal: " << iIndex << " Return Value = " << iRetVal << endl;

   iIndex = iRetVal;

   iRetVal = IncrementBeforeIntReturnRef(iIndex);

   cout << "Wert nach IncrementBeforeIntReturnRef: " << iIndex << " Return Value = " << iRetVal << endl;

   iIndex = iRetVal;

   IncrementAfterIntPtr(&iIndex);

   cout << "Wert nach IncrementAfterIntPtr: " << iIndex << endl;
   
   IncrementBeforeIntPtr(&iIndex);

   cout << "Wert nach IncrementBeforeIntPtr: " << iIndex << endl;

   WaitForChar();

   return 0;
}