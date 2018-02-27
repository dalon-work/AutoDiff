#ifndef AUTODIFF
#define AUTODIFF

#include "ADBase.h"
#include <array>

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
      double _x;
      std::array<double,nDeriv> _dx;

      typedef class AutoDiff Derived;
      typedef class ADBase< AutoDiff<nDeriv> > Base;

      AutoDiff() {};

      AutoDiff(const AutoDiff&)=default;
      AutoDiff(AutoDiff&&)=default;

      Derived& operator = (const AutoDiff& B)
      {
         this->_x = B._x;
         this->_dx = B._dx;
         return *this;
      }
      Derived& operator = (AutoDiff&& B)
      {
         this->_x = B._x;
         this->_dx = B._dx;
         return *this;
      }

      template<typename OtherDerived>
      Derived& operator = (const ADBase<OtherDerived>& B){
         return Base::operator = (B);
      }

      double& x() {
         return _x;
      }

      const double & x() const {
         return _x;
      }

      double& dx(const int& i) {
         return _dx[i];
      }

      const double& dx(const int& i) const {
         return _dx[i];
      }

      friend std::ostream& operator << (std::ostream& os, const AutoDiff<nDeriv>& A)
      {
         os << "x : " << A.x() << " dx: ";
         for(int i=0;i<nDeriv;i++) {
            os << A.dx(i) << ' ';
         }
         return os;
      }

};


}; // end namespace AD

#endif
