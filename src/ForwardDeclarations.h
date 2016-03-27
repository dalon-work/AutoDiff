#ifndef AD_FORWARD
#define AD_FORWARD

namespace AD
{


template<typename Derived> class ADBase;
template<int nDeriv> class AutoDiff;
template<typename Lhs,typename Rhs,typename Op> class BinaryOp;
template<int Side,typename Derived,typename Op> class ConstantOp;
template<typename Rhs,typename Op> class UnaryOp;

namespace internal
{

template<typename Derived> struct traits;

}; // end namespace internal

}; // end namespace AD


#endif

