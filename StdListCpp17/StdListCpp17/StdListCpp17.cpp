// StdListCpp17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <map>

auto main() -> int
{
   std::list<long>       listOfLongs { 1L, 2L, 3L };
   std::map<long, long>  testMap;

   if (std::find(listOfLongs.begin(), listOfLongs.end(), 2L) != listOfLongs.end())
      std::cout << "Found entry in list!" << std::endl;

   for (const auto& listItem : listOfLongs)
   {
      std::cout << "Item in list: " << listItem << std::endl;
   }

   testMap.emplace(1L, 2L);
   testMap.emplace(2L, 4L);

   for (const auto& mapItem : testMap)
   {
      std::cout << "Item in Map: " << mapItem.second << std::endl;
   }

   // Wait for any key to be pressed before exiting the application
   std::cout << "\n----\nPress any key to exit." << std::endl;
   std::getchar();


   return 0;
}

