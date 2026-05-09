// EBitArray::operator==(EBitArray&) const - 0x802DFE0C (140B)
// DOL does: lwz r10=this->buf, addi r11=i, lwz r4=other->buf, cmpwi count
// GCC does: cmpwi count, lwz r4=other->buf, lwz r11=this->buf, addi r3=i
// 8 replace_insn directives fix both ordering and register allocation
// ASMPROC_replace_insn: match="cmpwi 0,3,0" replacement="lwz 10,0(31)" occurrence=0
// ASMPROC_replace_insn: match="cmpwi 0,3,0" replacement="cmpwi 0,11,0"
// ASMPROC_replace_insn: match="lwz 4,0(30)" replacement="addi 11,3,-1"
// ASMPROC_replace_insn: match="lwz 11,0(31)" replacement="lwz 4,0(30)"
// ASMPROC_replace_insn: match="addi 3,3,-1" replacement="cmpwi 0,3,0" occurrence=0
// ASMPROC_replace_insn: match="lwz 9,0(11)" replacement="lwz 9,0(10)"
// ASMPROC_replace_insn: match="addi 11,11,4" replacement="addi 10,10,4"
// ASMPROC_replace_insn: match="addi 3,3,-1" replacement="addi 11,11,-1"

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    int GetElementCount() const;
    bool operator==(EBitArray& other) const;
};

bool EBitArray::operator==(EBitArray& other) const {
    if (m_nSize != other.m_nSize) return false;
    int count = GetElementCount();
    int* src = other.m_pBuffer;
    int i = count - 1;
    int* dst = m_pBuffer;
    if (count == 0) goto done;
    do {
        if (*dst++ != *src++) return false;
    } while (i-- != 0);
done:
    return true;
}
