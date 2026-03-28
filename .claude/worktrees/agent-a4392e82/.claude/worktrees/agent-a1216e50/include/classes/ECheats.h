#ifndef ECHEATS_H
#define ECHEATS_H

#include "types.h"

// ECheats - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10C (268 bytes)
// 5 known fields (0 named), 22 methods

class ECheats {
public:
    // Constructors / Destructors
    ECheats(void)  // 0x800518B8
    ~ECheats(void);  // 0x80051908

    // Methods
    void EmptyLookupList(void);  // 0x80054B70 (64B)
    void DisableCheats(void);  // 0x800558B0 (272B)
    void Init(EGlobal &);  // 0x80051974 (12732B)
    void ReadCheatsFile(void);  // 0x80054BB0 (2368B)
    void WriteCheatsFile(void);  // 0x800555BC (420B)
    void EnableCheats(void);  // 0x80055788 (296B)
    void Reset(void);  // 0x80054B30 (64B)
    void SetGodMode(bool);  // 0x800554F0 (204B)
    void Update(void);  // 0x80055760 (40B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [W] (EnableCheats)
    u32 m_field_00C;  // 0x00C [W] (EnableCheats)
    u8 _pad_010[0xF0];  // 0x010
    u32 m_field_100;  // 0x100 [R/W] (EmptyLookupList, Init)
    u32 m_field_104;  // 0x104 [W] (ECheats)
    u32 m_field_108;  // 0x108 [W] (Init)
};

#endif // ECHEATS_H
