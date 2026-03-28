/* GetMemoryCardCacheSectionSize(unsigned int) - 0x800D26A0 (64 bytes) */

struct NghLayout;
extern NghLayout s_nghLayout;

struct MemoryCardCache {
    int GetSubSectionMemoryUsage(NghLayout *, int);
};

struct NghResFile {
    MemoryCardCache *GetMemoryCardCache(void);
};

namespace Globs {
    extern NghResFile *pNghResFile;
}

int GetMemoryCardCacheSectionSize(unsigned int section)
{
    return Globs::pNghResFile->GetMemoryCardCache()->GetSubSectionMemoryUsage(&s_nghLayout, section);
}
