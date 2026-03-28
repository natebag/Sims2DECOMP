#ifndef SLOTS_H
#define SLOTS_H

#include "types.h"

// Forward declarations
class SlotDescriptor;
class cXObject;
class cXPerson;
class ObjSelector;
class ReconBuffer;
class BString;
class StringBuffer;
struct ObjectDataID;
class iResFile;

// Height enum used by ObjectSlot
enum StdHeight {};

// ============================================================================
// Slot - Base class for all slot types
// Size: 0x04 (vtable pointer only)
// Vtable at 0x80464A30
// ============================================================================
class Slot {
public:
    Slot();
    Slot(SlotDescriptor* desc);
    virtual ~Slot();
    virtual void WriteSlot(SlotDescriptor* desc);
};

// ============================================================================
// RoutingSlot - Controls NPC pathfinding to object slots
// Size: 0x3C (inherits Slot)
// Vtable at 0x804649D0
//
// Flag bits in m_flags (+0x1C):
//   Bits 0-7:  Direction allowed mask (8 compass directions)
//   Bit 8:     AllowAnyRotation (0x100)
//   Bit 9:     Absolute (0x200)
//   Bit 11:    IgnoreRooms (0x800)
//   Bit 12:    SnapsToDirection (0x1000)
//   Bit 13:    HasRandomScoring (0x2000)
//   Bit 14:    AllowFailureTrees (0x4000)
//   Bit 15:    AllowDifferentAlts (0x8000)
//   Bit 16:    UseAverageObjectLocation (0x10000)
// ============================================================================
class RoutingSlot : public Slot {
public:
    enum VerticalPosition {
        kAbove = 0,
        kLevel = 1,
        kBelow = 2
    };

    RoutingSlot();
    RoutingSlot(SlotDescriptor* desc);
    virtual ~RoutingSlot();
    virtual void WriteSlot(SlotDescriptor* desc);

    // Setters
    void SetIsOnTopOfObject();
    void AllowDirection(int dir);
    void AllowAnyRotation();
    void AllowAnyFacing();
    void FaceTowardsObject();
    void FaceAwayFromObject();
    void SetFacingDirection(int dir);
    void SetDistances(int minDist, int maxDist, int optimalDist);
    void SetTileDistances(float minDist, float maxDist, float optimalDist);
    void SetMultiplier(VerticalPosition pos, int value);
    void SetIgnoreRooms(bool ignore);
    void SetHasRandomScoring(bool random);
    void SetAllowFailureTrees(bool allow);
    void SetAllowDifferentAlts(bool allow);
    void SetUseAverageObjectLocation(bool use);
    void SetResolution(int res);

    // Getters
    bool IsOnTopOfObject() const;
    bool IsDirectionAllowed(int dir) const;
    bool IsAnyRotationAllowed() const;
    bool IsAnyFacingAllowed() const;
    bool IsFacingTowardsObject() const;
    bool IsFacingAwayFromObject() const;
    int GetFacingDirection() const;
    bool GetIgnoreRooms() const;
    int GetMinDist() const;
    int GetMaxDist() const;
    int GetOptimalDist() const;
    int GetResolution() const;
    float GetGradient() const;
    int GetMultiplier(VerticalPosition pos) const;
    int GetSnapTargetSlot() const;
    bool SnapsToDirection() const;
    int GetSnapDirection() const;
    bool Absolute() const;
    bool HasRandomScoring() const;
    bool GetAllowFailureTrees() const;
    bool GetAllowDifferentAlts() const;
    bool GetUseAverageObjectLocation() const;
    float GetXOffset() const;
    float GetYOffset() const;
    float GetAltOffset() const;

    // Member layout (offsets from this pointer):
    // +0x00: vtable (inherited from Slot)
    float m_xOffset;            // +0x04
    float m_yOffset;            // +0x08
    float m_altOffset;          // +0x0C
    int m_multipliers[3];       // +0x10 (indexed by VerticalPosition)
    u32 m_flags;                // +0x1C
    int m_snapTargetSlot;       // +0x20
    int m_minDist;              // +0x24
    int m_maxDist;              // +0x28
    int m_optimalDist;          // +0x2C
    float m_gradient;           // +0x30
    int m_facingDirection;      // +0x34
    int m_resolution;           // +0x38
};

// ============================================================================
// ObjectSlot - A slot where objects can be placed on another object
// Size: 0x20 (inherits Slot)
// Vtable at 0x80464A10
// ============================================================================
class ObjectSlot : public Slot {
public:
    ObjectSlot();
    ObjectSlot(SlotDescriptor* desc);
    virtual ~ObjectSlot();
    virtual void WriteSlot(SlotDescriptor* desc);

    void SetHeight(StdHeight height);
    int GetHeight();
    bool IsSurface();
    bool IsFreePos();

    static int GetHeightMask(StdHeight height);

    // +0x00: vtable (inherited from Slot)
    u16 m_type;                 // +0x04 (short, initialized to 0)
    u16 m_pad06;                // +0x06
    int m_height;               // +0x08
    int m_defaultHeight;        // +0x0C (initialized to 50)
    u32 m_flags;                // +0x10 (bit 0 = surface, bit 1 = freePos)
    float m_xOffset;            // +0x14
    float m_yOffset;            // +0x18
    float m_altOffset;          // +0x1C
};

// ============================================================================
// SpriteSlot - A slot that displays a sprite/visual effect on an object
// Size: 0x68 (inherits Slot)
// Vtable at 0x804649F0
// ============================================================================
class SpriteSlot : public Slot {
public:
    SpriteSlot(cXObject* obj);
    SpriteSlot(SlotDescriptor* desc, cXObject* obj);
    virtual ~SpriteSlot();
    virtual void WriteSlot(SlotDescriptor* desc);

    void Reset();
    void SetSprite(unsigned int spriteID, int numFrames, int startFrame, bool loop);
    void SetSprite(ObjSelector* selector);
    void ChangeToSprite(int spriteID);
    void AlternateWithSprite(int altSpriteID, int altFrameCount);
    void Tick();
    void ActivateForTicks(int ticks);
    void ActivateForLoops(int loops);
    void ActivateForever();
    void Deactivate();
    bool IsActive() const;

    void UseBalloonSprite(int id);
    void UseOverlaySprite(int id);
    void SetOptions(int options);
    void SetPopSize(float size);
    void SetPriority(int priority);
    void SetShowOverInactivePeople(bool show);
    void SetAltOffset(float offset);

    int GetTicksPerFrame();
    ObjSelector* GetSelector() const;
    int GetSpriteID() const;
    int GetBalloonSpriteID() const;
    int GetOverlaySpriteID() const;
    int GetCurrentFrame() const;
    cXPerson* GetPPerson();
    int GetPriority() const;
    int GetOptions() const;
    bool GetIsSkillMeter() const;
    bool GetShowOverInactivePeople() const;
    float GetAltOffset() const;
    float GetSizeMultiplierX() const;
    float GetSizeMultiplierY() const;
    float GetAlpha() const;

    // +0x00: vtable (inherited from Slot)
    float m_xOffset;            // +0x04
    float m_yOffset;            // +0x08
    float m_altOffset;          // +0x0C
    int m_tickCount;            // +0x10
    int m_pad14;                // +0x14
    int m_spriteID;             // +0x18
    int m_altSpriteID;          // +0x1C
    int m_altFrameCount;        // +0x20
    int m_pad24;                // +0x24
    ObjSelector* m_pSelector;   // +0x28
    int m_numFrames;            // +0x2C
    int m_currentFrame;         // +0x30
    int m_pad34;                // +0x34
    int m_pad38;                // +0x38
    int m_balloonSpriteID;      // +0x3C
    int m_overlaySpriteID;      // +0x40
    int m_priority;             // +0x44
    int m_options;              // +0x48
    float m_defaultAltOffset;   // +0x4C
    float m_sizeMultiplierX;    // +0x50
    float m_sizeMultiplierY;    // +0x54
    float m_alpha;              // +0x58
    float m_popSize;            // +0x5C
    int m_showOverInactivePeople; // +0x60
    cXPerson* m_pPerson;        // +0x64
};

// ============================================================================
// SlotLoader - Loads/saves slot definitions from resources
// Size: 0x08
// ============================================================================
class SlotLoader {
public:
    SlotLoader(unsigned int id);
    ~SlotLoader();

    int Save(short, void*, void*, void*, cXObject*);
    void GetSlotName(Slot* slot, BString& name, int index);

    u32 m_id;                   // +0x00
    u16 m_count;                // +0x04
};

// ============================================================================
// SlotDescriptor - Serializable description of a slot
// Size: 0x48 (72 bytes)
// ============================================================================
class SlotDescriptor {
public:
    SlotDescriptor();
    void DoStream(ReconBuffer* buffer, int direction);

    u16 m_type;                 // +0x00
    u16 m_pad02;                // +0x02
    float m_xOffset;            // +0x04
    float m_yOffset;            // +0x08
    float m_altOffset;          // +0x0C
    char m_data[0x38];          // +0x10 to +0x48 (remaining fields TBD)
};

// ============================================================================
// ObjectDataSlotDescList - Base class for slot descriptor list resources
// Vtable at 0x80464B90
// ============================================================================
class ObjectDataSlotDescList {
public:
    ObjectDataSlotDescList();
    virtual ~ObjectDataSlotDescList();

    virtual void GetResourceName(StringBuffer& name) const;
    virtual int SetResourceName(StringBuffer& name);
    virtual void GetDataID(ObjectDataID& id) const;
    // Additional virtuals defined by subclasses

    // +0x00: vtable
    char m_resourceName[0x48];  // +0x04 (StringBuffer inline data)
    char m_dataID[0x10];        // +0x4C (ObjectDataID inline data)
};

// ============================================================================
// QuickDataSlotDescList - Read-only cached slot descriptor list
// Vtable at 0x80464AF0
// ============================================================================
class QuickDataSlotDescList : public ObjectDataSlotDescList {
public:
    QuickDataSlotDescList();
    virtual ~QuickDataSlotDescList();

    int LoadFromDataID(ObjectDataID& id);
    int LoadFromIndex(unsigned int index, int type);
    int QueryInterface(unsigned int iid, void** ppObj);
    int AddRef();
    int Release();
    int SaveDataByID(ObjectDataID& id);
    int GetDataSourceType() const;
    int LoadOnlyNameAndIDFromIndex(unsigned int index, int type);
    int AddSlot(SlotDescriptor& desc);
    int RemoveSlot(int index);
    int GetNumSlots();
    SlotDescriptor* GetSlot(int index);
    int GetStringSetID() const;
    void SetStringSetID(int id);

    // Additional members beyond ObjectDataSlotDescList:
    // +0x54: SlotDescriptor* m_pSlots (ReconStreamVector data pointer, has count at -4)
    // +0x58: padding
    // +0x5C: int m_refCount
};

// ============================================================================
// IFFSlotDescList - Editable IFF-backed slot descriptor list
// Vtable at 0x80464A50
// ============================================================================
class IFFSlotDescList : public ObjectDataSlotDescList {
public:
    IFFSlotDescList();
    virtual ~IFFSlotDescList();

    int LoadFromDataID(ObjectDataID& id);
    int LoadFromIndex(unsigned int index, int type);
    int LoadOnlyNameAndIDFromIndex(unsigned int index, int type);
    int SaveDataByID(ObjectDataID& id);
    int QueryInterface(unsigned int iid, void** ppObj);
    int AddRef();
    int Release();
    int AddSlot(SlotDescriptor& desc);
    int RemoveSlot(int index);
    int GetNumSlots();
    SlotDescriptor* GetSlot(int index);
    int GetStringSetID() const;
    void SetStringSetID(int id);
    int GetDataSourceType() const;

    // Additional members beyond ObjectDataSlotDescList:
    // +0x54: SlotDescriptor* m_pSlotsBegin (vector begin iterator)
    // +0x58: SlotDescriptor* m_pSlotsEnd (vector end iterator)
    // ... more vector members
    // +0x64: int m_refCount
};

#endif // SLOTS_H
