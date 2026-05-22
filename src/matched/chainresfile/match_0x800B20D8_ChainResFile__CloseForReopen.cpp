// 0x800B20D8 ChainResFile::CloseForReopen(void) (148B)
// ASMPROC_replace_insn: match="lwz 0,16(30)" replacement="addi 3,30,16"
// ASMPROC_replace_insn: match="addi 30,30,16" replacement="lwzx 0,3,29"
// ASMPROC_inject_before: before=".L9:" lines="mr 30,3"

struct iResFile {
    char _pad[12];
};

struct ChainResFile {
    char _pad[16];
    void SetError(int err);
    int CloseForReopen();
};

int ChainResFile::CloseForReopen() {
    int result = 0;
    this->SetError(0);
    int i = 0;
    char* p = (char*)this + 16;
    if (*(iResFile**)p) {
        do {
            iResFile* f = *(iResFile**)p;
            char* vt = *(char**)((char*)f + 12);
            short adj = *(short*)(vt + 48);
            int (*fn)(void*) = (int(*)(void*))*(void**)(vt + 52);
            int r = fn((char*)f + adj);
            if (r) result = r;
            i++;
            p += 24;
            if (i > 7) break;
        } while (*(iResFile**)p);
    }
    return result;
}
