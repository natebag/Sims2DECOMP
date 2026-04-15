// 0x800D3CC8 NghResFile::GetByName (8B) — stub returns 0
struct StringBuffer;
struct NghResFile {
    int GetByName(int a, StringBuffer& b, void (*c)(void*, int));
};

int NghResFile::GetByName(int, StringBuffer&, void (*)(void*, int)) { return 0; }
