/* SaveAllMemoryCardCache(int) - 0x800D25AC (64 bytes) */

struct MemoryCardCache {
    int SaveAllToMemoryCard(int);
};

struct NghResFile {
    MemoryCardCache *GetMemoryCardCache(void);
};

namespace Globs {
    extern NghResFile *pNghResFile;
}

int SaveAllMemoryCardCache(int slot)
{
    return Globs::pNghResFile->GetMemoryCardCache()->SaveAllToMemoryCard(slot) == 0;
}
