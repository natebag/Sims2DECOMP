// 0x80364ED0 ERenderSurface::SetSize(int, int, int) (24B)
//
// 3-field setter that writes pitch, width, height in DOL's specific order
// (pitch first, then width, then height) and returns 1. DOL also emits
// `mr r9, r3` (this-alias) + interleaves `li r3, 1` between pitch and width
// stores. Pure compiler-choice byte wall.
//
// WALL CLASS: store-order + this-alias + interleaved return-value-set
//   1. Store order: DOL writes offset 24 (pitch) FIRST, then 0 (w), then 4 (h).
//      GCC reorders to 4 (h), then 24 (p), then 0 (w). Fixed via volatile-on-all
//      MainGuy-promoted technique 2026-05-21.
//   2. this-alias: DOL emits `mr r9, r3` and uses r9 as the store base for ALL
//      three stores. GCC uses r3 directly. Fixed via new this_alias_rN mutator.
//   3. Return-value position: DOL emits `li r3, 1` BETWEEN the first store and
//      the second store. GCC emits it AFTER all stores. Fixed via 2x
//      swap_adj a=stw b=li which=first (each call shifts the li one position
//      earlier in the store run).
//
// Recipe: 3-directive ASMPROC chain + volatile-on-all source pattern.
//
// **First validating match for this_alias_rN mutator** (S16) — primitive was
// built earlier on Commander/InventoryItem CopyTo but both walls needed
// additional force_reg_at_pos chains beyond the alias. SetSize is the clean
// solo-alias validation that promotes this_alias_rN to 1-INSTANCE-PROVISIONAL.
//
// ASMPROC_this_alias_rN: reg=9 after=".L_fSetSize"
// ASMPROC_swap_adj: a=stw b=li which=first
// ASMPROC_swap_adj: a=stw b=li which=first

class ERenderSurface {
public:
    int SetSize(int w, int h, int p);
};

int ERenderSurface::SetSize(int w, int h, int p) {
    *(volatile int*)((char*)this + 24) = p;
    *(volatile int*)((char*)this + 0) = w;
    *(volatile int*)((char*)this + 4) = h;
    return 1;
}
