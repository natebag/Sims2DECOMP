#ifndef QUICKDATASOUNDINFO_H
#define QUICKDATASOUNDINFO_H

#include "types.h"

// QuickDataSoundInfo - struct layout extracted from assembly analysis
// Estimated minimum size: 0x5C (92 bytes)
// 6 known fields (1 named), 20 methods

class QuickDataSoundInfo {
public:
    // Constructors / Destructors
    QuickDataSoundInfo(void)  // 0x803C6344
    ~QuickDataSoundInfo(void);  // 0x803C6398

    // Methods
    void LoadFromDataID(ObjectDataID &);  // 0x803C5D54 (320B)
    void QueryInterface(unsigned int, void **);  // 0x803C5E94 (248B)
    void AddRef(void);  // 0x803C5F8C (64B)
    void Release(void);  // 0x803C5FCC (160B)
    void LoadFromIndex(unsigned int, int);  // 0x803C63F0 (48B)
    void SaveDataByID(ObjectDataID &);  // 0x803C6420 (44B)
    /* ? */ GetDataSourceType(void);  // 0x803C644C (40B)
    void LoadOnlyNameAndIDFromIndex(unsigned int, int);  // 0x803C6474 (48B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (LoadFromDataID, QueryInterface, QuickDataSoundInfo, ...)
    u32 m_field_004;  // 0x004 [R] (LoadFromDataID)
    u32 m_field_008;  // 0x008 [R] (LoadFromDataID)
    u8 _pad_00C[0xC];  // 0x00C
    u32 m_field_018;  // 0x018 [R] (LoadFromDataID)
    u8 _pad_01C[0x30];  // 0x01C
    u32 m_field_04C;  // 0x04C [W] (LoadFromDataID, QuickDataSoundInfo)
    u8 _pad_050[8];  // 0x050
    u32 m_field_058;  // 0x058 [R/W] (QuickDataSoundInfo, Release)
};

#endif // QUICKDATASOUNDINFO_H
