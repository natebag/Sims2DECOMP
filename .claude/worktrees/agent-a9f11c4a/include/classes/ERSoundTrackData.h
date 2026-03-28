#ifndef ERSOUNDTRACKDATA_H
#define ERSOUNDTRACKDATA_H

#include "types.h"

// ERSoundTrackData - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 5 known fields (1 named), 34 methods

class ERSoundTrackData {
public:
    // Constructors / Destructors
    ERSoundTrackData(void)  // 0x80873C08
    ~ERSoundTrackData(void);  // 0x80873C7C

    // Methods
    /* ? */ GetProgramSize(void);  // 0x8087565C (72B)
    /* ? */ GetInstruction(unsigned int);  // 0x808755A0 (188B)
    void Load(EFile *);  // 0x80873E00 (1148B)
    void SafeDelete(void);  // 0x808752C4 (108B)
    /* ? */ GetTypeInfo(void);  // 0x80875330 (44B)
    /* ? */ GetTypeName(void);  // 0x8087535C (52B)
    /* ? */ GetTypeKey(void);  // 0x80875390 (52B)
    /* ? */ GetTypeVersion(void);  // 0x808753C4 (56B)
    void RegisterType(unsigned short);  // 0x80875458 (116B)
    void New(void);  // 0x808751F0 (76B)
    void Construct(ERSoundTrackData *);  // 0x8087523C (76B)
    void Destruct(ERSoundTrackData *);  // 0x80875288 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x808753FC (40B)
    /* ? */ GetReadVersion(void);  // 0x80875424 (52B)
    void CreateCopy(void);  // 0x808754CC (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ERSoundTrackData, ~ERSoundTrackData)
    u32 m_field_004;  // 0x004 [R/W] (Load)
    u8 _pad_008[8];  // 0x008
    u32 m_field_010;  // 0x010 [R/W] (Load)
    u32 m_field_014;  // 0x014 [R/W] (ERSoundTrackData, Load, ~ERSoundTrackData)
    u32 m_field_018;  // 0x018 [W] (ERSoundTrackData)
};

#endif // ERSOUNDTRACKDATA_H
