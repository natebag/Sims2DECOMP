// 0x800BE834 IFFResFile2::Reopen(void) (152B)
// ASMPROC_gpr_relabel: swap="29:31"
// ASMPROC_replace_insn: match="addi 4,1,16" replacement="addi 4,31,8"
// ASMPROC_swap_adj: a=addi b=lwz which=first
// ASMPROC_swap_adj: a=mr b=li which=first

class iResFile {
public:
    int m_0, m_4, m_8;
    void SetError(int);
    int GetError();
};

class StringBuffer { public: int m_dummy; };

extern "C" void __ct__12StringBufferFPcUi(StringBuffer*, char*, unsigned int);
extern "C" void append__12StringBufferFR12StringBufferi(StringBuffer*, StringBuffer&, int);
extern "C" int length__C12StringBuffer(StringBuffer*);

class IFFResFile2 : public iResFile {
public:
    char m_padC[316-12];
    int m_13C;                // 316
    char m_pad140[332-320];
    StringBuffer* m_14C_savedSb;  // 332
    int Reopen();
};

int IFFResFile2::Reopen() {
    char rawBuf[268];
    StringBuffer* sb = (StringBuffer*)rawBuf;
    StringBuffer* saved = m_14C_savedSb;
    __ct__12StringBufferFPcUi(sb, rawBuf + 8, 260);
    append__12StringBufferFR12StringBufferi(sb, *saved, -1);
    delete m_14C_savedSb;
    m_14C_savedSb = 0;
    if (length__C12StringBuffer(sb) == 0) return -50;
    char* obj = (char*)this;
    char* vt = *(char**)(obj + 12);
    short adj = *(short*)(vt + 40);
    int (*fn)(void*, StringBuffer&) = *(int (**)(void*, StringBuffer&))(vt + 44);
    int rc = fn(obj + adj, *sb);
    m_13C = 0;
    return rc;
}
