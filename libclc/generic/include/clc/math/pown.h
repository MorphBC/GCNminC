#define _CLC_POWN_INTRINSIC "llvm.powi"

#define _CLC_POWN_DECL(GENTYPE, INTTYPE) \
  _CLC_OVERLOAD _CLC_DECL GENTYPE pown(GENTYPE x, INTTYPE y);

#define _CLC_VECTOR_POWN_DECL(GENTYPE, INTTYPE) \
  _CLC_POWN_DECL(GENTYPE##2, INTTYPE##2)  \
  _CLC_POWN_DECL(GENTYPE##3, INTTYPE##3)  \
  _CLC_POWN_DECL(GENTYPE##4, INTTYPE##4)  \
  _CLC_POWN_DECL(GENTYPE##8, INTTYPE##8)  \
  _CLC_POWN_DECL(GENTYPE##16, INTTYPE##16)

_CLC_OVERLOAD float pown(float x, int y) __asm(_CLC_POWN_INTRINSIC ".f32");

_CLC_VECTOR_POWN_DECL(float, int)

#ifdef cl_khr_fp64
_CLC_OVERLOAD double pown(double x, int y) __asm(_CLC_POWN_INTRINSIC ".f64");
_CLC_VECTOR_POWN_DECL(double, int)
#endif

#undef _CLC_POWN_INTRINSIC
#undef _CLC_POWN_DECL
#undef _CLC_VECTOR_POWN_DECL