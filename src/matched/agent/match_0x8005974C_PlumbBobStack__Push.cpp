// 0x8005974C (76B) PlumbBobStack::Push(PlumbBob*)
// Stack of up to 4 PlumbBob snapshots; each slot 16B at this+count*16+4.
// bgtlr if count>3; indexed stwx for slot[0] keeps r9 alive; double-load m_count++ at end.
// srcbase = src+296 as intermediate base for field300/304 (addi r7,r4,296).
// GCC scheduler reverses field300/304 load pair; ASMPROC swaps 4(r7)/8(r7) and 4(r11)/8(r11).
// ASMPROC_replace_insn: match="lwz 10,4(7)" replacement="lwz 10,8(7)"
// ASMPROC_replace_insn: match="lwz 8,8(7)" replacement="lwz 8,4(7)"
// ASMPROC_replace_insn: match="stw 10,4(11)" replacement="stw 10,8(11)"
// ASMPROC_replace_insn: match="stw 8,8(11)" replacement="stw 8,4(11)"

struct PlumbBob_PS {
    char _pad[296];
    int m_field296;
    int m_field300;
    int m_field304;
    char _pad2[56];
    int m_field364;
};

struct PlumbBobStack_PS {
    int m_count;
    void Push(PlumbBob_PS* src);
};

void PlumbBobStack_PS::Push(PlumbBob_PS* src) {
    if (m_count > 3) return;
    int idx = m_count * 16 + 4;
    int field364 = src->m_field364;
    int* srcbase = &src->m_field296;
    int* slot = (int*)((char*)this + idx);
    slot[3] = field364;
    int field296 = src->m_field296;
    int field304 = srcbase[2];
    int field300 = srcbase[1];
    slot[0] = field296;
    slot[2] = field304;
    slot[1] = field300;
    m_count++;
}
