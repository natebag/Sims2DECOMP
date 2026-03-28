#ifndef NEIGHBORHOODIMPL_H
#define NEIGHBORHOODIMPL_H

#include "types.h"

// NeighborhoodImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x450 (1104 bytes)
// 43 known fields (9 named), 148 methods

class NeighborhoodImpl {
public:
    // Constructors / Destructors
    NeighborhoodImpl(void)  // 0x80279DE8
    ~NeighborhoodImpl(void);  // 0x80279EF8

    // Methods
    void Unload(void);  // 0x8027A280 (352B)
    void Load(NghResFile *);  // 0x8027A3E0 (3024B)
    void SetHouseNum(int);  // 0x80289FF0 (40B)
    /* ? */ GetHouseInfo(NghResFile *, int, HouseInfo *);  // 0x80280CC4 (360B)
    void MoveIn(Family *, int);  // 0x8027F4A4 (280B)
    bool IsFreeplayLot(int);  // 0x8028A018 (64B)
    void SetPlayerFamilyInHouse(int);  // 0x8027F5BC (276B)
    void RelationshipsChanged(Neighbor *);  // 0x80279FD0 (156B)
    void PostSim(void);  // 0x8027A06C (32B)
    void LevelComplete(int);  // 0x8027A08C (120B)
    void RemoveNeighbor(Neighbor *);  // 0x8027C6FC (496B)
    void FindNeighborByType(ObjSelector *);  // 0x8027BF9C (316B)
    void AddNewNeighbor(ObjSelector *);  // 0x8027C0D8 (352B)
    void UpdateFamilyNumbers(void);  // 0x8027AFB0 (908B)
    void Save(NghResFile *, int);  // 0x8027B33C (1280B)
    void DoStream(ReconBuffer *, int);  // 0x8027B83C (640B)
    /* ? */ GetHouseNumberForLevel(int);  // 0x8027BABC (164B)
    void FindNeighborByID(int);  // 0x8027BB60 (292B)
    void FindNeighborByGUID(int);  // 0x8027BC84 (336B)
    void FindFamilyAndIndexByGUID(int, int &, int &);  // 0x8027BDD4 (456B)
    void LoadPersistentData(cXPerson *);  // 0x8027C238 (992B)
    void RemoveNeighborRelationships(Neighbor *);  // 0x8027C618 (228B)
    void SavePersistentData(cXPerson *);  // 0x8027C8EC (760B)
    /* ? */ GetNeighborSelector(int);  // 0x8027CBE4 (152B)
    /* ? */ GetNextNeighborID(short);  // 0x8027CC7C (312B)
    /* ? */ GetNeighborData(short, short, short **);  // 0x8027CDB4 (1840B)
    /* ? */ GetFamily(int);  // 0x8027D4E4 (324B)
    /* ? */ GetFamilyInHouse(int);  // 0x8027D628 (480B)
    /* ? */ GetNumFamilies(void);  // 0x8027D808 (80B)
    /* ? */ GetFamilyByIndex(int);  // 0x8027D858 (92B)
    /* ? */ GetFamilyIndex(Family *);  // 0x8027D8B4 (200B)
    void MakeNewFamily(void);  // 0x8027D97C (84B)
    void BaseMakeNewFamily(bool, int);  // 0x8027DA80 (908B)
    void MakeNewFreePlayFamily(int);  // 0x8027D9D0 (176B)
    void RemoveFamily(Family *);  // 0x8027DE0C (432B)
    void AddToFamily(Neighbor *, Family *);  // 0x8027DFBC (952B)
    void RemoveFromFamily(Neighbor *);  // 0x8027E374 (576B)
    void AddAsPlayerRoommate(Neighbor *);  // 0x8027E5B4 (728B)
    void RemovePlayerRoommate(void);  // 0x8027E88C (868B)
    void AddNewCharacter(Neighbor **);  // 0x8027EBF0 (392B)
    void DeleteCharacter(Neighbor *);  // 0x8027ED78 (968B)
    /* ? */ GetNumCharacters(void);  // 0x8027F140 (188B)
    /* ? */ GetFamilyFriendsCount(Family *);  // 0x8027F1FC (104B)
    void UpdateFamilyFriendsCount(Family *);  // 0x80280534 (624B)
    /* ? */ GetFamilyNetWorth(Family *);  // 0x8027F264 (576B)
    void MoveOut(NghResFile *, int, bool);  // 0x8027F6D0 (3684B)
    void PrepareAndTestLot(StringBuffer &);  // 0x802807A4 (440B)
    /* ? */ GetHousePrice(cSimulator *);  // 0x8028095C (300B)
    /* ? */ GetFamilyInfo(Family *, FamilyInfo *, bool);  // 0x80280A88 (408B)
    /* ? */ GetFamilyInfo(int, FamilyInfo *);  // 0x80280C20 (164B)
    /* ? */ GetHouseInfo(NghResFile *, HouseInfo *);  // 0x80280E2C (164B)
    /* ? */ GetHouseFileInfo(NghResFile *, int *, bool *, bool *, bool *);  // 0x80280ED0 (564B)
    void compareHouses(int &, int &);  // 0x80281104 (448B)
    void LoadHouse(NghResFile *, int, bool);  // 0x802812C4 (4756B)
    void SaveHouse(NghResFile *);  // 0x80282558 (672B)
    /* ? */ GetHouseNumber(void);  // 0x802827F8 (44B)
    void UnloadHouse(void);  // 0x80282824 (132B)
    /* ? */ GetLotPosition(int, int *, int *);  // 0x802828A8 (168B)
    void DumpState(void);  // 0x80282950 (348B)
    void UpdateInstanceVisitorTypes(void);  // 0x80282AAC (464B)
    void NotifyAllNeighbors(WantFear::Notification &, Neighbor *);  // 0x80282C7C (248B)
    void NotifyAllResidents(WantFear::Notification &, Neighbor *);  // 0x80282D74 (532B)
    void NotifyAllPersons(WantFear::Notification &, Neighbor *);  // 0x80282F88 (692B)
    /* ? */ GetNeighborhoodName(void);  // 0x80289C84 (72B)
    /* ? */ GetHighestLevelCompleted(void);  // 0x80289CCC (48B)
    /* ? */ GetNeighborhoodVar(int);  // 0x80289CFC (64B)
    /* ? */ GetNeighborhoodVarRef(int);  // 0x80289D3C (60B)
    void SetNeighborhoodVar(int, short);  // 0x80289D78 (60B)
    /* ? */ GetPlayerVisitingAnotherHouse(void);  // 0x80289DB4 (124B)
    /* ? */ GetNumNeighborHouses(void);  // 0x80289E6C (72B)
    /* ? */ GetNeighborHouseByIndex(int);  // 0x80289EE0 (232B)
    /* ? */ GetImpl(void);  // 0x80289FC8 (40B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_houseInfo;  // 0x000 [R/W] (AddAsPlayerRoommate, AddToFamily, BaseMakeNewFamily, ...)
    s16 m_neighborData;  // 0x004 [R/W] (DeleteCharacter, GetNeighborData, Load, ...)
    u8 _pad_006[6];  // 0x006
    u32 m_neighborData_00C;  // 0x00C [R] (GetNeighborData, GetNeighborSelector, LoadHouse)
    u8 _pad_010[4];  // 0x010
    u32 m_field_014;  // 0x014 [W] (LoadHouse)
    u8 _pad_018[4];  // 0x018
    u32 m_field_01C;  // 0x01C [R] (Load)
    u32 m_field_020;  // 0x020 [W] (RelationshipsChanged)
    u8 _pad_024[0x28];  // 0x024
    u32 m_field_04C;  // 0x04C [R/W] (LoadHouse, NeighborhoodImpl, ~NeighborhoodImpl)
    u32 m_field_050;  // 0x050 [R/W] (LoadHouse, NeighborhoodImpl)
    u32 m_field_054;  // 0x054 [R/W] (LoadHouse)
    s16 m_field_058;  // 0x058 [R] (LoadHouse, NotifyAllResidents)
    u8 _pad_05A[2];  // 0x05A
    u32 m_familyIndex;  // 0x05C [R/W] (BaseMakeNewFamily, DeleteCharacter, GetFamily, ...)
    u32 m_field_060;  // 0x060 [R/W] (Unload)
    u32 m_field_064;  // 0x064 [R/W] (Unload)
    u8 _pad_068[4];  // 0x068
    s16 m_field_06C;  // 0x06C [R/W] (AddAsPlayerRoommate, DoStream, NeighborhoodImpl, ...)
    s16 m_field_06E;  // 0x06E [R/W] (Load, Save)
    u32 m_family;  // 0x070 [R/W] (GetFamily, GetFamilyNetWorth, LoadHouse, ...)
    u16 m_field_072;  // 0x072 [R] (Save)
    u32 m_nextNeighborID;  // 0x074 [R/W] (AddNewNeighbor, FindNeighborByGUID, FindNeighborByType, ...)
    u32 m_nextNeighborID_078;  // 0x078 [R] (FindNeighborByType, GetNextNeighborID, UpdateFamilyFriendsCount)
    u8 _pad_07C[8];  // 0x07C
    u16 m_field_084;  // 0x084 [W] (LevelComplete)
    s16 m_field_086;  // 0x086 [R/W] (DoStream)
    u16 m_field_088;  // 0x088 [W] (Save)
    u8 _pad_08A[0xE];  // 0x08A
    s16 m_field_098;  // 0x098 [R] (LoadPersistentData)
    u8 _pad_09A[2];  // 0x09A
    u32 m_field_09C;  // 0x09C [R] (LoadPersistentData)
    u8 _pad_0A0[0x30];  // 0x0A0
    s16 m_field_0D0;  // 0x0D0 [R] (MoveOut)
    u8 _pad_0D2[6];  // 0x0D2
    u32 m_field_0D8;  // 0x0D8 [R] (LoadHouse)
    u8 _pad_0DC[4];  // 0x0DC
    s16 m_field_0E0;  // 0x0E0 [R] (Save)
    u8 _pad_0E2[2];  // 0x0E2
    s16 m_neighborData_0E4;  // 0x0E4 [R] (GetNeighborData)
    u8 _pad_0E6[2];  // 0x0E6
    u32 m_field_0E8;  // 0x0E8 [R] (LoadHouse)
    s16 m_neighborData_0EA;  // 0x0EA [R] (GetNeighborData)
    u32 m_field_0EC;  // 0x0EC [R] (Load)
    u32 m_field_0F0;  // 0x0F0 [R] (LoadHouse)
    u8 _pad_0F4[2];  // 0x0F4
    s16 m_field_0F6;  // 0x0F6 [R] (MoveOut)
    u8 _pad_0F8[0x48];  // 0x0F8
    s16 m_field_140;  // 0x140 [R] (LoadPersistentData)
    u8 _pad_142[2];  // 0x142
    u32 m_field_144;  // 0x144 [R] (LoadPersistentData)
    u8 _pad_148[0x70];  // 0x148
    s16 m_field_1B8;  // 0x1B8 [R] (LoadPersistentData)
    u8 _pad_1BA[2];  // 0x1BA
    u32 m_field_1BC;  // 0x1BC [R] (LoadPersistentData)
    u8 _pad_1C0[0x90];  // 0x1C0
    s16 m_field_250;  // 0x250 [R] (LoadPersistentData)
    u8 _pad_252[2];  // 0x252
    u32 m_field_254;  // 0x254 [R] (LoadPersistentData)
    u8 _pad_258[0x110];  // 0x258
    s16 m_field_368;  // 0x368 [R] (LoadPersistentData)
    u8 _pad_36A[2];  // 0x36A
    u32 m_field_36C;  // 0x36C [R] (LoadPersistentData)
    u8 _pad_370[0xD8];  // 0x370
    u32 m_field_448;  // 0x448 [R] (Load)
    u32 m_field_44C;  // 0x44C [R] (Load)
};

#endif // NEIGHBORHOODIMPL_H
