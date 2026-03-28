#ifndef EDATAHEADER_H
#define EDATAHEADER_H

#include "types.h"

// EDataHeader - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 5 known fields (2 named), 18 methods

class EDataHeader {
public:
    // Constructors / Destructors
    EDataHeader(void)  // 0x808FC6A0
    ~EDataHeader(void);  // 0x808FC6E8

    // Methods
    void Read(EFile &, unsigned int, unsigned int, unsigned int);  // 0x808FC898 (1136B)
    /* ? */ GetName(void);  // 0x808FCE30 (44B)
    void Clear(void);  // 0x808FC740 (112B)
    void Write(EStream &);  // 0x808FC7B0 (232B)
    void VerifySignature(unsigned int);  // 0x808FCD08 (184B)
    void SetName(char *);  // 0x808FCDC0 (112B)
    bool IsSignatureValid(void);  // 0x808FCEA8 (340B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Clear, Read, SetName, ...)
    u32 m_field_004;  // 0x004 [R/W] (Clear, Read, Write)
    u32 m_bIsSignatureValid;  // 0x008 [R/W] (Clear, IsSignatureValid, Read, ...)
    u32 m_field_00C;  // 0x00C [R/W] (Clear, Read, Write)
    u32 m_field_010;  // 0x010 [R/W] (Clear, Write)
};

#endif // EDATAHEADER_H
