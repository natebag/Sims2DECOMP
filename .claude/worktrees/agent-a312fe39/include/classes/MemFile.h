#ifndef MEMFILE_H
#define MEMFILE_H

#include "types.h"

// MemFile - struct layout extracted from assembly analysis
// Estimated minimum size: 0x128 (296 bytes)
// 8 known fields (3 named), 34 methods

class MemFile {
public:
    // Constructors / Destructors
    MemFile(void)  // 0x80201FB0
    ~MemFile(void);  // 0x8020202C

    // Methods
    void WriteBlock(void *, int *);  // 0x80201B50 (472B)
    void ValidFile(void);  // 0x802024C4 (60B)
    /* ? */ GetFileSize(int *);  // 0x80201D28 (100B)
    void SetFileSize(int);  // 0x80201D8C (164B)
    void Create(StringBuffer &);  // 0x80201E30 (192B)
    void Delete(StringBuffer &);  // 0x80201EF0 (192B)
    void Close(void);  // 0x80202244 (276B)
    void Open(StringBuffer &);  // 0x8020209C (424B)
    void Flush(void);  // 0x80202500 (436B)
    void ReadBlock(void *, int *);  // 0x80202358 (248B)
    void SetPos(int);  // 0x80202450 (116B)
    /* ? */ GetFileName(StringBuffer &);  // 0x802026B4 (120B)
    void SetFileName(StringBuffer &);  // 0x8020272C (84B)
    void Read1(signed char *);  // 0x80202780 (100B)
    void Writable(void);  // 0x802027E4 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (Flush)
    u8 _pad_004[0x108];  // 0x004
    u32 m_fileSize;  // 0x10C [R/W] (Close, Flush, MemFile, ...)
    u32 m_field_110;  // 0x110 [R/W] (Close, Flush, MemFile, ...)
    u32 m_field_114;  // 0x114 [R/W] (Close, Flush, MemFile, ...)
    u32 m_field_118;  // 0x118 [R/W] (MemFile, Open, WriteBlock)
    u32 m_pos;  // 0x11C [R/W] (MemFile, Open, ReadBlock, ...)
    u32 m_fileSize_120;  // 0x120 [R/W] (Flush, GetFileSize, MemFile, ...)
    u32 m_field_124;  // 0x124 [W] (MemFile, ~MemFile)
};

#endif // MEMFILE_H
