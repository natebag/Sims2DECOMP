// medium_engine_core.cpp - Engine/Renderer/Audio medium stubs (101-500 lines)
// E* engine, ENgc* GameCube, ER* resources, Effects, Memory, Threading, CTG
// Converted from PPC inline asm to portable C++
#include "types.h"

// ============================================================
// Forward declarations and externs
// ============================================================

extern "C" {
    void* memcpy(void*, const void*, unsigned int);
    void* memset(void*, int, unsigned int);
    char* strncpy(char*, const char*, unsigned int);
    char* strcpy(char*, const char*);
    char* strcat(char*, const char*);
    unsigned int strlen(const char*);
    int Sprintf(char*, char*, ...);
    int Vsprintf(char*, char*, void*);
    float acosf(float);
    float cosf(float);
    void PSVECMag(void*); // returns in f1
    void PSVECDotProduct(void*, void*); // returns in f1
    void DCFlushRange(void*, unsigned int);
    void DCInvalidateRange(void*, unsigned int);
    int OSDisableInterrupts();
    int OSEnableInterrupts();
    void ARInit(int, int);
    void ARQInit();
    unsigned int ARGetBaseAddress();
    void ARQPostRequest(void*, int, int, int, void*, unsigned int, unsigned int, void*);
    void PADInit();
    void PADRecalibrate(unsigned int);
    void PADRead(void*);
    void PADClampCircle(void*);
    void PADReset(unsigned int);
    void PADControlMotor(int, int);
    int DVDGetDriveStatus();
    int DVDSetAutoFatalMessaging(int);
    void OSCreateAlarm(void*);
    void OSSetAlarmTag(void*, void*);
    void OSSetAlarm(void*, int, unsigned int, void*);
}

class EAHeap;
class ENodeList;
class ERedBlackTree;
class EResource;
class EInstance;
class EStream;
class EVec3;
class EBound3;
class EBoundSphere;
class EStorable;
class ETypeInfo;
class EMat4;
class EFile;
class ERC;
class ESyncObject;
class ESemaphore;
class EController;
class EDebugMenuItem;
class EEngine;
class EGlobal;
class EGlobalManagerClient;
class ECheats;
class FastAllocPool;
class BloomSettings;
class PADStatus;
class ObjSelector;

extern EAHeap* MainHeap();
extern void EORDbgTrace(char*, ...);

// ============================================================
// EACTrack — Audio track
// ============================================================

class EACTrack {
public:
    float m_field_0x00;       // 0x00
    float m_field_0x04;       // 0x04
    int   m_field_0x08;       // 0x08
    char  m_field_0x0C;       // 0x0C
    char  m_field_0x0D;       // 0x0D
    char  m_field_0x0E;       // 0x0E
    char  _pad0[1];
    float m_field_0x10;       // 0x10
    float m_field_0x14;       // 0x14
    float m_field_0x18;       // 0x18
    float m_field_0x1C;       // 0x1C
    int   m_field_0x20;       // 0x20 (offset 32)
    int   m_field_0x24;       // 0x24
    int   m_field_0x28;       // 0x28
    int   m_field_0x2C;       // 0x2C (offset 44)
    int   m_field_0x30;       // 0x30 (offset 48)
    char  _pad1[12];
    float m_field_0x3C;       // 0x3C (offset 60)
    float m_field_0x40;       // 0x40 (offset 64)
    char  _pad2[8];
    float m_field_0x4C;       // 0x4C (offset 76)
    float m_field_0x50;       // 0x50 (offset 80)
    char  _pad3[8];
    float m_field_0x5C;       // 0x5C (offset 92)
    char  _pad4[20];
    int   m_field_0x74;       // 0x74 (offset 116)
    float m_field_0x78;       // 0x78 (offset 120)
    int   m_pResource;        // 0x7C (offset 124)
    char  _pad5[4];           // 0x80 (offset 128)
    char  _pad6[8];           // 0x84
    ERedBlackTree* m_tree;    // 0x8C (offset 140) — actually embedded at +140
    char  _pad7[12];
    int   m_field_0x98;       // 0x98 (offset 152)
    int   m_field_0x9C;       // 0x9C (offset 156)
    char  m_field_0xA0;       // 0xA0 (offset 160)
    char  _pad8[3];
    int   m_field_0xA4;       // 0xA4 (offset 164)
    int   m_field_0xA8;       // 0xA8 (offset 168)
    int   m_field_0xAC;       // 0xAC (offset 172)

    EACTrack(void);
    void operator=(EACTrack& other);
};

// 0x802E76A8
EACTrack::EACTrack(void) {
    // Initialize with float constants from rodata
    m_field_0x00 = 0.0f;
    m_field_0x08 = 251;
    m_field_0x0C = 3;
    m_field_0x0D = 0;
    m_field_0x0E = 1;
    m_field_0x04 = 1.0f;
    m_field_0x10 = 0.0f;
    m_field_0x14 = 0.0f;
    m_field_0x1C = 0.0f;  // from rodata
    m_field_0x20 = 0;     // from rodata
    m_field_0x18 = 0.0f;  // from rodata
    m_pResource = 0;
    // Construct embedded ERedBlackTree at offset 140
    // ERedBlackTree::ERedBlackTree() called on this+140
    m_field_0x74 = -1;
    m_field_0x78 = 0.0f;
    m_field_0x50 = 1.0f;
    m_field_0x30 = 0;
    m_field_0x24 = 0;
    m_field_0x28 = 0;
    m_field_0x3C = 0.0f;
    m_field_0x40 = 0.0f;
    m_field_0x4C = 1.0f;
    m_field_0x00 = 1.0f;
    m_field_0xA0 = 0;
    m_field_0x5C = 0.0f;
    m_field_0x98 = 0;
    m_field_0x9C = 0;
    m_field_0xA8 = 0;
    m_field_0xAC = 0;
}

// 0x803C33B4
void EACTrack::operator=(EACTrack& other) {
    // Copy first 48 bytes (fields 0x00..0x2F) in a loop (24-byte chunks * 2 + 12 remainder)
    memcpy(this, &other, 48);
    // Copy floats at offsets 60..112
    // Copy resource pointer with ref management
    // Copy ERedBlackTree with operator=
    // Copy trailing fields
    // (Simplified: bulk copy with resource ref management)
}


// ============================================================
// EAllocGroup — Group memory allocator
// ============================================================

class EAllocGroup : public ENodeList {
public:
    int   m_blockSize;    // 0x10 (offset 16)
    int   m_currentOff;   // 0x14 (offset 20)
    EAHeap* m_heap;       // 0x0C (offset 12)

    EAllocGroup(int blockSize);
    void* Alloc(unsigned int size, int alignment);
    void DeallocateAll(void);
    void MoveContents(EAllocGroup& other);
    void Validate(void);
};

// 0x80359E0C
EAllocGroup::EAllocGroup(int blockSize) {
    // offset 0: ENodeList head = 0
    // offset 4: ENodeList tail = 0
    // offset 8: ENodeList count = 1
    *(int*)((char*)this + 0) = 0;
    *(int*)((char*)this + 8) = 1;
    *(int*)((char*)this + 20) = blockSize + blockSize; // doubled
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 16) = blockSize;
    m_heap = MainHeap();
}

// 0x80359E68
void* EAllocGroup::Alloc(unsigned int size, int alignment) {
    unsigned int blockSize = *(unsigned int*)((char*)this + 16);
    if (size >= blockSize || alignment > 32) {
        // Large allocation — direct from heap
        void* ptr = m_heap->MallocAligned(size, 0, 0);
        if (ptr) {
            // ENodeList::AddHead
        }
        return ptr;
    }
    // Try to fit in current block
    unsigned int off = *(unsigned int*)((char*)this + 20);
    unsigned int alignMask = alignment - 1;
    unsigned int aligned = (off + alignMask) & ~alignMask;
    unsigned int newOff = aligned + size;
    if (newOff >= blockSize) {
        // Need new block
        void* ptr = m_heap->MallocAligned(blockSize, 32, 0);
        if (ptr) {
            // ENodeList::AddTail
            *(unsigned int*)((char*)this + 20) = size;
        }
        return ptr;
    }
    // Fit within current block
    void* base = *(void**)((char*)this + 4); // tail node data
    void* data = (char*)*(void**)base + aligned;
    *(unsigned int*)((char*)this + 20) = newOff;
    return data;
}

// 0x80359F38
void EAllocGroup::DeallocateAll(void) {
    // Walk node list, free each block via heap
    void* node = *(void**)((char*)this + 4); // first node
    while (node != NULL) {
        void* data = *(void**)node;
        m_heap->Free(data);
        node = *(void**)((char*)node + 4); // next
    }
    // ENodeList::RemoveAll()
    unsigned int bs = *(unsigned int*)((char*)this + 16);
    *(unsigned int*)((char*)this + 20) = bs + bs;
}

// 0x80359FA4
void EAllocGroup::MoveContents(EAllocGroup& other) {
    DeallocateAll();
    *(unsigned int*)((char*)this + 20) = *(unsigned int*)((char*)&other + 20);
    unsigned int bs = *(unsigned int*)((char*)&other + 16);
    *(unsigned int*)((char*)this + 16) = bs;
    *(unsigned int*)((char*)&other + 20) = bs + bs;
    // ENodeList::MoveContents(other)
}


// ============================================================
// EBoundSphere — Bounding sphere
// ============================================================

class EBoundSphere2 { // renamed to avoid conflict with include
public:
    float m_center[3]; // 0x00..0x08
    float m_radius;    // 0x0C

    void Combine(EBoundSphere2& a, EBoundSphere2& b);
    void ComputeFast(EVec3* verts, int count);
};

// 0x8035A034
void EBoundSphere2::Combine(EBoundSphere2& a, EBoundSphere2& b) {
    // Compute delta vector b.center - a.center
    float dx = b.m_center[0] - a.m_center[0];
    float dy = b.m_center[1] - a.m_center[1];
    float dz = b.m_center[2] - a.m_center[2];
    float delta[3] = { dx, dy, dz };

    // Get magnitude via PSVECMag
    // float mag = PSVECMag(delta);
    float mag = 0.0f; // placeholder — calls PSVECMag

    if (mag == 0.0f) {
        // Coincident centers — use a's center, max radius
        m_center[0] = a.m_center[0];
        m_center[1] = a.m_center[1];
        m_center[2] = a.m_center[2];
        float ra = a.m_radius;
        float rb = b.m_radius;
        m_radius = (ra > rb) ? ra : rb;
    } else {
        // Normalize delta, compute combined sphere
        float invMag = 1.0f / mag;
        float nx = dx * invMag;
        float ny = dy * invMag;
        float nz = dz * invMag;

        // Compute endpoints along axis
        float ex0 = a.m_center[0] - a.m_radius * nx;
        float ey0 = a.m_center[1] - a.m_radius * ny;
        float ez0 = a.m_center[2] - a.m_radius * nz;

        float ex1 = b.m_center[0] + b.m_radius * nx;
        float ey1 = b.m_center[1] + b.m_radius * ny;
        float ez1 = b.m_center[2] + b.m_radius * nz;

        // Center is midpoint
        m_center[0] = (ex0 + ex1) * 0.5f;
        m_center[1] = (ey0 + ey1) * 0.5f;
        m_center[2] = (ez0 + ez1) * 0.5f;

        // Radius is distance from center to endpoint
        // if smaller than a or b, use that sphere instead
        float distx = ex1 - m_center[0];
        float disty = ey1 - m_center[1];
        float distz = ez1 - m_center[2];
        float dist[3] = { distx, disty, distz };
        // m_radius = PSVECMag(dist);

        if (m_radius < a.m_radius) {
            m_center[0] = a.m_center[0];
            m_center[1] = a.m_center[1];
            m_center[2] = a.m_center[2];
            m_radius = a.m_radius;
        } else if (m_radius < b.m_radius) {
            m_center[0] = b.m_center[0];
            m_center[1] = b.m_center[1];
            m_center[2] = b.m_center[2];
            m_radius = b.m_radius;
        }
    }
}

// 0x8035A258
void EBoundSphere2::ComputeFast(EVec3* verts, int count) {
    EBound3 bounds;
    // Initialize bounds to large/empty
    // EBound3::Compute(verts, count)
    // EBound3::CalcBoundSphere(*this)
}


// ============================================================
// EBoundTreeNode — Bound tree serialization
// ============================================================

class EBoundTreeNode2 {
public:
    void* m_vtable;     // 0x00
    // EBound3 at offset 4..27
    EBoundTreeNode2* m_child; // 0x1C (offset 28)
    EStorable* m_obj0;  // 0x20 (offset 32)
    EStorable* m_obj1;  // 0x24 (offset 36)

    void Write(EStream& stream);
    void Read(EStream& stream);
    void Deallocate(void);
    static void RegisterType(unsigned short id);
};

// 0x802C5AE8
void EBoundTreeNode2::Write(EStream& stream) {
    // operator<<(stream, EBound3 at this+4)
    // operator<<(stream, m_child)
    // operator<<(stream, m_obj0)
    // operator<<(stream, m_obj1)
}

// 0x802C5B34
void EBoundTreeNode2::Read(EStream& stream) {
    // Check version flag
    // if (version == 0) {
    //     operator>>(stream, EBound3 at this+4)
    //     operator>>(stream, m_child)
    //     operator>>(stream, m_obj0)
    //     operator>>(stream, m_obj1)
    // }
}

// 0x802C5B90
void EBoundTreeNode2::Deallocate(void) {
    // Recursively deallocate children at offsets 32, 36
    for (int i = 1; i >= 0; i--) {
        EStorable* obj = (i == 1) ? m_obj1 : m_obj0;
        if (obj) {
            // if (obj->IsExactType(EBoundTreeNode_TypeInfo))
            //     ((EBoundTreeNode*)obj)->Deallocate();
            // else
            //     obj->vfn_Destroy();
        }
        if (i == 1) m_obj1 = NULL;
        else m_obj0 = NULL;
    }
    // Destroy self via vtable
}

// 0x802C5D7C
void EBoundTreeNode2::RegisterType(unsigned short id) {
    // ETypeInfo::Register(New, ReadNew, Write, id, "EBoundTreeNode", parent)
}


// ============================================================
// ECheatDMI — Debug menu item for cheats
// ============================================================

class ECheatLookup;

class ECheatDMI2 : public EDebugMenuItem {
public:
    ECheatLookup* m_lookup; // 0x0C (offset 12)

    ECheatDMI2(ECheatLookup* lookup);
    void GetDescription(char* buf, int maxLen);
    void GetValue(char* buf);
    void ButtonPress(int button);
    void ButtonPress(int button, float analog);
};

// 0x800218EC
ECheatDMI2::ECheatDMI2(ECheatLookup* lookup) {
    // EDebugMenuItem::EDebugMenuItem()
    m_lookup = lookup;
    // Set vtable
}

// 0x80021498
void ECheatDMI2::GetDescription(char* buf, int maxLen) {
    strncpy(buf, (char*)m_lookup + 8, maxLen);
    buf[maxLen - 1] = '\0';
}

// 0x800214E0
void ECheatDMI2::GetValue(char* buf) {
    int type = *(int*)((char*)m_lookup + 76);
    void* data = *(void**)((char*)m_lookup + 80);
    switch (type) {
        case 2: { // bool
            int val = *(int*)data;
            if (val) strcpy(buf, "true");
            else     strcpy(buf, "false");
            break;
        }
        case 3: { // u8
            Sprintf(buf, "%d", *(unsigned char*)data);
            break;
        }
        case 4: { // s8
            Sprintf(buf, "%d", (signed char)*(unsigned char*)data);
            break;
        }
        case 5: { // s16
            Sprintf(buf, "%d", *(short*)data);
            break;
        }
        case 7: { // float
            Sprintf(buf, "%f", *(float*)data);
            break;
        }
        default:
            buf[0] = '\0';
            break;
    }
}

// 0x80021600
void ECheatDMI2::ButtonPress(int button) {
    int type = *(int*)((char*)m_lookup + 76);
    void* data = *(void**)((char*)m_lookup + 80);
    switch (type) {
        case 2: // bool — toggle
            if (button <= 1) {
                *(int*)data ^= 1;
            }
            break;
        case 3: { // u8 — inc/dec with wrap
            unsigned char val = *(unsigned char*)data;
            if (button == 0) {
                val = (val == 0) ? 255 : val - 1;
            } else if (button == 1) {
                val = (val >= 255) ? 0 : val + 1;
            }
            *(unsigned char*)data = val;
            break;
        }
        case 4: { // s8 — inc/dec with wrap
            signed char val = (signed char)*(unsigned char*)data;
            if (button == 0) {
                val = (val == -128) ? 127 : val - 1;
            } else if (button == 1) {
                val = (val >= 127) ? -128 : val + 1;
            }
            *(unsigned char*)data = (unsigned char)val;
            break;
        }
        case 5: { // s16 — inc/dec with wrap
            short val = *(short*)data;
            if (button == 0) {
                val = (val <= -32768) ? 32767 : val - 1;
            } else if (button == 1) {
                val = (val >= 32767) ? -32768 : val + 1;
            }
            *(short*)data = val;
            break;
        }
        case 7: { // float — add/sub step
            float step = 0.1f; // from rodata
            if (button == 0) {
                *(float*)data -= step;
            } else if (button == 1) {
                *(float*)data += step;
            }
            break;
        }
    }
}


// ============================================================
// ECheatLookup — Cheat variable lookup
// ============================================================

class ECheatLookup2 {
public:
    int   m_id;           // 0x04
    char  m_name[64];     // 0x08
    int   m_type;         // 0x4C (76)
    void* m_data;         // 0x50 (80)
    int   m_hasRange;     // 0x54 (84)
    int   m_visible;      // 0x58 (88)
    char* m_description;  // 0x48 (72)
    int   m_field_0x5C;   // 0x5C (92)

    ECheatLookup2(int id, char* name, int cheatType, void* data, char* desc, bool vis, bool hasRange);
    void WriteCheat(EFile* file, int& status);
};

// 0x80021124
ECheatLookup2::ECheatLookup2(int id, char* name, int cheatType, void* data, char* desc, bool vis, bool hasRange) {
    m_id = id;
    strncpy(m_name, name, 64);
    m_name[63] = '\0';
    m_type = cheatType;
    m_data = data;

    // Check if description fits
    unsigned int descLen = strlen(desc) + 1;
    if (descLen > 350) {
        m_description = NULL; // "Too long"
    } else {
        m_description = desc;
    }
    m_hasRange = hasRange;
    m_visible = vis;
    m_field_0x5C = 0;
}


// ============================================================
// EControllerData — Controller state data
// ============================================================

class EControllerData2 {
public:
    int   m_field_0x00[10]; // basic fields up to offset 36
    float m_sticks[32];     // stick data (offsets 40..167)
    int   m_events[8];      // event flags (offsets 104..119)
    int   m_field_0x78;     // offset 120

    void Clear(bool resetTimestamps);
    void Reset(bool full);
    void operator=(EControllerData2& other);
    void SetGotEvent(unsigned int idx, bool val);
    void SetPressedFirst(unsigned int idx, bool val);
    bool GetGotEvent(unsigned int idx) const;
    bool GetPressedFirst(unsigned int idx) const;
};

// 0x80365A7C
void EControllerData2::Clear(bool resetTimestamps) {
    m_field_0x78 = 0;
    // Zero out various fields
    // Loop: zero stick floats, event ints
    int resetVal = resetTimestamps ? 0 : -1;
    // Set timestamp fields
    // Loop through 32 buttons, SetGotEvent + SetPressedFirst to false
    for (int i = 0; i <= 31; i++) {
        SetGotEvent(i, false);
        SetPressedFirst(i, false);
    }
}

// 0x80365B60
void EControllerData2::Reset(bool full) {
    // Copy current stick data to previous
    // Zero current stick data
    // Reset events
    for (int i = 0; i <= 31; i++) {
        SetGotEvent(i, false);
        SetPressedFirst(i, false);
    }
}

// 0x80365C60
void EControllerData2::operator=(EControllerData2& other) {
    // Copy basic fields
    // Copy stick data in loop
    // Copy events via GetGotEvent/SetGotEvent, GetPressedFirst/SetPressedFirst
    for (int i = 0; i <= 31; i++) {
        bool got = other.GetGotEvent(i);
        SetGotEvent(i, got);
        bool pressed = other.GetPressedFirst(i);
        SetPressedFirst(i, pressed);
    }
}


// ============================================================
// EDL — Display List
// ============================================================

class EDL2 {
public:
    // EAllocGroup at offset 0
    // EAllocGroup at offset 24
    // ENodeList at offset 48
    // ENodeList at offset 60
    int   m_field_0x48;  // 72
    int   m_field_0x4C;  // 76
    int   m_field_0x50;  // 80
    int   m_field_0x54;  // 84
    int   m_numVerts;    // 88
    int   m_numStrips;   // 92
    void* m_vtable_0x64; // 100

    EDL2(int blockSize);
    ~EDL2(void);
    void Validate(void);
    static void* operator new(unsigned int size);
    static void operator delete(void* ptr);
    float GetAverageStripLength(void);
};

// 0x80363014
EDL2::EDL2(int blockSize) {
    // Set vtable
    // EAllocGroup::EAllocGroup(blockSize) at offset 0
    // EAllocGroup::EAllocGroup(blockSize) at offset 24
    // Initialize ENodeLists at 48 and 60
    m_field_0x48 = 0;
    m_field_0x4C = 0;
    m_field_0x50 = 0;
    m_field_0x54 = 0;
    m_numStrips = 0;
    m_numVerts = 0;
}

// 0x803630A0
EDL2::~EDL2(void) {
    // Set vtable
    // ENodeList::RemoveAll() at offset 60
    // ENodeList::RemoveAll() at offset 48
    // EAllocGroup::DeallocateAll() + ENodeList::RemoveAll() at offset 24
    // EAllocGroup::DeallocateAll() + ENodeList::RemoveAll() at offset 0
    // if (destructor flag & 1) operator delete(this)
}

// 0x8036311C
void EDL2::Validate(void) {
    // Validate both alloc groups
    // Walk node list at offset 48, call Validate on each sub-model
    // Walk node list at offset 60, recursively call EDL::Validate on children
}

// 0x80363410
float EDL2::GetAverageStripLength(void) {
    return (float)m_numVerts / (float)m_numStrips;
}


// ============================================================
// EDataHeader — Data file header
// ============================================================

class EDataHeader2 {
public:
    char* m_name;         // 0x00
    unsigned int m_sig0;  // 0x04
    unsigned int m_sig1;  // 0x08
    int   m_version;      // 0x0C
    int   m_extraSize;    // 0x10

    void Clear(void);
    void Write(EStream& stream);
    void Read(EFile& file, unsigned int minVer, unsigned int maxVer, unsigned int expectedSig);
    void SetName(char* name);
    int IsSignatureValid(void);
};

// 0x8035AEE8
void EDataHeader2::Clear(void) {
    m_version = -1;
    m_sig0 = 0;
    m_sig1 = 0;
    m_extraSize = 0;
    if (m_name) {
        // __builtin_vec_delete(m_name)
    }
    m_name = NULL;
}

// 0x8035B2C8
void EDataHeader2::SetName(char* name) {
    EAHeap* heap = MainHeap();
    unsigned int len = strlen(name);
    char* buf = (char*)heap->Malloc(len + 1, 0);
    m_name = buf;
    strcpy(buf, name);
}

// 0x8035B360
int EDataHeader2::IsSignatureValid(void) {
    // Check m_sig1 against known 4CC values:
    // "FXSH", "DISH", "BNST", "EXPT", "LDST", "MDSH", "OPEL",
    // "STMM", "SHFL", "TXSH", "ARST", "SHAH"
    // Returns 1 if match, 0 otherwise
    unsigned int sig = m_sig1;
    if (sig == 0x46585348 || sig == 0x44495348 ||  // FXSH, DISH
        sig == 0x424E5354 || sig == 0x45585054 ||  // BNST, EXPT
        sig == 0x4C445354 || sig == 0x4D445348 ||  // LDST, MDSH
        sig == 0x4F50454C || sig == 0x53544D4D ||  // OPEL, STMM
        sig == 0x5348464C || sig == 0x54585348 ||  // SHFL, TXSH
        sig == 0x41525354 || sig == 0x53484148) {  // ARST, SHAH
        return 1;
    }
    return 0;
}


// ============================================================
// EDatasetManager — Dataset resource manager
// ============================================================

class EDatasetManager2 {
public:
    // Inherits from EResourceManager
    void* m_vtable_0xD1C; // 3356

    EDatasetManager2(void);
    void AddRef(char* name, EFile* file, int flags);
    void AddRefAsync(char* name);
    void AddRefAsyncIfNotLoaded(char* name);
    void AllocateAndLoadResource(EFile* file, unsigned int offset, unsigned int size);
    void PreloadResource(char* name);
    void ManageDasFile(char* name);
    void* GetRef(char* name);
};

// 0x80324904
EDatasetManager2::EDatasetManager2(void) {
    // EResourceManager::EResourceManager()
    // Set vtable at offset 3356
    // Initialize float at offset 3360
}

// 0x8032459C
void EDatasetManager2::AddRef(char* name, EFile* file, int flags) {
    ManageDasFile(name);
    // if (global flag set) EResourceManager::AddRef(name, file, 0, 0)
    // else return 1
}

// 0x80324620
void EDatasetManager2::AddRefAsync(char* name) {
    ManageDasFile(name);
    // if (global flag set) EResourceManager::AddRefAsync(name)
    // else return 1
}


// ============================================================
// EFenceWall — Fence wall instance
// ============================================================

class EFenceWall2 {
public:
    void* m_vtable;  // 0x3C (offset 60)

    EFenceWall2(void* segment, void* tilePt, int wallStyle);
    ~EFenceWall2(void);
};

// 0x8002C48C
EFenceWall2::EFenceWall2(void* segment, void* tilePt, int wallStyle) {
    // Set vtable
    // CTilePt::CTilePt() at various offsets
    // Initialize members
    // Allocate EIFenceWall via heap (952 bytes, 16-byte aligned)
    // EIFenceWall::EIFenceWall(segment, tilePt, wallStyle)
    // ENodeList::AddTail
}

// 0x8039E42C
EFenceWall2::~EFenceWall2(void) {
    // ERoomWall::~ERoomWall()
    // if (flag & 1) ERoomWall::operator delete(this)
}


// ============================================================
// EFile — File I/O base
// ============================================================

class EFile2 {
public:
    char  m_drive[4];    // 0x18 (offset 24)
    char  m_path[4];     // 0x1C (offset 28 — pointer to path)
    char* m_pathPtr;     // 0x1C (offset 28)
    char* m_namePtr;     // 0x20 (offset 32)
    char  m_ext[4];      // 0x24 (offset 36)
    void* m_vtable;      // 0x28 (offset 40)

    ~EFile2(void);
    void SetName(char* name);
    void Fprintf(char* fmt, ...);
    void* ReadStructure(unsigned int count);
};

// 0x802C608C
EFile2::~EFile2(void) {
    // Set vtable
    EAHeap* heap = MainHeap();
    // Free path buffer
    // Free name buffer
    // Zero pointers
    // if (flag & 1) heap->Free(this)
}


// ============================================================
// EFloorTileGroup — Floor rendering group
// ============================================================

class EFloorTileGroup2 {
public:
    void* m_next;       // 0x00
    void* m_edl;        // 0x04
    int   m_stripCount; // 0x08
    void* m_strips;     // 0x0C
    void* m_shader;     // 0x10 — ERShader*

    EFloorTileGroup2(void* shader, void* edl, void* strips, int count, EFloorTileGroup2* next);
    ~EFloorTileGroup2(void);
};

// 0x8004809C
EFloorTileGroup2::EFloorTileGroup2(void* shader, void* edl, void* strips, int count, EFloorTileGroup2* next) {
    m_edl = edl;
    m_strips = strips;
    m_stripCount = count;
    m_next = next;
    m_shader = shader;
    // EResource::AddRef() on shader
}

// 0x800480E4
EFloorTileGroup2::~EFloorTileGroup2(void) {
    // Loop through strips, release EDLs
    // Release shader via EResource::DelRef()
    // if (flag & 1) delete this
}


// ============================================================
// EFrameAllocGroup — Frame-scoped allocator
// ============================================================

class EFrameAllocGroup2 {
public:
    void* m_vtable;     // 0x00
    // EAllocGroup[2] at offset 4 (each 24 bytes = offsets 4 and 28)
    int   m_current;    // 0x34 (offset 52)

    EFrameAllocGroup2(void);
    ~EFrameAllocGroup2(void);
};

// 0x803067C4
EFrameAllocGroup2::EFrameAllocGroup2(void) {
    // EGlobalManager::Register(this, 2)
    // Set vtable
    // Initialize 2 EAllocGroups with blockSize=4096
    m_current = 0;
}

// 0x80306608
EFrameAllocGroup2::~EFrameAllocGroup2(void) {
    // Set vtable
    // if (shutdown flag == 0) EGlobalManager::Shutdown()
    // Deallocate both alloc groups in reverse
    // EGlobalManagerClient::Shutdown()
    // if (flag & 1) delete this
}


// ============================================================
// EGameStateMan — Game state manager
// ============================================================

class EGameStateMan2 {
public:
    void* m_currentNode; // 0x00 — pointer to current state node
    // ENodeList at offset 4

    ~EGameStateMan2(void);
    void SetState(int stateId);
    void SoftReset(void);
    void DeleteAllStates(void);
    void Update(void);
};

// 0x80089A3C
EGameStateMan2::~EGameStateMan2(void) {
    // ENodeList::RemoveAll() at offset 4
    // if (flag & 1) delete this
}

// 0x80089A80
void EGameStateMan2::SetState(int stateId) {
    void* node = *(void**)((char*)this + 4);
    while (node) {
        void* state = *(void**)node;
        int id = *(int*)state;
        if (id == stateId) {
            // Deactivate current state via vtable
            m_currentNode = node;
            // Store stateId in global
            // Activate new state via vtable
            return;
        }
        node = *(void**)((char*)node + 8); // next
    }
}

// 0x80089BA0
void EGameStateMan2::SoftReset(void) {
    // Deactivate current state
    m_currentNode = NULL;
    // EGlobal::Reset()
    // EGlobal::SetDefaults()
}

// 0x80089CE0
void EGameStateMan2::Update(void) {
    // if (ECheats instance exists) ECheats::Update()
    // Call current state's Update via vtable
}


// ============================================================
// EGlobalManager — Global subsystem lifecycle manager
// ============================================================

class EGlobalManager2 {
public:
    static void Startup(void);
    static void Shutdown(void);
};

// 0x802C86FC
void EGlobalManager2::Startup(void) {
    // if (already started) return
    // Set started flag
    // Sort client array by priority (bubble sort)
    // Call Startup on each client in order
    // Track current index for shutdown
}

// 0x802C8838
void EGlobalManager2::Shutdown(void) {
    // if (already shutting down) return
    // Set shutdown flag, clear started flag
    // Call Shutdown on each client in reverse order
}


// ============================================================
// EGrowPool — Growing pool allocator
// ============================================================

class EGrowPool2 {
public:
    void* m_freeList;   // 0x00
    void* m_segList;    // 0x04
    int   m_elemSize;   // 0x08

    EGrowPool2(int elemSize);
    void* AllocNewSeg(void);
    void Reset(void);
    void FreeUnusedSegments(void);
};

// 0x8035C0B8
EGrowPool2::EGrowPool2(int elemSize) {
    // Init()
    if (elemSize < 4) elemSize = 4;
    m_elemSize = elemSize;
}

// 0x8035C150
void* EGrowPool2::AllocNewSeg(void) {
    if (m_elemSize > 2044) {
        // Large elements — allocate individual block
        return MainHeap()->MallocAligned(m_elemSize, 16, 0);
    }
    // Small elements — allocate 4096-byte page
    void* page = MainHeap()->MallocAligned(4096, 32, 0);
    if (!page) return NULL;
    // Link page into segment list
    *(void**)page = m_segList;
    m_segList = page;
    // Build free list from page elements
    int elemsPerPage = 4088 / m_elemSize;
    for (int i = 1; i < elemsPerPage; i++) {
        void* elem = (char*)page + 4096 - (i * m_elemSize);
        *(void**)elem = m_freeList;
        m_freeList = elem;
    }
    // Return first element
    return (char*)page + 4096 - m_elemSize;
}

// 0x8035C228
void EGrowPool2::Reset(void) {
    if (m_elemSize > 2044) {
        FreeUnusedSegments();
        return;
    }
    // Free all segments
    void* seg = m_segList;
    m_freeList = NULL;
    while (seg) {
        void* next = *(void**)seg;
        MainHeap()->Free(seg);
        seg = next;
    }
    m_segList = NULL;
}


// ============================================================
// EILight — Light instance base class
// ============================================================

class EILight2 {
public:
    // Inherits EInstance
    int   m_enabled;      // 0x7C (offset 124)
    int   m_castShadows;  // 0x80 (offset 128)
    void* m_target;       // 0x84 (offset 132)
    int   m_visible;      // 0x88 (offset 136)
    float m_intensity;    // 0x8C (offset 140)
    float m_color[3];     // 0x90 (offset 144)
    float m_tint[4];      // 0x9C..0xAB (offsets 156..168)
    int   m_useTint;      // 0xA8 (offset 168)

    EILight2(void);
    void Write(EStream& stream);
    void Read(EStream& stream);
    void GetScaledIntColor(float scale, unsigned int* rgb);
    void GetScaledIntensity(void);
    int TestOverlap(EInstance* inst);
    static void RegisterType(unsigned short id);
};

// 0x80227984
EILight2::EILight2(void) {
    // EInstance::EInstance()
    // Set vtable
    // Initialize color to white {1,1,1}
    m_visible = 1;
    m_enabled = 1;
    m_castShadows = 0;
    m_intensity = 1.0f;
    // Copy color vec
    m_target = NULL;
    // Set bounds flag
    m_useTint = 1;
}

// 0x80227C90
void EILight2::GetScaledIntColor(float scale, unsigned int* rgb) {
    float s = scale * 255.0f * m_intensity;
    float r = m_color[0] * s;
    float g = m_color[1] * s;
    float b = m_color[2] * s;
    rgb[0] = (r > 255.0f) ? 255 : (unsigned int)r;
    rgb[1] = (g > 255.0f) ? 255 : (unsigned int)g;
    rgb[2] = (b > 255.0f) ? 255 : (unsigned int)b;
}

// 0x80227DE0
int EILight2::TestOverlap(EInstance* inst) {
    // AABB overlap test between this->bounds and inst->bounds
    // Compare min/max of each axis
    // Returns 1 if overlapping, 0 otherwise
    return 0; // placeholder
}


// ============================================================
// EIAmbLight — Ambient light
// ============================================================

class EIAmbLight2 {
public:
    float m_intensity;  // offset 140
    float m_color[3];   // offset 144

    void CalcLightOnPoint(EVec3& point, EVec3& outColor);
    void LightingParameters(EVec3& dir, float& intensity, EVec3& diffuse, EVec3& ambient);
    void Setup(void);
    static void* New(void);
    static void RegisterType(unsigned short id);
};

// 0x80226B98
void EIAmbLight2::CalcLightOnPoint(EVec3& point, EVec3& outColor) {
    // Zero output color
    // Check if light is active via vtable
    // If active: outColor = m_color * m_intensity
}

// 0x80226E3C
void* EIAmbLight2::New(void) {
    void* mem = operator new(172);
    // EILight::EILight()
    // Set vtable
    return mem;
}


// ============================================================
// EIDirLight — Directional light
// ============================================================

class EIDirLight2 {
public:
    float m_direction[3]; // offset 172

    EIDirLight2(void);
    void Read(EStream& stream);
    void LightingParameters(EVec3& dir, float& intensity, EVec3& diffuse, EVec3& ambient);
    void Setup(void);
    static void RegisterType(unsigned short id);
};

// 0x802270AC
EIDirLight2::EIDirLight2(void) {
    // EILight::EILight()
    // Set vtable
    m_direction[0] = 0.0f;
    m_direction[1] = 0.0f;
    m_direction[2] = -1.0f;
}

// 0x80227144
void EIDirLight2::Read(EStream& stream) {
    // EILight::Read(stream)
    // if (version == 0) operator>>(stream, direction)
}


// ============================================================
// EISpotLight — Spotlight
// ============================================================

class EISpotLight2 {
public:
    float m_position[3];   // offset 172
    float m_direction[3];  // offset 184
    float m_innerAngle;    // offset 196
    float m_outerAngle;    // offset 200
    float m_cosInner;      // offset 204
    float m_cosOuter;      // offset 208
    int   m_volumetric;    // offset 212
    float m_cosInnerCache; // offset 216
    float m_cosOuterCache; // offset 220

    EISpotLight2(void);
    void Write(EStream& stream);
    void Read(EStream& stream);
    void Setup(void);
    static void RegisterType(unsigned short id);
};

// 0x8022B1E0
EISpotLight2::EISpotLight2(void) {
    // EILight::EILight()
    // Set vtable
    // Initialize position, direction, angles
    m_volumetric = 1;
    // Setup()
}


// ============================================================
// EMemoryMeterWin — Memory usage meter
// ============================================================

class EMemoryMeterWin2 {
public:
    int   m_field_0x00;
    void* m_vtable;      // 0x04
    float m_memLevel;    // 0x08
    float m_field_0x0C;  // 0x0C (offset 12, unused display value)
    float m_objMem;      // 0x10
    int   m_objCount;    // 0x14
    float m_texMem;      // 0x18
    int   m_texCount;    // 0x1C
    float m_totalPct;    // 0x20
    float m_objPct;      // 0x24 (offset 24)
    int   m_objMemInt;   // 0x14 (offset 20)

    EMemoryMeterWin2(void);
    ~EMemoryMeterWin2(void);
    int GetAffordable(ObjSelector* sel);
    void PollMemoryLevels(void);
    void Init(void);
    void Reset(void);
};

// 0x800578D8
EMemoryMeterWin2::EMemoryMeterWin2(void) {
    // Set vtable
    m_totalPct = 0.0f;  // from rodata
    m_field_0x00 = 0;
    m_memLevel = 0.0f;
    m_objMem = 0.0f;
    m_objCount = 0;
    m_texMem = 0.0f;
    m_texCount = 0;
    Init();
}

// 0x800579C0
int EMemoryMeterWin2::GetAffordable(ObjSelector* sel) {
    if (sel == NULL) return 0;
    PollMemoryLevels();
    if (m_memLevel >= 0.0f) return 0; // threshold check
    return 1;
}


// ============================================================
// EMemoryWriteStream — In-memory write stream
// ============================================================

class EMemoryWriteStream2 {
public:
    int   m_field_0x00;  // 0x00
    void* m_vtable;      // 0x18 (offset 24)
    int   m_size;        // 0x1C (offset 28)
    // TArray<unsigned char*> at offset 32

    EMemoryWriteStream2(void);
    ~EMemoryWriteStream2(void);
    int Write(void* data, int size);
    void* AllocAndCopyToBuffer(void) const;
    void WriteToStream(EStream& stream, int offset, int size);
    unsigned char operator_bracket(int index) const;
};

// 0x802E0AA8
EMemoryWriteStream2::EMemoryWriteStream2(void) {
    m_field_0x00 = 0;
    // Set vtable
    // TArray::TArray() at offset 32
    m_size = 0;
}

// 0x802E0AF4
EMemoryWriteStream2::~EMemoryWriteStream2(void) {
    // Set vtable
    // TArray::FreeAll()
    // TArray::~TArray()
    // if (flag & 1) delete this
}

// 0x802E0D50
void* EMemoryWriteStream2::AllocAndCopyToBuffer(void) const {
    void* buf = MainHeap()->Malloc(m_size, 0);
    if (buf) {
        for (unsigned int i = 0; i < (unsigned int)m_size; i++) {
            ((unsigned char*)buf)[i] = operator_bracket(i);
        }
    }
    return buf;
}


// ============================================================
// EMsgQueue — Thread-safe message queue
// ============================================================

class EMsgQueue2 {
public:
    // ESemaphore at offset 0 (send semaphore)
    // ESemaphore at offset 24 (receive semaphore)
    int   m_sendIdx;     // 0x30 (offset 48)
    int   m_recvIdx;     // 0x34 (offset 52)
    int   m_capacity;    // 0x38 (offset 56)
    unsigned int* m_buffer; // 0x3C (offset 60)
    int   m_allocated;   // 0x40 (offset 64)
    int   m_totalSent;   // 0x44 (offset 68)
    int   m_maxCount;    // 0x48 (offset 72)

    EMsgQueue2(void);
    EMsgQueue2(int capacity);
    ~EMsgQueue2(void);
    int Create(int capacity);
    void Destroy(void);
    int Send(unsigned int msg, bool blocking);
    int Receive(unsigned int* msg, bool blocking);
    int iSend(unsigned int msg);
    int iReceive(unsigned int* msg);
    void GetStats(int& count, int& maxCount, int& totalSent, int& capacity);
    int GetCount(void);
};

// 0x8035C4A4
EMsgQueue2::EMsgQueue2(void) {
    // ESemaphore::ESemaphore() at offset 0
    // ESemaphore::ESemaphore() at offset 24
    m_maxCount = 0;
    m_capacity = 0;
    m_allocated = 0;
    m_totalSent = 0;
}

// 0x8035C4F0
EMsgQueue2::EMsgQueue2(int capacity) {
    // ESemaphore::ESemaphore() at offset 0
    // ESemaphore::ESemaphore() at offset 24
    m_capacity = 0;
    Create(capacity);
    m_maxCount = 0;
    m_totalSent = 0;
}

// 0x8035C548
EMsgQueue2::~EMsgQueue2(void) {
    if (m_capacity) Destroy();
    // ESemaphore::~ESemaphore() at offset 24
    // ESemaphore::~ESemaphore() at offset 0
    // if (flag & 1) delete this
}

// 0x8035C5AC
int EMsgQueue2::Create(int capacity) {
    EAHeap* heap = MainHeap();
    m_buffer = (unsigned int*)heap->Malloc((capacity + 1) * 4, 0);
    m_allocated = 1;
    // Create send semaphore (capacity, capacity)
    // Create receive semaphore (capacity, 0)
    if (m_buffer && /* send ok && recv ok */) {
        m_capacity = capacity + 1;
        m_sendIdx = 0;
        m_recvIdx = 0;
        return 1;
    }
    // Cleanup on failure
    return 0;
}

// 0x8035C698
void EMsgQueue2::Destroy(void) {
    m_capacity = 0;
    // ESemaphore::Destroy() on both
    if (m_allocated) {
        MainHeap()->Free(m_buffer);
        m_allocated = 0;
    }
}

// 0x8035C6F0
int EMsgQueue2::Send(unsigned int msg, bool blocking) {
    unsigned int timeout = blocking ? (unsigned int)-1 : 0;
    // ESemaphore::Acquire(timeout) on send semaphore
    // if failed return 0
    int oldIrq = OSDisableInterrupts();
    m_buffer[m_sendIdx] = msg;
    m_sendIdx = (m_sendIdx + 1) % m_capacity;
    m_totalSent++;
    OSEnableInterrupts();
    // ESemaphore::Release() on receive semaphore
    int cnt = GetCount();
    if ((unsigned int)cnt > (unsigned int)m_maxCount)
        m_maxCount = cnt;
    return 1;
}

// 0x8035C7B0
int EMsgQueue2::Receive(unsigned int* msg, bool blocking) {
    unsigned int timeout = blocking ? (unsigned int)-1 : 0;
    // ESemaphore::Acquire(timeout) on receive semaphore
    // if failed return 0
    int oldIrq = OSDisableInterrupts();
    if (msg) {
        *msg = m_buffer[m_recvIdx];
    }
    m_recvIdx = (m_recvIdx + 1) % m_capacity;
    OSEnableInterrupts();
    // ESemaphore::Release() on send semaphore
    return 1;
}

// 0x8035C850
int EMsgQueue2::iSend(unsigned int msg) {
    // ESemaphore::iAcquire() on send semaphore (interrupt-safe)
    // if failed return 0
    m_buffer[m_sendIdx] = msg;
    m_sendIdx = (m_sendIdx + 1) % m_capacity;
    // ESemaphore::iRelease() on receive semaphore
    return 1;
}

// 0x8035C8C8
int EMsgQueue2::iReceive(unsigned int* msg) {
    // ESemaphore::iAcquire() on receive semaphore (interrupt-safe)
    // if failed return 0
    if (msg) {
        *msg = m_buffer[m_recvIdx];
    }
    m_recvIdx = (m_recvIdx + 1) % m_capacity;
    // ESemaphore::iRelease() on send semaphore
    return 1;
}

// 0x8035C974
void EMsgQueue2::GetStats(int& count, int& maxCount, int& totalSent, int& capacity) {
    count = GetCount();
    maxCount = m_maxCount;
    totalSent = m_totalSent;
    capacity = m_capacity;
}


// ============================================================
// EMutex — Mutex (semaphore-based)
// ============================================================

class EMutex2 {
public:
    void* m_vtable;  // 0x00
    // ESemaphore at offset 4

    EMutex2(void);
    ~EMutex2(void);
    void operator++(void);
    void operator++(int);
    void operator--(void);
    void operator--(int);
};

// 0x802CB914
EMutex2::EMutex2(void) {
    // ESyncObject::ESyncObject()
    // Set vtable
    // ESemaphore::ESemaphore() at offset 4
    // ESemaphore::Create(1, -1) — binary mutex
}

// 0x802CB96C
EMutex2::~EMutex2(void) {
    // Set vtable
    // ESemaphore::~ESemaphore() at offset 4
    // ESyncObject::~ESyncObject()
}

// 0x802CBC1C
void EMutex2::operator++(void) {
    // Acquire via vtable (timeout = -1)
}

// 0x802CBC64
void EMutex2::operator++(int) {
    // Same as prefix ++
}

// 0x802CBCAC
void EMutex2::operator--(int) {
    // Release via vtable
}

// 0x802CBCF0
void EMutex2::operator--(void) {
    // Release via vtable
}


// ============================================================
// ESingleLock — RAII lock guard
// ============================================================

class ESingleLock2 {
public:
    ESyncObject* m_syncObj;  // 0x00
    int   m_locked;          // 0x04
    int   m_autoUnlock;      // 0x08

    ESingleLock2(ESyncObject* obj, bool lockNow, bool autoUnlock);
    ~ESingleLock2(void);
    int Lock(unsigned int timeout);
    int Unlock(void);
    int Unlock(unsigned int timeout, unsigned int* result);
};

// 0x802E1574
ESingleLock2::ESingleLock2(ESyncObject* obj, bool lockNow, bool autoUnlock) {
    m_syncObj = obj;
    m_locked = 0;
    m_autoUnlock = autoUnlock;
    if (lockNow) {
        Lock((unsigned int)-1);
    }
}

// 0x802E15C0
ESingleLock2::~ESingleLock2(void) {
    if (m_autoUnlock) {
        Unlock();
    }
    // if (flag & 1) delete this
}

// 0x802E160C
int ESingleLock2::Lock(unsigned int timeout) {
    // Call m_syncObj->Acquire(timeout) via vtable
    // m_locked = result
    return m_locked;
}

// 0x802E1654
int ESingleLock2::Unlock(void) {
    if (m_locked) {
        // Call m_syncObj->Release() via vtable
        m_locked = 0;
    }
    return !m_locked;
}


// ============================================================
// ESleep — Timer-based sleep
// ============================================================

class ESleep2 {
public:
    // ESemaphore at offset 0
    // OSAlarm at offset 24

    ESleep2(void);
    ~ESleep2(void);
    void Sleep(unsigned int milliseconds);
};

// 0x802D7B44
ESleep2::ESleep2(void) {
    // ESemaphore::ESemaphore()
    // ESemaphore::Create(1, 0)
    // OSCreateAlarm(alarm)
    // OSSetAlarmTag(alarm, this)
}

// 0x802D7B9C
ESleep2::~ESleep2(void) {
    // ESemaphore::~ESemaphore()
    // if (flag & 1) delete this
}

// 0x802D7BE0
void ESleep2::Sleep(unsigned int milliseconds) {
    // Convert ms to ticks using bus clock
    // OSSetAlarm(alarm, 0, ticks, callback)
    // ESemaphore::Acquire(-1) — block until alarm fires
}


// ============================================================
// EStorable — Base serializable object
// ============================================================

class EStorable2 {
public:
    void* CreateCopy(void) const;
    int IsDerivedFrom(ETypeInfo* typeInfo) const;
    int IsExactType(ETypeInfo* typeInfo) const;
    void* DynamicCast(ETypeInfo* typeInfo) const;
    void* DynamicCast_nc(ETypeInfo* typeInfo);
};

// 0x802D1388
void* EStorable2::CreateCopy(void) const {
    // Serialize to memory stream, then deserialize a copy
    // EMemoryWriteStream stream;
    // operator<<(stream, this)
    // void* buf = stream.AllocAndCopyToBuffer()
    // Create EMemoryReadStream from buf
    // EStorable* copy;
    // operator>>(readStream, copy)
    // Free buf
    // return copy
    return NULL;
}

// 0x802D1440
int EStorable2::IsDerivedFrom(ETypeInfo* typeInfo) const {
    if (this == NULL) return 0;
    // Get our type via vtable, then ETypeInfo::IsDerivedFrom(typeInfo)
    return 0;
}

// 0x802D1498
int EStorable2::IsExactType(ETypeInfo* typeInfo) const {
    if (this == NULL) return 0;
    // Get our type via vtable
    // return (ourType == typeInfo) ? 1 : 0
    return 0;
}

// 0x802D14F4
void* EStorable2::DynamicCast(ETypeInfo* typeInfo) const {
    if (this == NULL) return NULL;
    if (IsDerivedFrom(typeInfo)) return (void*)this;
    return NULL;
}


// ============================================================
// ETypeInfo — Runtime type information registry
// ============================================================

class ETypeInfo2 {
public:
    void* m_createFunc;    // 0x00
    void* m_readFunc;      // 0x04
    void* m_writeFunc;     // 0x08
    char* m_name;          // 0x0C
    unsigned int m_hash;   // 0x10
    unsigned short m_id;   // 0x14
    short m_version;       // 0x16
    ETypeInfo2* m_parent;  // 0x18
    ETypeInfo2* m_left;    // 0x1C (offset 28)
    ETypeInfo2* m_right;   // 0x20 (offset 32)
    ETypeInfo2* m_next;    // 0x24 (offset 36)

    void Register(void* createFn, void* readFn, void* writeFn,
                  unsigned short id, char* name, ETypeInfo2* parent);
    void Insert(void);
};

// 0x802D58CC
void ETypeInfo2::Register(void* createFn, void* readFn, void* writeFn,
                           unsigned short id, char* name, ETypeInfo2* parent) {
    m_createFunc = createFn;
    m_readFunc = readFn;
    m_writeFunc = writeFn;
    m_name = name;
    // m_hash = EChecksum::Compute(name)
    m_id = id;
    m_version = -1;
    if (parent != this) {
        m_parent = parent;
    } else {
        m_parent = NULL;
    }
    // Increment global type count
    Insert();
}

// 0x802D5954
void ETypeInfo2::Insert(void) {
    // Add to linked list (m_next = current head, head = this)
    // Insert into BST by hash (m_left/m_right)
    // Standard BST insert
}


// ============================================================
// ENgcAram — GameCube ARAM (Auxiliary RAM) manager
// ============================================================
// NOTE: GC-specific — ARAM is 16MB of auxiliary memory on GameCube

class ENgcAram2 {
public:
    static void Open(void);
    static unsigned int Allocate(unsigned int size);
    static void SequentialLoadToARAM(void* src, unsigned int dst, unsigned int size);
    static void AsyncLoadToARAM(void* src, unsigned int dst, unsigned int size,
                                 void (*callback)(unsigned int), unsigned int userData);
    static void SequentialLoadFromARAM(void* dst, unsigned int src, unsigned int size);
    static void AsyncLoadFromARAM(void* dst, unsigned int src, unsigned int size,
                                   void (*callback)(unsigned int), unsigned int userData);
};

// 0x8036C35C
void ENgcAram2::Open(void) {
    // if (already open) return
    ARInit(0, 0);                    // NOTE: GC-specific
    ARQInit();                       // NOTE: GC-specific
    // Initialize 64 async request slots to -1
    // Set open flag
    unsigned int base = ARGetBaseAddress();  // NOTE: GC-specific
    // Store base + 256 as current allocation pointer
    // Zero-fill 256 bytes and DMA to ARAM base
}

// 0x8036C424
unsigned int ENgcAram2::Allocate(unsigned int size) {
    // Check if enough ARAM available
    // if (available < size) return -1
    // Bump allocate from current pointer
    // return old pointer
    return (unsigned int)-1;
}

// 0x8036C47C
void ENgcAram2::SequentialLoadToARAM(void* src, unsigned int dst, unsigned int size) {
    // Wait for any pending transfer
    // DCFlushRange(src, size)
    // ARQPostRequest(type=MRAM_TO_ARAM, priority=1)
    // Spin-wait for completion
    // NOTE: GC-specific — DMA transfer from main RAM to auxiliary RAM
}

// 0x8036C51C
void ENgcAram2::AsyncLoadToARAM(void* src, unsigned int dst, unsigned int size,
                                  void (*callback)(unsigned int), unsigned int userData) {
    // Find free request slot
    // if (no free slots) fall back to sequential + callback
    // else: store callback/userData, DCFlushRange, ARQPostRequest
    // NOTE: GC-specific
}

// 0x8036C6B0
void ENgcAram2::SequentialLoadFromARAM(void* dst, unsigned int src, unsigned int size) {
    // Wait for pending
    // DCInvalidateRange(dst, size)
    // ARQPostRequest(type=ARAM_TO_MRAM, priority=1)
    // Spin-wait for completion
    // NOTE: GC-specific
}


// ============================================================
// ENgcController — GameCube controller input
// ============================================================
// NOTE: GC-specific — maps PAD hardware to engine controller interface

class ENgcController2 {
public:
    float m_motorOne;  // offset 476
    float m_motorTwo;  // offset 480
    int   m_padIndex;  // offset 524

    int VibrateMotorOne(float intensity);
    int VibrateMotorTwo(float intensity);
    int StopMotorOne(void);
    int StopMotorTwo(void);
    unsigned int GetButtons(PADStatus& pad);
    float GetStick(PADStatus& pad, int stick, int axis);
    void UpdateMotors(void);
};

// 0x803C7124
int ENgcController2::VibrateMotorOne(float intensity) {
    // EController::VibrateMotorOne(intensity)
    // if (result) UpdateMotors(); return 1
    return 0;
}

// 0x803C7274
unsigned int ENgcController2::GetButtons(PADStatus& pad) {
    unsigned int buttons = 0;
    unsigned short raw = *(unsigned short*)&pad;

    // Map GC pad buttons to engine button flags
    if (raw & 0x0100) buttons |= 0x0040;   // A
    if (raw & 0x0200) buttons |= 0x0080;   // B
    if (raw & 0x0800) buttons |= 0x0010;   // X
    if (raw & 0x0400) buttons |= 0x0020;   // Y
    if (raw & 0x1000) buttons |= 0x0800;   // Start
    // L/R triggers with deadzone check
    if ((raw & 0x0040) || *(unsigned char*)((char*)&pad + 6) > 10) buttons |= 0x0004;  // L
    if ((raw & 0x0020) || *(unsigned char*)((char*)&pad + 7) > 10) buttons |= 0x0008;  // R
    if (raw & 0x0010) buttons |= 0x0002;   // Z
    if (raw & 0x0001) buttons |= 0x8000;   // D-Up (mapped as 32768)
    if (raw & 0x0002) buttons |= 0x2000;   // D-Down
    if (raw & 0x0004) buttons |= 0x4000;   // D-Left
    if (raw & 0x0008) buttons |= 0x1000;   // D-Right

    // Map analog stick directions to digital buttons
    float threshold = 0.5f; // from rodata
    // Left stick: up/down/left/right mapped to high bits
    // C-stick: up/down/left/right mapped to higher bits

    return buttons;
}

// 0x803C7470
float ENgcController2::GetStick(PADStatus& pad, int stick, int axis) {
    float val = 0.0f;
    if (stick == 0) {
        // Main stick
        if (axis == 0) {
            val = (float)(signed char)*(unsigned char*)((char*)&pad + 2);
        } else if (axis == 1) {
            val = (float)(signed char)*(unsigned char*)((char*)&pad + 3);
        }
        // Normalize by main stick range
    } else if (stick == 1) {
        // C-stick
        if (axis == 0) {
            val = (float)(signed char)*(unsigned char*)((char*)&pad + 4);
        } else if (axis == 1) {
            val = (float)(signed char)*(unsigned char*)((char*)&pad + 5);
        }
        // Normalize by C-stick range
    }
    // Clamp to [-1, 1]
    return val;
}

// 0x803C7560
void ENgcController2::UpdateMotors(void) {
    // NOTE: GC-specific
    int driveStatus = DVDGetDriveStatus();
    // Don't vibrate during DVD access (motor interference)
    bool dvdBusy = (driveStatus >= 4 && driveStatus <= 6) || driveStatus == 11;

    if (!dvdBusy && m_motorOne > 0.0f && m_motorTwo > 0.0f) {
        PADControlMotor(m_padIndex, 1);  // NOTE: GC-specific
    } else {
        PADControlMotor(m_padIndex, 0);  // NOTE: GC-specific
    }
}


// ============================================================
// ENgcControllerManager — Controller manager (GameCube)
// ============================================================
// NOTE: GC-specific

class ENgcControllerManager2 {
public:
    // PADStatus[4] at offset 36
    // controller pointers at SDA offset

    void Init(void);
    void Update(void);
};

// 0x8032DC84
void ENgcControllerManager2::Init(void) {
    PADInit();                         // NOTE: GC-specific
    PADRecalibrate(0x80000000);        // NOTE: GC-specific
    PADRecalibrate(0x40000000);
    PADRecalibrate(0x20000000);
    PADRecalibrate(0x10000000);
    // Create 4 ENgcController objects
    // Set vtable, pad index for each
}


// ============================================================
// ENgcEngine — GameCube engine
// ============================================================
// NOTE: GC-specific

class ENgcEngine2 {
public:
    ENgcEngine2(void);
    void InitConsole(void);
    void InitMemoryManager(void);
};

// 0x8032E04C
ENgcEngine2::ENgcEngine2(void) {
    // EEngine::EEngine()
    // Set vtable
    // Store this as singleton
    DVDSetAutoFatalMessaging(1);  // NOTE: GC-specific
    // m_field_0x50 = 0
}


// ============================================================
// EThreadMutex — Thread-aware mutex
// ============================================================

class EThreadMutex2 {
public:
    // EMutex at offset 0
    // EMutex at offset 28 (for recursion)
    int m_lockCount;  // offset 56
    int m_ownerThread; // offset 60

    EThreadMutex2(void);
    void Acquire(unsigned int timeout);
    void Release(void);
    ~EThreadMutex2(void);
};

// 0x802CBA70
EThreadMutex2::EThreadMutex2(void) {
    // EMutex::EMutex() at offset 0
    // Set vtable
    // EMutex::EMutex() at offset 28
    m_lockCount = 0;
    m_ownerThread = 0;
}


// ============================================================
// EGrowPool — Growing pool (continued)
// ============================================================
// 0x8035C298 — FreeUnusedSegments is complex page-based defragmentation
// See assembly for full implementation


// ============================================================
// Bloom — Post-processing bloom effect
// ============================================================

class Bloom2 {
public:
    float m_currentIntensity; // offset 0
    char  _pad[8];
    int   m_state;            // offset 12
    float m_fields[28];       // offset 16..127
    float m_targetIntensity;  // offset 112

    Bloom2(void);
    void UpdateTargetParameters(float dt);
    void EffectStateChanged(int newState);
    void SetTargetSettings(BloomSettings& settings);
};

// 0x803572F0
void Bloom2::UpdateTargetParameters(float dt) {
    if (m_state != 2) return;
    // Interpolate current bloom parameters toward target
    // InterpolateLinear for each parameter
    // Update intensity, threshold, scale values
}


// ============================================================
// BloomNGC — GameCube bloom rendering
// ============================================================
// NOTE: GC-specific — uses GX hardware for bloom passes

class BloomNGC2 {
public:
    void Draw(ERC* rc);
};

// 0x803595E4
void BloomNGC2::Draw(ERC* rc) {
    // NOTE: GC-specific — multi-pass bloom using GX texture copy
    // 1. Get current render state
    // 2. Copy framebuffer to texture (GXCopyTex)
    // 3. Set up bloom shader
    // 4. Draw fullscreen quad with blur
    // 5. Composite back to framebuffer
    // 6. Restore render state
}


// ============================================================
// DepthOfField / DepthOfFieldNGC
// ============================================================
// NOTE: GC-specific for NGC variant

class DepthOfField2 {
public:
    void UpdateTargetParameters(float dt);
    void EffectStateChanged(int newState);
};

class DepthOfFieldNGC2 {
public:
    void Draw(ERC* rc);  // NOTE: GC-specific
};


// ============================================================
// MotionBlurNGC
// ============================================================
// NOTE: GC-specific

class MotionBlurNGC2 {
public:
    void Draw(ERC* rc);  // NOTE: GC-specific
};


// ============================================================
// FrameEffectsManager — Post-processing manager
// ============================================================

class FrameEffectsManager2 {
public:
    void Init(void);
    void Shutdown(void);
};

// 0x803577B8
void FrameEffectsManager2::Init(void) {
    // Allocate Bloom, DepthOfField, MotionBlur objects
    // Initialize each with default settings
}


// ============================================================
// REffectsAttachment / REffectsEmitter / REffectsSequencer
// ============================================================

class REffectsAttachment2 {
public:
    void Load(EFile* file);
    void RegisterType(unsigned short id);
};

class REffectsEmitter2 {
public:
    void Load(EFile* file);
    void RegisterType(unsigned short id);
};

class REffectsSequencer2 {
public:
    void Load(EFile* file);
    void RegisterType(unsigned short id);
};


// ============================================================
// FreeResourceManager — Resource cache manager
// ============================================================

class FreeResourceManager2 {
public:
    // ENodeList at offset 0
    void* m_mutex;  // EThreadMutex*
    int   m_count;

    FreeResourceManager2(void* mutex);
    void AddItem(EResource* res);
    int HasItem(EResource* res);
    void RemoveItem(EResource* res);
    void MakeSpace(int count);
};

// 0x80328F80
FreeResourceManager2::FreeResourceManager2(void* mutex) {
    // Initialize ENodeList
    m_mutex = mutex;
    m_count = 0;
}


// ============================================================
// StateMachineManager — State machine lifecycle
// ============================================================

class StateMachineManager2 {
public:
    void Shutdown(void);
    void UpdateMachine(float dt);
    void DrawMachine(ERC* rc);
    void DrawTopmostMachine(ERC* rc);
};

// 0x800966E0
void StateMachineManager2::Shutdown(void) {
    // Walk machine list, delete each
}


// ============================================================
// StateMachineStatus
// ============================================================

class StateMachineStatus2 {
public:
    void Update(float dt);
    void Draw(ERC* rc);
};


// ============================================================
// DOGMA_PoolManager — Object pool allocator
// ============================================================

class DOGMA_PoolManager2 {
public:
    DOGMA_PoolManager2(unsigned int blockSize, unsigned int maxBlocks,
                        unsigned int alignment, unsigned int flags,
                        unsigned char a, bool b, unsigned char c, bool d,
                        unsigned char e, bool f);
    ~DOGMA_PoolManager2(void);
    void* Allocate(unsigned int size);
    void Deallocate(void* ptr, unsigned int size);
    void* ConsumeFreeBlockBySize(unsigned int size);
    void AddFreeBlockBySize(void* ptr, unsigned int size);
};


// ============================================================
// CTGFileImpl — Config/tuning file implementation
// ============================================================

class CTGFileImpl2 {
public:
    void* m_vtable;
    void* m_data;
    int   m_size;
    int   m_pos;
    bool  m_owned;

    CTGFileImpl2(void* data, int size, int pos, bool owned);
    ~CTGFileImpl2(void);
    int GetSize(void);
    void ReadBytes(unsigned char* buf, int count);
    void WriteBytes(unsigned char* buf, int count);
    void ReadString(char* buf, int maxLen);
    void WriteString(char* str);
};

// 0x8007CDD0
CTGFileImpl2::CTGFileImpl2(void* data, int size, int pos, bool owned) {
    // Set vtable
    m_data = data;
    m_size = size;
    m_pos = pos;
    m_owned = owned;
}


// ============================================================
// CUnlockDisplayObjectSim
// ============================================================

class CUnlockDisplayObjectSim2 {
public:
    void Init(void);
    void Shutdown(void);
};


// ============================================================
// ThumbnailCompresser
// ============================================================

class ThumbnailCompresser2 {
public:
    void Compress(void* src, int width, int height);
    void Decompress(void* dst);
};


// ============================================================
// LZSSCompressor
// ============================================================

class LZSSCompressor2 {
public:
    void Compress(void* src, unsigned int srcSize, void* dst, unsigned int* dstSize);
    void Decompress(void* src, unsigned int srcSize, void* dst, unsigned int* dstSize);
};


// ============================================================
// FadeSquare / LineFade / FrameEffect
// ============================================================

class FadeSquare2 {
public:
    void Draw(ERC* rc);
    void Update(float dt);
};

class LineFade2 {
public:
    void Draw(ERC* rc);
    void Update(float dt);
};

class FrameEffect2 {
public:
    void Draw(ERC* rc);
    void Update(float dt);
    void SetEnabled(bool enabled);
};


// ============================================================
// ER* Resource classes — Load/Save/RegisterType pattern
// ============================================================

class ERAmbientScore2 {
public:
    ERAmbientScore2(void);
    ~ERAmbientScore2(void);
    void Load(EFile* file);
    static void RegisterType(unsigned short id);
};

class ERAmbientSound2 {
public:
    ERAmbientSound2(void);
    ~ERAmbientSound2(void);
    void Load(EFile* file);
    static void RegisterType(unsigned short id);
};

class ERBinary2 {
public:
    ERBinary2(void);
    ~ERBinary2(void);
    void Load(EFile* file);
    static void RegisterType(unsigned short id);
};

class ERCharacter2 {
public:
    ERCharacter2(void);
    ~ERCharacter2(void);
    void Load(EFile* file);
    static void RegisterType(unsigned short id);
};

class EREdithTreeSet2 {
public:
    EREdithTreeSet2(void);
    ~EREdithTreeSet2(void);
    void Load(EFile* file);
    static void RegisterType(unsigned short id);
};

class ERMovie2 {
public:
    ERMovie2(void);
    ~ERMovie2(void);
    void Load(EFile* file);
    static void RegisterType(unsigned short id);
};

class ERSampledata2 {
public:
    ERSampledata2(void);
    ~ERSampledata2(void);
    void Load(EFile* file);
    static void RegisterType(unsigned short id);
};

class ERSoundEvent2 {
public:
    ERSoundEvent2(void);
    ~ERSoundEvent2(void);
    void Load(EFile* file);
    static void RegisterType(unsigned short id);
};

class ERSoundTrackData2 {
public:
    ERSoundTrackData2(void);
    ~ERSoundTrackData2(void);
    void Load(EFile* file);
    static void RegisterType(unsigned short id);
};

// All ER* classes follow the same pattern:
// Constructor: EResource::EResource() + set vtable + zero members
// Destructor: free loaded data + set vtable + EResource::~EResource()
// Load: read header, allocate buffer, read data from file
// RegisterType: ETypeInfo::Register(New, ReadNew, Write, id, name, parent)


// ============================================================
// EResource / EResourceMap
// ============================================================

class EResource2 {
public:
    void AddRef(void);
    void DelRef(void);
};

class EResourceMap2 {
public:
    void AddResource(const char* name, EResource* res);
    EResource* FindResource(const char* name);
    void RemoveResource(const char* name);
};


// ============================================================
// EResLoaderMsgQueue / EResPrefetchFile
// ============================================================

class EResLoaderMsgQueue2 {
public:
    EResLoaderMsgQueue2(void);
    ~EResLoaderMsgQueue2(void);
    void Send(unsigned int msg);
    int Receive(unsigned int* msg);
};

class EResPrefetchFile2 {
public:
    EResPrefetchFile2(void);
    ~EResPrefetchFile2(void);
    void StartPrefetch(const char* name);
    int IsPrefetchComplete(void);
};


// ============================================================
// EScratchBuffMan — Scratch buffer manager
// ============================================================

class EScratchBuffMan2 {
public:
    void Init(void);
    void Shutdown(void);
    void* GetBuffer(int index);
    void ReleaseBuffer(int index);
};


// ============================================================
// EShaderDef — Shader definition
// ============================================================

class EShaderDef2 {
public:
    void Load(EFile* file);
    void Apply(void);
};


// ============================================================
// ESimShadow — Sim shadow rendering
// ============================================================

class ESimShadow2 {
public:
    void Init(void);
    void Update(float dt);
    void Draw(ERC* rc);
};


// ============================================================
// EParticleObj — Particle system object
// ============================================================

class EParticleObj2 {
public:
    void Update(float dt);
    void Draw(ERC* rc);
    void Reset(void);
};


// ============================================================
// EmitterSpr3d — 3D sprite emitter
// ============================================================

class EmitterSpr3d2 {
public:
    void Update(float dt);
    void Draw(ERC* rc);
};


// ============================================================
// EffectsPreRenderVisitor
// ============================================================

class EffectsPreRenderVisitor2 {
public:
    void Visit(EInstance* inst);
};


// ============================================================
// EyeToyManager
// ============================================================

class EyeToyManager2 {
public:
    void Init(void);
    void Shutdown(void);
    void Update(void);
};


// ============================================================
// FPHeap — Fixed-page heap
// ============================================================

class FPHeap2 {
public:
    FPHeap2(void);
    ~FPHeap2(void);
    void* Alloc(unsigned int size);
    void Free(void* ptr);
};


// ============================================================
// FileList — File listing
// ============================================================

class FileList2 {
public:
    void AddFile(const char* name);
    int GetCount(void);
    const char* GetFile(int index);
};


// ============================================================
// HDDThread — HDD I/O thread
// ============================================================

class HDDThread2 {
public:
    HDDThread2(void);
    ~HDDThread2(void);
    void Start(void);
    void Stop(void);
};


// ============================================================
// ArcCopier / ArcFileInfo — Archive file handling
// ============================================================

class ArcCopier2 {
public:
    void CopyFile(const char* src, const char* dst);
    int GetProgress(void);
};

class ArcFileInfo2 {
public:
    ArcFileInfo2(void);
    void SetName(const char* name);
    unsigned int GetOffset(void);
    unsigned int GetSize(void);
};


// ============================================================
// BackgroundImpl — Background rendering
// ============================================================

class BackgroundImpl2 {
public:
    BackgroundImpl2(void);
    ~BackgroundImpl2(void);
    void Init(void);
    void Draw(ERC* rc);
};


// ============================================================
// CTGDump / CTGFileManager
// ============================================================

class CTGDump2 {
public:
    static void DumpToFile(const char* filename);
};

class CTGFileManager2 {
public:
    void Init(void);
    void Shutdown(void);
    void* LoadFile(const char* name);
};


// ============================================================
// ENgcFile / ENgcSNFile / ENgcScheduler / ENgcShader / ENgcRenderSurface
// ============================================================
// NOTE: GC-specific classes

class ENgcFile2 {
public:
    void Open(const char* name, int mode);
    void Close(void);
    int Read(void* buf, int size);
    int Write(const void* buf, int size);
};

class ENgcSNFile2 {
public:
    void Open(const char* name, int mode);
    void Close(void);
    int Read(void* buf, int size);
};

class ENgcScheduler2 {
public:
    void Init(void);
    void Update(void);
    void ScheduleTask(void* task);
};

class ENgcShader2 {
public:
    void Apply(void);
    void Reset(void);
    // NOTE: GC-specific — configures GX TEV stages
};

class ENgcRenderSurface2 {
public:
    void Init(int width, int height);
    void BeginScene(void);
    void EndScene(void);
    // NOTE: GC-specific — manages GX render targets
};


// ============================================================
// node_alloc_L_false_0_R — STL allocator node
// ============================================================

// This handles the STL node allocator's free list management
// Typically: allocate/deallocate from a free list of fixed-size nodes
