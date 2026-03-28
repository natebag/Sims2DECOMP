#ifndef EIOBJECTMAN_H
#define EIOBJECTMAN_H

#include "types.h"

// EIObjectMan - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC4 (196 bytes)
// 10 known fields (2 named), 38 methods

class EIObjectMan {
public:
    // Constructors / Destructors
    EIObjectMan(EHouse *)  // 0x800F986C
    ~EIObjectMan(void);  // 0x800F9A6C

    // Methods
    void Init(void);  // 0x800F9920 (332B)
    void PostLoad(void);  // 0x800FB128 (60B)
    void RemoveObjectsFromHouse(ERLevel *);  // 0x800FA7CC (300B)
    bool IsEmpty(void);  // 0x800FA8F8 (72B)
    void ReOrientHouse(bool);  // 0x800FB5B0 (212B)
    void FreeSimsObjectInstance(ISimInstance *);  // 0x800FA15C (164B)
    void AddObject(cXObject *, ERLevel *);  // 0x800FA348 (1156B)
    void AttachObject(ISimInstance *);  // 0x800FA200 (328B)
    bool IsValidID(unsigned int);  // 0x800F98C4 (92B)
    void Find(ISimInstance *);  // 0x800F9C3C (156B)
    void AllPlayersActiveInputInteractors(void);  // 0x800F9CD8 (384B)
    void TurnOffAllHighlights(unsigned int);  // 0x800F9E58 (324B)
    /* ? */ GetObjectsInRect(int, TNodeList<ISimInstance *> &);  // 0x800F9F9C (304B)
    /* ? */ GetObjects(TNodeList<ISimInstance *> &);  // 0x800FA0CC (144B)
    /* ? */ GetHandle(ISimInstance *);  // 0x800FFE34 (164B)
    void AllocSimsObjectInstance(cXObject *);  // 0x800FA940 (2024B)
    void CountObjects(float &, float &, float &, float &);  // 0x800FB164 (1100B)
    /* ? */ GetInstance(unsigned int);  // 0x800FFED8 (132B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddObject, AllocSimsObjectInstance, CountObjects, ...)
    u32 m_objects;  // 0x004 [R/W] (AddObject, CountObjects, FreeSimsObjectInstance, ...)
    u8 m_field_005;  // 0x005 [R] (AllocSimsObjectInstance)
    u8 m_field_006;  // 0x006 [R] (AllocSimsObjectInstance)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [W] (CountObjects)
    u8 _pad_00C[4];  // 0x00C
    u32 m_field_010;  // 0x010 [R/W] (AllocSimsObjectInstance, EIObjectMan, TurnOffAllHighlights)
    s16 m_field_014;  // 0x014 [R] (AllocSimsObjectInstance)
    u8 _pad_016[6];  // 0x016
    u32 m_field_01C;  // 0x01C [R] (AllocSimsObjectInstance, TurnOffAllHighlights)
    u8 _pad_020[0x96];  // 0x020
    u16 m_field_0B6;  // 0x0B6 [R] (AllocSimsObjectInstance, CountObjects)
    u8 _pad_0B8[8];  // 0x0B8
    u32 m_field_0C0;  // 0x0C0 [R] (AllocSimsObjectInstance)
};

#endif // EIOBJECTMAN_H
