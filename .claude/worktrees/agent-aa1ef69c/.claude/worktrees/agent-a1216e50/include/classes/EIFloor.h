#ifndef EIFLOOR_H
#define EIFLOOR_H

#include "types.h"

// EIFloor - struct layout extracted from assembly analysis
// Estimated minimum size: 0x120 (288 bytes)
// 22 known fields (4 named), 54 methods

class EIFloor {
public:
    // Constructors / Destructors
    EIFloor(void)  // 0x800D2990
    ~EIFloor(void);  // 0x800D7BC8

    // Methods
    void CreateFloors(EHouse *);  // 0x800D3400 (3940B)
    void DestroyFloors(void);  // 0x800D326C (104B)
    void DoLightingCalculation(void);  // 0x800D17A8 (516B)
    void Draw(ELevelDrawData &);  // 0x800D2A58 (820B)
    void DrawStencil(ELevelDrawData &);  // 0x800D2D8C (544B)
    void DrawShadow(ELevelDrawData &);  // 0x800D2FAC (164B)
    void VisibilityTest(E3DWindow &);  // 0x800D3050 (80B)
    void TestCreateFloors(void);  // 0x800D446C (76B)
    void Cleanup(void);  // 0x800D4364 (264B)
    bool IsRoomInFloor(unsigned short);  // 0x800D44B8 (172B)
    /* ? */ GetInstName(EInstance::InstType &);  // 0x800D4564 (60B)
    void SafeDelete(void);  // 0x800D797C (108B)
    /* ? */ GetTypeInfo(void);  // 0x800D79E8 (44B)
    /* ? */ GetTypeName(void);  // 0x800D7A14 (52B)
    /* ? */ GetTypeKey(void);  // 0x800D7A48 (52B)
    /* ? */ GetTypeVersion(void);  // 0x800D7A7C (56B)
    void Update(void);  // 0x800D7C30 (32B)
    /* ? */ GetNumRoomID(void);  // 0x800D7C50 (48B)
    void RegisterType(unsigned short);  // 0x800D7B10 (116B)
    void New(void);  // 0x800D78A8 (76B)
    void Construct(EIFloor *);  // 0x800D78F4 (76B)
    void Destruct(EIFloor *);  // 0x800D7940 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x800D7AB4 (40B)
    /* ? */ GetReadVersion(void);  // 0x800D7ADC (52B)
    void CreateCopy(void);  // 0x800D7B84 (68B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_bIsRoomInFloor;  // 0x000 [R/W] (Cleanup, DoLightingCalculation, DrawStencil, ...)
    u8 _pad_002[2];  // 0x002
    u32 m_stencil;  // 0x004 [R] (DoLightingCalculation, DrawStencil)
    u32 m_field_008;  // 0x008 [R] (DoLightingCalculation)
    u32 m_field_00C;  // 0x00C [R] (DoLightingCalculation)
    u32 m_field_010;  // 0x010 [R] (DoLightingCalculation)
    u8 _pad_014[8];  // 0x014
    u32 m_field_01C;  // 0x01C [R/W] (CreateFloors)
    u8 _pad_020[8];  // 0x020
    u32 m_field_028;  // 0x028 [W] (CreateFloors)
    u8 _pad_02C[0x20];  // 0x02C
    f32 m_field_04C;  // 0x04C [R] (CreateFloors)
    u8 _pad_050[0xC];  // 0x050
    u32 m_field_05C;  // 0x05C [R/W] (EIFloor)
    u8 _pad_060[0x1C];  // 0x060
    u32 m_bIsRoomInFloor_07C;  // 0x07C [R/W] (CreateFloors, IsRoomInFloor)
    u16 m_field_07E;  // 0x07E [R] (CreateFloors, DoLightingCalculation)
    u8 m_bIsRoomInFloor_080;  // 0x080 [R/W] (CreateFloors, Draw, EIFloor, ...)
    u8 m_field_081;  // 0x081 [R] (Draw)
    u8 m_field_082;  // 0x082 [R] (Draw)
    u8 m_field_083;  // 0x083 [R] (Draw)
    u16 m_field_084;  // 0x084 [R] (CreateFloors)
    u8 _pad_086[0x6A];  // 0x086
    u32 m_field_0F0;  // 0x0F0 [R] (Draw)
    u8 _pad_0F4[0x10];  // 0x0F4
    u32 m_field_104;  // 0x104 [R/W] (Cleanup, CreateFloors, DoLightingCalculation, ...)
    u32 m_field_108;  // 0x108 [R/W] (Cleanup, CreateFloors, DoLightingCalculation)
    u32 m_field_10C;  // 0x10C [R/W] (Cleanup, CreateFloors, DoLightingCalculation)
    u32 m_field_110;  // 0x110 [W] (CreateFloors, EIFloor)
    u8 _pad_114[8];  // 0x114
    u32 m_field_11C;  // 0x11C [R/W] (CreateFloors, EIFloor)
};

#endif // EIFLOOR_H
