/**********************************************************************************
    Blessing Alagba
    v223e376
    Program 5
*/

#include <iostream>
#include "arraydb.cpp"

using namespace std;

#ifndef __ARITHARR_HPP__
#ifndef __LIMARR_HPP__
int main ()
{
   unsigned int regions;
   cout << "Enter number of regions";
   cin >> regions;

   // Create an "array" of that size
   ArrayDb <double> tons(regions);

   cout << "Enter the regional sales in tons:\n";
   int i;
   for (i = 0; i < regions; i++)
   {
      cout << "Region " << (i+1) << ":  ";
      cin >> tons[i];
      // tons.operator[](i)
   }

   cout << tons;

   // Default object
   ArrayDb <double> dup;

   // Array assignment - calls the overloaded operator=
   dup = tons;
   cout << "Here's the original data:\n" << tons;
   cout << "Here's the copy :\n" << dup;

   double wts[5] = {155.2, 189.6, 174.3, 256.9, 203.5};

   // Initialize an ArrayDb to an array
   ArrayDb <double> bod (wts,5);

   cout << "Here are the weights:\n" << bod;

   //try to exceed array limit
   cout << "Index: value \n";
   for (i = 0; i <= regions; i++)
   {
   	    cout.width(5);
        cout << i << ": " << tons[i] << "\n";
   }

   return 0;
}
#endif
#endif
