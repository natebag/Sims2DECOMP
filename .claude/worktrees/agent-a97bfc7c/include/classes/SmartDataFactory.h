#ifndef SMARTDATAFACTORY_H
#define SMARTDATAFACTORY_H

#include "types.h"

// SmartDataFactory - struct layout extracted from assembly analysis
// Estimated minimum size: 0x68 (104 bytes)
// 10 known fields (2 named), 20 methods

class SmartDataFactory {
public:
    // Constructors / Destructors
    SmartDataFactory(void)  // 0x803FDA84
    ~SmartDataFactory(void);  // 0x803FDAE4

    // Methods
    void QueryInterface(unsigned int, void **);  // 0x803FDB50 (248B)
    void AddRef(void);  // 0x803FDC48 (64B)
    void Release(void);  // 0x803FDC88 (160B)
    /* ? */ GetDataProvider(unsigned int, ObjectDataID &);  // 0x803FDD28 (312B)
    void SetDataProvider(unsigned int, ObjectDataID &, ISmartDataFactory::tDataProvider);  // 0x803FDE60 (272B)
    void CreateObject(unsigned int, unsigned int, void **);  // 0x803FDF70 (156B)
    void CreateObject(unsigned int, ObjectDataID &, void **);  // 0x803FE00C (220B)
    void CreateObjectFromProvider(unsigned int, ISmartDataFactory::tDataProvider, void **);  // 0x803FE0E8 (2516B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CreateObject, CreateObjectFromProvider, QueryInterface, ...)
    u8 _pad_004[4];  // 0x004
    u32 m_dataProvider;  // 0x008 [R/W] (GetDataProvider, SmartDataFactory)
    u8 _pad_00C[8];  // 0x00C
    u32 m_field_014;  // 0x014 [R/W] (Release, SmartDataFactory)
    u8 _pad_018[4];  // 0x018
    u32 m_field_01C;  // 0x01C [W] (CreateObjectFromProvider)
    u8 _pad_020[0x2C];  // 0x020
    u32 m_field_04C;  // 0x04C [W] (CreateObjectFromProvider)
    u8 _pad_050[4];  // 0x050
    u32 m_field_054;  // 0x054 [W] (CreateObjectFromProvider)
    u32 m_field_058;  // 0x058 [W] (CreateObjectFromProvider)
    u32 m_field_05C;  // 0x05C [W] (CreateObjectFromProvider)
    u32 m_field_060;  // 0x060 [W] (CreateObjectFromProvider)
    u32 m_field_064;  // 0x064 [W] (CreateObjectFromProvider)
};

#endif // SMARTDATAFACTORY_H
