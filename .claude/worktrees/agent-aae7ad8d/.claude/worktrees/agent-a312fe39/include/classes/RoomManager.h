#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include "types.h"

// RoomManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0x38 (56 bytes)
// 14 known fields (3 named), 56 methods

class RoomManager {
public:
    // Constructors / Destructors
    RoomManager(void)  // 0x8039C0C4
    ~RoomManager(void);  // 0x8039C1B8

    // Methods
    /* ? */ GetMaxRoomId(void);  // 0x800691A8 (336B)
    /* ? */ GetRoomCollection(void);  // 0x800692F8 (40B)
    /* ? */ GetRoom(_Rb_tree_iterator<pair<unsigned short, Room *>, _Const_traits<pair<unsigned short, Room *> > >);  // 0x80069320 (88B)
    void CreateInstance(void);  // 0x8024EFD8 (80B)
    void DestroyInstance(RoomManager *);  // 0x8024F028 (72B)
    /* ? */ GetOutsideObjectScore(void);  // 0x8024EFAC (44B)
    /* ? */ GetRoomEnvironmentScore(unsigned short);  // 0x80329AC0 (152B)
    /* ? */ GetRoom(unsigned short);  // 0x8039CE64 (212B)
    void ResolveDiagonal(CTilePt &, Room **, Room **, Room::Sides *, Room::Sides *);  // 0x8039D66C (524B)
    void ResetRoomManager(void);  // 0x8039DC4C (244B)
    void UpdateRooms(void);  // 0x8039D178 (132B)
    void AllRoomsScoreChanged(void);  // 0x8039C570 (200B)
    void ComputeRooms(void);  // 0x8039C638 (1692B)
    void RoomLightingChanged(int);  // 0x8039C400 (168B)
    void RoomScoreChanged(int);  // 0x8039C358 (168B)
    void PrintStats(void);  // 0x8039CCD4 (400B)
    void AllRoomsLightingChanged(void);  // 0x8039C4A8 (200B)
    void ClearRoomPartitions(void);  // 0x8039DB9C (176B)
    /* ? */ GetRoomManager(void);  // 0x8039FF44 (44B)
    void SetRoomIntensityScale(int, bool, float);  // 0x8039DD40 (356B)
    void SetRoomIntensityColorScale(int, bool, int, float);  // 0x8039DEA4 (452B)
    void InitLights(void);  // 0x8039DA8C (32B)
    /* ? */ GetNewRoom(unsigned short);  // 0x8039CF38 (576B)
    void OffsetWorld(CTilePt &);  // 0x8039D1FC (432B)
    void ProcessDegenerateTile(CTilePt &, unsigned short, Room::Sides);  // 0x8039D3AC (704B)
    void ResolveDiagonal(CTilePt &, unsigned short *, unsigned short *, Room::Sides *, Room::Sides *);  // 0x8039D878 (332B)
    void ResetRooms(void);  // 0x8039D9C4 (200B)
    /* ? */ GetOutsideAmbientLevel(void);  // 0x8039DAAC (240B)
    void ChangeLightingGroup(unsigned short, unsigned short);  // 0x8039E068 (408B)
    /* ? */ GetRoomCount(void);  // 0x8060A9E4 (268B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetOutsideAmbientLevel, OffsetWorld, ResetRoomManager, ...)
    u16 m_field_002;  // 0x002 [R] (ChangeLightingGroup)
    u32 m_room;  // 0x004 [R/W] (AllRoomsLightingChanged, AllRoomsScoreChanged, ChangeLightingGroup, ...)
    u32 m_field_008;  // 0x008 [R/W] (ResetRoomManager, ResetRooms, RoomManager, ...)
    u8 m_field_00C;  // 0x00C [R/W] (ProcessDegenerateTile, ResetRoomManager, RoomManager)
    u8 _pad_00D[3];  // 0x00D
    u32 m_field_010;  // 0x010 [W] (OffsetWorld)
    u32 m_roomIntensityScale;  // 0x014 [R] (ComputeRooms, OffsetWorld, ResetRoomManager, ...)
    u32 m_field_018;  // 0x018 [R/W] (OffsetWorld)
    u8 m_field_01C;  // 0x01C [R/W] (OffsetWorld)
    u8 _pad_01D[3];  // 0x01D
    u32 m_field_020;  // 0x020 [R/W] (AllRoomsLightingChanged, AllRoomsScoreChanged, ComputeRooms, ...)
    u32 m_field_024;  // 0x024 [R/W] (ComputeRooms, RoomManager)
    f32 m_field_028;  // 0x028 [R/W] (ComputeRooms, RoomManager)
    f32 m_field_02C;  // 0x02C [R/W] (ComputeRooms, RoomManager)
    u8 _pad_030[4];  // 0x030
    u32 m_field_034;  // 0x034 [R] (ResetRooms)
};

#endif // ROOMMANAGER_H
