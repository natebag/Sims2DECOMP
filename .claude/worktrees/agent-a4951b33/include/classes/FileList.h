#ifndef FILELIST_H
#define FILELIST_H

#include "types.h"

// FileList - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD (13 bytes)
// 4 known fields (2 named), 11 methods

class FileList {
public:
    // Constructors / Destructors
    FileList(void)  // 0x802D5984
    ~FileList(void);  // 0x802D592C

    // Methods
    void Find(ResFile *);  // 0x801FE118 (156B)
    /* ? */ GetRefCount(ResFile *);  // 0x801FE1B4 (156B)
    void AddRef(iResFile *);  // 0x801FE250 (364B)
    void ReleaseRef(iResFile *);  // 0x801FE3BC (244B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (FileList)
    u32 m_refCount;  // 0x004 [R/W] (AddRef, FileList, Find, ...)
    u32 m_field_008;  // 0x008 [R/W] (AddRef, FileList, ReleaseRef)
    u8 m_field_00C;  // 0x00C [W] (FileList)
};

#endif // FILELIST_H
