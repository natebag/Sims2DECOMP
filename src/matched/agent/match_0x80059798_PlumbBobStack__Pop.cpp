// 0x80059798 (72B) PlumbBobStack::Pop(PlumbBob*)
// Symmetric inverse of Push: copy top slot to dst, decrement count.
// m_count stored early (before slot loads); lwzx for slot[0] via r3+r9;
// dstbase=dst+296 (addi r8,r4,296) for field300/304 stores.
// GCC uses r7 for dstbase; DOL uses r8. Also r8/r0 for slot[2]/slot[1] reversed.
// region_gpr_relabel from after lwzx: r0→r9, r8→r0, r7→r8.
// Then swap final two stws (4(r8)/8(r8) ordering).
// ASMPROC_replace_insn: match="addi 7,4,296" replacement="addi 8,4,296"
// ASMPROC_region_gpr_relabel: start_anchor="lwzx 10,3,9" start_mode=after end_anchor="blr" end_mode=before rename="0:9,8:0,7:8" unsafe_clobber=true
// ASMPROC_replace_insn: match="stw 9, 4(8)" replacement="stw 0, 8(8)"
// ASMPROC_replace_insn: match="stw 0, 8(8)" replacement="stw 9, 4(8)" occurrence=1

struct PlumbBob_PP {
    char _pad[296];
    int m_field296;
    int m_field300;
    int m_field304;
    char _pad2[56];
    int m_field364;
};

struct PlumbBobStack_PP {
    int m_count;
    void Pop(PlumbBob_PP* dst);
};

void PlumbBobStack_PP::Pop(PlumbBob_PP* dst) {
    int count = m_count;
    if (count == 0) return;
    int newCount = count - 1;
    int* dstbase = (int*)((char*)dst + 296);
    int idx = newCount * 16 + 4;
    m_count = newCount;
    int* slot = (int*)((char*)this + idx);
    dst->m_field364 = slot[3];
    int f0 = slot[0];
    int f1 = slot[1];
    int f2 = slot[2];
    dst->m_field296 = f0;
    dstbase[2] = f2;
    dstbase[1] = f1;
}
