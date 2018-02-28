#include "../src/AutoDiff.h"



void quadratic_function(const AD::AutoDiff<2> &__restrict__ x, AD::AutoDiff<2> &__restrict__ res)
{
   res = 3.0*x*x + 4.5*x + 1.0;
}

void quadratic_function(const double &x, const double dx[2], double &f, double df[2]) {
       f = 3.0*x*x + 4.5*x + 1.0;
       for(int i=0;i<2;i++) {
          df[i] = 6.0*x*dx[i] + 4.5*dx[i];
       }
}



   
