#ifndef CTGFILEIMPL_H
#define CTGFILEIMPL_H

#include "types.h"

// CTGFileImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x114 (276 bytes)
// 2 known fields (2 named), 46 methods

class CTGFileImpl {
public:
    // Constructors / Destructors
    CTGFileImpl(void *, int, int, bool)  // 0x801835B0
    ~CTGFileImpl(void);  // 0x80183620

    // Methods
    void FlushCache(void);  // 0x80183C1C (40B)
    /* ? */ GetSize(void);  // 0x80183690 (212B)
    bool IsWritable(void);  // 0x80183764 (40B)
    void Read(void *, int);  // 0x8018378C (204B)
    void Write(void *, int);  // 0x80183858 (148B)
    void Seek(int);  // 0x801838EC (172B)
    void SeekPastEnd(int);  // 0x80183998 (172B)
    void Tell(void);  // 0x80183A44 (176B)
    void SetSize(int);  // 0x80183AF4 (144B)
    void Flush(void);  // 0x80183B84 (152B)
    void ReadBytes(unsigned char *, int);  // 0x80183C44 (136B)
    void WriteBytes(unsigned char *, int);  // 0x80183CCC (232B)
    void ReadByte(unsigned char *);  // 0x80183DB4 (116B)
    void WriteByte(unsigned char);  // 0x80183E28 (124B)
    void ReadInteger(int *);  // 0x80183EA4 (116B)
    void WriteInteger(int);  // 0x80183F18 (116B)
    void ReadFloat(float *);  // 0x80183F8C (116B)
    void WriteFloat(float);  // 0x80184000 (116B)
    void ReadString(char *, int);  // 0x80184074 (620B)
    void WriteString(char *);  // 0x801842E0 (668B)
    /* ? */ GetName(void);  // 0x80184BA0 (72B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CTGFileImpl, ReadBytes, ReadString, ...)
    u8 _pad_004[0x10C];  // 0x004
    u32 m_size;  // 0x110 [R/W] (CTGFileImpl, GetSize, ~CTGFileImpl)
};

#endif // CTGFILEIMPL_H
