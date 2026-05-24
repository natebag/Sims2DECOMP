// 0x80132C60 QuickResFile::GetString(StringBuffer&, short, short) const (188B)
// ASMPROC_inject_before: before="cmpwi 0,3,0" lines="	mr 9,3" occurrence=2
// ASMPROC_replace_insn: match="lwz 0,-4(3)" replacement="lwz 0,-4(9)"
// ASMPROC_replace_insn: match="slwi 9,31,2" replacement="addi 9,31,-1"
// ASMPROC_replace_insn: match="add 9,9,3" replacement="slwi 9,9,2"
// ASMPROC_replace_insn: match="lwz 4,-4(9)" replacement="lwzx 4,3,9"

struct QuickResFile {
    void GetString();
};

void QuickResFile::GetString() {
}
