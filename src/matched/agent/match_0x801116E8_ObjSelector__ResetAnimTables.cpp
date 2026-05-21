// 0x801116E8 ObjSelector::ResetAnimTables(void) (92B)
//
// 4-iteration loop zeroing m_64+i*4 slot if non-null. Wall class: lwzx/stwx
// commutative base/index swap (same as ERTQuantize::FreeNode @ 0x802CFDCC).
//
// Recipe: 2 swap_operands (one each for lwzx and stwx).
//
// ASMPROC_swap_operands: match="lwzx 0,31,29" pos=1,2
// ASMPROC_swap_operands: match="stwx 28,31,29" pos=1,2

extern "C" void helper_0x800AAAAC(void* p);

class ObjSelector {
public:
    void ResetAnimTables();
};

void ObjSelector::ResetAnimTables() {
    void** arr = (void**)((char*)this + 64);
    for (short i = 0; i <= 3; i++) {
        void* p = arr[i];
        if (p != 0) {
            helper_0x800AAAAC(p);
            arr[i] = 0;
        }
    }
}
