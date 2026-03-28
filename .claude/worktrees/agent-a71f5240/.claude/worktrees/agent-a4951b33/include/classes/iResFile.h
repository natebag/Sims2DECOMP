#ifndef IRESFILE_H
#define IRESFILE_H

#include "types.h"

// iResFile - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 2 known fields (1 named), 28 methods

class iResFile {
public:
    // Constructors / Destructors
    iResFile(void)  // 0x8039AFB0
    ~iResFile(void);  // 0x8039B010

    // Methods
    /* ? */ GetResFileData(void);  // 0x8039B5DC (44B)
    void SetError(int);  // 0x8039B0A0 (44B)
    /* ? */ GetError(void);  // 0x8039B074 (44B)
    void _dyncastimpl(SCID);  // 0x8039B5A0 (60B)
    void Release(Memory::HandleNode *);  // 0x8039B0CC (164B)
    /* ? */ GetByIDAndLanguage(int, short, char, void (*);  // 0x8039B458 (184B)
    /* ? */ GetLanguage(Memory::HandleNode *);  // 0x8039B338 (116B)
    void AddWithLanguage(Memory::HandleNode *, int, short, StringBuffer &, char, bool);  // 0x8039B3AC (172B)
    void SetResFileData(ResFile *);  // 0x8039B608 (164B)
    void Open(StringBuffer &, iResFile::OpenFlags);  // 0x8039B170 (456B)
    void Link(void);  // 0x8039AE88 (52B)
    void Unlink(void);  // 0x8039AEBC (244B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [W] (iResFile)
    u32 m_byIDAndLanguage;  // 0x00C [R/W] (AddWithLanguage, GetByIDAndLanguage, Open, ...)
};

#endif // IRESFILE_H
