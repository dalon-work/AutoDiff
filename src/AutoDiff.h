#ifndef AUTODIFF
#define AUTODIFF

#include "ADBase.h"

namespace AD
{

namespace internal
{
   template<int _nDeriv>
   struct traits< AutoDiff<_nDeriv> >
   {
      static const int nDeriv = _nDeriv;
   };
};

template<int nDeriv>
class AutoDiff : public ADBase< AutoDiff<nDeriv> >
{
   public:
      double x;
      FortCpp::Fixed<double,nDeriv> dx;

      typedef class AutoDiff Derived;
      typedef class ADBase< AutoDiff<nDeriv> > Base;

      AutoDiff()=default;

      AutoDiff(const AutoDiff&)=default;
      AutoDiff(AutoDiff&&)=default;

      Derived& operator = (const AutoDiff& B)
      {
         (*this).x = B.x;
         (*this).dx = B.dx;
         return *this;
      }
      Derived& operator = (AutoDiff&& B)
      {
         (*this).x = B.x;
         (*this).dx = B.dx;
         return *this;
      }

      double operator = (double B)
      {
         x = B;
         dx = 0.0;
         return B;
      }

      template<typename OtherDerived>
      Derived& operator = (const ADBase<OtherDerived>& B){
         return Base::operator = (B);
      }

      Derived& eval() {
         return *this;
      }
      const Derived& eval() const {
         return *this;
      }

   friend std::ostream& operator << (std::ostream& os, const AutoDiff<nDeriv>& A)
   {
      os << "x : " << A.x << " dx: " << A.dx << std::endl;
      return os;
   }

};

}; // end namespace AD

#endif
