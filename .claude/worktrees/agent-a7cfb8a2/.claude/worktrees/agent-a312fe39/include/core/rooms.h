#ifndef ROOMS_H
#define ROOMS_H

#include "types.h"

// Forward declarations
struct CTilePt;
class ObjectIterator;

// ============================================================================
// WallStyle - Wall style enum (shared with world.h)
// ============================================================================
#ifndef WALLSTYLE_DEFINED
#define WALLSTYLE_DEFINED
typedef int WallStyle;
#endif

// ============================================================================
// DiagonalNode - Node for diagonal room resolution
// ============================================================================
struct DiagonalNode {
    char _data[4]; // placeholder
};

// ============================================================================
// GlobalConstantsClient - Base class for constants clients
// ============================================================================
class GlobalConstantsClient {
public:
    GlobalConstantsClient(short id);
    virtual ~GlobalConstantsClient();
    virtual void UpdateConstants(void) = 0;
};

// ============================================================================
// RoomScoreConstants - Constants for room scoring calculation
// Inherits from GlobalConstantsClient
// vtable at 0x804644E0
// ============================================================================
class RoomScoreConstants : public GlobalConstantsClient {
public:
    RoomScoreConstants(void);

    virtual void UpdateConstants(void);
};

// ============================================================================
// Room::Sides - Direction enum for room sides
// ============================================================================
class Room {
public:
    enum Sides {
        SIDE_NORTH = 1,
        SIDE_EAST  = 2,
        SIDE_SOUTH = 3,
        SIDE_WEST  = 4
    };

    Room(unsigned short id, class RoomManager* mgr);
    ~Room(void);

    void Clear(void);
    void ComputeRoom(void);
    void CollectTileStats(CTilePt& tile);
    void CollectObjectStats(ObjectIterator iter);

    int GetArea(void);
    void GetObjectDensity(void);
    void GetPartition(void);
    bool IsOutside(void);
    int IsPool(void);
    static Sides Rotate(Sides side, int amount);
    void AbsorbNewRoomList(void* tileList);
    bool IsTileInRoom(CTilePt& tile);
    void SetOverheadLights(bool enable);
    void GetPeopleCount(void);
    void GetAmbientLight(void) const;
    void GetAmbientLightMultiplier(void);
    void PrintStats(void);

    // Data members (from constructor at 0x801374C4)
    unsigned short m_id;         // +0x00
    unsigned short m_field02;    // +0x02
    int m_field04;               // +0x04
    int m_field08;               // +0x08
    int m_field0C;               // +0x0C  (pair start)
    int m_field10;               // +0x10
    int m_field14;               // +0x14  (pair start)
    int m_field18;               // +0x18
    int m_field1C;               // +0x1C  (pair start)
    int m_field20;               // +0x20
    int m_field24;               // +0x24  (pair start)
    int m_field28;               // +0x28
    int m_field2C;               // +0x2C  (pair start)
    int m_field30;               // +0x30
    int m_field34;               // +0x34
    float m_field38;             // +0x38 (EVec3 starts here)
    float m_field3C;             // +0x3C
    float m_field40;             // +0x40
    int m_field44;               // +0x44
    char _pad48[0x04];           // +0x48
    int m_tileCount;             // +0x4C  (used by GetArea: area = m_tileCount / 2)
    char _pad50[0x04];           // +0x50
    int m_objectCount;           // +0x54  (used by GetObjectDensity)
    char _pad58[0x38];           // +0x58
    int m_field90;               // +0x90
    int m_isPool;                // +0x94  (used by IsPool)
    RoomManager* m_roomMgr;      // +0x98
};

// ============================================================================
// RoomManager - Manages all rooms on a lot
// ============================================================================
class RoomManager {
public:
    RoomManager(void);
    ~RoomManager(void);

    void InitLights(void);
    void ComputeRooms(void);
    void UpdateRooms(void);
    void ResetRooms(void);
    void ResetRoomManager(void);
    void ClearRoomPartitions(void);

    void RoomScoreChanged(int roomId);
    void RoomLightingChanged(int roomId);
    void AllRoomsLightingChanged(void);
    void AllRoomsScoreChanged(void);

    Room* GetRoom(unsigned short id);
    Room* GetNewRoom(unsigned short id);
    void OffsetWorld(CTilePt& offset);

    void ProcessDegenerateTile(CTilePt& tile, unsigned short id, Room::Sides sides);
    void ResolveDiagonal(CTilePt& tile, Room** roomA, Room** roomB, Room::Sides* sideA, Room::Sides* sideB);
    void ResolveDiagonal(CTilePt& tile, unsigned short* idA, unsigned short* idB, Room::Sides* sideA, Room::Sides* sideB);

    void GetOutsideAmbientLevel(void);
    void SetRoomIntensityScale(int room, bool flag, float scale);
    void SetRoomIntensityColorScale(int room, bool flag, int color, float scale);
    void ChangeLightingGroup(unsigned short from, unsigned short to);

    void PrintStats(void);

    static RoomManager* GetRoomManager(void);

    // Static
    static RoomManager* sRoomMgr;
};

// ============================================================================
// Free functions
// ============================================================================
RoomScoreConstants* GetRoomScoreConstantsClient(void);
bool IsScoredStyle(WallStyle style);
unsigned short GetLightRoomID(unsigned short id);

#endif // ROOMS_H
