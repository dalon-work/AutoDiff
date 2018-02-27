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
  inline ConstantOp(const ConstantOp &A) : _c(A._c), _rhs(A._rhs), _op(A._op) { }

  inline double x() const{
    return _op.x(_c, _rhs.x());
  }

  inline double dx(const int& i) const {
    return _op.x(_c, 0.0, _rhs.x(), _rhs.dx(i));
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

  inline double x() const {
    return _op.x(_lhs.x(), _c);
  }

  inline double dx(const int& i) const {
    return _op.dx(_lhs.x(), _lhs.dx(i), _c, 0.0);
  }

  inline const Lhs& getExpr() const { return _lhs; }

};

AutoDiff_LHS_CONSTANT_OP(AddBinOp,+)
AutoDiff_LHS_CONSTANT_OP(SubBinOp,-)
AutoDiff_LHS_CONSTANT_OP(MulBinOp,*)
AutoDiff_LHS_CONSTANT_OP(DivBinOp,/)

// AutoDiff_LHS_CONSTANT_OP(LesConOp,<)
// AutoDiff_LHS_CONSTANT_OP(GreConOp,>)
// AutoDiff_LHS_CONSTANT_OP(LEqConOp,<=)
// AutoDiff_LHS_CONSTANT_OP(GEqConOp,>=)
// AutoDiff_LHS_CONSTANT_OP(EquConOp,==)
// AutoDiff_LHS_CONSTANT_OP(NEqConOp,!=)

AutoDiff_RHS_CONSTANT_OP(AddBinOp,+)
AutoDiff_RHS_CONSTANT_OP(SubBinOp,-)
AutoDiff_RHS_CONSTANT_OP(MulBinOp,*)
AutoDiff_RHS_CONSTANT_OP(DivBinOp,/)

// AutoDiff_RHS_CONSTANT_OP(LesConOp,<)
// AutoDiff_RHS_CONSTANT_OP(GreConOp,>)
// AutoDiff_RHS_CONSTANT_OP(LEqConOp,<=)
// AutoDiff_RHS_CONSTANT_OP(GEqConOp,>=)
// AutoDiff_RHS_CONSTANT_OP(EquConOp,==)
// AutoDiff_RHS_CONSTANT_OP(NEqConOp,!=)

}; // end namespace AutoDiff
#endif
