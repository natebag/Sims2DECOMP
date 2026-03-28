#ifndef CASCOSTUMES_H
#define CASCOSTUMES_H

#include "types.h"

// CasCostumes - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (1 named), 24 methods

class CasCostumes {
public:
    // Constructors / Destructors
    CasCostumes(void)  // 0x80422338
    ~CasCostumes(void);  // 0x804223C8

    // Methods
    void LoadCostumesList(void);  // 0x804226AC (308B)
    /* ? */ GetSimDescription(bool, char *);  // 0x804231D8 (656B)
    void ClearCostumesList(void);  // 0x8042258C (288B)
    void CompareSimDescription(CasSimDescriptionS2C *, CasSimDescriptionS2C *);  // 0x80422470 (284B)
    void CreateNewCostumesList(void);  // 0x80422FB0 (552B)
    void SaveCostumesList(void);  // 0x804227E0 (632B)
    void DoStream(ReconBuffer *, int);  // 0x80422A58 (1368B)
    /* ? */ GetSimDescription(bool, unsigned int);  // 0x80423468 (292B)
    void UpdateSimDescription(bool, char *, CasSimDescriptionS2C *);  // 0x8042358C (860B)
    void UpdateSimDescription(bool, unsigned int, CasSimDescriptionS2C *);  // 0x804238E8 (520B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetSimDescription, LoadCostumesList)
    u32 m_field_004;  // 0x004 [R/W] (ClearCostumesList, DoStream, LoadCostumesList)
    u32 m_field_008;  // 0x008 [R/W] (LoadCostumesList)
};

#endif // CASCOSTUMES_H
