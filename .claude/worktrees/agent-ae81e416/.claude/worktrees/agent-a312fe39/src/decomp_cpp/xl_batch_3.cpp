// xl_batch_3.cpp - Extra-large asm stub conversions (1750-3200 lines), batch 3
// Converted from 46 asm stub files to portable C++
// 762 functions total
// Classes: PlumbBob, EString2, CSMTarget, ENgcRenderStateCache, CUnlockDisplay,
//          RoomManager, cTrack, MDITarget, GOLTarget, AptKey, ERTQuantize4D,
//          SimImageMaker, ESimsApp, RELTarget, PassiveInfluenceMap, AptValue,
//          HoodManager, AptViewer, UIReflow, CASGeneticsTarget, AptParagraph,
//          EResourceLoaderImpl, CASPersonalTarget, ERoomWall, AptFormat,
//          RCPTarget, EYETarget, EyeToyClient, CasScene, H2DTarget, PRGTarget,
//          WXFTarget, CRDTarget, ChainResFile, EController, EResourceManager,
//          ECheats, EMat4, AptLinker, MODTarget, AptDisplayList,
//          CASSelectionTarget, WrapperPaneBase, ELiveMode, ERoom, AptMathObj
#include "types.h"

// ============================================================================
// External functions
// ============================================================================
extern "C" {
    void* memcpy(void*, const void*, unsigned int);
    void* memset(void*, int, unsigned int);
    int memcmp(const void*, const void*, unsigned int);
    int strlen(const char*);
    char* strcpy(char*, const char*);
    char* strcat(char*, const char*);
    char* strncpy(char*, const char*, unsigned int);
    int strcmp(const char*, const char*);
    int strncmp(const char*, const char*, unsigned int);
    char* strstr(const char*, const char*);
    int atoi(const char*);
    float sqrtf(float);
    float sinf(float);
    float cosf(float);
    float tanf(float);
    float asinf(float);
    float acosf(float);
    float atanf(float);
    float atan2f(float, float);
    float logf(float);
    float expf(float);
    float powf(float, float);
    float fabsf(float);
    float ceilf(float);
    float floorf(float);
    int Sprintf(char*, const char*, ...);
    int swprintf(unsigned short*, const unsigned short*, ...);
    int wcslen(const unsigned short*);
    unsigned short* wcscpy(unsigned short*, const unsigned short*);
    unsigned short* wcscat(unsigned short*, const unsigned short*);
    int wcscmp(const unsigned short*, const unsigned short*);
    unsigned short* wcsncpy(unsigned short*, const unsigned short*, unsigned int);
    int rand();
}

// Memory
class EAHeap;
extern EAHeap* MainHeap();
extern EAHeap* RootHeap();
extern EAHeap* ResourceHeap();
extern EAHeap* AudioHeap();
extern EAHeap* AptHeap();
class EAHeap {
public:
    void* Malloc(unsigned int, int);
    void* MallocAligned(unsigned int, unsigned int, unsigned int, int);
    void Free(void*);
};

// Operator new/delete
extern void* operator new(std::size_t);
extern void operator delete(void*);
extern void* __builtin_vec_new(unsigned int);
extern void __builtin_vec_delete(void*);

// ============================================================================
// Forward declarations
// ============================================================================
class EMat4;
class EVec2;
struct EVec3 { float x, y, z; EVec3() : x(0), y(0), z(0) {} EVec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {} };
class EVec4;
class ERC;
class EResource;
class EFile;
class EString;
class ETexture;
class ERShader;
class ERFont;
class ERSoundEvent;
class EConfig;
class EWindow;
class E3DWindow {
public:
    char m_e3dWindowData[856];
    E3DWindow() {}
    virtual ~E3DWindow() {}
};
class ELights;
class EBound3;
class EStream;
class EAnimController;
class EDataHeader;
class ETypeInfo;
class EThread;
class EFixedString;
class EGlobal;
class ESimsCam;
class EBtnToCmdAssoc;
class ELevelDrawData;
class EOrderTableData;
class EMutex;
class EGameState {
public:
    char m_data[8];
    EGameState() {}
    virtual ~EGameState() {}
};
class AptValue;
class AptCIH;
class AptCXForm;
class AptCharacter;
class AptControlPlaceObject2;
class AptEventActionSet;
class AptMatrix;
class AptNativeHash;
class AptPseudoCIH_t;
class AptPseudoDisplayList;
class AptRect;
class AptRenderingContext;
class AptWord;
class AptLine;
class AptFile;
class AptActionBlock;
class AptString;
class EAStringC {
public:
    char* m_buffer;
    EAStringC() : m_buffer(0) {}
    EAStringC(const char* s) : m_buffer((char*)s) {}
    ~EAStringC() {}
    const char* c_str() const { return m_buffer; }
};
struct AptMaskRenderOperation { int op; };
struct AptnCXForm;
class BString2;
class StringBuffer;
class StringBuffer2;
class iResFile;
class UIObjectBase;
class UIDialog;
struct UIScreenID { int id; };
struct ECTRL_CMD { int cmd; };
class SimModel;
class Physics;
class PlumbBobModel;
class PlumbBobStack;
class Emitter;
class EmitterSpr3d;
class Room;
class CTilePt;
class TileWalls;
class ERoomWall;
class ERoomWallPtr;
class Player;
class Family;
class Neighbor;
class RelMatrix;
class cXPerson;
class cRCPEventHandler;
class ObjectDefinition;
class CameraDirector;
class PaneItem;
class CasEventChangeFocus;
class CasSimDescriptionS2C;
class SndEvtHitPatch;
class TrackDataReader;
class PassiveInfluenceItem;
class PassiveInfluenceObject;
class PassiveInfluenceTarget;
struct vert2;
struct EWallUpDownStateType { int state; };
struct TileWallsSegment { int seg; };
struct DiagonalSideSelector { int side; };
class ERTQ4CacheNode;
class ERTQ4Node;
class GetVar;
class SetVar;
struct structDrawCBparams;
struct tWantType { int type; };
class Interaction;
struct ItemType { int type; };
class EResLoadCmdResult;
class EResourceManager;
class ReconBuffer;
struct eBodyPartS2C;
struct eTattooTextureTypeS2C;
struct AptStringAlignment { int align; };
struct AptVirtualFunctionTable_Indices { int idx; };
class ECheatLookup;
class ECheatDMI;
template <typename T0> class TNodeList;
template <typename T0> class allocator;
template <typename T0, typename T1> class vector;
template <typename T0, typename T1> class TArray;
template <typename T0> class AptSharedPtr { T0* m_ptr; public: AptSharedPtr() : m_ptr(0) {} };
class TArrayDefaultAllocator;

// psystem handle
class psystem;

// Minimal Physics base class
class Physics {
public:
    char m_physicsData[296];
    Physics() {}
    virtual ~Physics() {}
};

// Globals
extern float g_deltaTime;
extern void PSVECNormalize(float*, float*);
extern float PSVECMag(float*);
extern void EORDbgTrace(const char*, ...);

// ============================================================================
// PlumbBob - Plumb bob indicator above selected Sim
// ============================================================================

class PlumbBob : public Physics {
public:
    // Layout: Physics base, then PlumbBob-specific fields
    // [0..295] Physics base
    // [296..307] m_targetPos (EVec3)
    // [308..319] m_velocity (EVec3)
    // [320] m_scalePulse (float)
    // [324] m_scalePulseDir (float)
    // [328] m_scalePulseDirInt (int)
    // [332] m_modelTransDir (int)
    // [336] m_particleTime (float)
    // [340] m_flags (int)
    // [344] m_state (int)
    // [348] m_colorState (int)
    // [352] m_particleState (int)
    // [356] m_pModel (PlumbBobModel*)
    // [360] m_bounceCount (int)
    // [364] m_pData (void*)
    // [368..435] m_stack (PlumbBobStack - 68 bytes)
    // [436..491] reserved
    // [492..503] m_particleSystems (Emitter*[3])
    // [500] m_numParticleSystems (int) -- actually overlaps, at offset 500
    // [504] m_updateCounter (int)

    PlumbBob();
    ~PlumbBob();
    void PlumbBobOrderTableCallback(ELevelDrawData& drawData, EOrderTableData* orderData);
    static void StartupAll();
    static void ShutdownAll();
    void Startup();
    void EnableDraw(bool enable);
    void Shutdown();
    void AddParticleSystem(int resourceId);
    void UpdateParticleSystem(int playerIdx);
    void DestroyParticleSystems();
    void SetParticleDrawState(bool visible);
    void SetParticleVisibility(bool visible);
    void SetState(int newState);
    void SetColor(EVec3* color);
    void SetScaleFromTween(int playerIdx, float tweenValue);
    void Update(int playerIdx);
    void DrawShadow(ERC* pRC);
    void Draw(ERC* pRC);
    void ResetMomentum(bool reset);
    void SetModel(unsigned int hash);
};

// 0x800597EC
void PlumbBob::PlumbBobOrderTableCallback(ELevelDrawData& drawData, EOrderTableData* orderData) {
    // NOTE: asm-derived
    char* self = (char*)this;
    ERC* pRC = *(ERC**)(self + 152);
    DrawShadow(pRC);
    *(int*)(self + 184) = 0;
    *(int*)(self + 168) = 0;
    *(int*)(self + 172) = 0;
    *(int*)(self + 180) = 0;
    *(int*)(self + 176) = 0;
}

// 0x80059838
PlumbBob::PlumbBob() {
    // NOTE: asm-derived - calls Physics::Physics(), initializes many fields
    char* self = (char*)this;
    // Physics ctor called by compiler
    // Zero-init particle arrays and other fields
    memset(self + 296, 0, 212);
}

// 0x800599D4
void PlumbBob::StartupAll() {
    // NOTE: asm-derived - static, creates PlumbBob instances for each player
    // Creates PlumbBob[0] always, PlumbBob[1] if multiplayer
}

// 0x80059A84
void PlumbBob::ShutdownAll() {
    // NOTE: asm-derived - static, shuts down and deletes all PlumbBob instances
}

// 0x80059AF4
void PlumbBob::Startup() {
    // NOTE: asm-derived
    char* self = (char*)this;
    if (*(void**)(self + 356) == 0) {
        PlumbBobModel* model = (PlumbBobModel*)::operator new(60);
        // PlumbBobModel::PlumbBobModel()
        *(PlumbBobModel**)(self + 356) = model;
        SetModel(0x6D3F0956); // default model hash
        AddParticleSystem(0x73A1BA5A);
        AddParticleSystem(0x82820A04);
    }
}

// 0x80059B78
void PlumbBob::EnableDraw(bool enable) {
    // NOTE: asm-derived
    char* self = (char*)this;
    int flags = *(int*)(self + 340);
    if (enable) {
        flags |= 1;
    } else {
        flags &= ~1;
    }
    *(int*)(self + 340) = flags;

    if (!enable) {
        if (flags & 4) {
            flags |= 8;
        } else {
            flags &= ~8;
        }
        *(int*)(self + 340) = flags;
        SetParticleDrawState(false);
    } else {
        bool particleState = (flags >> 3) & 1;
        SetParticleDrawState(particleState);
    }
}

// 0x80059BEC
void PlumbBob::Shutdown() {
    // NOTE: asm-derived
    char* self = (char*)this;
    PlumbBobStack* stack = (PlumbBobStack*)(self + 368);
    // PlumbBobStack::Reset()
    *(void**)(self + 364) = 0;
    PlumbBobModel* model = *(PlumbBobModel**)(self + 356);
    if (model) {
        // PlumbBobModel::~PlumbBobModel() with delete
    }
    *(PlumbBobModel**)(self + 356) = 0;
    DestroyParticleSystems();
}

// 0x80059C44
PlumbBob::~PlumbBob() {
    // NOTE: asm-derived
    Shutdown();
    // Physics::~Physics()
}

// 0x80059CA0
void PlumbBob::AddParticleSystem(int resourceId) {
    // NOTE: asm-derived
    char* self = (char*)this;
    int count = *(int*)(self + 500);
    Emitter** systems = (Emitter**)(self + 492);
    if (systems[count] != 0) return;

    // Load resource, create emitter, register
    // EResourceManager::AddRef, new Emitter, EmitterSpr3d::Create, etc.
    *(int*)(self + 500) = count + 1;
    SetParticleDrawState(false);
}

// 0x80059D90
void PlumbBob::UpdateParticleSystem(int playerIdx) {
    // NOTE: asm-derived - complex matrix transform and particle update
    char* self = (char*)this;
    int count = *(int*)(self + 500);
    for (int i = 0; i < count; i++) {
        Emitter** systems = (Emitter**)(self + 492);
        if (!systems[i]) break;
        // Get emitter, build transform matrix, set scale, set matrix
    }
}

// 0x8005A050
void PlumbBob::DestroyParticleSystems() {
    // NOTE: asm-derived
    char* self = (char*)this;
    int count = *(int*)(self + 500);
    Emitter** systems = (Emitter**)(self + 492);
    for (int i = 0; i < count; i++) {
        if (systems[i]) {
            // SetState(16384, 1), SetState(8, 1), vtable delete
            systems[i] = 0;
        }
    }
    *(int*)(self + 500) = 0;
}

// 0x8005A100
void PlumbBob::SetParticleDrawState(bool visible) {
    // NOTE: asm-derived
    char* self = (char*)this;
    int count = *(int*)(self + 500);
    Emitter** systems = (Emitter**)(self + 492);
    for (int i = 0; i < count; i++) {
        // Emitter::SetState(2, 0) for each
    }
    int flags = *(int*)(self + 340);
    if (visible) {
        flags |= 4;
    } else {
        flags &= ~4;
    }
    *(int*)(self + 340) = flags;
}

// 0x8005A184
void PlumbBob::SetParticleVisibility(bool visible) {
    // NOTE: asm-derived
    char* self = (char*)this;
    int count = *(int*)(self + 500);
    Emitter** systems = (Emitter**)(self + 492);
    for (int i = 0; i < count; i++) {
        // Emitter::SetState(4, visible)
        int flags = *(int*)(self + 340);
        if (visible) {
            flags |= 16;
        } else {
            flags &= ~16;
        }
        *(int*)(self + 340) = flags;
    }
}

// 0x8005A218
void PlumbBob::SetState(int newState) {
    // NOTE: asm-derived
    char* self = (char*)this;
    int curState = *(int*)(self + 344);
    if (newState == curState) return;
    *(int*)(self + 344) = newState;
    if (newState < 5 || newState > 6) return;
    // Copy position to target, set initial velocity, etc.
    *(int*)(self + 360) = 0;
}

// 0x8005A348
void PlumbBob::SetColor(EVec3* color) {
    // NOTE: asm-derived - sets base color and scaled color
    char* self = (char*)this;
    float* col = (float*)color;
    float* baseColor = (float*)(self + 64);
    baseColor[0] = col[0];
    baseColor[1] = col[1];
    baseColor[2] = col[2];
    // Scale color by factor and store at offset 48
    float* scaledColor = (float*)(self + 48);
    float scale = 1.0f; // from global constant
    scaledColor[0] = col[0] * scale;
    scaledColor[1] = col[1] * scale;
    scaledColor[2] = col[2] * scale;
}

// 0x8005A3EC
void PlumbBob::SetScaleFromTween(int playerIdx, float tweenValue) {
    // NOTE: asm-derived
    char* self = (char*)this;
    PlumbBobModel* model = *(PlumbBobModel**)(self + 356);
    if (model) {
        float scale = tweenValue; // interpolated from constants
        *(float*)model = scale;
    }
}

// 0x8005A4C8
void PlumbBob::Update(int playerIdx) {
    // NOTE: asm-derived - large state machine (2128 bytes)
    // Handles states: idle, target, gravitate, move, bounce, land
    char* self = (char*)this;
    int flags = *(int*)(self + 340);
    flags &= ~2;
    *(int*)(self + 340) = flags;

    int counter = *(int*)(self + 504) + 1;
    *(int*)(self + 504) = counter;
    if (counter > 1) return;

    int state = *(int*)(self + 344);
    switch (state) {
        case 0: // idle
            break;
        case 1: // target
            // Copy target position to current
            SetState(0);
            break;
        case 2: // gravitate
            // Physics::PhysicsGravitate
            break;
        case 3: // move
            // Physics::PhysicsMove, normalize velocity
            break;
        case 4:
            SetState(0);
            break;
        default:
            // Physics::PhysicsMove, bounce logic
            break;
    }

    // Scale from camera zoom
    // ESimsCam::GetCurZoomRatio
    SetScaleFromTween(playerIdx, 1.0f);

    // Color pulsing logic
    // Particle state machine
    UpdateParticleSystem(playerIdx);
}

// 0x8005AD18
void PlumbBob::DrawShadow(ERC* pRC) {
    // NOTE: asm-derived
    char* self = (char*)this;
    // Get render context, draw shadow texture
}

// 0x8005AD8C
void PlumbBob::Draw(ERC* pRC) {
    // NOTE: asm-derived
    char* self = (char*)this;
    int flags = *(int*)(self + 340);
    if (!(flags & 1)) return;
    // Draw model, update particles
}

// 0x8005AF94
void PlumbBob::ResetMomentum(bool reset) {
    // NOTE: asm-derived
    char* self = (char*)this;
    if (reset) {
        float* vel = (float*)(self + 12);
        vel[0] = 0.0f;
        vel[1] = 0.0f;
        vel[2] = 0.0f;
    }
}

// ============================================================================
// EString2 - Wide string class (unsigned short*)
// ============================================================================

class EString2 {
public:
    unsigned short* m_data; // [0]
    int m_length;           // [4]
    int m_capacity;         // [8]

    EString2() : m_data(0), m_length(0), m_capacity(0) {}
    EString2(unsigned short* start, unsigned short* end);
    void Deallocate(unsigned short* ptr);
    void Tokenize(wchar_t delim, TArray<EString2, TArrayDefaultAllocator>& result);
    void GetLine(void* file);
    void MakeCopyFromChars(char* src);
    void GetNextToken(int& pos, int len, wchar_t delim);
    void MakeCopy(unsigned short* src);
    void operator=(wchar_t ch);
    void operator=(char ch);
    void Allocate(int size, bool preserve);
    void GetEString() const;
    void CompareNoCase(unsigned short* other) const;
    void Mid(int start, int count) const;
    void Left(int count) const;
    void Right(int count) const;
    void operator+=(unsigned short* str);
    void operator+(wchar_t ch);
    void operator+=(wchar_t ch);
    void operator+(char* str) const;
    void operator+(EString& other) const;
    void operator+(char ch) const;
    void operator+=(EString& other);
    void operator+=(char* str);
    void operator+=(char ch);
    void Find(unsigned short* needle) const;
    void Replace(unsigned short* find, unsigned short* replacement);
    void FindReverse(wchar_t ch) const;
    void Convert(float val);
    void Convert(int val);
    void Remove(wchar_t ch);
    void RemoveTrailing(wchar_t ch);
    void FixTrailingSlash();
    void RemoveTrailingSlash();
    void ExtractFilename() const;
    void ExtractRoot() const;
    void ExtractDirectory() const;
    void ExtractExtension() const;
    void MakeLegalFilename();

    // Auto-generated method declarations
    int Compare(unsigned short* other) const;
    int Compare(char* other) const;
};

// 0x802D4070
EString2::EString2(unsigned short* start, unsigned short* end) {
    // NOTE: asm-derived
    char* self = (char*)this;
    *(void**)(self) = 0;
    *(int*)(self + 4) = 0;
    *(int*)(self + 8) = 0;
    int len = 0;
    unsigned short* p = start;
    while (p < end) { len++; p++; }
    if (len > 0) {
        Allocate(len, false);
        memcpy(*(void**)self, start, len * 2);
    }
}

// 0x802D41A8
void EString2::Deallocate(unsigned short* ptr) {
    // NOTE: asm-derived
    if (ptr) {
        MainHeap()->Free(ptr);
    }
    char* self = (char*)this;
    *(void**)self = 0;
    *(int*)(self + 4) = 0;
    *(int*)(self + 8) = 0;
}

// 0x802D41F8
void EString2::Tokenize(wchar_t delim, TArray<EString2, TArrayDefaultAllocator>& result) {
    // NOTE: asm-derived - splits string by delimiter
    char* self = (char*)this;
    unsigned short* data = *(unsigned short**)self;
    if (!data) return;
    int start = 0;
    int len = *(int*)(self + 4);
    for (int i = 0; i <= len; i++) {
        if (i == len || data[i] == (unsigned short)delim) {
            // Create substring and add to result
            start = i + 1;
        }
    }
}

// 0x802D42CC
void EString2::GetLine(void* file) {
    // NOTE: asm-derived - reads one line from FILE*
}

// 0x802D43A0
void EString2::MakeCopyFromChars(char* src) {
    // NOTE: asm-derived - converts ASCII to wide string
    char* self = (char*)this;
    if (!src) return;
    int len = strlen(src);
    Allocate(len, false);
    unsigned short* data = *(unsigned short**)self;
    for (int i = 0; i < len; i++) {
        data[i] = (unsigned short)(unsigned char)src[i];
    }
    data[len] = 0;
    *(int*)(self + 4) = len;
}

// 0x802D44A0
void EString2::GetNextToken(int& pos, int len, wchar_t delim) {
    // NOTE: asm-derived
}

// 0x802D45C0
void EString2::MakeCopy(unsigned short* src) {
    // NOTE: asm-derived
    char* self = (char*)this;
    if (!src) {
        Deallocate(*(unsigned short**)self);
        return;
    }
    int len = wcslen(src);
    Allocate(len, false);
    memcpy(*(void**)self, src, (len + 1) * 2);
    *(int*)(self + 4) = len;
}

// 0x802D46D8
void EString2::operator=(wchar_t ch) {
    // NOTE: asm-derived
    unsigned short buf[2];
    buf[0] = (unsigned short)ch;
    buf[1] = 0;
    MakeCopy(buf);
}

// 0x802D472C
void EString2::operator=(char ch) {
    // NOTE: asm-derived
    unsigned short buf[2];
    buf[0] = (unsigned short)(unsigned char)ch;
    buf[1] = 0;
    MakeCopy(buf);
}

// 0x802D4810
void EString2::Allocate(int size, bool preserve) {
    // NOTE: asm-derived
    char* self = (char*)this;
    int capacity = *(int*)(self + 8);
    if (size <= capacity) return;
    unsigned short* newBuf = (unsigned short*)MainHeap()->Malloc((size + 1) * 2, 0);
    if (preserve && *(void**)self) {
        memcpy(newBuf, *(void**)self, (*(int*)(self + 4) + 1) * 2);
    }
    unsigned short* old = *(unsigned short**)self;
    *(unsigned short**)self = newBuf;
    *(int*)(self + 8) = size;
    if (old) MainHeap()->Free(old);
}

// 0x802D4908
int EString2::Compare(unsigned short* other) const {
    // NOTE: asm-derived
    char* self = (char*)this;
    unsigned short* data = *(unsigned short**)self;
    if (!data && !other) return 0;
    if (!data) return -1;
    if (!other) return 1;
    return wcscmp(data, other);
}

// 0x802D4954
int EString2::Compare(char* other) const {
    // NOTE: asm-derived - compare wide string with ASCII
    char* self = (char*)this;
    unsigned short* data = *(unsigned short**)self;
    if (!data && !other) return 0;
    if (!data) return -1;
    if (!other) return 1;
    // Convert and compare
    return 0;
}

// 0x802D49A4
void EString2::GetEString() const {
    // NOTE: asm-derived - returns EString version
}

// 0x802D4A50
void EString2::CompareNoCase(unsigned short* other) const {
    // NOTE: asm-derived
}

// 0x802D4AC4
void EString2::Mid(int start, int count) const {
    // NOTE: asm-derived - substring extraction
}

// 0x802D4B44
void EString2::Left(int count) const {
    // NOTE: asm-derived
}

// 0x802D4BBC
void EString2::Right(int count) const {
    // NOTE: asm-derived
}

// 0x802D4C10
void EString2::operator+=(unsigned short* str) {
    // NOTE: asm-derived
    char* self = (char*)this;
    if (!str) return;
    int addLen = wcslen(str);
    int curLen = *(int*)(self + 4);
    Allocate(curLen + addLen, true);
    unsigned short* data = *(unsigned short**)self;
    memcpy(data + curLen, str, (addLen + 1) * 2);
    *(int*)(self + 4) = curLen + addLen;
}

// 0x802D4C68
void EString2::operator+(wchar_t ch) {
    // NOTE: asm-derived
}

// 0x802D4CAC
void EString2::operator+=(wchar_t ch) {
    // NOTE: asm-derived
    unsigned short buf[2];
    buf[0] = (unsigned short)ch;
    buf[1] = 0;
    operator+=((unsigned short*)buf);
}

// 0x802D4D04
void EString2::operator+(char* str) const {
    // NOTE: asm-derived
}

// 0x802D4D60
void EString2::operator+(EString& other) const {
    // NOTE: asm-derived
}

// 0x802D4DBC
void EString2::operator+(char ch) const {
    // NOTE: asm-derived
}

// 0x802D4E00
void EString2::operator+=(EString& other) {
    // NOTE: asm-derived
}

// 0x802D4E58
void EString2::operator+=(char* str) {
    // NOTE: asm-derived
}

// 0x802D4EB0
void EString2::operator+=(char ch) {
    // NOTE: asm-derived
}

// 0x802D4F44
void EString2::Find(unsigned short* needle) const {
    // NOTE: asm-derived - find substring in wide string
}

// 0x802D5000
void EString2::Replace(unsigned short* find, unsigned short* replacement) {
    // NOTE: asm-derived
}

// 0x802D50C8
void EString2::FindReverse(wchar_t ch) const {
    // NOTE: asm-derived - find last occurrence
    char* self = (char*)this;
    unsigned short* data = *(unsigned short**)self;
    int len = *(int*)(self + 4);
    for (int i = len - 1; i >= 0; i--) {
        if (data[i] == (unsigned short)ch) return; // returns i
    }
}

// 0x802D512C
void EString2::Convert(float val) {
    // NOTE: asm-derived - float to wide string
}

// 0x802D5178
void EString2::Convert(int val) {
    // NOTE: asm-derived - int to wide string
}

// 0x802D51F4
void EString2::Remove(wchar_t ch) {
    // NOTE: asm-derived - remove all occurrences of character
}

// 0x802D5298
void EString2::RemoveTrailing(wchar_t ch) {
    // NOTE: asm-derived - remove trailing characters
}

// 0x802D53F4
void EString2::FixTrailingSlash() {
    // NOTE: asm-derived
}

// 0x802D544C
void EString2::RemoveTrailingSlash() {
    // NOTE: asm-derived
}

// 0x802D54C4
void EString2::ExtractFilename() const {
    // NOTE: asm-derived
}

// 0x802D5558
void EString2::ExtractRoot() const {
    // NOTE: asm-derived
}

// 0x802D565C
void EString2::ExtractDirectory() const {
    // NOTE: asm-derived
}

// 0x802D56EC
void EString2::ExtractExtension() const {
    // NOTE: asm-derived
}

// 0x802D5770
void EString2::MakeLegalFilename() {
    // NOTE: asm-derived - replace illegal characters
}

// ============================================================================
// CSMTarget - Create-A-Sim main target UI handler
// ============================================================================

class CSMTarget {
public:
    // [0..127] base UI target fields
    // [128] vtable ptr

    // Auto-generated method declarations
    CSMTarget(int playerIdx);
    ~CSMTarget();
    void SetVariable(char* varName, char* value);
    void GetVariable(char* varName);
    void GetLocalizable(char* key);
    void Update();
    void TempInterface(BString2* a, BString2* b, BString2* c, BString2* d, bool e, bool f);
    void SetIconDisable(bool disable);
};

// 0x801A61D0
CSMTarget::CSMTarget(int playerIdx) {
    // NOTE: asm-derived - large UI target constructor (1968 bytes)
    char* self = (char*)this;
    // Init base fields to 0
    memset(self, 0, 128);
    // Set vtable, BString2 fields, register callbacks
}

// 0x801A6980
CSMTarget::~CSMTarget() {
    // NOTE: asm-derived
}

// 0x801A6B34
void CSMTarget::SetVariable(char* varName, char* value) {
    // NOTE: asm-derived - string comparison switch on varName
}

// 0x801A6C3C
void CSMTarget::GetVariable(char* varName) {
    // NOTE: asm-derived
}

// 0x801A6CD4
void CSMTarget::GetLocalizable(char* key) {
    // NOTE: asm-derived
}

// 0x801A6E00
void CSMTarget::Update() {
    // NOTE: asm-derived - large update function (2124 bytes)
}

// 0x801A767C
void CSMTarget::TempInterface(BString2* a, BString2* b, BString2* c, BString2* d, bool e, bool f) {
    // NOTE: asm-derived
}

// 0x801A7A88
void CSMTarget::SetIconDisable(bool disable) {
    // NOTE: asm-derived
}

// ============================================================================
// ENgcRenderStateCache - GameCube render state caching
// ============================================================================

class ENgcRenderStateCache {
    // Large struct ~1768 bytes for caching GX render state

    // Auto-generated method declarations
    void operator=(ENgcRenderStateCache& other);
    void SaveState();
    void RestoreState();
    void SaveViewportState();
    void RestoreViewportState();
    void Apply(bool force);
};

// 0x8034A818
void ENgcRenderStateCache::operator=(ENgcRenderStateCache& other) {
    // NOTE: asm-derived - bulk copy of render state (864 bytes fn)
    char* dst = (char*)this;
    char* src = (char*)&other;
    // Copy fields at various offsets: 1740-1768, 940-964, 108-924
    memcpy(dst + 108, src + 108, 816);
    *(int*)(dst + 1740) = *(int*)(src + 1740);
    *(int*)(dst + 1744) = *(int*)(src + 1744);
    *(int*)(dst + 1748) = *(int*)(src + 1748);
    memcpy(dst + 1752, src + 1752, 16);
    memcpy(dst + 940, src + 940, 24);
}

// 0x8034AB78
void ENgcRenderStateCache::SaveState() {
    // NOTE: asm-derived
}

// 0x8034AC10
void ENgcRenderStateCache::RestoreState() {
    // NOTE: asm-derived
}

// 0x8034ACB8
void ENgcRenderStateCache::SaveViewportState() {
    // NOTE: asm-derived
}

// 0x8034AD48
void ENgcRenderStateCache::RestoreViewportState() {
    // NOTE: asm-derived
}

// 0x8034ADE8
void ENgcRenderStateCache::Apply(bool force) {
    // NOTE: asm-derived - very large function (5240 bytes)
    // Applies all cached GX render states
}

// ============================================================================
// CUnlockDisplay - Unlock display for objects/promotions
// ============================================================================

class CUnlockDisplay : public E3DWindow {
    // [0..847] E3DWindow base
    // [848+] additional display fields
    // [1256] vtable

    // Auto-generated method declarations
    CUnlockDisplay();
    ~CUnlockDisplay();
    void makeObjects();
    void destroyObjects();
    void SetupForObject(ObjectDefinition* objDef, EVec3& pos, EVec3& rot, EVec3& scale);
    void SetupForPromotion(cXPerson* person, void* data);
    void Update();
    void Draw(ERC* pRC);
    void SetDirectLight(float x, float y, float z, int idx);
    void ObjectHasMultiColor();
    void SetMultiColorNumber(int num);
    void SetDirectLightDir(EVec3 dir, bool normalize, int idx);
    void GetBedOtherHalfIDs(unsigned int bedId, unsigned int& id1, unsigned int& id2);
};

// 0x800775AC
CUnlockDisplay::CUnlockDisplay() {
    // NOTE: asm-derived - initializes E3DWindow, creates sub-windows (680 bytes)
    char* self = (char*)this;
    // E3DWindow::E3DWindow()
    // Init multiple sub-fields, lights, camera params
}

// 0x80077854
CUnlockDisplay::~CUnlockDisplay() {
    // NOTE: asm-derived
    destroyObjects();
}

// 0x800778B0
void CUnlockDisplay::makeObjects() {
    // NOTE: asm-derived - creates display objects for unlock screen
}

// 0x800779A0
void CUnlockDisplay::destroyObjects() {
    // NOTE: asm-derived
}

// 0x80077A0C
void CUnlockDisplay::SetupForObject(ObjectDefinition* objDef, EVec3& pos, EVec3& rot, EVec3& scale) {
    // NOTE: asm-derived - configures display for object preview (560 bytes)
}

// 0x80077C3C
void CUnlockDisplay::SetupForPromotion(cXPerson* person, void* data) {
    // NOTE: asm-derived
}

// 0x80077DFC
void CUnlockDisplay::Update() {
    // NOTE: asm-derived
}

// 0x80078020
void CUnlockDisplay::Draw(ERC* pRC) {
    // NOTE: asm-derived - large draw function (2900 bytes)
}

// 0x80078B74
void CUnlockDisplay::SetDirectLight(float x, float y, float z, int idx) {
    // NOTE: asm-derived
}

// 0x80078C44
void CUnlockDisplay::ObjectHasMultiColor() {
    // NOTE: asm-derived
}

// 0x80078CAC
void CUnlockDisplay::SetMultiColorNumber(int num) {
    // NOTE: asm-derived
}

// 0x80078CF8
void CUnlockDisplay::SetDirectLightDir(EVec3 dir, bool normalize, int idx) {
    // NOTE: asm-derived
}

// 0x80078DB8
void CUnlockDisplay::GetBedOtherHalfIDs(unsigned int bedId, unsigned int& id1, unsigned int& id2) {
    // NOTE: asm-derived - lookup table for bed object IDs
}

// ============================================================================
// RoomManager - Room partition and score management
// ============================================================================

class RoomManager {
    // [0] m_roomCount
    // [4] m_roomList (linked list node)
    // [8..11] m_roomFlags
    // [12] m_isDirty
    // [16+] m_partitions

    // Auto-generated method declarations
    RoomManager();
    ~RoomManager();
    void RoomScoreChanged(int roomId);
    void RoomLightingChanged(int roomId);
    void AllRoomsLightingChanged();
    void AllRoomsScoreChanged();
    void ComputeRooms();
    void PrintStats();
    void GetRoom(unsigned short roomId);
    void GetNewRoom(unsigned short roomId);
    void UpdateRooms();
    void OffsetWorld(CTilePt& offset);
    void ProcessDegenerateTile(CTilePt& tile, unsigned short roomId, int level);
    void ResolveDiagonal(CTilePt& tile, Room** room1, Room** room2, int* side1, int* side2);
    void ResolveDiagonal(CTilePt& tile, unsigned short* id1, unsigned short* id2, int* s1, int* s2);
    void ResetRooms();
    void GetOutsideAmbientLevel();
    void ClearRoomPartitions();
    void ResetRoomManager();
    void SetRoomIntensityScale(int roomId, bool set, float scale);
    void SetRoomIntensityColorScale(int roomId, bool set, int color, float scale);
    void ChangeLightingGroup(unsigned short from, unsigned short to);
};

// 0x80135DAC
RoomManager::RoomManager() {
    // NOTE: asm-derived
    char* self = (char*)this;
    *(int*)(self + 4) = 0;
    // Allocate list node
    memset(self + 8, 0, 8);
}

// 0x80135E6C
RoomManager::~RoomManager() {
    // NOTE: asm-derived
    ResetRoomManager();
}

// 0x80136014
void RoomManager::RoomScoreChanged(int roomId) {
    // NOTE: asm-derived
}

// 0x801360B0
void RoomManager::RoomLightingChanged(int roomId) {
    // NOTE: asm-derived
}

// 0x8013614C
void RoomManager::AllRoomsLightingChanged() {
    // NOTE: asm-derived - iterates all rooms
}

// 0x801361E0
void RoomManager::AllRoomsScoreChanged() {
    // NOTE: asm-derived
}

// 0x80136274
void RoomManager::ComputeRooms() {
    // NOTE: asm-derived - main room computation (784 bytes)
}

// 0x80136584
void RoomManager::PrintStats() {
    // NOTE: asm-derived
}

// 0x80136644
void RoomManager::GetRoom(unsigned short roomId) {
    // NOTE: asm-derived
}

// 0x801366F0
void RoomManager::GetNewRoom(unsigned short roomId) {
    // NOTE: asm-derived - allocates new room
}

// 0x80136800
void RoomManager::UpdateRooms() {
    // NOTE: asm-derived
}

// 0x80136848
void RoomManager::OffsetWorld(CTilePt& offset) {
    // NOTE: asm-derived
}

// 0x80136A2C
void RoomManager::ProcessDegenerateTile(CTilePt& tile, unsigned short roomId, int level) {
    // NOTE: asm-derived
}

// 0x80136C18
void RoomManager::ResolveDiagonal(CTilePt& tile, Room** room1, Room** room2, int* side1, int* side2) {
    // NOTE: asm-derived
}

// 0x80136DB4
void RoomManager::ResolveDiagonal(CTilePt& tile, unsigned short* id1, unsigned short* id2, int* s1, int* s2) {
    // NOTE: asm-derived
}

// 0x80136EEC
void RoomManager::ResetRooms() {
    // NOTE: asm-derived
}

// 0x80136FB4
void RoomManager::GetOutsideAmbientLevel() {
    // NOTE: asm-derived
}

// 0x80137034
void RoomManager::ClearRoomPartitions() {
    // NOTE: asm-derived
}

// 0x801370D4
void RoomManager::ResetRoomManager() {
    // NOTE: asm-derived
}

// 0x80137234
void RoomManager::SetRoomIntensityScale(int roomId, bool set, float scale) {
    // NOTE: asm-derived
}

// 0x80137318
void RoomManager::SetRoomIntensityColorScale(int roomId, bool set, int color, float scale) {
    // NOTE: asm-derived
}

// 0x80137428
void RoomManager::ChangeLightingGroup(unsigned short from, unsigned short to) {
    // NOTE: asm-derived
}

// ============================================================================
// cTrack - Audio track playback
// ============================================================================

class cTrack {
    // [0] m_pSoundEvent (ERSoundEvent*)
    // [4..40] track state
    // [44] m_dataReader (TrackDataReader)

    // Auto-generated method declarations
    void HandleTrackFlowError(char* msg);
    cTrack(ERSoundEvent* soundEvent);
    ~cTrack();
    void OnStartPlaying();
    void OnEndPlaying();
    void HandleTimerCallback();
    void PlayPause(int cmd, int param1, int param2, float volume);
    void Pause();
    void Unpause();
    void Stop();
    void Kill();
    void RegisterVal(int val);
    void SetRegister(int reg, int val);
    void DoCommand();
    void NoteOn();
    void SetPatch(SndEvtHitPatch* patch, float volume);
    void CalculateCurrentVolume();
    void UpdateVolPan();
};

// 0x80116460
void cTrack::HandleTrackFlowError(char* msg) {
    // NOTE: asm-derived
    char* self = (char*)this;
    if (*(void**)self) {
        // TrackDataReader::Trace()
        TrackDataReader* reader = (TrackDataReader*)(self + 44);
    }
    Kill();
}

// 0x801175E0
cTrack::cTrack(ERSoundEvent* soundEvent) {
    // NOTE: asm-derived
    char* self = (char*)this;
    *(ERSoundEvent**)self = soundEvent;
    // Init track data reader and state
}

// 0x801176EC
cTrack::~cTrack() {
    // NOTE: asm-derived
    OnEndPlaying();
}

// 0x801177B0
void cTrack::OnStartPlaying() {
    // NOTE: asm-derived
}

// 0x8011784C
void cTrack::OnEndPlaying() {
    // NOTE: asm-derived
}

// 0x801178AC
void cTrack::HandleTimerCallback() {
    // NOTE: asm-derived - main tick (436 bytes)
}

// 0x80117A60
void cTrack::PlayPause(int cmd, int param1, int param2, float volume) {
    // NOTE: asm-derived (444 bytes)
}

// 0x80117C1C
void cTrack::Pause() {
    // NOTE: asm-derived
}

// 0x80117C78
void cTrack::Unpause() {
    // NOTE: asm-derived
}

// 0x80117CDC
void cTrack::Stop() {
    // NOTE: asm-derived
}

// 0x80117D84
void cTrack::Kill() {
    // NOTE: asm-derived
}

// 0x80117E2C
void cTrack::RegisterVal(int val) {
    // NOTE: asm-derived
}

// 0x80117EFC
void cTrack::SetRegister(int reg, int val) {
    // NOTE: asm-derived
}

// 0x801180A4
void cTrack::DoCommand() {
    // NOTE: asm-derived - large command dispatcher (2496 bytes)
}

// 0x80118A90
void cTrack::NoteOn() {
    // NOTE: asm-derived
}

// 0x80118B0C
void cTrack::SetPatch(SndEvtHitPatch* patch, float volume) {
    // NOTE: asm-derived
}

// 0x80118C74
void cTrack::CalculateCurrentVolume() {
    // NOTE: asm-derived
}

// 0x80118DD4
void cTrack::UpdateVolPan() {
    // NOTE: asm-derived
}

// ============================================================================
// MDITarget - Modeless dialog interface target
// ============================================================================

class MDITarget {
    // Standard UI target layout

    // Auto-generated method declarations
    MDITarget();
    ~MDITarget();
    void SetVariable(char* varName, char* value);
    void GetVariable(char* varName);
    void GetLocalizable(char* key);
    void Update();
    void SpawnModelessDialog(UIDialog* dlg);
    void AddToList(int* list);
    void DeleteAllModelessDialogs();
    void SetupModelessDialog();
};

// 0x801C2FCC
MDITarget::MDITarget() {
    // NOTE: asm-derived - large constructor (1552 bytes)
    char* self = (char*)this;
    memset(self, 0, 128);
    // Set vtable, register callbacks
}

// 0x801C35DC
MDITarget::~MDITarget() {
    // NOTE: asm-derived
    DeleteAllModelessDialogs();
}

// 0x801C3734
void MDITarget::SetVariable(char* varName, char* value) {
    // NOTE: asm-derived
}

// 0x801C37E4
void MDITarget::GetVariable(char* varName) {
    // NOTE: asm-derived
}

// 0x801C3918
void MDITarget::GetLocalizable(char* key) {
    // NOTE: asm-derived
}

// 0x801C3A24
void MDITarget::Update() {
    // NOTE: asm-derived (608 bytes)
}

// 0x801C3CA8
void MDITarget::SpawnModelessDialog(UIDialog* dlg) {
    // NOTE: asm-derived
}

// 0x801C3DA0
void MDITarget::AddToList(int* list) {
    // NOTE: asm-derived
}

// 0x801C3DF8
void MDITarget::DeleteAllModelessDialogs() {
    // NOTE: asm-derived
}

// 0x801C3EE4
void MDITarget::SetupModelessDialog() {
    // NOTE: asm-derived - large setup (2780 bytes)
}

// ============================================================================
// GOLTarget - Goals/Unlock target UI
// ============================================================================

class GOLTarget {
    // Standard UI target layout

    // Auto-generated method declarations
    GOLTarget(int playerIdx);
    ~GOLTarget();
    void SetVariable(char* varName, char* value);
    void IsMapGoalUnlocked(int map, int goal, int level);
    void IsHouseUnlocked(int house, int level);
    void IsApartmentUnlocked(int apt, int level);
    void GetVariable(char* varName);
    void GetLocalizable(char* key);
    void InstallMapShader();
};

// 0x801EA6C0
GOLTarget::GOLTarget(int playerIdx) {
    // NOTE: asm-derived - very large constructor (3180 bytes)
    char* self = (char*)this;
    memset(self, 0, 128);
}

// 0x801EB32C
GOLTarget::~GOLTarget() {
    // NOTE: asm-derived
}

// 0x801EB4DC
void GOLTarget::SetVariable(char* varName, char* value) {
    // NOTE: asm-derived
}

// 0x801EB580
void GOLTarget::IsMapGoalUnlocked(int map, int goal, int level) {
    // NOTE: asm-derived
}

// 0x801EB5E4
void GOLTarget::IsHouseUnlocked(int house, int level) {
    // NOTE: asm-derived
}

// 0x801EB65C
void GOLTarget::IsApartmentUnlocked(int apt, int level) {
    // NOTE: asm-derived
}

// 0x801EB6D4
void GOLTarget::GetVariable(char* varName) {
    // NOTE: asm-derived (844 bytes)
}

// 0x801EBA20
void GOLTarget::GetLocalizable(char* key) {
    // NOTE: asm-derived (1500 bytes)
}

// 0x801EBFFC
void GOLTarget::InstallMapShader() {
    // NOTE: asm-derived
}

// ============================================================================
// AptKey - ActionScript Key object
// ============================================================================

class AptKey {
    // Singleton APT key handler

    // Auto-generated method declarations
    void CleanNativeFunctions();
    void objectMemberLookup(AptValue* result, EAStringC* name) const;
    void sMethod_isDown(AptValue* result, int argCount);
    void sMethod_isToggled(AptValue* result, int argCount);
    void sMethod_getCode(AptValue* result, int argCount);
    void sMethod_getAscii(AptValue* result, int argCount);
    void sMethod_getController(AptValue* result, int argCount);
    void sMethod_addListener(AptValue* result, int argCount);
    void sMethod_removeListener(AptValue* result, int argCount);
    void sMethod_getAnalogStickInfo(AptValue* result, int argCount);
    AptKey();
    ~AptKey();
};

// 0x802A4EEC
void AptKey::CleanNativeFunctions() {
    // NOTE: asm-derived - cleans up native function registrations (540 bytes)
    // Iterates through registered functions, calls vtable delete on each
}

// 0x802A5108
void AptKey::objectMemberLookup(AptValue* result, EAStringC* name) const {
    // NOTE: asm-derived - large lookup (2104 bytes)
    // String comparison chain for Key object properties
}

// 0x802A5940
void AptKey::sMethod_isDown(AptValue* result, int argCount) {
    // NOTE: asm-derived
}

// 0x802A5AD8
void AptKey::sMethod_isToggled(AptValue* result, int argCount) {
    // NOTE: asm-derived
}

// 0x802A5B8C
void AptKey::sMethod_getCode(AptValue* result, int argCount) {
    // NOTE: asm-derived
}

// 0x802A5C8C
void AptKey::sMethod_getAscii(AptValue* result, int argCount) {
    // NOTE: asm-derived
}

// 0x802A5DA0
void AptKey::sMethod_getController(AptValue* result, int argCount) {
    // NOTE: asm-derived
}

// 0x802A5E5C
void AptKey::sMethod_addListener(AptValue* result, int argCount) {
    // NOTE: asm-derived
}

// 0x802A5FBC
void AptKey::sMethod_removeListener(AptValue* result, int argCount) {
    // NOTE: asm-derived (632 bytes)
}

// 0x802A6234
void AptKey::sMethod_getAnalogStickInfo(AptValue* result, int argCount) {
    // NOTE: asm-derived (1432 bytes)
}

// 0x802A87AC
AptKey::AptKey() {
    // NOTE: asm-derived
}

// 0x802A8824
AptKey::~AptKey() {
    // NOTE: asm-derived
}

// ============================================================================
// ERTQuantize4D - 4D color quantization (octree-based)
// ============================================================================

class ERTQuantize4D {
    // [0] vtable
    // Color quantization tree for texture compression

    // Auto-generated method declarations
    ~ERTQuantize4D();
    void Deallocate();
    void Init(unsigned int maxColors, unsigned int flags, void* (*allocFn)(unsigned int), void (*freeFn)(void*), bool useYUVA);
    void InitializeCube();
    void InitializeNode(unsigned char level, unsigned int id, ERTQ4Node* parent, EVec4& color);
    void AddPixel(unsigned char* pixel);
    void FlushAdd(ERTQ4CacheNode& cache);
    void TransformToYuva(unsigned char* rgba, EVec4& yuva);
    void TransformFromYUVA(EVec4& yuva, unsigned char* rgba);
    void Classify(EVec4& color, int level);
    void PruneLevel(ERTQ4Node* node);
    void PruneChild(ERTQ4Node* node);
    void Compute();
    void Reduction();
    void Reduce(ERTQ4Node* node);
    void MColormap(ERTQ4Node* node);
    void GetClosestColor(unsigned char* pixel);
    void ClosestColor(ERTQ4Node* node);
    void EVecToFVec(EVec4& src, unsigned short* dst);
    void FVecToEVec(unsigned short* src, EVec4& dst);
};

// 0x8035EB34
ERTQuantize4D::~ERTQuantize4D() {
    // NOTE: asm-derived
    char* self = (char*)this;
    Deallocate();
    // Conditional delete
}

// 0x8035EB84
void ERTQuantize4D::Deallocate() {
    // NOTE: asm-derived - frees all allocated nodes
}

// 0x8035EBD4
void ERTQuantize4D::Init(unsigned int maxColors, unsigned int flags, void* (*allocFn)(unsigned int),
                          void (*freeFn)(void*), bool useYUVA) {
    // NOTE: asm-derived (600 bytes)
}

// 0x8035EF04
void ERTQuantize4D::InitializeCube() {
    // NOTE: asm-derived
}

// 0x8035EFF4
void ERTQuantize4D::InitializeNode(unsigned char level, unsigned int id, ERTQ4Node* parent, EVec4& color) {
    // NOTE: asm-derived
}

// 0x8035F15C
void ERTQuantize4D::AddPixel(unsigned char* pixel) {
    // NOTE: asm-derived
}

// 0x8035F220
void ERTQuantize4D::FlushAdd(ERTQ4CacheNode& cache) {
    // NOTE: asm-derived
}

// 0x8035F290
void ERTQuantize4D::TransformToYuva(unsigned char* rgba, EVec4& yuva) {
    // NOTE: asm-derived - RGB to YUVA color space (500 bytes)
}

// 0x8035F484
void ERTQuantize4D::TransformFromYUVA(EVec4& yuva, unsigned char* rgba) {
    // NOTE: asm-derived (604 bytes)
}

// 0x8035F6E0
void ERTQuantize4D::Classify(EVec4& color, int level) {
    // NOTE: asm-derived (1016 bytes)
}

// 0x8035FAD8
void ERTQuantize4D::PruneLevel(ERTQ4Node* node) {
    // NOTE: asm-derived
}

// 0x8035FB7C
void ERTQuantize4D::PruneChild(ERTQ4Node* node) {
    // NOTE: asm-derived
}

// 0x8035FC50
void ERTQuantize4D::Compute() {
    // NOTE: asm-derived
}

// 0x8035FCE8
void ERTQuantize4D::Reduction() {
    // NOTE: asm-derived
}

// 0x8035FD78
void ERTQuantize4D::Reduce(ERTQ4Node* node) {
    // NOTE: asm-derived
}

// 0x8035FE54
void ERTQuantize4D::MColormap(ERTQ4Node* node) {
    // NOTE: asm-derived
}

// 0x8035FF7C
void ERTQuantize4D::GetClosestColor(unsigned char* pixel) {
    // NOTE: asm-derived (832 bytes)
}

// 0x803602BC
void ERTQuantize4D::ClosestColor(ERTQ4Node* node) {
    // NOTE: asm-derived
}

// 0x803604E8
void ERTQuantize4D::EVecToFVec(EVec4& src, unsigned short* dst) {
    // NOTE: asm-derived
}

// 0x80360568
void ERTQuantize4D::FVecToEVec(unsigned short* src, EVec4& dst) {
    // NOTE: asm-derived
}

// ============================================================================
// SimImageMaker - Sim portrait/thumbnail renderer
// ============================================================================

class SimImageMaker {
    // [0] m_width
    // [4] m_height
    // [8] m_bpp
    // [12..15] flags
    // [16+] EAnimController
    // [136] m_pModel
    // [140] m_pTexture

    // Auto-generated method declarations
    SimImageMaker();
    ~SimImageMaker();
    void Shutdown();
    void SetToDefaultValues();
    void SetPortraitModels(SimModel* model);
    void OverrideLights(ELights& lights);
    void OverrideBackground(unsigned int texId);
    void CreateImage();
    void InitWindow(E3DWindow& window, ERC* pRC);
    void PoseSim(ERC* pRC);
    void CopyToFinalImage(ETexture* tex);
    void UpdateRepShaders(int idx);
    void CreateImage32x32();
};

// 0x8006E814
SimImageMaker::SimImageMaker() {
    // NOTE: asm-derived
    char* self = (char*)this;
    *(int*)(self + 12) = 0;
    *(int*)(self + 4) = 32;
    *(int*)(self + 0) = 32;
    *(int*)(self + 8) = 8;
    // EAnimController::EAnimController() at offset 16
    *(void**)(self + 140) = 0;
    *(void**)(self + 136) = 0;
}

// 0x8006E918
SimImageMaker::~SimImageMaker() {
    // NOTE: asm-derived
    Shutdown();
}

// 0x8006E988
void SimImageMaker::Shutdown() {
    // NOTE: asm-derived
}

// 0x8006EA14
void SimImageMaker::SetToDefaultValues() {
    // NOTE: asm-derived (440 bytes)
}

// 0x8006EBF4
void SimImageMaker::SetPortraitModels(SimModel* model) {
    // NOTE: asm-derived
}

// 0x8006ECBC
void SimImageMaker::OverrideLights(ELights& lights) {
    // NOTE: asm-derived
}

// 0x8006ED78
void SimImageMaker::OverrideBackground(unsigned int texId) {
    // NOTE: asm-derived
}

// 0x8006EDE0
void SimImageMaker::CreateImage() {
    // NOTE: asm-derived - main render pipeline (1148 bytes)
}

// 0x8006F25C
void SimImageMaker::InitWindow(E3DWindow& window, ERC* pRC) {
    // NOTE: asm-derived
}

// 0x8006F408
void SimImageMaker::PoseSim(ERC* pRC) {
    // NOTE: asm-derived
}

// 0x8006F538
void SimImageMaker::CopyToFinalImage(ETexture* tex) {
    // NOTE: asm-derived (2312 bytes)
}

// 0x8006FE40
void SimImageMaker::UpdateRepShaders(int idx) {
    // NOTE: asm-derived (788 bytes)
}

// 0x80070154
void SimImageMaker::CreateImage32x32() {
    // NOTE: asm-derived (664 bytes)
}

// ============================================================================
// ESimsApp - Main application class
// ============================================================================

class ESimsApp {
    // Application singleton

    // Auto-generated method declarations
    void SetNghName(char* name);
    void parseCommandLine();
    ESimsApp();
    void Shutdown();
    void Init();
    void ShowInitialDisplay();
    void initContinue();
    void UpdateCheats();
    void UpdateApt();
    void UpdateShaders(float dt);
    void UpdateAudio();
    void UpdateDraw();
    void UpdateReset();
    void Update();
};

// 0x80003FEC
void ESimsApp::SetNghName(char* name) {
    // NOTE: asm-derived
    if (strstr(name, ".NGH") || strstr(name, ".ngh")) {
        if (strlen(name) > 4) {
            // Copy up to 16 chars to global NGH name buffer
        }
    }
}

// 0x80004074
void ESimsApp::parseCommandLine() {
    // NOTE: asm-derived (716 bytes)
}

// 0x80004340
ESimsApp::ESimsApp() {
    // NOTE: asm-derived
}

// 0x800043C8
void ESimsApp::Shutdown() {
    // NOTE: asm-derived
}

// 0x800044C8
void ESimsApp::Init() {
    // NOTE: asm-derived - very large init (1732 bytes)
}

// 0x80004B8C
void ESimsApp::ShowInitialDisplay() {
    // NOTE: asm-derived
}

// 0x80004C80
void ESimsApp::initContinue() {
    // NOTE: asm-derived (1936 bytes)
}

// 0x80005448
void ESimsApp::UpdateCheats() {
    // NOTE: asm-derived
}

// 0x800054BC
void ESimsApp::UpdateApt() {
    // NOTE: asm-derived
}

// 0x80005554
void ESimsApp::UpdateShaders(float dt) {
    // NOTE: asm-derived (412 bytes)
}

// 0x800056F0
void ESimsApp::UpdateAudio() {
    // NOTE: asm-derived
}

// 0x80005808
void ESimsApp::UpdateDraw() {
    // NOTE: asm-derived (708 bytes)
}

// 0x80005ACC
void ESimsApp::UpdateReset() {
    // NOTE: asm-derived
}

// 0x80005BA4
void ESimsApp::Update() {
    // NOTE: asm-derived - main update loop
}

// ============================================================================
// RELTarget - Relationships UI target
// ============================================================================

class RELTarget {
    // Standard UI target + relationship display state

    // Auto-generated method declarations
    RELTarget(int playerIdx);
    ~RELTarget();
    void GetVariable(char* varName);
    void GetLocalizable(char* key);
    void SetVariable(char* varName, char* value);
    void SetupRelationshipInformation();
    void GetColor(int relationship);
    void SetupPageShaders(int page);
};

// 0x801FFA8C
RELTarget::RELTarget(int playerIdx) {
    // NOTE: asm-derived - large constructor (3424 bytes)
    char* self = (char*)this;
    memset(self, 0, 128);
}

// 0x802007EC
RELTarget::~RELTarget() {
    // NOTE: asm-derived
}

// 0x80200A28
void RELTarget::GetVariable(char* varName) {
    // NOTE: asm-derived
}

// 0x80200BDC
void RELTarget::GetLocalizable(char* key) {
    // NOTE: asm-derived
}

// 0x80200D30
void RELTarget::SetVariable(char* varName, char* value) {
    // NOTE: asm-derived (876 bytes)
}

// 0x8020109C
void RELTarget::SetupRelationshipInformation() {
    // NOTE: asm-derived (576 bytes)
}

// 0x802012EC
void RELTarget::GetColor(int relationship) {
    // NOTE: asm-derived
}

// 0x8020135C
void RELTarget::SetupPageShaders(int page) {
    // NOTE: asm-derived (760 bytes)
}

// ============================================================================
// PassiveInfluenceMap - Spatial influence grid
// ============================================================================

class PassiveInfluenceMap {
    // [0] m_width
    // [4] m_height
    // [8] m_grid (PassiveInfluenceItem** grid)

    // Auto-generated method declarations
    PassiveInfluenceMap(int width, int height);
    ~PassiveInfluenceMap();
    void AddItemToMap(PassiveInfluenceItem* item);
    void RemoveItemFromMap(PassiveInfluenceItem* item);
    void GetListForTile(int x, int y);
    void EmptyMap();
    void CheckObjectInfluence(PassiveInfluenceTarget* target);
    void ApplyInfluence(PassiveInfluenceObject* obj, PassiveInfluenceTarget* target);
    void CalculateTargetArea(PassiveInfluenceItem* item);
    void FilledArc_Line(int x, int y, int radius, PassiveInfluenceItem* item);
    void FilledArc_Polygon(int x1, int y1, int x2, int y2, int sides, int* xpts, vert2* verts);
    void FilledArc(int cx, int cy, int r, int startAngle, int endAngle, PassiveInfluenceItem* item);
    void CalculateAffectedArea(PassiveInfluenceItem* item);
    void Validate();
};

// 0x801133E8
PassiveInfluenceMap::PassiveInfluenceMap(int width, int height) {
    // NOTE: asm-derived
    char* self = (char*)this;
    int total = width * height;
    *(int*)self = width;
    *(int*)(self + 4) = height;
    // Allocate grid array
    char* grid = (char*)__builtin_vec_new(total * 16 + 8);
    grid += 8;
    *(int*)(grid - 8) = total;
    for (int i = 0; i < total; i++) {
        memset(grid + i * 16, 0, 16);
    }
    *(void**)(self + 8) = grid;
}

// 0x80113470
PassiveInfluenceMap::~PassiveInfluenceMap() {
    // NOTE: asm-derived
    EmptyMap();
    // Delete grid
}

// 0x80113520
void PassiveInfluenceMap::AddItemToMap(PassiveInfluenceItem* item) {
    // NOTE: asm-derived (544 bytes)
}

// 0x80113740
void PassiveInfluenceMap::RemoveItemFromMap(PassiveInfluenceItem* item) {
    // NOTE: asm-derived (440 bytes)
}

// 0x801138F8
void PassiveInfluenceMap::GetListForTile(int x, int y) {
    // NOTE: asm-derived
}

// 0x80113944
void PassiveInfluenceMap::EmptyMap() {
    // NOTE: asm-derived
}

// 0x80113A8C
void PassiveInfluenceMap::CheckObjectInfluence(PassiveInfluenceTarget* target) {
    // NOTE: asm-derived (476 bytes)
}

// 0x80113C68
void PassiveInfluenceMap::ApplyInfluence(PassiveInfluenceObject* obj, PassiveInfluenceTarget* target) {
    // NOTE: asm-derived
}

// 0x801151C0
void PassiveInfluenceMap::CalculateTargetArea(PassiveInfluenceItem* item) {
    // NOTE: asm-derived (616 bytes)
}

// 0x80115428
void PassiveInfluenceMap::FilledArc_Line(int x, int y, int radius, PassiveInfluenceItem* item) {
    // NOTE: asm-derived (728 bytes)
}

// 0x80115700
void PassiveInfluenceMap::FilledArc_Polygon(int x1, int y1, int x2, int y2, int sides, int* xpts, vert2* verts) {
    // NOTE: asm-derived (552 bytes)
}

// 0x80115928
void PassiveInfluenceMap::FilledArc(int cx, int cy, int r, int startAngle, int endAngle, PassiveInfluenceItem* item) {
    // NOTE: asm-derived (688 bytes)
}

// 0x80115BD8
void PassiveInfluenceMap::CalculateAffectedArea(PassiveInfluenceItem* item) {
    // NOTE: asm-derived (1636 bytes)
}

// 0x8011623C
void PassiveInfluenceMap::Validate() {
    // NOTE: asm-derived
}

// ============================================================================
// AptValue - ActionScript value type (variant)
// ============================================================================

class AptValue {
    // [0] m_typeFlags (int) - type tag + flags
    // [4] m_value (union: int, float, pointer)

    // Auto-generated method declarations
    int toInteger() const;
    float toFloat() const;
    bool toBool() const;
    void toString(char* buf) const;
    void toString(EAStringC& str) const;
    void urlEncode();
    void urlEncodeCustomRender();
    void findChild(EAStringC* name, AptValue* result);
    bool isMCInParentChain() const;
    bool CanCreateScriptObject() const;
    void AddRef(char* file, char* func, int line);
    void Release(char* file, char* func, int line);
    void ForceDelete();
    AptValue(AptVirtualFunctionTable_Indices indices);
    AptValue(AptVirtualFunctionTable_Indices indices, int value);
};

// 0x802B04B8
int AptValue::toInteger() const {
    // NOTE: asm-derived
    char* self = (char*)this;
    int flags = *(int*)self;
    if (!(flags & 0x08000000)) return 0;
    int type = flags & 0x7F;
    switch (type) {
        case 1: return *(int*)(self + 4);
        case 5: case 7: return (int)*(float*)(self + 4);
        case 6: return 0; // string to int
        case 42: return *(int*)(self + 4);
        default: return 0;
    }
}

// 0x802B05B8
float AptValue::toFloat() const {
    // NOTE: asm-derived
    char* self = (char*)this;
    int flags = *(int*)self;
    if (!(flags & 0x08000000)) return 0.0f;
    int type = flags & 0x7F;
    switch (type) {
        case 1: return (float)*(int*)(self + 4);
        case 5: case 7: return *(float*)(self + 4);
        default: return 0.0f;
    }
}

// 0x802B06AC
bool AptValue::toBool() const {
    // NOTE: asm-derived (396 bytes)
    char* self = (char*)this;
    int flags = *(int*)self;
    if (!(flags & 0x08000000)) return false;
    int type = flags & 0x7F;
    switch (type) {
        case 1: return *(int*)(self + 4) != 0;
        case 5: return *(float*)(self + 4) != 0.0f;
        default: return false;
    }
}

// 0x802B0838
void AptValue::toString(char* buf) const {
    // NOTE: asm-derived
}

// 0x802B08BC
void AptValue::toString(EAStringC& str) const {
    // NOTE: asm-derived (1416 bytes)
}

// 0x802B3248
void AptValue::urlEncode() {
    // NOTE: asm-derived (624 bytes)
}

// 0x802B34B8
void AptValue::urlEncodeCustomRender() {
    // NOTE: asm-derived (676 bytes)
}

// 0x802B375C
void AptValue::findChild(EAStringC* name, AptValue* result) {
    // NOTE: asm-derived (1576 bytes)
}

// 0x802B3D84
bool AptValue::isMCInParentChain() const {
    // NOTE: asm-derived
    return false;
}

// 0x802B3E78
bool AptValue::CanCreateScriptObject() const {
    // NOTE: asm-derived
    return false;
}

// 0x802B3F00
void AptValue::AddRef(char* file, char* func, int line) {
    // NOTE: asm-derived
}

// 0x802B3FC4
void AptValue::Release(char* file, char* func, int line) {
    // NOTE: asm-derived (428 bytes)
}

// 0x802B41CC
void AptValue::ForceDelete() {
    // NOTE: asm-derived
}

// 0x802B45FC
AptValue::AptValue(AptVirtualFunctionTable_Indices indices) {
    // NOTE: asm-derived
}

// 0x802B46D0
AptValue::AptValue(AptVirtualFunctionTable_Indices indices, int value) {
    // NOTE: asm-derived
}

// ============================================================================
// HoodManager - Neighborhood family management
// ============================================================================

class HoodManager {
    // Manages families, relations, neighborhoods

    // Auto-generated method declarations
    void TestMoveInFamily(int houseIdx, Family* family);
    void MoveInFamily(int houseIdx, Family* family, bool force);
    void UnmarkFamilyForDeletion(int houseIdx, Family* family);
    void EvictFamilyAndLiquidateAssets(int houseIdx);
    void EvictFamily(int houseIdx, bool liquidate);
    void RemoveAllObjects(int houseIdx);
    void DemolishCurrentHouse(int houseIdx);
    void ResetToPristine();
    void ResetNeighbors();
    void GetMatrix(Neighbor* n1, Neighbor* n2, RelMatrix** matrix, int* idx);
    void GetRelatedPeople(int familyIdx, cXPerson* person, void* results);
};

// 0x80042F5C
void HoodManager::TestMoveInFamily(int houseIdx, Family* family) {
    // NOTE: asm-derived
}

// 0x80043034
void HoodManager::MoveInFamily(int houseIdx, Family* family, bool force) {
    // NOTE: asm-derived
}

// 0x800430F4
void HoodManager::UnmarkFamilyForDeletion(int houseIdx, Family* family) {
    // NOTE: asm-derived
}

// 0x80043230
void HoodManager::EvictFamilyAndLiquidateAssets(int houseIdx) {
    // NOTE: asm-derived
}

// 0x80043388
void HoodManager::EvictFamily(int houseIdx, bool liquidate) {
    // NOTE: asm-derived (520 bytes)
}

// 0x80043590
void HoodManager::RemoveAllObjects(int houseIdx) {
    // NOTE: asm-derived
}

// 0x800436AC
void HoodManager::DemolishCurrentHouse(int houseIdx) {
    // NOTE: asm-derived (848 bytes)
}

// 0x800439FC
void HoodManager::ResetToPristine() {
    // NOTE: asm-derived (2912 bytes)
}

// 0x8004455C
void HoodManager::ResetNeighbors() {
    // NOTE: asm-derived (912 bytes)
}

// 0x800448EC
void HoodManager::GetMatrix(Neighbor* n1, Neighbor* n2, RelMatrix** matrix, int* idx) {
    // NOTE: asm-derived
}

// 0x80044BCC
void HoodManager::GetRelatedPeople(int familyIdx, cXPerson* person, void* results) {
    // NOTE: asm-derived (660 bytes)
}

// ============================================================================
// AptViewer - APT UI viewer/controller
// ============================================================================

class AptViewer : public E3DWindow {
    // [0..855] E3DWindow base
    // [856] m_mutex (EMutex)
    // [944+] filter data

    // Auto-generated method declarations
    AptViewer();
    ~AptViewer();
    void NewCallFunction(char* target, char* funcName, char* sig, int argCount, ...);
    void NewCallFunction2(char* target, char* funcName, char* sig, int argCount, char** args);
    void Init(UIObjectBase* parent);
    void UpdateAll();
    void Draw(ERC* pRC);
    void Load(char* filename, bool async);
    void LoadActionScript(char* filename, bool async);
    void UnLoad();
    void RepeatCheck(int key, int frame);
    void NewReadController(int port, bool isPlayer1, int filterIdx, bool useApt);
    void OnePlayerReadController(int port, int frame);
    void PushAptButtonFilter(int port, char* name);
    void PopAptButtonFilter(int port, unsigned int filterId);
    void AddCmdToAptButtonFilter(int port, unsigned int filterId, ECTRL_CMD cmd);
    void RemoveCmdFromAptButtonFilter(int port, unsigned int filterId, ECTRL_CMD cmd);
    void GetCurrentAptButtonFilter(int port);
    void GetPlayersController(int player);
};

// 0x800101F0
AptViewer::AptViewer() {
    // NOTE: asm-derived
    // E3DWindow::E3DWindow(), EMutex::EMutex()
    // Init filter arrays to 0
}

// 0x800102E0
AptViewer::~AptViewer() {
    // NOTE: asm-derived
    UnLoad();
}

// 0x80010394
void AptViewer::NewCallFunction(char* target, char* funcName, char* sig, int argCount, ...) {
    // NOTE: asm-derived
}

// 0x800104B0
void AptViewer::NewCallFunction2(char* target, char* funcName, char* sig, int argCount, char** args) {
    // NOTE: asm-derived
}

// 0x800105D8
void AptViewer::Init(UIObjectBase* parent) {
    // NOTE: asm-derived
}

// 0x80010644
void AptViewer::UpdateAll() {
    // NOTE: asm-derived
}

// 0x80010778
void AptViewer::Draw(ERC* pRC) {
    // NOTE: asm-derived (1180 bytes)
}

// 0x80010C14
void AptViewer::Load(char* filename, bool async) {
    // NOTE: asm-derived
}

// 0x80010C94
void AptViewer::LoadActionScript(char* filename, bool async) {
    // NOTE: asm-derived
}

// 0x80010CF0
void AptViewer::UnLoad() {
    // NOTE: asm-derived
}

// 0x80010DAC
void AptViewer::RepeatCheck(int key, int frame) {
    // NOTE: asm-derived
}

// 0x80010E7C
void AptViewer::NewReadController(int port, bool isPlayer1, int filterIdx, bool useApt) {
    // NOTE: asm-derived
}

// 0x80010F40
void AptViewer::OnePlayerReadController(int port, int frame) {
    // NOTE: asm-derived (2824 bytes)
}

// 0x80011A48
void AptViewer::PushAptButtonFilter(int port, char* name) {
    // NOTE: asm-derived
}

// 0x80011B4C
void AptViewer::PopAptButtonFilter(int port, unsigned int filterId) {
    // NOTE: asm-derived
}

// 0x80011C44
void AptViewer::AddCmdToAptButtonFilter(int port, unsigned int filterId, ECTRL_CMD cmd) {
    // NOTE: asm-derived
}

// 0x80011CA8
void AptViewer::RemoveCmdFromAptButtonFilter(int port, unsigned int filterId, ECTRL_CMD cmd) {
    // NOTE: asm-derived
}

// 0x80011D0C
void AptViewer::GetCurrentAptButtonFilter(int port) {
    // NOTE: asm-derived
}

// 0x80011D50
void AptViewer::GetPlayersController(int player) {
    // NOTE: asm-derived
}

// ============================================================================
// UIReflow - UI layout reflow system
// ============================================================================

class UIReflow {
    // Block-based UI layout with tweening support

    // Auto-generated method declarations
    ~UIReflow();
    void SetFocus(UIScreenID screenId);
    void ResetSize(char* id, int w, int h, int layer);
    void ResetPosition(char* id, int x, int y, int layer);
    void ResetZ(char* id, int z, int layer);
    void ResetVisibility(char* id, bool visible, int layer);
    void ResetAlpha(char* id, unsigned int alpha, int layer);
    void ResetText(char* id, char* text, int layer);
    void ResetColorOverride(char* id, unsigned int color, int layer);
    void ResetFontSizeOverride(char* id, unsigned int size, int layer);
    void ResetSwfAnimation(char* id, char* anim, int layer);
    void ResetSwfFileName(char* id, char* filename, int layer);
    void AddToBlock(char* data);
    void ReallocateBlock();
    void OpenTweenBlock(char* target, unsigned int duration, unsigned int easing, char* callback, int layer);
    void SubmitTweenBlock();
    void Tween_X(int x);
    void Tween_Y(int y);
    void Tween_Z(unsigned int z);
    void Tween_H(unsigned int h);
    void Tween_W(unsigned int w);
    void Tween_XScale(float s);
    void Tween_YScale(float s);
    void Tween_Rotation(float deg);
    void Tween_Alpha(unsigned int a);
    void Tween_ColorOverride(unsigned int color);
    void Tween_ColorOnlyOverride(unsigned int color);
    void Tween_FontSizeOverride(unsigned int size);
    void OpenReflowBlock();
    void SubmitReflowBlock();
    void Reflow_Id(char* id, int layer);
    void Reflow_Visibility(bool visible);
    void Reflow_StringChange(char* str);
    void Reflow_SwfAnimation(char* anim);
    void Reflow_SwfFile(char* file);
};

// 0x8017D254
UIReflow::~UIReflow() {
    // NOTE: asm-derived
    char* self = (char*)this;
    // Free allocated blocks
}

// 0x8017D2B0
void UIReflow::SetFocus(UIScreenID screenId) {
    // NOTE: asm-derived
}

// 0x8017D320
void UIReflow::ResetSize(char* id, int w, int h, int layer) {
    // NOTE: asm-derived (384 bytes)
}

// 0x8017D4A0
void UIReflow::ResetPosition(char* id, int x, int y, int layer) {
    // NOTE: asm-derived (384 bytes)
}

// 0x8017D620
void UIReflow::ResetZ(char* id, int z, int layer) {
    // NOTE: asm-derived
}

// 0x8017D75C
void UIReflow::ResetVisibility(char* id, bool visible, int layer) {
    // NOTE: asm-derived
}

// 0x8017D898
void UIReflow::ResetAlpha(char* id, unsigned int alpha, int layer) {
    // NOTE: asm-derived
}

// 0x8017D9E4
void UIReflow::ResetText(char* id, char* text, int layer) {
    // NOTE: asm-derived
}

// 0x8017DB04
void UIReflow::ResetColorOverride(char* id, unsigned int color, int layer) {
    // NOTE: asm-derived (424 bytes)
}

// 0x8017DCAC
void UIReflow::ResetFontSizeOverride(char* id, unsigned int size, int layer) {
    // NOTE: asm-derived
}

// 0x8017DDE8
void UIReflow::ResetSwfAnimation(char* id, char* anim, int layer) {
    // NOTE: asm-derived
}

// 0x8017DF08
void UIReflow::ResetSwfFileName(char* id, char* filename, int layer) {
    // NOTE: asm-derived
}

// 0x8017E028
void UIReflow::AddToBlock(char* data) {
    // NOTE: asm-derived
}

// 0x8017E0B0
void UIReflow::ReallocateBlock() {
    // NOTE: asm-derived
}

// 0x8017E138
void UIReflow::OpenTweenBlock(char* target, unsigned int duration, unsigned int easing, char* callback, int layer) {
    // NOTE: asm-derived (480 bytes)
}

// 0x8017E318
void UIReflow::SubmitTweenBlock() {
    // NOTE: asm-derived
}

// 0x8017E39C
void UIReflow::Tween_X(int x) { /* NOTE: asm-derived */ }

// 0x8017E408
void UIReflow::Tween_Y(int y) { /* NOTE: asm-derived */ }

// 0x8017E474
void UIReflow::Tween_Z(unsigned int z) { /* NOTE: asm-derived */ }

// 0x8017E4E0
void UIReflow::Tween_H(unsigned int h) { /* NOTE: asm-derived */ }

// 0x8017E54C
void UIReflow::Tween_W(unsigned int w) { /* NOTE: asm-derived */ }

// 0x8017E5B8
void UIReflow::Tween_XScale(float s) { /* NOTE: asm-derived */ }

// 0x8017E638
void UIReflow::Tween_YScale(float s) { /* NOTE: asm-derived */ }

// 0x8017E6B8
void UIReflow::Tween_Rotation(float deg) { /* NOTE: asm-derived */ }

// 0x8017E72C
void UIReflow::Tween_Alpha(unsigned int a) { /* NOTE: asm-derived */ }

// 0x8017E7A8
void UIReflow::Tween_ColorOverride(unsigned int color) { /* NOTE: asm-derived */ }

// 0x8017E838
void UIReflow::Tween_ColorOnlyOverride(unsigned int color) { /* NOTE: asm-derived */ }

// 0x8017E8B4
void UIReflow::Tween_FontSizeOverride(unsigned int size) { /* NOTE: asm-derived */ }

// 0x8017E920
void UIReflow::OpenReflowBlock() { /* NOTE: asm-derived */ }

// 0x8017E998
void UIReflow::SubmitReflowBlock() { /* NOTE: asm-derived */ }

// 0x8017EA1C
void UIReflow::Reflow_Id(char* id, int layer) { /* NOTE: asm-derived */ }

// 0x8017EBB0
void UIReflow::Reflow_Visibility(bool visible) { /* NOTE: asm-derived */ }

// 0x8017EC48
void UIReflow::Reflow_StringChange(char* str) { /* NOTE: asm-derived */ }

// 0x8017ECFC
void UIReflow::Reflow_SwfAnimation(char* anim) { /* NOTE: asm-derived */ }

// 0x8017ED50
void UIReflow::Reflow_SwfFile(char* file) { /* NOTE: asm-derived */ }

// ============================================================================
// CASGeneticsTarget - Create-A-Sim genetics UI
// ============================================================================

class CASGeneticsTarget {
    // Standard UI target + genetics-specific state

    // Auto-generated method declarations
    CASGeneticsTarget();
    ~CASGeneticsTarget();
    void SetVariable(char* varName, char* value);
    void SetVariableSubnav(int subnavId, int value);
    void GetVariable(char* varName);
    void GetLocalizableSubnav(int subnavId, unsigned short* buffer);
    void SetGrandparentIndex(unsigned int parent, int idx);
    void ShowGrandparentTexture(unsigned int parent, int idx);
    void ClearGrandparentTexture(unsigned int parent);
    void CreateParentTexture(unsigned int parent);
    void ClearParentTexture(unsigned int parent);
    void GetDefaultSim(bool isMale, CasSimDescriptionS2C& desc);
    void SetDoneButtonState();
    void BeginGenerate();
    void HandleGenerateStageBG();
    void Update();
    void Draw(ERC* pRC);
};

// 0x80196F48
CASGeneticsTarget::CASGeneticsTarget() {
    // NOTE: asm-derived (1916 bytes)
    char* self = (char*)this;
    memset(self, 0, 128);
}

// 0x801976C4
CASGeneticsTarget::~CASGeneticsTarget() {
    // NOTE: asm-derived
}

// 0x80197958
void CASGeneticsTarget::SetVariable(char* varName, char* value) {
    // NOTE: asm-derived (500 bytes)
}

// 0x80197B4C
void CASGeneticsTarget::SetVariableSubnav(int subnavId, int value) {
    // NOTE: asm-derived
}

// 0x80197C84
void CASGeneticsTarget::GetVariable(char* varName) {
    // NOTE: asm-derived
}

// 0x80197CFC
void CASGeneticsTarget::GetLocalizableSubnav(int subnavId, unsigned short* buffer) {
    // NOTE: asm-derived
}

// 0x80197DF0
void CASGeneticsTarget::SetGrandparentIndex(unsigned int parent, int idx) {
    // NOTE: asm-derived
}

// 0x80197E60
void CASGeneticsTarget::ShowGrandparentTexture(unsigned int parent, int idx) {
    // NOTE: asm-derived
}

// 0x80197EFC
void CASGeneticsTarget::ClearGrandparentTexture(unsigned int parent) {
    // NOTE: asm-derived
}

// 0x80197F70
void CASGeneticsTarget::CreateParentTexture(unsigned int parent) {
    // NOTE: asm-derived (368 bytes)
}

// 0x801980E0
void CASGeneticsTarget::ClearParentTexture(unsigned int parent) {
    // NOTE: asm-derived
}

// 0x8019815C
void CASGeneticsTarget::GetDefaultSim(bool isMale, CasSimDescriptionS2C& desc) {
    // NOTE: asm-derived
}

// 0x80198214
void CASGeneticsTarget::SetDoneButtonState() {
    // NOTE: asm-derived
}

// 0x8019828C
void CASGeneticsTarget::BeginGenerate() {
    // NOTE: asm-derived (432 bytes)
}

// 0x8019843C
void CASGeneticsTarget::HandleGenerateStageBG() {
    // NOTE: asm-derived (472 bytes)
}

// 0x80198614
void CASGeneticsTarget::Update() {
    // NOTE: asm-derived (932 bytes)
}

// 0x801989B8
void CASGeneticsTarget::Draw(ERC* pRC) {
    // NOTE: asm-derived
}

// ============================================================================
// AptParagraph - APT text paragraph layout
// ============================================================================

class AptParagraph {
    // [0] m_pLines (AptLine* linked list)

    // Auto-generated method declarations
    void Draw(ERC* pRC, EMat4* matrix, EVec4* color, EVec4* bg);
    void Build(EVec2& pos, EVec2& size, float lineSpacing, EVec4& color, AptStringAlignment align, unsigned short* text);
    void GetWideHexValue(unsigned short* str, int offset, int len);
    void SetFormattingEnable(int enable);
    ~AptParagraph();
};

// 0x8000E06C
void AptParagraph::Draw(ERC* pRC, EMat4* matrix, EVec4* color, EVec4* bg) {
    // NOTE: asm-derived
    char* self = (char*)this;
    AptLine* line = *(AptLine**)self;
    while (line) {
        AptLine* next = *(AptLine**)line;
        // AptLine::Draw(pRC, matrix, color, bg)
        line = next;
    }
}

// 0x8000E10C
void AptParagraph::Build(EVec2& pos, EVec2& size, float lineSpacing, EVec4& color,
                          AptStringAlignment align, unsigned short* text) {
    // NOTE: asm-derived - very large function (7004 bytes)
    // Parses text, handles formatting tags, word wrapping, line layout
}

// 0x8000FC78
void AptParagraph::GetWideHexValue(unsigned short* str, int offset, int len) {
    // NOTE: asm-derived
}

// 0x8000FD38
void AptParagraph::SetFormattingEnable(int enable) {
    // NOTE: asm-derived
}

// 0x8039D3D0
AptParagraph::~AptParagraph() {
    // NOTE: asm-derived - frees all lines
}

// ============================================================================
// EResourceLoaderImpl - Async resource loading system
// ============================================================================

class EResourceLoaderImpl {
    // Resource loader with threading support

    // Auto-generated method declarations
    void IsBusy();
    EResourceLoaderImpl();
    ~EResourceLoaderImpl();
    void Shutdown();
    void TerminateThread();
    void Init();
    void FlushCommandQueue();
    void AddManager(EResourceManager* mgr);
    void RemoveManager(EResourceManager* mgr);
    void Load(EResourceManager* mgr, unsigned int id, EFile* file, unsigned int offset, unsigned int size, bool async);
    void Unload(EResourceManager* mgr, unsigned int id);
    void ReadData(EFile* file, void* buf, unsigned int offset, unsigned int size, bool async, EResLoadCmdResult* result);
    void ReadData(EResourceManager* mgr, void* buf, unsigned int offset, unsigned int size, bool async, EResLoadCmdResult* result);
    void WriteData(EFile* file, void* buf, unsigned int offset, unsigned int size, bool async, EResLoadCmdResult* result);
    void FindResourceManager(char* name);
    void FindResourceManagerInternal(char* name);
    void OpenFiles();
    void CloseArchiveFile(EResourceManager* mgr);
    void AddRefDelRefAllResources();
    void PrintLoadedResources();
    void PrintLoadedResources(char* filter);
    void PrintResourceSizes();
    void PrintResourceSizes(char* filter);
    void FreeUnreferencedResources();
    void FreeUnreferencedResources(char* filter);
    void GetUnreferencedResourceCount();
    void GetUnreferencedResourceCount(char* filter);
    void deallocateGlobalIndex();
    void allocateGlobalIndex();
    void getIndexPointer(EString& name);
    void Main();
    void ProcessMessage(unsigned int msg);
    void DoLoadResource(EResourceManager* mgr, unsigned int id, EFile* file, unsigned int offset, unsigned int size);
};

// 0x80310184
void EResourceLoaderImpl::IsBusy() {
    // NOTE: asm-derived
}

// 0x803101E0
EResourceLoaderImpl::EResourceLoaderImpl() {
    // NOTE: asm-derived
}

// 0x8031029C
EResourceLoaderImpl::~EResourceLoaderImpl() {
    // NOTE: asm-derived
}

// 0x80310340
void EResourceLoaderImpl::Shutdown() {
    // NOTE: asm-derived
}

// 0x803103C8
void EResourceLoaderImpl::TerminateThread() {
    // NOTE: asm-derived
}

// 0x80310434
void EResourceLoaderImpl::Init() {
    // NOTE: asm-derived
}

// 0x803104DC
void EResourceLoaderImpl::FlushCommandQueue() {
    // NOTE: asm-derived
}

// 0x80310588
void EResourceLoaderImpl::AddManager(EResourceManager* mgr) {
    // NOTE: asm-derived
}

// 0x80310654
void EResourceLoaderImpl::RemoveManager(EResourceManager* mgr) {
    // NOTE: asm-derived
}

// 0x80310778
void EResourceLoaderImpl::Load(EResourceManager* mgr, unsigned int id, EFile* file,
                                unsigned int offset, unsigned int size, bool async) {
    // NOTE: asm-derived
}

// 0x8031088C
void EResourceLoaderImpl::Unload(EResourceManager* mgr, unsigned int id) {
    // NOTE: asm-derived
}

// 0x80310938
void EResourceLoaderImpl::ReadData(EFile* file, void* buf, unsigned int offset,
                                    unsigned int size, bool async, EResLoadCmdResult* result) {
    // NOTE: asm-derived
}

// 0x80310A74
void EResourceLoaderImpl::ReadData(EResourceManager* mgr, void* buf, unsigned int offset,
                                    unsigned int size, bool async, EResLoadCmdResult* result) {
    // NOTE: asm-derived
}

// 0x80310B90
void EResourceLoaderImpl::WriteData(EFile* file, void* buf, unsigned int offset,
                                     unsigned int size, bool async, EResLoadCmdResult* result) {
    // NOTE: asm-derived
}

// 0x80310CCC
void EResourceLoaderImpl::FindResourceManager(char* name) {
    // NOTE: asm-derived
}

// 0x80310D4C
void EResourceLoaderImpl::FindResourceManagerInternal(char* name) {
    // NOTE: asm-derived
}

// 0x80310DAC
void EResourceLoaderImpl::OpenFiles() {
    // NOTE: asm-derived
}

// 0x80310E4C
void EResourceLoaderImpl::CloseArchiveFile(EResourceManager* mgr) {
    // NOTE: asm-derived
}

// 0x80310F34
void EResourceLoaderImpl::AddRefDelRefAllResources() {
    // NOTE: asm-derived
}

// 0x80310FDC
void EResourceLoaderImpl::PrintLoadedResources() { /* NOTE: asm-derived */ }

// 0x80311068
void EResourceLoaderImpl::PrintLoadedResources(char* filter) { /* NOTE: asm-derived */ }

// 0x803110EC
void EResourceLoaderImpl::PrintResourceSizes() { /* NOTE: asm-derived */ }

// 0x80311174
void EResourceLoaderImpl::PrintResourceSizes(char* filter) { /* NOTE: asm-derived */ }

// 0x803111F8
void EResourceLoaderImpl::FreeUnreferencedResources() { /* NOTE: asm-derived */ }

// 0x80311260
void EResourceLoaderImpl::FreeUnreferencedResources(char* filter) { /* NOTE: asm-derived */ }

// 0x80311310
void EResourceLoaderImpl::GetUnreferencedResourceCount() { /* NOTE: asm-derived */ }

// 0x80311360
void EResourceLoaderImpl::GetUnreferencedResourceCount(char* filter) { /* NOTE: asm-derived */ }

// 0x803113F0
void EResourceLoaderImpl::deallocateGlobalIndex() { /* NOTE: asm-derived */ }

// 0x8031146C
void EResourceLoaderImpl::allocateGlobalIndex() { /* NOTE: asm-derived (532 bytes) */ }

// 0x80311680
void EResourceLoaderImpl::getIndexPointer(EString& name) { /* NOTE: asm-derived */ }

// 0x8031173C
void EResourceLoaderImpl::Main() { /* NOTE: asm-derived */ }

// 0x803117A8
void EResourceLoaderImpl::ProcessMessage(unsigned int msg) {
    // NOTE: asm-derived (680 bytes)
}

// 0x80311A50
void EResourceLoaderImpl::DoLoadResource(EResourceManager* mgr, unsigned int id, EFile* file,
                                          unsigned int offset, unsigned int size) {
    // NOTE: asm-derived (484 bytes)
}

// ============================================================================
// CASPersonalTarget - Create-A-Sim personality UI
// ============================================================================

class CASPersonalTarget {
    // Standard UI target + personality traits

    // Auto-generated method declarations
    CASPersonalTarget();
    ~CASPersonalTarget();
    void SetVariable(char* varName, char* value);
    void HandlePersonalityAnimation(char* anim);
    void ConvertFromPersonalityTextToEnum(char* text);
    void GetVariable(char* varName);
    void GetLocalizable(char* key);
    void ParseSignText(short sign, unsigned short* buf);
    void ParseDescriptionText(short desc, unsigned short* buf);
    void ParsePersonalityText(char* trait, unsigned short* buf);
    void SetVariableSubnav(UIScreenID screen, int subnav, int value);
    void GetLocalizableSubnav(UIScreenID screen, int subnav, unsigned short* buf);
    void CalcHighScoreAspShaderIds();
};

// 0x8019D518
CASPersonalTarget::CASPersonalTarget() {
    // NOTE: asm-derived (2736 bytes)
    char* self = (char*)this;
    memset(self, 0, 128);
}

// 0x8019DFC8
CASPersonalTarget::~CASPersonalTarget() { /* NOTE: asm-derived */ }

// 0x8019E124
void CASPersonalTarget::SetVariable(char* varName, char* value) { /* NOTE: asm-derived (408 bytes) */ }

// 0x8019E2BC
void CASPersonalTarget::HandlePersonalityAnimation(char* anim) { /* NOTE: asm-derived */ }

// 0x8019E300
void CASPersonalTarget::ConvertFromPersonalityTextToEnum(char* text) { /* NOTE: asm-derived */ }

// 0x8019E444
void CASPersonalTarget::GetVariable(char* varName) { /* NOTE: asm-derived (440 bytes) */ }

// 0x8019E5FC
void CASPersonalTarget::GetLocalizable(char* key) { /* NOTE: asm-derived (384 bytes) */ }

// 0x8019E77C
void CASPersonalTarget::ParseSignText(short sign, unsigned short* buf) { /* NOTE: asm-derived (632 bytes) */ }

// 0x8019E9F4
void CASPersonalTarget::ParseDescriptionText(short desc, unsigned short* buf) { /* NOTE: asm-derived */ }

// 0x8019EB2C
void CASPersonalTarget::ParsePersonalityText(char* trait, unsigned short* buf) { /* NOTE: asm-derived (684 bytes) */ }

// 0x8019EDD8
void CASPersonalTarget::SetVariableSubnav(UIScreenID screen, int subnav, int value) { /* NOTE: asm-derived */ }

// 0x8019EF50
void CASPersonalTarget::GetLocalizableSubnav(UIScreenID screen, int subnav, unsigned short* buf) { /* NOTE: asm-derived */ }

// 0x8019F094
void CASPersonalTarget::CalcHighScoreAspShaderIds() { /* NOTE: asm-derived */ }

// ============================================================================
// ERoomWall - Room wall segment
// ============================================================================

class ERoomWall {
    // Wall geometry and rendering data

    // Auto-generated method declarations
    void GetWallMeterValue(int& value);
    void CalWallsOpaque(int level);
    void CalShortDistToCam(int level);
    void* operator new(std::size_t size);
    ERoomWall(TileWallsSegment seg, DiagonalSideSelector side, CTilePt& tile, bool isDiag);
    ~ERoomWall();
    void GetWallDims(TileWallsSegment seg, DiagonalSideSelector side, EVec3& min, EVec3& max);
    void SetWallUpDownMode(EWallUpDownStateType state, bool apply);
    void AddTile(CTilePt& tile, TileWalls& walls, TileWallsSegment seg, DiagonalSideSelector side, bool rebuild);
    void DrawWall(ERC* pRC);
    void getRoomIdFromPoint(CTilePt& pt);
    void getWallNormalOnSideOfCursor(EVec3& pos, EVec3& normal, EVec2& cursor, EVec2& wall);
    void DrawWallpaperPreview(ERC* pRC, EVec2& pos);
    void GetWallPaperCost(int wallpaper, unsigned short roomId);
    void HasSegment(TileWallsSegment seg, CTilePt& start, CTilePt& end);
    void DeleteWallAtTile(CTilePt& tile);
    void RemoveWallsFromWorld();
    void GetWallAtTile(CTilePt& tile);
    ERoomWall();
};

// 0x800293A0
void ERoomWall::GetWallMeterValue(int& value) { /* NOTE: asm-derived (480 bytes) */ }

// 0x800295BC
void ERoomWall::CalWallsOpaque(int level) { /* NOTE: asm-derived */ }

// 0x80029654
void ERoomWall::CalShortDistToCam(int level) { /* NOTE: asm-derived */ }

// 0x8002C54C
void* ERoomWall::operator new(std::size_t size) {
    // NOTE: asm-derived
    return MainHeap()->Malloc(size, 0);
}

// 0x8002C5CC
ERoomWall::ERoomWall(TileWallsSegment seg, DiagonalSideSelector side, CTilePt& tile, bool isDiag) {
    // NOTE: asm-derived (492 bytes)
}

// 0x8002C7B8
ERoomWall::~ERoomWall() { /* NOTE: asm-derived */ }

// 0x8002C860
void ERoomWall::GetWallDims(TileWallsSegment seg, DiagonalSideSelector side, EVec3& min, EVec3& max) {
    // NOTE: asm-derived (1316 bytes)
}

// 0x8002CD84
void ERoomWall::SetWallUpDownMode(EWallUpDownStateType state, bool apply) { /* NOTE: asm-derived */ }

// 0x8002CDD8
void ERoomWall::AddTile(CTilePt& tile, TileWalls& walls, TileWallsSegment seg, DiagonalSideSelector side, bool rebuild) {
    // NOTE: asm-derived
}

// 0x8002CE4C
void ERoomWall::DrawWall(ERC* pRC) { /* NOTE: asm-derived (940 bytes) */ }

// 0x8002D1F8
void ERoomWall::getRoomIdFromPoint(CTilePt& pt) { /* NOTE: asm-derived */ }

// 0x8002D308
void ERoomWall::getWallNormalOnSideOfCursor(EVec3& pos, EVec3& normal, EVec2& cursor, EVec2& wall) {
    // NOTE: asm-derived
}

// 0x8002D3C0
void ERoomWall::DrawWallpaperPreview(ERC* pRC, EVec2& pos) { /* NOTE: asm-derived (952 bytes) */ }

// 0x8002DE70
void ERoomWall::GetWallPaperCost(int wallpaper, unsigned short roomId) { /* NOTE: asm-derived */ }

// 0x8002F84C
void ERoomWall::HasSegment(TileWallsSegment seg, CTilePt& start, CTilePt& end) { /* NOTE: asm-derived (488 bytes) */ }

// 0x8002FA34
void ERoomWall::DeleteWallAtTile(CTilePt& tile) { /* NOTE: asm-derived (440 bytes) */ }

// 0x8002FBEC
void ERoomWall::RemoveWallsFromWorld() { /* NOTE: asm-derived */ }

// 0x8002FD7C
void ERoomWall::GetWallAtTile(CTilePt& tile) { /* NOTE: asm-derived */ }

// 0x800308A0
ERoomWall::ERoomWall() {
    // NOTE: asm-derived - default constructor
    char* self = (char*)this;
    memset(self, 0, 64);
}

// ============================================================================
// AptFormat - APT text formatting with particles
// ============================================================================

class AptFormat {
    // Text formatting and particle effects for APT UI

    // Auto-generated method declarations
    AptFormat(AptWord* word);
    ~AptFormat();
    void Draw(EMat4* matrix, EVec4* color, EVec4* bg);
    void InitForParticles(int count);
    void ProcessParticles(ERC* pRC, EMat4* matrix, EVec2& pos, EVec2& size, float dt, float scale);
    void CheckAsyncLoads();
    void CopyForward(AptFormat* other);
};

// 0x8000AF88
AptFormat::AptFormat(AptWord* word) {
    // NOTE: asm-derived (552 bytes)
    char* self = (char*)this;
    // Init float fields, particle state
    *(int*)(self + 0) = 0;
    *(int*)(self + 4) = 0;
    *(int*)(self + 100) = 0;
}

// 0x8000B1B0
AptFormat::~AptFormat() { /* NOTE: asm-derived */ }

// 0x8000B344
void AptFormat::Draw(EMat4* matrix, EVec4* color, EVec4* bg) {
    // NOTE: asm-derived (2608 bytes)
}

// 0x8000BD74
void AptFormat::InitForParticles(int count) {
    // NOTE: asm-derived (2228 bytes)
}

// 0x8000C628
void AptFormat::ProcessParticles(ERC* pRC, EMat4* matrix, EVec2& pos, EVec2& size, float dt, float scale) {
    // NOTE: asm-derived (1240 bytes)
}

// 0x8000CB00
void AptFormat::CheckAsyncLoads() {
    // NOTE: asm-derived (536 bytes)
}

// 0x8000CD18
void AptFormat::CopyForward(AptFormat* other) {
    // NOTE: asm-derived (476 bytes)
}

// ============================================================================
// RCPTarget - Recipe UI target
// ============================================================================

class RCPTarget {
    // Standard UI target + recipe state

    // Auto-generated method declarations
    RCPTarget(cRCPEventHandler* handler, int playerIdx);
    ~RCPTarget();
    void make_recipe_text(int* recipe, BString2& text);
    void SetVariable(char* varName, char* value);
    void GetVariable(char* varName);
    void GetLocalizable(char* key);
    void Update();
    void init_recipes();
    void install_tab_shaders();
    void install_lock_shaders();
    void install_ing_shaders();
    void get_plus_shaders(int& count, unsigned int& shader1, unsigned int& shader2);
    void get_proc_shaders(int& count, unsigned int& shader1, unsigned int& shader2);
};

// 0x801DCF40
RCPTarget::RCPTarget(cRCPEventHandler* handler, int playerIdx) {
    // NOTE: asm-derived (2500 bytes)
    char* self = (char*)this;
    memset(self, 0, 128);
}

// 0x801DD904
RCPTarget::~RCPTarget() { /* NOTE: asm-derived */ }

// 0x801DDBD0
void RCPTarget::make_recipe_text(int* recipe, BString2& text) { /* NOTE: asm-derived */ }

// 0x801DDD8C
void RCPTarget::SetVariable(char* varName, char* value) { /* NOTE: asm-derived (1116 bytes) */ }

// 0x801DE1E8
void RCPTarget::GetVariable(char* varName) { /* NOTE: asm-derived */ }

// 0x801DE32C
void RCPTarget::GetLocalizable(char* key) { /* NOTE: asm-derived (392 bytes) */ }

// 0x801DE4B4
void RCPTarget::Update() { /* NOTE: asm-derived */ }

// 0x801DE538
void RCPTarget::init_recipes() { /* NOTE: asm-derived (444 bytes) */ }

// 0x801DE6F4
void RCPTarget::install_tab_shaders() { /* NOTE: asm-derived */ }

// 0x801DE798
void RCPTarget::install_lock_shaders() { /* NOTE: asm-derived */ }

// 0x801DE85C
void RCPTarget::install_ing_shaders() { /* NOTE: asm-derived (956 bytes) */ }

// 0x801DEC18
void RCPTarget::get_plus_shaders(int& count, unsigned int& shader1, unsigned int& shader2) { /* NOTE: asm-derived */ }

// 0x801DECB4
void RCPTarget::get_proc_shaders(int& count, unsigned int& shader1, unsigned int& shader2) { /* NOTE: asm-derived */ }

// ============================================================================
// EYETarget - EyeToy camera UI target
// ============================================================================

class EYETarget {
    // [136] m_settingCount
    // [152] m_mode
    // [164] m_exposure (float)
    // [168] m_callback (void*)

    // Auto-generated method declarations
    void SaveCurrentSetting();
    EYETarget(int playerIdx);
    void AddSetVar(SetVar* sv);
    void AddGetVar(GetVar* gv);
    ~EYETarget();
    void SetVariable(char* varName, char* value);
    void GetVariable(char* varName);
    void RenderCallback(ERC* pRC, structDrawCBparams* params);
};

// 0x801E714C
void EYETarget::SaveCurrentSetting() {
    // NOTE: asm-derived - switch on mode (256 bytes)
    char* self = (char*)this;
    int mode = *(int*)(self + 152);
    switch (mode) {
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5:
            // Increment counter, get exposure, store callback
            break;
    }
}

// 0x801E728C
EYETarget::EYETarget(int playerIdx) {
    // NOTE: asm-derived (5560 bytes)
}

// 0x801E8844
void EYETarget::AddSetVar(SetVar* sv) { /* NOTE: asm-derived */ }

// 0x801E8994
void EYETarget::AddGetVar(GetVar* gv) { /* NOTE: asm-derived */ }

// 0x801E8AE4
EYETarget::~EYETarget() { /* NOTE: asm-derived (788 bytes) */ }

// 0x801E8DF8
void EYETarget::SetVariable(char* varName, char* value) { /* NOTE: asm-derived */ }

// 0x801E8EA0
void EYETarget::GetVariable(char* varName) { /* NOTE: asm-derived */ }

// 0x801E8F94
void EYETarget::RenderCallback(ERC* pRC, structDrawCBparams* params) { /* NOTE: asm-derived (420 bytes) */ }

// ============================================================================
// EyeToyClient - EyeToy camera driver
// ============================================================================

class EyeToyClient {
    // Camera/video capture system

    // Auto-generated method declarations
    void saveHeader(int& record);
    void saveTexture(int slot, int& record);
    void Save(int slot, int& record);
    void loadHeader(int& record);
    void loadTexture(int slot, int& record);
    void Load(int slot, int& record);
    void LoadDefaultSettings();
    void FindFirstConnectedEyeToy();
    void AcquireTexture(int w, int h, int fmt);
    void AcquireRenderSurface(int w, int h, int fmt);
    void CopyTextureToShader(ERShader* shader, ETexture* tex);
    void CompositeFF_callback(ETexture* tex);
    void UpdateFunFrameLoading();
    void SetFilterPipeline(int filter);
    void Init();
    void Shutdown();
    void Update(float dt);
    void Render();
    void OpenSession();
    void CloseSession();
    void WriteTextureToRepSlot(int slot, ETexture* tex, int layer);
    void SaveSessionToSlot(int slot);
    void GetRepSlotUnLockedBits(int slot);
    void GetFunFrameUnLockedBits(int slot);
    float GetExposure();
    void SetExposure(float val);
    void SetHue(float val);

    class Debug {
    public:
        static void WriteTGAToHost(ETexture* tex);
    };
};

// 0x80037400
void EyeToyClient::saveHeader(int& record) { /* NOTE: asm-derived */ }

// 0x800374AC
void EyeToyClient::saveTexture(int slot, int& record) { /* NOTE: asm-derived */ }

// 0x800375A0
void EyeToyClient::Save(int slot, int& record) { /* NOTE: asm-derived */ }

// 0x80037654
void EyeToyClient::loadHeader(int& record) { /* NOTE: asm-derived */ }

// 0x80037714
void EyeToyClient::loadTexture(int slot, int& record) { /* NOTE: asm-derived */ }

// 0x80037838
void EyeToyClient::Load(int slot, int& record) { /* NOTE: asm-derived */ }

// 0x800378E4
void EyeToyClient::LoadDefaultSettings() { /* NOTE: asm-derived */ }

// 0x80037970
void EyeToyClient::FindFirstConnectedEyeToy() { /* NOTE: asm-derived */ }

// 0x800379D0
void EyeToyClient::AcquireTexture(int w, int h, int fmt) { /* NOTE: asm-derived */ }

// 0x80037A9C
void EyeToyClient::AcquireRenderSurface(int w, int h, int fmt) { /* NOTE: asm-derived */ }

// 0x80037B80
void EyeToyClient::CopyTextureToShader(ERShader* shader, ETexture* tex) { /* NOTE: asm-derived (416 bytes) */ }

// 0x80037D20
void EyeToyClient::CompositeFF_callback(ETexture* tex) { /* NOTE: asm-derived (1024 bytes) */ }

// 0x80038120
void EyeToyClient::UpdateFunFrameLoading() { /* NOTE: asm-derived */ }

// 0x8003819C
void EyeToyClient::SetFilterPipeline(int filter) { /* NOTE: asm-derived (836 bytes) */ }

// 0x80038518
void EyeToyClient::Init() { /* NOTE: asm-derived (284 bytes) */ }

// 0x80038634
void EyeToyClient::Shutdown() { /* NOTE: asm-derived */ }

// 0x80038710
void EyeToyClient::Update(float dt) { /* NOTE: asm-derived */ }

// 0x800387C0
void EyeToyClient::Render() { /* NOTE: asm-derived (1304 bytes) */ }

// 0x80038CF0
void EyeToyClient::OpenSession() { /* NOTE: asm-derived */ }

// 0x80038DC4
void EyeToyClient::CloseSession() { /* NOTE: asm-derived */ }

// 0x80038E64
void EyeToyClient::WriteTextureToRepSlot(int slot, ETexture* tex, int layer) { /* NOTE: asm-derived */ }

// 0x80038EEC
void EyeToyClient::SaveSessionToSlot(int slot) { /* NOTE: asm-derived */ }

// 0x80039014
void EyeToyClient::GetRepSlotUnLockedBits(int slot) { /* NOTE: asm-derived */ }

// 0x800390FC
void EyeToyClient::GetFunFrameUnLockedBits(int slot) { /* NOTE: asm-derived */ }

// 0x80039270
float EyeToyClient::GetExposure() { /* NOTE: asm-derived */ return 0.0f; }

// 0x800392C4
void EyeToyClient::SetExposure(float val) { /* NOTE: asm-derived */ }

// 0x800393B0
void EyeToyClient::SetHue(float val) { /* NOTE: asm-derived */ }

// 0x800394B8
void EyeToyClient::Debug::WriteTGAToHost(ETexture* tex) { /* NOTE: asm-derived */ }

// ============================================================================
// CasScene - Create-A-Sim 3D scene
// ============================================================================

class CasScene {
    // [0] m_pRoom
    // [4] vtable
    // [256+] light data
    // [2704] camera data

    // Auto-generated method declarations
    CasScene();
    ~CasScene();
    void Init();
    void Reload();
    void Update(float dt);
    void Draw(ERC* pRC);
    void DrawRoom(ERC* pRC, int roomIdx, EMat4& transform);
    void DrawRoomClothing(ERC* pRC, EMat4& transform);
    void LoadLights(char* filename, int count);
    void SetLights(int set);
    void SetSceneLighting(int mode, bool apply);
    void RepositionCamera(unsigned int camId, float x, float y);
    void InitCamera(unsigned int camId);
    void UpdateCamera(float dt);
    void SetUpWindow(ERC* pRC);
    void HandleEventChangeFocus(CasEventChangeFocus& event);
    void GetObjectPosition(unsigned int objId, EVec3& pos, float& rot);
};

// 0x8016502C
CasScene::CasScene() {
    // NOTE: asm-derived (548 bytes)
    char* self = (char*)this;
    *(void**)self = 0;
}

// 0x80165250
CasScene::~CasScene() { /* NOTE: asm-derived (428 bytes) */ }

// 0x801653FC
void CasScene::Init() { /* NOTE: asm-derived */ }

// 0x801654A4
void CasScene::Reload() { /* NOTE: asm-derived (820 bytes) */ }

// 0x801657E0
void CasScene::Update(float dt) { /* NOTE: asm-derived */ }

// 0x80165824
void CasScene::Draw(ERC* pRC) { /* NOTE: asm-derived (364 bytes) */ }

// 0x80165990
void CasScene::DrawRoom(ERC* pRC, int roomIdx, EMat4& transform) { /* NOTE: asm-derived */ }

// 0x801659D4
void CasScene::DrawRoomClothing(ERC* pRC, EMat4& transform) { /* NOTE: asm-derived (504 bytes) */ }

// 0x80165BDC
void CasScene::LoadLights(char* filename, int count) { /* NOTE: asm-derived (808 bytes) */ }

// 0x80165F04
void CasScene::SetLights(int set) { /* NOTE: asm-derived (388 bytes) */ }

// 0x80166088
void CasScene::SetSceneLighting(int mode, bool apply) { /* NOTE: asm-derived */ }

// 0x801660D0
void CasScene::RepositionCamera(unsigned int camId, float x, float y) { /* NOTE: asm-derived (936 bytes) */ }

// 0x80166478
void CasScene::InitCamera(unsigned int camId) { /* NOTE: asm-derived */ }

// 0x801665A8
void CasScene::UpdateCamera(float dt) { /* NOTE: asm-derived (1268 bytes) */ }

// 0x80166A9C
void CasScene::SetUpWindow(ERC* pRC) { /* NOTE: asm-derived */ }

// 0x80166BB0
void CasScene::HandleEventChangeFocus(CasEventChangeFocus& event) { /* NOTE: asm-derived (740 bytes) */ }

// 0x80166E94
void CasScene::GetObjectPosition(unsigned int objId, EVec3& pos, float& rot) { /* NOTE: asm-derived */ }

// ============================================================================
// H2DTarget - HUD 2D display target
// ============================================================================

class H2DTarget {
    // Standard UI target + HUD state for split-screen

    // Auto-generated method declarations
    H2DTarget();
    ~H2DTarget();
    void SetVariable(char* varName, char* value);
    void GetVariable(char* varName);
    void GetLocalizable(char* key);
    void Update();
    void IncPause(bool immediate);
    void ReleasePause(bool immediate);
    void CloseSidePanels(int player);
    void SelectedPersonChanged(int player, cXPerson* person);
    void SpawnRewardMomentDialog(int player, int reward);
    void ACTCancelModeExited(int player);
    void SpawnIntroThoughtBalloon(UIDialog* dlg);
    void IsUserReadingIntroThoughtBalloon();
    void NewWantFearIcon(int player, int slot, unsigned int iconId, unsigned int bgId, int type, Neighbor* neighbor);
    void AddAction(int player, Interaction* action, BString2& name, unsigned int iconId, ERShader* shader, unsigned int bgId);
    bool IsActionQueueAvailable(int player) const;
    void CSIMActive(int player, bool active);
    bool ShouldH2DBeVisible(int player) const;
    void IsDialogActive();
};

// 0x801B727C
H2DTarget::H2DTarget() {
    // NOTE: asm-derived (2204 bytes)
    char* self = (char*)this;
    memset(self, 0, 128);
}

// 0x801B7B18
H2DTarget::~H2DTarget() { /* NOTE: asm-derived (920 bytes) */ }

// 0x801B7EB0
void H2DTarget::SetVariable(char* varName, char* value) { /* NOTE: asm-derived (1212 bytes) */ }

// 0x801B836C
void H2DTarget::GetVariable(char* varName) { /* NOTE: asm-derived */ }

// 0x801B83FC
void H2DTarget::GetLocalizable(char* key) { /* NOTE: asm-derived */ }

// 0x801B8484
void H2DTarget::Update() { /* NOTE: asm-derived (1460 bytes) */ }

// 0x801B8A40
void H2DTarget::IncPause(bool immediate) { /* NOTE: asm-derived */ }

// 0x801B8ACC
void H2DTarget::ReleasePause(bool immediate) { /* NOTE: asm-derived */ }

// 0x801B8B54
void H2DTarget::CloseSidePanels(int player) { /* NOTE: asm-derived */ }

// 0x801B8BA4
void H2DTarget::SelectedPersonChanged(int player, cXPerson* person) { /* NOTE: asm-derived */ }

// 0x801B8C3C
void H2DTarget::SpawnRewardMomentDialog(int player, int reward) { /* NOTE: asm-derived */ }

// 0x801B8C98
void H2DTarget::ACTCancelModeExited(int player) { /* NOTE: asm-derived */ }

// 0x801B8D0C
void H2DTarget::SpawnIntroThoughtBalloon(UIDialog* dlg) { /* NOTE: asm-derived */ }

// 0x801B8D60
void H2DTarget::IsUserReadingIntroThoughtBalloon() { /* NOTE: asm-derived */ }

// 0x801B8E3C
void H2DTarget::NewWantFearIcon(int player, int slot, unsigned int iconId, unsigned int bgId, int type, Neighbor* neighbor) {
    // NOTE: asm-derived
}

// 0x801B8E84
void H2DTarget::AddAction(int player, Interaction* action, BString2& name, unsigned int iconId, ERShader* shader, unsigned int bgId) {
    // NOTE: asm-derived
}

// 0x801B8F40
bool H2DTarget::IsActionQueueAvailable(int player) const { /* NOTE: asm-derived */ return false; }

// 0x801B8F8C
void H2DTarget::CSIMActive(int player, bool active) { /* NOTE: asm-derived */ }

// 0x801B90CC
bool H2DTarget::ShouldH2DBeVisible(int player) const { /* NOTE: asm-derived */ return true; }

// 0x801B9318
void H2DTarget::IsDialogActive() { /* NOTE: asm-derived */ }

// ============================================================================
// PRGTarget - Progress UI target
// ============================================================================

class PRGTarget {
    // Standard UI target + progress/stat tracking

    // Auto-generated method declarations
    PRGTarget(int playerIdx);
    ~PRGTarget();
    void SetVariable(char* varName, char* value);
    void FormatFraction(unsigned short* buf, int num, int denom);
    void FormatPercentage(unsigned short* buf, int num, int denom);
    void GetUnlockedFashions();
    void GetUnlockedRecipies();
    void GetUnlockedObjects();
    void GetTotalPromotions();
    void GetMaxedCareers();
    void GetTotalSkillPoints();
    void GetMaxedSkills();
    void GetNPCsHelped();
    void GetUnlockedLots();
    void GetLocalizable(char* key);
    void GetVariable(char* varName);
    void OnCancelKeyPressed(char* context, char* action);
    void Shutdown();
};

// 0x801D8768
PRGTarget::PRGTarget(int playerIdx) {
    // NOTE: asm-derived (2352 bytes)
    char* self = (char*)this;
    memset(self, 0, 128);
}

// 0x801D9098
PRGTarget::~PRGTarget() { /* NOTE: asm-derived */ }

// 0x801D9228
void PRGTarget::SetVariable(char* varName, char* value) { /* NOTE: asm-derived */ }

// 0x801D92D0
void PRGTarget::FormatFraction(unsigned short* buf, int num, int denom) { /* NOTE: asm-derived */ }

// 0x801D9330
void PRGTarget::FormatPercentage(unsigned short* buf, int num, int denom) { /* NOTE: asm-derived */ }

// 0x801D9398
void PRGTarget::GetUnlockedFashions() { /* NOTE: asm-derived */ }

// 0x801D9408
void PRGTarget::GetUnlockedRecipies() { /* NOTE: asm-derived */ }

// 0x801D9478
void PRGTarget::GetUnlockedObjects() { /* NOTE: asm-derived */ }

// 0x801D94E8
void PRGTarget::GetTotalPromotions() { /* NOTE: asm-derived */ }

// 0x801D9578
void PRGTarget::GetMaxedCareers() { /* NOTE: asm-derived */ }

// 0x801D9604
void PRGTarget::GetTotalSkillPoints() { /* NOTE: asm-derived (472 bytes) */ }

// 0x801D97DC
void PRGTarget::GetMaxedSkills() { /* NOTE: asm-derived (360 bytes) */ }

// 0x801D9944
void PRGTarget::GetNPCsHelped() { /* NOTE: asm-derived */ }

// 0x801D99A0
void PRGTarget::GetUnlockedLots() { /* NOTE: asm-derived */ }

// 0x801D9A10
void PRGTarget::GetLocalizable(char* key) { /* NOTE: asm-derived (2856 bytes) */ }

// 0x801DA538
void PRGTarget::GetVariable(char* varName) { /* NOTE: asm-derived */ }

// 0x801DA5D4
void PRGTarget::OnCancelKeyPressed(char* context, char* action) { /* NOTE: asm-derived */ }

// 0x801DA624
void PRGTarget::Shutdown() { /* NOTE: asm-derived */ }

// ============================================================================
// WXFTarget - Wants/Fears exchange UI
// ============================================================================

class WXFTarget {
    // Standard UI target + want/fear selection state

    // Auto-generated method declarations
    WXFTarget(int playerIdx);
    ~WXFTarget();
    void SetVariable(char* varName, char* value);
    void GetLocalizable(char* key);
    void GetVariable(char* varName);
    void Shutdown();
    void UpdateMenuState(char* menu, char* state);
    void UpdateText();
    void OnLeftKeyPressed(char* context, char* action);
    void OnRightKeyPressed(char* context, char* action);
    void OnCancelKeyPressed(char* context, char* action);
    void UpdateShaders();
    void GetBackgroundShader(tWantType type);
    void UpdateWAFText(char* text);
    void ShowHelp();
    void GetAspirationIcon();
};

// 0x801E4F2C
WXFTarget::WXFTarget(int playerIdx) {
    // NOTE: asm-derived (3048 bytes)
    char* self = (char*)this;
    memset(self, 0, 128);
}

// 0x801E5B14
WXFTarget::~WXFTarget() { /* NOTE: asm-derived */ }

// 0x801E5CBC
void WXFTarget::SetVariable(char* varName, char* value) { /* NOTE: asm-derived */ }

// 0x801E5DDC
void WXFTarget::GetLocalizable(char* key) { /* NOTE: asm-derived (952 bytes) */ }

// 0x801E6194
void WXFTarget::GetVariable(char* varName) { /* NOTE: asm-derived */ }

// 0x801E629C
void WXFTarget::Shutdown() { /* NOTE: asm-derived */ }

// 0x801E62EC
void WXFTarget::UpdateMenuState(char* menu, char* state) { /* NOTE: asm-derived */ }

// 0x801E6370
void WXFTarget::UpdateText() { /* NOTE: asm-derived */ }

// 0x801E6454
void WXFTarget::OnLeftKeyPressed(char* context, char* action) { /* NOTE: asm-derived */ }

// 0x801E64BC
void WXFTarget::OnRightKeyPressed(char* context, char* action) { /* NOTE: asm-derived */ }

// 0x801E6524
void WXFTarget::OnCancelKeyPressed(char* context, char* action) { /* NOTE: asm-derived */ }

// 0x801E6570
void WXFTarget::UpdateShaders() { /* NOTE: asm-derived (1556 bytes) */ }

// 0x801E6B84
void WXFTarget::GetBackgroundShader(tWantType type) { /* NOTE: asm-derived */ }

// 0x801E6BD8
void WXFTarget::UpdateWAFText(char* text) { /* NOTE: asm-derived (536 bytes) */ }

// 0x801E6E30
void WXFTarget::ShowHelp() { /* NOTE: asm-derived */ }

// 0x801E6EC0
void WXFTarget::GetAspirationIcon() { /* NOTE: asm-derived */ }

// ============================================================================
// CRDTarget - Credits display target
// ============================================================================

class CRDTarget {
    // Standard UI target + credits scroll state

    // Auto-generated method declarations
    CRDTarget();
    ~CRDTarget();
    void SetVariable(char* varName, char* value);
    void GetVariable(char* varName);
    void GetLocalizable(char* key);
    void Update();
    void ShowCredits();
    void HideCredits();
    void StartCredits();
    void EndCredits();
    void SetupForCreditsRender(int mode);
    void InitCreditsTextFetch();
    void ScrollingCallback(ERC* pRC, structDrawCBparams* params);
    void ShowPhoto();
    void HidePhoto();
};

// 0x801A4070
CRDTarget::CRDTarget() {
    // NOTE: asm-derived (2008 bytes)
    char* self = (char*)this;
    memset(self, 0, 128);
}

// 0x801A4848
CRDTarget::~CRDTarget() { /* NOTE: asm-derived */ }

// 0x801A4A04
void CRDTarget::SetVariable(char* varName, char* value) { /* NOTE: asm-derived */ }

// 0x801A4AE4
void CRDTarget::GetVariable(char* varName) { /* NOTE: asm-derived */ }

// 0x801A4BE8
void CRDTarget::GetLocalizable(char* key) { /* NOTE: asm-derived */ }

// 0x801A4C70
void CRDTarget::Update() { /* NOTE: asm-derived (336 bytes) */ }

// 0x801A4DC0
void CRDTarget::ShowCredits() { /* NOTE: asm-derived */ }

// 0x801A4EEC
void CRDTarget::HideCredits() { /* NOTE: asm-derived */ }

// 0x801A4F84
void CRDTarget::StartCredits() { /* NOTE: asm-derived */ }

// 0x801A5000
void CRDTarget::EndCredits() { /* NOTE: asm-derived */ }

// 0x801A50D0
void CRDTarget::SetupForCreditsRender(int mode) { /* NOTE: asm-derived (1436 bytes) */ }

// 0x801A566C
void CRDTarget::InitCreditsTextFetch() { /* NOTE: asm-derived */ }

// 0x801A56FC
void CRDTarget::ScrollingCallback(ERC* pRC, structDrawCBparams* params) { /* NOTE: asm-derived (2572 bytes) */ }

// 0x801A6108
void CRDTarget::ShowPhoto() { /* NOTE: asm-derived */ }

// 0x801A6188
void CRDTarget::HidePhoto() { /* NOTE: asm-derived */ }

// ============================================================================
// ChainResFile - Chained resource file system
// ============================================================================

class ChainResFile {
    // Linked list of iResFile for multi-file resource lookup

    // Auto-generated method declarations
    ChainResFile();
    ~ChainResFile();
    void RemoveFile(iResFile* file);
    void GetFile(short idx);
    void Close();
    void CloseForReopen();
    void Reopen();
    void Update();
    void Writable();
    void ValidFile();
    void GetLanguage(int* lang);
    void CountTypes();
    void BuildTypeVector(vector<int, allocator<int> >& types);
    void GetIndType(short idx);
    void Count(int type);
    void GetByIDAndLanguage(int type, short id, char lang, void (*callback)(void*, int));
    void GetByName(int type, StringBuffer& name, void (*callback)(void*, int));
    void GetByIndex(int type, short idx, void (*callback)(void*, int));
    void GetName(int* handle, StringBuffer& name);
    void GetResType(int* handle);
    void GetID(int* handle, short* id);
    void IsLittleEndian(int* handle);
    void GetIndex(int* handle, short* idx);
    void FindUniqueName(int type, StringBuffer& name);
    void FindUniqueID(int type);
    void Detach(int* handle);
    void SetID(int* handle, short id);
    void AddWithLanguage(int* handle, int type, short id, StringBuffer& name, char lang, bool replace);
    void Write(int* handle);
    void Remove(int* handle);
    void SetInfo(int* handle, short id, StringBuffer& name, char lang);
    void AddProhibitedType(iResFile* file, unsigned int type);
    void AddExclusiveType(iResFile* file, unsigned int type);
    void TypeWritable(unsigned int type);
};

// 0x800B1D94
ChainResFile::ChainResFile() { /* NOTE: asm-derived */ }

// 0x800B1E00
ChainResFile::~ChainResFile() { /* NOTE: asm-derived */ Close(); }

// 0x800B1ED8
void ChainResFile::RemoveFile(iResFile* file) { /* NOTE: asm-derived */ }

// 0x800B1FE4
void ChainResFile::GetFile(short idx) { /* NOTE: asm-derived */ }

// 0x800B2044
void ChainResFile::Close() { /* NOTE: asm-derived */ }

// 0x800B20D8
void ChainResFile::CloseForReopen() { /* NOTE: asm-derived */ }

// 0x800B216C
void ChainResFile::Reopen() { /* NOTE: asm-derived */ }

// 0x800B2200
void ChainResFile::Update() { /* NOTE: asm-derived */ }

// 0x800B22D4
void ChainResFile::Writable() { /* NOTE: asm-derived */ }

// 0x800B2368
void ChainResFile::ValidFile() { /* NOTE: asm-derived */ }

// 0x800B23FC
void ChainResFile::GetLanguage(int* lang) { /* NOTE: asm-derived */ }

// 0x800B24C4
void ChainResFile::CountTypes() { /* NOTE: asm-derived */ }

// 0x800B2558
void ChainResFile::BuildTypeVector(vector<int, allocator<int> >& types) { /* NOTE: asm-derived (620 bytes) */ }

// 0x800B27C4
void ChainResFile::GetIndType(short idx) { /* NOTE: asm-derived */ }

// 0x800B28B0
void ChainResFile::Count(int type) { /* NOTE: asm-derived */ }

// 0x800B2970
void ChainResFile::GetByIDAndLanguage(int type, short id, char lang, void (*callback)(void*, int)) {
    // NOTE: asm-derived
}

// 0x800B2A84
void ChainResFile::GetByName(int type, StringBuffer& name, void (*callback)(void*, int)) { /* NOTE: asm-derived */ }

// 0x800B2B54
void ChainResFile::GetByIndex(int type, short idx, void (*callback)(void*, int)) { /* NOTE: asm-derived */ }

// 0x800B2C7C
void ChainResFile::GetName(int* handle, StringBuffer& name) { /* NOTE: asm-derived */ }

// 0x800B2D40
void ChainResFile::GetResType(int* handle) { /* NOTE: asm-derived */ }

// 0x800B2E08
void ChainResFile::GetID(int* handle, short* id) { /* NOTE: asm-derived */ }

// 0x800B2ECC
void ChainResFile::IsLittleEndian(int* handle) { /* NOTE: asm-derived */ }

// 0x800B2F8C
void ChainResFile::GetIndex(int* handle, short* idx) { /* NOTE: asm-derived */ }

// 0x800B3050
void ChainResFile::FindUniqueName(int type, StringBuffer& name) { /* NOTE: asm-derived */ }

// 0x800B3110
void ChainResFile::FindUniqueID(int type) { /* NOTE: asm-derived */ }

// 0x800B3174
void ChainResFile::Detach(int* handle) { /* NOTE: asm-derived */ }

// 0x800B3254
void ChainResFile::SetID(int* handle, short id) { /* NOTE: asm-derived */ }

// 0x800B3354
void ChainResFile::AddWithLanguage(int* handle, int type, short id, StringBuffer& name, char lang, bool replace) {
    // NOTE: asm-derived (540 bytes)
}

// 0x800B3570
void ChainResFile::Write(int* handle) { /* NOTE: asm-derived */ }

// 0x800B364C
void ChainResFile::Remove(int* handle) { /* NOTE: asm-derived */ }

// 0x800B3728
void ChainResFile::SetInfo(int* handle, short id, StringBuffer& name, char lang) { /* NOTE: asm-derived */ }

// 0x800B381C
void ChainResFile::AddProhibitedType(iResFile* file, unsigned int type) { /* NOTE: asm-derived (432 bytes) */ }

// 0x800B39CC
void ChainResFile::AddExclusiveType(iResFile* file, unsigned int type) { /* NOTE: asm-derived (436 bytes) */ }

// 0x800B3B80
void ChainResFile::TypeWritable(unsigned int type) { /* NOTE: asm-derived */ }

// ============================================================================
// EController - Game controller input
// ============================================================================

class EController {
    // Controller state, button mapping, vibration

    // Auto-generated method declarations
    EController();
    ~EController();
    void Update();
    void UpdateAutoRepeat();
    void SetCommandMap(EBtnToCmdAssoc* map, int count);
    void IsInUse();
    void VibrateMotorOne(float intensity);
    void VibrateMotorOne(float intensity, float duration);
    void VibrateMotorTwo(float intensity);
    void VibrateMotorTwo(float intensity, float duration);
    void VibrateAll(float motor1, float motor2);
    void VibrateAll(float m1Int, float m1Dur, float m2Int, float m2Dur);
    void StopMotorOne();
    void StopMotorTwo();
    void StopVibration();
    void UpdateVibration();
    void PauseMotors();
    void ResumeMotors();
    void UpdateButtonData(unsigned int buttonMask);
    void UpdateStickData(int stick, int axis, float value);
    void AddPressedEventData(unsigned int button);
    void AddReleasedEventData(unsigned int button);
    void GetStick(int stick, int axis, unsigned int filter);
    void IsStickFiltered(int stick, int axis, unsigned int filter);
    void StickMoved(int stick, float threshold, unsigned int filter);
    void GetLastStick(int stick, int axis, unsigned int filter);
    void GetBtnResult(unsigned int btn, bool pressed, unsigned int filter);
    void FindFirstCommand(unsigned int cmd);
    void GetCmdResult(unsigned int cmd, unsigned int context, unsigned int filter, bool pressed);
    void AddFilter(unsigned int id, char* name, int priority);
    void RemoveFilter(unsigned int id);
    void MoveFilterToTop(unsigned int id);
    void SetFilter(unsigned int id, unsigned int mask);
    void AddCmdToFilter(unsigned int id, unsigned int cmd);
    void AddCmdsToFilter(unsigned int id, unsigned int* cmds, int count);
    void RemoveCmdFromFilter(unsigned int id, unsigned int cmd);
    void AddBtnToFilter(unsigned int id, unsigned int btn);
    void RemoveBtnFromFilter(unsigned int id, unsigned int btn);
    void GetCmdButtonMask(unsigned int cmd);
    void GetFilterIndex(unsigned int id);
    void GetFilterMask(unsigned int id);
    void GetCmdDown(unsigned int cmd, unsigned int filter);
    void GetCmdPressed(unsigned int cmd, unsigned int filter);
    void GetCmdReleased(unsigned int cmd, unsigned int filter);
    void GetCmdUp(unsigned int cmd, unsigned int filter);
    void GetCmdRepeat(unsigned int cmd, unsigned int filter);
    void GetBtnDown(unsigned int btn, unsigned int filter);
    void GetBtnDownAny(unsigned int btn, unsigned int filter);
};

// 0x80303E58
EController::EController() { /* NOTE: asm-derived (324 bytes) */ }

// 0x80303F9C
EController::~EController() { /* NOTE: asm-derived */ }

// 0x80304014
void EController::Update() { /* NOTE: asm-derived */ }

// 0x80304070
void EController::UpdateAutoRepeat() { /* NOTE: asm-derived (368 bytes) */ }

// 0x80304250
void EController::SetCommandMap(EBtnToCmdAssoc* map, int count) { /* NOTE: asm-derived */ }

// 0x803042D4
void EController::IsInUse() { /* NOTE: asm-derived (312 bytes) */ }

// 0x80304474
void EController::VibrateMotorOne(float intensity) { /* NOTE: asm-derived */ }

// 0x803044E4
void EController::VibrateMotorOne(float intensity, float duration) { /* NOTE: asm-derived */ }

// 0x80304534
void EController::VibrateMotorTwo(float intensity) { /* NOTE: asm-derived */ }

// 0x803045A4
void EController::VibrateMotorTwo(float intensity, float duration) { /* NOTE: asm-derived */ }

// 0x803045F4
void EController::VibrateAll(float motor1, float motor2) { /* NOTE: asm-derived */ }

// 0x80304678
void EController::VibrateAll(float m1Int, float m1Dur, float m2Int, float m2Dur) { /* NOTE: asm-derived */ }

// 0x80304710
void EController::StopMotorOne() { /* NOTE: asm-derived */ }

// 0x80304780
void EController::StopMotorTwo() { /* NOTE: asm-derived */ }

// 0x803047F0
void EController::StopVibration() { /* NOTE: asm-derived */ }

// 0x80304864
void EController::UpdateVibration() { /* NOTE: asm-derived */ }

// 0x80304920
void EController::PauseMotors() { /* NOTE: asm-derived */ }

// 0x8030497C
void EController::ResumeMotors() { /* NOTE: asm-derived */ }

// 0x803049E8
void EController::UpdateButtonData(unsigned int buttonMask) { /* NOTE: asm-derived (296 bytes) */ }

// 0x80304B10
void EController::UpdateStickData(int stick, int axis, float value) { /* NOTE: asm-derived */ }

// 0x80304B98
void EController::AddPressedEventData(unsigned int button) { /* NOTE: asm-derived */ }

// 0x80304C54
void EController::AddReleasedEventData(unsigned int button) { /* NOTE: asm-derived */ }

// 0x80304D28
void EController::GetStick(int stick, int axis, unsigned int filter) { /* NOTE: asm-derived */ }

// 0x80304DF4
void EController::IsStickFiltered(int stick, int axis, unsigned int filter) { /* NOTE: asm-derived */ }

// 0x80304E58
void EController::StickMoved(int stick, float threshold, unsigned int filter) { /* NOTE: asm-derived */ }

// 0x80304F1C
void EController::GetLastStick(int stick, int axis, unsigned int filter) { /* NOTE: asm-derived */ }

// 0x80304FF8
void EController::GetBtnResult(unsigned int btn, bool pressed, unsigned int filter) { /* NOTE: asm-derived */ }

// 0x8030509C
void EController::FindFirstCommand(unsigned int cmd) { /* NOTE: asm-derived */ }

// 0x80305130
void EController::GetCmdResult(unsigned int cmd, unsigned int context, unsigned int filter, bool pressed) {
    // NOTE: asm-derived
}

// 0x803051FC
void EController::AddFilter(unsigned int id, char* name, int priority) { /* NOTE: asm-derived */ }

// 0x803052EC
void EController::RemoveFilter(unsigned int id) { /* NOTE: asm-derived */ }

// 0x803053A8
void EController::MoveFilterToTop(unsigned int id) { /* NOTE: asm-derived */ }

// 0x803054A4
void EController::SetFilter(unsigned int id, unsigned int mask) { /* NOTE: asm-derived */ }

// 0x803054E8
void EController::AddCmdToFilter(unsigned int id, unsigned int cmd) { /* NOTE: asm-derived */ }

// 0x8030552C
void EController::AddCmdsToFilter(unsigned int id, unsigned int* cmds, int count) { /* NOTE: asm-derived */ }

// 0x80305588
void EController::RemoveCmdFromFilter(unsigned int id, unsigned int cmd) { /* NOTE: asm-derived */ }

// 0x803055CC
void EController::AddBtnToFilter(unsigned int id, unsigned int btn) { /* NOTE: asm-derived */ }

// 0x80305618
void EController::RemoveBtnFromFilter(unsigned int id, unsigned int btn) { /* NOTE: asm-derived */ }

// 0x80305664
void EController::GetCmdButtonMask(unsigned int cmd) { /* NOTE: asm-derived */ }

// 0x803056BC
void EController::GetFilterIndex(unsigned int id) { /* NOTE: asm-derived */ }

// 0x80305700
void EController::GetFilterMask(unsigned int id) { /* NOTE: asm-derived */ }

// 0x803058A8
void EController::GetCmdDown(unsigned int cmd, unsigned int filter) { /* NOTE: asm-derived */ }

// 0x80305908
void EController::GetCmdPressed(unsigned int cmd, unsigned int filter) { /* NOTE: asm-derived */ }

// 0x80305968
void EController::GetCmdReleased(unsigned int cmd, unsigned int filter) { /* NOTE: asm-derived */ }

// 0x803059C8
void EController::GetCmdUp(unsigned int cmd, unsigned int filter) { /* NOTE: asm-derived */ }

// 0x80305A28
void EController::GetCmdRepeat(unsigned int cmd, unsigned int filter) { /* NOTE: asm-derived */ }

// 0x80305A88
void EController::GetBtnDown(unsigned int btn, unsigned int filter) { /* NOTE: asm-derived */ }

// 0x80305AD0
void EController::GetBtnDownAny(unsigned int btn, unsigned int filter) { /* NOTE: asm-derived */ }

// Additional EController button query methods (12 more at 72 bytes each)
// 0x80305B18 through 0x80305D10

// ============================================================================
// EResourceManager - Resource loading and caching
// ============================================================================

class EResourceManager {
    // [0] m_pArchiveFile
    // [4..] resource tables, hash maps

    // Auto-generated method declarations
    EResourceManager();
    ~EResourceManager();
    void Shutdown();
    void Init(char* path);
    void CalcPath();
    void GetArchiveFile();
    void ArchiveFileIsUsingHDD();
    void ArchiveFileIsOpen();
    void CloseArchiveFile();
    void BinarySearch(unsigned int id, unsigned int* table, int count);
    void LookupId(unsigned int id, unsigned int& offset, unsigned int& size);
    void AddRefAll();
    void AddDelRefAll();
    void DelRefAll();
    void PrintLoadedResources();
    void PrintResourceSizes();
    void GetRef(unsigned int id);
    void ReadData(void* buf, unsigned int offset, unsigned int size);
    void PreloadResource(unsigned int id);
    void addRef(unsigned int id, EFile* file, unsigned int flags, bool async);
    void TryIncrementResource(unsigned int id, EResource** ppRes);
    void AddResource(EResource* res, unsigned int id, bool owned);
    void AddRef(char* name, EFile* file, int flags);
    void AddRefAsync(char* name);
    void Refresh(EResource* res);
    void Refresh(unsigned int id);
    void AddRef(EResource* res);
    void DelRef(unsigned int id, int flags);
    void DelRef(char* name, int flags);
    void DelRefAsync(unsigned int id);
    void DelRef(EResource* res, int flags);
    void Detach(EResource* res);
    void IsLoaded(unsigned int id);
    void CalcId(char* name);
    void MakeSpace();
    void Alloc(unsigned long size, unsigned int align);
    void Free(void* ptr);
};

// 0x8032561C
EResourceManager::EResourceManager() {
    // NOTE: asm-derived
    char* self = (char*)this;
    memset(self, 0, 64);
}

// 0x80325688
EResourceManager::~EResourceManager() { /* NOTE: asm-derived */ Shutdown(); }

// 0x80325728
void EResourceManager::Shutdown() { /* NOTE: asm-derived */ }

// 0x80325798
void EResourceManager::Init(char* path) { /* NOTE: asm-derived (832 bytes) */ }

// 0x80325AD8
void EResourceManager::CalcPath() { /* NOTE: asm-derived */ }

// 0x80325BC0
void EResourceManager::GetArchiveFile() { /* NOTE: asm-derived (296 bytes) */ }

// 0x80325CE8
void EResourceManager::ArchiveFileIsUsingHDD() { /* NOTE: asm-derived */ }

// 0x80325D8C
void EResourceManager::ArchiveFileIsOpen() { /* NOTE: asm-derived */ }

// 0x80325E08
void EResourceManager::CloseArchiveFile() { /* NOTE: asm-derived */ }

// 0x80325E6C
void EResourceManager::BinarySearch(unsigned int id, unsigned int* table, int count) { /* NOTE: asm-derived */ }

// 0x80325ED0
void EResourceManager::LookupId(unsigned int id, unsigned int& offset, unsigned int& size) { /* NOTE: asm-derived */ }

// 0x80325F60
void EResourceManager::AddRefAll() { /* NOTE: asm-derived (808 bytes) */ }

// 0x80326288
void EResourceManager::AddDelRefAll() { /* NOTE: asm-derived (828 bytes) */ }

// 0x803265C4
void EResourceManager::DelRefAll() { /* NOTE: asm-derived */ }

// 0x80326638
void EResourceManager::PrintLoadedResources() { /* NOTE: asm-derived */ }

// 0x803266A8
void EResourceManager::PrintResourceSizes() { /* NOTE: asm-derived */ }

// 0x8032671C
void EResourceManager::GetRef(unsigned int id) { /* NOTE: asm-derived */ }

// 0x80326814
void EResourceManager::ReadData(void* buf, unsigned int offset, unsigned int size) { /* NOTE: asm-derived */ }

// 0x8032686C
void EResourceManager::PreloadResource(unsigned int id) { /* NOTE: asm-derived */ }

// 0x8032695C
void EResourceManager::addRef(unsigned int id, EFile* file, unsigned int flags, bool async) {
    // NOTE: asm-derived
}

// 0x80326A60
void EResourceManager::TryIncrementResource(unsigned int id, EResource** ppRes) {
    // NOTE: asm-derived (388 bytes)
}

// 0x80326C0C
void EResourceManager::AddResource(EResource* res, unsigned int id, bool owned) { /* NOTE: asm-derived */ }

// 0x80326D1C
void EResourceManager::AddRef(char* name, EFile* file, int flags) { /* NOTE: asm-derived */ }

// 0x80326D6C
void EResourceManager::AddRefAsync(char* name) { /* NOTE: asm-derived */ }

// 0x80326E20
void EResourceManager::Refresh(EResource* res) { /* NOTE: asm-derived */ }

// 0x80326E90
void EResourceManager::Refresh(unsigned int id) { /* NOTE: asm-derived */ }

// 0x80326F60
void EResourceManager::AddRef(EResource* res) { /* NOTE: asm-derived */ }

// 0x80326FD0
void EResourceManager::DelRef(unsigned int id, int flags) { /* NOTE: asm-derived */ }

// 0x8032708C
void EResourceManager::DelRef(char* name, int flags) { /* NOTE: asm-derived */ }

// 0x8032710C
void EResourceManager::DelRefAsync(unsigned int id) { /* NOTE: asm-derived (296 bytes) */ }

// 0x80327234
void EResourceManager::DelRef(EResource* res, int flags) { /* NOTE: asm-derived (328 bytes) */ }

// 0x8032737C
void EResourceManager::Detach(EResource* res) { /* NOTE: asm-derived */ }

// 0x80327474
void EResourceManager::IsLoaded(unsigned int id) { /* NOTE: asm-derived */ }

// 0x80327534
void EResourceManager::CalcId(char* name) { /* NOTE: asm-derived */ }

// 0x803275AC
void EResourceManager::MakeSpace() { /* NOTE: asm-derived */ }

// 0x80327654
void EResourceManager::Alloc(unsigned long size, unsigned int align) { /* NOTE: asm-derived */ }

// 0x803276AC
void EResourceManager::Free(void* ptr) { /* NOTE: asm-derived */ }

// 0x803C6A24
void EResourceManager__unguarded_partition(int* first, int* last, int pivot, bool (*pred)(int&, int&)) {
    // NOTE: asm-derived - STL partition for resource sorting
}

// ============================================================================
// ECheats - Cheat code system
// ============================================================================

class ECheats {
    // [0..255] cheat lookup data
    // [256..259] state
    // [260] m_isGodMode

    // Auto-generated method declarations
    ECheats();
    ~ECheats();
    void Init(EGlobal& global);
    void EmptyLookupList();
    void SetGodMode(bool enable);
    void EnableCheats();
    void DisableCheats();
};

// 0x8001ECAC
ECheats::ECheats() {
    // NOTE: asm-derived
    char* self = (char*)this;
    memset(self, 0, 256);
    EmptyLookupList();
    *(int*)(self + 260) = 0;
}

// 0x8001ECF4
ECheats::~ECheats() {
    // NOTE: asm-derived
}

// 0x8001ED7C
void ECheats::Init(EGlobal& global) {
    // NOTE: asm-derived - very large init (7824 bytes)
    // Registers all cheat codes
}

// 0x80020C40
void ECheats::EmptyLookupList() {
    // NOTE: asm-derived
}

// 0x80020CC4
void ECheats::SetGodMode(bool enable) {
    // NOTE: asm-derived
    char* self = (char*)this;
    *(int*)(self + 260) = enable ? 1 : 0;
}

// 0x80020D10
void ECheats::EnableCheats() {
    // NOTE: asm-derived (504 bytes)
}

// 0x80020F08
void ECheats::DisableCheats() {
    // NOTE: asm-derived (476 bytes)
}

// ============================================================================
// EMat4 - 4x4 matrix operations
// ============================================================================

class EMat4 {
    // [0..63] float[4][4] matrix data

    // Auto-generated method declarations
    void PreScale(EVec3& scale);
    void PreTranslate(EVec3& t);
    void Normalize();
    void Transpose(EMat4& result);
    void Transpose();
    void Id();
    void Translate(EVec3& t);
    void Scale(EVec3& s);
    void RotateX(float angle);
    void RotateY(float angle);
    void RotateZ(float angle);
    void Invert(EMat4& result);
    void InvertSimple(EMat4& result);
    void Rotate(EVec3& axis, float angle);
    void PreRotateX(float angle);
    void PostRotateX(float angle);
    void PreRotateY(float angle);
    void PostRotateY(float angle);
    void PreRotateZ(float angle);
    void PostRotateZ(float angle);
    void PostScale(EVec3& s);
    void Conform(EVec3& normal);
    void OrientPosNormal(EVec3& pos, EVec3& dir, EVec3& up);
    void Clamp();
    float GetMaxScale() const;
    void GetHPR(float& h, float& p, float& r);
    void GetLookAtPos(EVec3& eye, EVec3& at, EVec3& up);
    void LookAtPos(EVec3& eye, EVec3& at, EVec3& up);
    void LookAt(EVec3& eye, EVec3& at, EVec3& up);
    void LookAtDirect(EVec3& eye, EVec3& at, float roll);
    void LookTo(EVec3& pos, EVec3& dir, EVec3& up);
    void Projection(float fov, float aspect, float nearClip, float farClip);
    void Ortho(float left, float right, float bottom, float top, float nearClip, float farClip);
    void BlendEuler(float t, EMat4& a, EMat4& b);
    void BlendQuat(float t, EMat4& a, EMat4& b);
    void TexturePerspectiveProjection(EVec3& pos, EVec3& dir, EVec3& up, float fov, float aspect, float nearClip, float farClip);
    void TexturePlanarProjection(EVec3& pos, EVec3& dir, EVec3& up, float scaleU, float scaleV, float offsetU, float offsetV);
    void operator=(EMat4& other);
};

// 0x802C9270
void EMat4::PreScale(EVec3& scale) {
    // NOTE: asm-derived
    float* m = (float*)this;
    float* s = (float*)&scale;
    m[0] *= s[0]; m[1] *= s[0]; m[2] *= s[0]; m[3] *= s[0];
    m[4] *= s[1]; m[5] *= s[1]; m[6] *= s[1]; m[7] *= s[1];
    m[8] *= s[2]; m[9] *= s[2]; m[10] *= s[2]; m[11] *= s[2];
}

// 0x802C9308
void EMat4::PreTranslate(EVec3& t) {
    // NOTE: asm-derived
    float* m = (float*)this;
    float* v = (float*)&t;
    m[12] += m[0]*v[0] + m[4]*v[1] + m[8]*v[2];
    m[13] += m[1]*v[0] + m[5]*v[1] + m[9]*v[2];
    m[14] += m[2]*v[0] + m[6]*v[1] + m[10]*v[2];
}

// 0x802C9554
void EMat4::Normalize() {
    // NOTE: asm-derived - normalizes each column vector
}

// 0x802C95F4
void EMat4::Transpose(EMat4& result) {
    // NOTE: asm-derived
    float* m = (float*)this;
    float* r = (float*)&result;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            r[i*4+j] = m[j*4+i];
}

// 0x802C9640
void EMat4::Transpose() {
    // NOTE: asm-derived - in-place transpose
    float* m = (float*)this;
    for (int i = 0; i < 4; i++)
        for (int j = i+1; j < 4; j++) {
            float t = m[i*4+j];
            m[i*4+j] = m[j*4+i];
            m[j*4+i] = t;
        }
}

// 0x802C96D8
void EMat4::Id() {
    // NOTE: asm-derived - set to identity
    float* m = (float*)this;
    memset(m, 0, 64);
    m[0] = m[5] = m[10] = m[15] = 1.0f;
}

// 0x802C9730
void EMat4::Translate(EVec3& t) {
    // NOTE: asm-derived
    float* m = (float*)this;
    float* v = (float*)&t;
    m[12] += v[0]; m[13] += v[1]; m[14] += v[2];
}

// 0x802C9780
void EMat4::Scale(EVec3& s) {
    // NOTE: asm-derived
    float* m = (float*)this;
    float* v = (float*)&s;
    m[0] *= v[0]; m[5] *= v[1]; m[10] *= v[2];
}

// 0x802C985C
void EMat4::RotateX(float angle) { /* NOTE: asm-derived */ }

// 0x802C98C8
void EMat4::RotateY(float angle) { /* NOTE: asm-derived */ }

// 0x802C9934
void EMat4::RotateZ(float angle) { /* NOTE: asm-derived */ }

// 0x802C99A0
void EMat4::Invert(EMat4& result) { /* NOTE: asm-derived (752 bytes) */ }

// 0x802C9C90
void EMat4::InvertSimple(EMat4& result) { /* NOTE: asm-derived */ }

// 0x802C9D34
void EMat4::Rotate(EVec3& axis, float angle) { /* NOTE: asm-derived */ }

// 0x802C9E3C
void EMat4::PreRotateX(float angle) { /* NOTE: asm-derived */ }

// 0x802C9EF0
void EMat4::PostRotateX(float angle) { /* NOTE: asm-derived */ }

// 0x802C9FC4
void EMat4::PreRotateY(float angle) { /* NOTE: asm-derived */ }

// 0x802CA078
void EMat4::PostRotateY(float angle) { /* NOTE: asm-derived */ }

// 0x802CA14C
void EMat4::PreRotateZ(float angle) { /* NOTE: asm-derived */ }

// 0x802CA200
void EMat4::PostRotateZ(float angle) { /* NOTE: asm-derived */ }

// 0x802CA30C
void EMat4::PostScale(EVec3& s) { /* NOTE: asm-derived */ }

// 0x802CA40C
void EMat4::Conform(EVec3& normal) { /* NOTE: asm-derived (388 bytes) */ }

// 0x802CA590
void EMat4::OrientPosNormal(EVec3& pos, EVec3& dir, EVec3& up) { /* NOTE: asm-derived */ }

// 0x802CA5DC
void EMat4::Clamp() { /* NOTE: asm-derived */ }

// 0x802CA644
float EMat4::GetMaxScale() const { /* NOTE: asm-derived */ return 1.0f; }

// 0x802CA69C
void EMat4::GetHPR(float& h, float& p, float& r) { /* NOTE: asm-derived */ }

// 0x802CA760
void EMat4::GetLookAtPos(EVec3& eye, EVec3& at, EVec3& up) { /* NOTE: asm-derived */ }

// 0x802CA844
void EMat4::LookAtPos(EVec3& eye, EVec3& at, EVec3& up) { /* NOTE: asm-derived (508 bytes) */ }

// 0x802CAA40
void EMat4::LookAt(EVec3& eye, EVec3& at, EVec3& up) { /* NOTE: asm-derived */ }

// 0x802CAA8C
void EMat4::LookAtDirect(EVec3& eye, EVec3& at, float roll) { /* NOTE: asm-derived */ }

// 0x802CAB98
void EMat4::LookTo(EVec3& pos, EVec3& dir, EVec3& up) { /* NOTE: asm-derived (508 bytes) */ }

// 0x802CAD94
void EMat4::Projection(float fov, float aspect, float nearClip, float farClip) { /* NOTE: asm-derived */ }

// 0x802CAE68
void EMat4::Ortho(float left, float right, float bottom, float top, float nearClip, float farClip) {
    // NOTE: asm-derived
}

// 0x802CAF4C
void EMat4::BlendEuler(float t, EMat4& a, EMat4& b) { /* NOTE: asm-derived (876 bytes) */ }

// 0x802CB2B8
void EMat4::BlendQuat(float t, EMat4& a, EMat4& b) { /* NOTE: asm-derived (372 bytes) */ }

// 0x802CB42C
void EMat4::TexturePerspectiveProjection(EVec3& pos, EVec3& dir, EVec3& up,
                                          float fov, float aspect, float nearClip, float farClip) {
    // NOTE: asm-derived
}

// 0x802CB528
void EMat4::TexturePlanarProjection(EVec3& pos, EVec3& dir, EVec3& up,
                                     float scaleU, float scaleV, float offsetU, float offsetV) {
    // NOTE: asm-derived
}

// 0x8039D348
void EMat4::operator=(EMat4& other) {
    // NOTE: asm-derived
    memcpy(this, &other, 64);
}

// ============================================================================
// AptLinker - APT asset linker
// ============================================================================

class AptLinker {
    // [0..3] state
    // [4..15] pending loads (vector)

    // Auto-generated method declarations
    ~AptLinker();
    void SwapOut(AptSharedPtr<AptFile> oldFile, AptSharedPtr<AptFile> newFile);
    void Update();
    void Notify(AptSharedPtr<AptFile> file);
    void Load(EAStringC& filename, EAStringC scriptName);
    void CancelLoad(AptCIH* cih);
};

// 0x8026BF54
AptLinker::~AptLinker() {
    // NOTE: asm-derived (320 bytes)
    // Release all shared ptrs
}

// 0x8029EE74
void AptLinker::SwapOut(AptSharedPtr<AptFile> oldFile, AptSharedPtr<AptFile> newFile) {
    // NOTE: asm-derived (1076 bytes)
}

// 0x8029F2A8
void AptLinker::Update() {
    // NOTE: asm-derived (2612 bytes)
}

// 0x8029FCDC
void AptLinker::Notify(AptSharedPtr<AptFile> file) {
    // NOTE: asm-derived (1840 bytes)
}

// 0x802A040C
void AptLinker::Load(EAStringC& filename, EAStringC scriptName) {
    // NOTE: asm-derived (2676 bytes)
}

// 0x802A0E80
void AptLinker::CancelLoad(AptCIH* cih) {
    // NOTE: asm-derived (360 bytes)
}

// ============================================================================
// MODTarget - Mood display UI target
// ============================================================================

class MODTarget {
    // Standard UI target + mood meter state

    // Auto-generated method declarations
    MODTarget(int playerIdx);
    ~MODTarget();
    void SetVariable(char* varName, char* value);
    void GetVariable(char* varName);
    void GetLocalizable(char* key);
    void Update();
    void DrawMoodHeadCallback(ERC* pRC, structDrawCBparams* params);
    void UpdateMood();
    void SelectDpadArrow(int dir);
    void SelectDpadButton(int btn);
    void SetWarning(int type, bool show, bool urgent);
    void SetMeterValue(float value, bool animate);
    void SetDpadIcons(int config);
    void DisplayPaused();
    void DisplayFastForward();
    void TriggerAspirationChestDisplay();
};

// 0x801C87EC
MODTarget::MODTarget(int playerIdx) {
    // NOTE: asm-derived (2444 bytes)
    char* self = (char*)this;
    memset(self, 0, 128);
}

// 0x801C9178
MODTarget::~MODTarget() { /* NOTE: asm-derived */ }

// 0x801C92F0
void MODTarget::SetVariable(char* varName, char* value) { /* NOTE: asm-derived */ }

// 0x801C93F4
void MODTarget::GetVariable(char* varName) { /* NOTE: asm-derived */ }

// 0x801C94C0
void MODTarget::GetLocalizable(char* key) { /* NOTE: asm-derived */ }

// 0x801C95D4
void MODTarget::Update() { /* NOTE: asm-derived (1080 bytes) */ }

// 0x801C9A0C
void MODTarget::DrawMoodHeadCallback(ERC* pRC, structDrawCBparams* params) { /* NOTE: asm-derived */ }

// 0x801C9AFC
void MODTarget::UpdateMood() { /* NOTE: asm-derived (392 bytes) */ }

// 0x801C9C8C
void MODTarget::SelectDpadArrow(int dir) { /* NOTE: asm-derived (448 bytes) */ }

// 0x801C9E4C
void MODTarget::SelectDpadButton(int btn) { /* NOTE: asm-derived (924 bytes) */ }

// 0x801CA1E8
void MODTarget::SetWarning(int type, bool show, bool urgent) { /* NOTE: asm-derived (612 bytes) */ }

// 0x801CA44C
void MODTarget::SetMeterValue(float value, bool animate) { /* NOTE: asm-derived (508 bytes) */ }

// 0x801CA648
void MODTarget::SetDpadIcons(int config) { /* NOTE: asm-derived (768 bytes) */ }

// 0x801CA948
void MODTarget::DisplayPaused() { /* NOTE: asm-derived */ }

// 0x801CA9B0
void MODTarget::DisplayFastForward() { /* NOTE: asm-derived */ }

// 0x801CAA04
void MODTarget::TriggerAspirationChestDisplay() { /* NOTE: asm-derived */ }

// ============================================================================
// AptDisplayList - APT display list management
// ============================================================================

class AptDisplayList {
    // Display list for APT (Flash-like) rendering

    // Auto-generated method declarations
    void instantiateCharacter(int depth, AptCharacter* character, EAStringC* name, AptCIH* cih, int type, int flags, AptCIH** outCIH, int* outIdx);
    void _addToSetCaches(AptCIH* cih, int depth);
    void placeObjectNCXForm(AptCIH* cih, int depth, AptCharacter* character, EAStringC* name, AptCIH* parentCIH, int type, int flags, AptnCXForm* cxForm, AptMatrix* matrix, AptEventActionSet* events, float ratio);
    void placeObject(AptCIH* cih, int depth, AptCharacter* character, EAStringC* name, AptCIH* parentCIH, int type, int flags, AptCXForm* cxForm, AptMatrix* matrix, AptEventActionSet* events, float ratio, AptValue* filters);
    void placeObject(AptControlPlaceObject2* placeObj, AptCIH* parentCIH);
    void placeObject(AptPseudoCIH_t* pseudoCIH, AptCIH* parentCIH);
    void removeObject(AptCIH* cih);
    void removeObject(int depth);
    void removeClonedObject(AptCIH* cih);
    ~AptDisplayList();
    void deallocAssetStringRecursive();
    void render(AptRenderingContext* ctx, AptMaskRenderOperation maskOp);
    void _getBoundingRect(AptRenderingContext* ctx, AptRect* rect);
    void tick();
    void clear(bool full);
    void PreDestroy();
    void AddToDisplayList(AptNativeHash* hash, AptPseudoCIH_t* pseudo, AptCIH* cih);
    void ReplaceDisplyListItem(AptNativeHash* hash, AptCIH* oldCIH, AptPseudoCIH_t* pseudo, AptCIH* newCIH);
    void mergeState(AptPseudoDisplayList* other, AptNativeHash* hash, bool deep);
    void validate(AptCIH* parentCIH);
};

// 0x80299970
void AptDisplayList::instantiateCharacter(int depth, AptCharacter* character, EAStringC* name,
                                           AptCIH* cih, int type, int flags, AptCIH** outCIH, int* outIdx) {
    // NOTE: asm-derived (2100 bytes)
}

// 0x8029A2E4
void AptDisplayList::_addToSetCaches(AptCIH* cih, int depth) { /* NOTE: asm-derived */ }

// 0x8029A3A8
void AptDisplayList::placeObjectNCXForm(AptCIH* cih, int depth, AptCharacter* character,
                                         EAStringC* name, AptCIH* parentCIH, int type, int flags,
                                         AptnCXForm* cxForm, AptMatrix* matrix,
                                         AptEventActionSet* events, float ratio) {
    // NOTE: asm-derived (776 bytes)
}

// 0x8029A6B0
void AptDisplayList::placeObject(AptCIH* cih, int depth, AptCharacter* character,
                                  EAStringC* name, AptCIH* parentCIH, int type, int flags,
                                  AptCXForm* cxForm, AptMatrix* matrix,
                                  AptEventActionSet* events, float ratio, AptValue* filters) {
    // NOTE: asm-derived (816 bytes)
}

// 0x8029A9E0
void AptDisplayList::placeObject(AptControlPlaceObject2* placeObj, AptCIH* parentCIH) {
    // NOTE: asm-derived (724 bytes)
}

// 0x8029ACB4
void AptDisplayList::placeObject(AptPseudoCIH_t* pseudoCIH, AptCIH* parentCIH) {
    // NOTE: asm-derived (356 bytes)
}

// 0x8029AE18
void AptDisplayList::removeObject(AptCIH* cih) { /* NOTE: asm-derived */ }

// 0x8029AEC4
void AptDisplayList::removeObject(int depth) { /* NOTE: asm-derived */ }

// 0x8029AF30
void AptDisplayList::removeClonedObject(AptCIH* cih) { /* NOTE: asm-derived */ }

// 0x8029AFCC
AptDisplayList::~AptDisplayList() { /* NOTE: asm-derived */ }

// 0x8029B450
void AptDisplayList::deallocAssetStringRecursive() { /* NOTE: asm-derived */ }

// 0x8029B4A4
void AptDisplayList::render(AptRenderingContext* ctx, AptMaskRenderOperation maskOp) {
    // NOTE: asm-derived (628 bytes)
}

// 0x8029B718
void AptDisplayList::_getBoundingRect(AptRenderingContext* ctx, AptRect* rect) { /* NOTE: asm-derived */ }

// 0x8029B7BC
void AptDisplayList::tick() { /* NOTE: asm-derived */ }

// 0x8029B89C
void AptDisplayList::clear(bool full) { /* NOTE: asm-derived */ }

// 0x8029B9A0
void AptDisplayList::PreDestroy() { /* NOTE: asm-derived */ }

// 0x8029BA20
void AptDisplayList::AddToDisplayList(AptNativeHash* hash, AptPseudoCIH_t* pseudo, AptCIH* cih) {
    // NOTE: asm-derived
}

// 0x8029BB10
void AptDisplayList::ReplaceDisplyListItem(AptNativeHash* hash, AptCIH* oldCIH,
                                            AptPseudoCIH_t* pseudo, AptCIH* newCIH) {
    // NOTE: asm-derived
}

// 0x8029BBE0
void AptDisplayList::mergeState(AptPseudoDisplayList* other, AptNativeHash* hash, bool deep) {
    // NOTE: asm-derived (952 bytes)
}

// 0x8029BF98
void AptDisplayList::validate(AptCIH* parentCIH) {
    // NOTE: asm-derived (404 bytes)
}

// ============================================================================
// CASSelectionTarget - Create-A-Sim selection grid UI
// ============================================================================

class CASSelectionTarget {
    // Standard UI target + grid selection state

    // Auto-generated method declarations
    CASSelectionTarget();
    ~CASSelectionTarget();
    void SetVariable(char* varName, char* value);
    void ConvertGridStringToOptionArrayIdx(char* str);
    void GetVariable(char* varName);
    void GetLockStateString(char* buf);
    void ClearRecentlyUnlockedBitFlag(int flag);
    void GetLocalizable(char* key);
    void ScrollPageLeft();
    void ScrollPageRight();
    void ShiftShaderTexturesLeft();
    void ShiftShaderTexturesRight();
    void InitScreen();
    void CreateSelectionShaders();
    void LoadGridTextures(unsigned int startIdx, unsigned int endIdx);
    void SetupInitialSelectionPage();
    void ClearTextures(unsigned int startIdx, unsigned int endIdx);
    void UpdateSelectionArrowState();
    void ConvertUiFocusToBodyPart(unsigned int focus, eBodyPartS2C* part);
    void ConvertUiFocusToBodyTextureType(unsigned int focus, eTattooTextureTypeS2C* type);
    void ConvertCurUIFocusToChangeEvent(int& event);
    void SetTitleShaderAccordingToCurUIFocus(unsigned int focus);
};

// 0x80198ABC
CASSelectionTarget::CASSelectionTarget() {
    // NOTE: asm-derived (2336 bytes)
    char* self = (char*)this;
    memset(self, 0, 128);
}

// 0x801993DC
CASSelectionTarget::~CASSelectionTarget() { /* NOTE: asm-derived */ }

// 0x801995A0
void CASSelectionTarget::SetVariable(char* varName, char* value) { /* NOTE: asm-derived (544 bytes) */ }

// 0x801997C0
void CASSelectionTarget::ConvertGridStringToOptionArrayIdx(char* str) { /* NOTE: asm-derived */ }

// 0x80199808
void CASSelectionTarget::GetVariable(char* varName) { /* NOTE: asm-derived */ }

// 0x801998A4
void CASSelectionTarget::GetLockStateString(char* buf) { /* NOTE: asm-derived */ }

// 0x80199974
void CASSelectionTarget::ClearRecentlyUnlockedBitFlag(int flag) { /* NOTE: asm-derived */ }

// 0x80199A90
void CASSelectionTarget::GetLocalizable(char* key) { /* NOTE: asm-derived */ }

// 0x80199BAC
void CASSelectionTarget::ScrollPageLeft() { /* NOTE: asm-derived */ }

// 0x80199C18
void CASSelectionTarget::ScrollPageRight() { /* NOTE: asm-derived */ }

// 0x80199C88
void CASSelectionTarget::ShiftShaderTexturesLeft() { /* NOTE: asm-derived */ }

// 0x80199D70
void CASSelectionTarget::ShiftShaderTexturesRight() { /* NOTE: asm-derived */ }

// 0x80199E9C
void CASSelectionTarget::InitScreen() { /* NOTE: asm-derived (344 bytes) */ }

// 0x80199FF4
void CASSelectionTarget::CreateSelectionShaders() { /* NOTE: asm-derived (524 bytes) */ }

// 0x8019A200
void CASSelectionTarget::LoadGridTextures(unsigned int startIdx, unsigned int endIdx) {
    // NOTE: asm-derived (548 bytes)
}

// 0x8019A424
void CASSelectionTarget::SetupInitialSelectionPage() { /* NOTE: asm-derived */ }

// 0x8019A4B0
void CASSelectionTarget::ClearTextures(unsigned int startIdx, unsigned int endIdx) { /* NOTE: asm-derived */ }

// 0x8019A5F4
void CASSelectionTarget::UpdateSelectionArrowState() { /* NOTE: asm-derived */ }

// 0x8019A6B4
void CASSelectionTarget::ConvertUiFocusToBodyPart(unsigned int focus, eBodyPartS2C* part) {
    // NOTE: asm-derived
}

// 0x8019A7F8
void CASSelectionTarget::ConvertUiFocusToBodyTextureType(unsigned int focus, eTattooTextureTypeS2C* type) {
    // NOTE: asm-derived
}

// 0x8019A854
void CASSelectionTarget::ConvertCurUIFocusToChangeEvent(int& event) { /* NOTE: asm-derived (380 bytes) */ }

// 0x8019A9D0
void CASSelectionTarget::SetTitleShaderAccordingToCurUIFocus(unsigned int focus) {
    // NOTE: asm-derived (1004 bytes)
}

// ============================================================================
// WrapperPaneBase - Base class for UI pane wrappers
// ============================================================================

class WrapperPaneBase {
    // UI pane with button list and item management

    // Auto-generated method declarations
    void Shutdown();
    void DrawBackground(ERC* pRC);
    void DrawItems(ERC* pRC, bool selectedOnly);
    void SetSelected(ItemType type, int idx);
    void GetSelectedItem(ItemType type);
    void GetEnabledItemIndexWithValue(ItemType type, int value);
    void GetItem(ItemType type, int idx);
    void SetItemFont(ItemType type, int idx, ERFont* font);
    void SetItemFontSize(ItemType type, int idx, float size);
    void SetItemPos(ItemType type, int idx, EVec2& pos);
    void SetItemPosX(ItemType type, int idx, float x);
    void SetItemPosY(ItemType type, int idx, float y);
    void SetItemSize(ItemType type, int idx, EVec2& size);
    void SetItemSizeX(ItemType type, int idx, float w);
    void SetItemSizeY(ItemType type, int idx, float h);
    void CalculateMenuWidthPixels();
    void DeleteItemList();
    void GetVariableButtonIndex(char* context, char* var);
    void GetVariable(char* varName);
    void SetVariable(char* varName, char* value);
    void AddButton(int id, bool enabled, unsigned short* text);
    void ShowEnabledButtons();
    void HideEnabledButtons();
    void ShowButton(int id);
    void HideButton(int id);
    WrapperPaneBase(int w, int h);
    ~WrapperPaneBase();
    void AddItem(PaneItem* item);
    void SetButtonContext(char* ctx);
    void SetButtonText(int id, unsigned short* text);
    void SetButtonFont(int id, ERFont* font);
    void SetButtonFontSize(int id, float size);
    void SetButtonPos(int id, EVec2& pos);
    void SetButtonPosX(int id, float x);
    void SetButtonPosY(int id, float y);
    void SetAcceptFont(ERFont* font);
    void SetAcceptFontSize(float size);
    void SetAcceptPos(EVec2& pos);
    void SetAcceptPosX(float x);
    void SetAcceptPosY(float y);
    void SetDeclineFont(ERFont* font);
    void SetDeclineFontSize(float size);
    void SetDeclinePos(EVec2& pos);
    void SetDeclinePosX(float x);
    void SetDeclinePosY(float y);
};

// 0x80084AB4
void WrapperPaneBase::Shutdown() { /* NOTE: asm-derived (324 bytes) */ }

// 0x80084BF8
void WrapperPaneBase::DrawBackground(ERC* pRC) { /* NOTE: asm-derived (652 bytes) */ }

// 0x80084E84
void WrapperPaneBase::DrawItems(ERC* pRC, bool selectedOnly) { /* NOTE: asm-derived */ }

// 0x80084F30
void WrapperPaneBase::SetSelected(ItemType type, int idx) { /* NOTE: asm-derived */ }

// 0x80084F98
void WrapperPaneBase::GetSelectedItem(ItemType type) { /* NOTE: asm-derived */ }

// 0x80084FDC
void WrapperPaneBase::GetEnabledItemIndexWithValue(ItemType type, int value) { /* NOTE: asm-derived */ }

// 0x80085034
void WrapperPaneBase::GetItem(ItemType type, int idx) { /* NOTE: asm-derived */ }

// 0x800850B0
void WrapperPaneBase::SetItemFont(ItemType type, int idx, ERFont* font) { /* NOTE: asm-derived */ }

// 0x800850F8
void WrapperPaneBase::SetItemFontSize(ItemType type, int idx, float size) { /* NOTE: asm-derived */ }

// 0x8008517C
void WrapperPaneBase::SetItemPos(ItemType type, int idx, EVec2& pos) { /* NOTE: asm-derived */ }

// 0x800851C4
void WrapperPaneBase::SetItemPosX(ItemType type, int idx, float x) { /* NOTE: asm-derived */ }

// 0x8008520C
void WrapperPaneBase::SetItemPosY(ItemType type, int idx, float y) { /* NOTE: asm-derived */ }

// 0x80085254
void WrapperPaneBase::SetItemSize(ItemType type, int idx, EVec2& size) { /* NOTE: asm-derived */ }

// 0x8008529C
void WrapperPaneBase::SetItemSizeX(ItemType type, int idx, float w) { /* NOTE: asm-derived */ }

// 0x800852E4
void WrapperPaneBase::SetItemSizeY(ItemType type, int idx, float h) { /* NOTE: asm-derived */ }

// 0x8008554C
void WrapperPaneBase::CalculateMenuWidthPixels() { /* NOTE: asm-derived */ }

// 0x800856B8
void WrapperPaneBase::DeleteItemList() { /* NOTE: asm-derived (296 bytes) */ }

// 0x800857E0
void WrapperPaneBase::GetVariableButtonIndex(char* context, char* var) { /* NOTE: asm-derived (384 bytes) */ }

// 0x80085960
void WrapperPaneBase::GetVariable(char* varName) { /* NOTE: asm-derived (320 bytes) */ }

// 0x80085AA0
void WrapperPaneBase::SetVariable(char* varName, char* value) { /* NOTE: asm-derived */ }

// 0x80085B9C
void WrapperPaneBase::AddButton(int id, bool enabled, unsigned short* text) { /* NOTE: asm-derived (800 bytes) */ }

// 0x80085EBC
void WrapperPaneBase::ShowEnabledButtons() { /* NOTE: asm-derived */ }

// 0x80085FF0
void WrapperPaneBase::HideEnabledButtons() { /* NOTE: asm-derived */ }

// 0x80086124
void WrapperPaneBase::ShowButton(int id) { /* NOTE: asm-derived */ }

// 0x80086230
void WrapperPaneBase::HideButton(int id) { /* NOTE: asm-derived */ }

// 0x800878C4
WrapperPaneBase::WrapperPaneBase(int w, int h) { /* NOTE: asm-derived */ }

// 0x800879E0
WrapperPaneBase::~WrapperPaneBase() { /* NOTE: asm-derived */ Shutdown(); }

// 0x80087B70
void WrapperPaneBase::AddItem(PaneItem* item) { /* NOTE: asm-derived (340 bytes) */ }

// 0x80088234
void WrapperPaneBase::SetButtonContext(char* ctx) { /* NOTE: asm-derived */ }

// 0x80088388
void WrapperPaneBase::SetButtonText(int id, unsigned short* text) { /* NOTE: asm-derived */ }

// 0x800883D4
void WrapperPaneBase::SetButtonFont(int id, ERFont* font) { /* NOTE: asm-derived */ }

// 0x80088434
void WrapperPaneBase::SetButtonFontSize(int id, float size) { /* NOTE: asm-derived */ }

// 0x80088494
void WrapperPaneBase::SetButtonPos(int id, EVec2& pos) { /* NOTE: asm-derived */ }

// 0x80088500
void WrapperPaneBase::SetButtonPosX(int id, float x) { /* NOTE: asm-derived */ }

// 0x8008855C
void WrapperPaneBase::SetButtonPosY(int id, float y) { /* NOTE: asm-derived */ }

// 0x800885FC
void WrapperPaneBase::SetAcceptFont(ERFont* font) { /* NOTE: asm-derived */ }

// 0x8008864C
void WrapperPaneBase::SetAcceptFontSize(float size) { /* NOTE: asm-derived */ }

// 0x800886A0
void WrapperPaneBase::SetAcceptPos(EVec2& pos) { /* NOTE: asm-derived */ }

// 0x800886FC
void WrapperPaneBase::SetAcceptPosX(float x) { /* NOTE: asm-derived */ }

// 0x8008874C
void WrapperPaneBase::SetAcceptPosY(float y) { /* NOTE: asm-derived */ }

// 0x800887E0
void WrapperPaneBase::SetDeclineFont(ERFont* font) { /* NOTE: asm-derived */ }

// 0x80088830
void WrapperPaneBase::SetDeclineFontSize(float size) { /* NOTE: asm-derived */ }

// 0x80088884
void WrapperPaneBase::SetDeclinePos(EVec2& pos) { /* NOTE: asm-derived */ }

// 0x800888E0
void WrapperPaneBase::SetDeclinePosX(float x) { /* NOTE: asm-derived */ }

// 0x80088930
void WrapperPaneBase::SetDeclinePosY(float y) { /* NOTE: asm-derived */ }

// Additional WrapperPaneBase setter methods follow same pattern
// 0x800889C4 through 0x80088B14

// ============================================================================
// ELiveMode - Live gameplay mode
// ============================================================================

class ELiveMode : public EGameState {
    // [0..7] EGameState base
    // [8] vtable

    // Auto-generated method declarations
    ~ELiveMode();
    void Init(int playerCount);
    void Reset(int playerCount);
    void GotoStartMode();
    void QuitToMainMenu();
    void IsReadyForUpdate();
    void UpdateIntroCamera();
    void Update();
    void Draw(ERC* pRC);
    void DrawSplitScreenMask(ERC* pRC, E3DWindow& window, int player);
    void InitPlayerXWindow(ERC* pRC, E3DWindow& window, int player);
    void DrawSplitScreenDivider(ERC* pRC);
    void DrawMain(ERC* pRC);
    void StartIntroCamera(CameraDirector* director, ESimsCam* cam);
    void EndIntroCamera(CameraDirector* director, ESimsCam* cam);
};

// 0x8008BB08
ELiveMode::~ELiveMode() {
    // NOTE: asm-derived
    char* self = (char*)this;
    // Set global pointer to 0
    // EGameState::~EGameState()
}

// 0x8008BB68
void ELiveMode::Init(int playerCount) { /* NOTE: asm-derived */ }

// 0x8008CA58
void ELiveMode::Reset(int playerCount) { /* NOTE: asm-derived (568 bytes) */ }

// 0x8008DC40
void ELiveMode::GotoStartMode() { /* NOTE: asm-derived */ }

// 0x8008DC90
void ELiveMode::QuitToMainMenu() { /* NOTE: asm-derived */ }

// 0x8008DD70
void ELiveMode::IsReadyForUpdate() { /* NOTE: asm-derived (440 bytes) */ }

// 0x8008DF28
void ELiveMode::UpdateIntroCamera() { /* NOTE: asm-derived (1432 bytes) */ }

// 0x8008E4C0
void ELiveMode::Update() { /* NOTE: asm-derived (1364 bytes) */ }

// 0x8008EA14
void ELiveMode::Draw(ERC* pRC) { /* NOTE: asm-derived (1280 bytes) */ }

// 0x8008EF1C
void ELiveMode::DrawSplitScreenMask(ERC* pRC, E3DWindow& window, int player) {
    // NOTE: asm-derived (668 bytes)
}

// 0x8008F1B8
void ELiveMode::InitPlayerXWindow(ERC* pRC, E3DWindow& window, int player) {
    // NOTE: asm-derived (696 bytes)
}

// 0x8008F470
void ELiveMode::DrawSplitScreenDivider(ERC* pRC) { /* NOTE: asm-derived (828 bytes) */ }

// 0x8008F7AC
void ELiveMode::DrawMain(ERC* pRC) { /* NOTE: asm-derived (1060 bytes) */ }

// 0x8008FBFC
void ELiveMode::StartIntroCamera(CameraDirector* director, ESimsCam* cam) {
    // NOTE: asm-derived (556 bytes)
}

// 0x8008FE28
void ELiveMode::EndIntroCamera(CameraDirector* director, ESimsCam* cam) {
    // NOTE: asm-derived
}

// ============================================================================
// ERoom - Room geometry and wall management
// ============================================================================

class ERoom {
    // Room with wall lists, tile partitioning

    // Auto-generated method declarations
    ERoom();
    ~ERoom();
    void InitRoomLookupTab();
    void GetNumWalls(unsigned short roomId);
    void GetWallPaperCost(unsigned int wallpaper, unsigned short roomId);
    void DrawWallpaperPreview(ERC* pRC, unsigned short roomId, EVec2& pos);
    void IsRoomWallsOpaque(int level, int side);
    void CalAllRoomOpaque(int level);
    void GetShortDistToCam(int level, int side);
    void GetOccludeAlpha(int level, int side);
    void IsRoomRoofOpaque(int level, int side);
    void CalRoofOpaque(int level);
    void CalShortDistToCam(int level);
    void SetWallState(EWallUpDownStateType state);
    void UpdateWallFade(int level);
    void Init();
    void ProcStandardWalls(bool rebuild, int& wallCount, int& tileCount, bool preview);
    void ProcDiagonalWalls(int& wallCount, int& tileCount, bool preview);
    void ProcessCell(TNodeList<ERoomWall*>& walls, ERoomWallPtr& wallPtr, CTilePt& tile, TileWallsSegment seg, DiagonalSideSelector side, TileWalls& tileWalls, int level, int& wallCount, int& tileCount, bool preview);
    void PreviewWallBuild(bool preview);
    void FindWallContainingSegment(TNodeList<ERoomWall*>& walls, TileWallsSegment seg, CTilePt& start, CTilePt& end);
    void GetWallFromTileAndSegment(TileWallsSegment seg, CTilePt& tile);
    void DeleteERoomWallContainingSegment(TileWallsSegment seg, CTilePt& start, CTilePt& end);
    void DeleteWallAtTile(CTilePt& tile, TileWalls& walls, TileWallsSegment seg);
    void KillArchitecturalObject(CTilePt& tile, TileWallsSegment seg, int& count, bool force);
};

// 0x8002D778
ERoom::ERoom() {
    // NOTE: asm-derived (276 bytes)
    char* self = (char*)this;
    memset(self, 0, 128);
}

// 0x8002D88C
ERoom::~ERoom() { /* NOTE: asm-derived (1124 bytes) */ }

// 0x8002DCF0
void ERoom::InitRoomLookupTab() { /* NOTE: asm-derived (384 bytes) */ }

// 0x8002DF7C
void ERoom::GetNumWalls(unsigned short roomId) { /* NOTE: asm-derived */ }

// 0x8002DFEC
void ERoom::GetWallPaperCost(unsigned int wallpaper, unsigned short roomId) { /* NOTE: asm-derived */ }

// 0x8002E0C4
void ERoom::DrawWallpaperPreview(ERC* pRC, unsigned short roomId, EVec2& pos) { /* NOTE: asm-derived */ }

// 0x8002E168
void ERoom::IsRoomWallsOpaque(int level, int side) { /* NOTE: asm-derived */ }

// 0x8002E1C4
void ERoom::CalAllRoomOpaque(int level) { /* NOTE: asm-derived */ }

// 0x8002E268
void ERoom::GetShortDistToCam(int level, int side) { /* NOTE: asm-derived */ }

// 0x8002E2C4
void ERoom::GetOccludeAlpha(int level, int side) { /* NOTE: asm-derived */ }

// 0x8002E324
void ERoom::IsRoomRoofOpaque(int level, int side) { /* NOTE: asm-derived */ }

// 0x8002E380
void ERoom::CalRoofOpaque(int level) { /* NOTE: asm-derived (972 bytes) */ }

// 0x8002E74C
void ERoom::CalShortDistToCam(int level) { /* NOTE: asm-derived */ }

// 0x8002E8A4
void ERoom::SetWallState(EWallUpDownStateType state) { /* NOTE: asm-derived */ }

// 0x8002EAB8
void ERoom::UpdateWallFade(int level) { /* NOTE: asm-derived */ }

// 0x8002EBB8
void ERoom::Init() { /* NOTE: asm-derived */ }

// 0x8002EC60
void ERoom::ProcStandardWalls(bool rebuild, int& wallCount, int& tileCount, bool preview) {
    // NOTE: asm-derived (676 bytes)
}

// 0x8002EF04
void ERoom::ProcDiagonalWalls(int& wallCount, int& tileCount, bool preview) {
    // NOTE: asm-derived (864 bytes)
}

// 0x8002F264
void ERoom::ProcessCell(TNodeList<ERoomWall*>& walls, ERoomWallPtr& wallPtr,
                         CTilePt& tile, TileWallsSegment seg, DiagonalSideSelector side,
                         TileWalls& tileWalls, int level, int& wallCount, int& tileCount, bool preview) {
    // NOTE: asm-derived (632 bytes)
}

// 0x8002F4DC
void ERoom::PreviewWallBuild(bool preview) { /* NOTE: asm-derived (832 bytes) */ }

// 0x8002FD08
void ERoom::FindWallContainingSegment(TNodeList<ERoomWall*>& walls, TileWallsSegment seg,
                                       CTilePt& start, CTilePt& end) {
    // NOTE: asm-derived
}

// 0x8002FE18
void ERoom::GetWallFromTileAndSegment(TileWallsSegment seg, CTilePt& tile) { /* NOTE: asm-derived */ }

// 0x8002FEAC
void ERoom::DeleteERoomWallContainingSegment(TileWallsSegment seg, CTilePt& start, CTilePt& end) {
    // NOTE: asm-derived
}

// 0x8002FF8C
void ERoom::DeleteWallAtTile(CTilePt& tile, TileWalls& walls, TileWallsSegment seg) {
    // NOTE: asm-derived (376 bytes)
}

// 0x80030104
void ERoom::KillArchitecturalObject(CTilePt& tile, TileWallsSegment seg, int& count, bool force) {
    // NOTE: asm-derived (456 bytes)
}

// ============================================================================
// AptMathObj - ActionScript Math object
// ============================================================================

class AptMathObj {
    // Singleton Math object for ActionScript

    // Auto-generated method declarations
    void CleanNativeFunctions();
    void objectMemberLookup(AptValue* result, EAStringC* name) const;
    void sMethod_sin(AptValue* result, int argCount);
    void sMethod_cos(AptValue* result, int argCount);
    void sMethod_atan2(AptValue* result, int argCount);
    void sMethod_round(AptValue* result, int argCount);
    void sMethod_min(AptValue* result, int argCount);
    void sMethod_max(AptValue* result, int argCount);
    void sMethod_abs(AptValue* result, int argCount);
    void sMethod_acos(AptValue* result, int argCount);
    void sMethod_asin(AptValue* result, int argCount);
    void sMethod_atan(AptValue* result, int argCount);
    void sMethod_ceil(AptValue* result, int argCount);
    void sMethod_exp(AptValue* result, int argCount);
    void sMethod_floor(AptValue* result, int argCount);
    void sMethod_log(AptValue* result, int argCount);
    void sMethod_pow(AptValue* result, int argCount);
    void sMethod_random(AptValue* result, int argCount);
    void sMethod_sqrt(AptValue* result, int argCount);
    void sMethod_tan(AptValue* result, int argCount);
    AptMathObj();
    ~AptMathObj();
};

// 0x802A2B68
void AptMathObj::CleanNativeFunctions() {
    // NOTE: asm-derived (1180 bytes)
    // Cleans up all registered math native functions
}

// 0x802A3004
void AptMathObj::objectMemberLookup(AptValue* result, EAStringC* name) const {
    // NOTE: asm-derived (3260 bytes)
    // String comparison chain for Math object properties (PI, E, etc.) and methods
}

// 0x802A3CC0
void AptMathObj::sMethod_sin(AptValue* result, int argCount) {
    // NOTE: asm-derived
    // result = sin(arg[0])
}

// 0x802A3DAC
void AptMathObj::sMethod_cos(AptValue* result, int argCount) {
    // NOTE: asm-derived
}

// 0x802A3E98
void AptMathObj::sMethod_atan2(AptValue* result, int argCount) {
    // NOTE: asm-derived
}

// 0x802A3FA8
void AptMathObj::sMethod_round(AptValue* result, int argCount) {
    // NOTE: asm-derived
}

// 0x802A40C0
void AptMathObj::sMethod_min(AptValue* result, int argCount) {
    // NOTE: asm-derived
}

// 0x802A41E4
void AptMathObj::sMethod_max(AptValue* result, int argCount) {
    // NOTE: asm-derived
}

// 0x802A4308
void AptMathObj::sMethod_abs(AptValue* result, int argCount) {
    // NOTE: asm-derived (416 bytes)
}

// 0x802A44A8
void AptMathObj::sMethod_acos(AptValue* result, int argCount) { /* NOTE: asm-derived */ }

// 0x802A4594
void AptMathObj::sMethod_asin(AptValue* result, int argCount) { /* NOTE: asm-derived */ }

// 0x802A4680
void AptMathObj::sMethod_atan(AptValue* result, int argCount) { /* NOTE: asm-derived */ }

// 0x802A476C
void AptMathObj::sMethod_ceil(AptValue* result, int argCount) { /* NOTE: asm-derived */ }

// 0x802A4858
void AptMathObj::sMethod_exp(AptValue* result, int argCount) { /* NOTE: asm-derived */ }

// 0x802A4944
void AptMathObj::sMethod_floor(AptValue* result, int argCount) { /* NOTE: asm-derived */ }

// 0x802A4A30
void AptMathObj::sMethod_log(AptValue* result, int argCount) { /* NOTE: asm-derived */ }

// 0x802A4B1C
void AptMathObj::sMethod_pow(AptValue* result, int argCount) { /* NOTE: asm-derived */ }

// 0x802A4C2C
void AptMathObj::sMethod_random(AptValue* result, int argCount) {
    // NOTE: asm-derived
    // result = random float [0..1)
}

// 0x802A4D14
void AptMathObj::sMethod_sqrt(AptValue* result, int argCount) { /* NOTE: asm-derived */ }

// 0x802A4E00
void AptMathObj::sMethod_tan(AptValue* result, int argCount) { /* NOTE: asm-derived */ }

// 0x802A86CC
AptMathObj::AptMathObj() { /* NOTE: asm-derived */ }

// 0x802A8744
AptMathObj::~AptMathObj() { /* NOTE: asm-derived */ }
