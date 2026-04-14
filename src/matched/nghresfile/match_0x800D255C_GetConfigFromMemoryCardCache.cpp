/* GetConfigFromMemoryCardCache(char *, unsigned int, int) - 0x800D255C (80 bytes) */

struct MemoryCardCache {
    int GetConfig(char *, unsigned int, int);
};

struct NghResFile {
    MemoryCardCache *GetMemoryCardCache(void);
};

namespace Globs {
    extern NghResFile *pNghResFile;
}

int GetConfigFromMemoryCardCache(char *name, unsigned int size, int flag)
{
    return Globs::pNghResFile->GetMemoryCardCache()->GetConfig(name, size, flag) == 0;
}
