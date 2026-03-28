#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

// Forward declarations
class cXObjectImpl;
class cXPersonImpl;
class cXMTObjectImpl;
class cXPortalImpl;
class cXObject;
class ObjectModule;
class ObjSelector;
class ReconBuffer;
class BString;
class ObjectProbe;

// Forward declarations for hierarchy/placement types
struct FTilePt;
struct FTileRect;
struct CTilePt;
struct PlacementSpec;
struct HierarchySite;
struct FindGoodLocationParams;

// Forward declarations for sim types
class ISimInstance;

// Opaque types referenced by cXObjectImpl
class TreeSim;
class TreeSimImpl;

// ============================================================================
// TreeReturnCode - Return code from tree execution
// ============================================================================
typedef s16 TreeReturnCode;

// ============================================================================
// ObjEntryPoint - Entry point enum for tree execution
// ============================================================================
typedef int ObjEntryPoint;

// ============================================================================
// cXObject::MiscFlag - Bit flags for misc object state
// ============================================================================
// Used as bitmask passed to SetMiscFlag/GetMiscFlag

// ============================================================================
// EdithVariableSet - Variable storage for object scripts
// Embedded at offset +0x28 in cXObjectImpl
// Size: at least 0x28 bytes (contains vector of byte_key_maps)
// ============================================================================
class EdithVariableSet {
public:
    EdithVariableSet();
    EdithVariableSet(EdithVariableSet& other);
    ~EdithVariableSet();
    void Initialize(cXObjectImpl* impl);
    void Reset();
    short* operator[](int index);
    void WriteVar(int key, short value);
    bool Contains(int key);
    void ReconStream(ReconBuffer* buffer, int direction);
    void ReconOldFdata(ReconBuffer* buffer, unsigned int version);

    // Internal data - exact layout TBD
    // Contains a vector of byte_key_map<72, short> for variable storage
    char _data[0x40]; // placeholder for internal storage
};

// ============================================================================
// cXObject - Base game object class
// Size: at least 0x08
// Contains a pointer to an impl union/struct at offset +0x00
// ============================================================================
class cXObject {
public:
    // Nested enum for MiscFlag
    typedef int MiscFlag;

    cXObject(int id);
    ~cXObject();

    // Static accessors for global state (stored relative to r13)
    static int GetPersonWidth();
    static bool GetFreeWill();
    static bool GetAutoCenter();
    static void SetAutoCenter(bool value);
    static bool GetAutoReset();
    static void SetAutoReset(bool value);
    static short GetGlobalInitTreeID();
    static short GetGlobalMainTreeID();
    static void SetGlobalFreeWillOverride(bool value);
    void SetFreeWill(bool value);

    // Impl setters
    void setObjectImpl(cXObjectImpl* impl);
    void setPersonImpl(cXPersonImpl* impl);
    void setMTObjectImpl(cXMTObjectImpl* impl);
    void setPortalImpl(cXPortalImpl* impl);

    // Cast
    cXObjectImpl* CAST_IMPL();

    // Wall block flags
    int GetWallBlockFlagsAtTile(CTilePt& tile, int level);

    // Impl pointer storage
    // +0x00: pointer to impl union
    // +0x04: vtable (set by constructor, not C++ virtual)
    struct ImplPtrs {
        cXObjectImpl* m_objectImpl;   // +0x00
        cXPersonImpl* m_personImpl;   // +0x04
        cXMTObjectImpl* m_mtObjectImpl; // +0x08
        cXPortalImpl* m_portalImpl;   // +0x0C
    };

    ImplPtrs* m_pImpls; // +0x00 (first member, before vtable)
};

// ============================================================================
// FTilePt - Tile position (8 bytes)
// ============================================================================
struct FTilePt {
    s32 x; // +0x00
    s32 y; // +0x04
};

// ============================================================================
// PlacementSpec - Describes where/how an object is placed
// Size: 0x18 (24 bytes)
//   +0x00: int  m_valid     (1 if valid)
//   +0x04: s32  m_tileX     (from FTilePt)
//   +0x08: s32  m_tileY     (from FTilePt)
//   +0x0C: cXObjectImpl* m_parent
//   +0x10: int  m_slot      (-1 if no slot)
//   +0x14: int  m_level
// ============================================================================
struct PlacementSpec {
    PlacementSpec(bool valid);
    PlacementSpec(cXObjectImpl* impl);
    PlacementSpec(FTilePt& tile, int level, cXObjectImpl* parent, int slot);

    int m_valid;            // +0x00
    s32 m_tileX;            // +0x04
    s32 m_tileY;            // +0x08
    cXObjectImpl* m_parent; // +0x0C
    int m_slot;             // +0x10
    int m_level;            // +0x14
};

// ============================================================================
// HierarchySite - Describes a position in the object hierarchy
// Size: 0x18 (24 bytes) - same layout as PlacementSpec
// ============================================================================
struct HierarchySite {
    HierarchySite(cXObjectImpl* impl);
    HierarchySite(PlacementSpec* spec);
    HierarchySite(cXObjectImpl* impl, FTilePt& tile, int level);
    HierarchySite(FTilePt& tile, int level);

    int m_valid;            // +0x00
    s32 m_tileX;            // +0x04
    s32 m_tileY;            // +0x08
    cXObjectImpl* m_parent; // +0x0C
    int m_slot;             // +0x10
    int m_level;            // +0x14
};

// ============================================================================
// ObjDef - Object definition data
// Accessed via cXObjectImpl at +0x88
// ============================================================================
class ObjDef {
public:
    // +0x12: s16 m_type
    // +0x14: s16 m_multiTileCount (non-zero = multi-tile)
    char _pad[0x20]; // placeholder
};

// ============================================================================
// ObjectModule - Module that owns/manages object instances
// ============================================================================
class ObjectModule {
public:
    // Virtual function table used for various callbacks
    // The cXObjectImpl uses vcalls through this
};

// ============================================================================
// cXObjectImpl - Full implementation of a game object
// Size: at least 0xEC bytes
//
// Member layout (from disassembly):
//   +0x00: vtable (cXObject vtable)
//   +0x04: cXObject* m_pXObject (back-pointer to cXObject)
//   +0x08: short* m_pAttrArray  (attribute array)
//   +0x0C: int m_numAttr
//   +0x10: padding
//   +0x14: padding
//   +0x16: short m_temps[kNumTemp] (temp variables, accessed via index*2)
//   +0x28: EdithVariableSet m_edithVars (variable storage)
//   +0x58: ObjectModule* m_pModule
//   +0x5C: cXObjectImpl* m_pNextImpl (linked list)
//   +0x60: EMat4* m_pRelMatrix
//   +0x64: s16 m_objectID
//   +0x68: FTilePt m_location (8 bytes)
//   +0x70: FTileRect m_rect (starts at +0x70)
//   +0x80: int m_level
//   +0x84: int m_miscFlags
//   +0x88: ObjDef* m_pDef
//   +0x8C: ObjSelector* m_pSelector
//   +0x90: HierarchySite* m_hierSlots (array)
//   +0x94: HierarchySite* m_hierSlotsEnd (end pointer)
//   +0x98: padding
//   +0x9C: padding
//   +0xA0: RoutingSlot* m_routingSlotsBegin
//   +0xA4: RoutingSlot* m_routingSlotsEnd
//   +0xB0: int m_spriteSlot
//   +0xC4: int m_drawLabelFlag
//   +0xC8: padding
//   +0xCC: int m_overrideRenderPosActive
//   +0xD0: float m_overrideRenderX
//   +0xD4: float m_overrideRenderY
//   +0xD8: padding
//   +0xDC: s8 m_syncObject
//   +0xE0: padding
//   +0xE4: int m_waitingForSync
//   +0xE8: int m_graphicsTagged
//   +0xEC: padding
// ============================================================================
class cXObjectImpl {
public:
    cXObjectImpl(int id, ObjSelector* selector, ObjectModule* module);
    virtual ~cXObjectImpl();

    // Initialization / lifecycle
    void Initialize();
    void Reset(bool flag);
    void JustBorn();
    void PostLoad(int param, bool flag);
    void PreSave();
    void Cleanup(cXObject* obj);
    void UpdateAge();
    void DayPassed();
    void Kill();

    // Identity
    cXObjectImpl* CastToObjectImpl();
    cXObjectImpl* GetObjectImplementation();
    int GetNumAttr();
    const char* GetName() const;
    int GetType();
    s16 GetID();
    ObjDef* GetDef();
    ObjSelector* GetSelector();
    ObjSelector* GetSelector() const;

    // Data access
    short GetData(int index);
    void SetData(int index, short value);
    short GetTemp(int index);
    void SetTemp(int index, short value);
    short GetAttr(int index);
    void SetAttr(int index, short value);
    bool ContainsData(int key);

    // Location / placement
    FTilePt* GetLocation();
    void GetLocation(FTilePt* outTile) const;
    int GetLevel() const;
    void SetLevel(int level);
    void GetCTilePt() const;
    void* GetRect();
    bool IsInWorld();
    void GetAverageLocation() const;
    void SetLocation(FTilePt& tile, int level);
    void ComputeRect(FTilePt& tile, FTileRect* outRect);

    // Hierarchy
    int GetNextObjectSibling();
    int GetPrevObjectSibling();
    HierarchySite* HierGetSlot(int index);
    int HierCountSlots();
    void HierGetChild(int slot);
    void HierGetSite(HierarchySite* site);
    void HierGetParent();
    void HierSetSite(HierarchySite* site);
    void HierSever();
    void HierGetObject(HierarchySite* site);
    bool IsContained();
    int GetContainerID();
    int GetContainedSlotNum();
    void* GetContainer();
    void GetObjectSlot(int slot);
    void ExtractContainedSims();

    // Object slots (routing + containment)
    int CountObjectSlots();
    void* GetContainedObject(int slot);
    int GetNumRoutingSlots();
    void* GetRoutingSlot(int index);

    // Placement
    void GetPlacementSpec(PlacementSpec* spec);
    void GetPlacementInfo(FTilePt* tile, int* level, cXObject** parent, short* slot, bool* valid);
    void GetRootObject(FTilePt& tile, int level);
    void GetObstacleAtLocation(FTilePt& tile, int level, bool flag);
    void TestAndPlace(PlacementSpec* spec, bool flag);
    void Place(FTilePt& tile, int level, cXObject* parent, int slot);
    bool CanPlace(FTilePt& tile, int level, cXObject* parent, int slot);
    void Pickup();
    void Turn(int direction);
    void ForceLocation();
    bool IsPartOfMe(cXObject* obj);
    void TestIntersection(FTilePt& tile, int direction);
    void FindGoodLocation(FindGoodLocationParams& params, FTilePt* outTile);

    // Rendering / display
    int GetHilite();
    void SetHilite(int value);
    int GetSpriteSlot();
    bool IsBeingDraggedAround();
    void SetDrawLabel(bool enable);
    bool OverrideRenderPosition(float& x, float& y);
    void SetOverrideRenderPosition(float x, float y);
    void GetOverrideRenderPosition(float& x, float& y);
    void ClearOverrideRenderPosition();
    u8 GetColorIndex() const;
    void SetColorIndex(u8 index);
    bool IsSpriteVisible(short id);
    void GetNumTiles(int& width, int& height);
    void* GetRelMatrix();
    bool HaveGraphicsBeenTagged();
    void TagGraphicsField();

    // Tree execution
    void RunTree(ObjEntryPoint entry, short param, short* result);
    void RunTree(char* treeName);
    short GetTreeID(ObjEntryPoint entry);
    void* GetFnTable();
    void* GetTreeTab();

    // Animation
    void* GetAdultAnimTable();
    void* GetChildAnimTable();

    // Object properties
    void SetMiscFlag(cXObject::MiscFlag flag, bool value);
    bool GetMiscFlag(cXObject::MiscFlag flag);
    bool IsRenderingRoot();
    bool IsEmissive();
    bool IsMultiTile();
    int GetFlags();
    int GetWallPlacementFlags();
    int GetWallBlockFlags();
    int GetSize();
    void* GetSim();
    int GetBuildModeType();
    bool IsSupport();
    bool CanContributeLight();
    int GetLightingContribution();
    int GetObjectLightSource();
    bool IsBroken();
    bool IsDirty();
    bool IsBurning();
    bool CanBurn();
    bool IsFireproof();
    bool HasZeroExtent();
    bool CanIntersectPeople();
    bool IsChair();
    bool IsOccupied();
    bool IsVehicle();
    bool IsPerson();
    bool IsPortal();
    bool IsWindow();
    bool IsDoor();
    bool IsRoof();
    void HideForCutaway();
    bool IsFromCatalog();
    bool GetWasPlacedFromInventory();
    void SetWasPlacedFromInventory(bool value);
    bool ShouldAutoRotate();
    int GetRequiredSegment();
    bool CanChooseAutonomously();
    void UpdateSimFlags();
    bool IsDeletedByEvict();
    int GetFrontFaceDirection();
    void GetTileWidth();
    void GetAgeInMinutes();

    // Sim query
    bool SimIndependent();
    bool SimEnabled();
    void EnableSim(bool enable);
    int GetIdleStatus();
    void SetIdleStatus(int status);
    void ClearIdleStatus();

    // Module access
    ObjectModule* GetModule();
    void* GetFolder();
    void* GetSelFile();
    void* GetBehavior();

    // Current value
    void GetCurrentValue();

    // Room
    int GetRoom();

    // Object iteration
    cXObject* GetObjectFromID(short id);
    cXObject* GetNext();
    cXObjectImpl* GetNextImpl();
    cXObject* GetFirst();
    cXObjectImpl* GetFirstImpl();

    // Sync
    s8 GetSyncObject();
    void ClearSyncObject();
    bool WaitingForSync();
    void SyncObjectIsReady(s8 value);
    void SyncObjectIsReady();
    void SetSyncObject(s8 value);

    // Probe
    ObjectProbe* GetObjectProbe();
    void SetObjectProbe(ObjectProbe* probe);

    // Interactions
    void GetInteractionLeader();
    bool UserCanPickup();
    bool UserCanDelete();
    void UserPlace(FTilePt& tile, int level, cXObject* parent, int slot);
    void UserPickup(bool flag);
    bool UserCanPlace(FTilePt& tile, int level, cXObject* parent, int slot);

    // Reconnect
    void ReconHeader(ReconBuffer* buffer, int direction);
    void ReconStream(ReconBuffer* buffer, int direction, bool flag);
    void ReconSlots(ReconBuffer* buffer, int direction);
    u32 ReconType();

    // Distance
    void CalcShortDistance(cXObject* obj);
    void CalcShortDistanceIn16thsOfTiles(cXObject* obj);
    void CalcDistanceWithPentalties(cXObject* obj);
    void CalcShortDistance(FTilePt* tile);
    void CalcDistance(cXObject* obj);

    // Chair facing
    void UpdateChairFacing();
    void UpdateChairFacing(ObjectModule* module, int a, int b, int c);

    // Wall adjacency
    void UpdateWallAdjacency();
    void RequiresWallAdjacency();
    void SimObjectPlaced(ISimInstance* instance);

    // Placement info
    void GetTypeName(BString& name);
    void GetSlotHeight(int slot);

    // FreeWill/AutoCenter/AutoReset (delegated to cXObject statics)
    bool GetFreeWill();
    bool GetAutoCenter();
    void SetAutoCenter(bool value);
    bool GetAutoReset();
    void SetAutoReset(bool value);

    // Override dialog return code
    void SetOverrideDialogReturnCode(TreeReturnCode code);

    // IsInteractionTile
    bool IsInteractionTile();

    // Static table used by direction computations
    static int sXDirTable[];
};

// ============================================================================
// External functions referenced by object.cpp
// ============================================================================
extern void __static_initialization_and_destruction_0(int init, int priority);

#endif // OBJECT_H
