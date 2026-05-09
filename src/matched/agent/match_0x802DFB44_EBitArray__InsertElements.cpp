// EBitArray::InsertElements(int, int) - 0x802DFB44 (172B)
// ASMPROC_replace_insn: match="subf. 29,29,30" replacement="subf. 0,29,30"
// ASMPROC_nop_before: match="bc 4,1,.L11"
// ASMPROC_replace_insn: match="nop" replacement="mtctr 0"
// ASMPROC_insert_mr: after="bc 4,1,.L11" src=30 dst=29
// ASMPROC_insert_mr: after="mr 29,30" src=31 dst=30
// ASMPROC_nop_before: match=".L9:"
// ASMPROC_replace_insn: match="nop" replacement="mfctr 31"
// ASMPROC_region_gpr_relabel: start_anchor="mfctr 31" start_mode="after" end_anchor="addic. 29,29,-1" end_mode="at" rename="29:31,30:29,31:30"
// ASMPROC_replace_insn: match="bc 12,1,.L9" replacement="bc 4,2,.L9"

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    void InsertElements(int pos, int count);
    void SetSize(int newSize, int allocSize);
    bool Get(int index) const;
    void Set(int idx, bool value);
};

void EBitArray::InsertElements(int pos, int count) {
    int oldSize = m_nSize;
    int newSize = oldSize + count;
    if (newSize > m_nAllocSize) {
        int allocSize = oldSize + m_field_C;
        if (allocSize < newSize) allocSize = newSize;
        SetSize(newSize, allocSize);
    } else {
        m_nSize = newSize;
    }
    for (int n = oldSize - pos; n > 0; n--) {
        Set(newSize, Get(oldSize));
        oldSize--;
        newSize--;
    }
}
