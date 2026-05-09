// RelMatrixImpl::GetNthKey(int) @ 0x801354D4 (56B)
// SN allocates r9=idx, r4=m_begin; DOL keeps r4=idx, r11=m_begin
// ASMPROC_replace_insn: match="mr. 9,4" replacement="mr. 4,4"
// ASMPROC_replace_insn: match="lwz 4,4(3)" replacement="lwz 11,4(3)"
// ASMPROC_replace_insn: match="subf 0,4,0" replacement="subf 0,11,0"
// ASMPROC_replace_insn: match="cmplw 0,9,0" replacement="cmplw 0,4,0"
// ASMPROC_replace_insn: match="slwi 9,9,2" replacement="slwi 9,4,2"
// ASMPROC_replace_insn: match="lwzx 11,9,4" replacement="lwzx 11,11,9"

struct KeyNode_GNK {
    int _p0, _p1, _p2, _p3;
    int m_key;  // offset 16
};

struct KeyEntry_GNK {
    KeyNode_GNK* ptr;
};

struct RMI_GNK {
    char _vt[4];
    KeyEntry_GNK* m_begin;
    KeyEntry_GNK* m_end;
    int GetNthKey(int idx);
};

int RMI_GNK::GetNthKey(int idx) {
    if (idx >= 0) {
        int count = m_end - m_begin;
        if ((unsigned int)idx < (unsigned int)count) {
            return m_begin[idx].ptr->m_key;
        }
    }
    return 0;
}
