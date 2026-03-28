#ifndef ENGCFILE_H
#define ENGCFILE_H

#include "types.h"

// ENgcFile - struct layout extracted from assembly analysis
// Estimated minimum size: 0x78 (120 bytes)
// 10 known fields (0 named), 24 methods

class ENgcFile {
public:
    // Constructors / Destructors
    ENgcFile(void)  // 0x80798728
    ~ENgcFile(void);  // 0x8079879C

    // Methods
    void Creator(EFile *, char *, char *, EFile::DeviceType, EFile::AccessMode, unsigned int);  // 0x80798814 (548B)
    void Destroy(void);  // 0x80798A38 (252B)
    void Read(void *, unsigned int);  // 0x80798B34 (272B)
    void BufferReadRequest(unsigned char *, int);  // 0x80798C44 (340B)
    void Write(void *, unsigned int);  // 0x80798D98 (148B)
    void Seek(int, EFile::SeekType);  // 0x80798E2C (372B)
    void Tell(void);  // 0x80798FA0 (44B)
    void Flush(void);  // 0x80798FCC (40B)
    /* ? */ GetLastError(void);  // 0x80798FF4 (40B)
    /* ? */ GetSystemHandle(void);  // 0x8079901C (44B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [W] (Creator)
    u32 m_field_00C;  // 0x00C [W] (Creator)
    u32 m_field_010;  // 0x010 [W] (Creator)
    u32 m_field_014;  // 0x014 [W] (Creator)
    u8 _pad_018[0x10];  // 0x018
    u32 m_field_028;  // 0x028 [R/W] (Creator, Destroy, ENgcFile, ...)
    u8 _pad_02C[0x34];  // 0x02C
    u32 m_field_060;  // 0x060 [R] (BufferReadRequest, Creator, Seek)
    u8 _pad_064[4];  // 0x064
    u32 m_field_068;  // 0x068 [R/W] (BufferReadRequest, Creator, Seek)
    u32 m_field_06C;  // 0x06C [R/W] (BufferReadRequest, ENgcFile, ~ENgcFile)
    u32 m_field_070;  // 0x070 [R/W] (BufferReadRequest, Creator, Seek)
    u32 m_field_074;  // 0x074 [R/W] (BufferReadRequest, Creator, Seek)
};

#endif // ENGCFILE_H
