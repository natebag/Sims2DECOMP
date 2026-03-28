#ifndef ISIMINSTANCE_H
#define ISIMINSTANCE_H

#include "types.h"

// ISimInstance - struct layout extracted from assembly analysis
// Estimated minimum size: 0x3C4 (964 bytes)
// 9 known fields (3 named), 84 methods

class ISimInstance {
public:
    // Constructors / Destructors
    ISimInstance(void)  // 0x80103498
    ~ISimInstance(void);  // 0x801035D4

    // Methods
    void SetObjOrient(void);  // 0x8010330C (32B)
    void SetCursFlags(unsigned int);  // 0x801070B4 (40B)
    /* ? */ GetCursFlags(void);  // 0x801070DC (44B)
    /* ? */ GetSimInstance(void);  // 0x80107108 (40B)
    void Create(cXObject *, EHouse *);  // 0x801032C0 (40B)
    void OrentSubObject(cXObject *);  // 0x801032E8 (36B)
    void SetCarryOrient(void);  // 0x801033D4 (32B)
    void CreateShadow(void);  // 0x8010332C (32B)
    void InsertSubModelsInHouse(ERLevel *);  // 0x8010334C (36B)
    void RemoveSubModelsFromHouse(ERLevel *);  // 0x80103370 (36B)
    void PropigateFlagsToSubModels(void);  // 0x80103394 (32B)
    void CleanupStuff(ERLevel *);  // 0x80107090 (36B)
    void SetOutOfWorld(void);  // 0x801033B4 (32B)
    void StartBurp(int);  // 0x801033F4 (36B)
    bool HasInteractions(int);  // 0x80103928 (464B)
    void SetPlacementError(bool);  // 0x8010327C (68B)
    bool IsMultiTilePart(void);  // 0x80107130 (40B)
    void SetAutonomyScore(float);  // 0x80103B48 (44B)
    /* ? */ GetXOb(void);  // 0x8010346C (44B)
    /* ? */ GetFlags(void);  // 0x80107158 (44B)
    bool HasModel(void);  // 0x80107184 (60B)
    void SetXOb(cXObject *);  // 0x80103440 (44B)
    /* ? */ GetObCenter(void);  // 0x80103AF8 (80B)
    /* ? */ GetIsPerson(void);  // 0x80103814 (144B)
    /* ? */ GetSelector(void);  // 0x801038A4 (132B)
    /* ? */ GetAnimController(void);  // 0x801071C0 (44B)
    void SetHighlight(unsigned int, bool);  // 0x801037B8 (92B)
    /* ? */ GetShadow(void);  // 0x80103418 (40B)
    void SafeDelete(void);  // 0x80106D8C (108B)
    /* ? */ GetTypeInfo(void);  // 0x80106DF8 (44B)
    /* ? */ GetTypeName(void);  // 0x80106E24 (52B)
    /* ? */ GetTypeKey(void);  // 0x80106E58 (52B)
    /* ? */ GetTypeVersion(void);  // 0x80106E8C (56B)
    void RegisterType(unsigned short);  // 0x80106F20 (116B)
    void New(void);  // 0x80106CB8 (76B)
    void Construct(ISimInstance *);  // 0x80106D04 (76B)
    void Destruct(ISimInstance *);  // 0x80106D50 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x80106EC4 (40B)
    /* ? */ GetReadVersion(void);  // 0x80106EEC (52B)
    void CreateCopy(void);  // 0x80106F94 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (HasInteractions, ISimInstance, ~ISimInstance)
    u32 m_bHasInteractions_004;  // 0x004 [R] (HasInteractions)
    u8 _pad_008[0x318];  // 0x008
    u32 m_field_320;  // 0x320 [W] (ISimInstance, ~ISimInstance)
    u8 _pad_324[4];  // 0x324
    u32 m_isPerson;  // 0x328 [R/W] (GetIsPerson, GetSelector, ISimInstance, ...)
    u32 m_field_32C;  // 0x32C [W] (ISimInstance)
    u8 _pad_330[0x7C];  // 0x330
    u32 m_field_3AC;  // 0x3AC [W] (ISimInstance)
    u32 m_field_3B0;  // 0x3B0 [W] (ISimInstance)
    u8 _pad_3B4[8];  // 0x3B4
    u32 m_field_3BC;  // 0x3BC [R/W] (ISimInstance, ~ISimInstance)
    u32 m_field_3C0;  // 0x3C0 [R/W] (ISimInstance, ~ISimInstance)
};

#endif // ISIMINSTANCE_H
