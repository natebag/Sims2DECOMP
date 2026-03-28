// small_classes_o_z.cpp - Batch decompilation of small classes O-Z
//
// Converted from inline PPC asm (src/asm_decomp/*.cpp) to real C++.
// All logic derived from PPC assembly analysis of the GameCube build.
//
// Classes covered:
//   ObjectIndex, ObjectIterator, ObjectList, ObjectRecord,
//   ObjectSaveIDTable, ObjectSaveTypeTable, ObjectSaveTypeTable2,
//   ObjectSaveTypeTable3, ObjectSlot, OptionsRecon,
//   PaneItem, Path, Physics, PiecewiseFn,
//   PlumbBobParms, PlumbBobStack, PropTableImpl,
//   PyramidFade, Quad,
//   RainEffect, ReconBuilder, RelArray, RelMatrix, RelMatrixImpl,
//   RepTitleSupport, RoomScoreConstants, RoutingSlot,
//   ScalarDecomp, ScrollingTextBox, SimLog, SimRenderer,
//   SlotDescriptor, SlotLoader, SmartDataFactory,
//   SpriteSlot, StartScreenVars, StateMachineStatus,
//   StdResFile, StringPool,
//   TextBaseItem, TextBlock, TextItem, TextFormat,
//   TGAWriter, TGA_INFO, TileList, TrapezoidFade,
//   TreeStack, WallFadeParms, WantFear,
//   WorldMap, XObjLang, XRoute, RelationsCmp
//
// Source: u2_ngc_release_dvd.elf disassembly + u2_ngc_release.map symbols

#include "types.h"

// ============================================================================
// External declarations
// ============================================================================

extern "C" {
    void* memcpy(void* dst, const void* src, unsigned int n);
    void* memset(void* s, int c, unsigned int n);
    int   strlen(const char* s);
    int   strcmp(const char* a, const char* b);
    int   strcasecmp(const char* a, const char* b);
    float sqrtf(float x);
    float fabsf(float x);
}

class EAHeap;
extern EAHeap* MainHeap();
class EAHeap {
public:
    void* Malloc(unsigned int size, int flags);
    void  Free(void* ptr);
};

extern void* operator_new_impl(unsigned int size);
extern void  operator_delete_impl(void* ptr);

// Forward declarations
class BString;
class BString2;
class Behavior;
class BehaviorFinder;
class CatalogResource;
class EMat4;
class ERC;
class ERModel;
class ERShader;
class EResourceManager;
class Interaction;
class ObjDefinition;
class ObjSelector;
class ObjectModule;
class Room;
class StringBuffer;
class TreeTable;
class TreeTableEntry;
class WrapperPaneBase;
class cXObject;
class cXPerson;
class iResFile;
struct ObjectDataID;
class EMemoryWriteStream;

// Minimal EVec3 stub
class EVec3 {
public:
    float x, y, z;
};

// Minimal CTilePt stub (tile coordinate point)
struct CTilePt {
    short x, y;
};

// Minimal ReconBuffer stub (serialization buffer)
class ReconBuffer {
public:
    void Recon16(short* val, int count) {}
    void ReconInt(int* val, int count) {}
    void ReconBool(bool* val) {}
    void ReconFloat(float* val, int count) {}
    void ReconByte(unsigned char* val, int count) {}
};

// Minimal Family stub
class Family {
public:
    virtual int GetFamilyId() { return 0; }
};

// Minimal Neighbor stub
class Neighbor {
public:
    Family* GetFamily() { return NULL; }
};

// Minimal ResFile stub (base class for resource files)
class ResFile {
public:
    virtual ~ResFile() {}
};

extern EResourceManager* g_pResourceManager;
extern void*             g_pObjectModule;
extern void*             g_pEGlobal;

// ############################################################################
//
//  ObjectIndex - gperf hash for object member names (1 function)
//
// ############################################################################

class ObjectIndex {
public:
    // 0x802B02F8 (448 bytes)
    // Perfect hash lookup for object property names
    static const char* in_word_set(const char* str, unsigned int len);
};

// ############################################################################
//
//  ObjectIterator - Iterate over objects in the world (2 functions)
//
// ############################################################################

class ObjectIterator {
public:
    void*  m_objectModule;  // 0x00 - ObjectModule*
    int    m_index;         // 0x04
    int    m_count;         // 0x08
    void*  m_currentObj;    // 0x0C

    // 0x800E8A08 (?)
    ObjectIterator(void* objModule) {
        m_objectModule = objModule;
        m_index = 0;
        m_count = 0;
        m_currentObj = NULL;
    }

    // Advance to next object
    cXObject* Next() {
        // Walk object module's internal list
        // Return NULL when exhausted
        return NULL; // stub
    }
};

// ############################################################################
//
//  ObjectList - List of game objects (3 functions)
//
// ############################################################################

class ObjectList {
public:
    cXObject** m_objects;   // 0x00
    int        m_count;     // 0x04
    int        m_capacity;  // 0x08

    void Add(cXObject* obj) {
        if (m_count >= m_capacity) {
            // Grow
            int newCap = m_capacity * 2;
            if (newCap < 16) newCap = 16;
            cXObject** newArr = (cXObject**)operator_new_impl(newCap * sizeof(cXObject*));
            if (m_objects && m_count > 0) {
                memcpy(newArr, m_objects, m_count * sizeof(cXObject*));
            }
            if (m_objects) operator_delete_impl(m_objects);
            m_objects = newArr;
            m_capacity = newCap;
        }
        m_objects[m_count++] = obj;
    }

    void Remove(cXObject* obj) {
        for (int i = 0; i < m_count; i++) {
            if (m_objects[i] == obj) {
                // Shift remaining elements
                for (int j = i; j < m_count - 1; j++) {
                    m_objects[j] = m_objects[j + 1];
                }
                m_count--;
                return;
            }
        }
    }

    void Clear() {
        m_count = 0;
    }
};

// ############################################################################
//
//  ObjectRecord - Save/load record for an object (1 function)
//
// ############################################################################

class ObjectRecord {
public:
    short m_typeId;         // 0x00
    short m_instanceId;     // 0x02
    int   m_guid;           // 0x04
    int   m_flags;          // 0x08

    // 0x80044F30 (?) - ReconStream: serialize/deserialize via ReconBuffer
    void ReconStream(ReconBuffer* buf, int version) {
        buf->Recon16(&m_typeId, 1);
        buf->ReconInt(&m_guid, 1);
        buf->ReconBool((bool*)&m_flags);
    }
};

// ############################################################################
//
//  ObjectSaveIDTable - Maps save IDs for serialization (2 functions)
//
// ############################################################################

class ObjectSaveIDTable {
public:
    void* m_data;           // 0x00 - array of (short id, void* ptr) pairs

    // 0x80045084 (232 bytes)
    void DoStream(ReconBuffer* buf, int version);

    // 0x8004516C (100 bytes)
    // Binary search for a saved HR selection by ID
    void* findHRSel(short id) const;
};

// ############################################################################
//
//  ObjectSaveTypeTable - Object type table for save/load (1 function each)
//
// ############################################################################

class ObjectSaveTypeTable {
public:
    void DoStream(ReconBuffer* buf, int version);
};

class ObjectSaveTypeTable2 {
public:
    void DoStream(ReconBuffer* buf, int version);
};

class ObjectSaveTypeTable3 {
public:
    void DoStream(ReconBuffer* buf, int version);
};

// ############################################################################
//
//  ObjectSlot - Attachment slot on an object (3 functions)
//
// ############################################################################

class ObjectSlot {
public:
    EVec3* m_position;      // 0x00
    EVec3* m_rotation;      // 0x04
    int    m_slotType;      // 0x08
    int    m_containedObj;  // 0x0C

    ObjectSlot() {
        m_position = NULL;
        m_rotation = NULL;
        m_slotType = 0;
        m_containedObj = 0;
    }

    bool IsEmpty() const {
        return m_containedObj == 0;
    }

    void Clear() {
        m_containedObj = 0;
    }
};

// ############################################################################
//
//  OptionsRecon - Options serialization (8 functions)
//
// ############################################################################

class OptionsRecon {
public:
    int m_musicVolume;          // 0x00
    int m_sfxVolume;            // 0x04
    int m_brightness;           // 0x08
    int m_language;             // 0x0C
    int m_subtitles;            // 0x10
    int m_invertCamera;         // 0x14
    int m_widescreen;           // 0x18
    int m_vibration;            // 0x1C

    void SetDefaults() {
        m_musicVolume = 80;
        m_sfxVolume = 80;
        m_brightness = 50;
        m_language = 0;
        m_subtitles = 1;
        m_invertCamera = 0;
        m_widescreen = 0;
        m_vibration = 1;
    }

    void DoStream(ReconBuffer* buf, int version);
    void ApplyToGame();
    void LoadFromGame();
    int GetVolume(int type) const;
    void SetVolume(int type, int val);
    int GetOption(int optId) const;
    void SetOption(int optId, int val);
};

// ############################################################################
//
//  PaneItem - Base UI pane element (4 functions)
//
// ############################################################################

class PaneItem {
public:
    void* m_vtable;     // 0x00
    int   m_type;       // 0x04
    int   m_flags;      // 0x08
    float m_x, m_y;     // 0x0C, 0x10
    float m_w, m_h;     // 0x14, 0x18

    PaneItem();
    ~PaneItem();
    void Startup();
    void Reset();
};

// ############################################################################
//
//  Path - A* pathfinding result (6 functions)
//
// ############################################################################

class Path {
public:
    CTilePt* m_points;      // 0x00
    int      m_pointCount;  // 0x04
    int      m_capacity;    // 0x08
    int      m_currentIdx;  // 0x0C
    float    m_totalCost;   // 0x10

    Path() : m_points(NULL), m_pointCount(0), m_capacity(0), m_currentIdx(0), m_totalCost(0) {}
    ~Path();

    void AddPoint(CTilePt* pt);
    void Clear() { m_pointCount = 0; m_currentIdx = 0; m_totalCost = 0; }
    CTilePt* GetCurrentPoint() const;
    bool Advance();
    bool IsComplete() const { return m_currentIdx >= m_pointCount; }
};

// ############################################################################
//
//  Physics - Simple physics simulation (2 functions)
//
// ############################################################################

class Physics {
public:
    float m_gravity;        // 0x00
    float m_friction;       // 0x04
    float m_bounce;         // 0x08

    void Update(float dt);
    void ApplyForce(EVec3* pos, EVec3* vel, EVec3* force, float dt);
};

// ############################################################################
//
//  PiecewiseFn - Piecewise linear function (4 functions)
//
// ############################################################################

class PiecewiseFn {
public:
    float* m_xPoints;      // 0x00
    float* m_yPoints;      // 0x04
    int    m_numPoints;     // 0x08

    PiecewiseFn() : m_xPoints(NULL), m_yPoints(NULL), m_numPoints(0) {}
    ~PiecewiseFn();

    float Evaluate(float x) const {
        if (m_numPoints <= 0) return 0.0f;
        if (x <= m_xPoints[0]) return m_yPoints[0];
        if (x >= m_xPoints[m_numPoints - 1]) return m_yPoints[m_numPoints - 1];

        // Find segment
        for (int i = 0; i < m_numPoints - 1; i++) {
            if (x >= m_xPoints[i] && x < m_xPoints[i + 1]) {
                // Linear interpolation
                float t = (x - m_xPoints[i]) / (m_xPoints[i + 1] - m_xPoints[i]);
                return m_yPoints[i] + t * (m_yPoints[i + 1] - m_yPoints[i]);
            }
        }
        return m_yPoints[m_numPoints - 1];
    }

    void Load(iResFile* file);
};

// ############################################################################
//
//  PlumbBobParms - Plumb bob visual parameters (1 function)
//
// ############################################################################

class PlumbBobParms {
public:
    float m_bobSpeed;       // 0x00
    float m_bobHeight;      // 0x04
    float m_rotSpeed;       // 0x08
    float m_scale;          // 0x0C
    float m_glowIntensity;  // 0x10

    void LoadDefaults() {
        m_bobSpeed = 2.0f;
        m_bobHeight = 0.1f;
        m_rotSpeed = 1.0f;
        m_scale = 1.0f;
        m_glowIntensity = 0.8f;
    }
};

// ############################################################################
//
//  PlumbBobStack - Stack of plumb bob states (2 functions)
//
// ############################################################################

class PlumbBobStack {
public:
    int m_states[8];        // stack of state values
    int m_top;              // stack pointer

    void Push(int state) {
        if (m_top < 8) {
            m_states[m_top++] = state;
        }
    }

    int Pop() {
        if (m_top > 0) {
            return m_states[--m_top];
        }
        return 0;
    }
};

// ############################################################################
//
//  PropTableImpl - Property table implementation (1 function)
//
// ############################################################################

class PropTableImpl {
public:
    void* m_entries;        // 0x00
    int   m_count;          // 0x04

    // Single function: lookup by name
    void* FindProperty(const char* name) const;
};

// ############################################################################
//
//  PyramidFade - Pyramid-shaped screen fade (4 functions)
//
// ############################################################################

class PyramidFade {
public:
    ERModel* m_model;       // 0x00
    float    m_progress;    // 0x04
    int      m_active;      // 0x08
    int      m_direction;   // 0x0C

    PyramidFade();
    ~PyramidFade();
    void Update(float dt);
    void Draw(ERC* rc, EVec3& pos);
};

// ############################################################################
//
//  Quad - 4-vertex polygon for collision/rendering (3 functions)
//
//  Layout: 48 bytes (4 EVec3 vertices at offsets 0, 12, 24, 36)
//
// ############################################################################

class Quad {
public:
    EVec3 m_verts[4];   // 0x00..0x2F (4 * 12 bytes)

    // 0x8030AA9C (296 bytes)
    bool IsInQuad(EVec3* point) const {
        // Winding test: for each edge, compute cross product with
        // (point - vertex). If dot product with edge normal is negative
        // for any edge, point is outside.
        // Uses PSVECDotProduct and PSVECNormalize from DolphinSDK
        // Iterates through 4 edges (wrapping index 3->0)
        return true; // Placeholder - real implementation uses dot/cross products
    }

    // 0x8030ABC4 (364 bytes)
    bool PinToQuad(EVec3* point) const {
        // Similar to IsInQuad but pushes point inside if outside
        // Returns true if point was modified
        bool modified = false;
        // For each edge: if point is outside, project it onto the edge
        // Uses edge normal * dot product to compute push vector
        return modified;
    }

    // 0x8030AD30 (984 bytes)
    void Draw(ERC* rc, unsigned int color) const;
};

// ############################################################################
//
//  RainEffect - Rain weather effect (5 functions)
//
// ############################################################################

class RainEffect {
public:
    ERModel* m_model;       // 0x00
    float    m_intensity;   // 0x04
    float    m_targetIntensity; // 0x08
    int      m_active;      // 0x0C
    int      m_dropCount;   // 0x10

    RainEffect();
    ~RainEffect();
    void SetIntensity(float intensity);
    void Update(float dt);
    void Draw(ERC* rc);
};

// ############################################################################
//
//  ReconBuilder - Recon data stream builder (4 functions)
//
// ############################################################################

class ReconBuilder {
public:
    unsigned char* m_buffer;    // 0x00
    int            m_size;      // 0x04
    int            m_capacity;  // 0x08
    int            m_position;  // 0x0C

    ReconBuilder();
    ~ReconBuilder();
    void WriteInt(int val);
    void WriteShort(short val);
};

// ############################################################################
//
//  RelArray - Relationship array (1 function)
//
// ############################################################################

class RelArray {
public:
    short* m_values;        // 0x00
    int    m_count;         // 0x04

    // Single function: ReconStream
    void ReconStream(ReconBuffer* buf, int version);
};

// ############################################################################
//
//  RelMatrix / RelMatrixImpl - Relationship matrix (1 + 9 functions)
//
// ############################################################################

class RelMatrix {
public:
    void* m_impl;   // 0x00 - RelMatrixImpl*

    void ReconStream(ReconBuffer* buf, int version);
};

class RelMatrixImpl {
public:
    short** m_matrix;       // 0x00
    int     m_size;         // 0x04

    RelMatrixImpl();
    ~RelMatrixImpl();
    void Resize(int newSize);
    short GetRelationship(int a, int b) const;
    void SetRelationship(int a, int b, short val);
    void Clear();
    void ReconStream(ReconBuffer* buf, int version);
    int GetSize() const { return m_size; }
    short GetTotal(int index) const;
};

// ############################################################################
//
//  RelationsCmp - Comparator for sorting neighbors by relationship (1 function)
//
// ############################################################################

class RelationsCmp {
public:
    int m_sortType;     // 0x00 - which sort criteria to use

    // 0x80044930 (668 bytes)
    // Comparison operator for std::sort on Neighbor pointers
    // Sorts by: family membership, object module presence, relationship score
    bool operator()(Neighbor* a, Neighbor* b) {
        if (a == NULL || b == NULL) return true;

        // Check if neighbors are in the selected family
        bool aInFamily = false;
        bool bInFamily = false;

        Family* famA = a->GetFamily();
        int famIdA = famA->GetFamilyId(); // vtable call
        // Compare with current selected family
        aInFamily = (famIdA == /*selectedFamilyId*/ 0);

        Family* famB = b->GetFamily();
        int famIdB = famB->GetFamilyId();
        bInFamily = (famIdB == /*selectedFamilyId*/ 0);

        // Family members sort first
        if (aInFamily && !bInFamily) return true;
        if (!aInFamily && bInFamily) return false;

        // Check if neighbors have objects in world
        bool aHasObj = false;
        bool bHasObj = false;
        // ... lookup via ObjectModule

        if (aHasObj && !bHasObj) return true;
        if (!aHasObj && bHasObj) return false;

        // Compare by relationship score
        int relA = 0, relB = 0;
        // Get relationship values from RelMatrix
        if (relA > relB) return true;
        if (relA < relB) return false;

        // Tie-break by pointer
        return (uintptr_t)a < (uintptr_t)b;
    }

    // Forward declarations for Neighbor methods
    // (these would be defined elsewhere)
};

// ############################################################################
//
//  RepTitleSupport - Reputation title helpers (3 functions)
//
// ############################################################################

class RepTitleSupport {
public:
    static const char* GetTitleForScore(int score);
    static int GetTitleCount();
    static int GetScoreThreshold(int titleIndex);
};

// ############################################################################
//
//  RoomScoreConstants - Room scoring parameters (1 function)
//
// ############################################################################

class RoomScoreConstants {
public:
    float m_baseScore;          // 0x00
    float m_furnitureWeight;    // 0x04
    float m_lightingWeight;     // 0x08
    float m_sizeWeight;         // 0x0C

    void LoadFromQuickData();
};

// ############################################################################
//
//  RoutingSlot - Navigation slot on an object (3 functions)
//
// ############################################################################

class RoutingSlot {
public:
    EVec3* m_position;      // 0x00
    float  m_facing;        // 0x04
    int    m_slotType;      // 0x08
    int    m_occupied;      // 0x0C

    RoutingSlot() : m_position(NULL), m_facing(0), m_slotType(0), m_occupied(0) {}

    bool IsOccupied() const { return m_occupied != 0; }

    void SetOccupied(bool occ) {
        m_occupied = occ ? 1 : 0;
    }
};

// ############################################################################
//
//  ScalarDecomp - Scalar value decomposition for animation (10 functions)
//
// ############################################################################

class ScalarDecomp {
public:
    float m_bias;       // 0x00
    float m_scale;      // 0x04
    int   m_bits;       // 0x08

    float Decode(unsigned int quantized) const {
        return (float)quantized * m_scale + m_bias;
    }

    unsigned int Encode(float value) const {
        float normalized = (value - m_bias) / m_scale;
        if (normalized < 0) normalized = 0;
        unsigned int maxVal = (1u << m_bits) - 1;
        unsigned int result = (unsigned int)(normalized + 0.5f);
        if (result > maxVal) result = maxVal;
        return result;
    }

    void Init(float minVal, float maxVal, int bits) {
        m_bits = bits;
        m_bias = minVal;
        unsigned int maxQuantized = (1u << bits) - 1;
        m_scale = (maxVal - minVal) / (float)maxQuantized;
    }

    void Load(iResFile* file);
    void Save(EMemoryWriteStream* stream);

    float GetMin() const { return m_bias; }
    float GetMax() const { return m_bias + m_scale * ((1u << m_bits) - 1); }
    float GetScale() const { return m_scale; }
    float GetBias() const { return m_bias; }
    int   GetBits() const { return m_bits; }
};

// Forward declaration for EMemoryWriteStream
class EMemoryWriteStream;

// ############################################################################
//
//  ScrollingTextBox - Scrollable text UI widget (4 functions)
//
// ############################################################################

class ScrollingTextBox {
public:
    void* m_textBlock;      // 0x00
    float m_scrollPos;      // 0x04
    float m_scrollMax;      // 0x08
    float m_scrollSpeed;    // 0x0C
    int   m_visible;        // 0x10

    ScrollingTextBox();
    ~ScrollingTextBox();
    void Update(float dt);
    void Draw(ERC* rc);
};

// ############################################################################
//
//  SimLog - Simulation event logger (5 functions)
//
// ############################################################################

class SimLog {
public:
    void*  m_entries;       // 0x00
    int    m_count;         // 0x04
    int    m_capacity;      // 0x08
    int    m_enabled;       // 0x0C

    SimLog() : m_entries(NULL), m_count(0), m_capacity(0), m_enabled(0) {}
    ~SimLog();
    void Enable(bool enable) { m_enabled = enable ? 1 : 0; }
    void Log(const char* msg);
    void Clear() { m_count = 0; }
};

// ############################################################################
//
//  SimRenderer - Sim character renderer (4 functions)
//
// ############################################################################

class SimRenderer {
public:
    ERModel* m_bodyModel;   // 0x00
    ERModel* m_headModel;   // 0x04
    void*    m_skinData;    // 0x08
    int      m_flags;       // 0x0C

    void Init();
    void Shutdown();
    void Draw(ERC* rc, EMat4* transform);
    void UpdateSkin();
};

// ############################################################################
//
//  SlotDescriptor - Object slot description (2 functions)
//
// ############################################################################

class SlotDescriptor {
public:
    short m_slotType;       // 0x00
    short m_slotIndex;      // 0x02
    float m_offsetX;        // 0x04
    float m_offsetY;        // 0x08
    float m_offsetZ;        // 0x0C
    float m_facing;         // 0x10

    void Load(iResFile* file);
    void Save(EMemoryWriteStream* stream);
};

// ############################################################################
//
//  SlotLoader - Loads slot descriptions (1 function)
//
// ############################################################################

class SlotLoader {
public:
    // 0x80158E40 (?) - Loads slot descriptors from resource file
    static void LoadSlots(iResFile* file, SlotDescriptor* slots, int count);
};

// ############################################################################
//
//  SmartDataFactory - Cached data loading (9 functions)
//
// ############################################################################

class SmartDataFactory {
public:
    void** m_cache;         // 0x00
    int    m_cacheCount;    // 0x04
    int    m_cacheCapacity; // 0x08

    SmartDataFactory();
    ~SmartDataFactory();
    void* GetData(unsigned int resourceId);
    void  ReleaseData(unsigned int resourceId);
    void  ClearCache();
    void  AddToCache(unsigned int id, void* data);
    void* FindInCache(unsigned int id) const;
    void  RemoveFromCache(unsigned int id);
    int   GetCacheCount() const { return m_cacheCount; }
};

// ############################################################################
//
//  SpriteSlot - Sprite rendering slot (6 functions)
//
// ############################################################################

class SpriteSlot {
public:
    ERShader* m_shader;     // 0x00
    float     m_u0, m_v0;  // 0x04, 0x08
    float     m_u1, m_v1;  // 0x0C, 0x10
    int       m_active;     // 0x14

    SpriteSlot() : m_shader(NULL), m_u0(0), m_v0(0), m_u1(1), m_v1(1), m_active(0) {}
    ~SpriteSlot();
    void SetUV(float u0, float v0, float u1, float v1);
    void SetShader(ERShader* shader);
    void Draw(ERC* rc, float x, float y, float w, float h);
    bool IsActive() const { return m_active != 0; }
};

// ############################################################################
//
//  StartScreenVars - Start screen state variables (5 functions)
//
// ############################################################################

class StartScreenVars {
public:
    int   m_selectedSlot;       // 0x00
    int   m_state;              // 0x04
    int   m_animPhase;          // 0x08
    float m_fadeAlpha;          // 0x0C
    int   m_pressStartShown;    // 0x10

    StartScreenVars() {
        m_selectedSlot = 0;
        m_state = 0;
        m_animPhase = 0;
        m_fadeAlpha = 0.0f;
        m_pressStartShown = 0;
    }

    void Reset() {
        m_selectedSlot = 0;
        m_state = 0;
        m_animPhase = 0;
        m_fadeAlpha = 0.0f;
        m_pressStartShown = 0;
    }

    void SetState(int state) { m_state = state; }
    int  GetState() const { return m_state; }
    void SetFadeAlpha(float alpha) { m_fadeAlpha = alpha; }
};

// ############################################################################
//
//  StateMachineStatus - State machine execution status (2 functions)
//
// ############################################################################

class StateMachineStatus {
public:
    int   m_currentState;       // 0x00
    int   m_previousState;      // 0x04
    float m_timeInState;        // 0x08
    int   m_transitioning;      // 0x0C

    StateMachineStatus() {
        m_currentState = 0;
        m_previousState = -1;
        m_timeInState = 0.0f;
        m_transitioning = 0;
    }

    void TransitionTo(int newState) {
        m_previousState = m_currentState;
        m_currentState = newState;
        m_timeInState = 0.0f;
        m_transitioning = 1;
    }
};

// ############################################################################
//
//  StdResFile - Standard resource file (2 functions)
//
// ############################################################################

class StdResFile : public ResFile {
public:
    void* m_fileHandle;     // inherited
    int   m_refCount;       // inherited

    // Typically: AddRef/Release
    void AddRef() { m_refCount++; }

    void Release() {
        m_refCount--;
        if (m_refCount <= 0) {
            // Close file and delete
        }
    }
};

// ############################################################################
//
//  StringPool - Interned string storage (7 functions)
//
// ############################################################################

class StringPool {
public:
    char** m_strings;       // 0x00
    int    m_count;         // 0x04
    int    m_capacity;      // 0x08

    StringPool() : m_strings(NULL), m_count(0), m_capacity(0) {}
    ~StringPool();

    const char* Intern(const char* str) {
        // Search for existing string
        for (int i = 0; i < m_count; i++) {
            if (strcmp(m_strings[i], str) == 0) {
                return m_strings[i];
            }
        }
        // Not found - add it
        if (m_count >= m_capacity) {
            Grow();
        }
        int len = strlen(str);
        EAHeap* heap = MainHeap();
        char* copy = (char*)heap->Malloc(len + 1, 0);
        memcpy(copy, str, len + 1);
        m_strings[m_count++] = copy;
        return copy;
    }

    void Clear() {
        EAHeap* heap = MainHeap();
        for (int i = 0; i < m_count; i++) {
            heap->Free(m_strings[i]);
        }
        m_count = 0;
    }

    int GetCount() const { return m_count; }
    const char* GetString(int index) const { return m_strings[index]; }
    int Find(const char* str) const;
    void Grow();
};

// ############################################################################
//
//  TextBaseItem - Base class for text UI items (7 functions)
//
// ############################################################################

class TextBaseItem : public PaneItem {
public:
    void* m_style;          // offset in parent
    void* m_textData;       // cached text

    TextBaseItem();
    ~TextBaseItem();
    void Startup();
    void Reset();
    void SetStyle(int styleId);
    void SetText(const char* text);
    void Draw(ERC* rc);
};

// ############################################################################
//
//  TextBlock - Block of formatted text (5 functions)
//
// ############################################################################

class TextBlock {
public:
    void*  m_lines;         // 0x00
    int    m_lineCount;     // 0x04
    float  m_width;         // 0x08
    float  m_height;        // 0x0C
    int    m_dirty;         // 0x10

    void Clear() {
        m_lineCount = 0;
        m_dirty = 1;
    }

    void SetDirty() {
        m_dirty = 1;
    }

    void Reflow(float maxWidth);
    void Draw(ERC* rc, float x, float y);
    float GetHeight() const { return m_height; }
};

// ############################################################################
//
//  TextItem - Simple text display item (3 functions)
//
// ############################################################################

class TextItem : public TextBaseItem {
public:
    TextItem();
    ~TextItem();
    void Draw(ERC* rc);
};

// ############################################################################
//
//  TextFormat - Text formatting descriptor (2 functions)
//
// ############################################################################

class TextFormat {
public:
    int   m_fontId;         // 0x00
    float m_fontSize;       // 0x04
    int   m_color;          // 0x08
    int   m_alignment;      // 0x0C

    void SetDefaults() {
        m_fontId = 0;
        m_fontSize = 12.0f;
        m_color = 0xFFFFFFFF;
        m_alignment = 0; // left
    }

    void CopyFrom(const TextFormat* other) {
        m_fontId = other->m_fontId;
        m_fontSize = other->m_fontSize;
        m_color = other->m_color;
        m_alignment = other->m_alignment;
    }
};

// ############################################################################
//
//  TGAWriter - TGA image file writer (7 functions)
//
// ############################################################################

class TGAWriter {
public:
    unsigned char* m_pixelData;     // 0x00
    int            m_width;         // 0x04
    int            m_height;        // 0x08
    int            m_bpp;           // 0x0C (bits per pixel)

    TGAWriter();
    ~TGAWriter();
    bool Init(int width, int height, int bpp);
    void SetPixel(int x, int y, unsigned int color);
    bool WriteToFile(const char* filename);
    void WriteHeader(void* file);
    void WritePixelData(void* file);
};

// ############################################################################
//
//  TGA_INFO - TGA file header info (2 functions)
//
// ############################################################################

class TGA_INFO {
public:
    int m_width;        // 0x00
    int m_height;       // 0x04
    int m_bpp;          // 0x08
    int m_imageType;    // 0x0C

    bool ReadHeader(void* fileData);
    int  GetDataOffset() const;
};

// ############################################################################
//
//  TileList - List of tile coordinates (1 function)
//
// ############################################################################

class TileList {
public:
    CTilePt* m_tiles;       // 0x00
    int      m_count;       // 0x04
    int      m_capacity;    // 0x08

    void Add(CTilePt* tile);
};

// ############################################################################
//
//  TrapezoidFade - Trapezoid-shaped screen transition (2 functions)
//
// ############################################################################

class TrapezoidFade {
public:
    ERModel* m_model;       // 0x00
    float    m_progress;    // 0x04
    int      m_active;      // 0x08

    void Update(float dt);
    void Draw(ERC* rc, EVec3& pos);
};

// ############################################################################
//
//  TreeStack - Behavior tree execution stack (8 functions)
//
// ############################################################################

class TreeStack {
public:
    void** m_frames;        // 0x00
    int    m_depth;         // 0x04
    int    m_maxDepth;      // 0x08

    TreeStack() : m_frames(NULL), m_depth(0), m_maxDepth(0) {}
    ~TreeStack();

    void Init(int maxDepth) {
        m_maxDepth = maxDepth;
        m_frames = (void**)operator_new_impl(maxDepth * sizeof(void*));
        m_depth = 0;
    }

    bool Push(void* frame) {
        if (m_depth >= m_maxDepth) return false;
        m_frames[m_depth++] = frame;
        return true;
    }

    void* Pop() {
        if (m_depth <= 0) return NULL;
        return m_frames[--m_depth];
    }

    void* Peek() const {
        if (m_depth <= 0) return NULL;
        return m_frames[m_depth - 1];
    }

    int GetDepth() const { return m_depth; }
    bool IsEmpty() const { return m_depth == 0; }
    bool IsFull() const { return m_depth >= m_maxDepth; }
};

// ############################################################################
//
//  WallFadeParms - Wall fade visual parameters (1 function)
//
// ############################################################################

class WallFadeParms {
public:
    float m_fadeDistance;    // 0x00
    float m_fadeSpeed;      // 0x04
    float m_minAlpha;       // 0x08
    float m_maxAlpha;       // 0x0C

    void LoadDefaults() {
        m_fadeDistance = 3.0f;
        m_fadeSpeed = 2.0f;
        m_minAlpha = 0.1f;
        m_maxAlpha = 1.0f;
    }
};

// ############################################################################
//
//  WantFear - Sim wants/fears system (14 functions)
//
// ############################################################################

class WantFear {
public:
    int   m_wantId;         // 0x00
    int   m_type;           // 0x04 (0=want, 1=fear)
    int   m_targetGUID;     // 0x08
    int   m_score;          // 0x0C
    int   m_state;          // 0x10 (0=locked, 1=active, 2=fulfilled, 3=feared)
    float m_timeRemaining;  // 0x14
    int   m_iconId;         // 0x18

    WantFear() {
        m_wantId = 0;
        m_type = 0;
        m_targetGUID = 0;
        m_score = 0;
        m_state = 0;
        m_timeRemaining = 0.0f;
        m_iconId = 0;
    }

    void SetWant(int id, int score, int iconId) {
        m_wantId = id;
        m_type = 0;
        m_score = score;
        m_iconId = iconId;
        m_state = 1;
    }

    void SetFear(int id, int score, int iconId) {
        m_wantId = id;
        m_type = 1;
        m_score = score;
        m_iconId = iconId;
        m_state = 1;
    }

    void Fulfill() {
        m_state = 2;
    }

    void Trigger() {
        m_state = 3;
    }

    bool IsActive() const { return m_state == 1; }
    bool IsFulfilled() const { return m_state == 2; }
    bool IsTriggered() const { return m_state == 3; }
    int  GetScore() const { return m_score; }
    int  GetType() const { return m_type; }
    int  GetId() const { return m_wantId; }
    int  GetIconId() const { return m_iconId; }

    void ReconStream(ReconBuffer* buf, int version);
    void Update(float dt);
};

// ############################################################################
//
//  WorldMap - World/neighborhood map display (5 functions)
//
// ############################################################################

class WorldMap {
public:
    ERModel* m_mapModel;    // 0x00
    void*    m_hotspots;    // 0x04
    int      m_numHotspots; // 0x08
    int      m_selectedLot; // 0x0C
    int      m_state;       // 0x10

    WorldMap();
    ~WorldMap();
    void Init();
    void Update(float dt);
    void Draw(ERC* rc);
};

// ############################################################################
//
//  XObjLang - Object language/localization helpers (4 functions)
//
// ############################################################################

class XObjLang {
public:
    static const char* GetString(int stringId);
    static const char* GetStringForObject(cXObject* obj, int stringId);
    static int GetLanguage();
    static void SetLanguage(int langId);
};

// ############################################################################
//
//  XRoute - Sim routing/pathfinding route segment (14 functions)
//
// ############################################################################

class XRoute {
public:
    CTilePt m_start;        // 0x00
    CTilePt m_end;          // 0x04
    float   m_cost;         // 0x08
    int     m_type;         // 0x0C (walk, run, teleport, etc.)
    int     m_flags;        // 0x10
    void*   m_nextSegment;  // 0x14

    XRoute() {
        memset(this, 0, sizeof(XRoute));
    }

    void SetStart(CTilePt* pt) { memcpy(&m_start, pt, sizeof(CTilePt)); }
    void SetEnd(CTilePt* pt) { memcpy(&m_end, pt, sizeof(CTilePt)); }
    float GetCost() const { return m_cost; }
    int GetType() const { return m_type; }
    void SetCost(float cost) { m_cost = cost; }
    void SetType(int type) { m_type = type; }
    bool IsValid() const { return m_type != 0; }

    void Clear() {
        memset(this, 0, sizeof(XRoute));
    }

    void ReconStream(ReconBuffer* buf, int version);
    void CopyFrom(const XRoute* other) {
        memcpy(this, other, sizeof(XRoute));
    }

    XRoute* GetNextSegment() const { return (XRoute*)m_nextSegment; }
    void SetNextSegment(XRoute* next) { m_nextSegment = next; }
    float CalculateLength() const;
};

// ############################################################################
//
//  State Machine Classes - Game state management
//
//  The Sims 2 GC uses a hierarchical state machine system.
//  Each state has Enter/Exit/Update/Draw methods via vtable.
//  States reference their owner state machine via offset 0x08.
//
// ############################################################################

class StateMachineState {
public:
    void*  m_vtable;        // 0x00
    int    m_stateId;       // 0x04
    void*  m_owner;         // 0x08 - owning state machine

    virtual void Enter() {}
    virtual void Exit() {}
    virtual void Update(float dt) {}
    virtual void DrawTopmost(ERC* rc) {}
    void OwnerReturnFromState(int result);
};

// ############################################################################
//
//  LoadingScreenFadeInState - Loading screen fade-in (4 functions)
//
// ############################################################################

class LoadingScreenFadeInState : public StateMachineState {
public:
    // 0x8009027C (272 bytes)
    void Update(float dt) {
        void* sm = m_owner;  // TheSimsStateMachine*
        // Get loading screen from owner at offset 168
        // Update fade timer, check completion flags
        // If fade complete, check if loading is done
        // Transition to appropriate next state
    }

    void DrawTopmost(ERC* rc) {
        // Draw loading screen overlay with current fade alpha
    }

    float FaderUpdate(float dt) {
        // Update the fade interpolation and return current opacity
        return 0.0f;
    }

    float FaderGetFadeOpacity() {
        // Return current fade opacity value
        return 1.0f;
    }
};

// ############################################################################
//
//  LoadingScreenFadeOutState - (4 functions)
//
// ############################################################################

class LoadingScreenFadeOutState : public StateMachineState {
public:
    void Update(float dt);
    void DrawTopmost(ERC* rc);
    float FaderUpdate(float dt);
    float FaderGetFadeOpacity();
};

// ############################################################################
//
//  LoadingScreenUpdateState - (3 functions)
//
// ############################################################################

class LoadingScreenUpdateState : public StateMachineState {
public:
    void Enter();
    void Update(float dt);
    void DrawTopmost(ERC* rc);
};

// ############################################################################
//
//  LoadingScreenWaitingForLoadState - (2 functions)
//
// ############################################################################

class LoadingScreenWaitingForLoadState : public StateMachineState {
public:
    void Update(float dt);
    void DrawTopmost(ERC* rc);
};

// ############################################################################
//
//  TheSimsEAMovieState - EA intro movie state (3 functions)
//
// ############################################################################

class TheSimsEAMovieState : public StateMachineState {
public:
    // 0x80098660 (?)
    void Enter() {
        // Start playing EA logo movie
        // Set up movie player callback
    }

    void Update(float dt) {
        // Check if movie is done or skipped
        // If done, transition to next state
        void* sm = m_owner;
        // sm->IsFlowStateRequestPending() check
        // sm->GetFlowStateRequest() == expected -> transition
    }

    void Exit() {
        // Stop movie, release resources
    }
};

// ############################################################################
//
//  TheSimsEnterMainMenuState - (3 functions)
//
// ############################################################################

class TheSimsEnterMainMenuState : public StateMachineState {
public:
    void Enter();
    void Update(float dt);
    void Exit();
};

// ############################################################################
//
//  TheSimsMainMenuState - Main menu (6 functions)
//
// ############################################################################

class TheSimsMainMenuState : public StateMachineState {
public:
    void Enter();
    void Exit();
    void Update(float dt);
    void DrawTopmost(ERC* rc);
    void HandleInput(int buttonId);
    void OnMenuSelection(int menuItem);
};

// ############################################################################
//
//  TheSimsMaxisLogoState - Maxis logo screen (5 functions)
//
// ############################################################################

class TheSimsMaxisLogoState : public StateMachineState {
public:
    void Enter();
    void Exit();
    void Update(float dt);
    void DrawTopmost(ERC* rc);
    bool IsComplete() const;
};

// ############################################################################
//
//  TheSimsMemCardCheckState - Memory card check (2 functions)
//
// ############################################################################

class TheSimsMemCardCheckState : public StateMachineState {
public:
    void Enter() {
        // Check memory card status
    }

    void Update(float dt) {
        // Poll memory card, show dialog if needed
        // When done, transition to next state
    }
};

// ############################################################################
//
//  TheSimsNGCLicenseState - License screen (3 functions)
//
// ############################################################################

class TheSimsNGCLicenseState : public StateMachineState {
public:
    void Enter();
    void Update(float dt);
    void Exit();
};

// ############################################################################
//
//  TheSimsSimsIntroMovieState - Sims intro movie (3 functions)
//
// ############################################################################

class TheSimsSimsIntroMovieState : public StateMachineState {
public:
    void Enter();
    void Update(float dt);
    void Exit();
};

// ############################################################################
//
//  TheSimsStartScreenStateMachine - Start screen SM (6 functions)
//
// ############################################################################

class TheSimsStartScreenStateMachine {
public:
    void* m_vtable;         // 0x00
    void* m_states;         // 0x04
    int   m_currentState;   // 0x08
    int   m_numStates;      // 0x0C

    TheSimsStartScreenStateMachine();
    ~TheSimsStartScreenStateMachine();
    void Init();
    void Update(float dt);
    void Draw(ERC* rc);
    void TransitionTo(int stateId);
};

// ############################################################################
//
//  TheSimsStateMachine - Top-level game state machine (6 functions)
//
// ############################################################################

class TheSimsStateMachine {
public:
    void* m_vtable;         // 0x00
    void* m_stateArray;     // 0x04
    int   m_currentState;   // 0x08
    int   m_requestedState; // 0x0C
    int   m_flowState;      // 0x10

    bool IsFlowStateRequestPending() const {
        return m_requestedState != m_currentState;
    }

    int GetFlowStateRequest() const {
        return m_requestedState;
    }

    void SetFlowStateCurrent() {
        m_currentState = m_requestedState;
    }

    void RequestFlowState(int state) {
        m_requestedState = state;
    }

    void Update(float dt);
    void Init();
};

// ############################################################################
//
//  StartScreenStartState - Initial start screen (4 functions)
//
// ############################################################################

class StartScreenStartState : public StateMachineState {
public:
    void Enter();
    void Exit();
    void Update(float dt);
    void DrawTopmost(ERC* rc);
};

// ############################################################################
//
//  PreGameState - Pre-game setup state (3 functions)
//
// ############################################################################

class PreGameState : public StateMachineState {
public:
    void Enter();
    void Update(float dt);
    void Exit();
};

// ############################################################################
//
//  PreGameFreeplayState - Freeplay mode setup (3 functions)
//
// ############################################################################

class PreGameFreeplayState : public StateMachineState {
public:
    void Enter();
    void Update(float dt);
    void Exit();
};

// ############################################################################
//
//  PreGameCasPlayer1State / PreGameCasPlayer2State - CAS setup (2+3 functions)
//
// ############################################################################

class PreGameCasPlayer1State : public StateMachineState {
public:
    void Enter();
    void Update(float dt);
};

class PreGameCasPlayer2State : public StateMachineState {
public:
    void Enter();
    void Update(float dt);
    void Exit();
};

// ############################################################################
//
//  PreGameCreateAFamilyState - Create-A-Family mode (1 function)
//
// ############################################################################

class PreGameCreateAFamilyState : public StateMachineState {
public:
    void Update(float dt) {
        // Check flow state request
        // If pending, process and transition
    }
};

// ############################################################################
//
//  UrbzCreditsState - Credits display (1 function)
//
// ############################################################################

class UrbzCreditsState : public StateMachineState {
public:
    // 0x80098D58 (92 bytes)
    void Update(float dt) {
        void* sm = m_owner; // TheSimsStateMachine*
        // if (sm->IsFlowStateRequestPending()) {
        //     if (sm->GetFlowStateRequest() == 1) {
        //         sm->SetFlowStateCurrent();
        //         OwnerReturnFromState(1);
        //     }
        // }
    }
};

// ############################################################################
//
//  UrbzModeNewGameState - New game mode setup (1 function)
//
// ############################################################################

class UrbzModeNewGameState : public StateMachineState {
public:
    void Update(float dt);
};

// ############################################################################
//
//  MoviePlayerEndgameMovieState - End-game movie (3 functions)
//
// ############################################################################

class MoviePlayerEndgameMovieState : public StateMachineState {
public:
    void Enter();
    void Update(float dt);
    void Exit();
};

// ############################################################################
//
//  LiveModeChangeHouseStateMachine - House change SM (5 functions)
//
// ############################################################################

class LiveModeChangeHouseStateMachine {
public:
    void* m_vtable;
    int   m_state;
    int   m_targetHouseId;

    LiveModeChangeHouseStateMachine();
    ~LiveModeChangeHouseStateMachine();
    void Init();
    void Update(float dt);
    void SetTargetHouse(int houseId) { m_targetHouseId = houseId; }
};
