#ifndef QUICKDATASLOTDESCLIST_H
#define QUICKDATASLOTDESCLIST_H

#include "types.h"

// QuickDataSlotDescList - struct layout extracted from assembly analysis
// Estimated minimum size: 0x60 (96 bytes)
// 6 known fields (1 named), 32 methods

class QuickDataSlotDescList {
public:
    // Constructors / Destructors
    QuickDataSlotDescList(void)  // 0x803C2308
    ~QuickDataSlotDescList(void);  // 0x803C235C

    // Methods
    void LoadFromDataID(ObjectDataID &);  // 0x803BFF44 (388B)
    void LoadFromIndex(unsigned int, int);  // 0x803C00C8 (416B)
    void QueryInterface(unsigned int, void **);  // 0x803C0268 (248B)
    void AddRef(void);  // 0x803C0360 (64B)
    void Release(void);  // 0x803C03A0 (160B)
    void SaveDataByID(ObjectDataID &);  // 0x803C24E4 (44B)
    /* ? */ GetDataSourceType(void);  // 0x803C2510 (40B)
    void LoadOnlyNameAndIDFromIndex(unsigned int, int);  // 0x803C2538 (48B)
    void AddSlot(SlotDescriptor &);  // 0x803C23A8 (44B)
    void RemoveSlot(int);  // 0x803C23D4 (44B)
    /* ? */ GetNumSlots(void);  // 0x803C2400 (72B)
    /* ? */ GetSlot(int);  // 0x803C2448 (80B)
    /* ? */ GetStringSetID(void);  // 0x803C2498 (40B)
    void SetStringSetID(int);  // 0x803C24C0 (36B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (LoadFromDataID, QueryInterface, QuickDataSlotDescList, ...)
    u32 m_field_004;  // 0x004 [R] (LoadFromDataID)
    u32 m_field_008;  // 0x008 [R] (LoadFromDataID, LoadFromIndex)
    u8 _pad_00C[0x48];  // 0x00C
    u32 m_field_054;  // 0x054 [W] (LoadFromDataID, LoadFromIndex)
    u32 m_field_058;  // 0x058 [W] (LoadFromDataID, LoadFromIndex)
    u32 m_field_05C;  // 0x05C [R/W] (QuickDataSlotDescList, Release)
};

#endif // QUICKDATASLOTDESCLIST_H
