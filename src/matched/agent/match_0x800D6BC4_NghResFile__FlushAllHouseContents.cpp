// 0x800D6BC4 NghResFile::FlushAllHouseContents(void) (68B)
// ASMPROC_gpr_relabel: swap=30:31 skip_opcodes=stmw,lmw

class NghResFile {
public:
    void FlushHouseContents(unsigned int idx);
    void FlushAllHouseContents();
};

void NghResFile::FlushAllHouseContents() {
    int i = 0;
loop:
    i++;
    FlushHouseContents(i);
    if (i <= 15) goto loop;
}
