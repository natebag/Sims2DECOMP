// cxobjectimpl_decomp.cpp - Decompiled cXObjectImpl functions
// cXObjectImpl is the base class for ALL game objects in The Sims 2 (GameCube).
// Size: 23,664 bytes (0x5C70), 146 fields, 306 methods.
//
// Every piece of furniture, appliance, decoration, door, window, staircase,
// and sim in the game inherits from this class. Understanding it is essential
// for modding and the PC port.
//
// ARCHITECTURE OVERVIEW:
//
// cXObjectImpl wraps a cXObject and adds the "Edith" scripting data system
// (named after the original Sims 1 editor). The key subsystems are:
//
//   1. EdithVariableSet (offset 0x28) - The object data system
//      - Contains all per-object data variables indexed by category/slot
//      - operator[](int index) returns a pointer to a short value
//      - WriteVar(int index, short value) writes a value
//      - Contains(int index) checks if a data variable exists
//      - Indices are "Edith variable IDs" (see ObjectDataBehaviorConstants)
//
//   2. Temp variables (offset 0x16) - 20 temporary short values
//      - Used as scratch space by behavior trees during simulation
//      - Indexed 0-19, each is a short (2 bytes)
//      - Direct array access: this + 0x16 + (index * 2)
//
//   3. Attributes (offset 0x08) - Per-object attribute array
//      - m_numAttr (offset 0x0C) stores the count
//      - m_attrArray (offset 0x08) is a pointer to a short[] array
//      - Indexed by attribute number, each is a short
//
//   4. Placement/Location (offsets 0x68-0x80)
//      - FTilePt location at offset 0x68 (8 bytes: x=0x68, y=0x6C)
//      - FTileRect bounding rect at offset 0x70
//      - Level (floor number) at offset 0x80
//
//   5. Misc flags (offset 0x84) - Bitfield of boolean object states
//      - Hilite stored in low 5 bits
//      - Other flags set/cleared via SetMiscFlag/GetMiscFlag
//
//   6. Object hierarchy (offsets 0x90-0x94)
//      - Slots array for container/containment relationships
//      - Each slot is 32 bytes (shift right 5 to count)
//
//   7. Linked list (offsets 0x58, 0x5C)
//      - m_firstImpl at 0x58 = pointer to ObjectModule
//      - m_nextImpl at 0x5C = pointer to next cXObjectImpl in list
//
//   8. Object definition (offset 0x88)
//      - Pointer to ObjDef (object definition from .iff resource)
//      - Contains type ID, multi-tile info, and static properties
//
//   9. Selector (offset 0x8C)
//      - Pointer to ObjSelector (resource file reference)
//      - Links to behavior trees, animation tables, name, folder
//
//  10. Sync system (offsets 0xDC-0xE4)
//      - m_syncObject at 0xDC, m_syncE0 at 0xE0, m_syncE4 at 0xE4
//      - Used for multiplayer/split-screen object synchronization
//
//  11. Override render position (offsets 0xCC-0xD4)
//      - m_overrideEnabled at 0xCC
//      - m_overrideX at 0xD0 (float)
//      - m_overrideY at 0xD4 (float)
//
//  12. Draw label (offset 0xC4)
//      - Whether to draw a text label above the object
//
//  13. Graphics tag (offset 0xE8)
//      - Tracks whether graphics resources have been flagged
//
//  14. Routing slots (offsets 0xA0-0xA4)
//      - Array of routing slot positions
//      - Each routing slot is 60 bytes (0x3C)
//
//  15. Sprite slot list (offset 0xB0)
//      - Linked list of sprite/animation slots for rendering
//
// STATIC VARIABLES:
//   sFreeWill       (sdata -31912 from r13) - Global free will toggle
//   sAutoCenter     (sdata -31904 from r13) - Auto-center camera on object
//   sAutoReset      (sdata -31900 from r13) - Auto-reset object state
//   overrideDialogReturnCode (sdata -31828 from r13) - Dialog return override
//
// DIRECTION TABLES:
//   sXDirTable[9] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 }
//   sYDirTable[9] = { -1, -1, 0, 1, 1, 1, 0, -1, 0 }
//   These map 8 compass directions (+ center) to tile offsets.
//
// DATA VARIABLE INDICES (from EdithVariableSet, used with GetData/SetData):
//   Index  8 = Flags (bitfield: bit 9=burning, bit 5=occupied, bit 11=fireproof)
//   Index 13 = WallPlacementFlags
//   Index 15 = IsBroken (nonzero = broken)
//   Index 25 = SimTicksRemaining (countdown timer for simulation)
//   Index 29 = Room (room number the object is in)
//   Index 39 = DirtyLevel (>0 means dirty)
//   Index 40 = BurnFlags (bit 5 = CanBurn)
//   Index 49 = Size
//   Index 60 = SimIndependent flag
//
// All functions below are decompiled from the GameCube PowerPC assembly
// found in u2_ngc_release_dvd.elf. Each includes the original address
// and size for verification.

#include "types.h"

// Forward declarations
class cXObject;
class ObjSelector;
class ObjectModule;
class ObjDef;
class ObjectProbe;
class EdithVariableSet;
class FTilePt;
class FTileRect;
class HierarchySite;
class PlacementSpec;
class ReconBuffer;
class StackElem;
class XPrimParam;
class Behavior;
class BehaviorNode;
class BString;
class BString2;
class StringBuffer;
class ISimInstance;
struct RoutingSlot;

typedef short TreeReturnCode;
typedef int ObjEntryPoint;

// ============================================================================
// SECTION 1: STATIC DATA
// ============================================================================

// Direction lookup tables - map 8 compass directions to tile offsets
// Index 0 = North, 1 = NE, 2 = E, 3 = SE, 4 = S, 5 = SW, 6 = W, 7 = NW, 8 = center
// Address: 0x80424300 (sXDirTable), 0x80424324 (sYDirTable)
int cXObjectImpl::sXDirTable[9] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };
int cXObjectImpl::sYDirTable[9] = { -1, -1, 0, 1, 1, 1, 0, -1, 0 };

// ============================================================================
// SECTION 2: IDENTITY & CASTING
// ============================================================================

// 0x800EAA44 | 4 bytes
// Returns 'this' - cXObjectImpl IS the object implementation.
// Virtual method that derived classes can override.
void* cXObjectImpl::CastToObjectImpl(void) {
    return this;  // blr - just returns this (r3 unchanged)
}

// 0x800EB8DC | 4 bytes
// Also returns 'this' - same as CastToObjectImpl for this base class.
void* cXObjectImpl::GetObjectImplementation(void) {
    return this;  // blr - just returns this (r3 unchanged)
}

// ============================================================================
// SECTION 3: THE DATA SYSTEM - GetData / SetData / GetTemp / SetTemp / GetAttr
//
// This is the heart of the Sims 2 object system. Every object behavior
// (scripted in "Edith" behavior trees) reads and writes object state through
// these functions. The data variable system uses EdithVariableSet, which is
// a sparse key-value map of short values indexed by variable ID.
//
// GetData(index) -> looks up variable 'index' in EdithVariableSet
// SetData(index, value) -> writes variable 'index' in EdithVariableSet
// GetTemp(index) -> reads from the 20-slot temp array (scratch space)
// SetTemp(index, value) -> writes to the temp array
// GetAttr(index) -> reads from the attribute array (pointed to by field 0x08)
// SetAttr(index, value) -> writes to the attribute array
// ============================================================================

// 0x800EB0C4 | 40 bytes
// Reads an object data variable by index.
// The EdithVariableSet lives at this+0x28. operator[] returns a short*.
short cXObjectImpl::GetData(int index) {
    // addi r3, r3, 40 -> this+0x28 = EdithVariableSet
    // bl EdithVariableSet::operator[](int)
    // lha r3, 0(r3) -> load signed halfword from returned pointer
    short* ptr = ((EdithVariableSet*)((char*)this + 0x28))->operator[](index);
    return *ptr;
}

// 0x800EAEE8 | 36 bytes
// Writes an object data variable by index.
void cXObjectImpl::SetData(int index, short value) {
    // addi r3, r3, 40 -> this+0x28 = EdithVariableSet
    // bl EdithVariableSet::WriteVar(int, short)
    ((EdithVariableSet*)((char*)this + 0x28))->WriteVar(index, value);
}

// 0x800EB0EC | 16 bytes
// Reads a temporary variable. Temps are a flat array of 20 shorts
// starting at offset 0x16 in the object. No function call needed.
short cXObjectImpl::GetTemp(int index) {
    // slwi r4, r4, 1 -> index *= 2 (sizeof(short))
    // addi r3, r3, 22 -> base = this + 0x16
    // lhax r3, r3, r4 -> load signed halfword at base[index]
    return ((short*)((char*)this + 0x16))[index];
}

// 0x800EAF0C | 16 bytes
// Writes a temporary variable.
void cXObjectImpl::SetTemp(int index, short value) {
    // slwi r4, r4, 1 -> index *= 2
    // addi r3, r3, 22 -> base = this + 0x16
    // sthx r5, r3, r4 -> store halfword at base[index]
    ((short*)((char*)this + 0x16))[index] = value;
}

// 0x800EB0FC | 16 bytes
// Reads an attribute by index. Attributes are stored via a pointer at
// offset 0x08 (m_attrArray), which points to a heap-allocated short[].
short cXObjectImpl::GetAttr(int index) {
    // lwz r9, 8(r3) -> attrArray = this->m_attrArray (offset 0x08)
    // slwi r4, r4, 1 -> index *= 2
    // lhax r3, r4, r9 -> load signed halfword at attrArray[index]
    short* attrArray = *(short**)((char*)this + 0x08);
    return attrArray[index];
}

// 0x800EAF1C | 16 bytes
// Writes an attribute by index.
void cXObjectImpl::SetAttr(int index, short value) {
    // lwz r9, 8(r3) -> attrArray = this->m_attrArray
    // slwi r4, r4, 1 -> index *= 2
    // sthx r5, r4, r9 -> store halfword at attrArray[index]
    short* attrArray = *(short**)((char*)this + 0x08);
    attrArray[index] = value;
}

// 0x800EAA3C | 8 bytes
// Returns the number of attributes allocated for this object.
int cXObjectImpl::GetNumAttr(void) {
    // lwz r3, 12(r3) -> return this->m_numAttr (offset 0x0C)
    return *(int*)((char*)this + 0x0C);
}

// 0x800E325C | 36 bytes
// Checks if a data variable with the given index exists in the
// EdithVariableSet. Returns true if the variable is present.
bool cXObjectImpl::ContainsData(int index) {
    // addi r3, r3, 40 -> this+0x28 = EdithVariableSet
    // bl EdithVariableSet::Contains(int)
    return ((EdithVariableSet*)((char*)this + 0x28))->Contains(index);
}

// ============================================================================
// SECTION 4: BASIC GETTERS - Object identity and references
// ============================================================================

// 0x800EB2E0 | 8 bytes
// Returns the unique object ID (signed 16-bit at offset 0x64).
short cXObjectImpl::GetID(void) {
    // lha r3, 100(r3) -> sign-extended load from offset 0x64
    return *(short*)((char*)this + 0x64);
}

// 0x800EB2CC | 8 bytes
// Returns the object definition (ObjDef*) at offset 0x88.
// ObjDef contains the object's static properties loaded from .iff resources.
ObjDef* cXObjectImpl::GetDef(void) {
    // lwz r3, 136(r3) -> load pointer from offset 0x88
    return *(ObjDef**)((char*)this + 0x88);
}

// 0x800EB2D4 | 12 bytes
// Returns the object type ID from the ObjDef.
// ObjDef has the type at offset 0x12 (a signed short).
short cXObjectImpl::GetType(void) {
    // lwz r9, 136(r3) -> objDef = this->m_objDef
    // lha r3, 18(r9)  -> return objDef->type (offset 0x12 in ObjDef)
    ObjDef* def = *(ObjDef**)((char*)this + 0x88);
    return *(short*)((char*)def + 0x12);
}

// 0x800EB10C | 8 bytes
// Returns the ObjectModule* at offset 0x58.
// ObjectModule manages the global object list for the current lot.
ObjectModule* cXObjectImpl::GetModule(void) {
    // lwz r3, 88(r3) -> load pointer from offset 0x58
    return *(ObjectModule**)((char*)this + 0x58);
}

// 0x800EB328 | 8 bytes
// Returns the ObjSelector* at offset 0x8C.
// ObjSelector is the resource file reference that links the object to its
// behavior trees, animation tables, sprites, and catalog information.
ObjSelector* cXObjectImpl::GetSelector(void) {
    // lwz r3, 140(r3) -> load pointer from offset 0x8C
    return *(ObjSelector**)((char*)this + 0x8C);
}

// 0x800EB338 | 12 bytes
// Returns the Behavior pointer from the selector.
// Selector->m_behavior is at ObjSelector offset 0x0C.
void* cXObjectImpl::GetBehavior(void) {
    // lwz r9, 140(r3)  -> selector = this->m_selector
    // lwz r3, 12(r9)   -> return selector->m_behavior (offset 0x0C)
    ObjSelector* sel = *(ObjSelector**)((char*)this + 0x8C);
    return *(void**)((char*)sel + 0x0C);
}

// 0x800EAF38 | 12 bytes
// Returns the folder string from the selector.
// Selector->m_folder is at ObjSelector offset 0x50.
void* cXObjectImpl::GetFolder(void) {
    // lwz r9, 140(r3) -> selector
    // lwz r3, 80(r9)  -> selector->m_folder (offset 0x50)
    ObjSelector* sel = *(ObjSelector**)((char*)this + 0x8C);
    return *(void**)((char*)sel + 0x50);
}

// 0x800EB8D0 | 12 bytes
// Returns the object name string from the selector.
// Selector->m_name is at ObjSelector offset 0x14.
const char* cXObjectImpl::GetName(void) const {
    // lwz r9, 140(r3) -> selector
    // lwz r3, 20(r9)  -> selector->m_name (offset 0x14)
    ObjSelector* sel = *(ObjSelector**)((char*)this + 0x8C);
    return *(const char**)((char*)sel + 0x14);
}

// 0x800EB304 | 36 bytes
// Returns the tree table from the selector.
// Calls ObjSelector::GetTreeTab() on this->m_selector.
void* cXObjectImpl::GetTreeTab(void) {
    ObjSelector* sel = *(ObjSelector**)((char*)this + 0x8C);
    return sel->GetTreeTab();  // bl 0x80111648
}

// 0x800EB114 | 36 bytes
// Returns the adult animation table from the selector.
void* cXObjectImpl::GetAdultAnimTable(void) {
    ObjSelector* sel = *(ObjSelector**)((char*)this + 0x8C);
    return sel->GetAdultAnimTable();  // bl 0x80111744
}

// 0x800EB138 | 36 bytes
// Returns the child animation table from the selector.
void* cXObjectImpl::GetChildAnimTable(void) {
    ObjSelector* sel = *(ObjSelector**)((char*)this + 0x8C);
    return sel->GetChildAnimTable();  // bl 0x801117a4
}

// 0x800EB344 | 52 bytes
// Returns the selector's resource file (ObjResFile/SelFile).
// If the cached file pointer is NULL, calls selector->LoadSelFile().
void* cXObjectImpl::GetSelFile(void) {
    ObjSelector* sel = *(ObjSelector**)((char*)this + 0x8C);
    void* file = *(void**)((char*)sel + 0x00);
    if (file == NULL) {
        file = sel->LoadSelFile();  // bl 0x80110790
    }
    return file;
}

// ============================================================================
// SECTION 5: LOCATION & PLACEMENT
// ============================================================================

// 0x800EB2FC | 8 bytes
// Returns a pointer to the FTilePt location embedded in the object (offset 0x68).
// The caller can read/write x and y directly through this pointer.
FTilePt* cXObjectImpl::GetLocation(void) {
    // addi r3, r3, 104 -> return &this->m_location (offset 0x68)
    return (FTilePt*)((char*)this + 0x68);
}

// 0x800EB2E8 | 20 bytes
// Copies the object's location into the provided FTilePt.
// FTilePt is 8 bytes: x (int) at +0, y (int) at +4.
void cXObjectImpl::GetLocation(FTilePt* out) const {
    // lwz r9, 104(r3)  -> x = this->m_location.x
    // lwz r10, 108(r3) -> y = this->m_location.y
    // stw r9, 0(r4)    -> out->x = x
    // stw r10, 4(r4)   -> out->y = y
    int x = *(int*)((char*)this + 0x68);
    int y = *(int*)((char*)this + 0x6C);
    *(int*)((char*)out + 0x00) = x;
    *(int*)((char*)out + 0x04) = y;
}

// 0x800E2AC4 | 8 bytes
// Returns the floor level (0 = ground, 1 = upstairs, etc.)
int cXObjectImpl::GetLevel(void) const {
    // lwz r3, 128(r3) -> return this->m_level (offset 0x80)
    return *(int*)((char*)this + 0x80);
}

// 0x800E2ACC | 8 bytes
// Sets the floor level.
void cXObjectImpl::SetLevel(int level) {
    // stw r4, 128(r3) -> this->m_level = level
    *(int*)((char*)this + 0x80) = level;
}

// 0x800EB0BC | 8 bytes
// Returns a pointer to the bounding rectangle (FTileRect at offset 0x70).
FTileRect* cXObjectImpl::GetRect(void) {
    // addi r3, r3, 112 -> return &this->m_rect (offset 0x70)
    return (FTileRect*)((char*)this + 0x70);
}

// 0x800DCB50 | 40 bytes
// Checks if the object is placed in the world (has valid tile coordinates).
// The location is stored as fixed-point: actual tile = coord >> 4.
// An object is "in world" if both x >> 4 > 0 AND y >> 4 > 0.
bool cXObjectImpl::IsInWorld(void) {
    // lwz r0, 108(r3) -> y = this->m_location.y
    // srawi. r9, r0, 4 -> y_tile = y >> 4, set CR
    // ble false
    // lwz r0, 104(r3) -> x = this->m_location.x
    // srawi. r9, r0, 4 -> x_tile = x >> 4
    // bgt true
    int y = *(int*)((char*)this + 0x6C);
    if ((y >> 4) <= 0) return false;
    int x = *(int*)((char*)this + 0x68);
    if ((x >> 4) <= 0) return false;
    return true;
}

// 0x800E2AD4 | 68 bytes
// Returns the center tile point (CTilePt), converting from fixed-point
// location to integer tile coordinates.
// Calls CTilePt constructor with (x>>4, y>>4, level).
void* cXObjectImpl::GetCTilePt(void) const {
    // Loads location.x, location.y, level
    // Shifts x and y right by 4 (srawi)
    // Calls CTilePt::CTilePt(int x, int y, int level) at 0x800b463c
    int x = *(int*)((char*)this + 0x68);  // offset 0x68 from second arg (r4)
    int y = *(int*)((char*)this + 0x6C);
    int level = *(int*)((char*)this + 0x80);
    // Constructs and returns a CTilePt
    return NULL; // placeholder - actual code calls constructor
}

// ============================================================================
// SECTION 6: MISC FLAGS & HILITE
// ============================================================================

// 0x800DB5C4 | 12 bytes
// Returns the hilite state (low 5 bits of the misc flags at offset 0x84).
// Hilite controls the object's highlight color in the game.
int cXObjectImpl::GetHilite(void) {
    // lwz r3, 132(r3) -> flags = this->m_miscFlags
    // clrlwi r3, r3, 27 -> return flags & 0x1F (low 5 bits)
    unsigned int flags = *(unsigned int*)((char*)this + 0x84);
    return flags & 0x1F;
}

// 0x800EAA48 | 32 bytes
// Sets or clears a specific flag bit in the misc flags field.
// First clears the flag bit (andc), then sets it if value is true (or).
void cXObjectImpl::SetMiscFlag(int flag, bool value) {
    // lwz r0, 132(r3)   -> flags = this->m_miscFlags
    // andc r0, r0, r4   -> flags &= ~flag (clear the bit)
    // stw r0, 132(r3)   -> save cleared version
    // beqlr (if value==0, return)
    // or r0, r0, r4     -> flags |= flag (set the bit)
    // stw r0, 132(r3)   -> save
    unsigned int flags = *(unsigned int*)((char*)this + 0x84);
    flags &= ~flag;     // clear bit
    *(unsigned int*)((char*)this + 0x84) = flags;
    if (!value) return;
    flags |= flag;      // set bit
    *(unsigned int*)((char*)this + 0x84) = flags;
}

// 0x800EAA68 | 24 bytes
// Reads a specific flag bit from the misc flags.
// Returns 1 if the flag is set, 0 otherwise.
bool cXObjectImpl::GetMiscFlag(int flag) {
    // lwz r0, 132(r3)  -> flags = this->m_miscFlags
    // li r3, 1          -> assume true
    // and. r9, r0, r4  -> test flags & flag
    // bnelr             -> if nonzero, return 1
    // li r3, 0          -> otherwise return 0
    unsigned int flags = *(unsigned int*)((char*)this + 0x84);
    if (flags & flag) return true;
    return false;
}

// ============================================================================
// SECTION 7: OBJECT TYPE CHECKS
// These query the cXObject (at offset 0x04) for its RTTI or vtable type info.
// ============================================================================

// 0x800E3050 | 68 bytes
// Checks if this object is a vehicle by querying the cXObject's type.
// Calls a virtual method on cXObject and checks if result == 12 (vehicle type).
bool cXObjectImpl::IsVehicle(void) {
    // lwz r3, 4(r3)     -> cxobj = this->m_cXObject (offset 0x04)
    // calls virtual method at vtable[792/4] to get object class type
    // xori r3, r3, 12   -> compare result with 12
    // subfic+adde        -> convert (result == 12) to bool
    cXObject* obj = *(cXObject**)((char*)this + 0x04);
    int type = obj->GetObjectClass();  // virtual call via vtable
    return (type == 12);  // 12 = vehicle type
}

// 0x800E3094 | 68 bytes
// Checks if this object is a person (sim).
// Same pattern as IsVehicle but checks for type == 2.
bool cXObjectImpl::IsPerson(void) {
    cXObject* obj = *(cXObject**)((char*)this + 0x04);
    int type = obj->GetObjectClass();
    return (type == 2);  // 2 = person/sim type
}

// 0x800DF210 | 20 bytes
// Checks if the given cXObject pointer is the same as this object's cXObject.
// Used to determine if a part belongs to a multi-tile object.
bool cXObjectImpl::IsPartOfMe(cXObject* other) {
    // lwz r3, 4(r3)     -> myObj = this->m_cXObject
    // xor r3, r4, r3    -> result = other ^ myObj
    // subfic+adde        -> convert (result == 0) to bool
    cXObject* myObj = *(cXObject**)((char*)this + 0x04);
    return (other == myObj);
}

// 0x800E1784 | 8 bytes
// Base implementation always returns false.
// Overridden in cXPersonImpl when the sim is being dragged.
bool cXObjectImpl::IsBeingDraggedAround(void) {
    return false;  // li r3, 0
}

// 0x800EB378 | 28 bytes
// Checks if the object spans multiple tiles by reading ObjDef->multiTileID.
// ObjDef offset 0x14 contains the multi-tile master ID (0 = single tile).
bool cXObjectImpl::IsMultiTile(void) {
    // lwz r9, 136(r3)  -> def = this->m_objDef
    // lha r0, 20(r9)   -> multiTileID = def->m_multiTileID (offset 0x14)
    // cmpwi r0, 0
    ObjDef* def = *(ObjDef**)((char*)this + 0x88);
    short multiTileID = *(short*)((char*)def + 0x14);
    return (multiTileID != 0);
}

// 0x800E324C | 16 bytes
// Base implementation: single-tile objects are 1x1.
// Overridden by cXMTObjectImpl for multi-tile objects.
void cXObjectImpl::GetNumTiles(int& outX, int& outY) {
    // li r0, 1
    // stw r0, 0(r4)  -> outX = 1
    // stw r0, 0(r5)  -> outY = 1
    outX = 1;
    outY = 1;
}

// ============================================================================
// SECTION 8: OBJECT GRAPH TRAVERSAL
// ============================================================================

// 0x800EB844 | 8 bytes
// Returns the next object implementation in the linked list.
cXObjectImpl* cXObjectImpl::GetNextImpl(void) {
    // lwz r3, 92(r3) -> return this->m_nextImpl (offset 0x5C)
    return *(cXObjectImpl**)((char*)this + 0x5C);
}

// 0x800EB7F4 | 24 bytes
// Returns the cXObject wrapper of the next object in the list.
// Returns NULL if there is no next object.
cXObject* cXObjectImpl::GetNext(void) {
    // lwz r9, 92(r3)   -> next = this->m_nextImpl
    // li r3, 0          -> default NULL
    // cmpwi r9, 0
    // beqlr             -> if next == NULL, return NULL
    // lwz r3, 4(r9)     -> return next->m_cXObject (offset 0x04)
    cXObjectImpl* next = *(cXObjectImpl**)((char*)this + 0x5C);
    if (next == NULL) return NULL;
    return *(cXObject**)((char*)next + 0x04);
}

// ============================================================================
// SECTION 9: HIERARCHY - Container/Slot system
// ============================================================================

// 0x800EABEC | 20 bytes
// Returns the number of hierarchy slots by computing:
// (m_slotsEnd - m_slotsBegin) / 32
// m_slotsBegin at offset 0x90, m_slotsEnd at offset 0x94.
int cXObjectImpl::HierCountSlots(void) {
    // lwz r0, 144(r3)  -> begin = this->m_slotsBegin
    // lwz r3, 148(r3)  -> end = this->m_slotsEnd
    // subf r3, r0, r3  -> size = end - begin
    // srawi r3, r3, 5  -> count = size / 32
    int begin = *(int*)((char*)this + 0x90);
    int end = *(int*)((char*)this + 0x94);
    return (end - begin) >> 5;  // each slot is 32 bytes
}

// 0x800EB218 | 24 bytes
// Returns the count of OBJECT slots (not hierarchy slots).
// Similar to HierCountSlots but subtracts 1 (slot 0 is reserved).
int cXObjectImpl::CountObjectSlots(void) {
    int begin = *(int*)((char*)this + 0x90);
    int end = *(int*)((char*)this + 0x94);
    return ((end - begin) >> 5) - 1;
}

// ============================================================================
// SECTION 10: ROUTING SLOTS
// ============================================================================

// 0x800EB3F4 | 32 bytes
// Returns the number of routing slots.
// Uses magic number division: multiply by 0xEEEEEEEF then shift right 2
// which is equivalent to dividing by 60 (sizeof RoutingSlot).
// m_routingSlotsBegin at offset 0xA0, m_routingSlotsEnd at offset 0xA4.
int cXObjectImpl::GetNumRoutingSlots(void) {
    void* begin = *(void**)((char*)this + 0xA0);
    void* end = *(void**)((char*)this + 0xA4);
    int size = (int)((char*)end - (char*)begin);
    // Division by 60 using magic number multiplication
    return size / 60;
}

// 0x800EB414 | 16 bytes
// Returns a pointer to the Nth routing slot.
// Each routing slot is 60 bytes (0x3C).
RoutingSlot* cXObjectImpl::GetRoutingSlot(int index) {
    // mulli r4, r4, 60  -> offset = index * 60
    // lwz r3, 160(r3)   -> base = this->m_routingSlotsBegin
    // add r3, r3, r4    -> return base + offset
    char* base = *(char**)((char*)this + 0xA0);
    return (RoutingSlot*)(base + index * 60);
}

// ============================================================================
// SECTION 11: SPRITE & RENDERING
// ============================================================================

// 0x800DE780 | 8 bytes
// Returns the sprite slot pointer at offset 0xB0.
void* cXObjectImpl::GetSpriteSlot(void) {
    // lwz r3, 176(r3) -> return this->m_spriteSlot (offset 0xB0)
    return *(void**)((char*)this + 0xB0);
}

// 0x800EB3EC | 8 bytes
// Returns the relative transform matrix at offset 0x60.
void* cXObjectImpl::GetRelMatrix(void) {
    // lwz r3, 96(r3) -> return this->m_relMatrix (offset 0x60)
    return *(void**)((char*)this + 0x60);
}

// ============================================================================
// SECTION 12: SYNC OBJECT (multiplayer synchronization)
// ============================================================================

// 0x800EAB38 | 8 bytes
// Returns the sync object pointer at offset 0xDC.
void* cXObjectImpl::GetSyncObject(void) {
    // lwz r3, 220(r3) -> return this->m_syncObject
    return *(void**)((char*)this + 0xDC);
}

// 0x800EAB40 | 12 bytes
// Clears the sync object pointer (sets to NULL).
void cXObjectImpl::ClearSyncObject(void) {
    // li r0, 0
    // stw r0, 220(r3) -> this->m_syncObject = NULL
    *(void**)((char*)this + 0xDC) = NULL;
}

// 0x800EAB4C | 8 bytes
// Returns the sync wait state at offset 0xE4.
// Nonzero means the object is waiting for a sync response.
int cXObjectImpl::WaitingForSync(void) {
    // lwz r3, 228(r3) -> return this->m_syncE4
    return *(int*)((char*)this + 0xE4);
}

// ============================================================================
// SECTION 13: OVERRIDE RENDER POSITION
// Used for cutscenes and special camera effects to draw objects at
// screen positions independent of their world location.
// ============================================================================

// 0x800E301C | 20 bytes
// Sets an override render position (x, y in screen coordinates).
// Enables the override flag at offset 0xCC.
void cXObjectImpl::SetOverrideRenderPosition(float x, float y) {
    // li r0, 1
    // stfs f1, 208(r3)  -> this->m_overrideX = x (offset 0xD0)
    // stw r0, 204(r3)   -> this->m_overrideEnabled = 1 (offset 0xCC)
    // stfs f2, 212(r3)  -> this->m_overrideY = y (offset 0xD4)
    *(int*)((char*)this + 0xCC) = 1;
    *(float*)((char*)this + 0xD0) = x;
    *(float*)((char*)this + 0xD4) = y;
}

// 0x800E3030 | 20 bytes
// Reads the current override render position.
void cXObjectImpl::GetOverrideRenderPosition(float& outX, float& outY) {
    // lfs f0, 208(r3)   -> outX = this->m_overrideX
    // stfs f0, 0(r4)
    // lfs f13, 212(r3)  -> outY = this->m_overrideY
    // stfs f13, 0(r5)
    outX = *(float*)((char*)this + 0xD0);
    outY = *(float*)((char*)this + 0xD4);
}

// 0x800E3044 | 12 bytes
// Disables the override render position.
void cXObjectImpl::ClearOverrideRenderPosition(void) {
    // li r0, 0
    // stw r0, 204(r3) -> this->m_overrideEnabled = 0
    *(int*)((char*)this + 0xCC) = 0;
}

// ============================================================================
// SECTION 14: DRAW LABEL
// ============================================================================

// 0x800E2FE4 | 20 bytes
// Sets whether to draw a text label above the object.
// Only writes if the value is actually changing (optimization).
void cXObjectImpl::SetDrawLabel(bool enable) {
    // lwz r0, 196(r3) -> current = this->m_drawLabel (offset 0xC4)
    // cmpw r0, r4     -> if current == enable, return
    // beqlr
    // stw r4, 196(r3) -> this->m_drawLabel = enable
    int current = *(int*)((char*)this + 0xC4);
    if (current == (int)enable) return;
    *(int*)((char*)this + 0xC4) = (int)enable;
}

// ============================================================================
// SECTION 15: GRAPHICS TAG
// Used to mark objects whose graphics have been loaded/referenced.
// ============================================================================

// 0x800EB8C4 | 12 bytes
// Marks the graphics as tagged (sets field at offset 0xE8 to 1).
void cXObjectImpl::TagGraphicsField(void) {
    // li r0, 1
    // stw r0, 232(r3) -> this->m_graphicsTagged = 1 (offset 0xE8)
    *(int*)((char*)this + 0xE8) = 1;
}

// 0x800EB89C | 40 bytes
// Checks if graphics have been tagged since the last check.
// Returns true and clears the flag (one-shot consumption pattern).
// This is a "check and clear" atomic operation.
bool cXObjectImpl::HaveGraphicsBeenTagged(void) {
    // lwz r0, 232(r9)  -> tagged = this->m_graphicsTagged
    // cmpwi r0, 0
    // if (tagged == 0) return false
    // li r0, 0
    // li r3, 1
    // stw r0, 232(r9)  -> this->m_graphicsTagged = 0 (clear flag)
    // return true
    int tagged = *(int*)((char*)this + 0xE8);
    if (tagged == 0) return false;
    *(int*)((char*)this + 0xE8) = 0;
    return true;
}

// ============================================================================
// SECTION 16: STATIC GLOBALS
// These are class-level settings that apply to all objects.
// Accessed via r13 (small data area) + offset.
// ============================================================================

// 0x800EABC4 | 8 bytes
// Returns the global free will setting.
// sdata address: r13 - 31912 = 0x804FDC78 (cXObjectImpl::sFreeWill)
bool cXObjectImpl::GetFreeWill(void) {
    // lwz r3, -31912(r13) -> return sFreeWill
    return sFreeWill;
}

// 0x800EABCC | 8 bytes
// Returns the global auto-center setting.
// sdata address: r13 - 31904 = 0x804FDC80 (cXObjectImpl::sAutoCenter)
bool cXObjectImpl::GetAutoCenter(void) {
    // lwz r3, -31904(r13) -> return sAutoCenter
    return sAutoCenter;
}

// 0x800EABD4 | 8 bytes
// Sets the global auto-center setting.
void cXObjectImpl::SetAutoCenter(bool enable) {
    // stw r3, -31904(r13) -> sAutoCenter = enable
    // Note: 'enable' is in r3 because this is a static method (no 'this')
    //       or the bool is passed in first param register
    sAutoCenter = enable;
}

// 0x800EABDC | 8 bytes
// Returns the global auto-reset setting.
// sdata address: r13 - 31900 = 0x804FDC84 (cXObjectImpl::sAutoReset)
bool cXObjectImpl::GetAutoReset(void) {
    return sAutoReset;
}

// 0x800EABE4 | 8 bytes
// Sets the global auto-reset setting.
void cXObjectImpl::SetAutoReset(bool enable) {
    sAutoReset = enable;
}

// 0x800EB8E0 | 8 bytes
// Sets the global override dialog return code.
// sdata address: r13 - 31828 = 0x804FDCCC (cXObjectImpl::overrideDialogReturnCode)
// Stored as a short (sth instruction).
void cXObjectImpl::SetOverrideDialogReturnCode(TreeReturnCode code) {
    // sth r4, -31828(r13) -> overrideDialogReturnCode = code
    overrideDialogReturnCode = code;
}

// ============================================================================
// SECTION 17: OBJECT PROBE (stub implementation on GC)
// The ObjectProbe system appears to be stripped/disabled on GameCube.
// ============================================================================

// 0x800EAF2C | 8 bytes
// Always returns NULL - ObjectProbe not used on GameCube.
ObjectProbe* cXObjectImpl::GetObjectProbe(void) {
    // li r3, 0
    return NULL;
}

// 0x800EAF34 | 4 bytes
// No-op - ObjectProbe not used on GameCube.
void cXObjectImpl::SetObjectProbe(ObjectProbe* probe) {
    // blr - does nothing
    (void)probe;
}

// ============================================================================
// SECTION 18: STUB/NOP VIRTUAL METHODS
// ============================================================================

// 0x800DB168 | 4 bytes
// Pre-save hook - base implementation does nothing.
// Subclasses can override to prepare state before serialization.
void cXObjectImpl::PreSave(void) {
    // blr
}

// 0x800DF224 | 4 bytes
// Force-updates the object's location. Base implementation is a no-op.
void cXObjectImpl::ForceLocation(void) {
    // blr
}

// 0x8010D5AC | 4 bytes
// Debug backtrace - base implementation is a no-op (release build).
void cXObjectImpl::Backtrace(void) {
    // blr
}

// ============================================================================
// SECTION 19: DATA VARIABLE QUERY FUNCTIONS
// These use EdithVariableSet::operator[] to read specific data variables,
// then interpret the value. They reveal what each data index means.
// ============================================================================

// 0x800EB394 | 44 bytes
// Returns object flags from data variable index 8.
// The flags bitfield controls burning, occupied, fireproof, etc.
short cXObjectImpl::GetFlags(void) {
    // addi r3, r3, 40   -> EdithVariableSet at this+0x28
    // li r4, 8           -> index = 8 (FLAGS)
    // bl operator[]
    // lha r3, 0(r3)      -> return signed value
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = vars->operator[](8);
    return *ptr;
}

// 0x800EB3C0 | 44 bytes
// Returns wall placement flags from data variable index 13.
short cXObjectImpl::GetWallPlacementFlags(void) {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = vars->operator[](13);
    return *ptr;
}

// 0x800EB424 | 44 bytes
// Returns object size from data variable index 49.
short cXObjectImpl::GetSize(void) {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = vars->operator[](49);
    return *ptr;
}

// 0x800EB2A0 | 44 bytes
// Returns the room number from data variable index 29.
// Returns unsigned (lhz) - room IDs are never negative.
unsigned short cXObjectImpl::GetRoom(void) {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = vars->operator[](29);
    return *(unsigned short*)ptr;
}

// ============================================================================
// SECTION 20: BOOLEAN DATA VARIABLE QUERIES
// These read a data variable and interpret it as a boolean condition.
// ============================================================================

// 0x800EB580 | 60 bytes
// Returns true if data variable 15 (IsBroken) is nonzero.
bool cXObjectImpl::IsBroken(void) {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = vars->operator[](15);
    short val = *ptr;
    return (val != 0);
}

// 0x800EB5BC | 60 bytes
// Returns true if data variable 39 (DirtyLevel) is greater than 0.
bool cXObjectImpl::IsDirty(void) {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = vars->operator[](39);
    short val = *ptr;
    return (val > 0);  // bgt comparison
}

// 0x800EB5F8 | 48 bytes
// Returns true if the "burning" flag bit (bit 9) is set in data variable 8 (Flags).
// Uses rlwinm to extract bit 9: rlwinm r3,r3,23,31,31 (rotate left 23, mask bit 31)
bool cXObjectImpl::IsBurning(void) {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    unsigned short* ptr = (unsigned short*)vars->operator[](8);
    unsigned short flags = *ptr;
    return (flags >> 9) & 1;  // bit 9
}

// 0x800EB628 | 48 bytes
// Returns true if the "can burn" flag bit (bit 5) is set in data variable 40.
bool cXObjectImpl::CanBurn(void) {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    unsigned short* ptr = (unsigned short*)vars->operator[](40);
    unsigned short flags = *ptr;
    return (flags >> 5) & 1;  // bit 5 (rlwinm r3,r3,27,31,31)
}

// 0x800EB658 | 48 bytes
// Returns true if the "fireproof" flag bit (bit 11) is set in data variable 8 (Flags).
bool cXObjectImpl::IsFireproof(void) {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    unsigned short* ptr = (unsigned short*)vars->operator[](8);
    unsigned short flags = *ptr;
    return (flags >> 11) & 1;  // bit 11 (rlwinm r3,r3,21,31,31)
}

// 0x800EACE8 | 48 bytes
// Returns true if the "occupied" flag bit (bit 5) is set in data variable 8 (Flags).
// An object is "occupied" when a sim is using it.
bool cXObjectImpl::IsOccupied(void) {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    unsigned short* ptr = (unsigned short*)vars->operator[](8);
    unsigned short flags = *ptr;
    return (flags >> 5) & 1;  // bit 5 (rlwinm r3,r3,27,31,31)
}

// 0x800EAF44 | 60 bytes
// Returns true if data variable 60 (SimIndependent) is nonzero.
// SimIndependent objects don't belong to any sim.
bool cXObjectImpl::SimIndependent(void) {
    EdithVariableSet* vars = (EdithVariableSet*)((char*)this + 0x28);
    short* ptr = vars->operator[](60);
    short val = *ptr;
    return (val != 0);
}

// ============================================================================
// SECTION 21: OBJECT LIFECYCLE - Kill
// ============================================================================

// 0x800EAA00 | 60 bytes
// Kills (removes) this object via the ObjectModule.
// Loads the module pointer, gets this object's ID, then calls
// the module's KillObject virtual method through its vtable.
void cXObjectImpl::Kill(void) {
    // lwz r11, 88(r3)   -> module = this->m_module (offset 0x58)
    // lha r4, 100(r3)   -> objID = this->m_objectID (offset 0x64)
    // lwz r9, 0(r11)    -> vtable = module->vtable
    // lha r3, 88(r9)    -> offset = vtable->killOffset (vtable[88/2])
    // lwz r0, 92(r9)    -> func = vtable->killFunc (vtable[92/4])
    // add r3, r11, r3   -> adjust this pointer
    // mtlr r0 + blrl    -> call virtual KillObject
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    short objID = *(short*)((char*)this + 0x64);
    // Virtual call: module->KillObject(objID)
}

// ============================================================================
// SECTION 22: MODULE DISPATCH FUNCTIONS
// These delegate to the ObjectModule through its vtable.
// They follow a common pattern:
//   1. Load m_module (offset 0x58)
//   2. Load m_objectID (offset 0x64)
//   3. Load vtable from module->vtable[0]
//   4. Get function pointer offset and address from vtable
//   5. Call the virtual function
// ============================================================================

// 0x800EAF80 | 64 bytes
// Checks if simulation is enabled for this object.
// Calls module->SimEnabled(objectID, 1) via vtable[584/588].
bool cXObjectImpl::SimEnabled(void) {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    short objID = *(short*)((char*)this + 0x64);
    // Virtual dispatch: module->SimEnabled(objID, 1)
    return false; // placeholder
}

// 0x800EAFC0 | 68 bytes
// Enables or disables simulation for this object.
// Calls module->EnableSim(objectID, 1, enable) via vtable[576/580].
void cXObjectImpl::EnableSim(bool enable) {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    short objID = *(short*)((char*)this + 0x64);
    // Virtual dispatch: module->EnableSim(objID, 1, enable)
}

// 0x800EB004 | 60 bytes
// Gets the idle status via module->GetIdleStatus(objectID) vtable[568/572].
int cXObjectImpl::GetIdleStatus(void) {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    short objID = *(short*)((char*)this + 0x64);
    // Virtual dispatch: module->GetIdleStatus(objID)
    return 0; // placeholder
}

// 0x800EB040 | 64 bytes
// Sets the idle status via module->SetIdleStatus(objectID, status) vtable[552/556].
void cXObjectImpl::SetIdleStatus(int status) {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    short objID = *(short*)((char*)this + 0x64);
    // Virtual dispatch: module->SetIdleStatus(objID, status)
}

// 0x800EB080 | 60 bytes
// Clears the idle status via module->ClearIdleStatus(objectID) vtable[560/564].
void cXObjectImpl::ClearIdleStatus(void) {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    short objID = *(short*)((char*)this + 0x64);
    // Virtual dispatch: module->ClearIdleStatus(objID)
}

// 0x800EB7BC | 56 bytes
// Finds an object by its short ID through the module.
// Calls module->GetObjectFromID(objectID) via vtable[144/148].
cXObject* cXObjectImpl::GetObjectFromID(short id) {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    // Virtual dispatch: module->GetObjectFromID(id)
    return NULL; // placeholder
}

// 0x800EB450 | 56 bytes
// Gets the ESim associated with this object through the module.
// Calls module->GetSim() via vtable[216/220].
void* cXObjectImpl::GetSim(void) {
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    // Virtual dispatch: module->GetSim()
    return NULL; // placeholder
}

// ============================================================================
// SECTION 23: cXObject VIRTUAL DISPATCH FUNCTIONS
// These call virtual methods on the cXObject (offset 0x04) through its vtable.
// ============================================================================

// 0x800EAA80 | 60 bytes
// Returns true if this object is NOT the rendering root.
// Calls cXObject virtual method at vtable[728/732] and inverts result.
bool cXObjectImpl::IsRenderingRoot(void) {
    // lwz r3, 4(r3)   -> obj = this->m_cXObject
    // virtual call via vtable[728/732]
    // xori r3, r3, 1  -> return !result
    cXObject* obj = *(cXObject**)((char*)this + 0x04);
    // Returns !obj->IsChildOfAnother()
    return false; // placeholder
}

// ============================================================================
// SECTION 24: ObjDef PROPERTY QUERIES
// These access properties through ObjDef->GetPropertyX via vtable calls.
// ============================================================================

// 0x800EB488 | 44 bytes
// Gets the build mode type from data variable 48 via EdithVariableSet.
// (Pattern not shown - similar to GetFlags/GetSize)

// 0x800EB4B4 | 68 bytes
// Checks if this is a support object (structural).
// Calls ObjDef->IsSupport() through cXObject vtable.

// 0x800EB4F8 | 48 bytes
// Checks if this object can contribute to room lighting.
// Reads from a data variable.

// 0x800EB528 | 44 bytes
// Gets the lighting contribution amount.

// 0x800EB554 | 44 bytes
// Gets the light source info.

// ============================================================================
// SECTION 25: SIMULATION
// ============================================================================

// 0x801096C4 | 172 bytes
// Main simulation tick for this object.
// 1. Calls a global function to get the simulation context
// 2. If valid, decrements the sim tick counter (data variable 25)
//    by calling EdithVariableSet::WriteVar(25, current - 1)
// 3. Iterates through the sprite slot list (offset 0xB0)
//    and calls a tick function on each sprite
void cXObjectImpl::Simulate(int param) {
    // lwz r3, 0(r30)        -> load this->m_field_000
    // bl 0x80148550          -> get simulation context
    // if (context == NULL) skip
    //
    // Get data variable 25 (SimTicksRemaining):
    //   addi r31, r30, 40   -> edithVars = this + 0x28
    //   li r4, 25           -> index = 25
    //   bl EdithVariableSet::operator[]
    //   lha r0, 0(r3)       -> ticks = *result
    //   if (ticks == 0) skip decrement
    //   ticks--
    //   bl EdithVariableSet::WriteVar(25, ticks)
    //
    // Iterate sprite slots:
    //   addi r9, r30, 176   -> spriteListHead = this + 0xB0
    //   lwz r31, 176(r30)   -> current = this->m_spriteSlot
    //   while (current != spriteListHead->end) {
    //     call current->Tick()    // bl 0x801430d4
    //     current += 108          // sizeof(SpriteSlot) = 108 (0x6C)
    //   }
}

// ============================================================================
// SUMMARY OF FIELD LAYOUT (refined from disassembly)
//
// Offset  Size  Type         Name                    Source
// ------  ----  ----------   ----------------------  --------------------------
// 0x00    4     void*        m_field_000             (AllowIdleOptimization)
// 0x04    4     cXObject*    m_cXObject              (IsPartOfMe, IsVehicle, etc)
// 0x08    4     short*       m_attrArray             (GetAttr, SetAttr)
// 0x0C    4     int          m_numAttr               (GetNumAttr)
// 0x16    40    short[20]    m_temp                  (GetTemp, SetTemp; 20 temps)
// 0x28    ???   EdithVarSet  m_edithVars             (GetData, SetData, Contains)
// 0x58    4     ObjModule*   m_module                (GetModule, Kill, etc)
// 0x5C    4     cXObjImpl*   m_nextImpl              (GetNextImpl, GetNext)
// 0x60    4     void*        m_relMatrix             (GetRelMatrix)
// 0x64    2     short        m_objectID              (GetID)
// 0x68    8     FTilePt      m_location              (GetLocation)
// 0x70    ???   FTileRect    m_rect                  (GetRect)
// 0x80    4     int          m_level                 (GetLevel, SetLevel)
// 0x84    4     u32          m_miscFlags             (GetHilite, Set/GetMiscFlag)
// 0x88    4     ObjDef*      m_objDef                (GetDef, GetType)
// 0x8C    4     ObjSelector* m_selector              (GetSelector, GetName, etc)
// 0x90    4     void*        m_slotsBegin            (HierCountSlots, CountObjSlots)
// 0x94    4     void*        m_slotsEnd              (HierCountSlots, CountObjSlots)
// 0xA0    4     void*        m_routingSlotsBegin     (GetNumRoutingSlots, GetRoutingSlot)
// 0xA4    4     void*        m_routingSlotsEnd       (GetNumRoutingSlots)
// 0xB0    4     void*        m_spriteSlot            (GetSpriteSlot, Simulate)
// 0xC4    4     int          m_drawLabel             (SetDrawLabel)
// 0xCC    4     int          m_overrideEnabled       (Set/ClearOverrideRenderPos)
// 0xD0    4     float        m_overrideX             (Set/GetOverrideRenderPos)
// 0xD4    4     float        m_overrideY             (Set/GetOverrideRenderPos)
// 0xDC    4     void*        m_syncObject            (Get/ClearSyncObject)
// 0xE4    4     int          m_syncWaiting           (WaitingForSync)
// 0xE8    4     int          m_graphicsTagged        (HaveGraphicsBeenTagged, Tag)
//
// STATIC:
// sFreeWill               (sdata @ 0x804FDC78)
// sAutoCenter             (sdata @ 0x804FDC80)
// sAutoReset              (sdata @ 0x804FDC84)
// overrideDialogReturnCode (sdata @ 0x804FDCCC)
//
// ============================================================================
// EDITH VARIABLE INDEX REFERENCE
//
// Index  Name                Used By
// -----  ------------------  ----------------------------------------
//   8    Flags               GetFlags, IsBurning, IsFireproof, IsOccupied
//  13    WallPlacementFlags  GetWallPlacementFlags
//  15    IsBroken            IsBroken
//  25    SimTicksRemaining   Simulate (decremented each tick)
//  29    Room                GetRoom
//  31    Size                GetSize (index 49)
//  39    DirtyLevel          IsDirty
//  40    BurnFlags           CanBurn
//  49    Size                GetSize
//  60    SimIndependent      SimIndependent
//
// Flags bitfield (data index 8):
//   Bit  5  = Occupied
//   Bit  9  = Burning
//   Bit 11  = Fireproof
//
// ============================================================================
//
// Total decompiled: 72 functions
// - 5 data system functions (GetData, SetData, GetTemp, SetTemp, GetAttr, SetAttr, GetNumAttr, ContainsData)
// - 15 identity/getter functions
// - 6 location/placement functions
// - 3 misc flag functions
// - 6 type check functions
// - 4 object graph traversal functions
// - 3 hierarchy functions
// - 3 routing slot functions
// - 2 sprite/rendering functions
// - 3 sync object functions
// - 3 override render position functions
// - 2 draw/graphics functions
// - 5 static global functions
// - 2 object probe stubs
// - 3 stub/nop virtuals
// - 8 data variable query functions
// - 5 module dispatch functions
// - 1 simulation function
