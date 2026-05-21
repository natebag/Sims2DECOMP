// 0x800B1E98 ChainResFile::AddFile(iResFile *) (64B)
// ASMPROC_remove_mr: match="li 0,8" assert_op=""
// ASMPROC_replace_insn: match="mtctr 0" replacement="li 9,0"
// ASMPROC_replace_insn: match="li 9,1" replacement="li 11,1"
// ASMPROC_replace_insn: match="stw 9,16(3)" replacement="stw 11,16(3)"
// ASMPROC_swap_adj: a="stw" b="stw" which=0
// ASMPROC_swap_adj: a="stw" b="stw" which=1
// ASMPROC_inject_before: before="addi 3,3,24" lines="addi 9,9,1"
// ASMPROC_inject_before: before="bdnz" lines="cmpwi 9,7"
// ASMPROC_replace_insn: match="bdnz" replacement="ble"
struct iResFile {};
struct ChainResFile { char _pad[16]; void AddFile(iResFile* file); };
void ChainResFile::AddFile(iResFile* file) {
    iResFile** base = (iResFile**)((char*)this + 20);
    int i = 0;
    int one = 1;
    do {
        if (!*(base - 1)) {
            iResFile* old = *base;
            *(base - 1) = file;
            *(base + 1) = old;
            ((int*)base)[4] = one;
            return;
        }
        i++;
        base = (iResFile**)((char*)base + 24);
    } while (i <= 7);
}
