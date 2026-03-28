#ifndef CTILEPT_H
#define CTILEPT_H

#include "types.h"

// CTilePt - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 5 known fields (4 named), 102 methods

class CTilePt {
public:
    // Constructors / Destructors
    CTilePt(int, int, int)  // 0x8022EE94
    CTilePt(void)  // 0x8022ED4C
    CTilePt(CTilePt &)  // 0x8022ED7C
    CTilePt(EVec3 &)  // 0x8022EA80
    CTilePt(float, float, int)  // 0x8022EF18
    CTilePt(FTilePt &, int)  // 0x8022EDCC
    CTilePt(TilePt &, int)  // 0x8022EE44
    CTilePt(TilePtDir, int)  // 0x8022EFE4
    ~CTilePt(void);  // 0x8022F054

    // Methods
    /* ? */ GetEVec3M(void);  // 0x8022EBCC (216B)
    void operator+(CTilePt &);  // 0x8022F478 (144B)
    void operator=(CTilePt &);  // 0x8022F0A4 (216B)
    void ToFTilePt(void);  // 0x8022F9FC (156B)
    /* ? */ GetX(void);  // 0x8022FA98 (48B)
    /* ? */ GetY(void);  // 0x8022FAC8 (48B)
    void operator!=(CTilePt &);  // 0x8022F1E8 (112B)
    void Set(int, int, int);  // 0x8022FC44 (68B)
    void operator==(CTilePt &);  // 0x8022F17C (108B)
    /* ? */ GetTileDirection(CTilePt &, CTilePt &);  // 0x80230194 (932B)
    /* ? */ GetXf(void);  // 0x8022ECA4 (84B)
    /* ? */ GetYf(void);  // 0x8022ECF8 (84B)
    /* ? */ GetEVec3(void);  // 0x8022EAF4 (216B)
    void SetX(int);  // 0x8022FB9C (56B)
    void SetY(int);  // 0x8022FBD4 (56B)
    void operator<(CTilePt &);  // 0x8022F258 (140B)
    void operator+=(CTilePt &);  // 0x8022F2E4 (92B)
    void operator-=(CTilePt &);  // 0x8022F340 (92B)
    void operator*=(int);  // 0x8022F39C (92B)
    void operator*(int);  // 0x8022F3F8 (128B)
    void operator-(CTilePt &);  // 0x8022F508 (144B)
    /* ? */ GetRow(void);  // 0x8022F624 (60B)
    /* ? */ GetColumn(void);  // 0x8022F660 (60B)
    bool IsoCompare(CTilePt &);  // 0x8022F69C (176B)
    bool IsNorthOf(CTilePt &);  // 0x8022F74C (96B)
    bool IsSouthOf(CTilePt &);  // 0x8022F7AC (96B)
    bool IsWestOf(CTilePt &);  // 0x8022F80C (96B)
    bool IsEastOf(CTilePt &);  // 0x8022F86C (96B)
    void SameRowParity(CTilePt &);  // 0x8022F8CC (104B)
    void SameColumnParity(CTilePt &);  // 0x8022F934 (104B)
    void ToTilePt(void);  // 0x8022F99C (96B)
    /* ? */ Get(int *, int *);  // 0x8022FAF8 (72B)
    /* ? */ Get(int *, int *, int *);  // 0x8022FB40 (92B)
    void Set(int, int);  // 0x8022FC0C (56B)
    void SetX(float);  // 0x8022FC88 (80B)
    void SetY(float);  // 0x8022FCD8 (80B)
    void Set(float, float);  // 0x8022FD28 (96B)
    void Set(float, float, int);  // 0x8022FD88 (108B)
    /* ? */ GetLevel(void);  // 0x8022FDF4 (48B)
    void SetLevel(int);  // 0x8022FE24 (192B)
    void SetLevel(CTilePt &);  // 0x8022FEE4 (48B)
    /* ? */ GetDirection(CTilePt &, CTilePt &);  // 0x8022FFA8 (492B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_direction;  // 0x000 [R/W] (GetDirection, GetEVec3, GetEVec3M, ...)
    u8 m_direction_001;  // 0x001 [R] (GetDirection, operator<)
    u8 m_field_002;  // 0x002 [W] (CTilePt)
    u8 _pad_003[1];  // 0x003
    f32 m_eVec3M;  // 0x004 [W] (GetEVec3, GetEVec3M, ToFTilePt)
    f32 m_eVec3M_008;  // 0x008 [W] (GetEVec3, GetEVec3M)
};

#endif // CTILEPT_H
