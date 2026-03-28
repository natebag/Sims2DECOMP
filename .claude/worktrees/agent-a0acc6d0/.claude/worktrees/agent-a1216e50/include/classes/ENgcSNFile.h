#ifndef ENGCSNFILE_H
#define ENGCSNFILE_H

#include "types.h"

// ENgcSNFile - struct layout extracted from assembly analysis
// Estimated minimum size: 0x40 (64 bytes)
// 10 known fields (0 named), 24 methods

class ENgcSNFile {
public:
    // Constructors / Destructors
    ENgcSNFile(void)  // 0x8077D7AC
    ~ENgcSNFile(void);  // 0x8077D820

    // Methods
    void Creator(EFile *, char *, char *, EFile::DeviceType, EFile::AccessMode, unsigned int);  // 0x8077D898 (604B)
    void Destroy(void);  // 0x8077DAF4 (116B)
    void Read(void *, unsigned int);  // 0x8077DB68 (188B)
    void BufferReadRequest(unsigned char *, int);  // 0x8077DC24 (440B)
    void Write(void *, unsigned int);  // 0x8077DDDC (84B)
    void Seek(int, EFile::SeekType);  // 0x8077DE30 (132B)
    void Tell(void);  // 0x8077DEB4 (44B)
    void Flush(void);  // 0x8077DEE0 (40B)
    /* ? */ GetLastError(void);  // 0x8077DF08 (40B)
    /* ? */ GetSystemHandle(void);  // 0x8077DF30 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [W] (Creator)
    u32 m_field_00C;  // 0x00C [W] (Creator)
    u32 m_field_010;  // 0x010 [W] (Creator)
    u32 m_field_014;  // 0x014 [R/W] (BufferReadRequest, Creator, Seek)
    u8 _pad_018[0x10];  // 0x018
    u32 m_field_028;  // 0x028 [R/W] (Creator, Destroy, ENgcSNFile, ...)
    u32 m_field_02C;  // 0x02C [R/W] (BufferReadRequest, Creator, Destroy)
    u32 m_field_030;  // 0x030 [R/W] (BufferReadRequest, Creator, Seek)
    u32 m_field_034;  // 0x034 [R/W] (BufferReadRequest, ENgcSNFile, ~ENgcSNFile)
    u32 m_field_038;  // 0x038 [R/W] (BufferReadRequest, Creator)
    u32 m_field_03C;  // 0x03C [R/W] (BufferReadRequest, Creator, Seek)
};

#endif // ENGCSNFILE_H
