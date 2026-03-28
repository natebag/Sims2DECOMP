#ifndef IFFSLOTDESCLIST_H
#define IFFSLOTDESCLIST_H

#include "types.h"

// IFFSlotDescList - struct layout extracted from assembly analysis
// Estimated minimum size: 0x68 (104 bytes)
// 9 known fields (1 named), 32 methods

class IFFSlotDescList {
public:
    // Constructors / Destructors
    IFFSlotDescList(void)  // 0x803C25AC
    ~IFFSlotDescList(void);  // 0x803C260C

    // Methods
    void AddSlot(SlotDescriptor &);  // 0x803C0440 (76B)
    void RemoveSlot(int);  // 0x803C048C (188B)
    void LoadFromDataID(ObjectDataID &);  // 0x803C0548 (420B)
    void LoadFromIndex(unsigned int, int);  // 0x803C06EC (484B)
    void LoadOnlyNameAndIDFromIndex(unsigned int, int);  // 0x803C08D0 (120B)
    void SaveDataByID(ObjectDataID &);  // 0x803C0948 (228B)
    void QueryInterface(unsigned int, void **);  // 0x803C0A2C (248B)
    void AddRef(void);  // 0x803C0B24 (64B)
    void Release(void);  // 0x803C0B64 (160B)
    /* ? */ GetDataSourceType(void);  // 0x803C2790 (40B)
    /* ? */ GetNumSlots(void);  // 0x803C26AC (72B)
    /* ? */ GetSlot(int);  // 0x803C26F4 (80B)
    /* ? */ GetStringSetID(void);  // 0x803C2744 (40B)
    void SetStringSetID(int);  // 0x803C276C (36B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddSlot, IFFSlotDescList, QueryInterface, ...)
    u32 m_field_004;  // 0x004 [W] (AddSlot)
    u32 m_field_008;  // 0x008 [W] (AddSlot)
    u32 m_field_00C;  // 0x00C [R/W] (AddSlot, LoadFromDataID, LoadFromIndex)
    u32 m_field_010;  // 0x010 [W] (AddSlot)
    u32 m_field_014;  // 0x014 [W] (AddSlot)
    u8 _pad_018[0x3C];  // 0x018
    u32 m_field_054;  // 0x054 [R/W] (AddSlot, IFFSlotDescList, RemoveSlot, ...)
    u32 m_field_058;  // 0x058 [W] (IFFSlotDescList)
    u8 _pad_05C[8];  // 0x05C
    u32 m_field_064;  // 0x064 [R/W] (IFFSlotDescList, Release)
};

#endif // IFFSLOTDESCLIST_H
