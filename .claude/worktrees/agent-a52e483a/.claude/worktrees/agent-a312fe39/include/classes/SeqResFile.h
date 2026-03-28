#ifndef SEQRESFILE_H
#define SEQRESFILE_H

#include "types.h"

// SeqResFile - struct layout extracted from assembly analysis
// Estimated minimum size: 0x138 (312 bytes)
// 3 known fields (1 named), 26 methods

class SeqResFile {
public:
    // Constructors / Destructors
    SeqResFile(void)  // 0x803B1710
    ~SeqResFile(void);  // 0x803B05C0

    // Methods
    void ClearOpenSpecs(void);  // 0x803B03BC (40B)
    void AddOpenSpec(int, char *);  // 0x803B03E4 (476B)
    void Create(StringBuffer &);  // 0x803B0DD0 (544B)
    void Delete(StringBuffer &);  // 0x803B0FF0 (288B)
    void Close(void);  // 0x803B12CC (324B)
    /* ? */ GetFileName(StringBuffer &);  // 0x803B1410 (228B)
    void CreateIResFile(iResFile *, StringBuffer &, int, int &, StackString<32> **);  // 0x803B0720 (564B)
    void OpenIResFile(iResFile *, StringBuffer &, int, bool &);  // 0x803B0954 (632B)
    void DeleteIResFile(iResFile *, StringBuffer &, int);  // 0x803B0BCC (516B)
    void Open(StringBuffer &);  // 0x803B1110 (444B)
    void _dyncastimpl(SCID);  // 0x803B17C8 (92B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0xC];  // 0x000
    u32 m_fileName;  // 0x00C [R/W] (Close, Create, Delete, ...)
    u8 _pad_010[0xC0];  // 0x010
    u32 m_field_0D0;  // 0x0D0 [W] (SeqResFile)
    u8 _pad_0D4[0x60];  // 0x0D4
    u32 m_field_134;  // 0x134 [W] (Create, Delete, Open)
};

#endif // SEQRESFILE_H
