#ifndef ESIMSDATAMANAGER_H
#define ESIMSDATAMANAGER_H

#include "types.h"

// ESimsDataManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD38 (3384 bytes)
// 12 known fields (3 named), 28 methods

class ESimsDataManager {
public:
    // Constructors / Destructors
    ESimsDataManager(void)  // 0x800593CC
    ~ESimsDataManager(void);  // 0x8005945C

    // Methods
    void compareID(unsigned int &, unsigned int &);  // 0x80058FAC (168B)
    /* ? */ GetLoadProgress(void);  // 0x80059510 (172B)
    void AllocateAndLoadResource(EFile *, unsigned int, unsigned int);  // 0x800595BC (704B)
    void preloadResources(EEvent &);  // 0x8005987C (140B)
    void preload(ObjSelector *);  // 0x80059E54 (192B)
    void decWorkQueued(void);  // 0x80059964 (212B)
    void incWorkQueued(void);  // 0x80059908 (92B)
    void LoadSelectorData(ObjSelector *, bool);  // 0x80059A38 (420B)
    void UnloadSelectorData(ObjSelector *, bool);  // 0x80059BDC (444B)
    void undoPreload(ObjSelector *);  // 0x80059D98 (188B)
    void QueueCommand(ESim *, unsigned int);  // 0x80059F14 (432B)
    void FlushCommands(void);  // 0x8005A0C4 (308B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (AllocateAndLoadResource, QueueCommand, UnloadSelectorData, ...)
    u8 _pad_004[0x24];  // 0x004
    u32 m_field_028;  // 0x028 [R] (AllocateAndLoadResource)
    u8 _pad_02C[0x14];  // 0x02C
    u32 m_field_040;  // 0x040 [W] (ESimsDataManager)
    u8 _pad_044[4];  // 0x044
    u32 m_field_048;  // 0x048 [W] (ESimsDataManager)
    u8 _pad_04C[0x3F0];  // 0x04C
    u32 m_field_43C;  // 0x43C [R/W] (AllocateAndLoadResource)
    u8 _pad_440[0x8DC];  // 0x440
    u32 m_field_D1C;  // 0xD1C [W] (ESimsDataManager)
    u32 m_loadProgress;  // 0xD20 [R/W] (AllocateAndLoadResource, ESimsDataManager, GetLoadProgress, ...)
    u32 m_loadProgress_D24;  // 0xD24 [R/W] (ESimsDataManager, GetLoadProgress)
    u32 m_loadProgress_D28;  // 0xD28 [R/W] (ESimsDataManager, GetLoadProgress, preloadResources)
    u32 m_field_D2C;  // 0xD2C [R/W] (ESimsDataManager, decWorkQueued, incWorkQueued)
    u32 m_field_D30;  // 0xD30 [R/W] (AllocateAndLoadResource, ESimsDataManager, UnloadSelectorData)
    u32 m_field_D34;  // 0xD34 [R/W] (ESimsDataManager, preloadResources)
};

#endif // ESIMSDATAMANAGER_H
