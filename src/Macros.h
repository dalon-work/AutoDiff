
#define AutoDiff_BASE_BINARY_OP(OP,X) template <typename OtherDerived> \
   inline const BinaryOp<Derived,OtherDerived,OP<nDeriv> >operator X \
     (const ADBase<OtherDerived> &rhs) const \
   { \
     return BinaryOp<Derived,OtherDerived,OP<nDeriv> >(derived(),rhs.derived(),OP<nDeriv>()); \
   }

#define AutoDiff_LHS_CONSTANT_OP(OP,X)  \
   template <typename Derived> \
   inline const ConstantOp<internal::LHS, \
                           Derived, \
                           OP<internal::traits<Derived>::nDeriv> > \
                           operator X \
     (const double& lhs,const ADBase<Derived> &rhs) \
   { \
      static const int nDeriv = internal::traits<Derived>::nDeriv; \
     return ConstantOp<internal::LHS,Derived,OP<nDeriv> >(lhs,rhs.derived(),OP<nDeriv>()); \
   }

#define AutoDiff_RHS_CONSTANT_OP(OP,X) \
   template <typename Derived> \
   inline const ConstantOp<internal::RHS, \
                           Derived, \
                           OP<internal::traits<Derived>::nDeriv> > \
                           operator X \
     (const ADBase<Derived> &lhs,const double& rhs) \
   { \
      static const int nDeriv = internal::traits<Derived>::nDeriv; \
     return ConstantOp<internal::RHS,Derived,OP<nDeriv> >(lhs.derived(),rhs,OP<nDeriv>()); \
   }

