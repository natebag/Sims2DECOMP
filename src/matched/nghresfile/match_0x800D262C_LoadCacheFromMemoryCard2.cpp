/* LoadCacheFromMemoryCard(NghResFile *, int) - 0x800D262C (68 bytes) */

struct NghResFile;

struct MemoryCardCache {
    int LoadCacheFromMemoryCard(int, NghResFile *);
};

struct NghResFile {
    MemoryCardCache *GetMemoryCardCache(void);
};

int LoadCacheFromMemoryCard(NghResFile *ngh, int slot)
{
    return ngh->GetMemoryCardCache()->LoadCacheFromMemoryCard(slot, ngh) == 0;
}
