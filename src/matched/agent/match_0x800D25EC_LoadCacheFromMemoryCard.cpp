/* LoadCacheFromMemoryCard(int) - 0x800D25EC (64 bytes) */

struct MemoryCardCache {
    int LoadCacheFromMemoryCard(int);
};

struct NghResFile {
    MemoryCardCache *GetMemoryCardCache(void);
};

namespace Globs {
    extern NghResFile *pNghResFile;
}

int LoadCacheFromMemoryCard(int slot)
{
    return Globs::pNghResFile->GetMemoryCardCache()->LoadCacheFromMemoryCard(slot) == 0;
}
