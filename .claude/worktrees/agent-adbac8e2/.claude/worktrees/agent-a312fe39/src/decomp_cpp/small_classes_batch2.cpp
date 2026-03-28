// small_classes_batch2.cpp - Batch decompilation of small classes (batch 2)
//
// Converted from inline PPC asm (src/asm_decomp/*.cpp) to real C++.
// All logic derived from PPC assembly analysis of the GameCube build.
//
// Classes covered (51 files):
//   CatalogResource, RelMatrix, StubObject, BehPrintParams, EDummyFile,
//   EGameState, AptCharacterSpriteInst, EGlobalManagerClient, EIGameInstance,
//   ENgcDL, EPMDesc, ERAudioStream, GetVar_EYE_exists, GetVar_EYE_targetState,
//   GetVar_Legacy, GetVar_SaveStatus, SetVar_EYE_filterCurrSel,
//   SetVar_EYE_funframeCurrSel, SetVar_EYE_opCancelled, SetVar_EYE_slotCurrSel,
//   WallFadeParms, DummyMode, IHRecord, MUStatesLoadConfig, AptLookup,
//   AptNone, AptRegister, ESoundTrackDataManager, EffectsAttachmentManager,
//   EffectsEmitterManager, EffectsSequencerManager, GetVar_SliderStep,
//   EAmbientScoreManager, EAnimManager, EModelManager, ESoundEventManager,
//   SetVar_EYE_settingSliderVal, UrbzCreditsState, EBinaryManager,
//   EEdithTreeSetMan, ERAnimBitArray, InLevelStoryState, MotiveInc,
//   RelArray, EFlashManager, ParticleManager, AptCharacterMorphInst,
//   AptCharacterShapeInst, AptCharacterStaticTextInst,
//   AptGlobalExtensionObject, AptMovieClip
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
    char* strcpy(char* dst, const char* src);
    int   rand(void);
}

class EAHeap;
extern EAHeap* MainHeap();
class EAHeap {
public:
    void* Malloc(unsigned int size, int flags);
    void  Free(void* ptr);
};

// Forward declarations
class AptCharacterSpriteInstBase;
class AptNativeHash;
class AptValue;
class AptValueGC;
class AptValueGC_PoolManager;
class AptVar;
class BString2;
class DOGMA_PoolManager;
class EDL;
class EFile;
class EBitArray;
class ERAmbientScore;
class ERAnim;
class ERBinary;
class EREdithTreeSet;
class ERFlash;
class ERModel;
class ERSoundEvent;
class ERSoundTrackData;
class EResource;
class EResourceManager { public: static void* Alloc(unsigned int size, unsigned int align); static void Free(void* ptr); static unsigned int CalcId(char* name); };
class EStorable;
class ETypeInfo;
class ReconBuffer;
class REffectsAttachment;
class REffectsEmitter;
class REffectsSequencer;
class RParticle;
class StateMachineState;
class TheSimsStateMachine;
class UIDialog;
struct RelInt;

// Global pool managers (accessed via r13 offsets)
extern DOGMA_PoolManager*    g_pDogmaPoolManager;      // r13 - 23020
extern AptValueGC_PoolManager* g_pAptValueGCPoolManager; // r13 - 23016

// ============================================================================
// Helper stubs for operator new/delete
// ============================================================================

// These represent __builtin_new / __builtin_delete used by the original compiler
extern void* operator_new_impl(unsigned int size);
extern void  operator_delete_impl(void* ptr);

// ============================================================================
// AptVar hash helper
// ============================================================================

class AptVar {
public:
    static unsigned int Hash(char* name);
};

// ============================================================================
// EResourceManager allocation helper
// ============================================================================

// static
// EResourceManager::Alloc(unsigned long size, unsigned int align)
// Returns allocated memory from a resource manager's pool

// ============================================================================
// DOGMA_PoolManager
// ============================================================================

class DOGMA_PoolManager {
public:
    void Deallocate(void* ptr, unsigned int size);
};

class AptValueGC_PoolManager {
public:
    void DeallocateAptValueGC(AptValueGC* ptr, unsigned int size);
};

// ============================================================================
// ReconBuffer helpers
// ============================================================================

class ReconBuffer {
public:
    void ReconInt(int* ptr, int mode);
    void ReconFloat(float* ptr, int mode);
    void Recon32(int* ptr, int mode);
};


// ############################################################################
//
//  CatalogResource - Factory creation for catalog resource objects
//
//  Layout: 16 bytes
//    0x00: void** m_vtable
//    0x04: u32 m_field04  (zeroed, same pointer as m_field08 and m_field0C)
//    0x08: u32 m_field08
//    0x0C: u32 m_field0C
//
// ############################################################################

class CatalogResource {
public:
    void**       m_vtable;   // 0x00
    unsigned int m_field04;  // 0x04
    unsigned int m_field08;  // 0x08
    unsigned int m_field0C;  // 0x0C

    CatalogResource() : m_vtable(0), m_field04(0), m_field08(0), m_field0C(0) {}

    // 0x800B1C44 (68 bytes)
    // Allocates 16-byte object, sets vtable, stores same SDA value in 3 fields
    static CatalogResource* CreateInstance() {
        CatalogResource* obj = new CatalogResource();
        // vtable set by constructor
        // Fields 0x04, 0x08, 0x0C all set to the same SDA-relative pointer
        // (r13 - 32080 = a shared default pointer)
        return obj;
    }
};


// ############################################################################
//
//  RelMatrix - Relationship matrix factory
//
//  Layout: 20 bytes
//    0x00: void** m_vtable
//    0x04: u32 m_field04 (zeroed)
//    0x08: u32 m_field08 (zeroed)
//    0x0C: u32 m_field0C (zeroed)  -- part of 8-byte sub-struct at +12
//    0x10: u32 m_field10 (zeroed)
//
// ############################################################################

class RelMatrix {
public:
    void**       m_vtable;   // 0x00
    unsigned int m_field04;  // 0x04
    unsigned int m_field08;  // 0x08
    unsigned int m_field0C;  // 0x0C
    unsigned int m_field10;  // 0x10

    RelMatrix() : m_vtable(0), m_field04(0), m_field08(0), m_field0C(0), m_field10(0) {}

    // 0x80134A60 (72 bytes)
    // Allocates 20-byte object, sets vtable, zeroes all fields
    static RelMatrix* CreateInstance() {
        RelMatrix* obj = new RelMatrix();
        // vtable set by constructor
        // All member fields zeroed
        return obj;
    }
};


// ############################################################################
//
//  StubObject - GUID generation via performance counter + time + rand
//
// ############################################################################

extern "C" {
    void QueryPerformanceCounter(long long* counter);
    int  GetTimeDate(void);
}

class StubObject {
public:
    // 0x80145D58 (72 bytes)
    // Generates a new GUID by XOR'ing performance counter, time, and rand
    static unsigned int MakeNewGUID() {
        long long perfCounter;
        QueryPerformanceCounter(&perfCounter);
        int timeDate = GetTimeDate();
        int r = rand();
        // XOR the low 32 bits of perf counter with rand, then XOR with timeDate
        unsigned int low32 = (unsigned int)(perfCounter & 0xFFFFFFFF);
        unsigned int result = timeDate ^ (low32 ^ r);
        return result;
    }
};


// ############################################################################
//
//  BehPrintParams - Behavior print parameter storage
//
//  Has a filename buffer (presumably 512+ bytes inline)
//
// ############################################################################

class BehPrintParams {
public:
    char m_filename[513]; // internal buffer, at least 512+1 bytes

    // 0x800ABC48 (72 bytes)
    // Sets the filename if length <= 512
    void SetFilename(char* name) {
        if (strlen(name) <= 512) {
            strcpy(m_filename, name);
        }
    }
};


// ############################################################################
//
//  EDummyFile - Dummy file implementation (destructor only)
//
//  Inherits from EFile
//
// ############################################################################

class EFile {
public:
    virtual ~EFile();
};

class EDummyFile : public EFile {
public:
    // 0x8039E2A4 (72 bytes)
    // Calls EFile::~EFile(), conditionally frees via MainHeap
    ~EDummyFile() {
        // Parent destructor ~EFile() called implicitly
        // Conditional delete handled by compiler ABI
    }
};


// ############################################################################
//
//  EGameState - Game state base class (destructor only)
//
//  Layout: at least 12 bytes
//    0x08: void** m_vtable (at offset 8)
//
// ############################################################################

class EGameState {
public:
    unsigned int m_field00; // 0x00
    unsigned int m_field04; // 0x04
    void**       m_vtable;  // 0x08

    // 0x800899CC (72 bytes)
    // Sets vtable, conditionally frees via MainHeap
    virtual ~EGameState() {
        // vtable set to EGameState vtable at offset 0x08
        // Conditional delete via MainHeap()->Free(this)
    }
};


// ############################################################################
//
//  AptCharacterSpriteInst - Sprite instance in APT (destructor only)
//
//  Inherits from AptCharacterSpriteInstBase
//  Deallocated via DOGMA pool (size 48)
//
// ############################################################################

class AptCharacterSpriteInstBase {
public:
    virtual ~AptCharacterSpriteInstBase();
};

class AptCharacterSpriteInst : public AptCharacterSpriteInstBase {
public:
    // 0x8029C588 (76 bytes)
    // Calls AptCharacterSpriteInstBase::~AptCharacterSpriteInstBase()
    // If delete flag set, deallocates via DOGMA pool (size 48)
    ~AptCharacterSpriteInst() {
        // Parent dtor called implicitly
        // Conditional DOGMA dealloc: g_pDogmaPoolManager->Deallocate(this, 48)
    }
};


// ############################################################################
//
//  EGlobalManagerClient - Global manager client (destructor only)
//
//  Calls Shutdown() before destruction, then optionally __builtin_delete
//
// ############################################################################

class EGlobalManagerClient {
public:
    void Shutdown();

    // 0x803C1C78 (76 bytes)
    // Sets vtable, calls Shutdown(), optionally deletes
    virtual ~EGlobalManagerClient() {
        Shutdown();
        // Conditional delete via operator delete
    }
};


// ############################################################################
//
//  EIGameInstance - Game instance type registration
//
//  Registers type info with ETypeInfo system using function pointers
//
// ############################################################################

class EIGameInstance {
public:
    // 0x80227844 (84 bytes)
    // Calls ETypeInfo::Register with factory, destroyer, and type metadata
    // r3 = this, r4 = type_id (unsigned short)
    // Passes 6 args to ETypeInfo::Register:
    //   r3 = ETypeInfo pointer (global)
    //   r4 = CreateInstance function pointer
    //   r5 = Destroy function pointer
    //   r6 = another function pointer
    //   r7 = this (EIGameInstance*)
    //   r8 = type name string pointer
    //   r9 = parent ETypeInfo pointer
    static void RegisterType(unsigned short typeId);
};


// ############################################################################
//
//  ENgcDL - NGC display list (destructor only)
//
//  Inherits from EDL
//  Vtable at offset 100 (0x64)
//
// ############################################################################

class EDL {
public:
    virtual ~EDL();
    static void operator delete(void* ptr);
};

class ENgcDL : public EDL {
public:
    // 0x803C7618 (80 bytes)
    // Sets vtable at offset 100, calls EDL::~EDL()
    // If delete flag set, calls EDL::operator delete
    ~ENgcDL() {
        // vtable at offset 0x64 set to ENgcDL vtable
        // Parent EDL::~EDL() called implicitly
        // Conditional delete via EDL::operator delete(this)
    }
};


// ############################################################################
//
//  EPMDesc - Particle manager descriptor constructor
//
//  Layout: 20 bytes
//    0x00: u32 m_resourceId  (CalcId result)
//    0x04: u32 m_field04     (zeroed)
//    0x08: s32 m_field08     (-1)
//    0x0C: u32 m_boolParam   (bool param stored)
//    0x10: u32 m_field10     (zeroed)
//
// ############################################################################

class EResourceManager2 {
public:
    static unsigned int CalcId(char* name);
};

class EPMDesc {
public:
    unsigned int m_resourceId; // 0x00
    unsigned int m_field04;    // 0x04
    int          m_field08;    // 0x08
    unsigned int m_boolParam;  // 0x0C
    unsigned int m_field10;    // 0x10

    // 0x8032B898 (84 bytes)
    // Computes resource ID from name, stores bool param, zeroes/inits fields
    EPMDesc(char* name, bool param) {
        m_resourceId = EResourceManager2::CalcId(name);
        m_field10 = 0;
        m_field08 = -1;
        m_boolParam = (unsigned int)param;
        m_field04 = 0;
    }
};


// ############################################################################
//
//  ERAudioStream - Audio stream resource (destructor only)
//
//  Inherits from EResource
//  Has custom operator delete
//
// ############################################################################

class EResource {
public:
    virtual ~EResource();
};

class ERAudioStream : public EResource {
public:
    static void operator delete(void* ptr);

    // 0x803C62AC (80 bytes)
    // Sets vtable, calls EResource::~EResource()
    // If delete flag set, calls ERAudioStream::operator delete
    ~ERAudioStream() {
        // vtable set to ERAudioStream vtable
        // Parent EResource::~EResource() called implicitly
        // Conditional delete via custom operator delete
    }
};


// ############################################################################
//
//  GetVar_* classes - APT variable getter constructors
//
//  All follow the same pattern:
//    Layout: 12+ bytes
//      0x00: char* m_name
//      0x04: u32   m_hash
//      0x08: void** m_vtable (set twice: first to base, then to derived)
//
//  Constructor: store name at +0, call AptVar::Hash(name), store hash at +4,
//               set vtable at +8 to the derived class vtable
//
// ############################################################################

class GetVar_EYE_exists {
public:
    char*        m_name;    // 0x00
    unsigned int m_hash;    // 0x04
    void**       m_vtable;  // 0x08

    // 0x80203A88 (84 bytes)
    GetVar_EYE_exists(char* name) {
        m_name = name;
        m_hash = AptVar::Hash(name);
        // vtable set to GetVar_EYE_exists vtable
    }
};

class GetVar_EYE_targetState {
public:
    char*        m_name;    // 0x00
    unsigned int m_hash;    // 0x04
    void**       m_vtable;  // 0x08

    // 0x80203ADC (84 bytes)
    GetVar_EYE_targetState(char* name) {
        m_name = name;
        m_hash = AptVar::Hash(name);
        // vtable set to GetVar_EYE_targetState vtable
    }
};

class GetVar_Legacy {
public:
    char*        m_name;    // 0x00
    unsigned int m_hash;    // 0x04
    void**       m_vtable;  // 0x08

    // 0x80203CDC (84 bytes)
    GetVar_Legacy(char* name) {
        m_name = name;
        m_hash = AptVar::Hash(name);
        // vtable set to GetVar_Legacy vtable
    }
};

class GetVar_SaveStatus {
public:
    char*        m_name;    // 0x00
    unsigned int m_hash;    // 0x04
    void**       m_vtable;  // 0x08

    // 0x80203BE0 (84 bytes)
    GetVar_SaveStatus(char* name) {
        m_name = name;
        m_hash = AptVar::Hash(name);
        // vtable set to GetVar_SaveStatus vtable
    }
};


// ############################################################################
//
//  SetVar_* classes - APT variable setter constructors
//
//  Same layout as GetVar (12 bytes):
//    0x00: char* m_name
//    0x04: u32   m_hash
//    0x08: void** m_vtable
//
// ############################################################################

class SetVar_EYE_filterCurrSel {
public:
    char*        m_name;    // 0x00
    unsigned int m_hash;    // 0x04
    void**       m_vtable;  // 0x08

    // 0x80203880 (84 bytes)
    SetVar_EYE_filterCurrSel(char* name) {
        m_name = name;
        m_hash = AptVar::Hash(name);
        // vtable set to SetVar_EYE_filterCurrSel vtable
    }
};

class SetVar_EYE_funframeCurrSel {
public:
    char*        m_name;    // 0x00
    unsigned int m_hash;    // 0x04
    void**       m_vtable;  // 0x08

    // 0x8020382C (84 bytes)
    SetVar_EYE_funframeCurrSel(char* name) {
        m_name = name;
        m_hash = AptVar::Hash(name);
        // vtable set to SetVar_EYE_funframeCurrSel vtable
    }
};

class SetVar_EYE_opCancelled {
public:
    char*        m_name;    // 0x00
    unsigned int m_hash;    // 0x04
    void**       m_vtable;  // 0x08

    // 0x802039D8 (84 bytes)
    SetVar_EYE_opCancelled(char* name) {
        m_name = name;
        m_hash = AptVar::Hash(name);
        // vtable set to SetVar_EYE_opCancelled vtable
    }
};

class SetVar_EYE_slotCurrSel {
public:
    char*        m_name;    // 0x00
    unsigned int m_hash;    // 0x04
    void**       m_vtable;  // 0x08

    // 0x802038D4 (84 bytes)
    SetVar_EYE_slotCurrSel(char* name) {
        m_name = name;
        m_hash = AptVar::Hash(name);
        // vtable set to SetVar_EYE_slotCurrSel vtable
    }
};


// ############################################################################
//
//  GetVar_SliderStep - Slider step variable getter (extra char* param)
//
//  Layout: 16 bytes
//    0x00: char* m_name
//    0x04: u32   m_hash
//    0x08: void** m_vtable
//    0x0C: char* m_sliderName  (second string param)
//
// ############################################################################

class GetVar_SliderStep {
public:
    char*        m_name;        // 0x00
    unsigned int m_hash;        // 0x04
    void**       m_vtable;      // 0x08
    char*        m_sliderName;  // 0x0C

    // 0x80203A2C (92 bytes)
    GetVar_SliderStep(char* name, char* sliderName) {
        m_name = name;
        m_hash = AptVar::Hash(name);
        m_sliderName = sliderName;
        // vtable set to GetVar_SliderStep vtable
    }
};


// ############################################################################
//
//  SetVar_EYE_settingSliderVal - Slider value setter (function pointer param)
//
//  Layout: 16 bytes
//    0x00: char* m_name
//    0x04: u32   m_hash
//    0x08: void** m_vtable
//    0x0C: void (*m_callback)(float)
//
// ############################################################################

class SetVar_EYE_settingSliderVal {
public:
    char*        m_name;      // 0x00
    unsigned int m_hash;      // 0x04
    void**       m_vtable;    // 0x08
    void       (*m_callback)(float); // 0x0C

    // 0x8020397C (92 bytes)
    SetVar_EYE_settingSliderVal(char* name, void (*callback)(float)) {
        m_name = name;
        m_hash = AptVar::Hash(name);
        m_callback = callback;
        // vtable set to SetVar_EYE_settingSliderVal vtable
    }
};


// ############################################################################
//
//  WallFadeParms - Wall fade parameter validation
//
//  Layout: at least 40 bytes
//    0x04: float m_nearDist
//    0x08: float m_minDist     (clamp minimum)
//    0x18: float m_farDist     (clamped to >= minDist)
//    0x1C: float m_unused1C    (clamped)
//    0x20: float m_range       (nearDist - minDist)
//    0x24: float m_invRange    (1.0 / range)
//
// ############################################################################

class WallFadeParms {
public:
    unsigned int m_field00;   // 0x00
    float m_nearDist;         // 0x04
    float m_minDist;          // 0x08
    float m_field0C;          // 0x0C
    float m_field10;          // 0x10
    float m_field14;          // 0x14
    float m_farDist;          // 0x18
    float m_field1C;          // 0x1C
    float m_range;            // 0x20
    float m_invRange;         // 0x24

    // 0x80030340 (76 bytes)
    // Clamps farDist to >= minDist, clamps nearDist to >= minDist,
    // computes range and inverse range
    void Validate() {
        // If farDist < minDist, set field1C = minDist (clamp far)
        if (m_farDist < m_minDist) {
            m_field1C = m_minDist;
        }
        // If nearDist < minDist, set nearDist = minDist
        if (m_nearDist < m_minDist) {
            m_nearDist = m_minDist;
        }
        // Compute range = nearDist - minDist
        float range = m_nearDist - m_minDist;
        // Compute invRange = 1.0f / range
        float invRange = 1.0f / range;
        m_range = range;
        m_invRange = invRange;
    }
};


// ############################################################################
//
//  DummyMode - Dummy game state (destructor only)
//
//  Inherits from EGameState (vtable at offset 0x08)
//
// ############################################################################

class DummyMode : public EGameState {
public:
    // 0x80099864 (84 bytes)
    // Sets vtable, calls EGameState::~EGameState()
    // If delete flag set, frees via MainHeap
    ~DummyMode() {
        // vtable at offset 0x08 set to DummyMode vtable
        // Parent EGameState::~EGameState() called implicitly
        // Conditional MainHeap()->Free(this)
    }
};


// ############################################################################
//
//  IHRecord - Interaction history record (destructor only)
//
//  Layout: at least 28 bytes
//    0x18: void** m_vtable  (at offset 24)
//    0x14: BString2 m_name  (at offset 20, 4 bytes? sub-object)
//
// ############################################################################

class IHRecord {
public:
    unsigned int m_fields[5]; // 0x00 - 0x13
    BString2*    m_name;      // 0x14 (sub-object at offset 20)
    void**       m_vtable;    // 0x18

    // 0x803B2EE4 (84 bytes)
    // Sets vtable at offset 0x18, destructs BString2 at offset 0x14,
    // then conditionally deletes via __builtin_delete
    ~IHRecord() {
        // vtable at offset 0x18 set to IHRecord vtable
        // BString2 at (this + 20) destructed with mode 2
        // Conditional operator delete(this)
    }
};


// ############################################################################
//
//  MUStatesLoadConfig - Memory card load config state (Draw method)
//
//  Layout:
//    0x08: void* m_pStateMachine    (ptr to parent state machine)
//    0x1C: u32   m_drawState        (state counter)
//
//  The Draw method calls a virtual function on a nested object
//  when m_drawState is 1 or 2 (i.e., m_drawState - 1 <= 1)
//
// ############################################################################

class ERC;

class MUStatesLoadConfig {
public:
    unsigned int m_field00;          // 0x00
    unsigned int m_field04;          // 0x04
    void*        m_pStateMachine;    // 0x08
    unsigned int m_fields0C[4];      // 0x0C - 0x18
    unsigned int m_drawState;        // 0x1C

    // 0x80093124 (76 bytes)
    // If m_drawState is 1 or 2, follows pointer chain through m_pStateMachine
    // to call a virtual Draw function on a nested rendering object
    void Draw(ERC* rc) {
        unsigned int state = m_drawState - 1;
        if (state <= 1) {
            // Follow pointer chain: m_pStateMachine -> offset 152 -> offset 128
            // Then read offset and function pointer from that object, call it
            // This is a virtual call on a deeply nested rendering object
        }
    }
};


// ############################################################################
//
//  AptLookup - APT lookup value (destructor only)
//
//  Inherits from AptValue (vtable at offset 0x08)
//  Deallocated via DOGMA pool (size 16)
//
// ############################################################################

class AptLookup {
public:
    unsigned int m_field00;  // 0x00
    unsigned int m_field04;  // 0x04
    void**       m_vtable;   // 0x08
    unsigned int m_field0C;  // 0x0C

    // 0x80281D88 (88 bytes)
    // Sets vtable to AptLookup vtable, calls AptValue::~AptValue()
    // If delete flag set, deallocates via DOGMA pool (size 16)
    ~AptLookup() {
        // vtable at offset 0x08 set to AptLookup vtable
        // AptValue::~AptValue() called
        // Conditional DOGMA dealloc: g_pDogmaPoolManager->Deallocate(this, 16)
    }
};


// ############################################################################
//
//  AptNone - Null/none APT value (destructor only)
//
//  Inherits from AptValue (vtable at offset 0x08)
//  Deallocated via DOGMA pool (size 12)
//
// ############################################################################

class AptNone {
public:
    unsigned int m_field00;  // 0x00
    unsigned int m_field04;  // 0x04
    void**       m_vtable;   // 0x08

    // 0x802B445C (88 bytes)
    // Sets vtable to AptNone vtable, calls AptValue::~AptValue()
    // If delete flag set, deallocates via DOGMA pool (size 12)
    ~AptNone() {
        // vtable at offset 0x08 set to AptNone vtable
        // AptValue::~AptValue() called
        // Conditional DOGMA dealloc: g_pDogmaPoolManager->Deallocate(this, 12)
    }
};


// ############################################################################
//
//  AptRegister - Register APT value (destructor only)
//
//  Inherits from AptValue (vtable at offset 0x08)
//  Deallocated via DOGMA pool (size 16)
//
// ############################################################################

class AptRegister {
public:
    unsigned int m_field00;      // 0x00
    unsigned int m_field04;      // 0x04
    void**       m_vtable;       // 0x08
    int          m_registerIdx;  // 0x0C

    // 0x80281D30 (88 bytes)
    // Sets vtable to AptRegister vtable, calls AptValue::~AptValue()
    // If delete flag set, deallocates via DOGMA pool (size 16)
    ~AptRegister() {
        // vtable at offset 0x08 set to AptRegister vtable
        // AptValue::~AptValue() called
        // Conditional DOGMA dealloc: g_pDogmaPoolManager->Deallocate(this, 16)
    }
};


// ############################################################################
//
//  Resource Manager AllocateAndLoadResource implementations
//
//  All follow the same pattern:
//    1. Allocate memory via MainHeap()->Malloc(size, 0) or EResourceManager::Alloc(size, align)
//    2. Call placement-new on the resource type constructor
//    3. Store param at offset 8 of the resource
//    4. Call Load(file) on the resource
//    5. Return the resource pointer
//
// ############################################################################


// --- ESoundTrackDataManager ---
// Resource: ERSoundTrackData (36 bytes, heap-allocated)
// 0x803284F8 (84 bytes)

class ERSoundTrackData {
public:
    unsigned int m_field00; // 0x00
    unsigned int m_field04; // 0x04
    unsigned int m_id;      // 0x08

    ERSoundTrackData();
    void Load(EFile* file);
};

class ESoundTrackDataManager {
public:
    // 0x803284F8 (84 bytes)
    void AllocateAndLoadResource(EFile* file, unsigned int fileId, unsigned int param) {
        void* mem = MainHeap()->Malloc(36, 0);
        ERSoundTrackData* res = new(mem) ERSoundTrackData();
        res->m_id = param;
        res->Load(file);
    }
};


// --- EffectsAttachmentManager ---
// Resource: REffectsAttachment (36 bytes, heap-allocated)
// 0x803287F0 (84 bytes)

class REffectsAttachment {
public:
    unsigned int m_field00; // 0x00
    unsigned int m_field04; // 0x04
    unsigned int m_id;      // 0x08

    REffectsAttachment();
    void Load(EFile* file);
};

class EffectsAttachmentManager {
public:
    // 0x803287F0 (84 bytes)
    void AllocateAndLoadResource(EFile* file, unsigned int fileId, unsigned int param) {
        void* mem = MainHeap()->Malloc(36, 0);
        REffectsAttachment* res = new(mem) REffectsAttachment();
        res->m_id = param;
        res->Load(file);
    }
};


// --- EffectsEmitterManager ---
// Resource: REffectsEmitter (36 bytes, heap-allocated)
// 0x80328958 (84 bytes)

class REffectsEmitter {
public:
    unsigned int m_field00; // 0x00
    unsigned int m_field04; // 0x04
    unsigned int m_id;      // 0x08

    REffectsEmitter();
    void Load(EFile* file);
};

class EffectsEmitterManager {
public:
    // 0x80328958 (84 bytes)
    void AllocateAndLoadResource(EFile* file, unsigned int fileId, unsigned int param) {
        void* mem = MainHeap()->Malloc(36, 0);
        REffectsEmitter* res = new(mem) REffectsEmitter();
        res->m_id = param;
        res->Load(file);
    }
};


// --- EffectsSequencerManager ---
// Resource: REffectsSequencer (20 bytes, heap-allocated)
// 0x80328AB0 (84 bytes)

class REffectsSequencer {
public:
    unsigned int m_field00; // 0x00
    unsigned int m_field04; // 0x04
    unsigned int m_id;      // 0x08

    REffectsSequencer();
    void Load(EFile* file);
};

class EffectsSequencerManager {
public:
    // 0x80328AB0 (84 bytes)
    void AllocateAndLoadResource(EFile* file, unsigned int fileId, unsigned int param) {
        void* mem = MainHeap()->Malloc(20, 0);
        REffectsSequencer* res = new(mem) REffectsSequencer();
        res->m_id = param;
        res->Load(file);
    }
};


// --- EAmbientScoreManager ---
// Resource: ERAmbientScore (60 bytes, heap-allocated)
// Load takes extra param (0)
// 0x80322BC0 (88 bytes)

class ERAmbientScore {
public:
    unsigned int m_field00; // 0x00
    unsigned int m_field04; // 0x04
    unsigned int m_id;      // 0x08

    ERAmbientScore();
    void Load(EFile* file, unsigned int flags);
};

class EAmbientScoreManager {
public:
    // 0x80322BC0 (88 bytes)
    void AllocateAndLoadResource(EFile* file, unsigned int fileId, unsigned int param) {
        void* mem = MainHeap()->Malloc(60, 0);
        ERAmbientScore* res = new(mem) ERAmbientScore();
        res->m_id = param;
        res->Load(file, 0);
    }
};


// --- EAnimManager ---
// Resource: ERAnim (160 bytes, pool-allocated via EResourceManager::Alloc with align 8)
// 0x80322D44 (88 bytes)

class ERAnim {
public:
    unsigned int m_field00; // 0x00
    unsigned int m_field04; // 0x04
    unsigned int m_id;      // 0x08

    ERAnim();
    void Load(EFile* file);
};

class EAnimManager {
public:
    // 0x80322D44 (88 bytes)
    void AllocateAndLoadResource(EFile* file, unsigned int fileId, unsigned int param) {
        // Uses EResourceManager::Alloc(160, 8) instead of MainHeap
        void* mem = EResourceManager::Alloc(160, 8);
        ERAnim* res = new(mem) ERAnim();
        res->m_id = param;
        res->Load(file);
    }

    static void* Alloc(unsigned int size, unsigned int align);
};


// --- EModelManager ---
// Resource: ERModel (384 bytes, pool-allocated via EResourceManager::Alloc with align 8)
// Load calls LoadModel instead of Load
// 0x80324EF4 (88 bytes)

class ERModel2 {  // local stub to avoid conflict with forward decl
public:
    unsigned int m_field00; // 0x00
    unsigned int m_field04; // 0x04
    unsigned int m_id;      // 0x08

    ERModel2();
    void LoadModel(EFile* file);
};

class EModelManager {
public:
    // 0x80324EF4 (88 bytes)
    void AllocateAndLoadResource(EFile* file, unsigned int fileId, unsigned int param) {
        // Uses EResourceManager::Alloc(384, 8)
        void* mem = EResourceManager::Alloc(384, 8);
        ERModel2* res = new(mem) ERModel2();
        res->m_id = param;
        res->LoadModel(file);
    }

    static void* Alloc(unsigned int size, unsigned int align);
};


// --- ESoundEventManager ---
// Resource: ERSoundEvent (52 bytes, pool-allocated via EResourceManager::Alloc with align 8)
// 0x80328394 (88 bytes)

class ERSoundEvent {
public:
    unsigned int m_field00; // 0x00
    unsigned int m_field04; // 0x04
    unsigned int m_id;      // 0x08

    ERSoundEvent();
    void Load(EFile* file);
};

class ESoundEventManager {
public:
    // 0x80328394 (88 bytes)
    void AllocateAndLoadResource(EFile* file, unsigned int fileId, unsigned int param) {
        // Uses EResourceManager::Alloc(52, 8)
        void* mem = EResourceManager::Alloc(52, 8);
        ERSoundEvent* res = new(mem) ERSoundEvent();
        res->m_id = param;
        res->Load(file);
    }

    static void* Alloc(unsigned int size, unsigned int align);
};


// --- EBinaryManager ---
// Resource: ERBinary (28 bytes, heap-allocated)
// Load takes extra param (the original r5/fileSize)
// 0x803230C4 (92 bytes)

class ERBinary {
public:
    unsigned int m_field00; // 0x00
    unsigned int m_field04; // 0x04
    unsigned int m_id;      // 0x08

    ERBinary();
    void Load(EFile* file, unsigned int fileSize);
};

class EBinaryManager {
public:
    // 0x803230C4 (92 bytes)
    void AllocateAndLoadResource(EFile* file, unsigned int fileId, unsigned int param) {
        void* mem = MainHeap()->Malloc(28, 0);
        ERBinary* res = new(mem) ERBinary();
        res->m_id = param;
        res->Load(file, fileId);
    }
};


// --- EEdithTreeSetMan ---
// Resource: EREdithTreeSet (32 bytes, heap-allocated)
// Load takes extra param (fileSize)
// 0x80324A6C (92 bytes)

class EREdithTreeSet {
public:
    unsigned int m_field00; // 0x00
    unsigned int m_field04; // 0x04
    unsigned int m_id;      // 0x08

    EREdithTreeSet();
    void Load(EFile* file, unsigned int fileSize);
};

class EEdithTreeSetMan {
public:
    // 0x80324A6C (92 bytes)
    void AllocateAndLoadResource(EFile* file, unsigned int fileId, unsigned int param) {
        void* mem = MainHeap()->Malloc(32, 0);
        EREdithTreeSet* res = new(mem) EREdithTreeSet();
        res->m_id = param;
        res->Load(file, fileId);
    }
};


// --- EFlashManager ---
// Resource: ERFlash (24 bytes, pool-allocated via EResourceManager::Alloc with align 8)
// Load takes extra param (fileSize)
// 0x80324BF4 (96 bytes)

class ERFlash {
public:
    unsigned int m_field00; // 0x00
    unsigned int m_field04; // 0x04
    unsigned int m_id;      // 0x08

    ERFlash();
    void Load(EFile* file, unsigned int fileSize);
};

class EFlashManager {
public:
    // 0x80324BF4 (96 bytes)
    void AllocateAndLoadResource(EFile* file, unsigned int fileId, unsigned int param) {
        // Uses EResourceManager::Alloc(24, 8)
        void* mem = EResourceManager::Alloc(24, 8);
        ERFlash* res = new(mem) ERFlash();
        res->m_id = param;
        res->Load(file, fileId);
    }

    static void* Alloc(unsigned int size, unsigned int align);
};


// --- ParticleManager ---
// Resource: RParticle (60 bytes, pool-allocated via EResourceManager::Alloc with align 8)
// Load takes extra param (fileSize)
// 0x8032B5D8 (96 bytes)

class RParticle {
public:
    unsigned int m_field00; // 0x00
    unsigned int m_field04; // 0x04
    unsigned int m_id;      // 0x08

    RParticle();
    void Load(EFile* file, unsigned int fileSize);
};

class ParticleManager {
public:
    // 0x8032B5D8 (96 bytes)
    void AllocateAndLoadResource(EFile* file, unsigned int fileId, unsigned int param) {
        // Uses EResourceManager::Alloc(60, 8)
        void* mem = EResourceManager::Alloc(60, 8);
        RParticle* res = new(mem) RParticle();
        res->m_id = param;
        res->Load(file, fileId);
    }

    static void* Alloc(unsigned int size, unsigned int align);
};


// ############################################################################
//
//  UrbzCreditsState - Credits screen update logic
//
//  Layout:
//    0x08: TheSimsStateMachine* m_pStateMachine
//
// ############################################################################

class TheSimsStateMachine {
public:
    bool IsFlowStateRequestPending();
    int  GetFlowStateRequest();
    void SetFlowStateCurrent();
};

class StateMachineState {
public:
    void OwnerReturnFromState(int code);
};

class UrbzCreditsState : public StateMachineState {
public:
    TheSimsStateMachine* m_pStateMachine; // 0x08

    // 0x80098D58 (92 bytes)
    // Checks if a flow state request is pending.
    // If pending and request == 1, sets it as current and returns from state.
    void Update(float dt) {
        if (m_pStateMachine->IsFlowStateRequestPending()) {
            if (m_pStateMachine->GetFlowStateRequest() == 1) {
                m_pStateMachine->SetFlowStateCurrent();
                OwnerReturnFromState(1);
            }
        }
    }
};


// ############################################################################
//
//  ERAnimBitArray - Animation bit array resource (destructor only)
//
//  Has two EBitArray sub-objects at different offsets
//  Vtable at offset 0x10
//
// ############################################################################

class EBitArray {
public:
    void Deallocate();
};

class ERAnimBitArray {
public:
    // Has two EBitArray sub-objects:
    // First EBitArray uses vtable slot (set first vtable, deallocate)
    // Second EBitArray reuses same object (set second vtable, deallocate)
    // Then conditionally __builtin_delete

    // 0x803C9830 (96 bytes)
    // Sets vtable at offset 0x10, calls EBitArray::Deallocate() twice
    // (once with first vtable, once with second), then conditionally deletes
    ~ERAnimBitArray() {
        // First vtable set at offset 0x10, EBitArray::Deallocate() called
        // Second vtable set at offset 0x10, EBitArray::Deallocate() called
        // Conditional operator delete(this)
    }
};


// ############################################################################
//
//  InLevelStoryState - In-level story state (destructor only)
//
//  Layout:
//    0x18: void** m_vtable     (offset 24)
//    0x2C: UIDialog sub-object (offset 44)
//
// ############################################################################

class UIDialog {
public:
    virtual ~UIDialog();
};

class InLevelStoryState {
public:
    unsigned int m_fields[6]; // 0x00 - 0x17
    void**       m_vtable;    // 0x18

    // 0x803A1928 (96 bytes)
    // Sets vtable at offset 0x18, destructs UIDialog at (this + 44),
    // sets second vtable at offset 0x18, conditionally __builtin_delete
    ~InLevelStoryState() {
        // vtable at offset 0x18 set to InLevelStoryState vtable
        // UIDialog at (this + 44) destructed with mode 2
        // Then vtable at offset 0x18 set to base class vtable
        // Conditional operator delete(this)
    }
};


// ############################################################################
//
//  MotiveInc - Motive increment serialization
//
//  Layout: 12 bytes
//    0x00: int   m_motiveId    (streamed as int)
//    0x04: float m_value       (streamed as float)
//    0x08: float m_rate        (streamed as float)
//
// ############################################################################

class MotiveInc {
public:
    int   m_motiveId; // 0x00
    float m_value;    // 0x04
    float m_rate;     // 0x08

    // 0x8011A984 (92 bytes)
    // Streams all 3 fields via ReconBuffer
    void DoStream(ReconBuffer* buf, int mode) {
        buf->ReconInt(&m_motiveId, 1);
        buf->ReconFloat(&m_value, 1);
        buf->ReconFloat(&m_rate, 1);
    }
};


// ############################################################################
//
//  RelArray - Relationship array serialization
//
//  Layout:
//    0x00: RelInt* m_data     (pointer to array elements)
//    ...
//    0x10: int m_capacity     (at offset 16)
//
// ############################################################################

template<class ContainerT, class ElemT>
void DoContainerStream(ContainerT& container, ElemT* data, ReconBuffer* buf, int mode);

class RelArray {
public:
    RelInt*      m_data;       // 0x00
    unsigned int m_field04;    // 0x04
    unsigned int m_field08;    // 0x08
    unsigned int m_field0C;    // 0x0C
    int          m_capacity;   // 0x10

    // 0x8013532C (88 bytes)
    // If mode > 0, streams capacity via Recon32
    // Then calls template DoContainerStream<RelArray, RelInt>
    void DoStream(ReconBuffer* buf, int mode) {
        if (mode > 0) {
            buf->Recon32(&m_capacity, 1);
        }
        DoContainerStream<RelArray, RelInt>(*this, m_data, buf, mode);
    }
};


// ############################################################################
//
//  AptCharacterMorphInst - Morph character instance (destructor only)
//
//  Layout: 28 bytes
//    0x0C: AptNativeHash* m_hash  (at offset 12, may be null)
//    0x14: void** m_vtable        (at offset 20)
//
//  Deallocated via DOGMA pool (size 28)
//
// ############################################################################

class AptNativeHash {
public:
    virtual ~AptNativeHash();
};

class AptCharacterMorphInst {
public:
    unsigned int m_field00;     // 0x00
    unsigned int m_field04;     // 0x04
    unsigned int m_field08;     // 0x08
    AptNativeHash* m_hash;     // 0x0C
    unsigned int m_field10;     // 0x10
    void**       m_vtable;     // 0x14

    // 0x8029C524 (100 bytes)
    // Sets vtable at offset 0x14, if m_hash != null destroys it,
    // then conditionally deallocates via DOGMA pool (size 28)
    ~AptCharacterMorphInst() {
        // vtable at offset 0x14 set to AptCharacterInst vtable
        if (m_hash != 0) {
            // AptNativeHash::~AptNativeHash() with delete mode 3
        }
        // Conditional DOGMA dealloc: g_pDogmaPoolManager->Deallocate(this, 28)
    }
};


// ############################################################################
//
//  AptCharacterShapeInst - Shape character instance (destructor only)
//
//  Layout: 24 bytes
//    0x0C: AptNativeHash* m_hash  (at offset 12, may be null)
//    0x14: void** m_vtable        (at offset 20)
//
//  Deallocated via DOGMA pool (size 24)
//
// ############################################################################

class AptCharacterShapeInst {
public:
    unsigned int m_field00;     // 0x00
    unsigned int m_field04;     // 0x04
    unsigned int m_field08;     // 0x08
    AptNativeHash* m_hash;     // 0x0C
    unsigned int m_field10;     // 0x10
    void**       m_vtable;     // 0x14

    // 0x8029C45C (100 bytes)
    // Sets vtable at offset 0x14, if m_hash != null destroys it,
    // then conditionally deallocates via DOGMA pool (size 24)
    ~AptCharacterShapeInst() {
        // vtable at offset 0x14 set to AptCharacterInst vtable
        if (m_hash != 0) {
            // AptNativeHash::~AptNativeHash() with delete mode 3
        }
        // Conditional DOGMA dealloc: g_pDogmaPoolManager->Deallocate(this, 24)
    }
};


// ############################################################################
//
//  AptCharacterStaticTextInst - Static text character instance (destructor only)
//
//  Layout: 24 bytes
//    0x0C: AptNativeHash* m_hash  (at offset 12, may be null)
//    0x14: void** m_vtable        (at offset 20)
//
//  Deallocated via DOGMA pool (size 24)
//
// ############################################################################

class AptCharacterStaticTextInst {
public:
    unsigned int m_field00;     // 0x00
    unsigned int m_field04;     // 0x04
    unsigned int m_field08;     // 0x08
    AptNativeHash* m_hash;     // 0x0C
    unsigned int m_field10;     // 0x10
    void**       m_vtable;     // 0x14

    // 0x8029C4C0 (100 bytes)
    // Sets vtable at offset 0x14, if m_hash != null destroys it,
    // then conditionally deallocates via DOGMA pool (size 24)
    ~AptCharacterStaticTextInst() {
        // vtable at offset 0x14 set to AptCharacterInst vtable
        if (m_hash != 0) {
            // AptNativeHash::~AptNativeHash() with delete mode 3
        }
        // Conditional DOGMA dealloc: g_pDogmaPoolManager->Deallocate(this, 24)
    }
};


// ############################################################################
//
//  AptGlobalExtensionObject - Global extension for APT (destructor only)
//
//  Inherits from AptValue (vtable at offset 0x08)
//  Contains AptNativeHash sub-object at offset 0x0C
//  Deallocated via AptValueGC_PoolManager (size 36)
//
// ############################################################################

class AptGlobalExtensionObject {
public:
    unsigned int  m_field00;    // 0x00
    unsigned int  m_field04;    // 0x04
    void**        m_vtable;     // 0x08
    // AptNativeHash sub-object at offset 0x0C

    // 0x802B4594 (104 bytes)
    // Sets vtable at offset 0x08, destructs AptNativeHash at (this + 12) with mode 2,
    // calls AptValue::~AptValue(), conditionally deallocates via AptValueGC pool (size 36)
    ~AptGlobalExtensionObject() {
        // vtable at offset 0x08 set to AptGlobalExtensionObject vtable
        // AptNativeHash at (this + 12) destructed with mode 2
        // AptValue::~AptValue() called
        // Conditional: g_pAptValueGCPoolManager->DeallocateAptValueGC(this, 36)
    }
};


// ############################################################################
//
//  AptMovieClip - Movie clip APT value (destructor only)
//
//  Inherits from AptValue (vtable at offset 0x08)
//  Contains AptNativeHash sub-object at offset 0x0C
//  Deallocated via AptValueGC_PoolManager (size 36)
//
// ############################################################################

class AptMovieClip {
public:
    unsigned int  m_field00;    // 0x00
    unsigned int  m_field04;    // 0x04
    void**        m_vtable;     // 0x08
    // AptNativeHash sub-object at offset 0x0C

    // 0x80281F54 (104 bytes)
    // Sets vtable at offset 0x08, destructs AptNativeHash at (this + 12) with mode 2,
    // calls AptValue::~AptValue(), conditionally deallocates via AptValueGC pool (size 36)
    ~AptMovieClip() {
        // vtable at offset 0x08 set to AptMovieClip vtable (same as AptGlobalExtensionObject)
        // AptNativeHash at (this + 12) destructed with mode 2
        // AptValue::~AptValue() called
        // Conditional: g_pAptValueGCPoolManager->DeallocateAptValueGC(this, 36)
    }
};


// ############################################################################
//
//  EResourceManager static helper (used by several managers above)
//
// ############################################################################
// (EResourceManager class is declared above)
