// missing_stubs.cpp — Stub implementations for all undefined symbols on PC
// All stubs return zero/null/empty. Methods defined OUT-OF-LINE to force symbol emission.

#include "platform/platform.h"

#ifdef SIMS2_PLATFORM_PC

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cstdarg>
#include <cctype>

// ============================================================================
// C library wrapper — decomp declares memcpy with unsigned int (32-bit) size param
// ============================================================================
// memcpy/memset wrappers not needed — add -fpermissive globally instead
int stricmp(const char* a, const char* b) {
    while (*a && *b) {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d) return d;
        ++a; ++b;
    }
    return tolower((unsigned char)*a) - tolower((unsigned char)*b);
}
float AtoF(const char* s) { return (float)atof(s); }
int AtoI(const char* s) { return atoi(s); }
int AtoI(char* s) { return atoi(s); }
// AtoI with no args (linker shows "AtoI" without signature — function pointer?)
// Provide via alias:
static int AtoI_noarg(void) { return 0; }
int (*AtoI_ptr)(void) = AtoI_noarg;

// C++ linkage versions
int Sprintf(char* buf, char* fmt, ...) {
    va_list a; va_start(a, fmt); int r = vsprintf(buf, fmt, a); va_end(a); return r;
}
int Sprintf(char* buf, const char* fmt, ...) {
    va_list a; va_start(a, fmt);
    int r = vsprintf(buf, fmt, a);
    va_end(a); return r;
}

// ============================================================================
// C-linkage helpers
// ============================================================================
extern "C" {
void EORDbgTrace(const char* fmt, ...) {
    va_list a; va_start(a, fmt); vprintf(fmt, a); va_end(a);
}
// ProfileHook defined below (C++ linkage)
void* __builtin_vec_new(unsigned int n) { return malloc(n); }
void __builtin_vec_delete(void* p) { free(p); }
void* __builtin_new(unsigned int n) { return malloc(n); }
void __builtin_delete(void* p) { free(p); }
}

// C++ linkage wrappers — some decomp files declare these without extern "C"
// so the linker needs C++-mangled versions
void localConvertToWide(unsigned short* d, const char* s) {
    if (!d || !s) return;
    while (*s) *d++ = (unsigned short)(unsigned char)*s++;
    *d = 0;
}

int strcmp(const char* a, const char* b) { return ::strcmp(a, b); }

// More C++ linkage stubs for symbols declared without extern "C" in decomp files
void* small_alloc(unsigned int n) { return malloc(n); }
void small_free(void* p) { free(p); }
void* EAHeap_Alloc(int n) { return malloc(n); }
void* EAHeap_MallocAligned(int n, int align) { return malloc(n); }
void EGraphics_SetCameraBloom(float, float, float, float) {}
void EGraphics_SetMotionBlur(float, float, float, float) {}
void EMat4_Identity(void* m) { if (m) memset(m, 0, 64); }
void ProfileHook() {}

template<typename T> struct AllocPoolManager {
    void* AttemptPoolAlloc(unsigned int, unsigned int) { return malloc(64); }
    void* FindPoolForBlock(void*) { return nullptr; }
};
class ProtectedAllocPool;
template struct AllocPoolManager<ProtectedAllocPool>;

void* operator_new_impl(unsigned int n) { return malloc(n); }
void operator_delete_impl(void* p) { free(p); }
void* operator_vec_new_impl(unsigned int n) { return malloc(n); }
void operator_vec_delete_impl(void* p) { free(p); }
// These must be extern "C" — decomp code declares them with C linkage
extern "C" void* operator_new_wrapper(unsigned int n) { return malloc(n); }
extern "C" void  operator_delete_wrapper(void* p) { free(p); }

// ============================================================================
// STL allocator stubs
// ============================================================================
void* __node_alloc_M_allocate(unsigned int n) { return malloc(n); }
void* __node_alloc_M_deallocate(void* p, unsigned int) { free(p); return nullptr; }
void node_alloc_deallocate(void* p, unsigned int) { free(p); }
// small_alloc/small_free defined above (C++ linkage)

// ============================================================================
// EAHeap stubs — two overload sets (void* and EAHeap*)
// ============================================================================
struct EAHeap { void MallocAligned(unsigned int, unsigned int, int, int); };
void EAHeap::MallocAligned(unsigned int, unsigned int, int, int) {}

void* EAHeap_GetCurrentHeap() { return nullptr; }
// EAHeap_Alloc(int) defined above (C++ linkage)
void* EAHeap_Alloc(void*, unsigned int n, int) { return malloc(n); }
void* EAHeap_AllocAlign(void*, unsigned int n, unsigned int, int, int) { return malloc(n); }
void  EAHeap_Free(void*, void* p) { free(p); }
void* EAHeap_Malloc(void*, unsigned int n, int) { return malloc(n); }
void* EAHeap_MallocAligned(void*, unsigned int n, unsigned int, unsigned int, int) { return malloc(n); }
// EAHeap* overloads
void* EAHeap_Malloc(EAHeap*, unsigned int n, int) { return malloc(n); }
void* EAHeap_MallocAligned(EAHeap*, unsigned int n, unsigned int, unsigned int, int) { return malloc(n); }
void  EAHeap_Free(EAHeap*, void* p) { free(p); }

// ============================================================================
// Vtable pointers
// ============================================================================
void* ENgcRenderer_vtable = nullptr;
void* ERFont_vtable = nullptr;
void* ERShader_vtable = nullptr;
void* ERTexture_vtable = nullptr;
void* EResource_vtable = nullptr;
void* EResourceLoaderImpl_vtable = nullptr;
void* EResourceManager_vtable = nullptr;
void* EStorable_vtable = nullptr;
void* IFFResFile2_vtable = nullptr;
void* NghResFile_vtable = nullptr;

// ============================================================================
// Global variables
// ============================================================================
void* g_pRoomManager = nullptr;
void* g_pObjectManager = nullptr;
void* g_pTextureManager = nullptr;
void* g_pShaderSystem = nullptr;
void* g_pSoundPlayer = nullptr;
void* g_pSoundModeManager = nullptr;
void* g_pSimsMemCardWrap = nullptr;
void* g_pDogmaPoolManager = nullptr;
void* g_pEyeToyState = nullptr;
void* g_pH2DTarget = nullptr;
void* g_pAptBooleanPool = nullptr;
void* g_pAptFloatPool = nullptr;
void* g_pAptIntegerPool = nullptr;
void* g_pAptNoneValue = nullptr;
void* g_pAptSoundAttach = nullptr;
void* g_pAptSoundStart = nullptr;
void* g_pAptSoundStop = nullptr;
void* g_pAptStageHeight = nullptr;
void* g_pAptStageWidth = nullptr;
void* g_pAptClipStackData = nullptr;
void* g_pAptClipStackRaw = nullptr;
void* g_hitMan = nullptr;
void* g_characterResourceManager = nullptr;
void* g_shaderResourceManager = nullptr;
void* g_textureResourceManager = nullptr;
void* g_commanderListHead = nullptr;
void* g_pPSys1 = nullptr;
void* g_pPSys2 = nullptr;
void* g_pPSys3 = nullptr;
void* _pRend = nullptr;
int g_frameCounter = 0;
float g_frameTimeAccum = 0.0f;
float g_frameTimePrev = 0.0f;
float g_prevFrameTime = 0.0f;
float g_prevFrameTimePrev = 0.0f;
int g_polyCount = 0;
int g_prevPolyCount = 0;
int g_batchCount = 0;
int g_drawCallCount = 0;
int g_prevDrawCallCount = 0;
int g_renderActive = 0;
float g_targetFrameRate = 30.0f;
int g_videoMode = 0;
int g_splitScreen = 0;
int g_viewportChanged = 0;
int g_windowMatrixChanged = 0;
int g_ngcFileSystemInitialized = 0;
int g_randomSeed = 0;
int g_useBinaryLoad = 0;
int g_treeTableAdInitialized = 0;
int g_perfEnabled = 0;
int g_perfFrameIdx = 0;
void* g_perfMetricTable = nullptr;
int g_perfNumMetrics = 0;
int g_aptClipStackCurDepth = 0;
int g_aptClipStackMaxDepth = 32;
float g_projectionMatrix[16] = {};
void* g_compareTable = nullptr;
void* g_arrayMembersAssocValues = nullptr;
void* g_arrayMembersWordList = nullptr;
void* g_loadVarsMembersAssocValues = nullptr;
void* g_loadVarsMembersWordList = nullptr;
void* g_soundMembersAssocValues = nullptr;
void* g_soundMembersWordList = nullptr;
void* g_casSceneDefaultMirrorCorners = nullptr;
void* g_casSceneGamecubeMirrorCorners = nullptr;
void* g_casScenePersonalMirrorCorners = nullptr;
void* g_emptyTreeTableAd = nullptr;

// ============================================================================
// Plain C++ functions (no extern "C") matching source declarations
// ============================================================================
void EString_SetToNull(void*) {}
void* EString_MakeCopy(void*, const char*) { return nullptr; }
void EString_Deallocate(void*, void*) {}
void ENodeList_RemoveAll(void*) {}
void ERedBlackTree_RemoveAll(void*) {}
int EBitArray_Get(void*, int) { return 0; }
void EBitArray_Set(void*, int, int) {}
int CTilePt_GetX(void*) { return 0; }
int CTilePt_GetY(void*) { return 0; }
void EGraphics_SetCameraBloom(void) {}
// EGraphics_SetCameraBloom(float x4) defined above (C++ linkage)
void EGraphics_SetMotionBlur(void) {}
// EGraphics_SetMotionBlur(float x4) defined above (C++ linkage)
void EMat4_Identity(void) {}
// EMat4_Identity(void*) defined above (C++ linkage)

struct ENgcRenderStateCache { char data[64]; };
void ENgcRenderStateCache_Restore(ENgcRenderStateCache*) {}
void ENgcRenderStateCache_Save(ENgcRenderStateCache*) {}
void ENgcRenderStateCache_Init(ENgcRenderStateCache*) {}

// ============================================================================
// DolphinSDK extras
// ============================================================================
extern "C" {
int OSEnableInterrupts(void) { return 0; }
unsigned int ARGetBaseAddress(void) { return 0; }
void ARInit(unsigned int*, int) {}
void ARQInit(void) {}
int DVDGetDriveStatus(void) { return 0; }
int DVDInit(void) { return 0; }
void DVDSetAutoFatalMessaging(int) {}
void PADControlMotor(int, unsigned int) {}
void PADRecalibrate(unsigned int) {}
void GXClearGPMetric(void) {}
int GXReadGP0Metric(void) { return 0; }
int GXReadGP1Metric(void) { return 0; }
void GXSetGPMetric(int, int) {}
void C_MTXCopy(float s[3][4], float d[3][4]) { if(s&&d) ::memcpy(d,s,sizeof(float)*12); }
void C_MTX44Copy(float s[4][4], float d[4][4]) { if(s&&d) ::memcpy(d,s,sizeof(float)*16); }
}

// ============================================================================
// Particle system
// ============================================================================
struct psystem {};
void* PEmitterCreate(void*) { return nullptr; }
void PEmitterReg(psystem*, void*) {}
void PEmitterUnReg(psystem*, void*) {}
void PSystemClean(void*) {}
int PSystemIsEmpty(void*) { return 1; }

// ============================================================================
// Parameter types (incomplete - just forward declarations where needed)
// ============================================================================
struct EVec3 { float x,y,z; };
struct BString2 {};
struct cXObject {};
struct EFile {};
struct EAStringC { const char* m_buf; EAStringC(); const char* c_str() const; };

// ============================================================================
// Supporting types (forward declarations + minimal definitions)
// ============================================================================
struct Interaction;   // forward decl for ActionQueue
struct StringBuffer {
    void copy(const StringBuffer&);
    int length() const;
};
struct StringBuffer2 {
    const char* c_str() const;
    int capacity() const;
    void copy(const unsigned short*);
    int length() const;
};
struct ReconBuffer {
    void Recon16(short*, int);
    void Recon32(int*, int);
    void ReconBool(bool*);
    void ReconInt(int*, int);
    void ReconString(StringBuffer&);
};
struct CasSimDescriptionS2C {
    void DoStream(ReconBuffer*, int);
};

// ============================================================================
// Class declarations — each class declared with all needed method signatures
// Methods defined OUT-OF-LINE below to force symbol emission
// ============================================================================

struct ActionQueue {
    int FindVisualInsertGUID(int);
    int IsVisibleAction(Interaction&);
};
struct AptCIH {
    void PreDestroy();
};
struct AptNativeHash {
    AptNativeHash(int);
    ~AptNativeHash();
};
struct AptControl {};
struct AptCharacter {};
struct AptPseudoData_t {
    AptPseudoData_t(AptControl*, int, AptCharacter*);
};
struct AptScriptFunctionBase {
    AptScriptFunctionBase(int, AptScriptFunctionBase*, AptCIH*, bool);
};
struct AptString {
    static void Create(char*);
    static void Destroy();
};
struct AptValue {
    AptValue();
    ~AptValue();
    void toString(EAStringC&);
};
struct AptVar {
    static int Hash(char*);
};
struct AptViewer {
    void NewCallFunction2(const char*, const char*, const char*, int, char**);
};
struct Behavior {
    Behavior();
    int GetGlobNamespaceID();
    int GetNamespaceID();
    int GetSemiGlobalNamespaceID();
};
struct CTilePt {
    short m_x, m_y;
    int GetX() const;
    int GetY() const;
    void Set(int, int, int);
};
struct CameraDirector {
    void CalcCancelCam();
    void CheckCancelled();
    void Interp();
    void ReleaseCurrentCamera();
    void SetFOV(float);
    void UpdateAnimNoteTrack();
    void UpdateCameraPosAndFOV();
};
struct CameraManager {
    static void* s_instance;
    CameraManager();
    static void Initialize();
};
struct Careers {
    virtual ~Careers();
};
struct CareersImpl : public Careers {
    static void operator delete(void*);
};
struct CreateASimBaseState {
    void OwnerReturnFromState(int);
    void Reset();
    void Update(float);
};
struct DOGMA_PoolManager {
    void* Allocate(unsigned int);
};
struct EBitArray {
    void SetGrowBy(int);
};
struct ECheatDMI2 {
    void ButtonPress(int, float);
};
struct EConfig {
    void GetString(char*, char*);
    void SetString(char*, char*);
};
struct EControllerData2 {
    int GetGotEvent(unsigned int) const;
    int GetPressedFirst(unsigned int) const;
    void SetGotEvent(unsigned int, bool);
    void SetPressedFirst(unsigned int, bool);
};
struct EDataHeader {
    EDataHeader();
    ~EDataHeader();
    int Read(void*, unsigned int, unsigned int, unsigned int);
};
struct EDatasetManager2 {
    void ManageDasFile(char*);
};
struct EDebugMenuItem {
    EDebugMenuItem();
};
struct EEngine {
    void ShutdownResourceManagers();
    void ShutdownThreads(bool);
};
struct EFileSystem {
    virtual int Init(int);
};
struct EFixedPool {
    void Init(int, int, void*);
};
struct EFontPage {
    void DeallocateShader();
};
struct EGlobalManager {
    static void Shutdown();
};
struct EGrowPool2 {
    void FreeUnusedSegments();
};
struct EHashTable {
    void ClearTable();
    void SetValues(EHashTable&);
};
struct EInstance {
    EInstance();
    void InsertInOrderTable(void*);
    void RemoveFromLevel();
};
struct EMemoryMeterWin2 {
    void Init();
    void PollMemoryLevels();
};
struct EMemoryWriteStream2 {
    void* operator_bracket(int) const;
};
struct EMirrorPortal {
    void SetNumCorners(int);
};
struct EMsgQueue2 {
    int GetCount();
};
struct ENgcTextureBase {
    ENgcTextureBase(int, int, int);
    virtual ~ENgcTextureBase() {}
};
struct ERCharacter {
    ERCharacter();
    int Load(EFile*);
};
struct ERFont {
    void Deallocate();
    int Load(EFile*);
};
struct ERModel {
    void DelRefSubResources();
};
struct ERMovie {
    ERMovie(EFile*, unsigned int, unsigned int, int);
};
struct ERShader {
    void Deallocate();
    void RemoveFromUpdateList();
    int Load(EFile*);
};
struct ERTexture {
    int Load(EFile*);
};
struct EResource {
    EResource();
    ~EResource();
    void DelRef();
};
struct EResourceManager {
    void AddRef(unsigned int, void*, int);
    void AddRefAsync(unsigned int);
    void Alloc(unsigned int, unsigned int);
};
struct ESim {
    void DeletePlayerCachedModel();
};
struct ESimsCam {
    void CursorNotActive();
    void HandleRotation();
    void HandleZoom();
    void SetActiveNoiseSetting(int);
    void UpdateWin();
};
struct EString {
    int CompareNoCase(const char*) const;
    const char* c_str() const;
};
struct EStringTableNoCase {
    void ClearTable();
};
struct EdithVariableSet {
    int Contains(int);
    void WriteVar(int, short);
    void* operator[](int);
};
namespace Effects {
    struct EffectsManager {
        static void DeleteAll();
        static void* GetSingleton();
    };
}
struct Emitter {
    static void Destroy();
    static void* Get();
    void SetSortPos(EVec3&);
};
struct EyeToyClient {
    void* GetRepTexture(int);
    int IsSessionEyeToyDisconnected();
    void RestoreDefaults();
    void SetBrightness(float);
    void SetSaturation(float);
};
struct FPHeap {
    void Free(void*);
};
struct FadeSquare {
    void StopDraw();
};
struct FastAllocPool {
    void* Alloc();
    void Free(void*);
    ~FastAllocPool();
};
struct FlashPiMenu {
    static void CleanUpAllMenus();
};
struct FrameEffect {
    int IsActivateComplete(float) const;
    int IsDeactivateComplete(float) const;
    int IsEffectRamping() const;
    int IsEffectRunning() const;
};
struct GameTime {
    static int CountDaysInMonth(int, int);
};
struct IconGroupImpl {
    IconGroupImpl();
    ~IconGroupImpl();
    int GetSpriteID(int);
    void Init(int);
};
struct Interaction {
    void* GetIconObject() const;
    const char* GetName() const;
    void SetIconObject(cXObject*);
    void SetName(BString2&);
    void SetUniqueID();
};
struct MUStateMachine {
    int MUPollForResult(int);
    void SetupQuitToMainMenu();
};
struct MUWrapper {
    void Reset();
    void SetDisplayOkType(int);
    void SetInfoType(int);
    void SetQueryType(int);
};
struct MemFile {
    int ValidFile();
};
struct MorphUtilities {
    static void ApplyMorph(int, float);
    static void ApplyMorphHead(float);
};
struct Neighbor {
    void InitDefaultValues();
    ~Neighbor();
};
struct ObjectTypeAttrBlock {
    void Clear();
};
struct PlumbBob {
    void SetModel(unsigned int);
};
struct REffectsSequencer {
    void Deallocate();
};
struct SAnimator2 {
    void SetIsRaining(bool);
};
struct SeqResFile {
    void ClearOpenSpecs();
};
struct SimModel {
    void DeallocateMorphResources();
    void DeallocateAllSkinTextures();
    void DetachSimDescription();
    void SetAllModels();
    void SetSimDescription(CasSimDescriptionS2C*);
};
struct SimsCameraParameters {
    void Validate();
};
struct SimsMemCardWrap {
    void FormatCard(int);
    void IsCardFormatted(int, bool&);
    void IsCardInSlot(int, bool&);
    void IsWrongDevice(int, bool&);
    void LoadGame(int, int);
    void SaveGame(int, bool, bool, int);
};
struct StateMachineState {
    void OwnerCallState(int, float);
};
struct StdResFile {
    StdResFile();
    int Open(StringBuffer&);
};
struct TileWalls {
    int HasWallNotFence(int) const;
};
struct TrackDataReader {
    void Trace() const;
};
class cTrack;
struct cSoundCache {
    int IsInMemory(cTrack*) const;
};
struct cSoundModeManager {
    void FadeOutMusic(unsigned int);
    void FadeOutSFX(unsigned int);
};
struct cTrack {
    int GetControlGroup();
};

// ============================================================================
// Out-of-line method definitions (force symbol emission)
// ============================================================================

// --- EAStringC ---
EAStringC::EAStringC() : m_buf("") {}
const char* EAStringC::c_str() const { return m_buf; }

// --- StringBuffer ---
void StringBuffer::copy(const StringBuffer&) {}
int StringBuffer::length() const { return 0; }

// --- StringBuffer2 ---
const char* StringBuffer2::c_str() const { return ""; }
int StringBuffer2::capacity() const { return 0; }
void StringBuffer2::copy(const unsigned short*) {}
int StringBuffer2::length() const { return 0; }

// --- ActionQueue ---
int ActionQueue::FindVisualInsertGUID(int) { return 0; }
int ActionQueue::IsVisibleAction(Interaction&) { return 0; }

// --- AptCIH ---
void AptCIH::PreDestroy() {}

// --- AptNativeHash ---
AptNativeHash::AptNativeHash(int) {}
AptNativeHash::~AptNativeHash() {}

// --- AptPseudoData_t ---
AptPseudoData_t::AptPseudoData_t(AptControl*, int, AptCharacter*) {}

// --- AptScriptFunctionBase ---
AptScriptFunctionBase::AptScriptFunctionBase(int, AptScriptFunctionBase*, AptCIH*, bool) {}

// --- AptString ---
void AptString::Create(char*) {}
void AptString::Destroy() {}

// --- AptValue ---
AptValue::AptValue() {}
AptValue::~AptValue() {}
void AptValue::toString(EAStringC&) {}

// --- AptVar ---
int AptVar::Hash(char*) { return 0; }

// --- AptViewer ---
void AptViewer::NewCallFunction2(const char*, const char*, const char*, int, char**) {}

// --- Behavior ---
Behavior::Behavior() {}
int Behavior::GetGlobNamespaceID() { return 0; }
int Behavior::GetNamespaceID() { return 0; }
int Behavior::GetSemiGlobalNamespaceID() { return 0; }

// --- CTilePt ---
int CTilePt::GetX() const { return m_x; }
int CTilePt::GetY() const { return m_y; }
void CTilePt::Set(int x, int y, int) { m_x=(short)x; m_y=(short)y; }

// --- CameraDirector ---
void CameraDirector::CalcCancelCam() {}
void CameraDirector::CheckCancelled() {}
void CameraDirector::Interp() {}
void CameraDirector::ReleaseCurrentCamera() {}
void CameraDirector::SetFOV(float) {}
void CameraDirector::UpdateAnimNoteTrack() {}
void CameraDirector::UpdateCameraPosAndFOV() {}

// --- CameraManager ---
void* CameraManager::s_instance = nullptr;
CameraManager::CameraManager() {}
void CameraManager::Initialize() {}

// --- Careers ---
Careers::~Careers() {}

// --- CareersImpl ---
void CareersImpl::operator delete(void* p) { free(p); }

// --- ReconBuffer ---
void ReconBuffer::Recon16(short*, int) {}
void ReconBuffer::Recon32(int*, int) {}
void ReconBuffer::ReconBool(bool*) {}
void ReconBuffer::ReconInt(int*, int) {}
void ReconBuffer::ReconString(StringBuffer&) {}

// --- CasSimDescriptionS2C ---
void CasSimDescriptionS2C::DoStream(ReconBuffer*, int) {}

// --- CreateASimBaseState ---
void CreateASimBaseState::OwnerReturnFromState(int) {}
void CreateASimBaseState::Reset() {}
void CreateASimBaseState::Update(float) {}

// --- DOGMA_PoolManager ---
void* DOGMA_PoolManager::Allocate(unsigned int) { return nullptr; }

// --- EBitArray ---
void EBitArray::SetGrowBy(int) {}

// --- ECheatDMI2 ---
void ECheatDMI2::ButtonPress(int, float) {}

// --- EConfig ---
void EConfig::GetString(char*, char* v) { if(v) v[0]=0; }
void EConfig::SetString(char*, char*) {}

// --- EControllerData2 ---
int EControllerData2::GetGotEvent(unsigned int) const { return 0; }
int EControllerData2::GetPressedFirst(unsigned int) const { return 0; }
void EControllerData2::SetGotEvent(unsigned int, bool) {}
void EControllerData2::SetPressedFirst(unsigned int, bool) {}

// --- EDataHeader ---
EDataHeader::EDataHeader() {}
EDataHeader::~EDataHeader() {}
int EDataHeader::Read(void*, unsigned int, unsigned int, unsigned int) { return 0; }

// --- EDatasetManager2 ---
void EDatasetManager2::ManageDasFile(char*) {}

// --- EDebugMenuItem ---
EDebugMenuItem::EDebugMenuItem() {}

// --- EEngine ---
void EEngine::ShutdownResourceManagers() {}
void EEngine::ShutdownThreads(bool) {}

// --- EFileSystem_stub ---
// EFileSystem already defined in headers — just provide the implementation
int EFileSystem::Init(int) { return 0; }

// --- EFixedPool ---
void EFixedPool::Init(int, int, void*) {}

// --- EFontPage ---
void EFontPage::DeallocateShader() {}

// --- EGlobalManager ---
void EGlobalManager::Shutdown() {}

// --- EGrowPool2 ---
void EGrowPool2::FreeUnusedSegments() {}

// --- EHashTable ---
void EHashTable::ClearTable() {}
void EHashTable::SetValues(EHashTable&) {}

// --- EInstance ---
EInstance::EInstance() {}
void EInstance::InsertInOrderTable(void*) {}
void EInstance::RemoveFromLevel() {}

// --- EMemoryMeterWin2 ---
void EMemoryMeterWin2::Init() {}
void EMemoryMeterWin2::PollMemoryLevels() {}

// --- EMemoryWriteStream2 ---
void* EMemoryWriteStream2::operator_bracket(int) const { return nullptr; }

// --- EMirrorPortal ---
void EMirrorPortal::SetNumCorners(int) {}

// --- EMsgQueue2 ---
int EMsgQueue2::GetCount() { return 0; }

// --- ENgcTextureBase ---
ENgcTextureBase::ENgcTextureBase(int, int, int) {}

// --- ERCharacter ---
ERCharacter::ERCharacter() {}
int ERCharacter::Load(EFile*) { return 0; }

// --- ERFont ---
void ERFont::Deallocate() {}
int ERFont::Load(EFile*) { return 0; }

// --- ERModel ---
void ERModel::DelRefSubResources() {}

// --- ERMovie ---
ERMovie::ERMovie(EFile*, unsigned int, unsigned int, int) {}

// --- ERShader ---
void ERShader::Deallocate() {}
void ERShader::RemoveFromUpdateList() {}
int ERShader::Load(EFile*) { return 0; }

// --- ERTexture ---
int ERTexture::Load(EFile*) { return 0; }

// --- EResource ---
EResource::EResource() {}
EResource::~EResource() {}
void EResource::DelRef() {}

// --- EResourceManager ---
void EResourceManager::AddRef(unsigned int, void*, int) {}
void EResourceManager::AddRefAsync(unsigned int) {}
void EResourceManager::Alloc(unsigned int, unsigned int) {}

// --- ESim ---
void ESim::DeletePlayerCachedModel() {}

// --- ESimsCam ---
void ESimsCam::CursorNotActive() {}
void ESimsCam::HandleRotation() {}
void ESimsCam::HandleZoom() {}
void ESimsCam::SetActiveNoiseSetting(int) {}
void ESimsCam::UpdateWin() {}

// --- EString ---
int EString::CompareNoCase(const char*) const { return 0; }
const char* EString::c_str() const { return ""; }

// --- EStringTableNoCase ---
void EStringTableNoCase::ClearTable() {}

// --- EdithVariableSet ---
int EdithVariableSet::Contains(int) { return 0; }
void EdithVariableSet::WriteVar(int, short) {}
void* EdithVariableSet::operator[](int) { return nullptr; }

// --- Effects::EffectsManager ---
void Effects::EffectsManager::DeleteAll() {}
void* Effects::EffectsManager::GetSingleton() { return nullptr; }

// --- Emitter ---
void Emitter::Destroy() {}
void* Emitter::Get() { return nullptr; }
void Emitter::SetSortPos(EVec3&) {}

// --- EyeToyClient ---
void* EyeToyClient::GetRepTexture(int) { return nullptr; }
int EyeToyClient::IsSessionEyeToyDisconnected() { return 1; }
void EyeToyClient::RestoreDefaults() {}
void EyeToyClient::SetBrightness(float) {}
void EyeToyClient::SetSaturation(float) {}

// --- FPHeap ---
void FPHeap::Free(void*) {}

// --- FadeSquare ---
void FadeSquare::StopDraw() {}

// --- FastAllocPool ---
void* FastAllocPool::Alloc() { return nullptr; }
void FastAllocPool::Free(void*) {}
FastAllocPool::~FastAllocPool() {}

// --- FlashPiMenu ---
void FlashPiMenu::CleanUpAllMenus() {}

// --- FrameEffect ---
int FrameEffect::IsActivateComplete(float) const { return 1; }
int FrameEffect::IsDeactivateComplete(float) const { return 1; }
int FrameEffect::IsEffectRamping() const { return 0; }
int FrameEffect::IsEffectRunning() const { return 0; }

// --- GameTime ---
int GameTime::CountDaysInMonth(int, int) { return 30; }

// --- GetShaderForObject ---
int GetShaderForObject(cXObject*, EResource**) { return 0; }

// --- IconGroupImpl ---
IconGroupImpl::IconGroupImpl() {}
IconGroupImpl::~IconGroupImpl() {}
int IconGroupImpl::GetSpriteID(int) { return 0; }
void IconGroupImpl::Init(int) {}

// --- Interaction ---
void* Interaction::GetIconObject() const { return nullptr; }
const char* Interaction::GetName() const { return ""; }
void Interaction::SetIconObject(cXObject*) {}
void Interaction::SetName(BString2&) {}
void Interaction::SetUniqueID() {}

// --- MUStateMachine ---
int MUStateMachine::MUPollForResult(int) { return 0; }
void MUStateMachine::SetupQuitToMainMenu() {}

// --- MUWrapper ---
void MUWrapper::Reset() {}
void MUWrapper::SetDisplayOkType(int) {}
void MUWrapper::SetInfoType(int) {}
void MUWrapper::SetQueryType(int) {}

// --- MemFile ---
int MemFile::ValidFile() { return 0; }

// --- MorphUtilities ---
void MorphUtilities::ApplyMorph(int, float) {}
void MorphUtilities::ApplyMorphHead(float) {}

// --- Neighbor ---
void Neighbor::InitDefaultValues() {}
Neighbor::~Neighbor() {}

// --- ObjectTypeAttrBlock ---
void ObjectTypeAttrBlock::Clear() {}

// --- PlumbBob ---
void PlumbBob::SetModel(unsigned int) {}

// --- REffectsSequencer ---
void REffectsSequencer::Deallocate() {}

// --- SAnimator2 ---
void SAnimator2::SetIsRaining(bool) {}

// --- SeqResFile ---
void SeqResFile::ClearOpenSpecs() {}

// --- SimModel ---
void SimModel::DeallocateMorphResources() {}
void SimModel::DeallocateAllSkinTextures() {}
void SimModel::DetachSimDescription() {}
void SimModel::SetAllModels() {}
void SimModel::SetSimDescription(CasSimDescriptionS2C*) {}

// --- SimsCameraParameters ---
void SimsCameraParameters::Validate() {}

// --- SimsMemCardWrap ---
void SimsMemCardWrap::FormatCard(int) {}
void SimsMemCardWrap::IsCardFormatted(int, bool&) {}
void SimsMemCardWrap::IsCardInSlot(int, bool&) {}
void SimsMemCardWrap::IsWrongDevice(int, bool&) {}
void SimsMemCardWrap::LoadGame(int, int) {}
void SimsMemCardWrap::SaveGame(int, bool, bool, int) {}

// --- StateMachineState ---
void StateMachineState::OwnerCallState(int, float) {}

// --- StdResFile ---
StdResFile::StdResFile() {}
int StdResFile::Open(StringBuffer&) { return 0; }

// --- TileWalls ---
int TileWalls::HasWallNotFence(int) const { return 0; }

// --- TrackDataReader ---
void TrackDataReader::Trace() const {}

// --- cSoundCache ---
int cSoundCache::IsInMemory(cTrack*) const { return 0; }

// --- cSoundModeManager ---
void cSoundModeManager::FadeOutMusic(unsigned int) {}
void cSoundModeManager::FadeOutSFX(unsigned int) {}

// --- cTrack ---
int cTrack::GetControlGroup() { return 0; }

// ============================================================================
// FindRes template stubs
// ============================================================================
struct CatalogData {};
struct TreeTableEntry_s {};
template<typename T>
T* FindRes(T*, T*, int) { return nullptr; }
template void* FindRes<void>(void*, void*, int);
template CatalogData* FindRes<CatalogData>(CatalogData*, CatalogData*, int);
template TreeTableEntry_s* FindRes<TreeTableEntry_s>(TreeTableEntry_s*, TreeTableEntry_s*, int);

// ============================================================================
// TArray template stubs
// Inline TArray definition to avoid conflicting with tarray_types.h
// ============================================================================
struct TArrayDefaultAllocator {};
struct TArrayERAnimAllocator {};
struct TArrayERCharacterAllocator {};
struct TArrayERSoundEventAllocator {};

template<typename T, typename A>
class TArray {
public:
    T* m_data;
    int m_count;
    int m_capacity;
    TArray() : m_data(nullptr), m_count(0), m_capacity(0) {}
    TArray(TArray&) : m_data(nullptr), m_count(0), m_capacity(0) {}
    ~TArray();
    void Init();
    void Destruct(T*, int);
    void Construct(T*, int);
    void Copy(T*, T*, int);
    void CopyReverse(T*, T*, int) {}
    void SetSize(int, int) {}
    void Deallocate();
    void Add(T&) {}
    void Insert(T*, int, int) {}
    void operator=(TArray&) {}
    void DeleteAll() {}
    void FreeAll() {}
    void SafeDeleteAll() {}
};

template<typename T, typename A> TArray<T,A>::~TArray() { free(m_data); }
template<typename T, typename A> void TArray<T,A>::Init() { m_data=nullptr; m_count=0; m_capacity=0; }
template<typename T, typename A> void TArray<T,A>::Destruct(T*, int) {}
template<typename T, typename A> void TArray<T,A>::Construct(T*, int) {}
template<typename T, typename A> void TArray<T,A>::Copy(T*, T*, int) {}
template<typename T, typename A> void TArray<T,A>::Deallocate() { free(m_data); m_data=nullptr; m_count=0; m_capacity=0; }

struct EILight {};
struct EFontPage_t {};
struct SndEvtHitPatch { char data[8]; };
// EVec3 already defined above

template class TArray<float, TArrayERAnimAllocator>;
template class TArray<int, TArrayDefaultAllocator>;
template class TArray<int, TArrayERCharacterAllocator>;
template class TArray<unsigned int, TArrayDefaultAllocator>;
template class TArray<unsigned char*, TArrayDefaultAllocator>;
template class TArray<EFontPage_t*, TArrayDefaultAllocator>;
template class TArray<EILight*, TArrayDefaultAllocator>;
template class TArray<EVec3, TArrayDefaultAllocator>;
template class TArray<SndEvtHitPatch, TArrayERSoundEventAllocator>;

// Note: The TArray<EFontPage*, TArrayDefaultAllocator> linker symbol uses EFontPage (not EFontPage_t).
// Define separate explicit instantiation:
template class TArray<EFontPage*, TArrayDefaultAllocator>;

// ============================================================================
// InterpolateLinear_float — used by effects_system_sweep.cpp in anonymous namespace
// ============================================================================
namespace {
    float InterpolateLinear_float(float start, float end, float startTime, float endTime, float t) {
        if (endTime <= startTime) return end;
        float pct = (t - startTime) / (endTime - startTime);
        if (pct < 0.0f) pct = 0.0f;
        if (pct > 1.0f) pct = 1.0f;
        return start + (end - start) * pct;
    }
}

// CareersImpl::operator delete — already defined earlier in this file at line 339

// extern "C" versions are in c_linkage_stubs.c

#endif // SIMS2_PLATFORM_PC
