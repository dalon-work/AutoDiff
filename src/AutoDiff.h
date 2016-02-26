#ifndef AUTODIFF
#define AUTODIFF

template<int nDeriv,int Order> class AutoDiff;

template<int nDeriv>
class AutoDiff<nDeriv,1> : ADBase< AutoDiff<nDeriv,1> >
{
   public:
      double x;
      FortCpp::Fixed<double,nDeriv> dx;

};

template<int nDeriv,int Order>
class AutoDiff<nDeriv,Order> : ADBase< AutoDiff<nDeriv,1> >
{
   public:
      double x;
      FortCpp::Fixed< AutoDiff<nDeriv,Order-1> , nDeriv > dx;

};

#endif
