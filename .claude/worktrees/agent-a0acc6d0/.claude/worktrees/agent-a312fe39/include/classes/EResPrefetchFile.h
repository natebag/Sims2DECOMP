#ifndef ERESPREFETCHFILE_H
#define ERESPREFETCHFILE_H

#include "types.h"

// EResPrefetchFile - struct layout extracted from assembly analysis
// Estimated minimum size: 0x44 (68 bytes)
// 8 known fields (7 named), 30 methods

class EResPrefetchFile {
public:
    // Constructors / Destructors
    EResPrefetchFile(void)  // 0x8084C4FC
    ~EResPrefetchFile(void);  // 0x8084C578

    // Methods
    void SetStreamBuffer(EResourceManager *, unsigned int, void *, unsigned int, unsigned int);  // 0x8084D588 (632B)
    void Destroy(void);  // 0x8084C60C (132B)
    void ReadFromBuffer(void *, unsigned int);  // 0x8084C690 (812B)
    void ValidateStreamPos(void);  // 0x8084D800 (80B)
    void Read(void *, unsigned int);  // 0x8084C9BC (1588B)
    void Write(void *, unsigned int);  // 0x8084CFF0 (148B)
    void Flush(void);  // 0x8084D084 (40B)
    /* ? */ GetLastError(void);  // 0x8084D0AC (40B)
    /* ? */ GetSystemHandle(void);  // 0x8084D0D4 (140B)
    void Tell(void);  // 0x8084D160 (44B)
    void Seek(int, EFile::SeekType);  // 0x8084D18C (688B)
    void SetStreamBuffer(EResourceManager *, char *, void *, unsigned int, unsigned int);  // 0x8084D43C (332B)
    /* ? */ GetResMan(void);  // 0x8084D850 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x14];  // 0x000
    u32 m_streamBuffer;  // 0x014 [W] (SetStreamBuffer)
    u8 _pad_018[0x10];  // 0x018
    u32 m_field_028;  // 0x028 [W] (EResPrefetchFile, ~EResPrefetchFile)
    u32 m_streamBuffer_02C;  // 0x02C [R/W] (EResPrefetchFile, Read, SetStreamBuffer, ...)
    u32 m_streamBuffer_030;  // 0x030 [R/W] (EResPrefetchFile, Read, ReadFromBuffer, ...)
    u32 m_streamBuffer_034;  // 0x034 [R/W] (EResPrefetchFile, Read, Seek, ...)
    u32 m_streamBuffer_038;  // 0x038 [R/W] (EResPrefetchFile, Read, Seek, ...)
    u32 m_streamBuffer_03C;  // 0x03C [R/W] (EResPrefetchFile, SetStreamBuffer, ~EResPrefetchFile)
    u32 m_streamBuffer_040;  // 0x040 [R/W] (EResPrefetchFile, Read, ReadFromBuffer, ...)
};

#endif // ERESPREFETCHFILE_H
