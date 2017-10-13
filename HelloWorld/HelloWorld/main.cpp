#include <iostream>

auto main() -> int
{
   std::cout << "Hello, World!" << std::endl;

   // Auf einen Tastendruck warten, damit das Terminal mit der Ausgabe nicht sofort wieder geschlossen wird
   std::getchar();

   return 0;
}