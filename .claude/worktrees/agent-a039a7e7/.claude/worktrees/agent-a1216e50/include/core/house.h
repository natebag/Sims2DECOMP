#ifndef HOUSE_H
#define HOUSE_H

#include "types.h"

// Forward declarations
class iResFile;
class cXPerson;
class cXObject;
class ReconBuffer;
class Family;
class ObjectModule;
struct FTilePt;
struct FTileRect;
struct CTilePt;
class StringBuffer;

// ============================================================================
// WallStyle / WallPattern / FloorPattern enums
// ============================================================================

// WallStyle values identified from CanWalkThrough:
// 3 = walkable, 5 = walkable, 6 = walkable, 15 = walkable, 23 = walkable
enum WallStyle {
    // TODO: fill in all values from disassembly
};

typedef unsigned short WallPattern;
typedef unsigned short FloorPattern;

// ============================================================================
// TileWalls system (from tilewalls.obj)
// ============================================================================

// TileWallsSegment is a bitmask for wall segments on a tile
typedef unsigned int TileWallsSegment;

// DiagonalSideSelector - used for diagonal wall sides
// Values: 1 and 2 map to offset 0x08, >=3 maps to offset 0x14
enum DiagonalSideSelector {
    // TODO: determine enum values
};

enum TilePtDir {
    // TODO: fill in
};

// TileWallStorage - storage backing for TileWalls
struct TileWallStorage {
    // TODO: determine layout
};

// TileWalls - manages walls on a single tile
// Layout: 0x38 (56) bytes total
//   0x00: u32 m_wallBits - bitmask of wall segments present
//   0x08: u16 m_floorValue1 - floor value for side 1/2
//   0x14: u16 m_floorValue2 - floor value for side 3+
//   0x24: u32 m_rotation - rotation value
class TileWalls {
public:
    // Internal data - 56 bytes, zeroed on default construction
    // We know specific offsets from disassembly:
    u32 m_wallBits;       // 0x00 - wall segment bitmask
    char _pad04[0x04];    // 0x04
    u16 m_floorValue1;    // 0x08 - floor for diagonal side <= 2
    char _pad0A[0x0A];    // 0x0A
    u16 m_floorValue2;    // 0x14 - floor for diagonal side >= 3
    char _pad16[0x0E];    // 0x16
    u32 m_rotation;       // 0x24 - rotation state
    char _pad28[0x10];    // 0x28

    // Constructors / Destructor
    TileWalls(void);
    TileWalls(TileWallStorage& storage);
    TileWalls(TileWallStorage& storage, bool, bool, bool, bool);
    TileWalls(TileWalls& other);
    ~TileWalls(void);

    // Assignment
    TileWalls& operator=(TileWalls& other);

    // Wall queries
    bool HasWall(TileWallsSegment seg) const;
    bool HasWall(void) const;
    bool HasDiagonal(void) const;
    bool HasWallNotFence(TileWallsSegment seg) const;
    bool HasFenceNotWall(TileWallsSegment seg) const;
    bool HasDiagonalNotFence(void) const;
    bool HasDiagonalFence(void) const;

    // Wall modification
    void AddWall(TileWallsSegment seg);
    void RemoveWall(TileWallsSegment seg);
    void RemoveAllWalls(void);
    bool CanAdd(TileWallsSegment seg) const;

    // Wall style/pattern
    WallStyle GetStyle(TileWallsSegment seg) const;
    void SetStyle(WallStyle style, TileWallsSegment seg);
    WallPattern GetPattern(TileWallsSegment seg, DiagonalSideSelector side) const;
    void SetPattern(WallPattern pattern, TileWallsSegment seg, DiagonalSideSelector side);

    // Floor values
    FloorPattern GetFloorValue(DiagonalSideSelector side) const;
    FloorPattern SetFloorValue(FloorPattern pattern, DiagonalSideSelector side);

    // Placement
    int GetPlacement(TileWallsSegment seg) const;

    struct SheerPlacement {};
    void SetPlacement(SheerPlacement placement, TileWallsSegment seg);

    // Iteration
    TileWallsSegment First(void) const;
    TileWallsSegment Next(TileWallsSegment seg) const;
    bool IsSingleWall(TileWallsSegment seg);

    // Rotation / conversion
    void Rotate(int amount);
    static TileWallsSegment RotateSegment(TileWallsSegment seg, int rotation);
    static DiagonalSideSelector RotateDiagonal(DiagonalSideSelector side, int rotation);
    void ConvertToWorldCoords(void);
    void GenerateRotationLookups(void);

    // Segment utilities
    static int SegmentToIndex(TileWallsSegment seg, DiagonalSideSelector* side);
    static TileWallsSegment IndexToSegment(int index, DiagonalSideSelector* side);
    static void GetAdjacentTile(TileWallsSegment seg, CTilePt* pt);
    static TileWallsSegment GetOppositeSegment(TileWallsSegment seg);
    static TileWallsSegment DirToWallSeg(TilePtDir dir);
    static TileWallsSegment GetWallBetween(TilePtDir dir);
};

// Rotation lookup tables (from .data section)
// RotateSegment LUT at 0x8050bc30, RotateDiagonal LUT at 0x8050c030
extern u32 sRotateSegmentLUT[];
extern u32 sRotateDiagonalLUT[];

// ============================================================================
// Walls functions (from walls.obj)
// ============================================================================

bool CanWalkThrough(unsigned char wallBits);
bool CanWalkThrough(WallStyle style);
int TestDoorCondition(TileWalls& walls, TileWallsSegment seg);
void SectWall(FTileRect* rect, int level);
int ValidDoorLocation(int x, int y, int level, int dir, int type);
unsigned char RotateWallBits(unsigned char bits, int rotation);
void CheckWallFlags(FTilePt pt, int level, int x, int y);

// ============================================================================
// HouseStats (from house.obj)
// ============================================================================

// HouseStats - statistics about a house
// Layout: 0x28 (40) bytes
//   0x00: int m_squareFeet
//   0x04: int m_unknown04
//   0x08: int m_numBedrooms
//   0x0C: int m_numBathrooms
//   0x10: int m_numLevels
//   0x14: int m_lotSize
//   0x18-0x20: unknowns
//   0x24: int m_objectCount
struct HouseStats {
    int m_squareFeet;    // 0x00
    int m_unknown04;     // 0x04
    int m_numBedrooms;   // 0x08
    int m_numBathrooms;  // 0x0C
    int m_numLevels;     // 0x10
    int m_lotSize;       // 0x14
    int m_unknown18;     // 0x18
    int m_unknown1C;     // 0x1C
    int m_unknown20;     // 0x20
    int m_objectCount;   // 0x24

    HouseStats(void);

    int GetSquareFeet(void);
    int GetNumBedrooms(void);
    int GetNumBathrooms(void);
    int GetNumLevels(void);
    int GetLotSize(void);
    int GetObjectCount(void);

    int GetSizeScore(void);
    int GetFurnishingsScore(void);
    int GetYardScore(void);
    int GetUpkeepScore(void);
    int GetOverallScore(void);
};

// ============================================================================
// House - abstract base class (from house.obj)
// ============================================================================

// Commander interface nested in HouseImpl
class Commander {
public:
    virtual ~Commander(void);
};

// ReconObject base
class ReconObject {
public:
    virtual ~ReconObject(void);
};

// SimpleReconObject<HouseImpl> template
// Layout: vtable at 0x00, HouseImpl* at 0x04, short type at 0x08
template <class T>
class SimpleReconObject : public ReconObject {
public:
    T* m_impl;     // 0x04
    short m_type;  // 0x08

    ~SimpleReconObject(void);
    void DoStream(ReconBuffer* buf, int flags);
    short GetType(void);
};

class House {
public:
    // vtable at 0x00

    static House* CreateInstance(void);
    static void DestroyInstance(House* house);

    virtual ~House(void);

    // Pure virtuals implemented by HouseImpl
};

// ============================================================================
// HouseImpl (from house.obj)
// ============================================================================

class HouseImpl : public House {
public:
    // Layout deduced from getters:
    //   0x00: vtable
    //   0x14: Family* m_family
    //   0x1C: void* m_sizeScoreCurve
    //   0x20: void* m_furnishingsScoreCurve

    // Known member offsets from getters
    char _pad04[0x10];               // 0x04
    Family* m_family;                // 0x14
    char _pad18[0x04];               // 0x18
    void* m_sizeScoreCurve;          // 0x1C
    void* m_furnishingsScoreCurve;   // 0x20

    HouseImpl(void);
    virtual ~HouseImpl(void);

    void Initialize(void);
    void Destroy(void);
    void RefreshHouse(void);
    void SetLotSize(int w, int h);
    int LoadFile(iResFile* file, int* ver);
    void ComputeAndStoreLotData(void);
    void SaveFile(iResFile* file);
    cXObject* GetFirstObject(void);
    int DoCommand(short cmd, int param);
    int IsNative(cXPerson* person);
    int IsResident(cXPerson* person);
    void EnterLiveMode(void);
    void PrepareForBudgetWindow(void);
    void DoStream(ReconBuffer* buf, int flags);
    void GetHouseStats(HouseStats& stats);
    Family* GetFamily(void);
    void* GetSizeScoreCurve(void);
    void* GetFurnishingsScoreCurve(void);
    void SetFamilyToNull(void);
};

// Resource type constants (from house.obj data section)
extern short kSimulatorResourceID;  // 0x804fdbfc
extern short kHouseResourceID;      // 0x804fdbfe
extern u32 kSimulatorResType;       // 0x804fdc00
extern u32 kHouseResType;           // 0x804fdc04

// ============================================================================
// IconGroup (from icongroup.obj)
// ============================================================================

class IconGroup {
public:
    // vtable at 0x00

    enum BalloonType {
        // TODO: determine values
    };

    static IconGroup* CreateInstance(void);
    static void DestroyInstance(IconGroup* group);

    virtual ~IconGroup(void);

    static int GetBalloonSpriteID(BalloonType type);
};

// IconGroupImpl - implementation
// Layout: 0x10 (16) bytes
//   0x00: vtable
//   0x04: int field_04
//   0x08: int field_08
//   0x0C: int field_0C
class IconGroupImpl : public IconGroup {
public:
    int m_field04;   // 0x04
    int m_field08;   // 0x08
    int m_field0C;   // 0x0C

    IconGroupImpl(void);
    virtual ~IconGroupImpl(void);

    void Init(int param);
    int GetSpriteID(int index);
    void GetLabel(StringBuffer& buf);
    void LoadStrings(void);
    void GetIconLabel(int index, StringBuffer& buf);
    int CountIconLabels(void);
};

// ============================================================================
// Careers (from careers.obj)
// ============================================================================

// Forward declarations
class Career;
struct Job;
template <class T> class VECTOR;
struct WStringSet;

// Careers - abstract base class
class Careers {
public:
    // vtable at 0x00

    Careers(void);
    virtual ~Careers(void);

    static Careers* CreateInstance(void);
    static void DestroyInstance(Careers* careers);
};

// CareersImpl - implementation
// Layout deduced from member access:
//   0x00: vtable
//   0x08: void* m_careerData (points to struct with career array at +4, count at +C)
//   0x0C: void* m_jobData (points to array of pointers)
//   0x1C: int m_fallbackGrade
class CareersImpl : public Careers {
public:
    char _pad04[0x04];      // 0x04
    void* m_careerData;     // 0x08
    void* m_jobData;        // 0x0C

    CareersImpl(void);
    virtual ~CareersImpl(void);

    void Load(void);
    void TearDown(void);
    Career* GetCareerByID(int id);
    int GetNumCareers(void);
    Career* GetCareerByIndex(int index);
    int GetIndexByCareer(Career* career);
    int* GetJobPerformance(int simID);
    int* GetJobGrade(int simID);
    void GetOfferDialogText(unsigned short* buf, Career& career, int grade, bool promoted);
    void GetBehCareerData(Career& career, int grade, int type, short* data);
    void* GetJobName(Job& job, bool useAlt);
    void* GetShortName(Job& job, bool useAlt);
    int GetCarpoolHour(Job& job);
    int GetSuit(Job& job, bool female);

    void* operator new(unsigned int size);
    void operator delete(void* ptr);
};

// ============================================================================
// FloatConstants (from floatconstants.obj)
// ============================================================================

// ObjectDataID - 8-byte data ID
struct ObjectDataID {
    u32 m_id1;  // 0x00
    u32 m_id2;  // 0x04

    ObjectDataID(const ObjectDataID& other);
};

struct FloatConstantItem;

// FloatConstants - abstract base class
class FloatConstants {
public:
    // vtable at 0x00

    static FloatConstants* CreateInstance(void);
    static FloatConstants* CreateInstance(ObjectDataID& dataID);
    static void DestroyInstance(FloatConstants* fc);

    virtual ~FloatConstants(void);
};

// FloatConstantsQuickData - implementation
// Layout: 0x14 (20) bytes
//   0x00: vtable
//   0x04: ObjectDataID m_dataID (8 bytes)
//   0x0C: void* m_items (pointer to sorted array of FloatConstantItem)
//   0x10: int m_refCount
class FloatConstantsQuickData : public FloatConstants {
public:
    ObjectDataID m_dataID;    // 0x04
    void* m_items;            // 0x0C
    int m_refCount;           // 0x10

    static FloatConstantsQuickData* CreateInstance(void);

    FloatConstantsQuickData(void);
    virtual ~FloatConstantsQuickData(void);

    float Get(char* name, float defaultVal, bool warn);
    bool Has(char* name);
    FloatConstantItem* findItem(FloatConstantItem* begin, FloatConstantItem* end, char* name);
    void Load(unsigned int id, short type);
    void Load(iResFile* file, short type);
    ObjectDataID GetDataID(void) const;
    void LoadFromDataID(ObjectDataID& dataID);
    int SaveDataByID(ObjectDataID& dataID);
    int QueryInterface(unsigned int iid, void** out);
    int GetDataSourceType(void) const;
    int AddRef(void);
    int Release(void);
    int LoadFromIndex(unsigned int index, int type);
    int GetResourceName(StringBuffer& buf) const;
    int SetResourceName(StringBuffer& buf);
    int LoadOnlyNameAndIDFromIndex(unsigned int index, int type);
};

// ============================================================================
// Portal system (from portal.obj)
// ============================================================================

class cXPortalImpl;
class cXMTObject;
class ObjSelector;
class cXMTObjectImpl;

// cXPortal - portal connecting rooms
class cXPortal {
public:
    // Layout: m_impl chain at 0x00
    void* m_data;  // 0x00 - pointer chain to portal impl data

    cXPortal(int type);
    virtual ~cXPortal(void);

    void setPortalImpl(cXPortalImpl* impl);
    cXPortalImpl* CAST_IMPL(void);

    static void DirtyAllRoutes(ObjectModule* module);
    static void InitPortalRoute(ObjectModule* module, cXObject* obj1, cXObject* obj2);
    static float EstimateDistance(ObjectModule* module, cXObject* obj1, cXObject* obj2);
    static cXPortal* FindBestPortal(ObjectModule* module, cXObject* obj1, cXObject* obj2);
    static void FailedPortalTree(ObjectModule* module, cXObject* obj, cXPortal* portal);
    static void BeginningPortalTree(ObjectModule* module, cXObject* obj, cXPortal* portal);
    static void DumpRouteScores(ObjectModule* module, short routeID);
};

// cXPortalImpl - portal implementation
// Layout deduced from GetRouteScore:
//   0x00: cXObject* m_object
//   0x08: float* m_routeScores (dynamic array start)
//   0x0C: float* m_routeScoresEnd (dynamic array end)
class cXPortalImpl {
public:
    void* m_object;           // 0x00
    char _pad04[0x04];        // 0x04
    float* m_routeScores;     // 0x08
    float* m_routeScoresEnd;  // 0x0C

    cXPortalImpl(int type, ObjSelector* sel, cXMTObject* mtObj, ObjectModule* module);
    virtual ~cXPortalImpl(void);

    void Initialize(void);
    void Place(FTilePt& pt, int level, cXObject* obj, int flags);
    void ApplyWallStyle(bool apply);
    int CanPlace(FTilePt& pt, int level, cXObject* obj, int flags);
    void Pickup(void);
    cXObject* GetOtherSide(void);
    u32 ReconType(void);
    void ReconStream(ReconBuffer* buf, int flags, bool save);
    int FindAvailRouteID(ObjectModule* module);
    float GetDistToPortal(cXPortal* portal);
    void SetRouteScore(short routeID, float score);
    float GetRouteScore(short routeID);
    void ClearRoute(ObjectModule* module, short routeID, float score);
    void ClearRouteScores(ObjectModule* module, short routeID);
    int GetCustomWallStyleID(void);
    void PostLoad(int version, bool flag);
    WallStyle GetWallStyle(void);
    cXPortalImpl* GetPortalImplementation(void);
};

#endif // HOUSE_H
