#ifndef EQUICKDATAMANAGER_H
#define EQUICKDATAMANAGER_H

#include "types.h"

// EQuickdataManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD28 (3368 bytes)
// 7 known fields (0 named), 20 methods

class EQuickdataManager {
public:
    // Constructors / Destructors
    EQuickdataManager(void)  // 0x8088C808
    ~EQuickdataManager(void);  // 0x8088C5AC

    // Methods
    /* ? */ GetCurrentLanguage(void);  // 0x8088C890 (44B)
    void SetCurrentLanguage(int);  // 0x8088C8BC (64B)
    void AddRef(unsigned int, EFile *, int);  // 0x8088C750 (92B)
    /* ? */ GetHeap(void);  // 0x8088C158 (64B)
    void AllocateAndLoadResource(EFile *, unsigned int, unsigned int);  // 0x8088C198 (408B)
    void Reload(unsigned int);  // 0x8088C330 (636B)
    bool CanCache(EResource *);  // 0x8088C864 (44B)
    void AddRef(char *, EFile *, int);  // 0x8088C7AC (92B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (Reload)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [W] (AllocateAndLoadResource)
    u8 _pad_00C[0x1C];  // 0x00C
    u32 m_field_028;  // 0x028 [R] (Reload)
    u8 _pad_02C[0x24];  // 0x02C
    u32 m_field_050;  // 0x050 [R] (Reload)
    u8 _pad_054[0xCC8];  // 0x054
    u32 m_field_D1C;  // 0xD1C [W] (EQuickdataManager)
    u32 m_field_D20;  // 0xD20 [R/W] (AllocateAndLoadResource, EQuickdataManager)
    u32 m_field_D24;  // 0xD24 [W] (AllocateAndLoadResource, EQuickdataManager)
};

#endif // EQUICKDATAMANAGER_H
