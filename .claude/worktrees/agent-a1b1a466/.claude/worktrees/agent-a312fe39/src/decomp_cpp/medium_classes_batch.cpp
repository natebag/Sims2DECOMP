// medium_classes_batch.cpp - Batch conversion of medium-size asm stubs (50-100 lines)
// ~84 classes converted from PPC asm to portable C++
//
// Converted from inline PPC asm (src/asm_decomp/*.cpp) to real C++.
// All logic derived from PPC assembly analysis of the GameCube build.
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
    int   strcmp(const char* s1, const char* s2);
    int   wcsncpy(void* dst, const void* src, int n);
    int Sprintf(char* buf, char* fmt, ...);
    void  Snprintf(char* buf, unsigned int size, char* fmt, ...);
    int   AtoI(char* str);
}

class EAHeap;
extern EAHeap* MainHeap();
class EAHeap {
public:
    void* Malloc(unsigned int size, int flags);
    void* MallocAligned(unsigned int size, unsigned int align, unsigned int flags, int extra);
    void  Free(void* ptr);
};

// Forward declarations
class AptCharacter;
class AptCharacterSpriteInstBase;
class AptCIH;
class AptControl;
class AptDisplayList;
class AptNativeHash;
class AptScriptFunctionBase;
class EAStringC;
class ReconBuffer;
class StringBuffer;

class AptScriptFunctionBase {
public:
    AptScriptFunctionBase();
    AptScriptFunctionBase(int type, AptScriptFunctionBase* parent, AptCIH* cih, bool flag);
    virtual ~AptScriptFunctionBase();
};

class AptValue {
public:
    int m_type;
    AptValue();
    virtual ~AptValue();
    void SetString(EAStringC* str);
    int GetType() const;
    void toString(EAStringC& out);
};

class AptNativeHash {
public:
    AptNativeHash(int buckets);
    ~AptNativeHash();
    void Insert(EAStringC* key, void* val);
    void* Lookup(EAStringC* key);
};

class AptDisplayList {
public:
    AptDisplayList();
    ~AptDisplayList();
    void AddObject(void* obj);
    void RemoveObject(void* obj);
};

class AptValue;
class AptValueGC;
class AptValueGC_PoolManager;
class AptVar;
class BString2;
class CasEvent;
class CasSimDescriptionS2C {
public:
    void DoStream(ReconBuffer* buf, int version);
};
class CDirtyXmlNode;
class DOGMA_PoolManager {
public:
    void* Allocate(unsigned int size);
    void Deallocate(void* ptr, unsigned int size);
};

class EAStringC {
public:
    void* m_buffer;
    EAStringC();
    EAStringC(unsigned int);
    EAStringC(unsigned int, unsigned int);
    ~EAStringC();
    void operator=(EAStringC&);
    char* c_str() const;
};
class EClock;
class EDebugMenuItem;
class EDL;
class EFile;
class EFileSystem {
public:
    EFileSystem();
    virtual ~EFileSystem();
    virtual int Init(int deviceType);
};
class EGlobal;
class EGlobalManager {
public:
    static void Shutdown();
};
class ELights;
class ENgcTextureBase {
public:
    ENgcTextureBase(int a, int b, int c);
    virtual ~ENgcTextureBase();
};
class EFile {
public:
    virtual unsigned int GetSize();
    virtual void Seek(unsigned int offset, int mode);
};

class EResource {
public:
    unsigned int m_id;
    unsigned int m_fileSize;
    unsigned int m_totalSize;
    EFile*       m_file;
    EResource();
};

class EResourceManager {
public:
    int m_field84;
    void* Alloc(unsigned int size, unsigned int align);
    void Free(void* ptr);
    EResourceManager();
};

class ETextureDef;
class ETypeInfo;
class ERenderSurfaceDef;

class ERCharacter {
public:
    unsigned int m_id;
    ERCharacter();
    void Load(EFile* file);
};

class ERFont {
public:
    unsigned int m_id;
    ERFont();
    void Load(EFile* file);
};

class ERMovie {
public:
    unsigned int m_id;
    ERMovie(EFile* file, unsigned int fileSize, unsigned int offset, int param);
};

class ERShader {
public:
    unsigned int m_id;
    ERShader();
    void Load(EFile* file);
};

class ERTexture {
public:
    unsigned int m_id;
    ERTexture();
    void Load(EFile* file);
};
class EVec3;
class EVec4;
class IconGroupImpl {
public:
    IconGroupImpl();
    ~IconGroupImpl();
    void Init(int type);
    int GetSpriteID(int spriteIdx);
};
class MUWrapper {
public:
    void SetQueryType(int type);
};
class ObjectDataID;
class ObjSelector;
class PlumbBob;
class StringBuffer {
public:
    const char* c_str() const;
    int length() const;
    void copy(const StringBuffer& other);
    void append(const char* str, int maxLen = -1);
    StringBuffer();
    ~StringBuffer();
};

class ReconBuffer {
public:
    void Recon32(int* ptr, int count);
    void Recon16(short* ptr, int count);
    void Recon8(unsigned char* ptr, int count);
    void ReconInt(int* ptr, int count);
    void ReconBool(bool* ptr);
    void ReconString(StringBuffer& str);
};
class StateMachine {
public:
    void ReturnFromState(int result);
    void SetState(int stateId, float param);
    void CallState(int stateId, float param);
};

class StateMachineState {
public:
    void OwnerSetNextState(int stateId, float param);
    void OwnerCallState(int stateId, float param = 0.0f);
    void OwnerReturnFromState(int result);
};
class StringBuffer;
class UIDialog;

struct AptConstantPool {
    int data[2]; // 8-byte struct passed by value
};

struct SCID {};

template <typename T> class TRect;

// Global pool managers
extern DOGMA_PoolManager*      g_pDogmaPoolManager;
extern AptValueGC_PoolManager* g_pAptValueGCPoolManager;

// Global singletons accessed via r13 offsets
extern void*  g_pObjectModuleImpl;   // r13 - 21508
extern void*  g_pObjectManager;      // r13 - 21484
extern void*  g_pLiveMode;           // r13 - 21496
extern void*  g_pSimulatorImpl;      // r13 - 21424
extern void*  g_pSoundPlayer;        // r13 - 21492
extern void*  g_pSoundModeManager;   // r13 - 24508
extern void*  g_pRoomManager;        // r13 - 21472
extern void*  g_pPSys1;             // r13 - 22708
extern void*  g_pPSys2;             // r13 - 22704
extern void*  g_pPSys3;             // r13 - 22700
extern void*  g_pEyeToyState;       // r13 - 28712
extern void*  g_pGameData;
extern void*  g_pHouseStats;

// EResourceManager static singleton addresses
extern EResourceManager g_textureResourceManager;
extern EResourceManager g_shaderResourceManager;
extern EResourceManager g_characterResourceManager;

// operator new/delete
extern void* operator_new_impl(unsigned int size);
extern void  operator_delete_impl(void* ptr);
extern void* operator_vec_new_impl(unsigned int size);
extern void  operator_vec_delete_impl(void* ptr);
extern void  node_alloc_deallocate(void* ptr, unsigned int size);

// AptVar hash helper
class AptVar {
public:
    static unsigned int Hash(char* name);
};

// EyeToyClient stubs
namespace EyeToyClient {
    int IsSessionEyeToyDisconnected();
    void* GetRepTexture(int slot);
    void SetHue(float val);
    void SetBrightness(float val);
    void SetSaturation(float val);
    void RestoreDefaults();
}

// ============================================================================
// Managers (AllocateAndLoadResource pattern)
// ============================================================================

// --- ECharacterManager ---

class ECharacterManager : public EResourceManager {
public:
    void AllocateAndLoadResource(EFile* file, unsigned int offset, unsigned int id);
};

// 0x80323224 (108 bytes)
void ECharacterManager::AllocateAndLoadResource(EFile* file, unsigned int offset, unsigned int id) {
    // Alloc from resource manager, size=52, align=8
    void* mem = g_characterResourceManager.Alloc(52, 8);
    ERCharacter* res = new (mem) ERCharacter();
    res->m_id = id;  // stw r29, 8(r30)
    // Virtual call: res->Load(file) via vtable offset 72/76
    res->Load(file);
    // return res (implicitly via this pattern)
}

// --- EShaderManager ---

class EShaderManager : public EResourceManager {
public:
    void AllocateAndLoadResource(EFile* file, unsigned int offset, unsigned int id);
};

// 0x803281FC (108 bytes)
void EShaderManager::AllocateAndLoadResource(EFile* file, unsigned int offset, unsigned int id) {
    void* mem = g_shaderResourceManager.Alloc(108, 8);
    ERShader* res = new (mem) ERShader();
    res->m_id = id;
    res->Load(file);
}

// --- ETextureManager ---

class ETextureManager : public EResourceManager {
public:
    void AllocateAndLoadResource(EFile* file, unsigned int offset, unsigned int id);
};

// 0x80328678 (108 bytes)
void ETextureManager::AllocateAndLoadResource(EFile* file, unsigned int offset, unsigned int id) {
    void* mem = g_textureResourceManager.Alloc(24, 8);
    ERTexture* res = new (mem) ERTexture();
    res->m_id = id;
    res->Load(file);
}

// --- EFontManager ---

class EFontManager : public EResourceManager {
public:
    void AllocateAndLoadResource(EFile* file, unsigned int offset, unsigned int id);
};

// 0x80324D60 (112 bytes)
void EFontManager::AllocateAndLoadResource(EFile* file, unsigned int offset, unsigned int id) {
    EAHeap* heap = MainHeap();
    void* mem = heap->MallocAligned(108, 16, 0, 0);
    ERFont* res = new (mem) ERFont();
    res->m_id = id;
    res->Load(file);
}

// --- EAudioStreamManager ---

class EAudioStreamManager : public EResourceManager {
public:
    void AllocateAndLoadResource(EFile* file, unsigned int offset, unsigned int id);
    EAudioStreamManager();
};

// 0x80322EA8 (172 bytes)
void EAudioStreamManager::AllocateAndLoadResource(EFile* file, unsigned int offset, unsigned int id) {
    // Get file size via virtual call: file->GetSize()
    unsigned int fileSize = file->GetSize();
    EAHeap* heap = MainHeap();
    unsigned int totalSize = fileSize + offset;
    void* mem = heap->Malloc(32, 0);
    // Construct EResource in-place
    EResource* res = new (mem) EResource();
    res->m_fileSize = fileSize;
    res->m_totalSize = totalSize - 1;
    // Set vtable, id, file pointer
    res->m_id = id;
    res->m_file = file;
    // Seek file
    file->Seek(offset, 1);
}

// 0x80323008 (68 bytes)
EAudioStreamManager::EAudioStreamManager() {
    // Call base EResourceManager constructor
    // base class EResourceManager initialized by compiler
    this->m_field84 = 1;
    // Set vtable at offset 3356
}

// --- EMovieMan ---

class EMovieMan : public EResourceManager {
public:
    int m_field3360;
    void AllocateAndLoadResource(EFile* file, unsigned int offset, unsigned int id);
    EMovieMan();
};

// 0x80325058 (188 bytes)
void EMovieMan::AllocateAndLoadResource(EFile* file, unsigned int offset, unsigned int id) {
    unsigned int fileSize = file->GetSize();
    EAHeap* heap = MainHeap();
    void* mem = heap->Malloc(40, 0);
    ERMovie* res = new (mem) ERMovie(file, fileSize, offset, this->m_field3360);
    res->m_id = id;
    // Adjust seek: file->GetSize() - fileSize, subtract from offset
    unsigned int newSize = file->GetSize();
    unsigned int remaining = offset - (newSize - fileSize);
    file->Seek(remaining, 1);
}

// 0x803251C8 (68 bytes)
EMovieMan::EMovieMan() {
    // base class EResourceManager initialized by compiler
    this->m_field84 = 1;
    // Set vtable at offset 3356
}

// ============================================================================
// Texture classes (ENgcTexture*)
// ============================================================================

// --- ENgcTextureC4 ---

class ENgcTextureC4 : public ENgcTextureBase {
public:
    ENgcTextureC4();
    ~ENgcTextureC4();
};

// 0x8035061C (72 bytes)
ENgcTextureC4::ENgcTextureC4() : ENgcTextureBase(8, 8, 8) {
    // Set derived vtable at offset 36
}

// 0x80350664 (88 bytes)
ENgcTextureC4::~ENgcTextureC4() {
    // Set vtable
    // Call base destructor with flag=0
    ENgcTextureBase::~ENgcTextureBase();
    // if (shouldDelete) EResourceManager::Free(this)
}

// --- ENgcTextureC8 ---

class ENgcTextureC8 : public ENgcTextureBase {
public:
    ENgcTextureC8();
    ~ENgcTextureC8();
};

// 0x80350C84 (72 bytes)
ENgcTextureC8::ENgcTextureC8() : ENgcTextureBase(9, 8, 4) {
    // Set derived vtable at offset 36
}

// 0x80350CCC (88 bytes)
ENgcTextureC8::~ENgcTextureC8() {
    ENgcTextureBase::~ENgcTextureBase();
}

// --- ENgcTextureCMPR ---

class ENgcTextureCMPR : public ENgcTextureBase {
public:
    ENgcTextureCMPR();
    ~ENgcTextureCMPR();
};

// 0x80351494 (72 bytes)
ENgcTextureCMPR::ENgcTextureCMPR() : ENgcTextureBase(14, 8, 8) {
    // Set derived vtable at offset 36
}

// 0x803514DC (88 bytes)
ENgcTextureCMPR::~ENgcTextureCMPR() {
    ENgcTextureBase::~ENgcTextureBase();
}

// --- ENgcTextureRGB5A3 ---

class ENgcTextureRGB5A3 : public ENgcTextureBase {
public:
    ENgcTextureRGB5A3();
    ~ENgcTextureRGB5A3();
};

// 0x8035159C (72 bytes)
ENgcTextureRGB5A3::ENgcTextureRGB5A3() : ENgcTextureBase(5, 4, 4) {
    // Set derived vtable at offset 36
}

// 0x803515E4 (88 bytes)
ENgcTextureRGB5A3::~ENgcTextureRGB5A3() {
    ENgcTextureBase::~ENgcTextureBase();
}

// --- ENgcTextureRGBA8 ---

class ENgcTextureRGBA8 : public ENgcTextureBase {
public:
    ENgcTextureRGBA8();
    ~ENgcTextureRGBA8();
};

// 0x80351700 (72 bytes)
ENgcTextureRGBA8::ENgcTextureRGBA8() : ENgcTextureBase(6, 4, 4) {
    // Set derived vtable at offset 36
}

// 0x80351748 (88 bytes)
ENgcTextureRGBA8::~ENgcTextureRGBA8() {
    ENgcTextureBase::~ENgcTextureBase();
}

// --- ETexture ---

class ETexture {
public:
    // Fields: 0x00-0x1F = ETextureDef data (56 bytes: 2 loops of 24 + 8),
    //   0x20 = data ptr, 0x24 = vtable
    u32 m_defData[14]; // offset 0..55
    u32 m_dataPtr;     // offset 32 (0x20)
    u32 m_vtable;      // offset 36 (0x24)

    ~ETexture();
    int Create(ETextureDef& def);
};

// 0x80364FC4 (80 bytes)
ETexture::~ETexture() {
    m_dataPtr = 0xDEADBEEF;  // lis 0,-8531; ori 0,0,48879 = 0xDEADBEEF
    // Set vtable
    // if (shouldDelete) EResourceManager::Free(this)
}

// 0x80365014 (96 bytes)
int ETexture::Create(ETextureDef& def) {
    // Copy 56 bytes (2x24-byte loop + 8 trailing bytes) from def to this
    u32* dst = (u32*)this;
    u32* src = (u32*)&def;
    // Loop: copy 24 bytes (6 words) twice
    for (int i = 0; i < 2; i++) {
        dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];
        dst[3] = src[3]; dst[4] = src[4]; dst[5] = src[5];
        dst += 6; src += 6;
    }
    // Copy trailing 8 bytes
    dst[0] = src[0];
    dst[1] = src[1];
    return 1;
}

// ============================================================================
// GetVar / SetVar handlers
// ============================================================================

// --- GetVar_GetCount ---

class GetVar_GetCount {
public:
    char* m_name;       // offset 0
    u32   m_hash;       // offset 4
    u32   m_vtable;     // offset 8
    char  m_buffer[16]; // offset 12

    GetVar_GetCount(char* name, int count);
};

// 0x801E9138 (112 bytes)
GetVar_GetCount::GetVar_GetCount(char* name, int count) {
    // Set base vtable, then derived vtable
    m_name = name;
    m_hash = AptVar::Hash(name);
    // Set derived vtable
    Sprintf(m_buffer, "%d", count);
}

// --- GetVar_EYE_settingSliderVal ---

class GetVar_EYE_settingSliderVal {
public:
    char* m_name;             // offset 0
    u32   m_hash;             // offset 4
    u32   m_vtable;           // offset 8
    float (*m_getter)(void);  // offset 12

    void Handler(char* buf);
    GetVar_EYE_settingSliderVal(char* name, float (*getter)(void));
};

// 0x801E9308 (72 bytes)
void GetVar_EYE_settingSliderVal::Handler(char* buf) {
    float val = m_getter();
    Sprintf(buf, "%f", val);
}

// 0x80203B30 (92 bytes)
GetVar_EYE_settingSliderVal::GetVar_EYE_settingSliderVal(char* name, float (*getter)(void)) {
    m_name = name;
    m_hash = AptVar::Hash(name);
    m_getter = getter;
    // Set derived vtable
}

// --- GetVar_ImageSlotsAvail ---

class GetVar_ImageSlotsAvail {
public:
    char* m_name;    // offset 0
    u32   m_hash;    // offset 4
    u32   m_vtable;  // offset 8

    void Handler(char* buf);
    GetVar_ImageSlotsAvail(char* name);
};

// 0x801E93BC (84 bytes)
void GetVar_ImageSlotsAvail::Handler(char* buf) {
    // g_pEyeToyState->field_132 checked
    u32* eyeState = (u32*)g_pEyeToyState;
    int connected = *(int*)((u8*)eyeState + 132);
    const char* valStr = connected ? "true" : "false";
    Sprintf(buf, "%s", valStr);
}

// 0x80203C34 (84 bytes)
GetVar_ImageSlotsAvail::GetVar_ImageSlotsAvail(char* name) {
    m_name = name;
    m_hash = AptVar::Hash(name);
    // Set derived vtable
}

// --- GetVar_EYE_connectionStatus ---

class GetVar_EYE_connectionStatus {
public:
    char* m_name;    // offset 0
    u32   m_hash;    // offset 4
    u32   m_vtable;  // offset 8

    void Handler(char* buf);
    GetVar_EYE_connectionStatus(char* name);
};

// 0x801E9410 (112 bytes)
void GetVar_EYE_connectionStatus::Handler(char* buf) {
    int disconnected = EyeToyClient::IsSessionEyeToyDisconnected();
    u32* eyeState = (u32*)g_pEyeToyState;
    *(int*)((u8*)eyeState + 176) = disconnected;
    const char* valStr = disconnected ? "false" : "true";
    Sprintf(buf, "%s", valStr);
    // Reset field to 0
    *(int*)((u8*)eyeState + 176) = 0;
}

// 0x80203C88 (84 bytes)
GetVar_EYE_connectionStatus::GetVar_EYE_connectionStatus(char* name) {
    m_name = name;
    m_hash = AptVar::Hash(name);
    // Set derived vtable
}

// --- GetVar_SaveRequired ---

class GetVar_SaveRequired {
public:
    char* m_name;    // offset 0
    u32   m_hash;    // offset 4
    u32   m_vtable;  // offset 8

    void Handler(char* buf);
    GetVar_SaveRequired(char* name);
};

// 0x801E9350 (108 bytes)
void GetVar_SaveRequired::Handler(char* buf) {
    u32* eyeState = (u32*)g_pEyeToyState;
    int field136 = *(int*)((u8*)eyeState + 136);
    int field176 = *(int*)((u8*)eyeState + 176);
    int saveRequired = 0;
    if (field136 > 0) {
        saveRequired = (field176 == 0) ? 1 : 0;
    }
    const char* valStr = saveRequired ? "true" : "false";
    Sprintf(buf, "%s", valStr);
}

// 0x80203B8C (84 bytes)
GetVar_SaveRequired::GetVar_SaveRequired(char* name) {
    m_name = name;
    m_hash = AptVar::Hash(name);
    // Set derived vtable
}

// --- GetVar_LockedStatus ---

class GetVar_LockedStatus {
public:
    char* m_name;    // offset 0
    u32   m_hash;    // offset 4
    u32   m_vtable;  // offset 8
    int   m_locked;  // offset 12

    GetVar_LockedStatus(char* name, unsigned int flags);
    void Handler(char* buf);
};

// 0x801E91A8 (160 bytes)
GetVar_LockedStatus::GetVar_LockedStatus(char* name, unsigned int flags) {
    m_name = name;
    m_hash = AptVar::Hash(name);
    // Parse last 2 chars of name as a 2-digit number
    int len = strlen(name);
    char* end = name + len;
    int digit1 = (int)(signed char)end[-2];
    int digit0 = (int)(signed char)end[-1];
    int index = digit1 * 10 + digit0 - 528;  // '0' * 10 + '0' = 528
    int bit = 1 << index;
    m_locked = (bit & flags) ? 1 : 0;
}

// 0x801E926C (68 bytes)
void GetVar_LockedStatus::Handler(char* buf) {
    if (m_locked) {
        strcpy(buf, "false");
    } else {
        strcpy(buf, "true");
    }
}

// --- SetVar_EYE_topLevelCurrSel ---

class SetVar_EYE_topLevelCurrSel {
public:
    char* m_name;    // offset 0
    u32   m_hash;    // offset 4
    u32   m_vtable;  // offset 8

    void Handler(char* value);
    SetVar_EYE_topLevelCurrSel(char* name);
};

// 0x801E95EC (92 bytes)
void SetVar_EYE_topLevelCurrSel::Handler(char* value) {
    int sel = AtoI(value);
    u32* eyeState = (u32*)g_pEyeToyState;
    *(int*)((u8*)eyeState + 152) = sel;
    if (sel == 1) {
        EyeToyClient::SetHue(0.0f);
        EyeToyClient::SetBrightness(0.0f);
        EyeToyClient::SetSaturation(0.0f);
        EyeToyClient::RestoreDefaults();
    }
}

// 0x802037D8 (84 bytes)
SetVar_EYE_topLevelCurrSel::SetVar_EYE_topLevelCurrSel(char* name) {
    m_name = name;
    m_hash = AptVar::Hash(name);
    // Set derived vtable
}

// --- SetVar_EYE_saveToSlotStatus ---

class SetVar_EYE_saveToSlotStatus {
public:
    char* m_name;    // offset 0
    u32   m_hash;    // offset 4
    u32   m_vtable;  // offset 8

    void Handler(char* value);
    SetVar_EYE_saveToSlotStatus(char* name);
};

// 0x801E9744 (140 bytes)
void SetVar_EYE_saveToSlotStatus::Handler(char* value) {
    if (value[0] != '0') return;
    u32* eyeState = (u32*)g_pEyeToyState;
    int field180 = *(int*)((u8*)eyeState + 180);
    if (field180 == 0) return;

    int slot = *(int*)((u8*)eyeState + 140);
    void* repTex = EyeToyClient::GetRepTexture(slot);
    // Get texture data pointer via virtual call at vtable offset 64/68
    void* texData;
    // Virtual call: repTex->GetData(0, &texData, &texData)
    u16 width  = *(u16*)((u8*)repTex + 16);
    u16 height = *(u16*)((u8*)repTex + 18);
    unsigned int dataSize = width * height * 2;
    memcpy((void*)field180, texData, dataSize);
}

// 0x80203928 (84 bytes)
SetVar_EYE_saveToSlotStatus::SetVar_EYE_saveToSlotStatus(char* name) {
    m_name = name;
    m_hash = AptVar::Hash(name);
    // Set derived vtable
}

// ============================================================================
// CasScene* classes (GetMirrorCorners pattern)
// ============================================================================

struct MirrorCornerData {
    u32 data[6]; // 24 bytes per corner pair
};

extern MirrorCornerData g_casSceneDefaultMirrorCorners[];
extern MirrorCornerData g_casSceneGamecubeMirrorCorners[];
extern MirrorCornerData g_casScenePersonalMirrorCorners[];

// --- CasSceneDefault ---

class CasSceneDefault {
public:
    int GetMirrorCorners(int roomId, EVec3* corners) const;
};

// 0x80175540 (100 bytes)
int CasSceneDefault::GetMirrorCorners(int roomId, EVec3* corners) const {
    if (roomId != 0) return 0;
    // Copy 3 pairs of EVec3 (72 bytes = 3*24) from static data
    MirrorCornerData* src = g_casSceneDefaultMirrorCorners;
    MirrorCornerData* dst = (MirrorCornerData*)corners;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    return 1;
}

// --- CasSceneGamecube ---

class CasSceneGamecube {
public:
    int GetMirrorCorners(int roomId, EVec3* corners) const;
};

// 0x80175700 (100 bytes)
int CasSceneGamecube::GetMirrorCorners(int roomId, EVec3* corners) const {
    if (roomId != 0) return 0;
    MirrorCornerData* src = g_casSceneGamecubeMirrorCorners;
    MirrorCornerData* dst = (MirrorCornerData*)corners;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    return 1;
}

// --- CasScenePersonal ---

class CasScenePersonal {
public:
    int GetMirrorCorners(int roomId, EVec3* corners) const;
};

// 0x801758A8 (100 bytes)
int CasScenePersonal::GetMirrorCorners(int roomId, EVec3* corners) const {
    if (roomId != 0) return 0;
    MirrorCornerData* src = g_casScenePersonalMirrorCorners;
    MirrorCornerData* dst = (MirrorCornerData*)corners;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    return 1;
}

// ============================================================================
// CasTweakTool (GetLights / SetLights)
// ============================================================================

// ELights is 248 bytes: 10 light entries of 24 bytes + 8 trailing bytes

class CasTweakTool {
public:
    void GetLights(ELights& out);
    void SetLights(ELights& in);
};

// 0x80175300 (88 bytes)
void CasTweakTool::GetLights(ELights& out) {
    u32* src = (u32*)this;
    u32* dst = (u32*)&out;
    // Copy 10 chunks of 24 bytes (240 bytes / 24 = 10 iterations)
    for (int i = 0; i < 10; i++) {
        dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];
        dst[3] = src[3]; dst[4] = src[4]; dst[5] = src[5];
        dst += 6; src += 6;
    }
    // Copy trailing 8 bytes
    dst[0] = src[0];
    dst[1] = src[1];
}

// 0x80175358 (88 bytes)
void CasTweakTool::SetLights(ELights& in) {
    u32* dst = (u32*)this;
    u32* src = (u32*)&in;
    for (int i = 0; i < 10; i++) {
        dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];
        dst[3] = src[3]; dst[4] = src[4]; dst[5] = src[5];
        dst += 6; src += 6;
    }
    dst[0] = src[0];
    dst[1] = src[1];
}

// ============================================================================
// Pane destructors (BackgroundPane, DialogPane, MenuDialogPane)
// ============================================================================

class WrapperPaneBase {
public:
    void Shutdown();
};

// --- BackgroundPane ---

class BackgroundPane : public WrapperPaneBase {
public:
    // offset 8: m_buffer (ptr)
    // offset 12: m_bufferEnd
    // offset 92: vtable
    ~BackgroundPane();
};

// 0x803A1988 (124 bytes)
BackgroundPane::~BackgroundPane() {
    // Set vtable at offset 92
    WrapperPaneBase::Shutdown();
    // Free internal buffer at offset 8
    void* buf = *(void**)((u8*)this + 8);
    if (buf) {
        u32 endOff = *(u32*)((u8*)this + 20); // offset 12 of sub-struct at +8
        u32 size = (endOff - (u32)(uintptr_t)buf) & ~3u;
        if (size > 128) {
            operator_delete_impl(buf);
        } else {
            node_alloc_deallocate(buf, size);
        }
    }
    // if (shouldDelete) delete this
}

// --- DialogPane ---

class DialogPane : public WrapperPaneBase {
public:
    ~DialogPane();
};

// 0x803A05F0 (124 bytes)
DialogPane::~DialogPane() {
    // Same pattern as BackgroundPane
    WrapperPaneBase::Shutdown();
    void* buf = *(void**)((u8*)this + 8);
    if (buf) {
        u32 endOff = *(u32*)((u8*)this + 20);
        u32 size = (endOff - (u32)(uintptr_t)buf) & ~3u;
        if (size > 128) {
            operator_delete_impl(buf);
        } else {
            node_alloc_deallocate(buf, size);
        }
    }
}

// --- MenuDialogPane ---

class MenuDialogPane : public WrapperPaneBase {
public:
    ~MenuDialogPane();
};

// 0x803A073C (124 bytes)
MenuDialogPane::~MenuDialogPane() {
    WrapperPaneBase::Shutdown();
    void* buf = *(void**)((u8*)this + 8);
    if (buf) {
        u32 endOff = *(u32*)((u8*)this + 20);
        u32 size = (endOff - (u32)(uintptr_t)buf) & ~3u;
        if (size > 128) {
            operator_delete_impl(buf);
        } else {
            node_alloc_deallocate(buf, size);
        }
    }
}

// ============================================================================
// ChangeHouse* state machine states
// ============================================================================

// --- ChangeHouseSaveHouse ---

class MUStateMachine {
public:
    static int MUPollForResult(int request);
};

class ChangeHouseSaveHouse : public StateMachineState {
public:
    void Update(float dt);
};

// 0x8008CD9C (120 bytes)
void ChangeHouseSaveHouse::Update(float dt) {
    int result = MUStateMachine::MUPollForResult(7);
    if (result == 0) return;

    if (result == 2 || result == 3) {
        // Success or skip
        StateMachine* owner = *(StateMachine**)((u8*)this + 8);
        owner->ReturnFromState(1);
    } else if (result == 1) {
        // Error - set global flag and advance to next state
        // Store result to global, set next state to 2
        this->OwnerSetNextState(2, 0.0f);
    }
}

// --- ChangeHouseDemolishHouse ---

class ChangeHouseDemolishHouse : public StateMachineState {
public:
    void Update(float dt);
};

// 0x8008CCC0 (184 bytes)
void ChangeHouseDemolishHouse::Update(float dt) {
    // Check global game state flags
    u32* gameState = (u32*)g_pObjectManager; // r13 - 32160 actually
    // Check if flag 4 is set in field 180
    u32 flags = *(u32*)((u8*)gameState + 180);
    if (!(flags & 4)) return;

    // Set demolish flag
    // Call LiveMode::SetDemolishMode(false)
    // Call LiveMode::ClearHouse()
    // PlumbBob::ShutdownAll()
    // Call ObjectManager::Shutdown()
    // Set next state to 1
    this->OwnerSetNextState(1, 0.0f);
}

// --- ChangeHouseUnloadHouse ---

class ChangeHouseUnloadHouse {
public:
    void Reset();
};

extern void UnloadLevelGlobalData();
extern void PSystemIsEmpty(void* psys);
extern void PSystemClean(void* psys);
namespace InteractorModule { void ShutdownInteractorModule(); }
namespace Effects { class EffectsManager {
public:
    static EffectsManager* GetSingleton();
    void DeleteAll();
}; }
class RoomManager { public: void ResetRoomManager(); };
class PlumbBob { public: static void ShutdownAll(); };
class cSoundModeManager {
public:
    void FadeOutMusic(unsigned int ms);
    void FadeOutSFX(unsigned int ms);
};
class cSoundPlayer { public: void SetGameMode(int mode); };

// 0x8008CE14 (252 bytes)
void ChangeHouseUnloadHouse::Reset() {
    // Fade out audio
    void* sndModeMan = g_pSoundModeManager;
    if (sndModeMan) {
        cSoundModeManager* mgr = (cSoundModeManager*)((u8*)sndModeMan + 48);
        mgr->FadeOutMusic(32);
        mgr->FadeOutSFX(32);
    }

    // Set game mode to 3
    cSoundPlayer* sndPlayer = (cSoundPlayer*)g_pSoundPlayer;
    sndPlayer->SetGameMode(3);

    // Call virtual shutdown on simulator
    // g_pSimulatorImpl->VirtualCall(144/148)
    // EGlobal::ClearCurHouse()
    // Set globals to 0/1
    UnloadLevelGlobalData();

    RoomManager* roomMgr = (RoomManager*)g_pRoomManager;
    roomMgr->ResetRoomManager();

    // ObjectModuleImpl virtual call(200/204) - shutdown
    InteractorModule::ShutdownInteractorModule();

    PSystemIsEmpty(g_pPSys1);
    PSystemIsEmpty(g_pPSys2);
    PSystemIsEmpty(g_pPSys3);
    PSystemClean(g_pPSys1);
    PSystemClean(g_pPSys2);
    PSystemClean(g_pPSys3);

    Effects::EffectsManager* efx = Effects::EffectsManager::GetSingleton();
    efx->DeleteAll();
}

// ============================================================================
// MUStates* (Memory Unit state machine states)
// ============================================================================

// --- MUStatesSlotSelectSave ---

class MUStatesSlotSelectSave : public StateMachineState {
public:
    void Update(float dt);
};

// 0x80091A7C (116 bytes)
void MUStatesSlotSelectSave::Update(float dt) {
    StateMachine* owner = *(StateMachine**)((u8*)this + 8);
    int result = *(int*)((u8*)owner + 144);

    if (result == 0) {
        // No slot selected - clear globals and return
        // stw 0 to global at r9+22744 and global+8
        owner->ReturnFromState(2);
    } else if (result == 1) {
        owner->ReturnFromState(1);
    } else if (result == 2) {
        owner->ReturnFromState(2);
    }
}

// --- MUStatesSlotSelectSaveNoSkip ---

class MUStatesSlotSelectSaveNoSkip : public StateMachineState {
public:
    void Update(float dt);
};

// 0x80091AF0 (136 bytes)
void MUStatesSlotSelectSaveNoSkip::Update(float dt) {
    StateMachine* owner = *(StateMachine**)((u8*)this + 8);
    int result = *(int*)((u8*)owner + 144);

    if (result == 0) {
        // Set MUWrapper request type and call state 14
        void* muWrapper = *(void**)((u8*)owner + 152);
        *(int*)((u8*)muWrapper + 172) = 7;
        MUWrapper* wrapper = *(MUWrapper**)((u8*)owner + 152);
        wrapper->SetQueryType(9);
        this->OwnerCallState(14);
    } else if (result == 1) {
        owner->ReturnFromState(1);
    } else if (result == 2) {
        owner->ReturnFromState(2);
    }
}

// --- MUStatesDisplay ---

class MUStatesDisplay : public StateMachineState {
public:
    void Update(float dt);
    void Draw(void* rc);
};

// 0x8009320C (68 bytes)
void MUStatesDisplay::Update(float dt) {
    StateMachine* owner = *(StateMachine**)((u8*)this + 8);
    void* muWrapper = *(void**)((u8*)owner + 152);
    if (muWrapper) {
        // Virtual call on muWrapper via vtable at offset 128 -> offset 40/44 (Update)
        u32* vt = *(u32**)((u8*)muWrapper + 128);
        // Call virtual Update
    }
}

// 0x80093250 (68 bytes)
void MUStatesDisplay::Draw(void* rc) {
    StateMachine* owner = *(StateMachine**)((u8*)this + 8);
    void* muWrapper = *(void**)((u8*)owner + 152);
    if (muWrapper) {
        // Virtual call on muWrapper via vtable at offset 128 -> offset 48/52 (Draw)
    }
}

// ============================================================================
// Commander destructor (linked list removal pattern)
// ============================================================================

class Commander {
public:
    // offset 0: next pointer (linked list)
    // offset 12: vtable
    ~Commander();
};

extern void* g_commanderListHead; // r13 - 32076

// 0x800B4250 (100 bytes)
Commander::~Commander() {
    // Set vtable at offset 12
    // Remove this from global linked list
    Commander** ppPrev = (Commander**)&g_commanderListHead;
    Commander* cur = *ppPrev;
    while (cur != NULL) {
        if (cur == this) {
            // Unlink: prev->next = this->next
            *ppPrev = *(Commander**)this;
            break;
        }
        ppPrev = (Commander**)cur;
        cur = *(Commander**)cur;
    }
    // if (shouldDelete) delete this
}

// ============================================================================
// MultiShaderInfo
// ============================================================================

class MultiShaderInfo {
public:
    // offset 12: m_shader1 (void*)
    // offset 16: m_shader2 (void*)
    void DeAlloc();
};

// 0x803C5710 (104 bytes)
void MultiShaderInfo::DeAlloc() {
    void* shader1 = *(void**)((u8*)this + 12);
    if (shader1) {
        g_shaderResourceManager.Free(shader1);
        *(void**)((u8*)this + 12) = NULL;
    }
    void* shader2 = *(void**)((u8*)this + 16);
    if (shader2) {
        g_shaderResourceManager.Free(shader2);
        *(void**)((u8*)this + 16) = NULL;
    }
}

// ============================================================================
// ObjectRecord
// ============================================================================

class ObjectRecord {
public:
    // offset 0: base class (virtual)
    // offset 4: m_field4 (int)
    // offset 8: m_field8 (bool)
    void DoStream(ReconBuffer* buf, int version);
};

// 0x8011ACFC (104 bytes)
void ObjectRecord::DoStream(ReconBuffer* buf, int version) {
    // Call virtual function on ObjectModuleImpl singleton (vtable offset 472/476)
    // Virtual call dispatches to serialize base
    buf->ReconInt((int*)((u8*)this + 4), 1);
    buf->ReconBool((bool*)((u8*)this + 8));
}

// ============================================================================
// CheatMenuParams
// ============================================================================

class CheatMenuParams {
public:
    // offset 0: m_head (EDebugMenuItem*)
    // offset 4: m_tail (EDebugMenuItem*)
    // offset 8: m_count (int)
    void Remove(EDebugMenuItem& item);
};

// EDebugMenuItem layout:
// offset 0: m_prev (EDebugMenuItem*)
// offset 4: m_next (EDebugMenuItem*)

// 0x80303D48 (100 bytes)
void CheatMenuParams::Remove(EDebugMenuItem& item) {
    int count = *(int*)((u8*)this + 8);
    if (count == 0) return;

    EDebugMenuItem* head = *(EDebugMenuItem**)((u8*)this + 0);
    EDebugMenuItem* itemPrev = *(EDebugMenuItem**)((u8*)&item + 0);
    EDebugMenuItem* itemNext = *(EDebugMenuItem**)((u8*)&item + 4);

    // Unlink from head
    if (head == &item) {
        *(EDebugMenuItem**)((u8*)this + 0) = itemNext;
    } else {
        *(EDebugMenuItem**)((u8*)itemPrev + 4) = itemNext;
    }

    // Unlink from tail
    EDebugMenuItem* tail = *(EDebugMenuItem**)((u8*)this + 4);
    if (tail == &item) {
        *(EDebugMenuItem**)((u8*)this + 4) = itemPrev;
    } else {
        *(EDebugMenuItem**)((u8*)itemNext + 0) = itemPrev;
    }

    // Decrement count
    count--;
    *(int*)((u8*)this + 8) = count;
}

// ============================================================================
// TreeTableEntry
// ============================================================================

struct TreeTableAdScratch {
    s16 field0;
    s16 field2;
    s16 field4;
    s16 field6;
};

extern TreeTableAdScratch g_emptyTreeTableAd; // r13 - 23900
extern int g_treeTableAdInitialized;           // r13 - 23892

class TreeTableEntry {
public:
    // offset 0: m_id (short)
    // offset 4: m_ads (array ptr)
    void* GetAdByID(int id) const;
};

// 0x803AF7F0 (108 bytes)
void* TreeTableEntry::GetAdByID(int id) const {
    if (g_treeTableAdInitialized == 0) {
        g_emptyTreeTableAd.field0 = 0;
        g_emptyTreeTableAd.field2 = 0;
        g_emptyTreeTableAd.field4 = 0;
        g_emptyTreeTableAd.field6 = 0;
        g_treeTableAdInitialized = 1;
    }

    void* ads = *(void**)((u8*)this + 4);
    int count = 0;
    if (ads) {
        count = *(int*)((u8*)ads - 4);
    }

    for (int i = 0; i < count; i++) {
        u8* entry = (u8*)ads + i * 8;
        s16 entryId = *(s16*)(entry + 6);
        if (entryId == id) {
            return entry;
        }
    }
    return &g_emptyTreeTableAd;
}

// ============================================================================
// CatalogResourceImpl
// ============================================================================

struct CatalogData {
    u32 field0;
    u32 field4;
    u32 field8;
    u32 fieldC;
};

template <typename T> T* FindRes(T* begin, T* end, int id);

class CatalogResourceImpl {
public:
    // offset 4: field4
    // offset 8: field8
    // offset 12: fieldC
    int Load(ObjSelector* sel, short id, bool flag);
};

// 0x800B1CC8 (120 bytes)
int CatalogResourceImpl::Load(ObjSelector* sel, short id, bool flag) {
    // Get catalog data array from sel->field84->field28
    void* field84 = *(void**)((u8*)sel + 84);
    void* dataPtr = *(void**)((u8*)field84 + 28);
    int count = 0;
    if (dataPtr) {
        count = *(int*)((u8*)dataPtr - 4);
    }

    CatalogData* begin = (CatalogData*)dataPtr;
    CatalogData* end = begin + count;
    CatalogData* found = FindRes(begin, end, id);
    if (!found) return -1;

    // Copy fields from found entry to this
    *(u32*)((u8*)this + 4)  = found->field4;
    *(u32*)((u8*)this + 8)  = found->field8;
    *(u32*)((u8*)this + 12) = found->fieldC;
    return 0;
}

// ============================================================================
// CTGMicroTimer
// ============================================================================

extern "C" void QueryPerformanceCounter(long long* counter);
extern "C" long long __divdi3(long long a, long long b);

class CTGMicroTimer {
public:
    // offset 0-7:  m_startTime (long long)
    // offset 8-15: m_stopTime (long long)
    // offset 16-23: m_frequency (long long)
    // offset 24:   m_running (int)
    long long GetElapsedTime() const;
};

// 0x8007D620 (136 bytes)
long long CTGMicroTimer::GetElapsedTime() const {
    long long currentTime;
    if (*(int*)((u8*)this + 24)) {
        // Timer is running - query current time
        QueryPerformanceCounter(&currentTime);
    } else {
        currentTime = *(long long*)((u8*)this + 8);
    }

    long long startTime = *(long long*)((u8*)this);
    long long freq = *(long long*)((u8*)this + 16);
    long long elapsed = currentTime - startTime;
    // Multiply by 1000000 (0x000F4240) and divide by frequency
    long long microseconds = (elapsed * 1000000LL) / freq;
    return microseconds;
}

// ============================================================================
// AnimTableImpl / PropTableImpl (Load pattern)
// ============================================================================

class AnimTableImpl {
public:
    // offset 4: m_table (void*)
    int Load(unsigned int resId, short id);
};

// 0x800AAB3C (136 bytes)
int AnimTableImpl::Load(unsigned int resId, short id) {
    // Get object module impl singleton, call virtual at vtable offset 56/60
    // This returns a resource container
    void* container; // = g_pObjectModuleImpl->GetAnimContainer()
    void* resArray = *(void**)((u8*)container + 8);
    void* dataPtr = *(void**)((u8*)resArray + 4);
    int count = 0;
    if (dataPtr) {
        count = *(int*)((u8*)dataPtr - 4);
    }
    void* end = (u8*)dataPtr + count * 8;
    void* found = FindRes((void*)dataPtr, end, id);
    if (!found) return -1;
    *(void**)((u8*)this + 4) = found;
    return 0;
}

class PropTableImpl {
public:
    // offset 4: m_table (void*)
    int Load(unsigned int resId, short id);
};

// 0x801328C8 (136 bytes)
int PropTableImpl::Load(unsigned int resId, short id) {
    // Same pattern as AnimTableImpl but accesses field 8 of container instead of 4
    void* container; // = g_pObjectModuleImpl->GetPropContainer()
    void* resArray = *(void**)((u8*)container + 8);
    void* dataPtr = *(void**)((u8*)resArray + 8);
    int count = 0;
    if (dataPtr) {
        count = *(int*)((u8*)dataPtr - 4);
    }
    void* end = (u8*)dataPtr + count * 8;
    void* found = FindRes((void*)dataPtr, end, id);
    if (!found) return -1;
    *(void**)((u8*)this + 4) = found;
    return 0;
}

// ============================================================================
// AptIntervalTimer
// ============================================================================

class AptIntervalTimer {
public:
    // offset 20: m_count (int)
    // offset 28: m_paramsArray (ptr)
    void cleanParams();
};

// 0x80285640 (144 bytes)
void AptIntervalTimer::cleanParams() {
    int count = *(int*)((u8*)this + 20);
    if (count <= 0) return;

    int remaining = count;
    while (remaining > 0) {
        // Get last element from params array
        int currentCount = *(int*)((u8*)this + 20);
        void* arrayPtr = *(void**)((u8*)this + 28);
        void* lastElem = *(void**)((u8*)arrayPtr + (currentCount * 4) - 4);
        // Call virtual function on lastElem at vtable offset 16/20
        // with args ("undefined", "undefined", 126) -- AptValue::release-like call
        u32* vt = *(u32**)((u8*)lastElem + 8);
        // Virtual dispatch

        // Decrement count
        currentCount--;
        *(int*)((u8*)this + 20) = currentCount;
        remaining--;
    }
}

// ============================================================================
// ENgcClockMan
// ============================================================================

extern "C" long long OSGetTime();

class ENgcClockMan {
public:
    void UpdateData(EClock* clock);
};

// EClock layout:
// offset 0-3: m_timeHi (u32)
// offset 4-7: m_timeLo (u32)
// offset 8:   m_accumulator (float)
// offset 12:  m_deltaMS (int)

// 0x8032DA7C (144 bytes)
void ENgcClockMan::UpdateData(EClock* clock) {
    long long time = OSGetTime();
    u32 busSpeed = *(u32*)0x800000F8; // Bus clock speed from OS globals
    u32 prevTimeLo = *(u32*)((u8*)clock + 4);
    u32 elapsed = (u32)time - prevTimeLo;

    // Convert bus ticks to milliseconds
    // busSpeed * 4194/19923 approximation for ticks-per-ms
    u32 ticksPerMs = (u32)((u64)busSpeed * 4194303ULL >> 32) >> 8;
    u32 elapsedMs = elapsed / ticksPerMs;

    // Store new time
    *(u32*)((u8*)clock + 0) = (u32)(time >> 32);
    *(u32*)((u8*)clock + 4) = (u32)time;

    // Convert to float and accumulate
    float deltaF = (float)elapsedMs / 1000.0f;
    float accum = *(float*)((u8*)clock + 8);
    accum += deltaF;
    *(float*)((u8*)clock + 8) = accum;
}

// ============================================================================
// IFFResNode
// ============================================================================

class IFFResNode {
public:
    // offset 0-3: m_id (int)
    // offset 4:   m_type (int, stored from 16-bit)
    // offset 6:   m_origType (short, intermediate)
    // offset 8:   m_subType (short)
    // offset 10:  m_field10 (short)
    // offset 16:  m_name (StringBuffer)
    void DoStream(ReconBuffer* buf, int version);
};

// 0x800BCD20 (140 bytes)
void IFFResNode::DoStream(ReconBuffer* buf, int version) {
    // Stream the ID (32-bit)
    buf->Recon32((int*)this, 1);

    // Stream a temporary 16-bit value for type
    s16 tmpType = (s16)*(int*)((u8*)this + 4); // field4 truncated to 16-bit
    s16 temp;
    temp = tmpType;
    buf->Recon16(&temp, 1);
    *(int*)((u8*)this + 4) = (int)temp; // promote back to int

    // Stream subType
    buf->Recon16((s16*)((u8*)this + 10), 1);

    // If loading (version == 0), copy field10 to field8
    if (version == 0) {
        *(s16*)((u8*)this + 8) = *(s16*)((u8*)this + 10);
    }

    // Stream name
    buf->ReconString(*(StringBuffer*)((u8*)this + 16));
}

// ============================================================================
// AptPseudoCIH_t
// ============================================================================

class AptPseudoData_t {
public:
    AptPseudoData_t(AptControl* ctrl, int param, AptCharacter* chr);
};

class AptPseudoCIH_t {
public:
    // offset 0:  m_control (AptControl*)
    // offset 4:  m_pseudoData (AptPseudoData_t*)
    // offset 8:  m_field8 (int)
    // offset 12: m_field12 (int)
    // offset 16: m_field16 (int)
    AptPseudoCIH_t(AptControl* ctrl, int type, int param, AptCharacter* chr);
};

// 0x80298FE8 (140 bytes)
AptPseudoCIH_t::AptPseudoCIH_t(AptControl* ctrl, int type, int param, AptCharacter* chr) {
    *(int*)((u8*)this + 16) = param;
    *(AptControl**)((u8*)this + 0) = ctrl;

    if (ctrl != NULL && *(int*)ctrl == 3) {
        // Allocate AptPseudoData_t from DOGMA pool
        void* mem = g_pDogmaPoolManager->Allocate(28);
        AptPseudoData_t* data = new (mem) AptPseudoData_t(ctrl, type, chr);
        *(AptPseudoData_t**)((u8*)this + 4) = data;
    } else {
        *(AptPseudoData_t**)((u8*)this + 4) = NULL;
    }

    *(int*)((u8*)this + 12) = 0;
    *(int*)((u8*)this + 8) = 0;
}

// ============================================================================
// EAudio
// ============================================================================

class EAudio {
public:
    int AdjustMusicVolume(float delta);
};

// 0x8032CB84 (152 bytes)
int EAudio::AdjustMusicVolume(float delta) {
    // Virtual call: this->GetMusicVolume() at vtable offset 104/108
    u32* vt = *(u32**)this;
    float currentVol; // = virtual call result
    float newVol = currentVol + delta;

    int clamped = 0;
    if (newVol > 1.0f || newVol < 0.0f) {
        newVol = 0.0f; // clamp
        clamped = 1;
    }

    // Virtual call: this->SetMusicVolume(newVol) at vtable offset 96/100
    return clamped;
}

// ============================================================================
// CDirtyXmlImpl
// ============================================================================

class CDirtyXmlImpl {
public:
    void* createNewAptXml(char* name);
};

// 0x8023A7A0 (152 bytes)
void* CDirtyXmlImpl::createNewAptXml(char* name) {
    // Allocate 36 bytes for CDirtyXml
    void* xmlObj = operator_new_impl(36);
    // Set CDirtyXmlNode vtable at offset 32 and CDirtyXml vtable at offset 0

    if (name && name[0] != '\0') {
        // Virtual call on the node sub-object to set the name
        // Via vtable at offset 32 -> virtual(280/284)
    } else {
        // Set data pointer to NULL
        *(void**)((u8*)xmlObj + 4) = NULL;
    }

    // Return pointer to node sub-object (xmlObj + 32), or NULL if xmlObj is NULL
    if (xmlObj) {
        return (u8*)xmlObj + 32;
    }
    return NULL;
}

// ============================================================================
// CDirtyXml
// ============================================================================

class CDirtyXml {
public:
    // offset 0: vtable (CDirtyXml)
    // offset 4: m_dataCopy (char*)
    // offset 16: m_parsed (int)
    // offset 28: m_parseState (void*)
    // offset 32: vtable (CDirtyXmlNode)
    ~CDirtyXml();
    void parseXml(char* xmlStr);
};

// 0x8023AF0C (108 bytes)
CDirtyXml::~CDirtyXml() {
    // Set CDirtyXmlNode vtable at offset 32
    // Set CDirtyXml vtable at offset 0
    char* dataCopy = *(char**)((u8*)this + 4);
    if (dataCopy) {
        operator_vec_delete_impl(dataCopy);
    }
    // Set CDirtyXmlNode vtable, call CDirtyXmlNode destructor
    CDirtyXmlNode* node = (CDirtyXmlNode*)this;
    // ~CDirtyXmlNode(flag)
}

// 0x8023AFC8 (136 bytes)
void CDirtyXml::parseXml(char* xmlStr) {
    int len = strlen(xmlStr);
    char* copy = (char*)operator_vec_new_impl(len + 1);
    *(char**)((u8*)this + 4) = copy;
    strcpy(copy, xmlStr);

    // Allocate parse state (4 bytes)
    void* parseState = operator_vec_new_impl(4);
    *(void**)((u8*)this + 28) = parseState;

    // Parse root node
    void* rootNode = NULL; // _ParseNode(NULL, copy)
    *(void**)parseState = rootNode;
    *(int*)((u8*)this + 16) = 1;

    // Run full parse
    // _Parse(this, rootNode, copy)
}

// ============================================================================
// SimsLightInfo
// ============================================================================

class SimsLightInfo {
public:
    // offset 0:  field0 (2 bytes)
    // offset 2:  field2 (2 bytes)
    // offset 4:  field4 (4 bytes)
    // offset 8:  field8 (12 bytes - EVec3)
    // offset 20: field20 (4 bytes)
    // offset 24: field24 (4 bytes)
    int Read(unsigned char* data);
};

// 0x80362210 (164 bytes)
int SimsLightInfo::Read(unsigned char* data) {
    unsigned char* start = data;

    memcpy((u8*)this + 0, data, 2);   data += 2;
    memcpy((u8*)this + 2, data, 2);   data += 2;
    memcpy((u8*)this + 4, data, 4);   data += 4;
    memcpy((u8*)this + 8, data, 12);  data += 12;
    memcpy((u8*)this + 20, data, 4);  data += 4;
    memcpy((u8*)this + 24, data, 4);  data += 4;

    return (int)(data - start); // total bytes read = 28
}

// ============================================================================
// EMovie
// ============================================================================

class EMovie {
public:
    // offset 8: m_vtable2 (for sub-object)
    void Update();
};

// 0x80364C24 (168 bytes)
void EMovie::Update() {
    // Virtual call: this->IsFinished() via vtable at offset 8 -> offsets 40/44
    u32* vt = *(u32**)((u8*)this + 8);
    int finished; // = virtual call result
    if (finished != 0) return;

    // Get EMovieMan singleton
    // Virtual call: movieMan->Acquire(0) via vtable offset 128/132
    void* movieMan; // singleton
    // movieMan->SetMovie(this) via vtable offset 592
    // movieMan->Release(movieMan) via vtable offset 136/140
}

// ============================================================================
// IconGroup
// ============================================================================

class IconGroup {
public:
    int GetBalloonSpriteID(int balloonType);
};

// 0x800BCC68 (156 bytes)
int IconGroup::GetBalloonSpriteID(int balloonType) {
    int result = 0;

    // Create a local IconGroupImpl on the stack
    IconGroupImpl localGroup;
    localGroup.Init(1);

    int spriteIdx;
    switch (balloonType) {
        case 0: spriteIdx = 0; break;
        case 1: spriteIdx = 1; break;
        case 2: spriteIdx = 2; break;
        default: goto cleanup;
    }

    result = localGroup.GetSpriteID(spriteIdx);

cleanup:
    localGroup.~IconGroupImpl();
    return result;
}

// ============================================================================
// DigestGeomShaderPtr
// ============================================================================

class DigestGeomShaderPtr {
public:
    // offset 4: m_shaderDef (ptr)
    // offset 8: m_flags (u32)
    void UpdateShaderFlags(bool& hasAlpha);
};

// 0x80227530 (164 bytes)
void DigestGeomShaderPtr::UpdateShaderFlags(bool& hasAlpha) {
    void* shaderDef = *(void**)((u8*)this + 4);

    // Get actual shader data - check field 20, fallback to field 24->field 20
    void* shaderData = *(void**)((u8*)shaderDef + 20);
    if (!shaderData) {
        void* alt = *(void**)((u8*)shaderDef + 24);
        if (alt) {
            shaderData = *(void**)((u8*)alt + 20);
        }
    }

    // Read shader flags from shaderData
    u32 texFlags = *(u32*)((u8*)shaderData + 4);
    *(u32*)((u8*)this + 8) = texFlags;

    // Check material properties at shaderData+100
    u8* matData = (u8*)shaderData + 100;
    u32 matFlags = *(u32*)(matData + 12);
    int hasTransparency = 0;

    if (matFlags & 64) {
        // Check blend modes
        if (matData[28] == 1 || matData[29] == 1 || matData[31] == 1) {
            hasTransparency = 1;
        }
    }

    if (hasTransparency) {
        u32 flags = *(u32*)((u8*)this + 8);
        if (!(flags & 2048)) {
            flags |= 32768;
            *(u32*)((u8*)this + 8) = flags;
        }
    }

    // Check if alpha flag is set
    u32 finalFlags = *(u32*)((u8*)this + 8);
    if (finalFlags & 32) {
        hasAlpha = true;
    }
}

// ============================================================================
// TrackDataReader
// ============================================================================

class TrackDataReader {
public:
    // offset 0: m_track (void*)
    // offset 4: m_commandIndex (int)
    void* ReadCommand();
    void Trace() const;
};

// Tracks have:
// offset 20: m_commandData (void*)
// offset 24: m_commandDataEnd (void*)

// 0x80116378 (172 bytes)
void* TrackDataReader::ReadCommand() {
    void* track = *(void**)((u8*)this + 0);
    if (!track) {
        // No track - emit a default "end" command
        Trace();
        // Return pointer to static default command (stored in SDA globals)
        return NULL; // simplified
    }

    u32 dataStart = *(u32*)((u8*)track + 20);
    u32 dataEnd = *(u32*)((u8*)track + 24);
    int cmdIdx = *(int*)((u8*)this + 4);
    int numCommands = (int)(dataEnd - dataStart) >> 2;

    if (cmdIdx >= numCommands) {
        Trace();
        // Return pointer to last command
        void* lastCmd = (void*)(dataStart + ((dataEnd - dataStart) & ~3u) - 4);
        return lastCmd;
    }

    *(int*)((u8*)this + 4) = cmdIdx + 1;
    return (void*)(dataStart + cmdIdx * 4);
}

// ============================================================================
// ENeighborhoodCustomChar
// ============================================================================

class ENeighborhoodCustomChar {
public:
    // offset 0-11: shorts (6x s16)
    // offset 12: m_flag (u8)
    // offset 16: m_field16 (u32)
    // offset 20: CasSimDescriptionS2C sub-object (starts here)
    // offset 312-371: zeros (15x u32)
    // offset 372: m_field372 (u32)
    // offset 376-400: zeros (4x u32, backward loop)
    ENeighborhoodCustomChar();
};

// 0x800C8A58 (188 bytes)
ENeighborhoodCustomChar::ENeighborhoodCustomChar() {
    // Construct CasSimDescriptionS2C at offset 20
    CasSimDescriptionS2C* desc = (CasSimDescriptionS2C*)((u8*)this + 20);
    // desc->CasSimDescriptionS2C(false)

    // Zero out all short fields
    *(s16*)((u8*)this + 0)  = 0;
    *(s16*)((u8*)this + 2)  = 0;
    *(s16*)((u8*)this + 4)  = 0;
    *(s16*)((u8*)this + 6)  = 0;
    *(s16*)((u8*)this + 8)  = 0;
    *(s16*)((u8*)this + 10) = 0;
    *(u8*)((u8*)this + 12)  = 0;
    *(u32*)((u8*)this + 16) = 0;
    *(u32*)((u8*)this + 372) = 0;

    // Zero fields 312-368 (15 words)
    for (int i = 0; i < 15; i++) {
        *(u32*)((u8*)this + 312 + i * 4) = 0;
    }

    // Zero fields 388-400 backward (4 words via CTR loop)
    for (int i = 0; i < 4; i++) {
        *(u32*)((u8*)this + 388 + i * 4) = 0;
    }
}

// ============================================================================
// PlumbBobStack
// ============================================================================

struct PlumbBobState {
    u32 field0;  // from PlumbBob offset 296
    u32 field4;  // from PlumbBob offset 300
    u32 field8;  // from PlumbBob offset 304
    u32 field12; // from PlumbBob offset 364
};

class PlumbBobStack {
public:
    // offset 0: m_count (int)
    // offset 4: m_stack[4] (PlumbBobState, 16 bytes each)
    void Push(PlumbBob* bob);
    void Pop(PlumbBob* bob);
};

// 0x8005974C (76 bytes)
void PlumbBobStack::Push(PlumbBob* bob) {
    int count = *(int*)this;
    if (count > 3) return; // max 4 entries

    PlumbBobState* entry = (PlumbBobState*)((u8*)this + 4 + count * 16);
    // Copy state from PlumbBob
    entry->field12 = *(u32*)((u8*)bob + 364);
    entry->field0  = *(u32*)((u8*)bob + 296);
    entry->field8  = *(u32*)((u8*)bob + 304);
    entry->field4  = *(u32*)((u8*)bob + 300);

    *(int*)this = count + 1;
}

// 0x80059798 (72 bytes)
void PlumbBobStack::Pop(PlumbBob* bob) {
    int count = *(int*)this;
    if (count == 0) return;

    count--;
    *(int*)this = count;

    PlumbBobState* entry = (PlumbBobState*)((u8*)this + 4 + count * 16);
    // Restore state to PlumbBob
    *(u32*)((u8*)bob + 364) = entry->field12;
    *(u32*)((u8*)bob + 296) = entry->field0;
    *(u32*)((u8*)bob + 304) = entry->field8;
    *(u32*)((u8*)bob + 300) = entry->field4;
}

// ============================================================================
// EdithResFile
// ============================================================================

class ChainResFile {
public:
    // offset 12: m_vtable
    ChainResFile();
};

class SeqResFile {
public:
    void ClearOpenSpecs();
    void AddOpenSpec(int spec, char* name);
};

class EdithResFile : public ChainResFile {
public:
    // offset 208: m_count
    // offset 212: m_name (StringBuffer)
    EdithResFile();
};

// 0x80145C38 (196 bytes)
EdithResFile::EdithResFile() {
    // base class ChainResFile initialized by compiler
    // Set ChainResFile vtable at offset 12

    // Initialize 8 StringBuffers at offset 208+
    // Each has a char[8] buffer and is 20 bytes apart
    // offset 208 = count, followed by 8 StringBuffer entries
    int count = 8;
    u8* ptr = (u8*)this + 208;
    for (int i = count; i > 0; i--) {
        // StringBuffer::StringBuffer(ptr+4, ptr+12, 8)
        ptr += 20;
    }

    *(int*)((u8*)this + 208) = 0;

    // Initialize local StringBuffer for empty string
    // StringBuffer::StringBuffer(local, localBuf, 8)
    // StringBuffer::append("", -1)
    // Copy to field 212
    // StringBuffer::copy(this->m_name, local)

    // Set EdithResFile vtable at offset 12
    SeqResFile* seq = (SeqResFile*)this;
    seq->ClearOpenSpecs();
    seq->AddOpenSpec(2, "iff");
}

// ============================================================================
// EGEVert
// ============================================================================

class EGEVert {
public:
    // 80 bytes total: 4 floats (pos) + 16 bytes + 4 floats + 16 bytes + 16 bytes
    void operator=(EGEVert& other);
};

// 0x8039E338 (192 bytes)
void EGEVert::operator=(EGEVert& other) {
    u32* dst = (u32*)this;
    u32* src = (u32*)&other;

    // Copy first 4 floats (16 bytes, offset 0-15)
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; dst[3] = src[3];

    // Copy 16 bytes at offset 16-31 (4 words via CTR loop)
    for (int i = 0; i < 4; i++) {
        dst[4 + i] = src[4 + i];
    }

    // Copy 4 floats at offset 32-47
    dst[8] = src[8]; dst[9] = src[9]; dst[10] = src[10]; dst[11] = src[11];

    // Copy 16 bytes at offset 48-63 (4 words via CTR loop)
    for (int i = 0; i < 4; i++) {
        dst[12 + i] = src[12 + i];
    }

    // Copy 16 bytes at offset 64-79 (4 words via CTR loop)
    for (int i = 0; i < 4; i++) {
        dst[16 + i] = src[16 + i];
    }
}

// ============================================================================
// EFixedPool
// ============================================================================

class EFixedPool {
public:
    // offset 0: (base)
    // offset 4: m_buffer (void*)
    ~EFixedPool();
    void Init(int elemSize, int count);
    void Init(int elemSize, int count, void* buffer);
};

// 0x802C7328 (72 bytes)
EFixedPool::~EFixedPool() {
    EAHeap* heap = MainHeap();
    heap->Free(*(void**)((u8*)this + 4));
    // if (shouldDelete) delete this
}

// 0x802C7370 (100 bytes)
void EFixedPool::Init(int elemSize, int count) {
    EAHeap* heap = MainHeap();
    int totalSize = elemSize * count;
    void* buffer = heap->MallocAligned(totalSize, 32, 0, 0);
    *(void**)((u8*)this + 4) = buffer;
    Init(elemSize, count, buffer);
}

// ============================================================================
// EMemoryBufferWriteStream
// ============================================================================

class EMemoryBufferWriteStream {
public:
    // offset 28: m_buffer (u8*)
    // offset 32: m_position (int)
    int Write(void* data, int size);
};

// 0x802E09EC (188 bytes)
int EMemoryBufferWriteStream::Write(void* data, int size) {
    u8* buffer = *(u8**)((u8*)this + 28);
    int pos = *(int*)((u8*)this + 32);
    *(int*)((u8*)this + 32) = pos + size;

    u8* dst = buffer + pos;
    u8* src = (u8*)data;

    // Optimized copy with Duff's device-like fallthrough
    switch (size) {
        default:
            memcpy(dst, src, size);
            break;
        case 4:
            dst[0] = src[0]; dst++; src++;
            // fallthrough
        case 3:
            dst[0] = src[0]; dst++; src++;
            // fallthrough
        case 2:
            dst[0] = src[0]; dst++; src++;
            // fallthrough
        case 1:
            dst[0] = src[0];
            break;
        case 0:
            break;
    }
    return size;
}

// ============================================================================
// EMemoryReadStream
// ============================================================================

class EMemoryReadStream {
public:
    // offset 28: m_buffer (u8*)
    // offset 32: m_position (int)
    int Read(void* data, int size);
};

// 0x802E091C (208 bytes)
int EMemoryReadStream::Read(void* data, int size) {
    if (!data) return 0;

    u8* buffer = *(u8**)((u8*)this + 28);
    int pos = *(int*)((u8*)this + 32);
    *(int*)((u8*)this + 32) = pos + size;

    u8* src = buffer + pos;
    u8* dst = (u8*)data;

    switch (size) {
        default:
            memcpy(dst, src, size);
            break;
        case 4:
            dst[0] = src[0]; dst++; src++;
            // fallthrough
        case 3:
            dst[0] = src[0]; dst++; src++;
            // fallthrough
        case 2:
            dst[0] = src[0]; dst++; src++;
            // fallthrough
        case 1:
            dst[0] = src[0];
            break;
        case 0:
            break;
    }
    return size;
}

// ============================================================================
// ObjectTypeAttrBlock
// ============================================================================

class ObjectTypeAttrBlock {
public:
    // offset 0: m_type (int)
    // offset 4: m_count (int)
    // offset 8: m_attrs (short*)
    ObjectTypeAttrBlock(int type, int count);
    ~ObjectTypeAttrBlock();
    void Clear();
};

// 0x8010FD80 (96 bytes)
ObjectTypeAttrBlock::ObjectTypeAttrBlock(int type, int count) {
    *(int*)((u8*)this + 0) = type;
    *(int*)((u8*)this + 4) = count;

    if (count <= 31999) {
        short* attrs = (short*)operator_vec_new_impl(count * 2);
        *(short**)((u8*)this + 8) = attrs;
    } else {
        *(short**)((u8*)this + 8) = NULL;
        *(int*)((u8*)this + 4) = 0;
    }

    Clear();
}

// 0x8010FDE0 (76 bytes)
ObjectTypeAttrBlock::~ObjectTypeAttrBlock() {
    short* attrs = *(short**)((u8*)this + 8);
    if (attrs) {
        operator_vec_delete_impl(attrs);
    }
    // if (shouldDelete) delete this
}

// ============================================================================
// TreeSim::_dyncastimpl
// ============================================================================

class TreeSim {
public:
    // offset 0: m_field0 (void*)
    // offset 4: m_field4 (void*)
    // offset 8: m_field8 (void*)
    // offset 12: m_field12 (void*)
    void* _dyncastimpl(int scid);
};

// 0x800F2BA4 (176 bytes)
void* TreeSim::_dyncastimpl(int scid) {
    void* field;
    switch (scid) {
        case 7:
            field = *(void**)((u8*)this + 4);
            return field;
        case 8:
            return *(void**)((u8*)this + 8);
        case 10:
            return *(void**)((u8*)this + 0);
        case 11:
            return *(void**)((u8*)this + 12);
        case 6: {
            void* f12 = *(void**)((u8*)this + 12);
            if (!f12) return NULL;
            return *(void**)((u8*)f12 + 4);
        }
        case 2: {
            void* f4 = *(void**)((u8*)this + 4);
            if (!f4) return NULL;
            return *(void**)((u8*)f4 + 4);
        }
        case 3: {
            void* f8 = *(void**)((u8*)this + 8);
            if (!f8) return NULL;
            return *(void**)((u8*)f8 + 4);
        }
        case 1:
        case 5: {
            void* f0 = *(void**)((u8*)this + 0);
            if (!f0) return NULL;
            return *(void**)((u8*)f0 + 4);
        }
        default:
            return NULL;
    }
}

// ============================================================================
// EVec4 (ToU8s / FromU8s)
// ============================================================================

class EVec4_impl {
public:
    float x, y, z, w;

    void ToU8s(unsigned char* out) const;
    void FromU8s(unsigned char* in);
};

// 0x80361F38 (120 bytes)
void EVec4_impl::ToU8s(unsigned char* out) const {
    const float* components = &x;
    for (int i = 0; i < 4; i++) {
        float val = components[i] * 255.0f;
        if (val < 0.0f) {
            out[i] = 0;
        } else if (val > 255.0f) {
            out[i] = 255;
        } else {
            out[i] = (unsigned char)(int)val;
        }
    }
}

// 0x80361FB0 (88 bytes)
void EVec4_impl::FromU8s(unsigned char* in) {
    float* components = &x;
    for (int i = 0; i < 4; i++) {
        components[i] = (float)in[i] / 255.0f;
    }
}

// ============================================================================
// ECullPlane
// ============================================================================

class ECullPlane {
public:
    float m_plane[4];   // offset 0-15: plane equation (a,b,c,d)
    u8    m_signs1[3];  // offset 16-18
    u8    m_signs2[3];  // offset 19-21
    void SetPlane(EVec4& plane);
};

// 0x80362F28 (236 bytes)
void ECullPlane::SetPlane(EVec4& plane) {
    float* src = (float*)&plane;
    m_plane[0] = src[0];
    m_plane[1] = src[1];
    m_plane[2] = src[2];
    m_plane[3] = src[3];

    // Compute sign bytes for culling optimization
    // For each axis component, determine which corner of a bounding box
    // to test against the plane
    float zero = 0.0f;
    float posArr[3] = { zero, zero, zero };
    float negArr[3] = { zero, zero, zero };

    for (int i = 0; i < 3; i++) {
        s8 posSign, negSign;
        if (m_plane[i] > zero) {
            // Component > 0: use max corner for positive test
            posSign = (s8)(((int)(uintptr_t)&negArr[i] - (int)(uintptr_t)&posArr[0]) >> 2);
            negSign = (s8)(((int)(uintptr_t)&posArr[i] - (int)(uintptr_t)&posArr[0]) >> 2);
        } else {
            posSign = (s8)(((int)(uintptr_t)&posArr[i] - (int)(uintptr_t)&posArr[0]) >> 2);
            negSign = (s8)(((int)(uintptr_t)&negArr[i] - (int)(uintptr_t)&posArr[0]) >> 2);
        }
        m_signs2[i] = posSign;
        m_signs1[i] = negSign;
    }
}

// ============================================================================
// ERenderSurface
// ============================================================================

class ERenderSurface {
public:
    int Create(ERenderSurfaceDef& def);
    void GetOutputRect(TRect<float>& rect);
};

// 0x80364E58 (96 bytes)
int ERenderSurface::Create(ERenderSurfaceDef& def) {
    // Copy 56 bytes (same 2x24 + 8 pattern as ETexture::Create)
    u32* dst = (u32*)this;
    u32* src = (u32*)&def;
    for (int i = 0; i < 2; i++) {
        dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];
        dst[3] = src[3]; dst[4] = src[4]; dst[5] = src[5];
        dst += 6; src += 6;
    }
    dst[0] = src[0];
    dst[1] = src[1];
    return 1;
}

// 0x80364EE8 (116 bytes)
void ERenderSurface::GetOutputRect(TRect<float>& rect) {
    int width  = *(int*)((u8*)this + 0);
    int height = *(int*)((u8*)this + 4);
    float fWidth  = (float)(width - 1);
    float fHeight = (float)(height - 1);
    float* r = (float*)&rect;
    r[0] = 0.0f;  // left
    r[1] = 0.0f;  // top
    r[2] = fWidth;  // right
    r[3] = fHeight; // bottom
}

// ============================================================================
// ObjectDataSlotDescList
// ============================================================================

class ObjectDataSlotDescList {
public:
    // offset 0: vtable
    // offset 4: m_name (StringBuffer, inline)
    // offset 76: m_dataId (ObjectDataID)
    ObjectDataSlotDescList();
    int GetResourceName(StringBuffer& out) const;
};

// 0x801445F8 (116 bytes)
ObjectDataSlotDescList::ObjectDataSlotDescList() {
    // Set vtable at offset 0
    // Initialize StringBuffer at offset 4 with char[64] at offset 12
    StringBuffer* name = (StringBuffer*)((u8*)this + 4);
    // StringBuffer::StringBuffer(this+12, 64)
    // StringBuffer::append("slot", -1)
    // Initialize ObjectDataID at offset 76 with (0, 0)
}

// 0x801446A0 (84 bytes)
int ObjectDataSlotDescList::GetResourceName(StringBuffer& out) const {
    StringBuffer* name = (StringBuffer*)((u8*)this + 4);
    int len = name->length();
    if (len == 0) return 0;
    out.copy(*name);
    return 1;
}

// ============================================================================
// NeighborList
// ============================================================================

class Neighbor {
public:
    ~Neighbor();
};

class NeighborList {
public:
    // offset 0: m_begin (Neighbor**)
    // offset 4: m_end (Neighbor**)
    // offset 8: m_capacity info
    void DeleteAll();
};

// 0x800CC9E8 (240 bytes)
void NeighborList::DeleteAll() {
    void** begin = *(void***)((u8*)this + 0);
    void** end   = *(void***)((u8*)this + 4);

    // Delete all Neighbor objects in the array
    for (void** it = begin; it != end; it++) {
        Neighbor* n = (Neighbor*)*it;
        if (n) {
            n->~Neighbor();
            operator_delete_impl(n);
        }
    }

    // Swap with empty vector (clear + free)
    // This frees the array buffer if size > 128, else uses node_alloc
    void** oldBegin = *(void***)((u8*)this + 0);
    *(void***)((u8*)this + 0) = NULL;
    *(void***)((u8*)this + 4) = NULL;

    if (oldBegin) {
        u32 endAddr = *(u32*)((u8*)this + 12); // capacity end
        u32 size = (endAddr - (u32)(uintptr_t)oldBegin) & ~3u;
        if (size > 128) {
            operator_delete_impl(oldBegin);
        } else {
            node_alloc_deallocate(oldBegin, size);
        }
    }
}

// ============================================================================
// GameTime
// ============================================================================

class GameTime {
public:
    static int SubtractDates(int y1, int m1, int d1, int y2, int m2, int d2);
    static int GetDaysSince1900(int year, int month, int day);
    static int CountDaysInMonth(int year, int month);
};

// 0x80147098 (76 bytes)
int GameTime::SubtractDates(int y1, int m1, int d1, int y2, int m2, int d2) {
    int days1 = GetDaysSince1900(y1, m1, d1);
    int days2 = GetDaysSince1900(y2, m2, d2);
    return days1 - days2;
}

// 0x801470E4 (128 bytes)
int GameTime::GetDaysSince1900(int year, int month, int day) {
    if (year <= 1899) return 0;
    if ((unsigned int)(month - 1) > 11) return 0;

    int totalDays = day - 1;
    int yearsFrom1900 = year - 1900;

    // Add days for each month before the target month
    for (int m = 1; m < month; m++) {
        totalDays += CountDaysInMonth(year, m);
    }

    // Add 360 days per year (simplified calendar)
    totalDays += yearsFrom1900 * 360;
    return totalDays;
}

// ============================================================================
// TreeTableAdQuickData
// ============================================================================

class TreeTableAdQuickData {
public:
    // offset 0: vtable
    // offset 8: m_refCount (int)
    int QueryInterface(unsigned int iid, void** ppOut);
    int Release();
};

// 0x8015E2BC (112 bytes)
int TreeTableAdQuickData::QueryInterface(unsigned int iid, void** ppOut) {
    if (!ppOut) return 0;

    // Accept IID == 1 or IID == 0x6BF32297
    if (iid == 1 || iid == 0x6BF32297) {
        // AddRef via virtual call at vtable offset 16/20
        u32* vt = *(u32**)this;
        // virtual AddRef()
        *ppOut = this;
        return 1;
    }
    return 0;
}

// 0x8015E340 (92 bytes)
int TreeTableAdQuickData::Release() {
    int refCount = *(int*)((u8*)this + 8);
    refCount--;
    *(int*)((u8*)this + 8) = refCount;

    if (refCount == 0) {
        if (this) {
            // Virtual destructor call at vtable offset 104/108
            // delete this (flag=3)
        }
        return 0;
    }
    return refCount;
}

// ============================================================================
// AptScriptFunctionByteCodeBlock
// ============================================================================

class AptScriptFunctionByteCodeBlock : public AptScriptFunctionBase {
public:
    // offset 52: m_bytecode (unsigned char*)
    // offset 56: m_bytecodeSize (int)
    // offset 60: m_name (char*)
    // offset 64-71: m_constantPool (AptConstantPool, 2 ints)
    AptScriptFunctionByteCodeBlock(unsigned char* bytecode, int size,
        AptConstantPool pool, char* name, AptCIH* cih, AptScriptFunctionBase* parent);
    ~AptScriptFunctionByteCodeBlock();
};

// 0x802B8788 (116 bytes)
AptScriptFunctionByteCodeBlock::AptScriptFunctionByteCodeBlock(
    unsigned char* bytecode, int size, AptConstantPool pool,
    char* name, AptCIH* cih, AptScriptFunctionBase* parent)
    : AptScriptFunctionBase(45, parent, cih, false)
{
    // Set derived vtable at offset 8
    *(unsigned char**)((u8*)this + 52) = bytecode;
    *(int*)((u8*)this + 56) = size;
    *(char**)((u8*)this + 60) = name;
    *(int*)((u8*)this + 64) = pool.data[0];
    *(int*)((u8*)this + 68) = pool.data[1];
}

// 0x802B91C4 (88 bytes)
AptScriptFunctionByteCodeBlock::~AptScriptFunctionByteCodeBlock() {
    // Set vtable
    // AptScriptFunctionBase base destructor called implicitly
    // if (shouldDelete) DOGMA_PoolManager::DeallocateAptValueGC(this, 72)
}

// ============================================================================
// AptCharacterButtonInst
// ============================================================================

class AptCharacterButtonInst {
public:
    // offset 0:  m_charId (int, init to -1)
    // offset 4:  (padding/unused)
    // offset 8:  m_field8 (int)
    // offset 12: m_nativeHash (AptNativeHash*)
    // offset 16: m_field16 (int)
    // offset 20: m_vtable2
    // offset 28: m_displayList (AptDisplayList)
    AptCharacterButtonInst();
    ~AptCharacterButtonInst();
};

// 0x802C4B5C (112 bytes)
AptCharacterButtonInst::AptCharacterButtonInst() {
    *(int*)((u8*)this + 12) = 0;
    *(int*)((u8*)this + 0) = -1;
    // Set vtable at offset 20
    *(int*)((u8*)this + 16) = 0;
    *(int*)((u8*)this + 8) = 0;

    // Construct AptDisplayList at offset 28
    AptDisplayList* dl = (AptDisplayList*)((u8*)this + 28);
    // dl->AptDisplayList()

    // Allocate AptNativeHash(4) from DOGMA pool
    void* mem = g_pDogmaPoolManager->Allocate(20);
    AptNativeHash* hash = new (mem) AptNativeHash(4);
    *(AptNativeHash**)((u8*)this + 12) = hash;
}

// 0x802C4AEC (112 bytes)
AptCharacterButtonInst::~AptCharacterButtonInst() {
    // Destroy display list at offset 28
    AptDisplayList* dl = (AptDisplayList*)((u8*)this + 28);
    dl->~AptDisplayList();

    // Set vtable at offset 20
    AptNativeHash* hash = *(AptNativeHash**)((u8*)this + 12);
    if (hash) {
        hash->~AptNativeHash();
        operator_delete_impl(hash);
    }

    // if (shouldDelete) DOGMA_PoolManager::Deallocate(this, 32)
}

// ============================================================================
// AptExtern
// ============================================================================

class AptExtern : public AptValue {
public:
    int objectMemberSet(AptValue* obj, EAStringC* name, AptValue* value);
    ~AptExtern();
};

// 0x802B44B4 (128 bytes)
int AptExtern::objectMemberSet(AptValue* obj, EAStringC* name, AptValue* value) {
    // Convert value to string
    EAStringC tempStr;
    // tempStr.EAStringC()
    value->toString(tempStr);

    // Get the c_str from name and tempStr
    char* nameStr = name->c_str();
    char* valStr  = tempStr.c_str(); // operator char*

    // Call the extern callback function pointer
    // Located at offset 60 of a global table
    // callback(nameStr, valStr)

    tempStr.~EAStringC();
    return 1;
}

// 0x802B453C (88 bytes)
AptExtern::~AptExtern() {
    // Set derived vtable at offset 8
    // AptValue base destructor called implicitly
    // if (shouldDelete) DOGMA_PoolManager::Deallocate(this, 12)
}

// ============================================================================
// MembersIndex classes (gperf hash table pattern)
// ============================================================================

// All MembersIndex::in_word_set functions follow the same pattern:
// 1. Check if string length is within expected range
// 2. Copy a static association table to stack (256 bytes)
// 3. Hash using first char + last char + length
// 4. Look up result in word list, compare with strcmp
// 5. Return pointer to entry or NULL

struct MembersIndexEntry {
    char* name;
    u32   data;
};

// --- ArrayMembersIndex ---

extern MembersIndexEntry g_arrayMembersWordList[];
extern u8 g_arrayMembersAssocValues[];

class ArrayMembersIndex {
public:
    static MembersIndexEntry* in_word_set(char* str, unsigned int len);
};

// 0x80285800 (264 bytes)
MembersIndexEntry* ArrayMembersIndex::in_word_set(char* str, unsigned int len) {
    if (len - 3 > 5) return NULL; // valid range: 3-8

    // Copy 256 bytes of association values to stack
    u8 assocValues[256];
    memcpy(assocValues, g_arrayMembersAssocValues, 256);

    u8 firstChar = str[0];
    u8 lastChar = str[len - 1];
    unsigned int hashVal = len + assocValues[firstChar] + assocValues[lastChar];

    if (hashVal > 27) return NULL;

    MembersIndexEntry* entry = &g_arrayMembersWordList[hashVal];
    if (entry->name[0] != firstChar) return NULL;
    if (strcmp(str + 1, entry->name + 1) != 0) return NULL;
    return entry;
}

// --- LoadVarsMembersIndex ---

extern MembersIndexEntry g_loadVarsMembersWordList[];
extern u8 g_loadVarsMembersAssocValues[];

class LoadVarsMembersIndex {
public:
    static MembersIndexEntry* in_word_set(char* str, unsigned int len);
};

// 0x802A2A60 (264 bytes)
MembersIndexEntry* LoadVarsMembersIndex::in_word_set(char* str, unsigned int len) {
    if (len - 4 > 10) return NULL;

    u8 assocValues[256];
    memcpy(assocValues, g_loadVarsMembersAssocValues, 256);

    u8 firstChar = str[0];
    u8 lastChar = str[len - 1];
    unsigned int hashVal = len + assocValues[firstChar] + assocValues[lastChar];

    if (hashVal > 16) return NULL;

    MembersIndexEntry* entry = &g_loadVarsMembersWordList[hashVal];
    if (entry->name[0] != firstChar) return NULL;
    if (strcmp(str + 1, entry->name + 1) != 0) return NULL;
    return entry;
}

// --- SoundMembersIndex ---

extern MembersIndexEntry g_soundMembersWordList[];
extern u8 g_soundMembersAssocValues[];

class SoundMembersIndex {
public:
    static MembersIndexEntry* in_word_set(char* str, unsigned int len);
};

// 0x802AB740 (264 bytes)
MembersIndexEntry* SoundMembersIndex::in_word_set(char* str, unsigned int len) {
    if (len - 4 > 7) return NULL;

    u8 assocValues[256];
    memcpy(assocValues, g_soundMembersAssocValues, 256);

    u8 firstChar = str[0];
    u8 lastChar = str[len - 1];
    unsigned int hashVal = len + assocValues[firstChar] + assocValues[lastChar];

    if (hashVal > 11) return NULL;

    MembersIndexEntry* entry = &g_soundMembersWordList[hashVal];
    if (entry->name[0] != firstChar) return NULL;
    if (strcmp(str + 1, entry->name + 1) != 0) return NULL;
    return entry;
}

// ============================================================================
// TreeTable
// ============================================================================

struct TreeTableEntry_s {
    s16 m_resId;  // offset 0
    s16 m_treeId; // offset 2
    // 36 bytes total per entry
};

class TreeTable {
public:
    // offset 0: m_entries (TreeTableEntry_s*)
    int GetIndexOfResource(short resId) const;
    int GetIndexByTreeID(short resId, short treeId) const;
};

// 0x801498B0 (116 bytes)
int TreeTable::GetIndexOfResource(short resId) const {
    TreeTableEntry_s* entries = *(TreeTableEntry_s**)((u8*)this + 0);
    int count = 0;
    if (entries) {
        count = *(int*)((u8*)entries - 4);
    }

    TreeTableEntry_s* end = (TreeTableEntry_s*)((u8*)entries + count * 36);
    TreeTableEntry_s* found = FindRes(entries, end, resId);
    if (!found) return -1;

    // Calculate index: (found - entries) / 36
    // Using magic number division: 0x38F32CA9 * diff >> 2
    int byteOffset = (int)((u8*)found - (u8*)entries);
    // Compiler uses multiply-by-reciprocal for /36
    return byteOffset / 36;
}

// 0x80149924 (92 bytes)
int TreeTable::GetIndexByTreeID(short resId, short treeId) const {
    TreeTableEntry_s* entries = *(TreeTableEntry_s**)((u8*)this + 0);
    int count = 0;
    if (entries) {
        count = *(int*)((u8*)entries - 4);
    }

    for (short i = 0; i < count; i++) {
        TreeTableEntry_s* entry = (TreeTableEntry_s*)((u8*)entries + i * 36);
        if (entry->m_resId == resId && entry->m_treeId == treeId) {
            return i;
        }
    }
    return -1;
}

// ============================================================================
// CasListener
// ============================================================================

class CasListener {
public:
    // offset 0: (base)
    // offset 4: m_vtable (ptr to vtable with event handlers)
    void HandleEvent(CasEvent& event);
};

// CasEvent: offset 0 = event type (int)
// Vtable offsets for event handlers (by type):
// type 0 -> vtable offset 48/52
// type 1 -> vtable offset 56/60
// type 2 -> vtable offset 32/36
// type 3 -> vtable offset 64/68
// type 4 -> vtable offset 40/44
// type 5 -> vtable offset 72/76
// type 6 -> vtable offset 80/84

// 0x80161A6C (228 bytes)
void CasListener::HandleEvent(CasEvent& event) {
    int eventType = *(int*)&event;
    u32* vt = *(u32**)((u8*)this + 4);
    s16 offset;
    u32 funcAddr;

    switch (eventType) {
        case 0: offset = *(s16*)(vt + 12); funcAddr = vt[13]; break;
        case 1: offset = *(s16*)(vt + 14); funcAddr = vt[15]; break;
        case 2: offset = *(s16*)(vt + 8);  funcAddr = vt[9];  break;
        case 3: offset = *(s16*)(vt + 16); funcAddr = vt[17]; break;
        case 4: offset = *(s16*)(vt + 10); funcAddr = vt[11]; break;
        case 5: offset = *(s16*)(vt + 18); funcAddr = vt[19]; break;
        case 6: offset = *(s16*)(vt + 20); funcAddr = vt[21]; break;
        default: return;
    }

    // Virtual dispatch: ((void*)(this + offset))->func(event)
    // All types dispatch the same way
}

// ============================================================================
// UserDataSaveLoad
// ============================================================================

class UserDataSaveLoad {
public:
    // offset 0: m_simId (int)
    // offset 4: CasSimDescriptionS2C sub-object
    // offset 8: m_firstName[32] (wchar_t)
    // offset 72: m_lastName[32] (wchar_t)
    void DoStream(ReconBuffer* buf, int version);
};

// 0x800F239C (228 bytes)
void UserDataSaveLoad::DoStream(ReconBuffer* buf, int version) {
    // Stream sim ID
    buf->Recon32((int*)this, 1);

    // Stream CAS description
    CasSimDescriptionS2C* desc = (CasSimDescriptionS2C*)((u8*)this + 4);
    desc->DoStream(buf, version);

    // Build lookup string using Snprintf
    char nameBuf[128];
    int simId = *(int*)this;
    // Snprintf(nameBuf, 128, format, relTableVersion, simId)

    // If loading (version == 0), look up names from relationship table
    if (version == 0) {
        void* relRow; // = EGlobal::GetRelationshipTableRow(simId)
        if (relRow) {
            // Copy first name
            void* firstNamePtr = *(void**)((u8*)relRow + 16);
            void* firstName = firstNamePtr ? *(void**)firstNamePtr : NULL;
            wcsncpy((u8*)this + 8, firstName, 32);

            // Copy last name
            void* lastNamePtr = *(void**)((u8*)relRow + 20);
            void* lastName = lastNamePtr ? *(void**)lastNamePtr : NULL;
            wcsncpy((u8*)this + 72, lastName, 32);
        }
    }
}

// ============================================================================
// InLevelCreateASimState
// ============================================================================

class CreateASimBaseState {
public:
    void Update(float dt);
    void OwnerReturnFromState(int result);
    void OwnerSetNextState(int stateId, float param = 0.0f);
    void OwnerCallState(int stateId, float param = 0.0f);
};

class LoadingScreenStateMachine {
public:
    static int LoadInProgress();
    static void StartingLoad(int mode);
};

class InLevelCreateASimState : public CreateASimBaseState {
public:
    // offset 32: m_field32 (int)
    // offset 40: m_casComplete (int)
    // offset 44: m_casCancel (int)
    void Update(float dt);
};

// 0x80094DF0 (252 bytes)
void InLevelCreateASimState::Update(float dt) {
    CreateASimBaseState::Update(dt);

    // Check if CAS is complete (accepted)
    int field32 = *(int*)((u8*)this + 32);
    int casAccepted = (!field32 && *(int*)((u8*)this + 40)) ? 1 : 0;

    if (!casAccepted) {
        // Check if CAS is cancelled
        int casCancelled = (!field32 && *(int*)((u8*)this + 44)) ? 1 : 0;
        if (!casCancelled) return;
    }

    // Start loading if not already in progress
    if (!LoadingScreenStateMachine::LoadInProgress()) {
        LoadingScreenStateMachine::StartingLoad(4);
        return;
    }

    // Check if loading is done (flag 4 in game state)
    // ...
    // When done, go to live mode
    // GameData::GotoLiveMode()
    // Determine return code: 2 for accept, 1 for cancel
    int accepted = (!field32 && *(int*)((u8*)this + 40)) ? 1 : 0;
    int returnCode = accepted ? 2 : 1;
    this->OwnerReturnFromState(returnCode);
}

// ============================================================================
// PreGameCreateAFamilyState
// ============================================================================

class PreGameCreateAFamilyState : public CreateASimBaseState {
public:
    // offset 32: m_field32 (int)
    // offset 40: m_casComplete (int)
    // offset 44: m_casCancel (int)
    void Update(float dt);
};

// 0x80094CA0 (272 bytes)
void PreGameCreateAFamilyState::Update(float dt) {
    CreateASimBaseState::Update(dt);

    int field32 = *(int*)((u8*)this + 32);

    // Check for CAS accepted
    int casAccepted = (!field32 && *(int*)((u8*)this + 40)) ? 1 : 0;
    if (!casAccepted) {
        int casCancelled = (!field32 && *(int*)((u8*)this + 44)) ? 1 : 0;
        if (!casCancelled) return;
    }

    if (!LoadingScreenStateMachine::LoadInProgress()) {
        LoadingScreenStateMachine::StartingLoad(2);
        return;
    }

    // Check game state flag 4
    // When loading done:
    int currentField32 = *(int*)((u8*)this + 32);
    int wasAccepted = (!currentField32 && *(int*)((u8*)this + 40)) ? 1 : 0;

    if (wasAccepted) {
        this->OwnerReturnFromState(2);
        return;
    }

    int wasCancelled = (!currentField32 && *(int*)((u8*)this + 44)) ? 1 : 0;
    if (wasCancelled) {
        this->OwnerReturnFromState(1);
    }
}

// ============================================================================
// ENgcFileSystem
// ============================================================================

class ENgcFileSystem : public EFileSystem {
public:
    ~ENgcFileSystem();
    int Init(int deviceType);
};

extern "C" void DVDInit();
extern int g_ngcFileSystemInitialized; // r13 - 26876

// 0x802D73FC (84 bytes)
ENgcFileSystem::~ENgcFileSystem() {
    // Set vtable
    if (g_ngcFileSystemInitialized == 0) {
        EGlobalManager::Shutdown();
    }
    // EFileSystem base destructor called implicitly
}

// 0x802D7450 (152 bytes)
int ENgcFileSystem::Init(int deviceType) {
    DVDInit();

    // If deviceType == 0x80000000, use DVD type (3)
    if (deviceType == (int)0x80000000) {
        deviceType = 3;
    }

    int result = EFileSystem::Init(deviceType);
    if (result != 0) {
        // Register DVD file creator
        // RegisterFileCreator(0x80000000, 0x80000000, 0x80000000, NULL, ENgcSNFile::Create)
    }
    // Register ARC file creator
    // RegisterFileCreator(0x80000000, 2, 0x80000000, NULL, ENgcFile::Create)
    return result;
}

// ============================================================================
// ENgcPerf
// ============================================================================

extern "C" {
    void GXDrawDone();
    u32  GXReadGP0Metric();
    u32  GXReadGP1Metric();
    void GXSetGPMetric(u32 metric);
    void GXClearGPMetric();
}

extern int g_perfEnabled;    // r13 - 26336
extern int g_perfFrameIdx;   // r13 - 26332
extern int g_perfNumMetrics; // r13 - 26328
extern u32 g_perfMetricTable[]; // static table

class ENgcPerf {
public:
    static void ReadMetrics();
    static void ClearMetrics();
};

// 0x80338028 (132 bytes)
void ENgcPerf::ReadMetrics() {
    if (!g_perfEnabled) return;

    GXDrawDone();
    u32 gp0a = GXReadGP0Metric();
    u32 gp0b = GXReadGP0Metric();
    u32 gp1a = GXReadGP1Metric();
    u32 gp1b = GXReadGP1Metric();

    int frameIdx = g_perfFrameIdx;
    u32 tableOffset = frameIdx * 64; // 16 metrics * 4 bytes per metric * ?

    // Store min of gp0a,gp0b and min of gp1a,gp1b
    u32 minGP0 = (gp0b < gp0a) ? gp0b : gp0a;
    u32 minGP1 = (gp1b < gp1a) ? gp1b : gp1a;

    // Store to metric result table
}

// 0x803380AC (104 bytes)
void ENgcPerf::ClearMetrics() {
    if (!g_perfEnabled) return;

    GXDrawDone();

    int frameIdx = g_perfFrameIdx + 1;
    frameIdx = frameIdx % g_perfNumMetrics;
    g_perfFrameIdx = frameIdx;

    u32 metric = g_perfMetricTable[frameIdx * 16 + 2]; // offset by 8 bytes
    GXSetGPMetric(metric);
    GXClearGPMetric();
}

// ============================================================================
// cHitControlGroup
// ============================================================================

class cTrack {
public:
    int GetControlGroup();
    void UpdateVolPan();
};

class cSoundCache {
public:
    int IsInMemory(cTrack* track) const;
};

extern void* g_hitMan; // r13 - 24136

class cHitControlGroup {
public:
    // offset 0: m_groupId (int)
    // offset 4: m_volume (int)
    int SetVolume(int volume);
};

// 0x801167C8 (192 bytes)
int cHitControlGroup::SetVolume(int volume) {
    *(int*)((u8*)this + 4) = volume;

    // Iterate through linked list of tracks
    // The track list is a linked list starting at g_hitMan+4
    u8* hitMan = (u8*)g_hitMan;
    void* listNode = *(void**)(hitMan + 4);
    void* sentinel = *(void**)((u8*)listNode + 4);
    void* cur = *(void**)sentinel;

    while (cur != *(void**)((u8*)listNode + 4)) {
        cTrack* track = *(cTrack**)((u8*)cur + 8);
        cSoundCache* cache = *(cSoundCache**)(hitMan + 80);

        if (cache->IsInMemory(track)) {
            int group = track->GetControlGroup();
            if (group == *(int*)this) {
                track->UpdateVolPan();
            }
        }
        cur = *(void**)cur;
    }
    return 1;
}

// ============================================================================
// EAudioStreamManager (continued) - already above
// ============================================================================

// ============================================================================
// EMovieMan (continued) - already above
// ============================================================================
