#ifndef AutoDiff_CONSTANTOP_h
#define AutoDiff_CONSTANTOP_h

namespace AD
{

namespace internal
{

enum
{
   LHS,
   RHS
};

/*
 * Traits specialization for ConstantOp
 */
template<int Side,typename Derived,typename Op>
struct traits<ConstantOp<Side,Derived,Op> > {
   static const int nDeriv = internal::traits<Derived>::nDeriv;
};

}; // end namespace internal

/*
 * Constant Op, with the constant on the LHS
 */
template<typename Rhs,typename Op>
class ConstantOp<internal::LHS,Rhs,Op> : public ADBase<ConstantOp<internal::LHS,Rhs,Op> >
{
  typedef ConstantOp<internal::LHS,Rhs,Op> Derived;
  static const int nDeriv = internal::traits<Rhs>::nDeriv;
  typedef AutoDiff<nDeriv> T;

  protected:
  const double &_c;
  const Rhs &_rhs;
  const Op  &_op;

  public:
  inline ConstantOp(const double &C, const Rhs &rhs,const Op &op): _c(C), _rhs(rhs), _op(op) {};
  inline ConstantOp(const ConstantOp &A) : _c(A._c), _rhs(A._rhs), _op(A._op)
  { }

  inline T eval() const{
    return _op.eval(_c,_rhs.eval());
  }

};

/*
 * Constant Op, with the constant on the RHS
 */
template<typename Lhs,typename Op>
class ConstantOp<internal::RHS,Lhs,Op> : public ADBase<ConstantOp<internal::RHS,Lhs,Op> >
{
  typedef ConstantOp<internal::LHS,Lhs,Op> Derived;
  static const int nDeriv = internal::traits<Lhs>::nDeriv;
  typedef AutoDiff<nDeriv> T;
  protected:
  const Lhs &_lhs;
  const double &_c;
  const Op  &_op;

  public:
  inline ConstantOp(const Lhs &lhs,const double &C, const Op &op): _c(C), _lhs(lhs), _op(op) {}
  inline ConstantOp(const ConstantOp &A) : _c(A._c), _lhs(A._lhs), _op(A._op) {}

  inline T eval() const{
    return _op.eval(_lhs.eval(),_c);
  }

  inline const Lhs& getExpr() const { return _lhs; }

};

template<int nDeriv>
struct AddConOp
{
   typedef AutoDiff<nDeriv> T;
   inline static const
      T eval(const T& lhs,const double& rhs){
         T a;
         a.x  = lhs.x + rhs;
         a.dx = lhs.dx;
         return a;
      }
   inline static const
      T eval(const double& lhs,const T& rhs){
         T a;
         a.x  = lhs + rhs.x;
         a.dx = rhs.dx;
         return a;
      }
};

template<int nDeriv>
struct SubConOp
{
   typedef AutoDiff<nDeriv> T;
   inline static const
      T eval(const T& lhs,const double& rhs){
         T a;
         a.x  = lhs.x - rhs;
         a.dx = lhs.dx;
         return a;
      }
   inline static const
      T eval(const double& lhs,const T& rhs){
         T a;
         a.x  = lhs - rhs.x;
         a.dx = -rhs.dx;
         return a;
      }
};

template<int nDeriv>
struct MulConOp
{
   typedef AutoDiff<nDeriv> T;
   inline static const
      T eval(const T& lhs,const double& rhs){
         T a;
         a.x  = lhs.x * rhs;
         a.dx = lhs.dx*rhs;
         return a;
      }
   inline static const
      T eval(const double& lhs,const T& rhs){
         T a;
         a.x  = lhs * rhs.x;
         a.dx = lhs*rhs.dx;
         return a;
      }
};

template<int nDeriv>
struct DivConOp
{
   typedef AutoDiff<nDeriv> T;
   inline static const
      T eval(const T& lhs,const double& rhs){
         T a;
         a.x  = lhs.x /rhs;
         a.dx = lhs.dx/rhs;
         return a;
      }
   inline static const
      T eval(const double& lhs,const T& rhs){
         T a;
         a.x  =  lhs /rhs.x;
         a.dx = -(lhs*rhs.dx)/(rhs.x*rhs.x);
         return a;
      }
};

AutoDiff_LHS_CONSTANT_OP(AddConOp,+)
AutoDiff_LHS_CONSTANT_OP(SubConOp,-)
AutoDiff_LHS_CONSTANT_OP(MulConOp,*)
AutoDiff_LHS_CONSTANT_OP(DivConOp,/)

// AutoDiff_LHS_CONSTANT_OP(LesConOp,<)
// AutoDiff_LHS_CONSTANT_OP(GreConOp,>)
// AutoDiff_LHS_CONSTANT_OP(LEqConOp,<=)
// AutoDiff_LHS_CONSTANT_OP(GEqConOp,>=)
// AutoDiff_LHS_CONSTANT_OP(EquConOp,==)
// AutoDiff_LHS_CONSTANT_OP(NEqConOp,!=)

AutoDiff_RHS_CONSTANT_OP(AddConOp,+)
AutoDiff_RHS_CONSTANT_OP(SubConOp,-)
AutoDiff_RHS_CONSTANT_OP(MulConOp,*)
AutoDiff_RHS_CONSTANT_OP(DivConOp,/)

// AutoDiff_RHS_CONSTANT_OP(LesConOp,<)
// AutoDiff_RHS_CONSTANT_OP(GreConOp,>)
// AutoDiff_RHS_CONSTANT_OP(LEqConOp,<=)
// AutoDiff_RHS_CONSTANT_OP(GEqConOp,>=)
// AutoDiff_RHS_CONSTANT_OP(EquConOp,==)
// AutoDiff_RHS_CONSTANT_OP(NEqConOp,!=)

}; // end namespace AutoDiff
#endif
