#include "../../FortCpp/FortCpp.h"
#include "../src/AutoDiff.h"
#include <iostream>

int main()
{

   using namespace AD;
   using namespace std;
   using namespace FortCpp;

   AutoDiff<1> a,b,c,d;

   Alloc< AutoDiff<1> ,1> e,f,g;

   e.allocate(10);
   f.allocate(10);
   g.allocate(10);

   for(int i=0;i<10;i++){
      e[i] = 3.0;
      f[i].x  = i;
      f[i].dx = 1.0;
   }

   g = f*f*f;

   cout << g << endl;
   
   // a = 2.0;
   // a.dx = 1.0;
   //
   // d = a;
   //
   // cout << d << endl;
   //
   // d = a*a;
   // cout << d << endl;






}

   
