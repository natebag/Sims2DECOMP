// 0x802C6048 (68B) EFile::EFile(void)
// ASMPROC_replace_insn: match="stw 10,8(9)" replacement="stw 10,12(9)"
// ASMPROC_replace_insn: match="stw 0,4(9)" replacement="stw 10,8(9)"
// ASMPROC_replace_insn: match="stw 0,0(9)" replacement="stw 0,4(9)"
// ASMPROC_replace_insn: match="stw 10,16(9)" replacement="stw 0,0(9)"
// ASMPROC_replace_insn: match="stw 10,12(9)" replacement="stw 10,16(9)"
// ASMPROC_replace_insn: match="stb 0,36(9)" replacement="stb 0,24(9)"
// ASMPROC_replace_insn: match="stb 0,24(9)" replacement="stb 0,36(9)"
extern int __vt__5EFile[];
struct EFile {
    int m_0; int m_4; int m_8; int m_C; int m_10; int m_14;
    char m_18; int m_1C; int m_20; char m_24; int* m_28;
    EFile();
};
EFile::EFile() {
    m_10 = (int)0x80000000;
    m_28 = __vt__5EFile;
    m_0 = 0;
    m_4 = 0;
    m_8 = (int)0x80000000;
    m_C = (int)0x80000000;
    m_14 = 0;
    m_1C = 0;
    m_20 = 0;
    m_24 = 0;
    m_18 = 0;
}
