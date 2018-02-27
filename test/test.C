#include "../../FortCpp/FortCpp.h"
#include "../src/AutoDiff.h"
#include <iostream>

int main()
{

   using namespace AD;
   using namespace std;
   using namespace FortCpp;

   AutoDiff<1> a,b,c,d;

   a.x() = 3.0;
   a.dx(0) = 1.0;

   b = a*a*a;

   cout << "a: " << a << endl;
   cout << "b: " << b << endl;


}

   
