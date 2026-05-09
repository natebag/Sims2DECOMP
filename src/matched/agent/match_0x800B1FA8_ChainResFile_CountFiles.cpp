// 0x800B1FA8 (60B) ChainResFile::CountFiles(void)
// Count non-null entries (stride 24B) starting at this+16, max 8 entries.
// Loop counter `n` separate from short return `idx` (extsh at end).

class iResFile;

struct ChainResFile {
    char _pad[16];
    iResFile* m_files[8];
    short CountFiles();
};

short ChainResFile::CountFiles()
{
    char* p = (char*)this + 16;
    int idx = 0;
    int n = 0;
    if (*(iResFile**)(p + idx) != 0) {
        do {
            n++;
            idx++;
            if (n > 7) break;
            p += 24;
        } while (*(iResFile**)p != 0);
    }
    return (short)idx;
}
