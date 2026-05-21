// 0x80111004 ObjSelector::DestroyThumbnail(void) (80B)
//
// Pattern: load pointer; if null return; double-load (lhz + lha at same
// offset for sign-extension comparison); if zero return; call helper;
// clear pointer.
//
// Recipe: volatile-cast on the unsigned-short read forces the lhz emission
// (otherwise GCC CSE's it with the signed lha read). Then swap_adj to
// reorder lhz/lha pair to match DOL's lhz-before-lha order.
//
// ASMPROC_swap_adj: a=lha b=lhz which=first

extern "C" void helper_0x80311F70(void* p);

class ObjSelector {
public:
    void DestroyThumbnail();
};

void ObjSelector::DestroyThumbnail() {
    void* p = *(void**)((char*)this + 148);
    if (p == 0) return;
    unsigned short u = *(volatile unsigned short*)((char*)p + 12);
    (void)u;
    if (*(short*)((char*)p + 12) == 0) return;
    helper_0x80311F70(p);
    *(void**)((char*)this + 148) = 0;
}
