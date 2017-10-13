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
   {
      (*pInt)++;
      cout << " lokaler Wert (*pInt) = " << *pInt << " ";
   }
}

void IncrementBeforeIntPtr(int *pInt)
{
   if (pInt)
   {
      ++(*pInt);
      cout << " lokaler Wert (*pInt) = " << *pInt << " ";
   }
}

// ------------------ MAIN ------------------

auto main() -> int
{
   int iIndex {0};

   cout << "Eingabewert: " << iIndex << " -> ";
   IncrementIntVal(iIndex);

   cout << "Wert nach IncrementIntVal: " << iIndex << endl;

   cout << "Eingabewert: " << iIndex << " -> ";
   IncrementIntRef(iIndex);

   cout << "Wert nach IncrementIntRef: " << iIndex << endl;

   cout << "Eingabewert: " << iIndex << " -> ";
   int iRetVal = IncrementAfterIntReturnVal(iIndex);

   cout << "Wert nach IncrementAfterIntReturnVal: " << iIndex << " Return Value = " << iRetVal << endl;

   iIndex = iRetVal;

   cout << "Eingabewert: " << iIndex << " -> ";
   iRetVal = IncrementAfterIntReturnRef(iIndex);

   cout << "Wert nach IncrementAfterIntReturnRef: " << iIndex << " Return Value = " << iRetVal << endl;

   iIndex = iRetVal;

   cout << "Eingabewert: " << iIndex << " -> ";
   iRetVal = IncrementAfterIntReturnVal2Steps(iIndex);

   cout << "Wert nach IncrementAfterIntReturnVal2Steps: " << iIndex << " Return Value = " << iRetVal << endl;

   iIndex = iRetVal;

   cout << "Eingabewert: " << iIndex << " -> ";
   iRetVal = IncrementAfterIntReturnRef2Steps(iIndex);

   cout << "Wert nach IncrementAfterIntReturnRef2Steps: " << iIndex << " Return Value = " << iRetVal << endl;

   iIndex = iRetVal;

   cout << "Eingabewert: " << iIndex << " -> ";
   iRetVal = IncrementBeforeIntReturnVal(iIndex);

   cout << "Wert nach IncrementBeforeIntReturnVal: " << iIndex << " Return Value = " << iRetVal << endl;

   iIndex = iRetVal;

   cout << "Eingabewert: " << iIndex << " -> ";
   iRetVal = IncrementBeforeIntReturnRef(iIndex);

   cout << "Wert nach IncrementBeforeIntReturnRef: " << iIndex << " Return Value = " << iRetVal << endl;

   iIndex = iRetVal;

   cout << "Eingabewert: " << iIndex << " -> ";
   IncrementAfterIntPtr(&iIndex);

   cout << "Wert nach IncrementAfterIntPtr: " << iIndex << endl;
   
   cout << "Eingabewert: " << iIndex << " -> ";
   IncrementBeforeIntPtr(&iIndex);

   cout << "Wert nach IncrementBeforeIntPtr: " << iIndex << endl;

   WaitForChar();

   return 0;
}