#ifndef AutoDiff_UNARYOP_H
#define AutoDiff_UNARYOP_H

namespace AD
{

namespace internal
{

template<typename Rhs,typename Op>
struct traits< UnaryOp<Rhs,Op> > 
{
   static const int nDeriv = traits<Rhs>::nDeriv;
};

}; // end namespace internal

/*
 * Unary Op
 */
template<typename Rhs,typename Op>
class UnaryOp : public ADBase<UnaryOp<Rhs,Op> >
{
	typedef UnaryOp<Rhs,Op> Derived;
   static const int nDeriv = internal::traits<Derived>::nDeriv;
   typedef AutoDiff<nDeriv> T;

protected:
	const Rhs& _rhs;
	const Op&  _op;

public:
	inline UnaryOp(const Rhs& rhs,const Op& op): _rhs(rhs), _op(op)
	{ }
	inline UnaryOp(const UnaryOp& A) : _rhs(A._rhs), _op(A._op)
	{ }

   T eval() const {
      return _op.eval(_rhs.eval());
   }

};

/*
 * Define functors
 * These should have matching functions in ArrayBase.h and ArrayMath.h
 */

template<int nDeriv>
struct NegUnOp {
   typedef AutoDiff<nDeriv> T;
	inline static const 
      T eval (const T& rhs) {
         T a;
         a.x  = -rhs.x;
         a.dx = -rhs.dx;
		return a;
	}
};

// AD_UNARY_OP(SqrtUnOp,sqrt)
// AD_UNARY_OP(SinUnOp,sin)
// AD_UNARY_OP(CosUnOp,cos)

}; // end namespace AD
#endif
