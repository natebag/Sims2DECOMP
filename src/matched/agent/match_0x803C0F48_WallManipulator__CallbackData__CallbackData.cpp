// 0x803C0F48 (88B) InteractorModule::WallManipulator::CallbackData::CallbackData(void)
// Phantom 32B stack frame: volatile int _dummy[6] forces stwu r1,-32(r1) without LR save.
// VPtr at this+8 via explicit void* member (Cfront ABI places vptr at END with virtual keyword,
// so use explicit member like DirectInteractor does).
// 5-pointer interleave: pA(0x1c) pB(0x24) pC(0x2c) pD(0x34) pE(0x3c) scheduler-woven.
// GCC CSE-eliminates pA (single-use pointer); ASMPROC 13-directive recipe:
//   Steps 1-3: Replace pB slot with pA, re-insert pB (r8) before pC.
//   Steps 4-10: Fix pA direct store, swap pC/field18, swap pD/pAstore, swap pE/subBf0.
//   Steps 11-13: Rename pointer stores (pD r8→r6, pB r7→r8, pC r10→r7).
// ASMPROC_replace_insn: match="addi 7,9,36" replacement="addi 10,9,28"
// ASMPROC_nop_before: match="addi 10,9,44" occurrence=0
// ASMPROC_replace_insn: match="nop" replacement="addi 8,9,36"
// ASMPROC_replace_insn: match="stw 0,32(9)" replacement="stw 0,4(10)"
// ASMPROC_replace_insn: match="addi 10,9,44" replacement="stw 0,24(9)"
// ASMPROC_replace_insn: match="stw 0,24(9)" replacement="addi 7,9,44" occurrence=1
// ASMPROC_replace_insn: match="addi 8,9,52" replacement="stw 0,4(10)"
// ASMPROC_replace_insn: match="stw 0,4(10)" replacement="addi 6,9,52" occurrence=1
// ASMPROC_replace_insn: match="addi 11,9,60" replacement="stw 0,36(9)"
// ASMPROC_replace_insn: match="stw 0,36(9)" replacement="addi 11,9,60" occurrence=1
// ASMPROC_replace_insn: match="stw 0,4(8)" replacement="stw 0,4(6)"
// ASMPROC_replace_insn: match="stw 0,4(7)" replacement="stw 0,4(8)"
// ASMPROC_replace_insn: match="stw 0,4(10)" replacement="stw 0,4(7)" occurrence=1

namespace InteractorModule {
namespace WallManipulator {

struct CBD_Base {
    int m_a;
    int m_b;
};

struct CBD_SubPair {
    int field_0;
    int field_4;
};

class CallbackData : public CBD_Base {
public:
    void*        m_vt;       // +8 (vtable pointer, explicit)
    int          m_fieldC;   // +0xC
    int          m_field10;  // +0x10
    int          m_field14;  // +0x14
    int          m_field18;  // +0x18
    CBD_SubPair  m_subA;     // +0x1C
    CBD_SubPair  m_subB;     // +0x24
    CBD_SubPair  m_subC;     // +0x2C
    CBD_SubPair  m_subD;     // +0x34
    CBD_SubPair  m_subE;     // +0x3C

    CallbackData();
};

extern char vt_WallManipulatorCallbackData[];

CallbackData::CallbackData() {
    volatile int _dummy[6];
    m_vt = vt_WallManipulatorCallbackData;
    CBD_SubPair* pA = &m_subA;
    m_field14 = 0;
    CBD_SubPair* pB = &m_subB;
    m_field18 = 0;
    CBD_SubPair* pC = &m_subC;
    pA->field_4 = 0;
    CBD_SubPair* pD = &m_subD;
    m_subB.field_0 = 0;
    CBD_SubPair* pE = &m_subE;
    pB->field_4 = 0;
    pC->field_4 = 0;
    m_subD.field_0 = 0;
    pD->field_4 = 0;
    pE->field_4 = 0;
}

} // namespace WallManipulator
} // namespace InteractorModule
