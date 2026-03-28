#ifndef ERLEVEL_H
#define ERLEVEL_H

#include "types.h"

// ERLevel - struct layout extracted from assembly analysis
// Estimated minimum size: 0x60A4 (24740 bytes)
// 51 known fields (9 named), 222 methods

class ERLevel {
public:
    // Constructors / Destructors
    ERLevel(void)  // 0x80640B00
    ~ERLevel(void);  // 0x806410B4

    // Methods
    void FixInstances(void);  // 0x80645450 (460B)
    void SetDayNightLightTable(LevelLighting *);  // 0x806514DC (44B)
    void SetRainInfoTable(levelraininfo *);  // 0x80651508 (44B)
    void SetSunYawOffset(float);  // 0x80651534 (44B)
    void SetDrawWallShadowsFunc(void (*);  // 0x806518A0 (44B)
    void CalcBounds(void);  // 0x80646138 (232B)
    void ClearWallIndexSaves(void);  // 0x80651788 (56B)
    void GroupWallInstances(void);  // 0x80644EE8 (32B)
    void UpdateRooms(int);  // 0x80651690 (80B)
    void SetWallFadeState(EWallUpDownStateType);  // 0x80651560 (44B)
    void Draw(ERC *);  // 0x80647328 (7936B)
    void OutsideLightsUpdate(float, LevelLightingEntry &);  // 0x8064BC8C (460B)
    void Update(void);  // 0x80646284 (956B)
    void SetRainBlend(float);  // 0x806516E0 (44B)
    void InitializeLightingGrid(void);  // 0x8064B15C (60B)
    void SetRoomCount(int);  // 0x8064AC70 (896B)
    void ResetLightLocations(void);  // 0x8064B198 (228B)
    /* ? */ GetSun(void);  // 0x8065147C (48B)
    void UpdateLightsIntensityScale(int, EVec3);  // 0x8064AFF0 (236B)
    void InsertLight(EILight *);  // 0x806440F4 (304B)
    void OutsideLightsInit(float, LevelLightingEntry &);  // 0x8064BC40 (76B)
    void RemoveLight(EILight *);  // 0x80644224 (236B)
    void InsertHouseObject(EOrderTableData *);  // 0x8064BF50 (64B)
    void InsertWall(EInstance *, bool);  // 0x80643F98 (228B)
    void RemoveWall(EInstance *);  // 0x8064407C (120B)
    /* ? */ GetLightsAtLocation(EVec3 &, int, ELights &);  // 0x8064BF90 (412B)
    void RemoveInstance(EInstance *);  // 0x80645C0C (880B)
    void InsertInDOFForegroundObjectList(EOrderTableData &);  // 0x80649FD8 (412B)
    void InsertInOrderTable(EOrderTableData &);  // 0x80649C74 (868B)
    void InsertInstance(EInstance *, EInstance *);  // 0x80643F0C (80B)
    void WallFadeState(void);  // 0x8065158C (48B)
    void NotifyInstanceMoved(EInstance *);  // 0x806453BC (148B)
    void InsertSkydomeInstance(EInstance *);  // 0x806444A0 (604B)
    /* ? */ GetSunLight(EVec3 &, EDirLight &);  // 0x80641358 (96B)
    /* ? */ GetSunAmbient(void);  // 0x806514AC (48B)
    void SetBounds(EInstance *, EBound3 &);  // 0x80645F7C (328B)
    void RegisterFloor(EOrderTableData &);  // 0x806499EC (648B)
    void RefreshRoomAssignment(EInstance *);  // 0x8065173C (76B)
    void AllocAndLoadLevel(EFile &);  // 0x8064379C (108B)
    void Deallocate(void);  // 0x80643BD0 (240B)
    void Write(EStream &);  // 0x806413B8 (500B)
    void AddInstancesFromList(TNodeList<EInstance *> &);  // 0x806415AC (276B)
    void AddInstancesFromBoundTree(EStorable *);  // 0x806416C0 (376B)
    void Read(EStream &);  // 0x80641838 (3612B)
    /* ? */ GetReadVersion(void);  // 0x806512D4 (52B)
    void Load(EFile &);  // 0x80642654 (3532B)
    void Refresh(EFile *);  // 0x80643420 (892B)
    void DestroyInstancesOriginallyReadByLevel(void);  // 0x80643AD4 (252B)
    void DeallocateSub(void);  // 0x80643CC0 (588B)
    void AddInstanceToLevelHead(EInstance *);  // 0x80644938 (612B)
    void PrepareInstance(EInstance *);  // 0x80644F08 (128B)
    void ClearJustReadByLevelFlags(void);  // 0x80643808 (140B)
    void DestroyInstancesWithoutJustReadByLevelFlags(void);  // 0x80643894 (576B)
    void AddInstanceToLevel(EInstance *);  // 0x806446FC (572B)
    bool IsInstanceListKindaFull(void);  // 0x80643F5C (60B)
    void ValidateInstanceInLevel(EInstance *);  // 0x80644310 (400B)
    void AddInstanceToRoom(EInstance *);  // 0x80644F88 (288B)
    void AddWallInstanceToLevel(EInstance *);  // 0x80644B9C (844B)
    void AddInstanceToIdMap(EInstance *);  // 0x806456C8 (100B)
    /* ? */ GetRoomIndex(EInstance *);  // 0x80645320 (156B)
    void RemoveInstanceFromRoom(EInstance *);  // 0x806450A8 (632B)
    void UnregisterFloorOTDs(EInstance *);  // 0x80645B80 (140B)
    void FixInstanceList(TNodeList<EInstance *> &);  // 0x8064561C (172B)
    void RemoveInstanceFromIdMap(EInstance *);  // 0x8064572C (204B)
    void FindInstance(char *);  // 0x806457F8 (96B)
    void FindInstance(unsigned int);  // 0x80645858 (116B)
    void FindFirstInstance(unsigned int, EInstance **);  // 0x806458CC (92B)
    void FindNextInstance(HTIteratorPtrType *, EInstance **);  // 0x80645928 (92B)
    void Init(void);  // 0x80645984 (340B)
    void AddBounds(EBound3 &, EBound3 &, bool &);  // 0x806460C4 (116B)
    void UpdateLightGrid(void);  // 0x80646220 (100B)
    void UpdatePerRoomData(void);  // 0x806497E4 (88B)
    void CalcRadiusFromViewParams(float, float, float);  // 0x80646640 (268B)
    void DrawObjectShadowsOutside(TNodeList<EInstance *> &);  // 0x80646824 (768B)
    void DrawObjectShadowsInside(TNodeList<EInstance *> &);  // 0x80646B24 (1052B)
    void DrawOrderTableSlot(EOrderTableData *);  // 0x80646F40 (188B)
    void DrawOrderTableEntry(EOrderTableData *, ERC *);  // 0x8064A1B4 (616B)
    void DrawOrderTableSlotFast(EOrderTableData *);  // 0x80646FFC (404B)
    void DrawSortedOrderTable(EOrderTableData *);  // 0x80647190 (408B)
    void ObjectShouldBeOccluded(EInstance *);  // 0x80649228 (412B)
    void DrawOrderTable(void);  // 0x8064A41C (556B)
    void DrawSimShadow(int);  // 0x80649464 (896B)
    void DrawDOFForegroundObjects(void);  // 0x8064A174 (64B)
    void ObjectShouldBeOccluded(short, float);  // 0x806493C4 (160B)
    void UpdateFloorLighting(void);  // 0x8064BE58 (248B)
    void AllocAndCopyOTD(EOrderTableData &);  // 0x8064983C (240B)
    void IntersectBoundBox(EBound3 &, EVec3 &, EVec3 &);  // 0x8064A648 (1140B)
    void DrawWireFrame(ERC *);  // 0x8064AABC (436B)
    bool IsRoomAt(EVec3 &, int);  // 0x8064B0DC (128B)
    void SafeDelete(void);  // 0x80651174 (108B)
    /* ? */ GetTypeInfo(void);  // 0x806511E0 (44B)
    /* ? */ GetTypeName(void);  // 0x8065120C (52B)
    /* ? */ GetTypeKey(void);  // 0x80651240 (52B)
    /* ? */ GetTypeVersion(void);  // 0x80651274 (56B)
    void RegisterType(unsigned short);  // 0x80651308 (116B)
    void New(void);  // 0x80651098 (80B)
    void Construct(ERLevel *);  // 0x806510E8 (80B)
    void Destruct(ERLevel *);  // 0x80651138 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x806512AC (40B)
    void CreateCopy(void);  // 0x8065137C (68B)
    void SetIdMapTableSize(int);  // 0x806515BC (72B)
    bool IsDrawingOrderTable(void);  // 0x80651604 (44B)
    bool IsInUse(void);  // 0x80651630 (48B)
    /* ? */ GetRoomCount(void);  // 0x80651660 (48B)
    /* ? */ GetStorableVersion(void);  // 0x8065170C (48B)
    /* ? */ GetNumInstances(void);  // 0x806517C0 (48B)
    /* ? */ GetInstance(int);  // 0x806517F0 (64B)
    /* ? */ GetNumVisibleInstances(void);  // 0x80651830 (48B)
    /* ? */ GetVisInstance(int);  // 0x80651860 (64B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_lightsAtLocation;  // 0x000 [R/W] (AllocAndCopyOTD, CalcBounds, Deallocate, ...)
    f32 m_roomCount;  // 0x004 [R/W] (AllocAndCopyOTD, CalcBounds, Draw, ...)
    f32 m_roomCount_008;  // 0x008 [R/W] (AddWallInstanceToLevel, AllocAndCopyOTD, CalcBounds, ...)
    f32 m_field_00C;  // 0x00C [R/W] (AllocAndCopyOTD, CalcBounds, ERLevel, ...)
    u32 m_field_010;  // 0x010 [W] (AllocAndCopyOTD, ERLevel, InsertInDOFForegroundObjectList)
    f32 m_field_014;  // 0x014 [R/W] (AllocAndCopyOTD, Draw, ERLevel, ...)
    s16 m_field_018;  // 0x018 [R/W] (Draw, InsertLight, RemoveLight)
    u8 _pad_01A[2];  // 0x01A
    u32 m_field_01C;  // 0x01C [R] (Draw)
    u8 _pad_020[4];  // 0x020
    u32 m_field_024;  // 0x024 [R] (RegisterFloor)
    u32 m_field_028;  // 0x028 [R/W] (AllocAndLoadLevel, Draw, InsertInDOFForegroundObjectList, ...)
    f32 m_field_02C;  // 0x02C [W] (InsertInOrderTable)
    f32 m_field_030;  // 0x030 [R/W] (Draw, InsertInOrderTable)
    f32 m_field_034;  // 0x034 [R] (Draw)
    u8 _pad_038[4];  // 0x038
    f32 m_field_03C;  // 0x03C [R] (Draw)
    u8 _pad_040[8];  // 0x040
    f32 m_field_048;  // 0x048 [R] (Draw)
    u32 m_lightsIntensityScale;  // 0x04C [R] (UpdateLightsIntensityScale)
    u32 m_lightsIntensityScale_050;  // 0x050 [R] (UpdateLightsIntensityScale)
    u8 _pad_054[0xC];  // 0x054
    f32 m_field_060;  // 0x060 [R/W] (Draw)
    f32 m_field_064;  // 0x064 [R/W] (Draw)
    f32 m_field_068;  // 0x068 [R/W] (Draw)
    u32 m_field_06C;  // 0x06C [R] (Draw)
    s16 m_field_070;  // 0x070 [R] (Draw, DrawObjectShadowsInside, DrawObjectShadowsOutside, ...)
    u8 _pad_072[2];  // 0x072
    u32 m_field_074;  // 0x074 [R] (Draw)
    s16 m_field_078;  // 0x078 [R] (Draw)
    u8 _pad_07A[2];  // 0x07A
    u32 m_field_07C;  // 0x07C [R] (Draw)
    s16 m_field_080;  // 0x080 [R] (Draw)
    u8 _pad_082[2];  // 0x082
    u32 m_field_084;  // 0x084 [R] (Draw)
    u8 _pad_088[4];  // 0x088
    f32 m_field_08C;  // 0x08C [R] (Draw)
    f32 m_field_090;  // 0x090 [R] (Draw)
    f32 m_field_094;  // 0x094 [R/W] (Draw)
    u32 m_field_098;  // 0x098 [W] (Draw)
    u32 m_field_09C;  // 0x09C [W] (Draw)
    u8 _pad_0A0[8];  // 0x0A0
    u32 m_field_0A8;  // 0x0A8 [W] (Draw)
    u32 m_field_0AC;  // 0x0AC [W] (Draw)
    u32 m_field_0B0;  // 0x0B0 [W] (Draw)
    u32 m_field_0B4;  // 0x0B4 [W] (Draw)
    u32 m_field_0B8;  // 0x0B8 [W] (Draw)
    u8 _pad_0BC[0x34];  // 0x0BC
    u32 m_field_0F0;  // 0x0F0 [R] (Draw, DrawObjectShadowsInside, DrawSimShadow)
    u8 _pad_0F4[4];  // 0x0F4
    s16 m_field_0F8;  // 0x0F8 [R] (Draw)
    u8 _pad_0FA[2];  // 0x0FA
    u32 m_field_0FC;  // 0x0FC [R] (Draw)
    u8 _pad_100[0x28];  // 0x100
    f32 m_field_128;  // 0x128 [R] (Draw, ObjectShouldBeOccluded)
    u32 m_field_12C;  // 0x12C [R] (Draw)
    s16 m_field_130;  // 0x130 [R] (Draw)
    u8 _pad_132[2];  // 0x132
    u32 m_field_134;  // 0x134 [R] (Draw)
    u8 _pad_138[0xA0];  // 0x138
    s16 m_field_1D8;  // 0x1D8 [R] (Draw)
    u8 _pad_1DA[2];  // 0x1DA
    u32 m_field_1DC;  // 0x1DC [R] (Draw)
    u8 _pad_1E0[0x5CCC];  // 0x1E0
    u32 m_field_5EAC;  // 0x5EAC [R] (Draw)
    u8 _pad_5EB0[0x19C];  // 0x5EB0
    u32 m_sunLight;  // 0x604C [R] (GetSunLight)
    u8 _pad_6050[0xC];  // 0x6050
    f32 m_sunLight_605C;  // 0x605C [R] (Draw, DrawObjectShadowsOutside, GetSunLight)
    u8 _pad_6060[0xC];  // 0x6060
    u32 m_sunLight_606C;  // 0x606C [R] (GetSunLight)
    u8 _pad_6070[0x30];  // 0x6070
    u32 m_objectShadowsInside;  // 0x60A0 [R] (DrawObjectShadowsInside)
};

#endif // ERLEVEL_H
