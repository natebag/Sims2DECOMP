#ifndef EISTATICSUBMODEL_H
#define EISTATICSUBMODEL_H

#include "types.h"

// EIStaticSubModel - struct layout extracted from assembly analysis
// Estimated minimum size: 0xF4 (244 bytes)
// 22 known fields (9 named), 74 methods

class EIStaticSubModel {
public:
    // Constructors / Destructors
    EIStaticSubModel(void)  // 0x80633A80
    ~EIStaticSubModel(void);  // 0x80633B24

    // Methods
    void Deallocate(void);  // 0x80633B98 (56B)
    void DeallocateModel(void);  // 0x80633E94 (200B)
    void Write(EStream &);  // 0x80633BD0 (112B)
    void Read(EStream &);  // 0x80633C40 (260B)
    /* ? */ GetReadVersion(void);  // 0x80638354 (52B)
    void SetupModel(void);  // 0x80633F5C (200B)
    void Load(EFile &);  // 0x80633D44 (260B)
    /* ? */ GetBoundSphere(EBoundSphere &);  // 0x80633E48 (76B)
    void BuildDigests(void);  // 0x80634024 (512B)
    void VisibilityTest(E3DWindow &);  // 0x80634224 (88B)
    void DrawAsShadow(ELevelDrawData &);  // 0x8063427C (252B)
    void Draw(ELevelDrawData &);  // 0x80634378 (1236B)
    void OrderTableCallback(ELevelDrawData &, EOrderTableData *);  // 0x80634E38 (336B)
    void SkyOrderTableCallback(ELevelDrawData &, EOrderTableData *);  // 0x80634A28 (332B)
    void FloorOrderTableCallback(ELevelDrawData &, EOrderTableData *);  // 0x80634F88 (336B)
    void FaceOrderTableCallback(ELevelDrawData &, EOrderTableData *);  // 0x80634B74 (708B)
    void DrawWireFrame(ERC *);  // 0x8063484C (148B)
    bool HasModifiableColor(void);  // 0x806350D8 (156B)
    void ModifyColor(unsigned int);  // 0x80635174 (52B)
    /* ? */ GetModifiableColor(void);  // 0x806351A8 (52B)
    void RebuildShaders(void);  // 0x806351DC (224B)
    void RealizeShaderTuning(void);  // 0x806352BC (100B)
    /* ? */ GetInstName(EInstance::InstType &);  // 0x80635320 (124B)
    void SafeDelete(void);  // 0x806381F4 (108B)
    /* ? */ GetTypeInfo(void);  // 0x80638260 (44B)
    /* ? */ GetTypeName(void);  // 0x8063828C (52B)
    /* ? */ GetTypeKey(void);  // 0x806382C0 (52B)
    /* ? */ GetTypeVersion(void);  // 0x806382F4 (56B)
    void RegisterType(unsigned short);  // 0x80638388 (116B)
    void New(void);  // 0x80638120 (76B)
    void Construct(EIStaticSubModel *);  // 0x8063816C (76B)
    void Destruct(EIStaticSubModel *);  // 0x806381B8 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8063832C (40B)
    void CreateCopy(void);  // 0x806383FC (68B)
    /* ? */ GetBoundSphere(void);  // 0x8063850C (44B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_bHasModifiableColor;  // 0x000 [R/W] (BuildDigests, Draw, EIStaticSubModel, ...)
    u16 m_field_002;  // 0x002 [W] (BuildDigests)
    u32 m_field_004;  // 0x004 [R/W] (BuildDigests, Draw, DrawAsShadow, ...)
    u32 m_asShadow;  // 0x008 [R] (DrawAsShadow)
    u32 m_asShadow_00C;  // 0x00C [R/W] (BuildDigests, DrawAsShadow)
    u8 _pad_010[4];  // 0x010
    u32 m_asShadow_014;  // 0x014 [R] (Draw, DrawAsShadow)
    u32 m_asShadow_018;  // 0x018 [R] (DrawAsShadow)
    u8 _pad_01C[0x4C];  // 0x01C
    u32 m_field_068;  // 0x068 [W] (BuildDigests)
    u32 m_field_06C;  // 0x06C [W] (BuildDigests)
    u32 m_field_070;  // 0x070 [R/W] (BuildDigests, Draw, DrawAsShadow, ...)
    u8 _pad_074[8];  // 0x074
    u32 m_field_07C;  // 0x07C [R/W] (BuildDigests, DrawWireFrame, EIStaticSubModel, ...)
    u32 m_field_080;  // 0x080 [W] (EIStaticSubModel)
    u8 _pad_084[0xC];  // 0x084
    u32 m_upModel;  // 0x090 [R/W] (EIStaticSubModel, SetupModel, Write)
    u32 m_field_094;  // 0x094 [W] (BuildDigests, DeallocateModel, EIStaticSubModel)
    u32 m_bHasModifiableColor_098;  // 0x098 [R/W] (BuildDigests, DeallocateModel, Draw, ...)
    u32 m_bHasModifiableColor_09C;  // 0x09C [R/W] (BuildDigests, DeallocateModel, Draw, ...)
    u32 m_upModel_0A0;  // 0x0A0 [R/W] (BuildDigests, DeallocateModel, Draw, ...)
    u32 m_field_0A4;  // 0x0A4 [R/W] (Draw, EIStaticSubModel)
    u32 m_field_0A8;  // 0x0A8 [R/W] (FaceOrderTableCallback, FloorOrderTableCallback, OrderTableCallback, ...)
    u32 m_field_0AC;  // 0x0AC [W] (FaceOrderTableCallback)
    u8 _pad_0B0[4];  // 0x0B0
    u32 m_field_0B4;  // 0x0B4 [W] (FaceOrderTableCallback)
    u8 _pad_0B8[0x38];  // 0x0B8
    u32 m_field_0F0;  // 0x0F0 [R] (Draw, DrawAsShadow, FaceOrderTableCallback, ...)
};

#endif // EISTATICSUBMODEL_H
