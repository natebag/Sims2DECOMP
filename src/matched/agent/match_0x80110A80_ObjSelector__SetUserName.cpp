// 0x80110A80 ObjSelector::SetUserName(BString2 &) (92B)
//
// 2-INSTANCE PAIR with SetUserLastName @ 0x80110B58 (identical recipe,
// only differs in field offset 132 vs 136).
//
// Pattern: lazy-init BString2 ptr — if m_field == 0, allocate via MainHeap +
// EAHeap::Malloc + BString2::BString2(), then op_assign(*m_field, name).
//
// KEY RECIPE: Declare BString2_ctor as returning `void*` (instead of `void`).
// GCC then knows the function preserves r3 (the input pointer = return value),
// uses the return value directly via `stw r3, 132(r31)` instead of saving
// the malloc result to a callee-saved register (r30) before the ctor call.
// Without this, GCC saves 3 callee-saved regs (r29/r30/r31) and uses a 24B
// stack frame; with it, only 2 (r30/r31) and a 16B frame — matching DOL.
//
// NEW PATTERN: "ctor-returns-this hint" — pure source-only, no mutator.
// Generalizable to any pattern where DOL chains `malloc → ctor → store`
// without intermediate register save.

class BString2;
extern "C" void* MainHeap();
extern "C" void* EAHeap_Malloc(void* heap, unsigned int sz, int flag);
extern "C" void* BString2_ctor(void* p);  // returns p (this) — key declaration
extern "C" void BString2_op_assign(void* p, BString2& other);

class ObjSelector {
public:
    void SetUserName(BString2& name);
};

void ObjSelector::SetUserName(BString2& name) {
    void* p = *(void**)((char*)this + 132);
    if (p == 0) {
        void* heap = MainHeap();
        void* mem = EAHeap_Malloc(heap, 4, 0);
        *(void**)((char*)this + 132) = BString2_ctor(mem);
    }
    BString2_op_assign(*(void**)((char*)this + 132), name);
}
