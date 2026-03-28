#ifndef ROOM_H
#define ROOM_H

#include "types.h"

// Room - struct layout extracted from assembly analysis
// Estimated minimum size: 0xA4 (164 bytes)
// 32 known fields (13 named), 57 methods

class Room {
public:
    // Constructors / Destructors
    Room(unsigned short, RoomManager *)  // 0x8039E200
    ~Room(void);  // 0x8039E354

    // Methods
    /* ? */ GetLightingGroup(void);  // 0x8004D3D8 (48B)
    void SetPointLightDimmer(float);  // 0x80069108 (40B)
    void Used(void);  // 0x8006905C (44B)
    bool IsRoomIntensityScaleDirty(void);  // 0x800690B4 (44B)
    /* ? */ GetRoomID(void);  // 0x8006902C (48B)
    /* ? */ GetRoomIntensityScale(void);  // 0x80069088 (44B)
    void ClearRoomIntensityScaleDirty(void);  // 0x800690E0 (40B)
    bool IsBathroom(void);  // 0x8024EE78 (60B)
    bool IsBedroom(void);  // 0x8024EE3C (60B)
    void BasicScore(void);  // 0x8032BCF8 (44B)
    /* ? */ GetAmbientLightMultiplier(void);  // 0x8039FD14 (560B)
    bool IsOutside(void);  // 0x8039F694 (824B)
    bool IsTileInRoom(CTilePt &);  // 0x8039F5CC (200B)
    /* ? */ GetArea(void);  // 0x8039F4B4 (60B)
    /* ? */ GetAmbientLight(void);  // 0x8039FC00 (132B)
    /* ? */ GetPeopleCount(void);  // 0x8039FA70 (400B)
    void SetOverheadLights(bool);  // 0x8039F9CC (164B)
    void SetDirty(bool);  // 0x803A2C2C (40B)
    bool IsDirty(void);  // 0x803A2C54 (44B)
    void Clear(void);  // 0x8039E410 (248B)
    void SetUsed(int);  // 0x803A2CA8 (40B)
    /* ? */ GetTileList(void);  // 0x803A2EDC (44B)
    void SetIsPool(bool);  // 0x803A2C80 (40B)
    void CollectTileStats(CTilePt &);  // 0x8039EB88 (952B)
    void CollectObjectStats(ObjectIterator);  // 0x8039EF40 (1040B)
    void ComputeRoom(void);  // 0x8039E578 (1424B)
    void PrintStats(void);  // 0x8039F350 (232B)
    void ClearPartition(void);  // 0x803A2DA4 (100B)
    void SetRoomIntensityScale(EVec3);  // 0x803A2E90 (76B)
    void SetLightingGroup(unsigned short);  // 0x803A2F38 (44B)
    /* ? */ GetPartition(void);  // 0x8039E508 (112B)
    /* ? */ GetObjectDensity(void);  // 0x8039F438 (124B)
    void AbsorbNewRoomList(vector<CTilePt, allocator<CTilePt> > &);  // 0x8039F4F0 (220B)
    bool IsPool(void);  // 0x8039FC84 (44B)
    void Rotate(Room::Sides, int);  // 0x8039FCB0 (100B)
    /* ? */ GetPointLightDimmer(void);  // 0x8065190C (44B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_partition;  // 0x000 [R/W] (CollectObjectStats, GetPartition, GetPeopleCount, ...)
    u16 m_field_002;  // 0x002 [W] (Room)
    f32 m_ambientLightMultiplier;  // 0x004 [R/W] (CollectObjectStats, GetAmbientLightMultiplier, GetPeopleCount, ...)
    f32 m_field_008;  // 0x008 [R/W] (CollectObjectStats, PrintStats, Room)
    u8 _pad_00C[8];  // 0x00C
    u32 m_field_014;  // 0x014 [R/W] (Clear, CollectObjectStats, Room, ...)
    u8 _pad_018[0xC];  // 0x018
    u32 m_partition_024;  // 0x024 [R/W] (GetPartition, Room, ~Room)
    u8 _pad_028[0xC];  // 0x028
    u32 m_bIsOutside;  // 0x034 [R/W] (AbsorbNewRoomList, Clear, IsOutside, ...)
    u32 m_field_038;  // 0x038 [W] (Room)
    u8 _pad_03C[8];  // 0x03C
    u32 m_field_044;  // 0x044 [W] (Room)
    f32 m_field_048;  // 0x048 [W] (Clear)
    u32 m_objectDensity;  // 0x04C [R/W] (Clear, CollectTileStats, ComputeRoom, ...)
    u32 m_field_050;  // 0x050 [R/W] (Clear, CollectTileStats, ComputeRoom)
    u32 m_objectDensity_054;  // 0x054 [R/W] (Clear, CollectObjectStats, GetObjectDensity)
    u32 m_field_058;  // 0x058 [R/W] (Clear, CollectObjectStats, ComputeRoom)
    u32 m_field_05C;  // 0x05C [R/W] (Clear, CollectObjectStats, ComputeRoom)
    u32 m_field_060;  // 0x060 [R/W] (Clear, CollectObjectStats)
    u32 m_field_064;  // 0x064 [R/W] (Clear, CollectObjectStats, ComputeRoom)
    u32 m_field_068;  // 0x068 [R/W] (Clear, CollectObjectStats, ComputeRoom)
    u32 m_field_06C;  // 0x06C [R/W] (Clear, CollectObjectStats)
    u32 m_field_070;  // 0x070 [R/W] (Clear, CollectObjectStats)
    u32 m_field_074;  // 0x074 [R/W] (Clear, CollectTileStats, ComputeRoom)
    u32 m_field_078;  // 0x078 [R/W] (Clear, CollectTileStats, ComputeRoom)
    f32 m_field_07C;  // 0x07C [W] (Clear, ComputeRoom)
    f32 m_ambientLight;  // 0x080 [R/W] (Clear, ComputeRoom, GetAmbientLight, ...)
    u32 m_field_084;  // 0x084 [W] (AbsorbNewRoomList, Clear)
    u32 m_bIsOutside_088;  // 0x088 [R/W] (Clear, IsOutside)
    u32 m_bIsOutside_08C;  // 0x08C [R/W] (Clear, IsOutside)
    u32 m_ambientLight_090;  // 0x090 [R/W] (GetAmbientLight, Room, SetOverheadLights)
    u32 m_ambientLight_094;  // 0x094 [R/W] (Clear, GetAmbientLight, SetOverheadLights)
    u32 m_field_098;  // 0x098 [R/W] (ComputeRoom, Room)
    u32 m_ambientLight_09C;  // 0x09C [R/W] (Clear, CollectObjectStats, GetAmbientLight, ...)
    u32 m_ambientLight_0A0;  // 0x0A0 [R/W] (Clear, CollectObjectStats, GetAmbientLight)
};

#endif // ROOM_H
