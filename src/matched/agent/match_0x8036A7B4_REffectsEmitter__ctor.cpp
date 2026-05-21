// 0x8036A7B4 REffectsEmitter::REffectsEmitter(void) (80B)
//
// EResource-derived ctor: parent ctor + vtable + 4 zeroed fields.
//
// WALL CLASS: volatile-void**-doesn't-order-with-int-stores + prologue insn-order.
//   When the source uses `*(volatile void**)((char*)this+0) = vt`, GCC 2.95
//   does NOT order this with `*(volatile int*)` stores at other offsets —
//   different pointer types break the volatile-ordering chain. The vt store
//   gets reordered to late position. UNIFORM `*(volatile int*)` for ALL
//   stores (cast the vtable pointer to int) keeps volatile ordering intact.
//
// Recipe: uniform volatile-int-cast source + 2 swap_adj prologue reorder.
//
// ASMPROC_swap_adj: a=li b=lis which=first
// ASMPROC_swap_adj: a=stw b=la which=first

extern char REffectsEmitter_vt[];

class EResource {
public:
    EResource();
};

class REffectsEmitter : public EResource {
public:
    REffectsEmitter();
};

REffectsEmitter::REffectsEmitter() {
    *(volatile int*)((char*)this + 32) = 0;
    *(volatile int*)((char*)this + 0)  = (int)REffectsEmitter_vt;
    *(volatile int*)((char*)this + 20) = 0;
    *(volatile int*)((char*)this + 24) = 0;
    *(volatile int*)((char*)this + 28) = 0;
}
