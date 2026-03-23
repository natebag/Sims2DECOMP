#ifndef EIFENCEWALL_H
#define EIFENCEWALL_H

#include "types.h"

// EIFenceWall - struct layout extracted from assembly analysis
// Estimated minimum size: 0x3B0 (944 bytes)
// 5 known fields (1 named), 38 methods

class EIFenceWall {
public:
    // Constructors / Destructors
    EIFenceWall(TileWallsSegment &, CTilePt &, WallStyle)  // 0x8006E0D8
    EIFenceWall(void)  // 0x8007F628
    ~EIFenceWall(void);  // 0x8006E630

    // Methods
    /* ? */ GetFenceMeterValue(void);  // 0x8006D7B8 (100B)
    void VisibilityTest(E3DWindow &);  // 0x8006DA88 (88B)
    void Draw(ELevelDrawData &);  // 0x8006F4FC (64B)
    void SafeDelete(void);  // 0x8007F310 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8007F37C (44B)
    /* ? */ GetTypeName(void);  // 0x8007F3A8 (52B)
    /* ? */ GetTypeKey(void);  // 0x8007F3DC (52B)
    /* ? */ GetTypeVersion(void);  // 0x8007F410 (56B)
    bool IsOpaque(void);  // 0x8007F68C (40B)
    void RegisterType(unsigned short);  // 0x8007F4A4 (116B)
    void New(void);  // 0x8007F23C (76B)
    void Construct(EIFenceWall *);  // 0x8007F288 (76B)
    void Destruct(EIFenceWall *);  // 0x8007F2D4 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8007F448 (40B)
    /* ? */ GetReadVersion(void);  // 0x8007F470 (52B)
    void CreateCopy(void);  // 0x8007F518 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (EIFenceWall, ~EIFenceWall)
    u32 m_field_004;  // 0x004 [R] (~EIFenceWall)
    u8 _pad_008[0x350];  // 0x008
    u16 m_field_358;  // 0x358 [W] (EIFenceWall)
    u16 m_field_35A;  // 0x35A [W] (EIFenceWall)
    u8 _pad_35C[0x50];  // 0x35C
    u32 m_field_3AC;  // 0x3AC [R/W] (EIFenceWall, ~EIFenceWall)
};

#endif // EIFENCEWALL_H
