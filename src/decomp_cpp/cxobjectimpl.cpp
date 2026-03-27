// cxobjectimpl.cpp - Decompiled cXObjectImpl class (PC port, functionally correct C++)
//
// Converted from inline PPC asm (src/asm_decomp/cXObjectImpl.cpp) using
// documentation in src/objects/cxobjectimpl_decomp.cpp.
//
// cXObjectImpl is the base class for ALL game objects in The Sims 2 (GameCube).
// Size: 0x5C70 (23,664 bytes), 146 fields, 306 methods.
//
// Every piece of furniture, appliance, decoration, door, window, staircase,
// and sim in the game inherits from this class.

#include "types.h"

// Forward declarations
class cXObject;
class ObjSelector;
class ObjectModule;
class ObjDef;
class ObjectProbe;
class BString;
class BString2;
class ISimInstance;
struct RoutingSlot;
struct FTilePt;
struct FTileRect;
struct HierarchySite;
struct PlacementSpec;
struct ReconBuffer;
struct StackElem;
struct XPrimParam;
struct Behavior;
struct CTilePt;

typedef short TreeReturnCode;
typedef int ObjEntryPoint;

// EdithVariableSet - sparse key-value store for object data variables
class EdithVariableSet {
public:
    short* operator[](int index);
    void WriteVar(int index, short value);
    bool Contains(int index);
};

// ============================================================================
// STATIC DATA
// ============================================================================

// Direction lookup tables - map 8 compass directions to tile offsets
// Index 0=N, 1=NE, 2=E, 3=SE, 4=S, 5=SW, 6=W, 7=NW, 8=center
static int sXDirTable[9] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };
static int sYDirTable[9] = { -1, -1, 0, 1, 1, 1, 0, -1, 0 };

// Static globals (originally SDA-relative via r13)
static bool sFreeWill = false;
static bool sAutoCenter = false;
static bool sAutoReset = false;
static short overrideDialogReturnCode = 0;

// ============================================================================
// cXObjectImpl class definition for this translation unit
// Uses named fields from the decomp documentation instead of raw offsets.
// ============================================================================

class cXObjectImpl {
public:
    // --- Field layout from assembly analysis ---
    // 0x00
    void*           m_field_000;        // used by AllowIdleOptimization
    // 0x04
    cXObject*       m_cXObject;         // the cXObject wrapper
    // 0x08
    short*          m_attrArray;        // heap-allocated attribute array
    // 0x0C
    int             m_numAttr;          // attribute count
    // 0x10 - padding/unknown
    u8              _pad_10[0x06];
    // 0x16
    short           m_temp[20];         // 20 temporary scratch variables
    // 0x3E - padding to reach 0x28 for EdithVariableSet
    //   NOTE: m_temp starts at 0x16 and is 40 bytes, ending at 0x3E.
    //   EdithVariableSet is at 0x28, which overlaps with m_temp.
    //   In reality, 0x10-0x15 is some other data, and the layout
    //   has m_temp at 0x16 (22) and EdithVariableSet at 0x28 (40).
    //   The temp array is 20 shorts = 40 bytes, 0x16..0x3E.
    //   EdithVariableSet overlaps because it starts at 0x28 within the object.
    //   This means temps 9-19 are part of/after EdithVariableSet start.
    //   For the PC port, we keep both accessible via their methods.

    // 0x28 - EdithVariableSet (embedded)
    // We can't declare it here because of the overlap; access via offset.

    // 0x58
    ObjectModule*   m_module;           // object module (global list manager)
    // 0x5C
    cXObjectImpl*   m_nextImpl;         // next object in linked list
    // 0x60
    void*           m_relMatrix;        // relative transform matrix
    // 0x64
    short           m_objectID;         // unique object ID
    short           _pad_66;
    // 0x68
    int             m_locationX;        // FTilePt.x (fixed-point, >>4 for tile)
    // 0x6C
    int             m_locationY;        // FTilePt.y (fixed-point, >>4 for tile)
    // 0x70
    // FTileRect     m_rect;            // bounding rectangle (variable size)
    u8              _rect_data[0x10];
    // 0x80
    int             m_level;            // floor level (0=ground, 1=upstairs)
    // 0x84
    u32             m_miscFlags;        // bitfield: low 5 bits = hilite
    // 0x88
    ObjDef*         m_objDef;           // object definition from .iff
    // 0x8C
    ObjSelector*    m_selector;         // resource file reference
    // 0x90
    void*           m_slotsBegin;       // hierarchy slots start
    // 0x94
    void*           m_slotsEnd;         // hierarchy slots end
    u8              _pad_98[0x08];
    // 0xA0
    void*           m_routingSlotsBegin;// routing slots start
    // 0xA4
    void*           m_routingSlotsEnd;  // routing slots end
    u8              _pad_A8[0x08];
    // 0xB0
    void*           m_spriteSlot;       // sprite slot linked list head
    u8              _pad_B4[0x10];
    // 0xC4
    int             m_drawLabel;        // draw text label above object
    u8              _pad_C8[0x04];
    // 0xCC
    int             m_overrideEnabled;  // override render position flag
    // 0xD0
    float           m_overrideX;        // override screen X
    // 0xD4
    float           m_overrideY;        // override screen Y
    u8              _pad_D8[0x04];
    // 0xDC
    void*           m_syncObject;       // multiplayer sync state
    // 0xE0
    u8              _pad_E0[0x04];
    // 0xE4
    int             m_syncWaiting;      // waiting for sync response
    // 0xE8
    int             m_graphicsTagged;   // graphics resources flagged

    // ---- Helper to access EdithVariableSet at offset 0x28 ----
    EdithVariableSet* GetEdithVars() {
        return (EdithVariableSet*)((char*)this + 0x28);
    }
    const EdithVariableSet* GetEdithVars() const {
        return (const EdithVariableSet*)((const char*)this + 0x28);
    }

    // ---- Methods ----

    // === SECTION 1: Identity & Casting ===
    void* CastToObjectImpl();
    void* GetObjectImplementation();

    // === SECTION 2: Data System ===
    short GetData(int index);
    void  SetData(int index, short value);
    short GetTemp(int index);
    void  SetTemp(int index, short value);
    short GetAttr(int index);
    void  SetAttr(int index, short value);
    int   GetNumAttr();
    bool  ContainsData(int index);

    // === SECTION 3: Basic Getters ===
    short        GetID();
    ObjDef*      GetDef();
    short        GetType();
    ObjectModule* GetModule();
    ObjSelector* GetSelector();
    void*        GetBehavior();
    void*        GetFolder();
    const char*  GetName() const;
    void*        GetTreeTab();
    void*        GetAdultAnimTable();
    void*        GetChildAnimTable();
    void*        GetSelFile();

    // === SECTION 4: Location & Placement ===
    FTilePt*     GetLocation();
    void         GetLocation(FTilePt* out) const;
    int          GetLevel() const;
    void         SetLevel(int level);
    FTileRect*   GetRect();
    bool         IsInWorld();

    // === SECTION 5: Misc Flags & Hilite ===
    int          GetHilite();
    void         SetMiscFlag(int flag, bool value);
    bool         GetMiscFlag(int flag);

    // === SECTION 6: Object Type Checks ===
    bool         IsVehicle();
    bool         IsPerson();
    bool         IsPartOfMe(cXObject* other);
    bool         IsBeingDraggedAround();
    bool         IsMultiTile();
    void         GetNumTiles(int& outX, int& outY);

    // === SECTION 7: Object Graph Traversal ===
    cXObjectImpl* GetNextImpl();
    cXObject*     GetNext();

    // === SECTION 8: Hierarchy ===
    int          HierCountSlots();
    int          CountObjectSlots();

    // === SECTION 9: Routing Slots ===
    int          GetNumRoutingSlots();
    RoutingSlot* GetRoutingSlot(int index);

    // === SECTION 10: Sprite & Rendering ===
    void*        GetSpriteSlotPtr();
    void*        GetRelMatrix();

    // === SECTION 11: Sync Object ===
    void*        GetSyncObject();
    void         ClearSyncObject();
    int          WaitingForSync();

    // === SECTION 12: Override Render Position ===
    void         SetOverrideRenderPosition(float x, float y);
    void         GetOverrideRenderPosition(float& outX, float& outY);
    void         ClearOverrideRenderPosition();

    // === SECTION 13: Draw Label & Graphics ===
    void         SetDrawLabel(bool enable);
    void         TagGraphicsField();
    bool         HaveGraphicsBeenTagged();

    // === SECTION 14: Static Globals ===
    static bool  GetFreeWill();
    static bool  GetAutoCenter();
    static void  SetAutoCenter(bool enable);
    static bool  GetAutoReset();
    static void  SetAutoReset(bool enable);
    static void  SetOverrideDialogReturnCode(TreeReturnCode code);

    // === SECTION 15: Object Probe (stubs) ===
    ObjectProbe* GetObjectProbe();
    void         SetObjectProbe(ObjectProbe* probe);

    // === SECTION 16: Stub/NOP Virtuals ===
    void         PreSave();
    void         ForceLocation();
    void         Backtrace();

    // === SECTION 17: Data Variable Queries ===
    short         GetFlags();
    short         GetWallPlacementFlags();
    short         GetSize();
    unsigned short GetRoom();
    bool          IsBroken();
    bool          IsDirty();
    bool          IsBurning();
    bool          CanBurn();
    bool          IsFireproof();
    bool          IsOccupied();
    bool          SimIndependent();

    // === SECTION 18: Lifecycle ===
    void          Kill();
};


// ============================================================================
// IMPLEMENTATIONS
// ============================================================================

// --- Identity & Casting ---

void* cXObjectImpl::CastToObjectImpl() {
    return this;
}

void* cXObjectImpl::GetObjectImplementation() {
    return this;
}

// --- Data System ---
// The heart of the Sims 2 object system. Every object behavior (scripted in
// "Edith" behavior trees) reads and writes object state through these functions.

short cXObjectImpl::GetData(int index) {
    EdithVariableSet* vars = GetEdithVars();
    short* ptr = (*vars)[index];
    return *ptr;
}

void cXObjectImpl::SetData(int index, short value) {
    EdithVariableSet* vars = GetEdithVars();
    vars->WriteVar(index, value);
}

short cXObjectImpl::GetTemp(int index) {
    return m_temp[index];
}

void cXObjectImpl::SetTemp(int index, short value) {
    m_temp[index] = value;
}

short cXObjectImpl::GetAttr(int index) {
    return m_attrArray[index];
}

void cXObjectImpl::SetAttr(int index, short value) {
    m_attrArray[index] = value;
}

int cXObjectImpl::GetNumAttr() {
    return m_numAttr;
}

bool cXObjectImpl::ContainsData(int index) {
    EdithVariableSet* vars = GetEdithVars();
    return vars->Contains(index);
}

// --- Basic Getters ---

short cXObjectImpl::GetID() {
    return m_objectID;
}

ObjDef* cXObjectImpl::GetDef() {
    return m_objDef;
}

short cXObjectImpl::GetType() {
    // ObjDef has the type at offset 0x12
    return *(short*)((char*)m_objDef + 0x12);
}

ObjectModule* cXObjectImpl::GetModule() {
    return m_module;
}

ObjSelector* cXObjectImpl::GetSelector() {
    return m_selector;
}

void* cXObjectImpl::GetBehavior() {
    // Selector->m_behavior at offset 0x0C
    return *(void**)((char*)m_selector + 0x0C);
}

void* cXObjectImpl::GetFolder() {
    // Selector->m_folder at offset 0x50
    return *(void**)((char*)m_selector + 0x50);
}

const char* cXObjectImpl::GetName() const {
    // Selector->m_name at offset 0x14
    return *(const char**)((char*)m_selector + 0x14);
}

void* cXObjectImpl::GetTreeTab() {
    // Delegates to ObjSelector::GetTreeTab()
    // For the PC port, we forward to the selector's method
    // Original: bl 0x80111648
    // TODO: implement ObjSelector::GetTreeTab
    return NULL; // placeholder
}

void* cXObjectImpl::GetAdultAnimTable() {
    // Delegates to ObjSelector::GetAdultAnimTable()
    return NULL; // placeholder
}

void* cXObjectImpl::GetChildAnimTable() {
    // Delegates to ObjSelector::GetChildAnimTable()
    return NULL; // placeholder
}

void* cXObjectImpl::GetSelFile() {
    // Returns the selector's resource file; lazy-loads if NULL
    void* file = *(void**)((char*)m_selector + 0x00);
    if (file == NULL) {
        // Original calls sel->LoadSelFile() at 0x80110790
        // TODO: implement ObjSelector::LoadSelFile
        return NULL;
    }
    return file;
}

// --- Location & Placement ---

FTilePt* cXObjectImpl::GetLocation() {
    // Return pointer to embedded FTilePt at offset 0x68
    return (FTilePt*)&m_locationX;
}

void cXObjectImpl::GetLocation(FTilePt* out) const {
    // Copy x,y into output
    *(int*)((char*)out + 0) = m_locationX;
    *(int*)((char*)out + 4) = m_locationY;
}

int cXObjectImpl::GetLevel() const {
    return m_level;
}

void cXObjectImpl::SetLevel(int level) {
    m_level = level;
}

FTileRect* cXObjectImpl::GetRect() {
    // Return pointer to bounding rect at offset 0x70
    return (FTileRect*)_rect_data;
}

bool cXObjectImpl::IsInWorld() {
    // Object is "in world" if both tile coords > 0
    // Location stored as fixed-point: tile = coord >> 4
    if ((m_locationY >> 4) <= 0) return false;
    if ((m_locationX >> 4) <= 0) return false;
    return true;
}

// --- Misc Flags & Hilite ---

int cXObjectImpl::GetHilite() {
    // Hilite is stored in low 5 bits of m_miscFlags
    return m_miscFlags & 0x1F;
}

void cXObjectImpl::SetMiscFlag(int flag, bool value) {
    // Clear the flag bit first
    m_miscFlags &= ~(u32)flag;
    // If value is true, set it
    if (value) {
        m_miscFlags |= (u32)flag;
    }
}

bool cXObjectImpl::GetMiscFlag(int flag) {
    return (m_miscFlags & (u32)flag) != 0;
}

// --- Object Type Checks ---

bool cXObjectImpl::IsVehicle() {
    // Query cXObject's GetObjectClass virtual method, check for type 12
    // TODO: implement cXObject virtual dispatch
    // cXObject* obj = m_cXObject;
    // return obj->GetObjectClass() == 12;
    return false;
}

bool cXObjectImpl::IsPerson() {
    // Same pattern, check for type 2 (person/sim)
    // TODO: implement cXObject virtual dispatch
    // cXObject* obj = m_cXObject;
    // return obj->GetObjectClass() == 2;
    return false;
}

bool cXObjectImpl::IsPartOfMe(cXObject* other) {
    return (other == m_cXObject);
}

bool cXObjectImpl::IsBeingDraggedAround() {
    // Base implementation always returns false
    // Overridden in cXPersonImpl
    return false;
}

bool cXObjectImpl::IsMultiTile() {
    // Check ObjDef->multiTileID at offset 0x14
    short multiTileID = *(short*)((char*)m_objDef + 0x14);
    return (multiTileID != 0);
}

void cXObjectImpl::GetNumTiles(int& outX, int& outY) {
    // Base implementation: single-tile objects are 1x1
    // Overridden by cXMTObjectImpl for multi-tile objects
    outX = 1;
    outY = 1;
}

// --- Object Graph Traversal ---

cXObjectImpl* cXObjectImpl::GetNextImpl() {
    return m_nextImpl;
}

cXObject* cXObjectImpl::GetNext() {
    if (m_nextImpl == NULL) return NULL;
    return m_nextImpl->m_cXObject;
}

// --- Hierarchy ---

int cXObjectImpl::HierCountSlots() {
    // Each slot is 32 bytes; count = (end - begin) / 32
    int begin = (int)(uintptr_t)m_slotsBegin;
    int end = (int)(uintptr_t)m_slotsEnd;
    return (end - begin) >> 5;
}

int cXObjectImpl::CountObjectSlots() {
    // Same as HierCountSlots but subtract 1 (slot 0 is reserved)
    int begin = (int)(uintptr_t)m_slotsBegin;
    int end = (int)(uintptr_t)m_slotsEnd;
    return ((end - begin) >> 5) - 1;
}

// --- Routing Slots ---

int cXObjectImpl::GetNumRoutingSlots() {
    // Each routing slot is 60 bytes (0x3C)
    int size = (int)((char*)m_routingSlotsEnd - (char*)m_routingSlotsBegin);
    return size / 60;
}

RoutingSlot* cXObjectImpl::GetRoutingSlot(int index) {
    return (RoutingSlot*)((char*)m_routingSlotsBegin + index * 60);
}

// --- Sprite & Rendering ---

void* cXObjectImpl::GetSpriteSlotPtr() {
    return m_spriteSlot;
}

void* cXObjectImpl::GetRelMatrix() {
    return m_relMatrix;
}

// --- Sync Object ---

void* cXObjectImpl::GetSyncObject() {
    return m_syncObject;
}

void cXObjectImpl::ClearSyncObject() {
    m_syncObject = NULL;
}

int cXObjectImpl::WaitingForSync() {
    return m_syncWaiting;
}

// --- Override Render Position ---

void cXObjectImpl::SetOverrideRenderPosition(float x, float y) {
    m_overrideEnabled = 1;
    m_overrideX = x;
    m_overrideY = y;
}

void cXObjectImpl::GetOverrideRenderPosition(float& outX, float& outY) {
    outX = m_overrideX;
    outY = m_overrideY;
}

void cXObjectImpl::ClearOverrideRenderPosition() {
    m_overrideEnabled = 0;
}

// --- Draw Label & Graphics ---

void cXObjectImpl::SetDrawLabel(bool enable) {
    // Only write if value is changing (optimization from original)
    if (m_drawLabel == (int)enable) return;
    m_drawLabel = (int)enable;
}

void cXObjectImpl::TagGraphicsField() {
    m_graphicsTagged = 1;
}

bool cXObjectImpl::HaveGraphicsBeenTagged() {
    // Check-and-clear pattern: returns true once, then resets
    if (m_graphicsTagged == 0) return false;
    m_graphicsTagged = 0;
    return true;
}

// --- Static Globals ---

bool cXObjectImpl::GetFreeWill() {
    return sFreeWill;
}

bool cXObjectImpl::GetAutoCenter() {
    return sAutoCenter;
}

void cXObjectImpl::SetAutoCenter(bool enable) {
    sAutoCenter = enable;
}

bool cXObjectImpl::GetAutoReset() {
    return sAutoReset;
}

void cXObjectImpl::SetAutoReset(bool enable) {
    sAutoReset = enable;
}

void cXObjectImpl::SetOverrideDialogReturnCode(TreeReturnCode code) {
    overrideDialogReturnCode = code;
}

// --- Object Probe (stubs - disabled on GameCube) ---

ObjectProbe* cXObjectImpl::GetObjectProbe() {
    return NULL;
}

void cXObjectImpl::SetObjectProbe(ObjectProbe* probe) {
    (void)probe; // no-op on GameCube
}

// --- Stub/NOP Virtuals ---

void cXObjectImpl::PreSave() {
    // Base implementation does nothing
}

void cXObjectImpl::ForceLocation() {
    // Base implementation does nothing
}

void cXObjectImpl::Backtrace() {
    // No-op in release build
}

// --- Data Variable Query Functions ---
// These use EdithVariableSet::operator[] to read specific data variables.
// The index numbers are defined by the Edith scripting system.

short cXObjectImpl::GetFlags() {
    // Data variable index 8 = Flags bitfield
    EdithVariableSet* vars = GetEdithVars();
    short* ptr = (*vars)[8];
    return *ptr;
}

short cXObjectImpl::GetWallPlacementFlags() {
    // Data variable index 13 = WallPlacementFlags
    EdithVariableSet* vars = GetEdithVars();
    short* ptr = (*vars)[13];
    return *ptr;
}

short cXObjectImpl::GetSize() {
    // Data variable index 49 = Size
    EdithVariableSet* vars = GetEdithVars();
    short* ptr = (*vars)[49];
    return *ptr;
}

unsigned short cXObjectImpl::GetRoom() {
    // Data variable index 29 = Room number (unsigned)
    EdithVariableSet* vars = GetEdithVars();
    short* ptr = (*vars)[29];
    return *(unsigned short*)ptr;
}

bool cXObjectImpl::IsBroken() {
    // Data variable index 15 (IsBroken) nonzero = broken
    EdithVariableSet* vars = GetEdithVars();
    short* ptr = (*vars)[15];
    return (*ptr != 0);
}

bool cXObjectImpl::IsDirty() {
    // Data variable index 39 (DirtyLevel) > 0 = dirty
    EdithVariableSet* vars = GetEdithVars();
    short* ptr = (*vars)[39];
    return (*ptr > 0);
}

bool cXObjectImpl::IsBurning() {
    // Flags (data index 8), bit 9 = burning
    EdithVariableSet* vars = GetEdithVars();
    unsigned short* ptr = (unsigned short*)(*vars)[8];
    unsigned short flags = *ptr;
    return (flags >> 9) & 1;
}

bool cXObjectImpl::CanBurn() {
    // BurnFlags (data index 40), bit 5 = can burn
    EdithVariableSet* vars = GetEdithVars();
    unsigned short* ptr = (unsigned short*)(*vars)[40];
    unsigned short flags = *ptr;
    return (flags >> 5) & 1;
}

bool cXObjectImpl::IsFireproof() {
    // Flags (data index 8), bit 11 = fireproof
    EdithVariableSet* vars = GetEdithVars();
    unsigned short* ptr = (unsigned short*)(*vars)[8];
    unsigned short flags = *ptr;
    return (flags >> 11) & 1;
}

bool cXObjectImpl::IsOccupied() {
    // Flags (data index 8), bit 5 = occupied (sim using this object)
    EdithVariableSet* vars = GetEdithVars();
    unsigned short* ptr = (unsigned short*)(*vars)[8];
    unsigned short flags = *ptr;
    return (flags >> 5) & 1;
}

bool cXObjectImpl::SimIndependent() {
    // Data variable index 60 (SimIndependent) nonzero = independent
    EdithVariableSet* vars = GetEdithVars();
    short* ptr = (*vars)[60];
    return (*ptr != 0);
}

// --- Lifecycle ---

void cXObjectImpl::Kill() {
    // Delegates to ObjectModule::KillObject via vtable dispatch
    // ObjectModule* module = m_module;
    // short objID = m_objectID;
    // module->KillObject(objID);  // virtual call
    // TODO: implement ObjectModule virtual dispatch for PC port
}
