#ifndef AUTODIFF
#define AUTODIFF

namespace AutoDiff
{

template <typename Derived>
class ADBase
{

public:

	typedef typename internal::traits<Derived>::Scalar T;

	ADBase()=default;
	ADBase(const ADBase<Derived>&)=default;
	ADBase(ADBase<Derived>&&)=default;
	~ADBase()=default;


// 	inline Derived& operator = (const ADBase<Derived>& B) {
// #ifndef NDEBUG
// 		internal::debug::compare_dims(derived(),B.derived());
// #endif
// #pragma GCC ivdep
// 		for (int i=0; i<this->size(); i++) {
// 			derived()[i] = B.derived()[i];
// 		}
// 		return derived();
// 	}

// 	inline Derived& operator = (ADBase<Derived>&& B) {
// #ifndef NDEBUG
// 		internal::debug::compare_dims(derived(),B.derived());
// #endif
// #pragma GCC ivdep
// 		for (int i=0; i<this->size(); i++) {
// 			derived()[i] = B.derived()[i];
// 		}
// 		return derived();
// 	}

// 	#<{(|*
// 	 * Sets the entire array to a given value
// 	 |)}>#
// 	inline const T& operator = (const T& B) {
// #pragma GCC ivdep
// 		for (int i=0; i < size(); i++) {
// 			derived()[i] = B;
// 		}
// 		return B;
// 	}

// 	template<typename OtherDerived>
// 	inline Derived& operator = (const ADBase<OtherDerived>& B) {
// #ifndef NDEBUG
// 		internal::debug::compare_dims(derived(),B.derived());
// #endif
// #pragma GCC ivdep
// 		for (int i=0; i<this->size(); i++) {
// 			derived()[i] = static_cast<T>(B.derived()[i]);
// 		}
// 		return derived();
// 	}
//
// 	constexpr int size() const { return derived().size(); }
// 	constexpr int size(int i) const { return derived().size(i); }
//
// 	#<{(|*
// 	 * += and -= operators
// 	 |)}>#
// 	inline Derived& operator += (const T& B) {
// 		derived() = derived() + B;
// 		return derived();
// 	}
//
// 	template<typename OtherDerived>
// 	inline Derived& operator += (const ADBase<OtherDerived>& B) {
// #ifndef NDEBUG
// 		internal::debug::compare_dims(derived(),B.derived());
// #endif
// 		derived() = derived() + B.derived();
// 		return derived();
// 	}
//
// 	inline Derived& operator -= (const T& B) {
// 		derived() = derived() - B;
// 		return derived();
// 	}
//
// 	template<typename OtherDerived>
// 	inline Derived& operator -= (const ADBase<OtherDerived>& B) {
// #ifndef NDEBUG
// 		internal::debug::compare_dims(derived(),B.derived());
// #endif
// 		derived() = derived() - B.derived();
// 		return derived();
// 	}

	/************************************************/

   // FortCpp_BASE_BINARY_OP(AddBinOp,+)
   // FortCpp_BASE_BINARY_OP(SubBinOp,-)
   // FortCpp_BASE_BINARY_OP(MulBinOp,*)
   // FortCpp_BASE_BINARY_OP(DivBinOp,/)
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

	//
	//  inline explicit operator bool() const {
	//    for(int i=0;i<derived().size();i++){
	//      if(derived()[i]) return 1;
	//    }
	//    return 0;
	//  }

	const Derived& derived() const { return *static_cast<const Derived*>(this); }
	Derived& derived() { return *static_cast<Derived*>(this); }

	// friend std::ostream& operator << (std::ostream& os, const ADBase<Derived>& A) {
	// 	for (int i=0; i<A.size(); i++) {
	// 		os << A.derived()[i] << ' ';
	// 	}
	// 	return os;
	// }
};

}; // end namespace AutoDiff

#endif
