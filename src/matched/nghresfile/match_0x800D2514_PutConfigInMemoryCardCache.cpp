/* PutConfigInMemoryCardCache(char *, unsigned int) - 0x800D2514 (72 bytes) */

struct MemoryCardCache {
    int PutConfig(char *, unsigned int);
};

struct NghResFile {
    MemoryCardCache *GetMemoryCardCache(void);
};

namespace Globs {
    extern NghResFile *pNghResFile;
}

int PutConfigInMemoryCardCache(char *name, unsigned int size)
{
    return Globs::pNghResFile->GetMemoryCardCache()->PutConfig(name, size) == 0;
}
