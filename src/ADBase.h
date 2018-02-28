#ifndef ADBASE
#define ADBASE

#include "Macros.h"
#include "ForwardDeclarations.h"
#include "BinaryOp.h"
#include "ConstantOp.h"
#include "UnaryOp.h"

namespace AD
{

template <typename Derived>
class ADBase
{

public:

   static const int nDeriv = internal::traits<Derived>::nDeriv;

	ADBase()=default;
	ADBase(const ADBase<Derived>&)=default;
	ADBase(ADBase<Derived>&&)=default;
	~ADBase()=default;


	inline Derived& operator = (const ADBase<Derived>& B) {
      derived().x() = B.derived().x();
      derived().dx() = B.derived().dx();
		return derived();
	}

	inline Derived& operator = (ADBase<Derived>&& B) {
      derived().x() = B.derived().x();
      for(int i=0; i<nDeriv; i++) {
         derived().dx[i] = B.derived().dx(i);
      }
		return derived();
	}

	template<typename OtherDerived>
	inline Derived& operator = (const ADBase<OtherDerived>& B) {
      static_assert( nDeriv == internal::traits<OtherDerived>::nDeriv , "Number of derivatives used does not match in equation");
      derived().x() = B.derived().x();
      for(int i=0;i<nDeriv;i++) {
         derived().dx(i) = B.derived().dx(i);
      }
		return derived();
	}


	/************************************************/

   AutoDiff_BASE_BINARY_OP(AddBinOp,+)
   AutoDiff_BASE_BINARY_OP(SubBinOp,-)
   AutoDiff_BASE_BINARY_OP(MulBinOp,*)
   AutoDiff_BASE_BINARY_OP(DivBinOp,/)

   // inline const UnaryOp<Derived,NegUnOp<nDeriv> > operator -() const {
   //    return UnaryOp<Derived,NegUnOp<nDeriv> >(derived(),NegUnOp<nDeriv>());
   // }

   // FortCpp_BASE_BINARY_OP(LesBinOp,<)
   // FortCpp_BASE_BINARY_OP(GreBinOp,>)
   // FortCpp_BASE_BINARY_OP(LEqBinOp,<=)
   // FortCpp_BASE_BINARY_OP(GEqBinOp,>=)
   // FortCpp_BASE_BINARY_OP(EquBinOp,==)
   // FortCpp_BASE_BINARY_OP(NEqBinOp,!=)
   //
   //
	// FortCpp_UNARY_FUNC(SqrtUnOp,sqrt)
	// FortCpp_UNARY_FUNC(SinUnOp,sin)
	// FortCpp_UNARY_FUNC(CosUnOp,cos)
   //
	// inline const UnaryOp<Derived,NegUnOp<T> >operator -() const {
	// 	return UnaryOp<Derived,NegUnOp<T> >(this->derived(),NegUnOp<T>());
	// }

	const Derived& derived() const { return *static_cast<const Derived*>(this); }
	Derived& derived() { return *static_cast<Derived*>(this); }

};

}; // end namespace AD

#endif
