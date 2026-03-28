#ifndef FLASHBIGFILE_H
#define FLASHBIGFILE_H

#include "types.h"

// FlashBigFile - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 6 known fields (3 named), 18 methods

class FlashBigFile {
public:
    // Constructors / Destructors
    FlashBigFile(void)  // 0x8084DC90
    ~FlashBigFile(void);  // 0x8084DCC8

    // Methods
    /* ? */ GetGeometry(char *);  // 0x8084E278 (228B)
    /* ? */ GetTexture(char *, int &, int &);  // 0x8084E35C (136B)
    /* ? */ GetDataSection(char *);  // 0x8084E200 (120B)
    /* ? */ GetFlashName(void);  // 0x8084E1D0 (48B)
    void LoadFiles(EFile *);  // 0x8084DEC8 (776B)
    bool IsTexture(int);  // 0x8084DE18 (176B)
    void CreateTexture(int);  // 0x8084E3E4 (676B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CreateTexture, GetDataSection, GetTexture, ...)
    u32 m_dataSection_004;  // 0x004 [R/W] (CreateTexture, GetDataSection, GetTexture, ...)
    u32 m_texture;  // 0x008 [R/W] (CreateTexture, GetTexture, LoadFiles)
    u32 m_field_00C;  // 0x00C [W] (LoadFiles)
    u32 m_field_010;  // 0x010 [W] (LoadFiles)
    u32 m_field_014;  // 0x014 [W] (LoadFiles)
};

#endif // FLASHBIGFILE_H
