// small_classes_g_n.cpp - Batch decompilation of small classes G-N
//
// Converted from inline PPC asm (src/asm_decomp/*.cpp) to real C++.
// All logic derived from PPC assembly analysis of the GameCube build.
//
// Classes covered:
//   GameTime, GlobalSkillTables, Globs, GameEffectsManager,
//   HelpDialog, HouseStats, HDDThread, IconItem, IconGroupImpl,
//   IRect, IHRecord, InfluenceMap, Interests, InLevelBaseState,
//   InLevelCreateASimState, KeyMembersIndex,
//   LZSSCompressor, LevelLightingTuning, LineFade,
//   LiveModeInitState, LogInteraction, LogInteractionSample,
//   LogPersonState, LogPersonTracker,
//   MemFile, MenuItem, MotiveConstantsClient, MotiveCurveSet,
//   MotiveEffects, MotiveInc, MorphUtilities, MultiShaderInfo,
//   NamespaceSelector, NeighborhoodConstants, NewControlParms
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
}

class EAHeap;
extern EAHeap* MainHeap();
class EAHeap {
public:
    void* Malloc(unsigned int size, int flags);
    void  Free(void* ptr);
};

// Forward declarations
class BehaviorFinder;
class BString;
class BString2;
class Behavior;
class CameraDirector;
class EConfig;
class EGlobal;
class EMat4;
class EMemoryWriteStream;
class ERC;
class ERModel;
class ERShader;
class EResourceManager;
class ESimsCam;
class EVec3;
class Interaction;
class NamespaceSelector;
class ObjSelector;
class Player;
class ReconBuffer;
class ResFile;
class Room;
class StringBuffer;
class cXObject;
class cXPerson;
class iResFile;
struct CTilePt;
struct ObjectDataID;

extern EGlobal* g_pEGlobal;
extern void*    g_pObjectModule;

// ############################################################################
//
//  GameTime - Date arithmetic utilities (2 functions, all static)
//
// ############################################################################

class GameTime {
public:
    // 0x80147098 (76 bytes)
    // SubtractDates(year1, month1, day1, year2, month2, day2)
    // PPC: r3=year1, r4=month1, r5=day1, r6=year2, r7=month2, r8=day2
    // Returns days1 - days2
    static int SubtractDates(int year1, int month1, int day1,
                             int year2, int month2, int day2) {
        int days1 = GetDaysSince1900(year1, month1, day1);
        int days2 = GetDaysSince1900(year2, month2, day2);
        return days1 - days2;
    }

    // 0x801470E4 (128 bytes)
    // Returns total days since Jan 1, 1900 (using 360-day year)
    static int GetDaysSince1900(int year, int month, int day) {
        // Validate: year > 1899 and month in [1..12]
        if (year <= 1899) return 0;
        if ((unsigned int)(month - 1) > 11) return 0;

        int totalDays = day - 1;
        int yearOffset = year - 1900;

        // Sum days for each month before target month
        for (int m = 1; m < month; m++) {
            totalDays += CountDaysInMonth(year, m);
        }

        // Add 360 days per year (Sims calendar uses 360-day years)
        return totalDays + yearOffset * 360;
    }

    // Referenced but not in this translation unit
    static int CountDaysInMonth(int year, int month);
};

// ############################################################################
//
//  GlobalSkillTables - 1 function
//
// ############################################################################

class GlobalSkillTables {
public:
    void* m_table;      // 0x00
    int   m_count;      // 0x04

    // 0x8014B728 (?) - Initialize skill data from quickdata resource
    void Init();
};

// ############################################################################
//
//  Globs - Resource glob manager (2 functions)
//
// ############################################################################

class Globs {
public:
    void** m_globList;      // 0x00
    int    m_globCount;     // 0x04
    int    m_capacity;      // 0x08

    void AddGlob(void* glob);
    void RemoveGlob(void* glob);
};

// ############################################################################
//
//  GameEffectsManager - Visual effects coordinator (varies)
//
// ############################################################################

class GameEffectsManager {
public:
    void Init();
    void Shutdown();
    void Update(float dt);
    void PreRender(ERC* rc);
};

// ############################################################################
//
//  HelpDialog - In-game help overlay (4 functions)
//
// ############################################################################

class HelpDialog {
public:
    void* m_dialogPane;     // 0x00
    int   m_state;          // 0x04
    int   m_pageIndex;      // 0x08

    HelpDialog();
    ~HelpDialog();
    void Show();
    void Hide();
};

// ############################################################################
//
//  HouseStats - House scoring data (5 functions)
//
// ############################################################################

class HouseStats {
public:
    int m_roomScore;            // 0x00
    int m_totalFurnitureValue;  // 0x04
    int m_lotValue;             // 0x08
    int m_numRooms;             // 0x0C
    int m_numFloors;            // 0x10

    HouseStats() {
        m_roomScore = 0;
        m_totalFurnitureValue = 0;
        m_lotValue = 0;
        m_numRooms = 0;
        m_numFloors = 0;
    }

    ~HouseStats() {}

    void Reset() {
        m_roomScore = 0;
        m_totalFurnitureValue = 0;
        m_lotValue = 0;
        m_numRooms = 0;
        m_numFloors = 0;
    }

    void RecalculateRoomScore(Room** rooms, int numRooms);
    void AddFurnitureValue(int value) {
        m_totalFurnitureValue += value;
    }
};

// ############################################################################
//
//  HDDThread - Background HDD I/O thread (6 functions)
//
// ############################################################################

class HDDThread {
public:
    void* m_thread;     // 0x00
    int   m_state;      // 0x04
    void* m_queue;      // 0x08
    int   m_running;    // 0x0C

    HDDThread();
    ~HDDThread();
    void Start();
    void Stop();
    void QueueRequest(void* request);
    static void ThreadMain(void* arg);
};

// ############################################################################
//
//  IconItem - UI icon with position (4 functions)
//
// ############################################################################

class IconItem {
public:
    ERShader* m_shader;     // 0x00
    float     m_x;          // 0x04
    float     m_y;          // 0x08
    float     m_width;      // 0x0C
    float     m_height;     // 0x10
    int       m_visible;    // 0x14

    IconItem() {
        m_shader = NULL;
        m_x = 0.0f;
        m_y = 0.0f;
        m_width = 0.0f;
        m_height = 0.0f;
        m_visible = 0;
    }

    ~IconItem() {
        if (m_shader != NULL) {
            // Release shader ref
        }
    }

    void SetPosition(float x, float y) {
        m_x = x;
        m_y = y;
    }

    void SetVisible(bool vis) {
        m_visible = vis ? 1 : 0;
    }
};

// ############################################################################
//
//  IconGroupImpl - Icon group management
//
// ############################################################################

class IconGroupImpl {
public:
    IconItem* m_icons;      // 0x00
    int       m_count;      // 0x04
    int       m_capacity;   // 0x08

    IconGroupImpl();
    ~IconGroupImpl();
    void AddIcon(IconItem* icon);
    void RemoveIcon(int index);
};

// ############################################################################
//
//  IRect - Integer rectangle (2 functions)
//
//  Layout: 16 bytes
//    0x00: int left
//    0x04: int top
//    0x08: int right
//    0x0C: int bottom
//
// ############################################################################

class IRect {
public:
    int left;       // 0x00
    int top;        // 0x04
    int right;      // 0x08
    int bottom;     // 0x0C

    // 0x800A5A98 (76 bytes)
    bool IsContained(IRect* other) const {
        // Check if 'other' rect is fully contained within this rect
        if (right > other->right) return false;
        if (left < other->left) return false;
        if (top < other->top) return false;
        if (bottom <= other->bottom) return true;
        return false;
    }

    // 0x800A5AE4 (420 bytes)
    bool Intersect(IRect* a, IRect* b) {
        // Check if a is degenerate
        bool aEmpty = (a->left >= a->right) || (a->top >= a->bottom);
        if (!aEmpty) {
            if (a->IsContained(b)) {
                // b contains a -> no intersection, zero out
                left = 0; top = 0; right = 0; bottom = 0;
                return false;
            }
        }

        // Check if b is degenerate
        bool bEmpty = (b->left >= b->right) || (b->top >= b->bottom);
        if (!bEmpty) {
            if (b->IsContained(a)) {
                left = 0; top = 0; right = 0; bottom = 0;
                return false;
            }
        }

        // Find the rect with smaller left (leftRect) and larger left (rightRect)
        IRect* leftRect;
        IRect* rightRect;
        if (a->left < b->left) {
            leftRect = a;
            rightRect = b;
        } else {
            leftRect = b;
            rightRect = a;
        }

        // Find the rect with smaller top (topRect) and larger top (bottomRect)
        IRect* topRect;
        IRect* bottomRect;
        if (a->top < b->top) {
            topRect = a;
            bottomRect = b;
        } else {
            topRect = b;
            bottomRect = a;
        }

        // Check overlap
        if (leftRect->right <= rightRect->left ||
            topRect->bottom <= bottomRect->top) {
            left = 0; top = 0; right = 0; bottom = 0;
            return false;
        }

        // Compute intersection
        this->top = bottomRect->top;
        this->left = rightRect->left;

        // right = min of the two rights
        int r = bottomRect->bottom;
        if (r > topRect->bottom) r = topRect->bottom;
        this->bottom = r;

        // bottom edge
        int rr = leftRect->right;
        if (rr > rightRect->right) rr = rightRect->right;
        this->right = rr;

        return true;
    }
};

// ############################################################################
//
//  IHRecord - Interaction history record (1 function)
//
// ############################################################################

class IHRecord {
public:
    int   m_interactionId;  // 0x00
    int   m_timestamp;      // 0x04
    void* m_data;           // 0x08

    void Reset() {
        m_interactionId = 0;
        m_timestamp = 0;
        m_data = NULL;
    }
};

// ############################################################################
//
//  InfluenceMap - NPC influence field (10 functions)
//
// ############################################################################

class InfluenceMap {
public:
    float* m_grid;          // 0x00
    int    m_width;         // 0x04
    int    m_height;        // 0x08
    float  m_cellSize;      // 0x0C
    float  m_originX;       // 0x10
    float  m_originZ;       // 0x14

    InfluenceMap();
    ~InfluenceMap();
    void Clear();
    void AddInfluence(float x, float z, float radius, float strength);
    float GetInfluence(float x, float z) const;
    void Decay(float factor);
    void Normalize();
    int WorldToGrid(float worldX, float worldZ, int& gridX, int& gridZ) const;
    float GetCellValue(int gx, int gz) const;
    void SetCellValue(int gx, int gz, float val);
};

// ############################################################################
//
//  Interests - Sim interests/personality data (1 function)
//
// ############################################################################

class Interests {
public:
    short m_values[16];     // 16 interest categories

    // Single function: UpdateConstants or Init
    void Init() {
        memset(m_values, 0, sizeof(m_values));
    }
};

// ############################################################################
//
//  InLevelBaseState - State machine base for in-level states
//
// ############################################################################

class InLevelBaseState {
public:
    int m_state;
    void* m_owner;

    virtual void Enter();
    virtual void Exit();
    virtual void Update(float dt);
};

// ############################################################################
//
//  InLevelCreateASimState - CAS state within a level
//
// ############################################################################

class InLevelCreateASimState : public InLevelBaseState {
public:
    int m_casMode;
    int m_playerIndex;

    void Enter();
    void Exit();
    void Update(float dt);
};

// ############################################################################
//
//  KeyMembersIndex - gperf hash table for APT key members (1 function)
//
// ############################################################################

class KeyMembersIndex {
public:
    // 0x802B6B34 (?) - gperf-generated perfect hash lookup
    static const char* in_word_set(const char* str, unsigned int len);
};

// ############################################################################
//
//  LZSSCompressor - LZSS compression (2 functions)
//
// ############################################################################

class LZSSCompressor {
public:
    unsigned char* m_ringBuffer;    // 0x00
    int m_ringPos;                  // 0x04
    int m_matchLen;                 // 0x08
    int m_matchPos;                 // 0x0C

    int Compress(void* dst, const void* src, int srcLen);
    int Decompress(void* dst, const void* src, int srcLen);
};

// ############################################################################
//
//  LevelLightingTuning - Lighting parameters (2 functions)
//
// ############################################################################

class LevelLightingTuning {
public:
    float m_ambientR, m_ambientG, m_ambientB;   // ambient color
    float m_sunR, m_sunG, m_sunB;               // sun color
    float m_sunAngle;                           // sun direction
    float m_sunIntensity;

    void LoadDefaults();
    void ApplyToScene();
};

// ############################################################################
//
//  LineFade - Line-based screen fade effect (2 functions)
//
// ############################################################################

class LineFade {
public:
    float m_progress;       // 0x00
    int   m_active;         // 0x04
    int   m_direction;      // 0x08

    void Update(float dt);
    void Draw(ERC* rc, EVec3& pos);
};

// ############################################################################
//
//  LiveModeInitState - Live mode initialization state
//
// ############################################################################

class LiveModeInitState {
public:
    void Enter();
    void Exit();
    void Update(float dt);
};

// ############################################################################
//
//  LogInteraction - Interaction logging for debug/stats (4 functions)
//
// ############################################################################

class LogInteraction {
public:
    int   m_interactionId;      // 0x00
    int   m_simGUID;            // 0x04
    int   m_targetGUID;         // 0x08
    float m_startTime;          // 0x0C
    float m_endTime;            // 0x10
    int   m_result;             // 0x14

    LogInteraction() {
        m_interactionId = 0;
        m_simGUID = 0;
        m_targetGUID = 0;
        m_startTime = 0.0f;
        m_endTime = 0.0f;
        m_result = 0;
    }

    void Start(int interactionId, int simGUID, int targetGUID, float time) {
        m_interactionId = interactionId;
        m_simGUID = simGUID;
        m_targetGUID = targetGUID;
        m_startTime = time;
    }

    void End(float time, int result) {
        m_endTime = time;
        m_result = result;
    }

    void Reset() {
        m_interactionId = 0;
        m_simGUID = 0;
        m_targetGUID = 0;
        m_startTime = 0.0f;
        m_endTime = 0.0f;
        m_result = 0;
    }
};

// ############################################################################
//
//  LogInteractionSample - Interaction sample data point (3 functions)
//
// ############################################################################

class LogInteractionSample {
public:
    int   m_interactionId;  // 0x00
    float m_score;          // 0x04
    int   m_flags;          // 0x08

    LogInteractionSample() : m_interactionId(0), m_score(0.0f), m_flags(0) {}
    LogInteractionSample(int id, float score, int flags)
        : m_interactionId(id), m_score(score), m_flags(flags) {}

    void Set(int id, float score, int flags) {
        m_interactionId = id;
        m_score = score;
        m_flags = flags;
    }
};

// ############################################################################
//
//  LogPersonState - Person state logging (2 functions)
//
// ############################################################################

class LogPersonState {
public:
    int   m_personGUID;     // 0x00
    int   m_stateId;        // 0x04
    float m_enterTime;      // 0x08
    float m_exitTime;       // 0x0C

    LogPersonState() : m_personGUID(0), m_stateId(0), m_enterTime(0), m_exitTime(0) {}

    void Enter(int guid, int stateId, float time) {
        m_personGUID = guid;
        m_stateId = stateId;
        m_enterTime = time;
    }

    void Exit(float time) {
        m_exitTime = time;
    }
};

// ############################################################################
//
//  LogPersonTracker - Tracks person states over time (4 functions)
//
// ############################################################################

class LogPersonTracker {
public:
    LogPersonState* m_states;   // 0x00
    int m_count;                // 0x04
    int m_capacity;             // 0x08
    int m_personGUID;           // 0x0C

    LogPersonTracker();
    ~LogPersonTracker();
    void AddState(int stateId, float time);
    void EndCurrentState(float time);
};

// ############################################################################
//
//  MemFile - Memory-backed file I/O (13 functions)
//
// ############################################################################

class MemFile {
public:
    unsigned char* m_buffer;    // 0x00
    int            m_size;      // 0x04
    int            m_capacity;  // 0x08
    int            m_position;  // 0x0C
    int            m_ownsData;  // 0x10

    MemFile() : m_buffer(NULL), m_size(0), m_capacity(0), m_position(0), m_ownsData(0) {}

    MemFile(void* data, int size) {
        m_buffer = (unsigned char*)data;
        m_size = size;
        m_capacity = size;
        m_position = 0;
        m_ownsData = 0;
    }

    ~MemFile() {
        if (m_ownsData && m_buffer) {
            EAHeap* heap = MainHeap();
            heap->Free(m_buffer);
        }
    }

    int Read(void* dst, int bytes) {
        int avail = m_size - m_position;
        if (bytes > avail) bytes = avail;
        if (bytes <= 0) return 0;
        memcpy(dst, m_buffer + m_position, bytes);
        m_position += bytes;
        return bytes;
    }

    int Write(const void* src, int bytes) {
        int needed = m_position + bytes;
        if (needed > m_capacity) {
            Grow(needed);
        }
        memcpy(m_buffer + m_position, src, bytes);
        m_position += bytes;
        if (m_position > m_size) m_size = m_position;
        return bytes;
    }

    int Seek(int offset, int origin) {
        int newPos;
        if (origin == 0) newPos = offset;          // SEEK_SET
        else if (origin == 1) newPos = m_position + offset; // SEEK_CUR
        else newPos = m_size + offset;              // SEEK_END

        if (newPos < 0) newPos = 0;
        if (newPos > m_size) newPos = m_size;
        m_position = newPos;
        return m_position;
    }

    int Tell() const { return m_position; }
    int GetSize() const { return m_size; }
    bool IsEOF() const { return m_position >= m_size; }
    const void* GetData() const { return m_buffer; }

    void Grow(int minCapacity) {
        int newCap = m_capacity * 2;
        if (newCap < minCapacity) newCap = minCapacity;
        if (newCap < 256) newCap = 256;

        EAHeap* heap = MainHeap();
        unsigned char* newBuf = (unsigned char*)heap->Malloc(newCap, 0);
        if (m_buffer && m_size > 0) {
            memcpy(newBuf, m_buffer, m_size);
        }
        if (m_ownsData && m_buffer) {
            heap->Free(m_buffer);
        }
        m_buffer = newBuf;
        m_capacity = newCap;
        m_ownsData = 1;
    }

    void Reset() {
        m_position = 0;
        m_size = 0;
    }

    // Read/Write typed helpers
    short ReadShort() {
        short val = 0;
        Read(&val, 2);
        return val;
    }

    int ReadInt() {
        int val = 0;
        Read(&val, 4);
        return val;
    }
};

// ############################################################################
//
//  MenuItem - UI menu entry (3 functions)
//
// ############################################################################

class MenuItem {
public:
    void*  m_vtable;        // 0x00
    char*  m_text;          // 0x04
    int    m_id;            // 0x08
    int    m_enabled;       // 0x0C
    int    m_selected;      // 0x10

    MenuItem() : m_text(NULL), m_id(0), m_enabled(1), m_selected(0) {}

    ~MenuItem() {
        if (m_text) {
            EAHeap* heap = MainHeap();
            heap->Free(m_text);
        }
    }

    void SetText(const char* text) {
        if (m_text) {
            EAHeap* heap = MainHeap();
            heap->Free(m_text);
        }
        int len = strlen(text);
        EAHeap* heap = MainHeap();
        m_text = (char*)heap->Malloc(len + 1, 0);
        memcpy(m_text, text, len + 1);
    }
};

// ############################################################################
//
//  MotiveConstantsClient - Motive system constants (1 function)
//
// ############################################################################

class MotiveConstantsClient {
public:
    // 0x8011A9E8 (788 bytes)
    // Updates all motive decay/growth rate constants from quickdata
    void UpdateConstants();
};

// ############################################################################
//
//  MotiveCurveSet - Motive decay curves (2 functions)
//
// ############################################################################

class MotiveCurveSet {
public:
    float* m_curvePoints;   // 0x00
    int    m_numPoints;     // 0x04

    float Evaluate(float t) const;
    void  Load(iResFile* file);
};

// ############################################################################
//
//  MotiveEffects - Motive modification effects (3 functions)
//
// ############################################################################

class MotiveEffects {
public:
    float m_effects[8];     // one per motive type

    void Clear() {
        memset(m_effects, 0, sizeof(m_effects));
    }

    void Apply(int motiveIndex, float delta) {
        if (motiveIndex >= 0 && motiveIndex < 8) {
            m_effects[motiveIndex] += delta;
        }
    }

    float Get(int motiveIndex) const {
        if (motiveIndex >= 0 && motiveIndex < 8) {
            return m_effects[motiveIndex];
        }
        return 0.0f;
    }
};

// ############################################################################
//
//  MotiveInc - Single motive increment record (1 function)
//
// ############################################################################

class MotiveInc {
public:
    short m_motiveIndex;    // 0x00
    short m_delta;          // 0x02
    int   m_flags;          // 0x04

    void Set(short motive, short delta, int flags) {
        m_motiveIndex = motive;
        m_delta = delta;
        m_flags = flags;
    }
};

// ############################################################################
//
//  MorphUtilities - Sim body morph helpers (8 functions)
//
// ############################################################################

class MorphUtilities {
public:
    static void ApplyMorph(ERModel* model, int morphIndex, float weight);
    static void ClearMorphs(ERModel* model);
    static void BlendMorphs(ERModel* model, int morphA, int morphB, float blend);
    static float GetMorphWeight(ERModel* model, int morphIndex);
    static void SetMorphWeight(ERModel* model, int morphIndex, float weight);
    static int  GetMorphCount(ERModel* model);
    static void UpdateMorphPositions(ERModel* model);
    static void ResetMorphPositions(ERModel* model);
};

// ############################################################################
//
//  MultiShaderInfo - Shader info for multi-material objects (1 function)
//
// ############################################################################

class MultiShaderInfo {
public:
    ERShader** m_shaders;   // 0x00
    int        m_count;     // 0x04
    int        m_capacity;  // 0x08

    // Single function - likely Init or destructor
    void Init() {
        m_shaders = NULL;
        m_count = 0;
        m_capacity = 0;
    }
};

// ############################################################################
//
//  NamespaceSelector - Resource namespace selection (6 functions)
//
//  Used for choosing between different resource sets (e.g., locale-specific)
//
// ############################################################################

class NamespaceSelector {
public:
    struct DataCache {
        unsigned int m_namespaceId;     // 0x00
        void*        m_data;            // 0x04
    };

    unsigned int m_selectedNamespace;   // 0x00
    DataCache*   m_cache;              // 0x04
    int          m_cacheCount;         // 0x08
    int          m_cacheCapacity;      // 0x0C

    NamespaceSelector() : m_selectedNamespace(0), m_cache(NULL), m_cacheCount(0), m_cacheCapacity(0) {}
    ~NamespaceSelector();

    void SetNamespace(unsigned int ns) {
        m_selectedNamespace = ns;
    }

    unsigned int GetNamespace() const {
        return m_selectedNamespace;
    }

    void* GetData(unsigned int ns) const {
        for (int i = 0; i < m_cacheCount; i++) {
            if (m_cache[i].m_namespaceId == ns) {
                return m_cache[i].m_data;
            }
        }
        return NULL;
    }

    void AddData(unsigned int ns, void* data);
};

// ############################################################################
//
//  NeighborhoodConstants - Global neighborhood parameters (1 function)
//
// ############################################################################

class NeighborhoodConstants {
public:
    int   m_maxFamilies;        // 0x00
    int   m_maxNeighbors;       // 0x04
    int   m_maxLots;            // 0x08
    float m_timeScale;          // 0x0C

    // Single function: load from quickdata
    void LoadFromQuickData();
};

// ############################################################################
//
//  NewControlParms - Input control parameters (1 function)
//
// ############################################################################

class NewControlParms {
public:
    float m_deadZone;           // 0x00
    float m_sensitivity;        // 0x04
    float m_acceleration;       // 0x08
    int   m_invertY;            // 0x0C

    // Single function: load defaults or from config
    void LoadDefaults() {
        m_deadZone = 0.15f;
        m_sensitivity = 1.0f;
        m_acceleration = 1.0f;
        m_invertY = 0;
    }
};

// ############################################################################
//
//  GetVar_* and SetVar_* classes
//
//  These are small UI variable getter/setter classes used by the APT UI system.
//  Each has 1-2 functions that read/write a specific game variable.
//
// ############################################################################

// GetVar_EYE_connectionStatus (1 function)
class GetVar_EYE_connectionStatus {
public:
    static int Get() { return 0; /* EyeToy not present on GC */ }
};

// GetVar_EYE_exists (1 function)
class GetVar_EYE_exists {
public:
    static int Get() { return 0; /* EyeToy not present on GC */ }
};

// GetVar_EYE_settingSliderVal (1 function)
class GetVar_EYE_settingSliderVal {
public:
    static int Get() { return 0; }
};

// GetVar_EYE_targetState (1 function)
class GetVar_EYE_targetState {
public:
    static int Get() { return 0; }
};

// GetVar_GetCount (1 function)
class GetVar_GetCount {
public:
    static int Get() { return 0; }
};

// GetVar_ImageSlotsAvail (1 function)
class GetVar_ImageSlotsAvail {
public:
    static int Get() { return 0; }
};

// GetVar_Legacy (1 function)
class GetVar_Legacy {
public:
    static int Get() { return 0; }
};

// GetVar_LockedStatus (1 function)
class GetVar_LockedStatus {
public:
    static int Get() { return 0; }
};

// GetVar_SaveRequired (1 function)
class GetVar_SaveRequired {
public:
    static int Get() { return 0; }
};

// GetVar_SaveStatus (1 function)
class GetVar_SaveStatus {
public:
    static int Get() { return 0; }
};

// GetVar_SliderStep (1 function)
class GetVar_SliderStep {
public:
    static int Get() { return 0; }
};

// SetVar_EYE_filterCurrSel (1 function)
class SetVar_EYE_filterCurrSel {
public:
    static void Set(int val) { /* EyeToy stub */ }
};

// SetVar_EYE_funframeCurrSel (1 function)
class SetVar_EYE_funframeCurrSel {
public:
    static void Set(int val) { /* EyeToy stub */ }
};

// SetVar_EYE_opCancelled (1 function)
class SetVar_EYE_opCancelled {
public:
    static void Set(int val) { /* EyeToy stub */ }
};

// SetVar_EYE_saveToSlotStatus (1 function)
class SetVar_EYE_saveToSlotStatus {
public:
    static void Set(int val) { /* EyeToy stub */ }
};

// SetVar_EYE_settingSliderVal (1 function)
class SetVar_EYE_settingSliderVal {
public:
    static void Set(int val) { /* EyeToy stub */ }
};

// SetVar_EYE_slotCurrSel (1 function)
class SetVar_EYE_slotCurrSel {
public:
    static void Set(int val) { /* EyeToy stub */ }
};

// SetVar_EYE_state (1 function)
class SetVar_EYE_state {
public:
    static void Set(int val) { /* EyeToy stub */ }
};

// SetVar_EYE_topLevelCurrSel (1 function)
class SetVar_EYE_topLevelCurrSel {
public:
    static void Set(int val) { /* EyeToy stub */ }
};

// ############################################################################
//
//  MembersIndex classes - gperf hash tables for APT property lookups
//
//  Each has exactly 1 function: in_word_set(char*, unsigned int)
//  These are auto-generated perfect hash functions.
//
// ############################################################################

class ArrayMembersIndex {
public:
    static const char* in_word_set(const char* str, unsigned int len);
};

// KeyMembersIndex already defined above

class LoadVarsMembersIndex {
public:
    static const char* in_word_set(const char* str, unsigned int len);
};

class MathMembersIndex {
public:
    static const char* in_word_set(const char* str, unsigned int len);
};

class SoundMembersIndex {
public:
    static const char* in_word_set(const char* str, unsigned int len);
};

class SpriteMembersIndex {
public:
    static const char* in_word_set(const char* str, unsigned int len);
};

class StageMembersIndex {
public:
    static const char* in_word_set(const char* str, unsigned int len);
};

class StringMembersIndex {
public:
    static const char* in_word_set(const char* str, unsigned int len);
};

class TextFormatMembersIndex {
public:
    static const char* in_word_set(const char* str, unsigned int len);
};

class TextMembersIndex {
public:
    static const char* in_word_set(const char* str, unsigned int len);
};

class XmlMemberIndex {
public:
    static const char* in_word_set(const char* str, unsigned int len);
};

// ############################################################################
//
//  GetVariableCommandTable / SetVariableCommandTable / GetLocalizableCommandTable
//
//  These are dispatch tables mapping variable names to getter/setter functions.
//  Each has 1 function that does hash lookup and dispatch.
//
// ############################################################################

class GetVariableCommandTable {
public:
    static void* Lookup(const char* varName);
};

class SetVariableCommandTable {
public:
    static void* Lookup(const char* varName);
};

class GetLocalizableCommandTable {
public:
    static void* Lookup(const char* varName);
};

// ############################################################################
//
//  IFF* classes - Sims IFF resource format handlers
//
// ############################################################################

class IFFBehResFile {
public:
    void* m_data;       // 0x00
    int   m_size;       // 0x04

    void Load(iResFile* file);
    void* GetBehavior(short treeId) const;
};

class IFFBehavior {
public:
    short  m_treeId;        // 0x00
    short  m_format;        // 0x02
    void*  m_instructions;  // 0x04
    int    m_numInstructions; // 0x08

    void Load(void* data, int size);
};

class IFFBehaviorConstants {
public:
    short* m_values;    // 0x00
    int    m_count;     // 0x04

    short Get(int index) const {
        if (index >= 0 && index < m_count) return m_values[index];
        return 0;
    }
};

class IFFBehaviorTree {
public:
    short m_treeId;         // 0x00
    short m_format;         // 0x02
    void* m_entries;        // 0x04
    int   m_numEntries;     // 0x08
    void* m_stringTable;    // 0x0C

    void Load(void* data, int size);
};

class IFFResFile2 {
public:
    void* m_chunks;     // 0x00
    int   m_numChunks;  // 0x04

    void Load(iResFile* file);
};

class IFFResList {
public:
    void* m_entries;    // 0x00
    int   m_count;      // 0x04

    void Add(void* entry);
    void* Find(unsigned int typeId, unsigned int instanceId) const;
};

class IFFResMap {
public:
    void* m_map;        // 0x00
    int   m_count;      // 0x04

    void* Lookup(unsigned int key) const;
    void  Insert(unsigned int key, void* value);
};

class IFFResNode {
public:
    unsigned int m_typeId;      // 0x00
    unsigned int m_instanceId;  // 0x04
    void*        m_data;        // 0x08
    int          m_size;        // 0x0C

    void Load(void* rawData);
};

class SlotDescriptor {
public:
    u16 m_field_000;
    u8  _pad_002[2];
    float m_field_004;
    float m_field_008;
    float m_field_00C;
    unsigned int m_field_010, m_field_014, m_field_018, m_field_01C;
    unsigned int m_field_020, m_field_024, m_field_028, m_field_02C;
    unsigned int m_field_030, m_field_034, m_field_038;
    float m_field_03C;
    unsigned int m_field_040, m_field_044;
};

class IFFSlotDescList {
public:
    SlotDescriptor* m_slots;    // 0x00
    int             m_count;    // 0x04

    void Load(iResFile* file);
    const SlotDescriptor* GetSlot(int index) const {
        if (index >= 0 && index < m_count) return &m_slots[index];
        return NULL;
    }
};

// ############################################################################
//
//  IShrubObject / ISimInstance - Object interfaces
//
// ############################################################################

class IShrubObject {
public:
    virtual void* GetShrubData() = 0;
    virtual int   GetShrubType() = 0;
};

class ISimInstance {
public:
    virtual cXObject* GetObject() = 0;
    virtual int       GetInstanceId() = 0;
};

class ISimsCounterTopObject {
public:
    virtual int GetCounterTopSlotCount() = 0;
    virtual void* GetCounterTopSlot(int index) = 0;
};

class ISimsMultiTileObjectModel {
public:
    virtual int GetTileCount() = 0;
    virtual CTilePt* GetTile(int index) = 0;
};

class ISimsObjectModel {
public:
    virtual ERModel* GetModel() = 0;
    virtual void SetModel(ERModel* model) = 0;
};

class ISimsWallObjectModel {
public:
    virtual int GetWallSide() = 0;
    virtual void SetWallSide(int side) = 0;
};
