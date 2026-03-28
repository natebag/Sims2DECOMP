#ifndef OBJECTMODULEIMPL_H
#define OBJECTMODULEIMPL_H

#include "types.h"

// ObjectModuleImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x209C (8348 bytes)
// 37 known fields (9 named), 182 methods

class ObjectModuleImpl {
public:
    // Constructors / Destructors
    ObjectModuleImpl(void)  // 0x802D8A24
    ~ObjectModuleImpl(void);  // 0x802D8C34

    // Methods
    bool IsValidObject(cXObject *);  // 0x802E2A98 (224B)
    void Save(iResFile *);  // 0x802D8D0C (376B)
    void Load(iResFile *);  // 0x802D8EA0 (1544B)
    void UpdateSimObjects(void);  // 0x802DE158 (1088B)
    void killDemolishedObjects(iResFile *);  // 0x802D94A8 (880B)
    void PostLoad(iResFile *, int, bool);  // 0x802D9818 (184B)
    void KillQueueFlush(void);  // 0x802DD178 (500B)
    void SelectPlayerSims(void);  // 0x802D98D0 (464B)
    void DoReconObject(ReconBuffer *, cXObjectImpl **);  // 0x802D9AA0 (300B)
    void DoReconPerson(ReconBuffer *, cXPersonImpl **);  // 0x802D9BCC (344B)
    void DoStream(ReconBuffer *, int);  // 0x802D9D40 (3872B)
    void Init(void);  // 0x802DAC60 (156B)
    void LoadGlobalRoutingSlots(void);  // 0x802DACFC (124B)
    void Destroy(void);  // 0x802DAD78 (720B)
    void RemoveObject(cXObject *);  // 0x802DFD4C (1188B)
    /* ? */ GetObjectByGUID(int);  // 0x802DB048 (612B)
    /* ? */ GetPersonByGUID(int);  // 0x802DB2AC (276B)
    void ConstructObject(ObjSelector *, cXMTObject *);  // 0x802DB3C0 (648B)
    void MakeNewOutOfWorldObject(ObjSelector *, short *);  // 0x802DB648 (3116B)
    void KillOutOfWorldObject(short, bool);  // 0x802DC274 (2896B)
    void KillObject(short);  // 0x802DCDC4 (948B)
    void PostSim(bool);  // 0x802DD36C (384B)
    void DayChanged(void);  // 0x802DD4EC (200B)
    void UpdateRooms(int);  // 0x802DD5B4 (1060B)
    void UpdateInteractionInfluences(void);  // 0x802DD9D8 (328B)
    void KillAllObjects(void);  // 0x802DDB20 (764B)
    void KillObjectsOutsideBounds(int, int, int, int);  // 0x802DDE1C (828B)
    void AddToKillQueue(short, bool);  // 0x802DE598 (1228B)
    void ClearKillQueue(void);  // 0x802DEA64 (60B)
    bool IsFamilyMemberAwakeAndVisible(void);  // 0x802DEAA0 (432B)
    void DoCommand(short, int);  // 0x802DEC50 (564B)
    void PreviewAnimation(short, short, short, bool);  // 0x802DEE84 (732B)
    void ForceAllLocations(void);  // 0x802DF160 (240B)
    /* ? */ GetAnObjectID(short);  // 0x802DF250 (560B)
    void AddObject(cXObject *, short, bool);  // 0x802DF480 (2252B)
    void DisableBuyAndBuild(cXObject *);  // 0x802E01F0 (208B)
    void EnableBuyAndBuild(cXObject *);  // 0x802E02C0 (324B)
    void CheckIntegrity(void);  // 0x802E0404 (1568B)
    void ClearAwarenessOfObject(cXObject *);  // 0x802E0A24 (216B)
    void CleanupPeople(cXObject *);  // 0x802E0AFC (256B)
    void EnqueueObjectDialog(cXObject *, StackElem *, DialogParam *);  // 0x802E0BFC (44B)
    void EnqueueObjectDialog(ObjSelector *, DialogParam *);  // 0x802E0C28 (40B)
    void BroadcastMessage(char *, int);  // 0x802E0C50 (320B)
    void SendMessage(cXObject *, char *, int);  // 0x802E0D90 (284B)
    void UpdateWallAdjacencies(void);  // 0x802E0EAC (116B)
    void InvalidateAllRoutes(void);  // 0x802E0F20 (192B)
    void SkillAccessed(cXPerson *, int, bool);  // 0x802E0FE0 (44B)
    void MotiveAccessed(cXPerson *, int, bool);  // 0x802E100C (44B)
    void PersonalityAccessed(cXPerson *, int, bool);  // 0x802E1038 (44B)
    void RelationshipAccessed(cXObject *, cXObject *, int, bool);  // 0x802E1064 (48B)
    void RelationshipAccessed(Neighbor *, Neighbor *, int, bool);  // 0x802E1094 (204B)
    void OffsetObjectMap(CTilePt &);  // 0x802E1160 (360B)
    void OffsetWorld(CTilePt &);  // 0x802E12C8 (2752B)
    /* ? */ GetTutorialObject(void);  // 0x802E1D88 (68B)
    void SetTutorialObject(cXObject *);  // 0x802E1DCC (164B)
    void ShowTutorialInfo(void);  // 0x802E1E70 (128B)
    void ComputeStats(int *, int *, bool *, bool *, bool *);  // 0x802E1EF0 (1904B)
    void FillInObjectStats(RoomManager *, HouseStats &);  // 0x802E2660 (832B)
    bool IsSelectionSwitchingAllowed(void);  // 0x802E29A0 (248B)
    bool IsValidPerson(cXPerson *);  // 0x802E2B78 (300B)
    void AdvanceSelectedPerson(int);  // 0x802E2CA4 (88B)
    /* ? */ GetSelectedPerson(int);  // 0x802E2CFC (92B)
    void ClearIdleStatus(int);  // 0x802E2D58 (604B)
    void SetSimFlag(int, ObjectModule::SimFlag, bool);  // 0x802E2FB4 (340B)
    /* ? */ GetSimFlag(int, ObjectModule::SimFlag);  // 0x802E3108 (280B)
    /* ? */ GetIdleStatus(int);  // 0x802E3220 (260B)
    void SetIdleStatus(int, int);  // 0x802E3324 (308B)
    /* ? */ GetObjectFromID(int);  // 0x802E3458 (176B)
    void Dump(void);  // 0x802E3508 (1740B)
    /* ? */ GetTileObjectID(CTilePt &);  // 0x802E3BD4 (332B)
    void SetTileObjectID(CTilePt &, short);  // 0x802E3D20 (440B)
    void CreateNeighbor(Neighbor *);  // 0x802E3ED8 (372B)
    /* ? */ GetObject(int);  // 0x802E404C (320B)
    /* ? */ GetNumObjects(void);  // 0x802E418C (168B)
    /* ? */ GetNextPerson(unsigned short);  // 0x802E4234 (428B)
    /* ? */ GetFolder(void);  // 0x802E8534 (64B)
    void AddObject(cXObject *, short);  // 0x802E8574 (128B)
    /* ? */ GetFirst(void);  // 0x802E85F4 (68B)
    /* ? */ GetSim(void);  // 0x802E8638 (64B)
    /* ? */ GetPeople(int);  // 0x802E8734 (212B)
    /* ? */ GetNumPeople(void);  // 0x802E8808 (72B)
    /* ? */ GetPortal(int);  // 0x802E887C (192B)
    /* ? */ GetNumPortals(void);  // 0x802E893C (72B)
    /* ? */ GetGlobalRoutingSlot(int);  // 0x802E8984 (188B)
    /* ? */ GetNumGlobalRoutingSlots(void);  // 0x802E8A40 (72B)
    bool IsBuyAndBuildDisabled(void);  // 0x802E8AC4 (88B)
    /* ? */ GetSimMemory(int, int, int);  // 0x803B7008 (196B)
    void SetSimMemory(int, int, int, int);  // 0x803B70CC (452B)
    /* ? */ GetDominantMemory(int, int, int);  // 0x803B7290 (264B)

    // ---- Field Layout (from assembly analysis) ----
    s16 m_bIsFamilyMemberAwakeAndVisible;  // 0x000 [R/W] (AddObject, AddToKillQueue, BroadcastMessage, ...)
    u8 _pad_002[2];  // 0x002
    s16 m_nextPerson;  // 0x004 [R/W] (AddObject, AddToKillQueue, CheckIntegrity, ...)
    u8 _pad_006[2];  // 0x006
    s16 m_field_008;  // 0x008 [R/W] (KillOutOfWorldObject, MakeNewOutOfWorldObject, OffsetObjectMap)
    u8 _pad_00A[2];  // 0x00A
    u32 m_field_00C;  // 0x00C [R/W] (CreateNeighbor, KillObjectsOutsideBounds, KillOutOfWorldObject, ...)
    u32 m_field_010;  // 0x010 [W] (ObjectModuleImpl, OffsetObjectMap, ~ObjectModuleImpl)
    u32 m_field_014;  // 0x014 [R/W] (AddObject, Destroy, Init, ...)
    u32 m_field_018;  // 0x018 [R/W] (ClearIdleStatus, Destroy, KillOutOfWorldObject, ...)
    u32 m_anObjectID;  // 0x01C [R/W] (AddObject, Destroy, DoStream, ...)
    u32 m_field_020;  // 0x020 [R/W] (Destroy, Init, KillAllObjects, ...)
    u32 m_field_024;  // 0x024 [R/W] (Destroy, KillAllObjects)
    u8 _pad_028[4];  // 0x028
    u32 m_field_02C;  // 0x02C [R/W] (AddObject, BroadcastMessage, CheckIntegrity, ...)
    u32 m_field_030;  // 0x030 [R/W] (AddObject, ObjectModuleImpl, RemoveObject)
    u8 _pad_034[4];  // 0x034
    u32 m_field_038;  // 0x038 [R] (DoStream)
    u8 _pad_03C[0x18];  // 0x03C
    s16 m_simObjects;  // 0x054 [R] (UpdateSimObjects)
    u8 _pad_056[2];  // 0x056
    s16 m_simObjects_058;  // 0x058 [R] (OffsetWorld, UpdateSimObjects)
    u8 _pad_05A[2];  // 0x05A
    u32 m_field_05C;  // 0x05C [R/W] (AddObject, RemoveObject, Save)
    u8 _pad_060[4];  // 0x060
    s16 m_field_064;  // 0x064 [R/W] (AddObject, RemoveObject)
    u8 _pad_066[0x50];  // 0x066
    u16 m_field_0B6;  // 0x0B6 [R] (KillObject)
    u8 _pad_0B8[0xC];  // 0x0B8
    u32 m_field_0C4;  // 0x0C4 [R] (AddObject, KillOutOfWorldObject)
    u8 _pad_0C8[0x20];  // 0x0C8
    s16 m_field_0E8;  // 0x0E8 [R] (SelectPlayerSims)
    u8 _pad_0EA[2];  // 0x0EA
    u32 m_field_0EC;  // 0x0EC [R] (KillOutOfWorldObject, MakeNewOutOfWorldObject, Save)
    u8 _pad_0F0[8];  // 0x0F0
    s16 m_field_0F8;  // 0x0F8 [R] (ComputeStats)
    u8 _pad_0FA[0x146];  // 0x0FA
    s16 m_field_240;  // 0x240 [R] (MakeNewOutOfWorldObject)
    u8 _pad_242[0x16];  // 0x242
    s16 m_field_258;  // 0x258 [R] (Load)
    u8 _pad_25A[0x10E];  // 0x25A
    s16 m_field_368;  // 0x368 [R] (MakeNewOutOfWorldObject)
    u8 _pad_36A[2];  // 0x36A
    u32 m_field_36C;  // 0x36C [R] (MakeNewOutOfWorldObject)
    u8 _pad_370[0x1CC4];  // 0x370
    u32 m_field_2034;  // 0x2034 [R/W] (DisableBuyAndBuild, DoStream, EnableBuyAndBuild, ...)
    u8 _pad_2038[0xC];  // 0x2038
    u32 m_field_2044;  // 0x2044 [R/W] (AddToKillQueue, KillQueueFlush, ObjectModuleImpl, ...)
    u8 _pad_2048[0xC];  // 0x2048
    s16 m_field_2054;  // 0x2054 [R/W] (KillOutOfWorldObject, ObjectModuleImpl, PreviewAnimation, ...)
    u8 _pad_2056[2];  // 0x2056
    u32 m_nextPerson_2058;  // 0x2058 [R/W] (AddObject, CleanupPeople, ClearAwarenessOfObject, ...)
    u8 _pad_205C[0xC];  // 0x205C
    u32 m_field_2068;  // 0x2068 [R/W] (AddObject, ObjectModuleImpl, RemoveObject, ...)
    u8 _pad_206C[0xC];  // 0x206C
    u32 m_field_2078;  // 0x2078 [R/W] (DoCommand, LoadGlobalRoutingSlots, ObjectModuleImpl, ...)
    u8 _pad_207C[0xC];  // 0x207C
    u32 m_tutorialObject;  // 0x2088 [R/W] (KillOutOfWorldObject, ObjectModuleImpl, SetTutorialObject, ...)
    u32 m_field_208C;  // 0x208C [R/W] (KillAllObjects, KillObject, ObjectModuleImpl)
    u32 m_anObjectID_2090;  // 0x2090 [R/W] (AddObject, Destroy, GetAnObjectID, ...)
    u32 m_objectFromID;  // 0x2094 [R/W] (Destroy, GetObjectByGUID, GetObjectFromID, ...)
    u32 m_field_2098;  // 0x2098 [R/W] (Destroy, KillAllObjects)
};

#endif // OBJECTMODULEIMPL_H
