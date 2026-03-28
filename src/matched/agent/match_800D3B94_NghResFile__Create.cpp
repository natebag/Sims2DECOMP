/* NghResFile::Create(StringBuffer &) - 0x800D3B94 (36 bytes) */

struct StringBuffer;

struct NghResFile {
    void reset(void);
    int Create(StringBuffer &);
};

int NghResFile::Create(StringBuffer &) {
    reset();
    return 0;
}
