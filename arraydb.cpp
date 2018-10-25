/**********************************************************************************
    Blessing Alagba
    v223e376
    Program 5
*/

#include "arraydb.hpp"


//Default constructor
template <class array>

ArrayDb <array> ::ArrayDb (void)
{
   arr_ptr = NULL;
   size = 0;
}

template <class array>
ArrayDb <array> ::ArrayDb (unsigned int n, array val)
{
   arr_ptr = new array[n];
   if (arr_ptr == NULL)
   {
	   cout << "Can't allocate new array";
       exit(0);
   }
   size = n;
   for (unsigned int i = 0; i < size; i++)
        arr_ptr[i] = val;
}

template <class array>
ArrayDb <array> ::ArrayDb (const array *pn, unsigned int n)
{

   arr_ptr = new array[n];
   size = n;
   for (int i = 0; i < size; i++)
        arr_ptr[i] = pn[i];
}

// Copy constructor
template <class array>
ArrayDb <array> ::ArrayDb (const ArrayDb & a)
{
   size = a.size;
   arr_ptr = new array[size];
   for (int i = 0; i < size; i ++)
    	arr_ptr[i] = a.arr_ptr[i];
}

template <class array>
ArrayDb <array> ::~ArrayDb (void)
{
	if (arr_ptr != NULL)
		delete [] arr_ptr;
}

template <class array>
array & ArrayDb <array> ::operator[] (int i)
{
   //cout << "\n Executing overloaded []";
   if (i < 0 || i >= size)
   {
    	cerr << "Error in array limits";
        exit (1);
   }
   return arr_ptr[i];

}

template <class array>
const array & ArrayDb <array> ::operator[] (int i) const
{
   cout << "\n Executing const overloaded []";
   if (i < 0 || i >= size)
   {
    	cerr << "Error in array limits";
        exit (1);
   }
   return arr_ptr[i];
}

template <class array>
ArrayDb <array> & ArrayDb <array> ::operator=(const ArrayDb <array> & a)
{
	if (this == &a)
   	    return *this;

   delete arr_ptr;
   size = a.size;
   arr_ptr = new array [size];
   for (int i = 0; i < size; i++)
   	    arr_ptr[i] = a.arr_ptr[i];
   return *this;

}

template <class array>
ostream & operator<< (ostream & os, const ArrayDb <array> &a)
{
	cout << "overloaded << " << endl;
   unsigned int i;
   for (i = 0; i < a.size; i++)
   {
    	os << a.arr_ptr[i] << " ";
        if (i % 5 == 4)
      	os << "\n";
   }
   if (i % 5 != 0)
     	os << endl;
   return os;

}

template <class array>
void display (ArrayDb <array> & ar)
{
   cout << "Func!\n";
   cout << ar;
   cout << "Func!\n";
}
