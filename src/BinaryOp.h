#ifndef AutoDiff_BINARYOP_H
#define AutoDiff_BINARYOP_H

namespace AD
{

namespace internal
{
   template<typename Lhs,typename Rhs,typename Op>
   struct traits<BinaryOp<Lhs,Rhs,Op> >
   {
      static const int nDeriv = internal::traits<Lhs>::nDeriv;
   };
}; // end namespace internal

/*
 * Binary Op
 */
template<typename Lhs,typename Rhs,typename Op>
class BinaryOp : public ADBase<BinaryOp<Lhs,Rhs,Op> >
{
	typedef BinaryOp<Lhs,Rhs,Op> Derived;
   static const int nDeriv = internal::traits<Derived>::nDeriv;
   typedef AutoDiff<nDeriv> T;

protected:
	const Lhs& _lhs;
	const Rhs& _rhs;
	const Op&  _op;

public:
	BinaryOp(const Lhs& lhs,const Rhs& rhs,const Op& op): _lhs(lhs), _rhs(rhs), _op(op) {
	};
	BinaryOp(const BinaryOp& A) : _lhs(A._lhs), _rhs(A._rhs), _op(A._op) { }

	double x() const {
		return _op.x(_lhs.x(),_rhs.x());
	}
	double dx(const int& i) const {
		return _op.dx(_lhs.x(), _lhs.dx(i), _rhs.x(), _rhs.dx(i));
	}

};

template<int nDeriv>
struct AddBinOp
{
   inline static const
      double x(const double& lhs_x,const double& rhs_x){
         return lhs_x + rhs_x;
      }
   inline static const
      double dx(const double& lhs_x,const double& lhs_dx, const double& rhs_x, const double& rhs_dx){
         return lhs_dx + rhs_dx;
      }
};

template<int nDeriv>
struct SubBinOp
{
   typedef AutoDiff<nDeriv> T;
   inline static const
      double x(const double& lhs_x,const double& rhs_x){
         return lhs_x - rhs_x;
      }

   inline static const
      double dx(const double& lhs_x, const double& lhs_dx, const double& rhs_x, const double& rhs_dx){
         return lhs_dx - rhs_dx;
      }
};

template<int nDeriv>
struct MulBinOp
{
   inline static const
      double x(const double& lhs_x,const double& rhs_x){
         return lhs_x * rhs_x;
      }
   inline static const
      double dx(const double& lhs_x,const double& lhs_dx, const double& rhs_x, const double& rhs_dx){
         return lhs_x * rhs_dx + lhs_dx * rhs_x;
      }
};

template<int nDeriv>
struct DivBinOp
{
   inline static const
      double x(const double& lhs_x,const double& rhs_x){
         return lhs_x / rhs_x;
      }

   inline static const
      double dx(const double& lhs_x, const double& lhs_dx, const double& rhs_x, const double& rhs_dx){
         return (lhs_dx*rhs_x - lhs_x*rhs_dx)/(rhs_x*rhs_x);
      }
};

}; // end namespace AD

#endif
