#include "../src/AutoDiff.h"
#include <iostream>

void quadratic_function(const AD::AutoDiff<2> &x, AD::AutoDiff<2> &res);

int main()
{

   using namespace AD;
   using namespace std;

   AutoDiff<2> a,b,c,d;

   a.x() = 3.0;
   a.dx(0) = 1.0;

   quadratic_function(a,b);

   cout << "a: " << a << endl;
   cout << "b: " << b << endl;


}

   
