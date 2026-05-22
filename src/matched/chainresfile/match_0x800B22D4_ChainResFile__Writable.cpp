// 0x800B22D4 ChainResFile::Writable(void) (148B)
// ASMPROC_replace_insn: match="stwu 1,-24(1)" replacement="stwu 1,-16(1)"
// ASMPROC_replace_insn: match="stmw 29,12(1)" replacement="stmw 30,8(1)"
// ASMPROC_replace_insn: match="stw 0,28(1)" replacement="stw 0,20(1)"
// ASMPROC_replace_insn: match="li 29,0" replacement="li 31,0"
// ASMPROC_replace_insn: match="addi 31,30,16" replacement="addi 3,30,16"
// ASMPROC_replace_insn: match="lwz 0,16(30)" replacement="lwzx 0,3,31"
// ASMPROC_inject_before: before=".L9:" lines="mr 30,3"
// ASMPROC_replace_insn: match="lwz 3,0(31)" replacement="lwz 3,0(30)"
// ASMPROC_replace_insn: match="addi 29,29,1" replacement="addi 31,31,1"
// ASMPROC_replace_insn: match="addi 31,31,24" replacement="addi 30,30,24"
// ASMPROC_replace_insn: match="cmpwi 0,29,7" replacement="cmpwi 0,31,7"
// ASMPROC_replace_insn: match="lwz 0,0(31)" replacement="lwz 0,0(30)"
// ASMPROC_replace_insn: match="lmw 29,12(1)" replacement="lmw 30,8(1)"
// ASMPROC_replace_insn: match="lwz 0,28(1)" replacement="lwz 0,20(1)"
// ASMPROC_replace_insn: match="la 1,24(1)" replacement="la 1,16(1)"

struct iResFile {
    char _pad[12];
};

struct ChainResFile {
    char _pad[16];
    void SetError(int err);
    int Writable();
};

int ChainResFile::Writable() {
    int i = 0;
    this->SetError(0);
    char* p = (char*)this + 16;
    if (*(iResFile**)p) {
        do {
            iResFile* f = *(iResFile**)p;
            char* vt = *(char**)((char*)f + 12);
            short adj = *(short*)(vt + 80);
            int (*fn)(void*) = (int(*)(void*))*(void**)(vt + 84);
            int r = fn((char*)f + adj);
            if (r) return 1;
            i++;
            p += 24;
            if (i > 7) break;
        } while (*(iResFile**)p);
    }
    return 0;
}
