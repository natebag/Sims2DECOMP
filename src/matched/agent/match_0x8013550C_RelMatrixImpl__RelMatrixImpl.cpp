// RelMatrixImpl::RelMatrixImpl(void) @ 0x8013550C (48B)
// ASMPROC_nop_before: match="lis 9,"
// ASMPROC_replace_insn: match="nop" replacement="stwu 1,-16(1)"
// ASMPROC_replace_insn: match="stw 0,16(11)" replacement="addi 10,11,12"
// ASMPROC_nop_before: match="blr"
// ASMPROC_replace_insn: match="nop" replacement="stw 0,4(10)"
// ASMPROC_nop_before: match="blr"
// ASMPROC_replace_insn: match="nop" replacement="addi 1,1,16"

struct RelMatrix_RMI {
    virtual ~RelMatrix_RMI();
    virtual void Init();
    virtual void CopyTo(void* dst);
    virtual int GetArraySize(int key);
    virtual int SetArraySize(int key, int size);
    virtual int RemoveArray(int key);
    virtual void Clear();
    virtual int GetValue(int key, int idx);
    virtual int SetValue(int key, int idx, int val);
    virtual void DoStream(void* buf, int mode);
    virtual int CountKeys();
    virtual int GetNthKey(int idx);
};

struct RelMatrixImpl_c : public RelMatrix_RMI {
    int m_a;
    int m_b;
    int m_c;
    int m_d;
    RelMatrixImpl_c();
};

RelMatrixImpl_c::RelMatrixImpl_c() {
    m_a = 0;
    m_b = 0;
    m_d = 0;
}
