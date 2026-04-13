/* NghResFile::GetByName(int, StringBuffer &, void (*)(void *, int)) - 0x800D3CC8 (8 bytes) */

struct StringBuffer;

struct NghResFile {
    int GetByName(int, StringBuffer &, void (*)(void *, int));
};

int NghResFile::GetByName(int, StringBuffer &, void (*)(void *, int)) {
    return 0;
}
