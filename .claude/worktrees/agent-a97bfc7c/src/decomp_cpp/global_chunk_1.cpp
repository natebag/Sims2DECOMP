// global_chunk_1.cpp - global.cpp functions 1-494 (lines 214-52003)
// Free functions, anonymous namespace, static initializers
// Converted from PPC inline asm to portable C++
// 494 functions, ~174,508 bytes of original code
//
// Source: u2_ngc_release_dvd.elf disassembly + u2_ngc_release.map symbols

#include "types.h"

// ============================================================================
// External declarations
// ============================================================================

extern "C" {
    void* memcpy(void* dst, const void* src, unsigned int n);
    void* memset(void* s, int c, unsigned int n);
    void* memchr(const void* s, int c, unsigned int n);
    int   memcmp(const void* s1, const void* s2, unsigned int n);
    void* memmove(void* dst, const void* src, unsigned int n);
    int   strlen(const char* s);
    char* strcpy(char* dst, const char* src);
    char* strncpy(char* dst, const char* src, unsigned int n);
    char* strcat(char* dst, const char* src);
    int   strcmp(const char* a, const char* b);
    int   strncmp(const char* a, const char* b, unsigned int n);
    int   strcasecmp(const char* a, const char* b);
    int   strncasecmp(const char* a, const char* b, unsigned int n);
    char* strchr(const char* s, int c);
    char* strrchr(const char* s, int c);
    char* strstr(const char* haystack, const char* needle);
    float sqrtf(float x);
    float sinf(float x);
    float cosf(float x);
    float tanf(float x);
    float acosf(float x);
    float atan2f(float y, float x);
    float atanf(float x);
    float fmodf(float x, float y);
    float floorf(float x);
    float ceilf(float x);
    float copysignf(float x, float y);
    float scalbnf(float x, int n);
    int   fprintf(void* stream, const char* fmt, ...);
    int   vfprintf(void* stream, const char* fmt, void* ap);
    int   sprintf(char* buf, const char* fmt, ...);
    void* malloc(unsigned int size);
    void  free(void* ptr);
    int   wcscmp(const unsigned short* s1, const unsigned short* s2);
    unsigned short* wcsncpy(unsigned short* dst, const unsigned short* src, unsigned int n);
    unsigned short* wcsstr(const unsigned short* s1, const unsigned short* s2);
    unsigned short* wcscat(unsigned short* dst, const unsigned short* src);
    int   qsort(void* base, unsigned int nmemb, unsigned int size, int (*compar)(const void*, const void*));
}

// Engine externals
class EAHeap;
extern EAHeap* MainHeap();
extern EAHeap* AptHeap();
class FPHeap { public: void Free(void*); };

extern void* operator_new(unsigned int size);
extern void  operator_delete(void* ptr);

extern float AtoF(const char*);
extern int   AtoI(const char*);
extern int Sprintf(char*, const char*, ...);

// Forward declarations for all referenced types
class AptAllocateStringParameters;
class AptAuxFontList;
class AptAuxLayerInfo;
class AptAuxUnit;
class AptCIH;
class AptCXForm;
class AptFile;
class AptInitParmsT;
class AptRenderingContext;
class AptSavedInputRecord;
class AptValue;
class AptViewer;
class AnimRef;
class AnimRefTable;
class AnimTable;
class AnimateNewParam;
class BString;
class BString2;
class BehaviorConstants;
class CDirtyXmlNode;
class CTilePt;
class CASTarget;
class CasGenetics;
class CasCostumes;
class CatalogData;
class EAnimNote;
class EBound3;
class EClock;
class EFile;
class EFixedString;
class EFloorStripInfo;
class EFloorVertexSpan;
class EInstance;
class ELightGrid;
class ELights;
class EMat4;
class ENCamera;
class EOrderTableData;
class EQuat;
class ERC;
class ERFont;
class ERQuickdata;
class ERShader;
class EResourceManager;
class ERoomWall;
class ESMSStrip;
class EShader;
class ESim;
class ESimsCam;
class EString {
public:
    int CompareNoCase(const char*) const;
    const char* c_str() const;
    EString& operator+=(const char*);
    void MakeCopy(const char*);
    void Deallocate(const char*);
};
class ESubModelShader;
class ExpenseReport;
class Family;
class FlashBigFile;
class FloorTile;
class FoodResult;
class FrameEffect;
class FrameEffectsBloomDataElement;
class FrameEffectsDepthOfFieldDataElement;
class FrameEffectsManager;
class FrameEffectsMotionBlurDataElement;
class HouseImpl;
class IRect;
class ISimInstance;
class INVTarget;
class Ingredient;
class IngredientType;
class Interaction;
class InteractionList;
class Intersection;
class LevelLighting;
class LevelLightingEntry;
class Neighbor;
class NeighborhoodImpl;
class NewLevelLightingLevel;
class NghResFile;
class NghResFileWriteInfo;
class ObjSelector;
class ObjectDefinition;
class ObjectModuleImpl;
class ObjectFolderImpl;
class OptionsRecon;
class PenaltyRect;
class PersDataPair;
class ReconBuffer;
class RelMatrix;
class RoutingSlot;
class SeqResFile;
class SkyLights;
class StackElem;
class StateMachineManager;
class StringBuffer;
class StringBuffer2;
class TextBlock;
struct TileWallsSegment {};
class TileWalls {
public:
    bool HasWall(void) const;
    bool HasWallNotFence(int segment) const;
    TileWallsSegment First(void) const;
    TileWallsSegment Next(TileWallsSegment) const;
    int GetStyle(TileWallsSegment) const;
    TileWalls& operator=(const TileWalls&);
    ~TileWalls(void);
};
class TreeTable;
class TreeTableEntry;
class UIDialog;
class UIObjectBase;
class WStringSet;
class XRoute;
class cSimulator;
class cXObject;
class cXPerson;
class cXPersonImpl;
class iResFile;
class levelraininfo;
class particle;
class pemitter;
class pemitterinfo;
class tm;

struct AptAnalogStickInfo;
struct AptInputController;
struct AptInputState;
struct AptMaskRenderOperation {};
struct DiagonalSideSelector {};
struct EVec2 { float x, y; };
struct EVec3 { float x, y, z; };
struct EVec4 { float x, y, z, w; };
struct FTilePt {};
struct FTileRect;
struct IPoint {};
struct PVector4;
struct ReachAnimIdx {};
struct RelationsCmp;
struct RotationAxis {};
struct StdAnimIdx {};
struct WallStyle {};
struct eInvFullDialogType {};
struct ScoredInteraction;
struct SndInfo;
struct OSAlarm;
struct OSContext;

template <typename T> class AptSharedPtr {};
template <typename T> class VECTOR;
template <typename T, typename A> class vector;
template <typename T, typename A> class TArray;
template <typename T> class TNodeList;
template <typename T> class allocator;
template <int N> class StackString;
template <int N> class StackString2;

namespace anim { struct PropKind; }
namespace InteractorModule { struct InteractorType; }
namespace Room { struct Sides; }
namespace Memory { struct HandleNode; }
namespace PCTTarget { struct PCTTabInfo; struct Recipe; struct cCellInfo; }
namespace RCPTarget { struct Recipe; }

// ============================================================================
// Function implementations
// ============================================================================

// 0x800034C0 (280 bytes)
// {anonymous}::OverrideMotionBlurSettingsFromTokens(FrameEffectsMotionBlurDataElement *, EString *, int)
void OverrideMotionBlurSettingsFromTokens(FrameEffectsMotionBlurDataElement* data, EString* tokens, int count) {
    // Parse key-value token pairs and apply to motion blur settings
    for (int i = 0; i < count - 1; i += 2) {
        if (tokens[i].CompareNoCase("FrameAlpha") == 0)
            *(float*)((char*)data + 0) = AtoF(tokens[i+1].c_str());
        else if (tokens[i].CompareNoCase("ObjectAlpha") == 0)
            *(float*)((char*)data + 4) = AtoF(tokens[i+1].c_str());
        else if (tokens[i].CompareNoCase("Enable") == 0)
            *(int*)((char*)data + 8) = AtoI(tokens[i+1].c_str());
        else if (tokens[i].CompareNoCase("Spread") == 0)
            *(float*)((char*)data + 12) = AtoF(tokens[i+1].c_str());
        else if (tokens[i].CompareNoCase("MaxDist") == 0)
            *(float*)((char*)data + 16) = AtoF(tokens[i+1].c_str());
    }
}

// 0x800035D8 (600 bytes)
// {anonymous}::OverrideBloomSettingsFromTokens(FrameEffectsBloomDataElement *, EString *, int)
void OverrideBloomSettingsFromTokens(FrameEffectsBloomDataElement* data, EString* tokens, int count) {
    // Parse key-value token pairs and apply to bloom settings
    // 14 float fields at offsets 0-48
    for (int i = 0; i < count - 1; i += 2) {
        // Matches against field names like "Intensity", "Threshold", etc.
        // Sets corresponding float in data struct
        // TODO: 600 bytes - 14 field comparisons
    }
}

// 0x80003830 (360 bytes)
// {anonymous}::OverrideDOFSettingsFromTokens(FrameEffectsDepthOfFieldDataElement *, EString *, int)
void OverrideDOFSettingsFromTokens(FrameEffectsDepthOfFieldDataElement* data, EString* tokens, int count) {
    // Parse key-value token pairs and apply to DOF settings
    // Fields: Enable(int), focal params(float), distances(float)
    for (int i = 0; i < count - 1; i += 2) {
        // TODO: 360 bytes - 7 field comparisons
    }
}

// 0x80003998 (680 bytes)
// HandleBloomEvent(EAnimNote &, FrameEffectsManager *)
void HandleBloomEvent(EAnimNote &, FrameEffectsManager *) {
    // Animation event handler
    // Gets quickdata table, looks up effect object,
    // parses token string, applies settings
    // Calls: ERQuickdata::getTable(char *)
    // Calls: FrameEffectsManager::BloomObject(void)
    // Calls: EString::CompareNoCase(char *) const
    // Calls: FrameEffect::Enable(bool)
    // Calls: TArray<EString, TArrayDefaultAllocator>::TArray(void)
    // TODO: 680 bytes - complex event processing
}

// 0x80003C40 (416 bytes)
// HandleMotionBlurEvent(EAnimNote &, FrameEffectsManager *)
void HandleMotionBlurEvent(EAnimNote &, FrameEffectsManager *) {
    // Animation event handler
    // Gets quickdata table, looks up effect object,
    // parses token string, applies settings
    // Calls: ERQuickdata::getTable(char *)
    // Calls: FrameEffectsManager::MotionBlurObject(void)
    // Calls: EString::CompareNoCase(char *) const
    // Calls: FrameEffect::Enable(bool)
    // Calls: TArray<EString, TArrayDefaultAllocator>::TArray(void)
    // TODO: 416 bytes - complex event processing
}

// 0x80003DE0 (508 bytes)
// HandleDepthOfFieldEvent(EAnimNote &, FrameEffectsManager *)
void HandleDepthOfFieldEvent(EAnimNote &, FrameEffectsManager *) {
    // Animation event handler
    // Gets quickdata table, looks up effect object,
    // parses token string, applies settings
    // Calls: ERQuickdata::getTable(char *)
    // Calls: FrameEffectsManager::DepthOfFieldObject(void)
    // Calls: EString::CompareNoCase(char *) const
    // Calls: FrameEffect::Enable(bool)
    // Calls: TArray<EString, TArrayDefaultAllocator>::TArray(void)
    // TODO: 508 bytes - complex event processing
}

// 0x8000574C (188 bytes)
// DrawGame(ERC *)
void DrawGame(ERC *) {
    // Calls: StateMachineManager::DrawMachines(ERC *)
    // Calls: AptViewer::Draw(ERC *)
    // TODO: 188 bytes, 2 call instructions
}

// 0x8000602C (720 bytes)
// ENgcGetDVDErrorString(int)
void ENgcGetDVDErrorString(int) {
    // Calls: NGCGetLanguage(void)
    // TODO: 720 bytes, 1 call instructions
}

// 0x80006404 (364 bytes)
// _loadFileSize(char *, int *)
void _loadFileSize(char *, int *) {
    // Calls: EString::MakeCopy(char *)
    // Calls: EString::operator+=(char *)
    // Calls: EFileSystem::Create(EFile *&, char *, char *, EFile::DeviceType, EFile::AccessMode, unsigned int)
    // Calls: MainHeap(void)
    // Calls: EAHeap::Malloc(unsigned int, int)
    // Calls: EFileSystem::Destroy(EFile *&)
    // Calls: EString::Deallocate(char *)
    // TODO: 364 bytes, 8 call instructions
}

// 0x800065A8 (72 bytes)
// SimsAptFree(void *)
void SimsAptFree(void* ptr) {
    if (ptr == 0) return;
    FPHeap* heap = (FPHeap*)AptHeap();
    if (*(int*)heap == 0) return;
    heap = (FPHeap*)AptHeap();
    heap->Free(ptr);
}

// 0x800065F4 (388 bytes)
// setExternVariable(char *, char *)
void setExternVariable(char *, char *) {
    // Calls: strcpy
    // Calls: strcat
    // Calls: strcmp
    // Calls: AptViewer::AllowControllerReading(bool)
    // Calls: AptFlushInputQueue(void)
    // TODO: 388 bytes, 12 call instructions
}

// 0x80006800 (808 bytes)
// getExternVariable(char *)
void getExternVariable(char *) {
    // Calls: strcmp
    // Calls: Sprintf(char *, char *,...)
    // Calls: AptValueFactory::CreateString(char *)
    // Calls: SimsAptFree(void *)
    // TODO: 808 bytes, 21 call instructions
}

// 0x80006B28 (76 bytes)
// debugPrintStub(char *,...)
void debugPrintStub(char* fmt, ...) {
    // Stub - does nothing in release build
    // Varargs are saved to stack and discarded
}

// 0x80006B7C (540 bytes)
// _loadGeometry(char *, AptAuxLayerInfo *)
void _loadGeometry(char *, AptAuxLayerInfo *) {
    // Calls: strcpy
    // Calls: strcat
    // Calls: FlashBigFile::GetGeometry(char *)
    // Calls: vector<AptAuxIDToChar, allocator<AptAuxIDToChar> >::_M_fill_insert(AptAuxIDToChar *, unsigned int, AptAuxIDToChar &)
    // TODO: 540 bytes, 4 call instructions
}

// 0x80006D98 (976 bytes)
// loadTexture(void *, int)
void loadTexture(void *, int) {
    // Calls: Sprintf(char *, char *,...)
    // Calls: FlashBigFile::GetTexture(char *, int &, int &)
    // TODO: 976 bytes, 2 call instructions
}

// 0x80007168 (144 bytes)
// freeTexture(void *)
void freeTexture(void *) {
    // Calls: EResource::DelRef(void)
    // TODO: 144 bytes, 1 call instructions
}

// 0x800071F8 (360 bytes)
// bindTexture(void *, int, void *)
void bindTexture(void *, int, void *) {
    // Calls: vector<AptAuxIDToChar, allocator<AptAuxIDToChar> >::_M_fill_insert(AptAuxIDToChar *, unsigned int, AptAuxIDToChar &)
    // TODO: 360 bytes, 1 call instructions
}

// 0x80007360 (88 bytes)
// setColourTransform(AptCXForm *)
void setColourTransform(AptCXForm *) {
    // TODO: 88 bytes, 0 call instructions
}

// 0x80007450 (168 bytes)
// drawRenderingUnit(void *, AptMaskRenderOperation)
void drawRenderingUnit(void *, AptMaskRenderOperation) {
    // Calls: DrawTriSolid(AptAuxUnit *, AptMaskRenderOperation)
    // Calls: DrawTriTiledClipped(AptAuxUnit *, AptMaskRenderOperation)
    // Calls: DrawLineSolid(AptAuxUnit *, AptMaskRenderOperation)
    // TODO: 168 bytes, 3 call instructions
}

// 0x800074F8 (3592 bytes)
// customControlRender(char *, char *, void *, char *)
void customControlRender(char *, char *, void *, char *) {
    // Calls: strlen
    // Calls: strcmp
    // Calls: __builtin_new
    // Calls: UI2D::UI2D(void)
    // Calls: UI2D::GetShader(char *)
    // Calls: UI3D::UI3D(void)
    // ... and 8 more
    // TODO: 3592 bytes, 20 call instructions
}

// 0x80008300 (1176 bytes)
// allocateString(AptAllocateStringParameters *)
void allocateString(AptAllocateStringParameters *) {
    // Calls: strlen
    // Calls: strcpy
    // Calls: MainHeap(void)
    // Calls: EAHeap::Malloc(unsigned int, int)
    // Calls: strncmp
    // Calls: UIQDTarget::GetQuickdataText(char *)
    // ... and 11 more
    // TODO: 1176 bytes, 28 call instructions
}

// 0x80008798 (644 bytes)
// Debug_DrawTextBox(ERC *, EVec2 &, EVec2 &, int)
void Debug_DrawTextBox(ERC *, EVec2 &, EVec2 &, int) {
    // TODO: 644 bytes, 0 call instructions
}

// 0x80008A1C (2384 bytes)
// drawStringEor(void *, AptMaskRenderOperation)
void drawStringEor(void *, AptMaskRenderOperation) {
    // Calls: strlen
    // Calls: Debug_DrawTextBox(ERC *, EVec2 &, EVec2 &, int)
    // Calls: ERFont::Select(ERC *)
    // Calls: EMat4::operator=(EMat4 &)
    // Calls: ERFont::SetSize(float, float, bool)
    // Calls: AptParagraph::Draw(ERC *, EMat4 *, EVec4 *, EVec4 *)
    // ... and 6 more
    // TODO: 2384 bytes, 14 call instructions
}

// 0x8000936C (124 bytes)
// deallocateString(void *, unsigned int)
void deallocateString(void *, unsigned int) {
    // TODO: 124 bytes, 0 call instructions
}

// 0x80009424 (368 bytes)
// LoadThreadProc(void *)
void LoadThreadProc(void *) {
    // Calls: strlen
    // Calls: strcpy
    // Calls: EResourceManager::AddRef(char *, EFile *, int)
    // Calls: ERFlash::GetFlashBigData(void)
    // Calls: EResource::DelRef(void)
    // Calls: strcat
    // Calls: FlashBigFile::GetDataSection(char *)
    // Calls: _loadGeometry(char *, AptAuxLayerInfo *)
    // TODO: 368 bytes, 14 call instructions
}

// 0x80009594 (292 bytes)
// AptAuxPCEorGL_LoadAnimation(char *, AptSharedPtr<AptFile>)
void AptAuxPCEorGL_LoadAnimation(char *, AptSharedPtr<AptFile>) {
    // Calls: AptFlushInputQueue(void)
    // Calls: MainHeap(void)
    // Calls: EAHeap::Malloc(unsigned int, int)
    // Calls: memset
    // Calls: strcpy
    // Calls: AptSharedPtrDecRef(AptFile *)
    // ... and 5 more
    // TODO: 292 bytes, 13 call instructions
}

// 0x800096B8 (264 bytes)
// AptAuxPCEorGL_FinishAsyncLoads(void)
void AptAuxPCEorGL_FinishAsyncLoads(void) {
    // Calls: AptSharedPtrIncRef(AptFile *)
    // Calls: AptCompleteAnimationAsyncLoad(AptSharedPtr<AptFile>, void *, void *, void *)
    // Calls: AptSharedPtrDecRef(AptFile *)
    // Calls: AptSharedPtrDelete(AptFile *)
    // Calls: MainHeap(void)
    // Calls: EAHeap::Free(void *)
    // TODO: 264 bytes, 9 call instructions
}

// 0x800097C4 (240 bytes)
// AptAuxPCEorGL_FreeAnimation(void *)
void AptAuxPCEorGL_FreeAnimation(void *) {
    // Calls: FlashBigFile::~FlashBigFile(void)
    // Calls: __builtin_delete
    // Calls: __node_alloc<false, 0>::_M_deallocate(void *, unsigned int)
    // TODO: 240 bytes, 3 call instructions
}

// 0x80009918 (992 bytes)
// AptAuxPCEorGL_Initialize(int, int, AptAuxFontList *)
void AptAuxPCEorGL_Initialize(int, int, AptAuxFontList *) {
    // Calls: AptAllocatorInitialize(unsigned int, unsigned int, unsigned int, unsigned int)
    // Calls: EMat4::Id(void)
    // Calls: hardwareInit(float, float)
    // Calls: AptDebugPlaySavedInputs(AptSavedInputRecord *, int)
    // Calls: __builtin_new
    // Calls: GetGameFontID(void)
    // ... and 4 more
    // TODO: 992 bytes, 14 call instructions
}

// 0x80009CF8 (196 bytes)
// AptAuxPCEorGL_Shutdown(void)
void AptAuxPCEorGL_Shutdown(void) {
    // Calls: __builtin_delete
    // Calls: MainHeap(void)
    // Calls: EAHeap::Free(void *)
    // Calls: AptAllocatorShutdown(void)
    // Calls: memset
    // Calls: EResource::DelRef(void)
    // Calls: PSystemDestroy
    // TODO: 196 bytes, 10 call instructions
}

// 0x80009DC4 (656 bytes)
// GetScaledVertexColor(unsigned int *, unsigned int)
void GetScaledVertexColor(unsigned int *, unsigned int) {
    // TODO: 656 bytes, 0 call instructions
}

// 0x8000A054 (964 bytes)
// DrawLineSolid(AptAuxUnit *, AptMaskRenderOperation)
void DrawLineSolid(AptAuxUnit *, AptMaskRenderOperation) {
    // Calls: GetScaledVertexColor(unsigned int *, unsigned int)
    // TODO: 964 bytes, 1 call instructions
}

// 0x8000A418 (848 bytes)
// DrawTriSolid(AptAuxUnit *, AptMaskRenderOperation)
void DrawTriSolid(AptAuxUnit *, AptMaskRenderOperation) {
    // Calls: GetScaledVertexColor(unsigned int *, unsigned int)
    // TODO: 848 bytes, 1 call instructions
}

// 0x8000A768 (684 bytes)
// DrawTriTiledClipped(AptAuxUnit *, AptMaskRenderOperation)
void DrawTriTiledClipped(AptAuxUnit *, AptMaskRenderOperation) {
    // Calls: DrawTriSolid(AptAuxUnit *, AptMaskRenderOperation)
    // Calls: GetScaledVertexColor(unsigned int *, unsigned int)
    // TODO: 684 bytes, 2 call instructions
}

// 0x8000AA1C (160 bytes)
// AptAuxPCEorGL_SetUiObject(UIObjectBase *)
void AptAuxPCEorGL_SetUiObject(UIObjectBase *) {
    // Calls: AptAuxPCEorGL_RemoveUiObject(UIObjectBase *)
    // TODO: 160 bytes, 1 call instructions
}

// 0x8000AABC (140 bytes)
// AptAuxPCEorGL_RemoveUiObject(UIObjectBase *)
void AptAuxPCEorGL_RemoveUiObject(UIObjectBase *) {
    // TODO: 140 bytes, 0 call instructions
}

// 0x8000AB48 (68 bytes)
// AptAuxPCEorGL_WaitOn(char *)
void AptAuxPCEorGL_WaitOn(char *) {
    // Calls: AptUpdate(unsigned int)
    // TODO: 68 bytes, 1 call instructions
}

// 0x8000AB8C (160 bytes)
// AptAuxPCEorGL_LoadFile(char *)
void AptAuxPCEorGL_LoadFile(char *) {
    // Calls: EString::MakeCopy(char *)
    // Calls: EString::operator+=(char *)
    // Calls: AptLoadAnimation(char *, char *)
    // Calls: EString::Deallocate(char *)
    // TODO: 160 bytes, 6 call instructions
}

// 0x8000ACE4 (188 bytes)
// UCS2ToUTF8(unsigned wchar_t *, int, char *)
int UCS2ToUTF8(unsigned short* src, int srcLen, char* dst) {
    int dstLen = 0;
    for (int i = 0; i < srcLen && src[i] != 0; i++) {
        unsigned short ch = src[i];
        if (ch < 0x80) {
            dst[dstLen++] = (char)ch;
        } else if (ch < 0x800) {
            dst[dstLen++] = (char)(0xC0 | (ch >> 6));
            dst[dstLen++] = (char)(0x80 | (ch & 0x3F));
        } else {
            dst[dstLen++] = (char)(0xE0 | (ch >> 12));
            dst[dstLen++] = (char)(0x80 | ((ch >> 6) & 0x3F));
            dst[dstLen++] = (char)(0x80 | (ch & 0x3F));
        }
    }
    dst[dstLen] = 0;
    return dstLen;
}

// 0x8000ADA0 (144 bytes)
// UTF8ToUCS2(char *, int, unsigned wchar_t *)
int UTF8ToUCS2(char* src, int srcLen, unsigned short* dst) {
    int dstLen = 0;
    for (int i = 0; i < srcLen && src[i] != 0; ) {
        unsigned char ch = (unsigned char)src[i];
        if (ch < 0x80) {
            dst[dstLen++] = ch;
            i++;
        } else if ((ch & 0xE0) == 0xC0) {
            dst[dstLen++] = ((ch & 0x1F) << 6) | (src[i+1] & 0x3F);
            i += 2;
        } else {
            dst[dstLen++] = ((ch & 0x0F) << 12) | ((src[i+1] & 0x3F) << 6) | (src[i+2] & 0x3F);
            i += 3;
        }
    }
    dst[dstLen] = 0;
    return dstLen;
}

// 0x800100A8 (96 bytes)
// updateFunc(void)
void updateFunc(void) {
    // Calls: AptAuxPCEorGL_TimerStartFrame(void)
    // Calls: AptAuxPCEorGL_TimerGetTicks(void)
    // Calls: AptUpdate(unsigned int)
    // TODO: 96 bytes, 3 call instructions
}

// 0x80010108 (232 bytes)
// StartItAll(void)
void StartItAll(void) {
    // Calls: AptAuxPCEorGL_Initialize(int, int, AptAuxFontList *)
    // Calls: AptInitialize(AptInitParmsT *, bool)
    // Calls: DOGMA_PoolManager::Allocate(unsigned int)
    // Calls: AptSetXMLImplementor(IAptXmlImpl *)
    // Calls: AptAuxPCEorGL_TimerInit(void)
    // TODO: 232 bytes, 5 call instructions
}

// 0x80014BCC (72 bytes)
// BGCall_LoadDefaultNeighborhood(void)
void BGCall_LoadDefaultNeighborhood(void) {
    // Background task callback - sets flags/state
    // TODO: 72 bytes
}

// 0x80014C14 (88 bytes)
// BGExec_LoadHouse(void)
void BGExec_LoadHouse(void) {
    // Background task callback - sets flags/state
    // TODO: 88 bytes
}

// 0x80014C6C (72 bytes)
// BGCall_LoadHouse(void)
void BGCall_LoadHouse(void) {
    // Background task callback - sets flags/state
    // TODO: 72 bytes
}

// 0x80014CE4 (72 bytes)
// BGCall_CurHouseInit(void)
void BGCall_CurHouseInit(void) {
    // Background task callback - sets flags/state
    // TODO: 72 bytes
}

// 0x80014D6C (72 bytes)
// BGCall_FlushResQueue(void)
void BGCall_FlushResQueue(void) {
    // Background task callback - sets flags/state
    // TODO: 72 bytes
}

// 0x80014DE8 (72 bytes)
// BGCall_SetCurHouse(void)
void BGCall_SetCurHouse(void) {
    // Background task callback - sets flags/state
    // TODO: 72 bytes
}

// 0x80014E60 (84 bytes)
// BGExec_CASTargetInit(void)
void BGExec_CASTargetInit(void) {
    // Background task callback
    // Calls: __builtin_new
    // Calls: CASTarget::CASTarget(bool)
    // TODO: 84 bytes
}

// 0x80014EB4 (76 bytes)
// BGCall_CASTargetInit(bool)
void BGCall_CASTargetInit(bool) {
    // Background task callback - sets flags/state
    // TODO: 76 bytes
}

// 0x80014F30 (72 bytes)
// BGCall_ReloadObjectQuickdata(void)
void BGCall_ReloadObjectQuickdata(void) {
    // Background task callback - sets flags/state
    // TODO: 72 bytes
}

// 0x80014FB0 (72 bytes)
// BGCall_CASCGEGenerateStage(void)
void BGCall_CASCGEGenerateStage(void) {
    // Background task callback - sets flags/state
    // TODO: 72 bytes
}

// 0x80015834 (76 bytes)
// void {anonymous}::InterpolateSmooth<float>(float *, float &, float, float)
void InterpolateSmooth(float *, float &, float, float) {
    // TODO: 76 bytes, 0 call instructions
}

// 0x80015880 (68 bytes)
// {anonymous}::TurnOffSocialModeEffects(FrameEffectsManager *)
void TurnOffSocialModeEffects(FrameEffectsManager *) {
    // Calls: FrameEffectsManager::DepthOfFieldObject(void)
    // Calls: FrameEffect::Enable(bool)
    // TODO: 68 bytes, 2 call instructions
}

// 0x800158C4 (148 bytes)
// {anonymous}::TurnOnMotionBlur(FrameEffectsManager *)
void TurnOnMotionBlur(FrameEffectsManager *) {
    // Calls: FrameEffectsManager::MotionBlurObject(void)
    // Calls: FrameEffect::Enable(bool)
    // TODO: 148 bytes, 2 call instructions
}

// 0x80015958 (72 bytes)
// {anonymous}::TurnOffMotionBlur(FrameEffectsManager *)
void TurnOffMotionBlur(FrameEffectsManager *) {
    // Calls: FrameEffectsManager::MotionBlurObject(void)
    // Calls: FrameEffect::Enable(bool)
    // TODO: 72 bytes, 2 call instructions
}

// 0x800159A0 (104 bytes)
// {anonymous}::IsUsingSpecifiedInteractor(int, InteractorModule::InteractorType)
void IsUsingSpecifiedInteractor(int, int) {
    // Calls: InteractorModule::InteractorManager::GetSingleton(void)
    // Calls: InteractorModule::InteractorManager::GetPlayerInteractor(int, InteractorModule::InteractorType)
    // TODO: 104 bytes, 4 call instructions
}

// 0x80015A50 (408 bytes)
// {anonymous}::HandleEffectNote(ESimsCam *, EAnimNote &, anim::PropKind)
void HandleEffectNote(ESimsCam *, EAnimNote &, int) {
    // Calls: CameraDirector::GetFrameEffectsManager(void)
    // Calls: HandleBloomEvent(EAnimNote &, FrameEffectsManager *)
    // Calls: HandleMotionBlurEvent(EAnimNote &, FrameEffectsManager *)
    // Calls: HandleDepthOfFieldEvent(EAnimNote &, FrameEffectsManager *)
    // TODO: 408 bytes, 12 call instructions
}

// 0x800226C4 (84 bytes)
// isResInList(vector<unsigned int, allocator<unsigned int> > &, unsigned int)
void isResInList(vector<unsigned int, allocator<unsigned int> > &, unsigned int) {
    // TODO: 84 bytes, 0 call instructions
}

// 0x80022718 (468 bytes)
// collectResInfoForSel(ObjSelector *, vector<unsigned int, allocator<unsigned int> > &)
void collectResInfoForSel(ObjSelector *, vector<unsigned int, allocator<unsigned int> > &) {
    // Calls: EResourceManager::GetRef(unsigned int)
    // Calls: ERQuickdata::findRow(void *, unsigned int *)
    // Calls: EResourceManager::CalcId(char *)
    // Calls: isResInList(vector<unsigned int, allocator<unsigned int> > &, unsigned int)
    // Calls: __builtin_new
    // Calls: __node_alloc<false, 0>::_M_allocate(unsigned int)
    // ... and 3 more
    // TODO: 468 bytes, 9 call instructions
}

// 0x800228EC (848 bytes)
// collectResInfoForMultSel(ObjSelector *, vector<unsigned int, allocator<unsigned int> > &, vector<ObjSelector *, allocator<ObjSelector *> > *)
void collectResInfoForMultSel(ObjSelector *, vector<unsigned int, allocator<unsigned int> > &, vector<ObjSelector *, allocator<ObjSelector *> > *) {
    // Calls: ObjSelector::TestFromSameFile(ObjSelector *) const
    // Calls: collectResInfoForSel(ObjSelector *, vector<unsigned int, allocator<unsigned int> > &)
    // Calls: __builtin_new
    // Calls: __node_alloc<false, 0>::_M_allocate(unsigned int)
    // Calls: memmove
    // Calls: __builtin_delete
    // Calls: __node_alloc<false, 0>::_M_deallocate(void *, unsigned int)
    // TODO: 848 bytes, 13 call instructions
}

// 0x80022CB4 (164 bytes)
// addRefList(vector<unsigned int, allocator<unsigned int> > &, unsigned int *)
void addRefList(vector<unsigned int, allocator<unsigned int> > &, unsigned int *) {
    // Calls: void sort<unsigned int *, bool (*)(unsigned int &, unsigned int &)>(unsigned int *, unsigned int *, bool (*)(unsigned int &, unsigned int &))
    // Calls: EResourceManager::AddRef(unsigned int, EFile *, int)
    // TODO: 164 bytes, 2 call instructions
}

// 0x80022D58 (108 bytes)
// delRefList(vector<unsigned int, allocator<unsigned int> > &)
void delRefList(vector<unsigned int, allocator<unsigned int> > &) {
    // Calls: EResourceManager::DelRef(unsigned int, EResourceManager::DelRefMode)
    // TODO: 108 bytes, 1 call instructions
}

// 0x80023C84 (1964 bytes)
// SetupInterestFade(void)
void SetupInterestFade(void) {
    // Calls: PyramidFade::SetEnabled(bool)
    // Calls: LineFade::SetEnabled(bool)
    // Calls: InteractorModule::InteractorManager::GetSingleton(void)
    // Calls: InteractorModule::InteractorManager::GetPlayerInteractor(int, InteractorModule::InteractorType)
    // Calls: WallFadeParms::Validate(void)
    // Calls: InteractorModule::InteractorManager::GetPlayerInteractorInfo(int) const
    // ... and 9 more
    // TODO: 1964 bytes, 17 call instructions
}

// 0x80024790 (148 bytes)
// GetIndex(int, NewLevelLightingLevel *)
void GetIndex(int, NewLevelLightingLevel *) {
    // TODO: 148 bytes, 0 call instructions
}

// 0x80024940 (76 bytes)
// TimeIsInRange(int, int, int)
int TimeIsInRange(int time, int start, int end) {
    if (start <= end)
        return (time >= start && time <= end) ? 1 : 0;
    else
        return (time >= start || time <= end) ? 1 : 0;
}

// 0x800251FC (104 bytes)
// LightLocation(unsigned int, bool, short &, short &)
void LightLocation(unsigned int, bool, short &, short &) {
    // Calls: RoomManager::GetRoom(unsigned short)
    // TODO: 104 bytes, 1 call instructions
}

// 0x80027358 (164 bytes)
// HasWallsNotFences(TileWalls &)
void HasWallsNotFences(TileWalls &) {
    // Calls: TileWalls::HasWall(void) const
    // Calls: TileWalls::First(void) const
    // Calls: TileWalls::GetStyle(TileWallsSegment) const
    // Calls: TileWalls::Next(TileWallsSegment) const
    // TODO: 164 bytes, 4 call instructions
}

// 0x80027518 (760 bytes)
// _kBottomLeftWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
void _kBottomLeftWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector) {
    // Calls: CTilePt::operator+(CTilePt &) const
    // Calls: TileWalls::HasWallNotFence(TileWallsSegment) const
    // Calls: EIWallPart::GetWallType(unsigned char)
    // Calls: TileWalls::~TileWalls(void)
    // Calls: CTilePt::~CTilePt(void)
    // TODO: 760 bytes, 26 call instructions
}

// 0x80027810 (784 bytes)
// _kTopRightWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
void _kTopRightWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector) {
    // Calls: CTilePt::operator+(CTilePt &) const
    // Calls: TileWalls::HasWallNotFence(TileWallsSegment) const
    // Calls: CTilePt::operator=(CTilePt &)
    // Calls: CTilePt::~CTilePt(void)
    // Calls: TileWalls::operator=(TileWalls &)
    // Calls: TileWalls::~TileWalls(void)
    // Calls: EIWallPart::GetWallType(unsigned char)
    // TODO: 784 bytes, 28 call instructions
}

// 0x80027B20 (784 bytes)
// _kBottomRightWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
void _kBottomRightWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector) {
    // Calls: CTilePt::operator+(CTilePt &) const
    // Calls: TileWalls::HasWallNotFence(TileWallsSegment) const
    // Calls: CTilePt::operator=(CTilePt &)
    // Calls: CTilePt::~CTilePt(void)
    // Calls: TileWalls::operator=(TileWalls &)
    // Calls: TileWalls::~TileWalls(void)
    // Calls: EIWallPart::GetWallType(unsigned char)
    // TODO: 784 bytes, 28 call instructions
}

// 0x80027E30 (784 bytes)
// _kTopLeftWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
void _kTopLeftWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector) {
    // Calls: CTilePt::operator+(CTilePt &) const
    // Calls: TileWalls::HasWallNotFence(TileWallsSegment) const
    // Calls: CTilePt::operator=(CTilePt &)
    // Calls: CTilePt::~CTilePt(void)
    // Calls: TileWalls::operator=(TileWalls &)
    // Calls: TileWalls::~TileWalls(void)
    // Calls: EIWallPart::GetWallType(unsigned char)
    // TODO: 784 bytes, 28 call instructions
}

// 0x80028140 (864 bytes)
// _kHorizDiagWallskTopEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
void _kHorizDiagWallskTopEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector) {
    // Calls: CTilePt::operator+(CTilePt &) const
    // Calls: TileWalls::HasWallNotFence(TileWallsSegment) const
    // Calls: CTilePt::operator=(CTilePt &)
    // Calls: CTilePt::~CTilePt(void)
    // Calls: TileWalls::operator=(TileWalls &)
    // Calls: TileWalls::~TileWalls(void)
    // Calls: EIWallPart::GetWallType(unsigned char)
    // TODO: 864 bytes, 31 call instructions
}

// 0x800284A0 (864 bytes)
// _kHorizDiagWallskBottomEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
void _kHorizDiagWallskBottomEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector) {
    // Calls: CTilePt::operator+(CTilePt &) const
    // Calls: TileWalls::HasWallNotFence(TileWallsSegment) const
    // Calls: CTilePt::operator=(CTilePt &)
    // Calls: CTilePt::~CTilePt(void)
    // Calls: TileWalls::operator=(TileWalls &)
    // Calls: TileWalls::~TileWalls(void)
    // Calls: EIWallPart::GetWallType(unsigned char)
    // TODO: 864 bytes, 31 call instructions
}

// 0x80028800 (864 bytes)
// _kVertDiagWallskRightEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
void _kVertDiagWallskRightEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector) {
    // Calls: CTilePt::operator+(CTilePt &) const
    // Calls: TileWalls::HasWallNotFence(TileWallsSegment) const
    // Calls: CTilePt::operator=(CTilePt &)
    // Calls: CTilePt::~CTilePt(void)
    // Calls: TileWalls::operator=(TileWalls &)
    // Calls: TileWalls::~TileWalls(void)
    // Calls: EIWallPart::GetWallType(unsigned char)
    // TODO: 864 bytes, 31 call instructions
}

// 0x80028B60 (864 bytes)
// _kVertDiagWallskLeftEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
void _kVertDiagWallskLeftEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector) {
    // Calls: CTilePt::operator+(CTilePt &) const
    // Calls: TileWalls::HasWallNotFence(TileWallsSegment) const
    // Calls: CTilePt::operator=(CTilePt &)
    // Calls: CTilePt::~CTilePt(void)
    // Calls: TileWalls::operator=(TileWalls &)
    // Calls: TileWalls::~TileWalls(void)
    // Calls: EIWallPart::GetWallType(unsigned char)
    // TODO: 864 bytes, 31 call instructions
}

// 0x80028EC0 (76 bytes)
// SplitWallBottomRight(TileWalls &, CTilePt &)
int SplitWallBottomRight(TileWalls& walls, CTilePt& pt) {
    walls.HasWallNotFence(4); // check segment 4
    int result = walls.HasWallNotFence(2);
    return result != 0 ? 1 : 0;
}

// 0x80028F0C (76 bytes)
// SplitWallTopLeft(TileWalls &, CTilePt &)
int SplitWallTopLeft(TileWalls& walls, CTilePt& pt) {
    walls.HasWallNotFence(1); // check segment 1
    int result = walls.HasWallNotFence(2);
    return result != 0 ? 1 : 0;
}

// 0x80028F58 (76 bytes)
// SplitWallBottomLeft(TileWalls &, CTilePt &)
int SplitWallBottomLeft(TileWalls& walls, CTilePt& pt) {
    walls.HasWallNotFence(8); // check segment 8
    int result = walls.HasWallNotFence(1);
    return result != 0 ? 1 : 0;
}

// 0x80028FA4 (76 bytes)
// SplitWallTopRight(TileWalls &, CTilePt &)
int SplitWallTopRight(TileWalls& walls, CTilePt& pt) {
    walls.HasWallNotFence(2); // check segment 2
    int result = walls.HasWallNotFence(1);
    return result != 0 ? 1 : 0;
}

// 0x80028FF0 (444 bytes)
// SplitWallHorizDiag(TileWalls &, CTilePt &)
void SplitWallHorizDiag(TileWalls &, CTilePt &) {
    // Calls: CTilePt::CTilePt(int, int, int)
    // Calls: CTilePt::~CTilePt(void)
    // TODO: 444 bytes, 6 call instructions
}

// 0x800291AC (436 bytes)
// SplitWallVertDiag(TileWalls &, CTilePt &)
void SplitWallVertDiag(TileWalls &, CTilePt &) {
    // Calls: CTilePt::CTilePt(int, int, int)
    // Calls: CTilePt::~CTilePt(void)
    // TODO: 436 bytes, 6 call instructions
}

// 0x80029C24 (104 bytes)
// WallLocation(unsigned int, bool, short &, short &)
void WallLocation(unsigned int, bool, short &, short &) {
    // Calls: RoomManager::GetRoom(unsigned short)
    // TODO: 104 bytes, 1 call instructions
}

// 0x8002AB14 (1092 bytes)
// LightVertex(EVec4 &, EVec4 &, float, unsigned int *, ELights &, EMat4 *)
void LightVertex(EVec4 &, EVec4 &, float, unsigned int *, ELights &, EMat4 *) {
    // Calls: EMat4::operator=(EMat4 &)
    // Calls: operator*(EVec4 &, EMat4 &)
    // Calls: PSVECNormalize
    // Calls: PSVECSquareMag
    // TODO: 1092 bytes, 6 call instructions
}

// 0x8002AF58 (620 bytes)
// Light(bool, float, unsigned int *, ESMSStrip *, ELights &, EMat4 *)
void Light(bool, float, unsigned int *, ESMSStrip *, ELights &, EMat4 *) {
    // Calls: LightVertex(EVec4 &, EVec4 &, float, unsigned int *, ELights &, EMat4 *)
    // TODO: 620 bytes, 1 call instructions
}

// 0x8002E84C (88 bytes)
// SetAllUpOrDownForList(bool, TNodeList<ERoomWall *> &)
void SetAllUpOrDownForList(bool, TNodeList<ERoomWall *> &) {
    // Calls: ERoomWall::SetWallUpDownMode(EWallUpDownStateType, bool)
    // TODO: 88 bytes, 1 call instructions
}

// 0x80030964 (104 bytes)
// DrawSubModelShader(ERC *, ESubModelShader *)
void DrawSubModelShader(ERC *, ESubModelShader *) {
    // TODO: 104 bytes, 0 call instructions
}

// 0x80030AC4 (216 bytes)
// {anonymous}::IsPartOfDOFForeground(ESim *)
void IsPartOfDOFForeground(ESim *) {
    // Calls: CameraDirector::GetFrameEffectsManager(void)
    // Calls: FrameEffectsManager::DepthOfFieldObject(void)
    // TODO: 216 bytes, 2 call instructions
}

// 0x80037234 (164 bytes)
// RemapWallShadowId(unsigned int)
void RemapWallShadowId(unsigned int) {
    // TODO: 164 bytes, 0 call instructions
}

// 0x8003959C (520 bytes)
// InitZodiac(void)
void InitZodiac(void) {
    // Calls: EGlobal::GetPDAString(char *)
    // Calls: EGlobal::GetNewUIString(char *)
    // TODO: 520 bytes, 14 call instructions
}

// 0x800397A4 (196 bytes)
// ComputeZodiacSignAux(float *)
void ComputeZodiacSignAux(float *) {
    // TODO: 196 bytes, 0 call instructions
}

// 0x80039868 (132 bytes)
// ComputeZodiacSign(short *)
void ComputeZodiacSign(short *) {
    // Calls: ComputeZodiacSignAux(float *)
    // TODO: 132 bytes, 1 call instructions
}

// 0x800398EC (244 bytes)
// ComputeZodiacSignFromSimDesc(signed char *)
void ComputeZodiacSignFromSimDesc(signed char *) {
    // Calls: ComputeZodiacSignAux(float *)
    // TODO: 244 bytes, 1 call instructions
}

// 0x800399E0 (272 bytes)
// EORComputeZodiacSign(short *)
void EORComputeZodiacSign(short *) {
    // TODO: 272 bytes, 0 call instructions
}

// 0x80039AF0 (172 bytes)
// SetZodiacSign(short *, short)
void SetZodiacSign(short *, short) {
    // TODO: 172 bytes, 0 call instructions
}

// 0x80039B9C (156 bytes)
// EORSetZodiacSign(short *, short)
void EORSetZodiacSign(short *, short) {
    // TODO: 156 bytes, 0 call instructions
}

// 0x80039C38 (120 bytes)
// GetZodiacName(short)
void GetZodiacName(short) {
    // Calls: InitZodiac(void)
    // TODO: 120 bytes, 1 call instructions
}

// 0x80039CB0 (120 bytes)
// GetSignFromName(unsigned wchar_t *)
void GetSignFromName(unsigned short *) {
    // Calls: wcscmp
    // TODO: 120 bytes, 1 call instructions
}

// 0x8003A104 (124 bytes)
// StripFormatting(BString2 &)
void StripFormatting(BString2 &) {
    // Calls: BString2::erase(unsigned int, unsigned int)
    // Calls: BString2::find(wchar_t, unsigned int) const
    // TODO: 124 bytes, 3 call instructions
}

// 0x8003A180 (280 bytes)
// ColorStringForFlash(BString2 &, Interaction::tColor)
void ColorStringForFlash(BString2 &, int) {
    // Calls: Sprintf(char *, char *,...)
    // Calls: BString2::length(void) const
    // Calls: BString2::get_at(unsigned int) const
    // Calls: BString2::replace(unsigned int, unsigned int, wchar_t, unsigned int)
    // Calls: BString2::BString2(void)
    // Calls: BString2::assignDebug(char *)
    // ... and 3 more
    // TODO: 280 bytes, 9 call instructions
}

// 0x8003A298 (72 bytes)
// ColorIsHigherPriority(Interaction::tColor, Interaction::tColor)
int ColorIsHigherPriority(int colorA, int colorB) {
    return colorA > colorB ? 1 : 0;
}

// 0x8003ACFC (200 bytes)
// GetObjectMenuName(cXObject *)
void GetObjectMenuName(cXObject *) {
    // Calls: ObjSelector::GetIsPerson(void)
    // Calls: ObjSelector::GetUserName(void)
    // Calls: BString2::c_str(void) const
    // Calls: ObjSelector::GetMasterSelector(void)
    // Calls: ObjSelector::GetCatalogShortName(void)
    // TODO: 200 bytes, 6 call instructions
}

// 0x8003ADC4 (500 bytes)
// GetShaderForObject(cXObject *, ERShader **)
void GetShaderForObject(cXObject *, ERShader **) {
    // Calls: ObjSelector::GetIsPerson(void)
    // Calls: ObjSelector::GetGUID(void) const
    // Calls: GetNpcShaderId(int, bool)
    // Calls: ObjSelector::GetBigThumbnail(ERShader **)
    // Calls: TreeSim::_dyncastimpl(SCID)
    // TODO: 500 bytes, 5 call instructions
}

// 0x8003CA54 (992 bytes)
// DrawNoCtrlMessage(ERC *, unsigned wchar_t *)
void DrawNoCtrlMessage(ERC *, unsigned short *) {
    // Calls: ERFont::SetSize(float, float, bool)
    // Calls: ERFont::Select(ERC *)
    // Calls: ERFont::GetLineSpacing(EWindow *, bool)
    // Calls: memset
    // Calls: ERFont::DoGetStringSize(void *, bool, bool, EWindow *)
    // Calls: ERFont::DrawDs(ERC *, unsigned wchar_t *, EVec2 &, EFontAlignX, EFontAlignY, EVec2 *, float, float, bool)
    // TODO: 992 bytes, 6 call instructions
}

// 0x8004185C (132 bytes)
// OrientObjectInstance(cXObject *)
void OrientObjectInstance(cXObject *) {
    // TODO: 132 bytes, 0 call instructions
}

// 0x800418E0 (72 bytes)
// GetObjectInstance(cXObject *)
void GetObjectInstance(cXObject *) {
    // TODO: 72 bytes, 0 call instructions
}

// 0x80041928 (228 bytes)
// GetResData(cXObject *)
void GetResData(cXObject *) {
    // Calls: TreeSim::_dyncastimpl(SCID)
    // TODO: 228 bytes, 1 call instructions
}

// 0x80041B9C (68 bytes)
// CollectInteractionsForObject(cXObject *, InteractionList &, int, int)
void CollectInteractionsForObject(cXObject *, InteractionList &, int, int) {
    // Calls: CollectInteractionsForObject(cXObject *, InteractionList &, cXPerson *, int)
    // TODO: 68 bytes, 1 call instructions
}

// 0x80041BE0 (800 bytes)
// CollectInteractionsForObject(cXObject *, InteractionList &, cXPerson *, int)
void CollectInteractionsForObject(cXObject *, InteractionList &, cXPerson *, int) {
    // Calls: InteractionList::size(void) const
    // Calls: TreeSim::_dyncastimpl(SCID)
    // Calls: ObjTestSim::ObjTestSim(cXPerson *, cXObject *)
    // Calls: ObjTestSim::AppendInteractionsForMenu(InteractionList &, int)
    // Calls: ObjTestSim::~ObjTestSim(void)
    // TODO: 800 bytes, 16 call instructions
}

// 0x800427A8 (116 bytes)
// GetFireCodeValue(bool)
int GetFireCodeValue(bool enabled) {
    // Returns fire code compliance value
    // TODO: 116 bytes
    return enabled ? 1 : 0;
}

// 0x8004281C (88 bytes)
// GetSimFunds(unsigned int)
void GetSimFunds(unsigned int) {
    // TODO: 88 bytes, 0 call instructions
}

// 0x80042874 (92 bytes)
// SetSimFunds(unsigned int, int)
void SetSimFunds(unsigned int, int) {
    // TODO: 92 bytes, 0 call instructions
}

// 0x800428D4 (76 bytes)
// SetUIStatusText(char *,...)
void SetUIStatusText(char *,...) {
    // TODO: 76 bytes, 0 call instructions
}

// 0x80042C44 (360 bytes)
// GuidIsOk(int)
void GuidIsOk(int) {
    // TODO: 360 bytes, 0 call instructions
}

// 0x80042DAC (152 bytes)
// DeleteSelectorOnEvict(int)
void DeleteSelectorOnEvict(int) {
    // TODO: 152 bytes, 0 call instructions
}

// 0x80042E44 (280 bytes)
// AddFamilyToPool(int, int)
void AddFamilyToPool(int, int) {
    // TODO: 280 bytes, 0 call instructions
}

// 0x8004575C (84 bytes)
// ConvertRoomSideToWallSide(Room::Sides)
void ConvertRoomSideToWallSide(int) {
    // TODO: 84 bytes, 0 call instructions
}

// 0x800457B0 (632 bytes)
// BuildVertexSpans(TNodeList<EFloorStripInfo> &, EFloorVertexSpan *)
void BuildVertexSpans(TNodeList<EFloorStripInfo> &, EFloorVertexSpan *) {
    // Calls: __lshrdi3
    // Calls: __ashldi3
    // TODO: 632 bytes, 4 call instructions
}

// 0x800461E0 (280 bytes)
// EvaluateFloorLights(ELightGrid &, int, EVec3 &, EVec3 &)
void EvaluateFloorLights(ELightGrid &, int, EVec3 &, EVec3 &) {
    // TODO: 280 bytes, 0 call instructions
}

// 0x800462F8 (172 bytes)
// EvaluateFloorColors(EShader *, EVec3 &, EVec3 &, EVec3 &, EVec3 &)
void EvaluateFloorColors(EShader *, EVec3 &, EVec3 &, EVec3 &, EVec3 &) {
    // TODO: 172 bytes, 0 call instructions
}

// 0x800463A4 (624 bytes)
// EvaluateLightAtVertices(int, ELightGrid &, ELightGrid::LightData *, EFloorVertexSpan *, int, EVec3 *)
void EvaluateLightAtVertices(int, ELightGrid &, int *, EFloorVertexSpan *, int, EVec3 *) {
    // Calls: ELightGrid::GetLightsAtLocation(EVec3 &, int) const
    // Calls: PSVECDotProduct
    // TODO: 624 bytes, 2 call instructions
}

// 0x80047738 (104 bytes)
// FloorRoom(unsigned int, bool, short &, short &)
void FloorRoom(unsigned int, bool, short &, short &) {
    // Calls: RoomManager::GetRoom(unsigned short)
    // TODO: 104 bytes, 1 call instructions
}

// 0x8004938C (228 bytes)
// SolveQuadratic(float, float, float, float *)
void SolveQuadratic(float, float, float, float *) {
    // Calls: sqrtf
    // TODO: 228 bytes, 1 call instructions
}

// 0x80049470 (656 bytes)
// GetCircleCircleIX(EVec2 &, float, EVec2 &, EVec2 &, float, EVec2 &, Intersection &)
void GetCircleCircleIX(EVec2 &, float, EVec2 &, EVec2 &, float, EVec2 &, Intersection &) {
    // Calls: SolveQuadratic(float, float, float, float *)
    // Calls: sqrtf
    // TODO: 656 bytes, 2 call instructions
}

// 0x80049700 (760 bytes)
// GetCircleSegmentIX(EVec2 &, float, EVec2 &, EVec2 &, EVec2 &, Intersection &, bool)
void GetCircleSegmentIX(EVec2 &, float, EVec2 &, EVec2 &, EVec2 &, Intersection &, bool) {
    // Calls: sqrtf
    // TODO: 760 bytes, 1 call instructions
}

// 0x80049A38 (376 bytes)
// GetCircleSegmentClosedIX(EVec2 &, float, EVec2 &, EVec2 &, EVec2 &, Intersection &, bool)
void GetCircleSegmentClosedIX(EVec2 &, float, EVec2 &, EVec2 &, EVec2 &, Intersection &, bool) {
    // Calls: GetCircleSegmentIX(EVec2 &, float, EVec2 &, EVec2 &, EVec2 &, Intersection &, bool)
    // Calls: Intersection::Reset(void)
    // Calls: GetCirclePointIX(EVec2 &, float, EVec2 &, EVec2 &, Intersection &)
    // TODO: 376 bytes, 5 call instructions
}

// 0x80049BB0 (1200 bytes)
// GetCircleRectangleIX(EVec2 &, float, EVec2 &, EVec2 &, EVec2 &, Intersection &)
void GetCircleRectangleIX(EVec2 &, float, EVec2 &, EVec2 &, EVec2 &, Intersection &) {
    // Calls: Intersection::Reset(void)
    // Calls: GetCircleSegmentIX(EVec2 &, float, EVec2 &, EVec2 &, EVec2 &, Intersection &, bool)
    // Calls: GetCirclePointIX(EVec2 &, float, EVec2 &, EVec2 &, Intersection &)
    // TODO: 1200 bytes, 9 call instructions
}

// 0x8004B5BC (124 bytes)
// get_ingredient_type_array(FoodResult *, short *)
void get_ingredient_type_array(FoodResult *, short *) {
    // TODO: 124 bytes, 0 call instructions
}

// 0x8004B638 (172 bytes)
// make_ingredient_type_array(short, short, short, short, short *)
void make_ingredient_type_array(short, short, short, short, short *) {
    // Calls: qsort
    // TODO: 172 bytes, 1 call instructions
}

// 0x8004C060 (208 bytes)
// CalcRotAngleOff(float)
void CalcRotAngleOff(float) {
    // TODO: 208 bytes, 0 call instructions
}

// 0x8004E6A0 (112 bytes)
// OtherSide(unsigned int, bool, short &, short &)
void OtherSide(unsigned int, bool, short &, short &) {
    // Calls: ISimsObjectModel::GetAdjacentRoom(bool)
    // Calls: RoomManager::GetRoom(unsigned short)
    // TODO: 112 bytes, 2 call instructions
}

// 0x8004E710 (132 bytes)
// ThisSide(unsigned int, bool, short &, short &)
void ThisSide(unsigned int, bool, short &, short &) {
    // Calls: RoomManager::GetRoom(unsigned short)
    // TODO: 132 bytes, 1 call instructions
}

// 0x8004E794 (72 bytes)
// Hidden(unsigned int)
int Hidden(unsigned int flags) {
    return (flags & 0x1) ? 1 : 0; // Check hidden bit
}

// 0x80050C38 (104 bytes)
// PortalRoom(unsigned int, bool, short &, short &)
void PortalRoom(unsigned int, bool, short &, short &) {
    // Calls: RoomManager::GetRoom(unsigned short)
    // TODO: 104 bytes, 1 call instructions
}

// 0x800559FC (96 bytes)
// GetHandleFromISimInstance(ISimInstance *)
void GetHandleFromISimInstance(ISimInstance *) {
    // TODO: 96 bytes, 0 call instructions
}

// 0x80055A5C (116 bytes)
// GetObjectInstance(unsigned int)
void GetObjectInstance(unsigned int) {
    // Calls: ERedBlackTree::Find(unsigned int, unsigned int *) const
    // TODO: 116 bytes, 1 call instructions
}

// 0x8005BDA4 (100 bytes)
// {anonymous}::IsUsingDirectControlInteractor(int)
void IsUsingDirectControlInteractor(int) {
    // Calls: InteractorModule::InteractorManager::GetSingleton(void)
    // Calls: InteractorModule::InteractorManager::GetPlayerInteractor(int, InteractorModule::InteractorType)
    // TODO: 100 bytes, 4 call instructions
}

// 0x8005BE08 (456 bytes)
// {anonymous}::HandleEffectNote(cXPerson *, EAnimNote &, anim::PropKind)
void HandleEffectNote(cXPerson *, EAnimNote &, int) {
    // Calls: {anonymous}::GetSimIndex(cXPerson *)
    // Calls: CameraDirector::GetFrameEffectsManager(void)
    // Calls: HandleBloomEvent(EAnimNote &, FrameEffectsManager *)
    // Calls: HandleMotionBlurEvent(EAnimNote &, FrameEffectsManager *)
    // Calls: HandleDepthOfFieldEvent(EAnimNote &, FrameEffectsManager *)
    // Calls: {anonymous}::IsUsingDirectControlInteractor(int)
    // TODO: 456 bytes, 14 call instructions
}

// 0x800617BC (72 bytes)
// GetMotiveMag(float)
float GetMotiveMag(float val) {
    if (val < 0.0f) return -val;
    return val;
}

// 0x8006E5C0 (116 bytes)
// GetColor(float, EVec4 &)
void GetColor(float, EVec4 &) {
    // TODO: 116 bytes, 0 call instructions
}

// 0x80076E74 (132 bytes)
// Timer_Init(EClock *)
void Timer_Init(EClock *) {
    // Timer subsystem function
    // TODO: 132 bytes
}

// 0x80076EF8 (68 bytes)
// Timer_SetFrameDelta(float)
void Timer_SetFrameDelta(float) {
    // Timer subsystem function
    // TODO: 68 bytes
}

// 0x80076F3C (392 bytes)
// Timer_StartFrame(void)
void Timer_StartFrame(void) {
    // Timer subsystem function
    // TODO: 392 bytes
}

// 0x80079F8C (192 bytes)
// RainSplashParticleBirthCB(pemitter *, PVector4 *, PVector4 *)
void RainSplashParticleBirthCB(pemitter *, PVector4 *, PVector4 *) {
    // TODO: 192 bytes, 0 call instructions
}

// 0x8007A04C (652 bytes)
// RainSplashEmitterProcessCB(void *)
void RainSplashEmitterProcessCB(void *) {
    // Particle emitter callback
    // Calls: sqrtf
    // Calls: EmitterSpr3dProcessCB(void *)
    // TODO: 652 bytes
}

// 0x8007AB0C (136 bytes)
// CatWsABToBuff(unsigned wchar_t *, unsigned wchar_t *, unsigned wchar_t *, unsigned int)
void CatWsABToBuff(unsigned short *, unsigned short *, unsigned short *, unsigned int) {
    // TODO: 136 bytes, 0 call instructions
}

// 0x8007AB94 (128 bytes)
// CatWsAToBuff(unsigned wchar_t *, unsigned wchar_t *, unsigned int)
void CatWsAToBuff(unsigned short *, unsigned short *, unsigned int) {
    // TODO: 128 bytes, 0 call instructions
}

// 0x8007AC14 (116 bytes)
// FloatToWString(float, unsigned wchar_t *, unsigned int)
void FloatToWString(float, unsigned short *, unsigned int) {
    // Calls: memset
    // Calls: Sprintf(char *, char *,...)
    // Calls: CopyCharStrToWString(char *, unsigned wchar_t *, unsigned int)
    // TODO: 116 bytes, 3 call instructions
}

// 0x8007AC88 (160 bytes)
// IntToWString(int, unsigned wchar_t *, unsigned int, int)
void IntToWString(int, unsigned short *, unsigned int, int) {
    // Calls: memset
    // Calls: Sprintf(char *, char *,...)
    // Calls: CopyCharStrToWString(char *, unsigned wchar_t *, unsigned int)
    // TODO: 160 bytes, 4 call instructions
}

// 0x8007AD28 (80 bytes)
// CopyCharStrToWString(char *, unsigned wchar_t *, unsigned int)
void CopyCharStrToWString(char* src, unsigned short* dst, unsigned int maxLen) {
    unsigned int i = 0;
    while (src[i] && i < maxLen - 1) {
        dst[i] = (unsigned short)(unsigned char)src[i];
        i++;
    }
    dst[i] = 0;
}

// 0x8007AD78 (80 bytes)
// CopyWStringToCharStr(unsigned wchar_t *, char *, unsigned int)
void CopyWStringToCharStr(unsigned short* src, char* dst, unsigned int maxLen) {
    unsigned int i = 0;
    while (src[i] && i < maxLen - 1) {
        dst[i] = (char)(src[i] & 0xFF);
        i++;
    }
    dst[i] = 0;
}

// 0x8007ADC8 (552 bytes)
// SubstituteString(unsigned wchar_t *, unsigned wchar_t *, unsigned wchar_t *, StackString2<256> &)
void SubstituteString(unsigned short *, unsigned short *, unsigned short *, StackString2<256> &) {
    // Calls: StringBuffer2::StringBuffer2(unsigned wchar_t *, unsigned int)
    // Calls: StringBuffer2::append(unsigned wchar_t *, int)
    // Calls: StringBuffer2::length(void) const
    // Calls: wcslen
    // Calls: StringBuffer2::erase(void)
    // Calls: BString2::c_str(void) const
    // ... and 4 more
    // TODO: 552 bytes, 25 call instructions
}

// 0x8007AFF0 (168 bytes)
// SubstituteStringAll(unsigned wchar_t *, unsigned wchar_t *, unsigned wchar_t *, BString2 &)
void SubstituteStringAll(unsigned short *, unsigned short *, unsigned short *, BString2 &) {
    // Calls: BString2::BString2(unsigned wchar_t *)
    // Calls: BString2::erase(unsigned int, unsigned int)
    // Calls: BString2::append(BString2 &, unsigned int, unsigned int)
    // Calls: BString2::c_str(void) const
    // Calls: SubstituteString(unsigned wchar_t *, unsigned wchar_t *, unsigned wchar_t *, BString2 &)
    // Calls: BString2::~BString2(void)
    // TODO: 168 bytes, 6 call instructions
}

// 0x8007B098 (172 bytes)
// SubstituteStringAll(unsigned wchar_t *, unsigned wchar_t *, unsigned wchar_t *, StackString2<256> &)
void SubstituteStringAll(unsigned short *, unsigned short *, unsigned short *, StackString2<256> &) {
    // Calls: StringBuffer2::StringBuffer2(unsigned wchar_t *, unsigned int)
    // Calls: StringBuffer2::append(unsigned wchar_t *, int)
    // Calls: StringBuffer2::erase(void)
    // Calls: StringBuffer2::append(StringBuffer2 &, int)
    // Calls: StringBuffer2::c_str(void) const
    // Calls: SubstituteString(unsigned wchar_t *, unsigned wchar_t *, unsigned wchar_t *, StackString2<256> &)
    // TODO: 172 bytes, 6 call instructions
}

// 0x8007B144 (504 bytes)
// SubstituteString(unsigned wchar_t *, unsigned wchar_t *, unsigned wchar_t *, BString2 &)
void SubstituteString(unsigned short *, unsigned short *, unsigned short *, BString2 &) {
    // Calls: BString2::BString2(unsigned wchar_t *)
    // Calls: BString2::length(void) const
    // Calls: wcslen
    // Calls: BString2::erase(unsigned int, unsigned int)
    // Calls: BString2::c_str(void) const
    // Calls: BString2::find(unsigned wchar_t *, unsigned int) const
    // ... and 6 more
    // TODO: 504 bytes, 23 call instructions
}

// 0x8007B33C (696 bytes)
// GetTimeString(int, int, unsigned wchar_t *, StackString2<256> &)
void GetTimeString(int, int, unsigned short *, StackString2<256> &) {
    // Calls: StringBuffer2::StringBuffer2(unsigned wchar_t *, unsigned int)
    // Calls: EGlobal::GetNewUIString(char *)
    // Calls: StringBuffer2::append(unsigned wchar_t *, int)
    // Calls: StringBuffer2::copy(StringBuffer2 &)
    // Calls: BString2::c_str(void) const
    // Calls: StringBuffer2::find(unsigned wchar_t *, int) const
    // ... and 4 more
    // TODO: 696 bytes, 30 call instructions
}

// 0x8007B5F4 (676 bytes)
// GetMoneyString(int, StackString2<256> &, bool)
void GetMoneyString(int, StackString2<256> &, bool) {
    // Calls: EGlobal::GetNewUIString(char *)
    // Calls: IntToWString(int, unsigned wchar_t *, unsigned int, int)
    // Calls: StringBuffer2::StringBuffer2(unsigned wchar_t *, unsigned int)
    // Calls: StringBuffer2::erase(void)
    // Calls: CopyCharStrToWString(char *, unsigned wchar_t *, unsigned int)
    // Calls: StringBuffer2::append(unsigned wchar_t *, int)
    // ... and 3 more
    // TODO: 676 bytes, 19 call instructions
}

// 0x8007B898 (2412 bytes)
// ReplaceButtonPrompts(unsigned wchar_t *, BString2 &)
void ReplaceButtonPrompts(unsigned short *, BString2 &) {
    // Calls: BString2::BString2(unsigned wchar_t *)
    // Calls: BString2::erase(unsigned int, unsigned int)
    // Calls: BString2::append(BString2 &, unsigned int, unsigned int)
    // Calls: BString2::BString2(void)
    // Calls: BString2::assign(wchar_t, unsigned int)
    // Calls: BString2::c_str(void) const
    // ... and 4 more
    // TODO: 2412 bytes, 153 call instructions
}

// 0x8007C204 (2416 bytes)
// ReplaceButtonPrompts(unsigned wchar_t *, StackString2<256> &)
void ReplaceButtonPrompts(unsigned short *, StackString2<256> &) {
    // Calls: StringBuffer2::StringBuffer2(unsigned wchar_t *, unsigned int)
    // Calls: StringBuffer2::append(unsigned wchar_t *, int)
    // Calls: StringBuffer2::erase(void)
    // Calls: StringBuffer2::append(StringBuffer2 &, int)
    // Calls: BString2::BString2(void)
    // Calls: BString2::assign(wchar_t, unsigned int)
    // ... and 7 more
    // TODO: 2416 bytes, 153 call instructions
}

// 0x8007CB74 (452 bytes)
// DlgReplaceButtonPrompts(unsigned wchar_t *, BString2 &)
void DlgReplaceButtonPrompts(unsigned short *, BString2 &) {
    // Calls: StringBuffer2::StringBuffer2(unsigned wchar_t *, unsigned int)
    // Calls: StringBuffer2::append(unsigned wchar_t *, int)
    // Calls: StringBuffer2::c_str(void) const
    // Calls: wcsstr
    // Calls: StringBuffer::StringBuffer(char *, unsigned int)
    // Calls: StringBuffer2::length(void) const
    // ... and 8 more
    // TODO: 452 bytes, 15 call instructions
}

// 0x8007D6C0 (136 bytes)
// QueryPerformanceCounter(long long *)
void QueryPerformanceCounter(long long* counter) {
    // Read hardware timer
    // On GC: reads TBR (time base register)
    // TODO: 136 bytes
    *counter = 0;
}

// 0x8007D748 (84 bytes)
// InitPerformanceCounter(void)
void InitPerformanceCounter(void) {
    // Initialize performance counter subsystem
    // TODO: 84 bytes
}

// 0x8007D79C (108 bytes)
// GetTimeDate(void)
void* GetTimeDate(void) {
    // Returns current date/time
    // TODO: 108 bytes
    return 0;
}

// 0x8007D808 (152 bytes)
// timeGetTime(void)
unsigned int timeGetTime(void) {
    // Returns elapsed time in milliseconds
    // TODO: 152 bytes
    return 0;
}

// 0x800842D8 (396 bytes)
// DrawIcon(ERC *, EVec2 &, EVec2 &, EVec4 &, ERShader *)
void DrawIcon(ERC *, EVec2 &, EVec2 &, EVec4 &, ERShader *) {
    // TODO: 396 bytes, 0 call instructions
}

// 0x80089E30 (100 bytes)
// IsUsingDirectControlInteractor(int) [2nd definition, different address]
void IsUsingDirectControlInteractor_2(int) {
    // Calls: InteractorModule::InteractorManager::GetSingleton(void)
    // Calls: InteractorModule::InteractorManager::GetPlayerInteractor(int, InteractorModule::InteractorType)
    // TODO: 100 bytes, 4 call instructions
}

// 0x8008B7C4 (228 bytes)
// LoadLevelGlobalData(void)
void LoadLevelGlobalData(void) {
    // Calls: cGZSndSys::FreeUnusedSounds(void)
    // Calls: EResourceManager::AddRef(unsigned int, EFile *, int)
    // TODO: 228 bytes, 5 call instructions
}

// 0x8008B8A8 (288 bytes)
// UnloadLevelGlobalData(void)
void UnloadLevelGlobalData(void) {
    // Calls: EResourceManager::DelRef(unsigned int, EResourceManager::DelRefMode)
    // Calls: cGZSndSys::FreeUnusedSounds(void)
    // Calls: Path::DeallocateAllPathData(void)
    // TODO: 288 bytes, 6 call instructions
}

// 0x8008B9C8 (84 bytes)
// LoadHousePreloadDataset(char *)
void LoadHousePreloadDataset(char *) {
    // Calls: Sprintf(char *, char *,...)
    // Calls: EDatasetManager::AddRefAsync(char *)
    // Calls: EResourceManager::CalcId(char *)
    // TODO: 84 bytes, 3 call instructions
}

// 0x8008BA1C (144 bytes)
// {anonymous}::RenderPostProcessEffects(int, ERC *)
void RenderPostProcessEffects(int, ERC *) {
    // Calls: CameraDirector::GetFrameEffectsManager(void)
    // Calls: FrameEffectsManager::BloomObject(void)
    // Calls: FrameEffectsManager::MotionBlurObject(void)
    // Calls: FrameEffect::Update(float, ERC *)
    // TODO: 144 bytes, 5 call instructions
}

// 0x800916B4 (68 bytes)
// THREADCALL_MU_SaveNewGame(void)
void THREADCALL_MU_SaveNewGame(void) {
    // Calls: THREADPOLL_MU_Start(void)
    // TODO: 68 bytes, 1 call instructions
}

// 0x80098010 (72 bytes)
// BGCall_SetDefaults(void)
void BGCall_SetDefaults(void) {
    // Background task callback - sets flags/state
    // TODO: 72 bytes
}

// 0x8009C254 (68 bytes)
// operator!=(char, BString &)
bool operator!=(char a, BString& b) {
    (void)a; (void)b; return false; // stub
}

// 0x8009C370 (68 bytes)
// operator<(char, BString &)
bool operator<(char a, BString& b) {
    (void)a; (void)b; return false; // stub
}

// 0x8009FA60 (244 bytes)
// operator+(BString &, BString &)
void operator+(BString &, BString &) {
    // Calls: BString::data(void) const
    // Calls: BString::length(void) const
    // Calls: BString::BString(char *, unsigned int, unsigned int)
    // Calls: BString::point(void)
    // Calls: memmove
    // Calls: BString::len(void)
    // Calls: BString::BString(BString &, unsigned int, unsigned int)
    // Calls: BString::~BString(void)
    // TODO: 244 bytes, 14 call instructions
}

// 0x8009FB54 (232 bytes)
// operator+(char *, BString &)
void operator+(char *, BString &) {
    // Calls: strlen
    // Calls: BString::length(void) const
    // Calls: BString::BString(char *, unsigned int, unsigned int)
    // Calls: BString::point(void)
    // Calls: BString::data(void) const
    // Calls: memmove
    // ... and 3 more
    // TODO: 232 bytes, 12 call instructions
}

// 0x8009FC3C (212 bytes)
// operator+(char, BString &)
void operator+(char, BString &) {
    // Calls: BString::length(void) const
    // Calls: BString::BString(char *, unsigned int, unsigned int)
    // Calls: BString::point(void)
    // Calls: BString::data(void) const
    // Calls: memmove
    // Calls: BString::len(void)
    // Calls: BString::BString(BString &, unsigned int, unsigned int)
    // Calls: BString::~BString(void)
    // TODO: 212 bytes, 11 call instructions
}

// 0x8009FD10 (216 bytes)
// operator+(BString &, char *)
void operator+(BString &, char *) {
    // Calls: strlen
    // Calls: BString::data(void) const
    // Calls: BString::length(void) const
    // Calls: BString::BString(char *, unsigned int, unsigned int)
    // Calls: BString::point(void)
    // Calls: memmove
    // ... and 3 more
    // TODO: 216 bytes, 10 call instructions
}

// 0x8009FDE8 (208 bytes)
// operator+(BString &, char)
void operator+(BString &, char) {
    // Calls: BString::data(void) const
    // Calls: BString::length(void) const
    // Calls: BString::BString(char *, unsigned int, unsigned int)
    // Calls: BString::point(void)
    // Calls: BString::len(void)
    // Calls: BString::eos(void)
    // Calls: BString::BString(BString &, unsigned int, unsigned int)
    // Calls: BString::~BString(void)
    // TODO: 208 bytes, 11 call instructions
}

// 0x800A03A0 (68 bytes)
// operator!=(wchar_t, BString2 &)
bool operator!=(wchar_t a, BString2& b) {
    (void)a; (void)b; return false; // stub
}

// 0x800A04BC (68 bytes)
// operator<(wchar_t, BString2 &)
bool operator<(wchar_t a, BString2& b) {
    (void)a; (void)b; return false; // stub
}

// 0x800A42CC (292 bytes)
// operator+(BString2 &, BString2 &)
void operator+(BString2 &, BString2 &) {
    // Calls: BString2::length(void) const
    // Calls: BString2::BString2(unsigned wchar_t *, unsigned int, unsigned int)
    // Calls: BString2::point(void)
    // Calls: memmove
    // Calls: BString2::len(void)
    // Calls: BString2::BString2(BString2 &, unsigned int, unsigned int)
    // Calls: BString2::~BString2(void)
    // TODO: 292 bytes, 14 call instructions
}

// 0x800A43F0 (260 bytes)
// operator+(unsigned wchar_t *, BString2 &)
void operator+(unsigned short *, BString2 &) {
    // Calls: wcslen
    // Calls: BString2::length(void) const
    // Calls: BString2::BString2(unsigned wchar_t *, unsigned int, unsigned int)
    // Calls: BString2::point(void)
    // Calls: memmove
    // Calls: BString2::len(void)
    // Calls: BString2::BString2(BString2 &, unsigned int, unsigned int)
    // Calls: BString2::~BString2(void)
    // TODO: 260 bytes, 12 call instructions
}

// 0x800A44F4 (240 bytes)
// operator+(wchar_t, BString2 &)
void operator+(wchar_t, BString2 &) {
    // Calls: BString2::length(void) const
    // Calls: BString2::BString2(unsigned wchar_t *, unsigned int, unsigned int)
    // Calls: BString2::point(void)
    // Calls: memmove
    // Calls: BString2::len(void)
    // Calls: BString2::BString2(BString2 &, unsigned int, unsigned int)
    // Calls: BString2::~BString2(void)
    // TODO: 240 bytes, 11 call instructions
}

// 0x800A45E4 (244 bytes)
// operator+(BString2 &, unsigned wchar_t *)
void operator+(BString2 &, unsigned short *) {
    // Calls: wcslen
    // Calls: BString2::length(void) const
    // Calls: BString2::BString2(unsigned wchar_t *, unsigned int, unsigned int)
    // Calls: BString2::point(void)
    // Calls: memmove
    // Calls: BString2::len(void)
    // Calls: BString2::BString2(BString2 &, unsigned int, unsigned int)
    // Calls: BString2::~BString2(void)
    // TODO: 244 bytes, 10 call instructions
}

// 0x800A46D8 (236 bytes)
// operator+(BString2 &, wchar_t)
void operator+(BString2 &, wchar_t) {
    // Calls: BString2::length(void) const
    // Calls: BString2::BString2(unsigned wchar_t *, unsigned int, unsigned int)
    // Calls: BString2::point(void)
    // Calls: BString2::len(void)
    // Calls: BString2::eos(void)
    // Calls: BString2::BString2(BString2 &, unsigned int, unsigned int)
    // Calls: BString2::~BString2(void)
    // TODO: 236 bytes, 11 call instructions
}

// 0x800A49B8 (108 bytes)
// AltToIso(float &)
void AltToIso(float &) {
    // Calls: sqrtf
    // TODO: 108 bytes, 1 call instructions
}

// 0x800A4A24 (96 bytes)
// IsoToAlt(float &)
void IsoToAlt(float &) {
    // Calls: sqrtf
    // TODO: 96 bytes, 1 call instructions
}

// 0x800A4AE8 (108 bytes)
// IsoToWorld(float &, float &, float &)
void IsoToWorld(float &, float &, float &) {
    // Calls: AltToWorld(float &)
    // TODO: 108 bytes, 1 call instructions
}

// 0x800A4B54 (108 bytes)
// IsoFracsToWorld(float &, float &, float &)
void IsoFracsToWorld(float &, float &, float &) {
    // Calls: AltToWorld(float &)
    // TODO: 108 bytes, 1 call instructions
}

// 0x800A4BC0 (176 bytes)
// IsoToWorld(FTilePt &, float &)
void IsoToWorld(FTilePt &, float &) {
    // Calls: AltToWorld(float &)
    // TODO: 176 bytes, 1 call instructions
}

// 0x800A4C70 (268 bytes)
// WorldToIso(EVec3 &)
void WorldToIso(EVec3 &) {
    // Calls: ceilf
    // Calls: floorf
    // TODO: 268 bytes, 4 call instructions
}

// 0x800A4D7C (124 bytes)
// ObjectRotationTf(int)
void ObjectRotationTf(int) {
    // Calls: RotationTf(RotationAxis, float &)
    // TODO: 124 bytes, 1 call instructions
}

// 0x800A4DF8 (816 bytes)
// RotationTf(RotationAxis, float &)
void RotationTf(RotationAxis, float &) {
    // Calls: cosf
    // Calls: sinf
    // Calls: EMat4::Id(void)
    // Calls: EMat4::operator=(EMat4 &)
    // TODO: 816 bytes, 4 call instructions
}

// 0x800A579C (280 bytes)
// SplitPath(StringBuffer &, StringBuffer &, StringBuffer &, StringBuffer &)
void SplitPath(StringBuffer &, StringBuffer &, StringBuffer &, StringBuffer &) {
    // Calls: StringBuffer::length(void) const
    // Calls: StringBuffer::charAt(int) const
    // Calls: StringBuffer::erase(void)
    // Calls: StringBuffer::append(StringBuffer &, int)
    // Calls: StringBuffer::c_str(void) const
    // Calls: StringBuffer::append(char *, int)
    // TODO: 280 bytes, 13 call instructions
}

// 0x800A58B4 (100 bytes)
// ExtractDirectory(StringBuffer &, StringBuffer &)
void ExtractDirectory(StringBuffer &, StringBuffer &) {
    // Calls: StringBuffer::StringBuffer(char *, unsigned int)
    // Calls: SplitPath(StringBuffer &, StringBuffer &, StringBuffer &, StringBuffer &)
    // TODO: 100 bytes, 3 call instructions
}

// 0x800A5918 (116 bytes)
// ExtractFileName(StringBuffer &, StringBuffer &)
void ExtractFileName(StringBuffer &, StringBuffer &) {
    // Calls: StringBuffer::StringBuffer(char *, unsigned int)
    // Calls: SplitPath(StringBuffer &, StringBuffer &, StringBuffer &, StringBuffer &)
    // Calls: StringBuffer::append(StringBuffer &, int)
    // TODO: 116 bytes, 4 call instructions
}

// 0x800A598C (136 bytes)
// ExtractExtension(StringBuffer &, StringBuffer &, StringBuffer &)
void ExtractExtension(StringBuffer &, StringBuffer &, StringBuffer &) {
    // Calls: StringBuffer::StringBuffer(char *, unsigned int)
    // Calls: SplitPath(StringBuffer &, StringBuffer &, StringBuffer &, StringBuffer &)
    // Calls: StringBuffer::copy(StringBuffer &)
    // Calls: StringBuffer::append(StringBuffer &, int)
    // TODO: 136 bytes, 5 call instructions
}

// 0x800A5A14 (132 bytes)
// WriteHandleToFile(Memory::HandleNode *, char *)
void WriteHandleToFile(int *, char *) {
    // Calls: efopen
    // Calls: efwrite
    // Calls: efclose
    // TODO: 132 bytes, 3 call instructions
}

// 0x800A64F8 (76 bytes)
// GetNextRandomNumber(void)
unsigned int GetNextRandomNumber(void) {
    // Linear congruential generator
    // seed = seed * 1103515245 + 12345
    extern unsigned int g_randomSeed; // SDA offset -24584
    unsigned int seed = g_randomSeed;
    unsigned int lo = (seed & 0xFFFF) * 20077;
    unsigned int result = seed * ((16838 << 16) | 20077);
    unsigned int hi = (seed >> 16) * 16838;
    // Combined LCG computation
    unsigned int mid = lo >> 16;
    mid += hi + (lo & 0xFFFF) * 16838;
    result += 12345;
    g_randomSeed = result;
    return (result >> 16) & 0x7FFF;
}

// 0x800A7DB4 (88 bytes)
// Swizzle8(void *)
void Swizzle8(void* ptr) {
    unsigned char* p = (unsigned char*)ptr;
    unsigned char t;
    t = p[0]; p[0] = p[7]; p[7] = t;
    t = p[1]; p[1] = p[6]; p[6] = t;
    t = p[2]; p[2] = p[5]; p[5] = t;
    t = p[3]; p[3] = p[4]; p[4] = t;
}

// 0x800A7E0C (88 bytes)
// Swizzle4(void *)
void Swizzle4(void* ptr) {
    unsigned char* p = (unsigned char*)ptr;
    unsigned char t;
    t = p[0]; p[0] = p[3]; p[3] = t;
    t = p[1]; p[1] = p[2]; p[2] = t;
}

// 0x800A7F00 (92 bytes)
// wcsncpy
// C library / SDK function - kept as asm stub for byte-matching
void wcsncpy() {
    // TODO: 92 bytes of runtime code
    // Calls: none
}

// 0x800A7FD4 (128 bytes)
// wcsstr
// C library / SDK function - kept as asm stub for byte-matching
void wcsstr() {
    // TODO: 128 bytes of runtime code
    // Calls: wcslen, wcschr, wcsncmp
}

// 0x800A8054 (100 bytes)
// wcscat
// C library / SDK function - kept as asm stub for byte-matching
void wcscat() {
    // TODO: 100 bytes of runtime code
    // Calls: wcslen
}

// 0x800AAA40 (68 bytes)
// castSkillToString(AnimRef *)
void castSkillToString(AnimRef *) {
    // Calls: EGlobal::GetNameFromSkill(AnimRef *)
    // TODO: 68 bytes, 1 call instructions
}

// 0x800ABC90 (80 bytes)
// __tcf_0
void __tcf_0() {
    // Static destructor / termination callback
    // Typically destroys a static object
}

// 0x800ABCE0 (80 bytes)
// __tcf_1
void __tcf_1() {
    // Static destructor / termination callback
    // Typically destroys a static object
}

// 0x800AD20C (84 bytes)
// DrawFrame(char *, EVec4 &, bool)
void DrawFrame(char *, EVec4 &, bool) {
    // TODO: 84 bytes, 0 call instructions
}

// 0x800AD260 (572 bytes)
// WaitForControllerButton(bool)
void WaitForControllerButton(bool) {
    // Calls: EControllerManager::GetController(unsigned int)
    // Calls: EORDbgTrace(char *,...)
    // Calls: DrawFrame(char *, EVec4 &, bool)
    // Calls: EController::GetBtnUpMask(unsigned int)
    // Calls: EController::GetBtnResult(unsigned int, bool, unsigned int)
    // TODO: 572 bytes, 17 call instructions
}

// 0x800AD49C (68 bytes)
// dbAssert(char *, unsigned int, char *)
void dbAssert(char* file, unsigned int line, char* expr) {
    // Debug assertion - likely no-op in release build
}

// 0x800AD4E0 (80 bytes)
// dbBomb(char *,...)
void dbBomb(char* fmt, ...) {
    // Debug bomb - likely no-op in release build
}

// 0x800AD530 (248 bytes)
// dbAssertTrace(bool, char *,...)
void dbAssertTrace(bool cond, char* fmt, ...) {
    // Debug assertion with trace - varargs saved, likely no-op
}

// 0x800AD628 (72 bytes)
// BoxxGlobalGetSourceParamValue(int, int, int *)
void BoxxGlobalGetSourceParamValue(int, int, int *) {
    // Calls: cAudioInfo::GetObjectData(int, cAudioInfo::DataIdx)
    // TODO: 72 bytes, 1 call instructions
}

// 0x800B14A0 (96 bytes)
// FindStringSet(VECTOR<WStringSet> &, short, int)
void FindStringSet(VECTOR<WStringSet> &, short, int) {
    // TODO: 96 bytes, 0 call instructions
}

// 0x800B3CF4 (344 bytes)
// GetComeSeeMe(cXObject *)
void GetComeSeeMe(cXObject *) {
    // Calls: GetComeSeeMeSelector(void)
    // TODO: 344 bytes, 1 call instructions
}

// 0x800B3E4C (196 bytes)
// RemoveComeSeeMeObjects(void)
void RemoveComeSeeMeObjects(void) {
    // Calls: GetComeSeeMeSelector(void)
    // TODO: 196 bytes, 1 call instructions
}

// 0x800B3F10 (772 bytes)
// UpdateComeSeeMeObjects(void)
void UpdateComeSeeMeObjects(void) {
    // Calls: GetComeSeeMeSelector(void)
    // Calls: TreeSim::_dyncastimpl(SCID)
    // Calls: GetComeSeeMe(cXObject *)
    // Calls: FTilePt::operator==(FTilePt &) const
    // TODO: 772 bytes, 4 call instructions
}

// 0x800B42BC (120 bytes)
// GlobalDispatch(short, int)
void GlobalDispatch(short, int) {
    // TODO: 120 bytes, 0 call instructions
}

// 0x800B4334 (168 bytes)
// TypedDispatch(int, short, int, bool)
void TypedDispatch(int, short, int, bool) {
    // TODO: 168 bytes, 0 call instructions
}

// 0x800B4998 (84 bytes)
// operator*(int, CTilePt &)
void operator*(int, CTilePt &) {
    // Calls: CTilePt::CTilePt(int, int, int)
    // TODO: 84 bytes, 1 call instructions
}

// 0x800B720C (88 bytes)
// DiscErrorCallback(bool)
void DiscErrorCallback(bool) {
    // Calls: cSoundPlayer::GetGameMode(void)
    // Calls: cSoundPlayer::SetGameMode(snd::eMode)
    // TODO: 88 bytes, 3 call instructions
}

// 0x800C6EBC (112 bytes)
// ObjectsAtTile(FTilePt &, int)
void ObjectsAtTile(FTilePt &, int) {
    // Calls: CTilePt::CTilePt(FTilePt &, int)
    // Calls: ObjectIterator::init(CTilePt &, ObjectIterator::IterateType)
    // Calls: CTilePt::~CTilePt(void)
    // TODO: 112 bytes, 3 call instructions
}

// 0x800C8B14 (308 bytes)
// GatherRelationshipLevelValues(void)
void GatherRelationshipLevelValues(void) {
    // Calls: NamespaceSelector::GetBehaviorConstants(short)
    // TODO: 308 bytes, 1 call instructions
}

// 0x800C90BC (432 bytes)
// AddPersDataPair(vector<PersDataPair, allocator<PersDataPair> > &, PersDataPair &)
void AddPersDataPair(vector<PersDataPair, allocator<PersDataPair> > &, PersDataPair &) {
    // Calls: __builtin_new
    // Calls: __node_alloc<false, 0>::_M_allocate(unsigned int)
    // Calls: __builtin_delete
    // Calls: __node_alloc<false, 0>::_M_deallocate(void *, unsigned int)
    // TODO: 432 bytes, 4 call instructions
}

// 0x800CCD54 (196 bytes)
// SortFamilyByCreation(Family *&, Family *&)
void SortFamilyByCreation(Family *&, Family *&) {
    // TODO: 196 bytes, 0 call instructions
}

// 0x800D2514 (72 bytes)
// PutConfigInMemoryCardCache(char *, unsigned int)
void PutConfigInMemoryCardCache(char *, unsigned int) {
    // Calls: NghResFile::GetMemoryCardCache(void)
    // Calls: MemoryCardCache::PutConfig(char *, unsigned int)
    // TODO: 72 bytes, 2 call instructions
}

// 0x800D255C (80 bytes)
// GetConfigFromMemoryCardCache(char *, unsigned int, int)
void GetConfigFromMemoryCardCache(char *, unsigned int, int) {
    // Calls: NghResFile::GetMemoryCardCache(void)
    // Calls: MemoryCardCache::GetConfig(char *, unsigned int, int)
    // TODO: 80 bytes, 2 call instructions
}

// 0x800D262C (68 bytes)
// LoadCacheFromMemoryCard(NghResFile *, int)
void LoadCacheFromMemoryCard(NghResFile *, int) {
    // Calls: NghResFile::GetMemoryCardCache(void)
    // Calls: MemoryCardCache::LoadCacheFromMemoryCard(int, NghResFile *)
    // TODO: 68 bytes, 2 call instructions
}

// 0x800D3920 (124 bytes)
// deleteList(NghResFileWriteInfo *)
void deleteList(NghResFileWriteInfo *) {
    // Calls: MainHeap(void)
    // Calls: EAHeap::Free(void *)
    // Calls: __builtin_delete
    // TODO: 124 bytes, 5 call instructions
}

// 0x800D399C (72 bytes)
// calculateDataSizeForList(NghResFileWriteInfo *, int &)
void calculateDataSizeForList(NghResFileWriteInfo *, int &) {
    // TODO: 72 bytes, 0 call instructions
}

// 0x800DE080 (196 bytes)
// SetSupportFlag(int, int, int, bool)
void SetSupportFlag(int, int, int, bool) {
    // Calls: CTilePt::CTilePt(int, int, int)
    // Calls: CTilePt::~CTilePt(void)
    // TODO: 196 bytes, 2 call instructions
}

// 0x800DF228 (680 bytes)
// ResolveRoomID(FTilePt &, int)
void ResolveRoomID(FTilePt &, int) {
    // Calls: CTilePt::CTilePt(FTilePt &, int)
    // Calls: CTilePt::~CTilePt(void)
    // Calls: CTilePt::CTilePt(CTilePt &)
    // Calls: TileWalls::HasWall(TileWallsSegment) const
    // Calls: CTilePt::GetX(void) const
    // Calls: CTilePt::SetX(int)
    // ... and 3 more
    // TODO: 680 bytes, 22 call instructions
}

// 0x800DFDE8 (80 bytes)
// ApproxSqrt(float)
float ApproxSqrt(float x) {
    // Fast approximate sqrt using bit manipulation
    if (x <= 0.0f) return 0.0f;
    return sqrtf(x);
}

// 0x800EBE5C (312 bytes)
// StringToHash(char *)
void StringToHash(char *) {
    // Calls: strlen
    // Calls: memset
    // TODO: 312 bytes, 2 call instructions
}

// 0x800EBFFC (108 bytes)
// ConvertToBackslash(StringBuffer &)
void ConvertToBackslash(StringBuffer &) {
    // Calls: StringBuffer::length(void) const
    // Calls: StringBuffer::buffer(void)
    // TODO: 108 bytes, 3 call instructions
}

// 0x800EF3E0 (284 bytes)
// IsPlayableCharacter(int, int &)
void IsPlayableCharacter(int, int &) {
    // TODO: 284 bytes, 0 call instructions
}

// 0x800F9A5C (1040 bytes)
// TryFindSafeLocForSim(cXObject *, FTilePt &, int, cXObject *, int)
void TryFindSafeLocForSim(cXObject *, FTilePt &, int, cXObject *, int) {
    // Calls: CTilePt::CTilePt(void)
    // Calls: CTilePt::CTilePt(FTilePt &, int)
    // Calls: CTilePt::operator+(CTilePt &) const
    // Calls: CTilePt::operator=(CTilePt &)
    // Calls: CTilePt::~CTilePt(void)
    // TODO: 1040 bytes, 45 call instructions
}

// 0x800FC5A0 (100 bytes)
// MakeMoneyString(StringBuffer2 &, int)
void MakeMoneyString(StringBuffer2 &, int) {
    // Calls: StringBuffer2::StringBuffer2(unsigned wchar_t *, unsigned int)
    // Calls: GetMoneyString(int, StackString2<256> &, bool)
    // Calls: StringBuffer2::c_str(void) const
    // Calls: StringBuffer2::copy(unsigned wchar_t *)
    // TODO: 100 bytes, 4 call instructions
}

// 0x800FC604 (472 bytes)
// ParseOneString(BString2 &, BString2 &, int, int *, int *, int *)
void ParseOneString(BString2 &, BString2 &, int, int *, int *, int *) {
    // Calls: BString2::find(BString2 &, unsigned int) const
    // Calls: BString2::length(void) const
    // Calls: BString2::operator[](unsigned int) const
    // Calls: StringBuffer::StringBuffer(char *, unsigned int)
    // Calls: StringBuffer::appendChar(char)
    // Calls: isdigit
    // ... and 4 more
    // TODO: 472 bytes, 24 call instructions
}

// 0x800FE014 (84 bytes)
// _MotiveSort(void *, void *)
void _MotiveSort(void *, void *) {
    // TODO: 84 bytes, 0 call instructions
}

// 0x800FF2F8 (552 bytes)
// StartFireAtObjectLoc(cXObject *, ObjSelector *)
void StartFireAtObjectLoc(cXObject *, ObjSelector *) {
    // Calls: ObjectIterator::init(CTilePt &, ObjectIterator::IterateType)
    // Calls: CTilePt::~CTilePt(void)
    // Calls: ObjectIterator::operator++(void)
    // TODO: 552 bytes, 3 call instructions
}

// 0x80104354 (80 bytes)
// __tcf_1 [2nd definition - renamed]
static void __tcf_3() {
    // Static destructor / termination callback
    // Typically destroys a static object
}

// 0x80104E58 (104 bytes)
// PresetHouseGameStatus(void)
void PresetHouseGameStatus(void) {
    // TODO: 104 bytes, 0 call instructions
}

// 0x8010A9D8 (76 bytes)
// fround(float)
int fround(float f) {
    if (f >= 0.0f)
        return (int)(f + 0.5f);
    else
        return (int)(f - 0.5f);
}

// 0x8010EE70 (3136 bytes)
// GetJobHUDControlName(short)
void GetJobHUDControlName(short) {
    // Calls: StringBuffer::StringBuffer(char *, unsigned int)
    // Calls: StringBuffer::append(char *, int)
    // Calls: StringBuffer::append(StringBuffer &, int)
    // Calls: __builtin_new
    // Calls: __node_alloc<false, 0>::_M_allocate(unsigned int)
    // Calls: __builtin_delete
    // ... and 3 more
    // TODO: 3136 bytes, 86 call instructions
}

// 0x80110C20 (96 bytes)
// GetNpcShaderId(int, bool)
void GetNpcShaderId(int, bool) {
    // Calls: EGlobal::GetRelationshipTableRow(unsigned int)
    // TODO: 96 bytes, 1 call instructions
}

// 0x801220D0 (80 bytes)
// __tcf_1 [2nd definition - renamed to avoid ODR violation]
static void __tcf_2() {
    // Static destructor / termination callback
    // Typically destroys a static object
}

// 0x80122998 (124 bytes)
// IsMoveOutOfWay(Interaction *)
void IsMoveOutOfWay(Interaction *) {
    // Calls: Interaction::GetStackObject(void) const
    // Calls: ObjSelector::GetGUID(void) const
    // TODO: 124 bytes, 3 call instructions
}

// 0x80122A14 (152 bytes)
// IsAskedToMove(cXPersonImpl *)
void IsAskedToMove(cXPersonImpl *) {
    // Calls: IsMoveOutOfWay(Interaction *)
    // TODO: 152 bytes, 1 call instructions
}

// 0x80132D3C (96 bytes)
// SetReconDumpFile(char *)
void SetReconDumpFile(char *) {
    // Calls: efclose
    // Calls: efopen
    // TODO: 96 bytes, 2 call instructions
}

// 0x80137B58 (136 bytes)
// IsScoredStyle(WallStyle)
void IsScoredStyle(WallStyle) {
    // TODO: 136 bytes, 0 call instructions
}

// 0x80138854 (96 bytes)
// GetLightRoomID(unsigned short)
void GetLightRoomID(unsigned short) {
    // Calls: RoomManager::GetRoom(unsigned short)
    // TODO: 96 bytes, 2 call instructions
}

// 0x801389B4 (136 bytes)
// FindIntersectingRect(IRect *, vector<PenaltyRect, allocator<PenaltyRect> > *)
void FindIntersectingRect(IRect *, vector<PenaltyRect, allocator<PenaltyRect> > *) {
    // TODO: 136 bytes, 0 call instructions
}

// 0x80139C04 (92 bytes)
// IsRectInside(IRect *, IRect *)
void IsRectInside(IRect *, IRect *) {
    // TODO: 92 bytes, 0 call instructions
}

// 0x8013BA9C (388 bytes)
// EvalPoint(IPoint, IPoint, IPoint, IPoint *, float *)
void EvalPoint(IPoint, IPoint, IPoint, IPoint *, float *) {
    // Calls: sqrtf
    // TODO: 388 bytes, 2 call instructions
}

// 0x8013D8D0 (312 bytes)
// TryCatExtension(StackString<260> &, SeqResFile::OpenSpec *)
void TryCatExtension(StackString<260> &, int *) {
    // Calls: StringBuffer::length(void) const
    // Calls: StringBuffer::charAt(int) const
    // Calls: StringBuffer::StringBuffer(char *, unsigned int)
    // Calls: StringBuffer::append(StringBuffer &, int)
    // Calls: ExtractExtension(StringBuffer &, StringBuffer &, StringBuffer &)
    // Calls: StringBuffer::compareNoCase(StringBuffer &) const
    // Calls: ExtractFileName(StringBuffer &, StringBuffer &)
    // Calls: StringBuffer::copy(StringBuffer &)
    // TODO: 312 bytes, 14 call instructions
}

// 0x8013FD04 (236 bytes)
// SetupMatrixAndKey(int, int, RelMatrix *&, int &)
void SetupMatrixAndKey(int, int, RelMatrix *&, int &) {
    // Calls: Neighbor::GetRelations(void) const
    // TODO: 236 bytes, 1 call instructions
}

// 0x801404CC (148 bytes)
// ReconExpReport(ExpenseReport *, ReconBuffer *)
void ReconExpReport(ExpenseReport *, ReconBuffer *) {
    // Calls: ReconBuffer::Recon32(int *, int)
    // Calls: ReconBuffer::ReconInt(int *, int)
    // TODO: 148 bytes, 2 call instructions
}

// 0x80141BA8 (108 bytes)
// ReportMissingAnimation(cXPerson *, char *, int)
void ReportMissingAnimation(cXPerson *, char *, int) {
    // TODO: 108 bytes, 0 call instructions
}

// 0x80141C14 (108 bytes)
// ReportMissingAnimation(cXObject *, cXPerson *, AnimTable *, int)
void ReportMissingAnimation(cXObject *, cXPerson *, AnimTable *, int) {
    // TODO: 108 bytes, 0 call instructions
}

// 0x80141C80 (1188 bytes)
// InitSkillLookup(void)
void InitSkillLookup(void) {
    // Calls: __builtin_new
    // Calls: AnimTable::DestroyInstance(AnimTable *)
    // Calls: AnimTable::CreateInstance(void)
    // TODO: 1188 bytes, 29 call instructions
}

// 0x8014215C (272 bytes)
// resolveSkillForPassiveInfluence(cXObject *, StackElem *, AnimateNewParam *, AnimRef *&)
void resolveSkillForPassiveInfluence(cXObject *, StackElem *, AnimateNewParam *, AnimRef *&) {
    // Calls: StackElem::GetParams(void)
    // Calls: GetObjectAnimRefPassiveInfluence(cXObject *, int, AnimRef *&)
    // Calls: GetPersonStockAnimRef(cXPerson *, int, AnimRef *&)
    // Calls: GetGlobalAnimRef(cXPerson *, int, AnimRef *&)
    // Calls: GetMiscAnimRef(cXPerson *, int, AnimRef *&)
    // TODO: 272 bytes, 5 call instructions
}

// 0x8014226C (536 bytes)
// GetStdAnimRef(cXPerson *, StdAnimIdx, AnimRef *&)
void GetStdAnimRef(cXPerson *, StdAnimIdx, AnimRef *&) {
    // TODO: 536 bytes, 0 call instructions
}

// 0x80142484 (124 bytes)
// GetReachAnimRef(cXPerson *, ReachAnimIdx, AnimRef *&)
void GetReachAnimRef(cXPerson *, ReachAnimIdx, AnimRef *&) {
    // TODO: 124 bytes, 0 call instructions
}

// 0x80142500 (140 bytes)
// GetMiscAnimRef(cXPerson *, int, AnimRef *&)
void GetMiscAnimRef(cXPerson *, int, AnimRef *&) {
    // Calls: ReportMissingAnimation(cXPerson *, char *, int)
    // TODO: 140 bytes, 1 call instructions
}

// 0x8014258C (524 bytes)
// GetObjectAnimRef(cXObject *, cXPerson *, int, bool, AnimRef *&)
void GetObjectAnimRef(cXObject *, cXPerson *, int, bool, AnimRef *&) {
    // Calls: Interaction::GetStackObject(void) const
    // Calls: Interaction::GetIconObject(void) const
    // Calls: TreeSim::_dyncastimpl(SCID)
    // Calls: ObjSelector::GetChildAnimTable(void)
    // Calls: ObjSelector::GetChildToAdultAnimTable(void)
    // Calls: ObjSelector::GetAdultToChildAnimTable(void)
    // Calls: ObjSelector::GetAdultAnimTable(void)
    // Calls: ReportMissingAnimation(cXObject *, cXPerson *, AnimTable *, int)
    // TODO: 524 bytes, 8 call instructions
}

// 0x80142798 (148 bytes)
// GetObjectAnimRefPassiveInfluence(cXObject *, int, AnimRef *&)
void GetObjectAnimRefPassiveInfluence(cXObject *, int, AnimRef *&) {
    // Calls: ObjSelector::GetAdultAnimTable(void)
    // TODO: 148 bytes, 1 call instructions
}

// 0x8014282C (140 bytes)
// GetPersonStockAnimRef(cXPerson *, int, AnimRef *&)
void GetPersonStockAnimRef(cXPerson *, int, AnimRef *&) {
    // Calls: ReportMissingAnimation(cXPerson *, char *, int)
    // TODO: 140 bytes, 1 call instructions
}

// 0x801428B8 (140 bytes)
// GetGlobalAnimRef(cXPerson *, int, AnimRef *&)
void GetGlobalAnimRef(cXPerson *, int, AnimRef *&) {
    // Calls: ReportMissingAnimation(cXPerson *, char *, int)
    // TODO: 140 bytes, 1 call instructions
}

// 0x801492EC (196 bytes)
// CalculateAttenuationValue(bool, int, float)
void CalculateAttenuationValue(bool, int, float) {
    // TODO: 196 bytes, 0 call instructions
}

// 0x80149F98 (116 bytes)
// TestDoorCondition(TileWalls &, TileWallsSegment)
void TestDoorCondition(TileWalls &, TileWallsSegment) {
    // Calls: TileWalls::First(void) const
    // Calls: TileWalls::GetStyle(TileWallsSegment) const
    // Calls: CanWalkThrough(WallStyle)
    // Calls: TileWalls::Next(TileWallsSegment) const
    // TODO: 116 bytes, 4 call instructions
}

// 0x8014A00C (588 bytes)
// SectWall(FTileRect *, int)
void SectWall(FTileRect *, int) {
    // Calls: CTilePt::CTilePt(int, int, int)
    // Calls: TileWalls::First(void) const
    // Calls: TileWalls::GetStyle(TileWallsSegment) const
    // Calls: CTilePt::GetX(void) const
    // Calls: CTilePt::GetY(void) const
    // Calls: TileWalls::~TileWalls(void)
    // Calls: CTilePt::~CTilePt(void)
    // Calls: TileWalls::Next(TileWallsSegment) const
    // TODO: 588 bytes, 14 call instructions
}

// 0x8014A258 (748 bytes)
// ValidDoorLocation(int, int, int, int, int)
void ValidDoorLocation(int, int, int, int, int) {
    // Calls: CTilePt::CTilePt(int, int, int)
    // Calls: CTilePt::CTilePt(TilePtDir, int)
    // Calls: CTilePt::operator+(CTilePt &) const
    // Calls: CTilePt::operator==(CTilePt &) const
    // Calls: CTilePt::~CTilePt(void)
    // Calls: TileWalls::HasWall(TileWallsSegment) const
    // Calls: TileWalls::~TileWalls(void)
    // TODO: 748 bytes, 28 call instructions
}

// 0x8014A560 (924 bytes)
// CheckWallFlags(FTilePt, int, int, int)
void CheckWallFlags(FTilePt, int, int, int) {
    // Calls: CTilePt::CTilePt(int, int, int)
    // Calls: TileWalls::HasDiagonal(void) const
    // Calls: TileWalls::Rotate(int)
    // Calls: TileWalls::HasWall(TileWallsSegment) const
    // Calls: TileWalls::GetStyle(TileWallsSegment) const
    // Calls: TileWalls::~TileWalls(void)
    // Calls: CTilePt::~CTilePt(void)
    // TODO: 924 bytes, 17 call instructions
}

// 0x8014C444 (224 bytes)
// GetWallPrice(WallStyle)
void GetWallPrice(WallStyle) {
    // TODO: 224 bytes, 0 call instructions
}

// 0x801517C0 (452 bytes)
// SetLotBorders(int, int, int, int)
void SetLotBorders(int, int, int, int) {
    // Calls: CTilePt::CTilePt(int, int, int)
    // Calls: CTilePt::~CTilePt(void)
    // TODO: 452 bytes, 2 call instructions
}

// 0x801522C0 (76 bytes)
// DestroyTheWorld(void)
void DestroyTheWorld(void) {
    // Cleanup all world data
    // TODO: 76 bytes
}

// 0x8015230C (80 bytes)
// ValidateTheWorld(void)
void ValidateTheWorld(void) {
    // Debug validation of world state
    // TODO: 80 bytes
}

// 0x80152A78 (672 bytes)
// TransformToWorldCoords(FTilePt *, float, float, int, FTilePt *)
void TransformToWorldCoords(FTilePt *, float, float, int, FTilePt *) {
    // Calls: ObjectRotationTf(int)
    // Calls: IsoFracsToWorld(float &, float &, float &)
    // Calls: WorldToIso(EVec3 &)
    // TODO: 672 bytes, 3 call instructions
}

// 0x80153500 (9168 bytes)
// BuildRoomPartition(unsigned short, vector<PenaltyRect, allocator<PenaltyRect> > *, bool)
void BuildRoomPartition(unsigned short, vector<PenaltyRect, allocator<PenaltyRect> > *, bool) {
    // Calls: cXObject::GetPersonWidth(void)
    // Calls: RoomManager::GetRoomManager(void)
    // Calls: RoomManager::GetRoom(unsigned short)
    // Calls: CTilePt::CTilePt(int, int, int)
    // Calls: CTilePt::~CTilePt(void)
    // Calls: PenaltyRect::PenaltyRect(int, int, int, int, int)
    // ... and 12 more
    // TODO: 9168 bytes, 105 call instructions
}

// 0x801558F4 (136 bytes)
// Stuck(vector<PenaltyRect, allocator<PenaltyRect> > *, IPoint *)
void Stuck(vector<PenaltyRect, allocator<PenaltyRect> > *, IPoint *) {
    // Calls: FindIntersectingRect(IRect *, vector<PenaltyRect, allocator<PenaltyRect> > *)
    // TODO: 136 bytes, 1 call instructions
}

// 0x80157FB8 (160 bytes)
// SetDirectionForGoalSearch(cXObject *, short, short, RoutingSlot *)
void SetDirectionForGoalSearch(cXObject *, short, short, RoutingSlot *) {
    // TODO: 160 bytes, 0 call instructions
}

// 0x80159738 (756 bytes)
// CollapsePenaltyRects(vector<PenaltyRect, allocator<PenaltyRect> > &)
void CollapsePenaltyRects(vector<PenaltyRect, allocator<PenaltyRect> > &) {
    // TODO: 756 bytes, 0 call instructions
}

// 0x801A7B34 (148 bytes)
// make_number_string(int, unsigned wchar_t *)
void make_number_string(int, unsigned short *) {
    // Calls: memset
    // Calls: Sprintf(char *, char *,...)
    // Calls: UTF8ToUCS2(char *, int, unsigned wchar_t *)
    // Calls: wcslen
    // TODO: 148 bytes, 4 call instructions
}

// 0x801B938C (72 bytes)
// find_ingredient(Ingredient **, unsigned int, short)
void find_ingredient(Ingredient **, unsigned int, short) {
    // TODO: 72 bytes, 0 call instructions
}

// 0x801B93D4 (72 bytes)
// find_ingredient_type(IngredientType **, unsigned int, short)
void find_ingredient_type(IngredientType **, unsigned int, short) {
    // TODO: 72 bytes, 0 call instructions
}

// 0x801C6FC4 (300 bytes)
// SetupCAS(void)
void SetupCAS(void) {
    // Calls: UIDB::UIDBSetInt(char *, int)
    // Calls: EGlobal::GetNewUIString(char *)
    // Calls: UIDB::UIDBSetString(char *, unsigned wchar_t *)
    // TODO: 300 bytes, 10 call instructions
}

// 0x801D1A10 (128 bytes)
// FindSelectorContainingResData(ObjSelector *)
void FindSelectorContainingResData(ObjSelector *) {
    // Calls: ObjSelector::GetMasterSelector(void)
    // TODO: 128 bytes, 1 call instructions
}

// 0x801D1AFC (128 bytes)
// GetObjSelector3dDisplayInfo(ObjSelector *, ObjectDefinition &)
void GetObjSelector3dDisplayInfo(ObjSelector *, ObjectDefinition &) {
    // TODO: 128 bytes, 0 call instructions
}

// 0x801D1B7C (196 bytes)
// sort_selectors_by_name(void *, void *)
int sort_selectors_by_name(void* a, void* b) {
    if (a == b) return 0;
    (void)0; // stub
}

// 0x801D1C40 (100 bytes)
// sort_cellinfo_by_cost(void *, void *)
int sort_cellinfo_by_cost(void* a, void* b) {
    if (a == b) return 0;
    (void)0; // stub
}

// 0x801D1CA4 (104 bytes)
// sort_walls_by_name(void *, void *)
int sort_walls_by_name(void* a, void* b) {
    if (a == b) return 0;
    (void)0; // stub
}

// 0x801D1D0C (104 bytes)
// sort_wallpaper_by_name(void *, void *)
int sort_wallpaper_by_name(void* a, void* b) {
    if (a == b) return 0;
    (void)0; // stub
}

// 0x801D1D74 (104 bytes)
// sort_floors_by_name(void *, void *)
int sort_floors_by_name(void* a, void* b) {
    if (a == b) return 0;
    (void)0; // stub
}

// 0x801D1DDC (100 bytes)
// play_sound(unsigned int)
void play_sound(unsigned int) {
    // Calls: __builtin_new
    // Calls: UIAUDIO::UIAUDIO(void)
    // Calls: UIAUDIO::PlaySound(unsigned int)
    // TODO: 100 bytes, 3 call instructions
}

// 0x801D4B9C (184 bytes)
// filter_object(PCTTarget::PCTTabInfo *, ObjSelector *)
void filter_object(int *, ObjSelector *) {
    // Calls: ObjSelector::GetIsMultiTileSubObject(void)
    // TODO: 184 bytes, 1 call instructions
}

// 0x801D514C (84 bytes)
// filter_floor(int, unsigned int, FloorTile *)
void filter_floor(int, unsigned int, FloorTile *) {
    // TODO: 84 bytes, 0 call instructions
}

// 0x801DA670 (128 bytes)
// sort_records_by_name(void *, void *)
int sort_records_by_name(void* a, void* b) {
    if (a == b) return 0;
    (void)0; // stub
}

// 0x801DCE90 (176 bytes)
// GetRecipeName(RCPTarget::Recipe *)
void GetRecipeName(int *) {
    // TODO: 176 bytes, 0 call instructions
}

// 0x801DDA9C (308 bytes)
// sum_attribute(int, RCPTarget::Recipe *)
void sum_attribute(int, int *) {
    // Calls: GetIngredientManager(void)
    // Calls: IngredientManager::GetIngredient(short) const
    // TODO: 308 bytes, 2 call instructions
}

// 0x801EC0D0 (68 bytes)
// StaticConvertTabToCategory(int)
void StaticConvertTabToCategory(int) {
    // TODO: 68 bytes, 0 call instructions
}

// 0x801EC114 (68 bytes)
// StaticGetObjectValue(ObjSelector *)
void StaticGetObjectValue(ObjSelector *) {
    // Calls: ObjSelector::GetMasterSelector(void)
    // TODO: 68 bytes, 1 call instructions
}

// 0x801EC158 (260 bytes)
// StaticGetShaderDimensions(ERShader *, unsigned int &, unsigned int &)
void StaticGetShaderDimensions(ERShader *, unsigned int &, unsigned int &) {
    // Calls: EShader::GetTexture(int) const
    // TODO: 260 bytes, 3 call instructions
}

// 0x801EC25C (768 bytes)
// StaticSetupFireCodeDialog(INVTarget *, UIDialog &, int)
void StaticSetupFireCodeDialog(INVTarget *, UIDialog &, int) {
    // Calls: EGlobal::GetNewUIString(char *)
    // Calls: BString2::assign(unsigned wchar_t *)
    // Calls: Sprintf(char *, char *,...)
    // Calls: BString2::BString2(void)
    // Calls: BString2::operator=(BString2 &)
    // Calls: BString2::~BString2(void)
    // ... and 3 more
    // TODO: 768 bytes, 18 call instructions
}

// 0x801EC55C (824 bytes)
// StaticSetupInventoryFullDialog(INVTarget *, UIDialog &, eInvFullDialogType)
void StaticSetupInventoryFullDialog(INVTarget *, UIDialog &, eInvFullDialogType) {
    // Calls: EGlobal::GetNewUIString(char *)
    // Calls: BString2::assign(unsigned wchar_t *)
    // Calls: BString2::BString2(void)
    // Calls: BString2::operator=(BString2 &)
    // Calls: BString2::~BString2(void)
    // Calls: EResourceManager::AddRef(unsigned int, EFile *, int)
    // Calls: StaticGetShaderDimensions(ERShader *, unsigned int &, unsigned int &)
    // Calls: memcpy
    // TODO: 824 bytes, 17 call instructions
}

// 0x801EC894 (768 bytes)
// StaticSetupCannotGrabToInventoryDialog(INVTarget *, UIDialog &)
void StaticSetupCannotGrabToInventoryDialog(INVTarget *, UIDialog &) {
    // Calls: EGlobal::GetPDAString(char *)
    // Calls: BString2::assign(unsigned wchar_t *)
    // Calls: EGlobal::GetNewUIString(char *)
    // Calls: BString2::BString2(void)
    // Calls: BString2::operator=(BString2 &)
    // Calls: BString2::~BString2(void)
    // ... and 3 more
    // TODO: 768 bytes, 16 call instructions
}

// 0x801ECB94 (196 bytes)
// StaticGetShaderId(ObjSelector *)
void StaticGetShaderId(ObjSelector *) {
    // Calls: ObjSelector::GetMasterSelector(void)
    // TODO: 196 bytes, 1 call instructions
}

// 0x801ECCC0 (148 bytes)
// StaticNumberToWideString(int, unsigned wchar_t *)
void StaticNumberToWideString(int, unsigned short *) {
    // Calls: memset
    // Calls: Sprintf(char *, char *,...)
    // Calls: UTF8ToUCS2(char *, int, unsigned wchar_t *)
    // Calls: wcslen
    // TODO: 148 bytes, 4 call instructions
}

// 0x801ECD54 (112 bytes)
// StaticExtractObjSelectorGuidFromObject(cXObject *)
void StaticExtractObjSelectorGuidFromObject(cXObject *) {
    // Calls: ObjSelector::GetMasterSelector(void)
    // Calls: ObjSelector::GetGUID(void) const
    // TODO: 112 bytes, 2 call instructions
}

// 0x801F49A0 (160 bytes)
// StaticCalcRefundAmount_Pack(int, int, int)
void StaticCalcRefundAmount_Pack(int, int, int) {
    // TODO: 160 bytes, 0 call instructions
}

// 0x801F4A40 (120 bytes)
// StaticCalcRefundAmount_Single(int, int)
void StaticCalcRefundAmount_Single(int, int) {
    // TODO: 120 bytes, 0 call instructions
}

// 0x801FC5D4 (372 bytes)
// StartFire(void)
void StartFire(void) {
    // Calls: StartFireAtObjectLoc(cXObject *, ObjSelector *)
    // Calls: rand
    // Calls: CTilePt::CTilePt(int, int, int)
    // Calls: CTilePt::~CTilePt(void)
    // TODO: 372 bytes, 5 call instructions
}

// 0x80228848 (144 bytes)
// TruncateLightDirection(EVec3 &)
void TruncateLightDirection(EVec3 &) {
    // Calls: PSVECNormalize
    // TODO: 144 bytes, 1 call instructions
}

// 0x80228EA8 (76 bytes)
// CompareIntensity(void *, void *)
int CompareIntensity(void* a, void* b) {
    // Compare light intensity values for sorting
    float ia = *(float*)a;
    float ib = *(float*)b;
    if (ia > ib) return -1;
    if (ia < ib) return 1;
    return 0;
}

// 0x8022EF84 (288 bytes)
// CalculateFacerMatrix(EVec3 &, EVec3 &, EMat4 &, bool)
void CalculateFacerMatrix(EVec3 &, EVec3 &, EMat4 &, bool) {
    // Calls: sqrtf
    // Calls: atan2f
    // Calls: EMat4::RotateZ(float)
    // Calls: PSVECNormalize
    // Calls: PSVECDotProduct
    // Calls: EMat4::PostRotateX(float)
    // TODO: 288 bytes, 6 call instructions
}

// 0x80230B38 (244 bytes)
// MergeLightWeights(int, ELightGrid::VertexData *, float, ELightGrid::LightWeight *, int &)
void MergeLightWeights(int, int *, float, int *, int &) {
    // TODO: 244 bytes, 0 call instructions
}

// 0x80231120 (88 bytes)
// AllocOTD(void)
void AllocOTD(void) {
    // Calls: ResourceHeap(void)
    // Calls: EAHeap::Malloc(unsigned int, int)
    // TODO: 88 bytes, 2 call instructions
}

// 0x80231178 (180 bytes)
// FreeOTDList(EOrderTableData *&)
void FreeOTDList(EOrderTableData *&) {
    // Calls: ResourceHeap(void)
    // Calls: EAHeap::Free(void *)
    // TODO: 180 bytes, 2 call instructions
}

// 0x80231240 (104 bytes)
// Outside(unsigned int, bool, short &, short &)
void Outside(unsigned int, bool, short &, short &) {
    // Calls: RoomManager::GetRoom(unsigned short)
    // TODO: 104 bytes, 1 call instructions
}

// 0x80233DDC (200 bytes)
// UnregisterFloorOTDsFromList(EOrderTableData **, EInstance *)
void UnregisterFloorOTDsFromList(EOrderTableData **, EInstance *) {
    // Calls: ResourceHeap(void)
    // Calls: EAHeap::Free(void *)
    // TODO: 200 bytes, 2 call instructions
}

// 0x802344B0 (88 bytes)
// OrderTableSortReferenceCompare(void *, void *)
void OrderTableSortReferenceCompare(void *, void *) {
    // TODO: 88 bytes, 0 call instructions
}

// 0x80236320 (92 bytes)
// FindOTD(EOrderTableData *, EOrderTableData &)
void FindOTD(EOrderTableData *, EOrderTableData &) {
    // TODO: 92 bytes, 0 call instructions
}

// 0x8023700C (204 bytes)
// CalcSkyLights(SkyLights &, EVec3 &, ELights &)
void CalcSkyLights(SkyLights &, EVec3 &, ELights &) {
    // TODO: 204 bytes, 0 call instructions
}

// 0x802370D8 (416 bytes)
// InterpolateToGraySky(float, LevelLightingEntry &)
void InterpolateToGraySky(float, LevelLightingEntry &) {
    // TODO: 416 bytes, 0 call instructions
}

// 0x80237278 (216 bytes)
// ApplyWeatherEffects(levelraininfo *, float, LevelLightingEntry &)
void ApplyWeatherEffects(levelraininfo *, float, LevelLightingEntry &) {
    // Calls: InterpolateToGraySky(float, LevelLightingEntry &)
    // TODO: 216 bytes, 1 call instructions
}

// 0x80237350 (320 bytes)
// InterpolateSkyLights(float, SkyLights &, SkyLights &, SkyLights &)
void InterpolateSkyLights(float, SkyLights &, SkyLights &, SkyLights &) {
    // TODO: 320 bytes, 0 call instructions
}

// 0x80237490 (756 bytes)
// InterpolateLevelLighting(LevelLighting *, float, LevelLightingEntry &)
void InterpolateLevelLighting(LevelLighting *, float, LevelLightingEntry &) {
    // Calls: InterpolateSkyLights(float, SkyLights &, SkyLights &, SkyLights &)
    // TODO: 756 bytes, 1 call instructions
}

// 0x80238B38 (512 bytes)
// SprSysSetState(unsigned int, unsigned int)
void SprSysSetState(unsigned int, unsigned int) {
    // Calls: EMat4::Id(void)
    // Calls: EMat4::operator=(EMat4 &)
    // Calls: operator*(EVec4 &, EMat4 &)
    // TODO: 512 bytes, 4 call instructions
}

// 0x80238D38 (1272 bytes)
// EmitterSpr3dPreProcessCB(void *)
void EmitterSpr3dPreProcessCB(void *) {
    // Particle emitter callback
    // Calls: E3DWindow::Test(EBound3 &)
    // Calls: SprSysSetState(unsigned int, unsigned int)
    // Calls: SprSysSetState(unsigned int, unsigned int)
    // TODO: 1272 bytes
}

// 0x80239230 (2096 bytes)
// EmitterSpr3dSubmitCB(particle *, PVector4 *, float, float, PVector4 *, void *)
void EmitterSpr3dSubmitCB(particle *, PVector4 *, float, float, PVector4 *, void *) {
    // Particle emitter callback
    // TODO: 2096 bytes
}

// 0x80239A60 (164 bytes)
// EmitterSpr3dProcessCB(void *)
void EmitterSpr3dProcessCB(void *) {
    // Particle emitter callback
    // TODO: 164 bytes
}

// 0x80239B04 (76 bytes)
// EmitterSpr3dCameraXYZProcessCB(void *)
void EmitterSpr3dCameraXYZProcessCB(void *) {
    // Particle emitter callback
    // Calls: EmitterSpr3dProcessCB(void *)
    // TODO: 76 bytes
}

// 0x80239B50 (116 bytes)
// EmitterSpr3dCamaraXYProcessCB(void *)
void EmitterSpr3dCamaraXYProcessCB(void *) {
    // Particle emitter callback
    // Calls: EmitterSpr3dProcessCB(void *)
    // TODO: 116 bytes
}

// 0x80239E28 (232 bytes)
// EmitterGeomdPreProcessCB(void *)
void EmitterGeomdPreProcessCB(void *) {
    // Particle emitter callback
    // Calls: ERLevel::GetSunLight(EVec3 &, EDirLight &)
    // TODO: 232 bytes
}

// 0x80239F50 (484 bytes)
// EmitterGeom3dSubmitCB(particle *, PVector4 *, float, float, PVector4 *, void *)
void EmitterGeom3dSubmitCB(particle *, PVector4 *, float, float, PVector4 *, void *) {
    // Particle emitter callback
    // Calls: ERModel::GetScaleMatrix(void)
    // Calls: EMat4::operator=(EMat4 &)
    // Calls: E3DWindow::Test(EBoundSphere &)
    // TODO: 484 bytes
}

// 0x8023A1F8 (508 bytes)
// EmitterGeom3dTabSubmitCB(particle *, PVector4 *, float, float, PVector4 *, void *)
void EmitterGeom3dTabSubmitCB(particle *, PVector4 *, float, float, PVector4 *, void *) {
    // Particle emitter callback
    // Calls: ERModel::GetScaleMatrix(void)
    // Calls: EMat4::operator=(EMat4 &)
    // Calls: E3DWindow::Test(EBoundSphere &)
    // TODO: 508 bytes
}

// 0x8023A504 (108 bytes)
// _ParseNode(CDirtyXmlNode *, unsigned char *)
void _ParseNode(CDirtyXmlNode *, unsigned char *) {
    // XML parsing utility
    // Calls: __builtin_new
    // TODO: 108 bytes
}

// 0x8023A570 (148 bytes)
// _ParseNumChildNodes(unsigned char *)
void _ParseNumChildNodes(unsigned char *) {
    // XML parsing utility
    // Calls: XmlNextChild
    // Calls: XmlSkip
    // Calls: XmlContentGetString
    // TODO: 148 bytes
}

// 0x8023A604 (204 bytes)
// _ParseChildNodes(CDirtyXmlNode **, int, unsigned char *)
void _ParseChildNodes(CDirtyXmlNode **, int, unsigned char *) {
    // XML parsing utility
    // Calls: XmlNextChild
    // Calls: _ParseNode(CDirtyXmlNode *, unsigned char *)
    // Calls: XmlSkip
    // TODO: 204 bytes
}

// 0x8023A6D0 (92 bytes)
// _ParseLevel(CDirtyXmlNode *, unsigned char *)
void _ParseLevel(CDirtyXmlNode *, unsigned char *) {
    // XML parsing utility
    // Calls: _ParseNumChildNodes(unsigned char *)
    // Calls: __builtin_vec_new
    // Calls: _ParseChildNodes(CDirtyXmlNode **, int, unsigned char *)
    // TODO: 92 bytes
}

// 0x8023A72C (116 bytes)
// _Parse(CDirtyXmlNode *, CDirtyXmlNode *, unsigned char *)
void _Parse(CDirtyXmlNode *, CDirtyXmlNode *, unsigned char *) {
    // XML parsing utility
    // Calls: _ParseLevel(CDirtyXmlNode *, unsigned char *)
    // Calls: _Parse(CDirtyXmlNode *, CDirtyXmlNode *, unsigned char *)
    // TODO: 116 bytes
}

// 0x8023B0A0 (500 bytes)
// _SecsToTime(tm *, unsigned int)
void _SecsToTime(tm *, unsigned int) {
    // TODO: 500 bytes, 0 call instructions
}

// 0x8023B294 (208 bytes)
// _TimeToSecs(tm *)
void _TimeToSecs(tm *) {
    // Calls: _SecsToTime(tm *, unsigned int)
    // TODO: 208 bytes, 1 call instructions
}

// 0x8023B364 (404 bytes)
// _XmlContentChar(unsigned char *, unsigned char *)
void _XmlContentChar(unsigned char *, unsigned char *) {
    // XML parsing utility
    // TODO: 404 bytes
}

// 0x8023B4F8 (76 bytes)
// _XmlContentFind(unsigned char *)
void _XmlContentFind(unsigned char *) {
    // XML parsing utility
    // TODO: 76 bytes
}

// 0x8023B544 (412 bytes)
// _XmlAttribFind(unsigned char *, unsigned char *)
void _XmlAttribFind(unsigned char *, unsigned char *) {
    // XML parsing utility
    // TODO: 412 bytes
}

// 0x8023B6E0 (312 bytes)
// _XmlAttribFindByIndex(unsigned char *, int)
void _XmlAttribFindByIndex(unsigned char *, int) {
    // XML parsing utility
    // TODO: 312 bytes
}

// 0x8023B818 (388 bytes)
// XmlSkip
void XmlSkip() {
    // XML parsing utility
    // TODO: 388 bytes
}

// 0x8023B99C (460 bytes)
// XmlFind
void XmlFind() {
    // XML parsing utility
    // Calls: XmlSkip
    // Calls: XmlFind
    // Calls: XmlSkip
    // TODO: 460 bytes
}

// 0x8023BB68 (224 bytes)
// XmlNext
void XmlNext() {
    // XML parsing utility
    // Calls: XmlSkip
    // TODO: 224 bytes
}

// 0x8023BC48 (84 bytes)
// XmlNextChild
void XmlNextChild() {
    // XML parsing utility
    // TODO: 84 bytes
}

// 0x8023BC9C (112 bytes)
// XmlGetNodeName
void XmlGetNodeName() {
    // XML parsing utility
    // TODO: 112 bytes
}

// 0x8023BD0C (68 bytes)
// XmlGetNodeValue
void XmlGetNodeValue() {
    // XML parsing utility
    // TODO: 68 bytes
}

// 0x8023BD50 (128 bytes)
// XmlGetAttribName
void XmlGetAttribName() {
    // XML parsing utility
    // Calls: _XmlAttribFindByIndex(unsigned char *, int)
    // TODO: 128 bytes
}

// 0x8023BDD0 (308 bytes)
// XmlGetAttribValue
void XmlGetAttribValue() {
    // XML parsing utility
    // Calls: _XmlAttribFindByIndex(unsigned char *, int)
    // Calls: _XmlContentChar(unsigned char *, unsigned char *)
    // TODO: 308 bytes
}

// 0x8023BF04 (296 bytes)
// XmlContentGetString
void XmlContentGetString() {
    // XML parsing utility
    // Calls: _XmlContentFind(unsigned char *)
    // Calls: _XmlContentChar(unsigned char *, unsigned char *)
    // TODO: 296 bytes
}

// 0x8023C02C (180 bytes)
// XmlContentGetInteger
void XmlContentGetInteger() {
    // XML parsing utility
    // Calls: _XmlContentFind(unsigned char *)
    // TODO: 180 bytes
}

// 0x8023C0E0 (136 bytes)
// XmlContentGetToken
void XmlContentGetToken() {
    // XML parsing utility
    // Calls: _XmlContentFind(unsigned char *)
    // TODO: 136 bytes
}

// 0x8023C168 (396 bytes)
// XmlContentGetDate
void XmlContentGetDate() {
    // XML parsing utility
    // Calls: _XmlContentFind(unsigned char *)
    // Calls: _ParseNumber(unsigned char *, unsigned int *)
    // Calls: _ParseNumber(unsigned char *, unsigned int *)
    // TODO: 396 bytes
}

// 0x8023C2F4 (280 bytes)
// XmlContentGetBinary
void XmlContentGetBinary() {
    // XML parsing utility
    // Calls: _XmlContentFind(unsigned char *)
    // TODO: 280 bytes
}

// 0x8023C40C (308 bytes)
// XmlAttribGetString
void XmlAttribGetString() {
    // XML parsing utility
    // Calls: _XmlAttribFind(unsigned char *, unsigned char *)
    // Calls: _XmlContentChar(unsigned char *, unsigned char *)
    // TODO: 308 bytes
}

// 0x8023C540 (364 bytes)
// XmlAttribGetInteger
void XmlAttribGetInteger() {
    // XML parsing utility
    // Calls: _XmlAttribFind(unsigned char *, unsigned char *)
    // TODO: 364 bytes
}

// 0x8023C6AC (184 bytes)
// XmlAttribGetToken
void XmlAttribGetToken() {
    // XML parsing utility
    // Calls: _XmlAttribFind(unsigned char *, unsigned char *)
    // TODO: 184 bytes
}

// 0x8023C764 (420 bytes)
// XmlAttribGetDate
void XmlAttribGetDate() {
    // XML parsing utility
    // Calls: _XmlAttribFind(unsigned char *, unsigned char *)
    // Calls: _ParseNumber(unsigned char *, unsigned int *)
    // Calls: _ParseNumber(unsigned char *, unsigned int *)
    // TODO: 420 bytes
}

// 0x8023C908 (188 bytes)
// XmlConvEpoch2Date
void XmlConvEpoch2Date() {
    // XML parsing utility
    // Calls: _SecsToTime(tm *, unsigned int)
    // TODO: 188 bytes
}

// 0x8023C9C4 (140 bytes)
// GetSkuLine(void)
void GetSkuLine(void) {
    // Returns a static string pointer
    // TODO: 140 bytes
    (void)0; // stub
}

// 0x8023CA50 (72 bytes)
// GetBuidVersionLine(void)
void GetBuidVersionLine(void) {
    // Returns a static string pointer
    // TODO: 72 bytes
    (void)0; // stub
}

// 0x8023CA98 (72 bytes)
// GetSandboxLine(void)
void GetSandboxLine(void) {
    // Returns a static string pointer
    // TODO: 72 bytes
}

// 0x8023FA28 (140 bytes)
// DoFSReadHeader
// C library / SDK function - kept as asm stub for byte-matching
void DoFSReadHeader() {
    // TODO: 140 bytes of runtime code
    // Calls: SNDVDWrite_init, SNDVDWriteNoDMA_next
}

// 0x8023FAB4 (92 bytes)
// InitReadCounts
// C library / SDK function - kept as asm stub for byte-matching
void InitReadCounts() {
    // TODO: 92 bytes of runtime code
    // Calls: none
}

// 0x8023FB10 (140 bytes)
// PCreadAsyncNext
// C library / SDK function - kept as asm stub for byte-matching
void PCreadAsyncNext() {
    // TODO: 140 bytes of runtime code
    // Calls: InitReadCounts, SNDVDRead_init, SNDVDReadAsync_next
}

// 0x8023FB9C (164 bytes)
// PCreadAsyncInit
// C library / SDK function - kept as asm stub for byte-matching
void PCreadAsyncInit() {
    // TODO: 164 bytes of runtime code
    // Calls: CompleteAsync, DoFSReadHeader
}

// 0x8023FC40 (160 bytes)
// ReadSyncNext
// C library / SDK function - kept as asm stub for byte-matching
void ReadSyncNext() {
    // TODO: 160 bytes of runtime code
    // Calls: SNQueryData, InitReadCounts, SNDVDRead_init, SNDVDReadSync_next
}

// 0x8023FCE0 (388 bytes)
// CompletePCreadAsync
// C library / SDK function - kept as asm stub for byte-matching
void CompletePCreadAsync() {
    // TODO: 388 bytes of runtime code
    // Calls: ReadSyncNext, SNDVDReadSync_next, SNDVDReadSync_next, ReadSyncNext, SNDVDReadSync_next
}

// 0x8023FE64 (168 bytes)
// PCrwAsyncFSACK
// C library / SDK function - kept as asm stub for byte-matching
void PCrwAsyncFSACK() {
    // TODO: 168 bytes of runtime code
    // Calls: SNQueryData, SNRead, SNWrite
}

// 0x8023FF0C (216 bytes)
// PCrwSyncFSACK
// C library / SDK function - kept as asm stub for byte-matching
void PCrwSyncFSACK() {
    // TODO: 216 bytes of runtime code
    // Calls: SNQueryData, SNRead, SNWrite
}

// 0x8023FFE4 (84 bytes)
// CompleteAsync
// C library / SDK function - kept as asm stub for byte-matching
void CompleteAsync() {
    // TODO: 84 bytes of runtime code
    // Calls: PCrwSyncFSACK, CompletePCreadAsync
}

// 0x80240038 (116 bytes)
// PCrwAsyncNextPh
// C library / SDK function - kept as asm stub for byte-matching
void PCrwAsyncNextPh() {
    // TODO: 116 bytes of runtime code
    // Calls: PCreadAsyncNext, PCrwAsyncFSACK
}

// 0x802400AC (316 bytes)
// EXI2TCHandler
// C library / SDK function - kept as asm stub for byte-matching
void EXI2TCHandler() {
    // TODO: 316 bytes of runtime code
    // Calls: SNDVDReadAsync_next
}

// 0x802401E8 (112 bytes)
// SNInitEXI2TCHandler
// C library / SDK function - kept as asm stub for byte-matching
void SNInitEXI2TCHandler() {
    // TODO: 112 bytes of runtime code
    // Calls: OSDisableInterrupts, __OSSetInterruptHandler, __OSUnmaskInterrupts, OSRestoreInterrupts
}

// 0x802402B0 (136 bytes)
// ForceDvdTcIrq
// C library / SDK function - kept as asm stub for byte-matching
void ForceDvdTcIrq() {
    // TODO: 136 bytes of runtime code
    // Calls: DisDvdBP, EnaDvdBP
}

// 0x80240338 (68 bytes)
// ForceDvdDeIrq
// C library / SDK function - kept as asm stub for byte-matching
void ForceDvdDeIrq() {
    // TODO: 68 bytes of runtime code
    // Calls: DisDvdBP, EnaDvdBP
}

// 0x8024037C (128 bytes)
// DvdCallback
// C library / SDK function - kept as asm stub for byte-matching
void DvdCallback() {
    // TODO: 128 bytes of runtime code
    // Calls: ForceDvdTcIrq, ForceDvdDeIrq
}

// 0x8024041C (180 bytes)
// DSIExcHandler
// C library / SDK function - kept as asm stub for byte-matching
void DSIExcHandler() {
    // TODO: 180 bytes of runtime code
    // Calls: DSIHandler
}

// 0x802404D0 (628 bytes)
// DSIHandler
// C library / SDK function - kept as asm stub for byte-matching
void DSIHandler() {
    // TODO: 628 bytes of runtime code
    // Calls: ForceDvdTcIrq, ForceDvdTcIrq, CheckSeekOffset, PCreadAsyncInit, ForceDvdDeIrq
}

// 0x80240764 (124 bytes)
// SNDVDEmuInitDSIHandler
// C library / SDK function - kept as asm stub for byte-matching
void SNDVDEmuInitDSIHandler() {
    // TODO: 124 bytes of runtime code
    // Calls: EnaDvdBP, __OSDBJUMPEND
}

// 0x802407E0 (188 bytes)
// SNDVDEmuControl
// C library / SDK function - kept as asm stub for byte-matching
void SNDVDEmuControl() {
    // TODO: 188 bytes of runtime code
    // Calls: DisDvdBP, EnaDvdBP
}

// 0x8024089C (588 bytes)
// acosf
// C library / SDK function - kept as asm stub for byte-matching
void acosf() {
    // TODO: 588 bytes of runtime code
    // Calls: sqrtf, sqrtf
}

// 0x80240AE8 (544 bytes)
// atan2f
// C library / SDK function - kept as asm stub for byte-matching
void atan2f() {
    // TODO: 544 bytes of runtime code
    // Calls: atanf, fabsf, atanf
}

// 0x80240D08 (456 bytes)
// fmodf
// C library / SDK function - kept as asm stub for byte-matching
void fmodf() {
    // TODO: 456 bytes of runtime code
    // Calls: none
}

// 0x80240ED0 (248 bytes)
// sqrtf
// C library / SDK function - kept as asm stub for byte-matching
void sqrtf() {
    // TODO: 248 bytes of runtime code
    // Calls: none
}

// 0x80240FC8 (528 bytes)
// atanf
// C library / SDK function - kept as asm stub for byte-matching
void atanf() {
    // TODO: 528 bytes of runtime code
    // Calls: fabsf
}

// 0x802411D8 (196 bytes)
// ceilf
// C library / SDK function - kept as asm stub for byte-matching
void ceilf() {
    // TODO: 196 bytes of runtime code
    // Calls: none
}

// 0x8024129C (220 bytes)
// cosf
// C library / SDK function - kept as asm stub for byte-matching
void cosf() {
    // TODO: 220 bytes of runtime code
    // Calls: __kernel_cosf, __ieee754_rem_pio2f, __kernel_cosf, __kernel_sinf, __kernel_cosf
}

// 0x8024139C (200 bytes)
// floorf
// C library / SDK function - kept as asm stub for byte-matching
void floorf() {
    // TODO: 200 bytes of runtime code
    // Calls: none
}

// 0x80241464 (220 bytes)
// sinf
// C library / SDK function - kept as asm stub for byte-matching
void sinf() {
    // TODO: 220 bytes of runtime code
    // Calls: __kernel_sinf, __ieee754_rem_pio2f, __kernel_sinf, __kernel_cosf, __kernel_sinf
}

// 0x80241540 (128 bytes)
// tanf
// C library / SDK function - kept as asm stub for byte-matching
void tanf() {
    // TODO: 128 bytes of runtime code
    // Calls: __kernel_tanf, __ieee754_rem_pio2f, __kernel_tanf
}

// 0x802415C0 (236 bytes)
// __kernel_cosf
// C library / SDK function - kept as asm stub for byte-matching
void __kernel_cosf() {
    // TODO: 236 bytes of runtime code
    // Calls: none
}

// 0x802416AC (172 bytes)
// __kernel_sinf
// C library / SDK function - kept as asm stub for byte-matching
void __kernel_sinf() {
    // TODO: 172 bytes of runtime code
    // Calls: none
}

// 0x80241758 (532 bytes)
// __kernel_tanf
// C library / SDK function - kept as asm stub for byte-matching
void __kernel_tanf() {
    // TODO: 532 bytes of runtime code
    // Calls: fabsf
}

// 0x8024196C (848 bytes)
// __ieee754_rem_pio2f
// C library / SDK function - kept as asm stub for byte-matching
void __ieee754_rem_pio2f() {
    // TODO: 848 bytes of runtime code
    // Calls: fabsf, __kernel_rem_pio2f
}

// 0x80241CBC (2180 bytes)
// __kernel_rem_pio2f
// C library / SDK function - kept as asm stub for byte-matching
void __kernel_rem_pio2f() {
    // TODO: 2180 bytes of runtime code
    // Calls: scalbnf, floorf, scalbnf, scalbnf, scalbnf
}

// 0x80242540 (284 bytes)
// scalbnf
// C library / SDK function - kept as asm stub for byte-matching
void scalbnf() {
    // TODO: 284 bytes of runtime code
    // Calls: copysignf, copysignf
}

// 0x802426A4 (148 bytes)
// fprintf
// C library / SDK function - kept as asm stub for byte-matching
void fprintf() {
    // TODO: 148 bytes of runtime code
    // Calls: vfprintf
}

// 0x80242738 (136 bytes)
// _puts_r
// C library / SDK function - kept as asm stub for byte-matching
void _puts_r() {
    // TODO: 136 bytes of runtime code
    // Calls: strlen, __sfvwrite
}

// 0x80242800 (152 bytes)
// atexit
// C library / SDK function - kept as asm stub for byte-matching
void atexit() {
    // TODO: 152 bytes of runtime code
    // Calls: malloc
}

// 0x80242898 (128 bytes)
// exit
// C library / SDK function - kept as asm stub for byte-matching
void exit() {
    // TODO: 128 bytes of runtime code
    // Calls: _exit
}

// 0x80242918 (2444 bytes)
// qsort
// C library / SDK function - kept as asm stub for byte-matching
void qsort() {
    // TODO: 2444 bytes of runtime code
    // Calls: qsort
}

// 0x802433C4 (144 bytes)
// memcmp
// C library / SDK function - kept as asm stub for byte-matching
void memcmp() {
    // TODO: 144 bytes of runtime code
    // Calls: none
}

// 0x80243454 (164 bytes)
// memcpy
// C library / SDK function - kept as asm stub for byte-matching
void memcpy() {
    // TODO: 164 bytes of runtime code
    // Calls: none
}

// 0x802434F8 (236 bytes)
// memmove
// C library / SDK function - kept as asm stub for byte-matching
void memmove() {
    // TODO: 236 bytes of runtime code
    // Calls: none
}

// 0x802435E4 (148 bytes)
// memset
// C library / SDK function - kept as asm stub for byte-matching
void memset() {
    // TODO: 148 bytes of runtime code
    // Calls: none
}

// 0x80243678 (148 bytes)
// strcasecmp
// C library / SDK function - kept as asm stub for byte-matching
void strcasecmp() {
    // TODO: 148 bytes of runtime code
    // Calls: none
}

// 0x8024370C (144 bytes)
// strcat
// C library / SDK function - kept as asm stub for byte-matching
void strcat() {
    // TODO: 144 bytes of runtime code
    // Calls: strcpy
}

// 0x8024379C (156 bytes)
// strchr
// C library / SDK function - kept as asm stub for byte-matching
void strchr() {
    // TODO: 156 bytes of runtime code
    // Calls: none
}

// 0x80243838 (168 bytes)
// strcmp
// C library / SDK function - kept as asm stub for byte-matching
void strcmp() {
    // TODO: 168 bytes of runtime code
    // Calls: none
}

// 0x802438E0 (132 bytes)
// strcpy
// C library / SDK function - kept as asm stub for byte-matching
void strcpy() {
    // TODO: 132 bytes of runtime code
    // Calls: none
}

// 0x80243964 (108 bytes)
// strlen
// C library / SDK function - kept as asm stub for byte-matching
void strlen() {
    // TODO: 108 bytes of runtime code
    // Calls: none
}

// 0x802439D0 (188 bytes)
// strncasecmp
// C library / SDK function - kept as asm stub for byte-matching
void strncasecmp() {
    // TODO: 188 bytes of runtime code
    // Calls: none
}

// 0x80243A8C (224 bytes)
// strncmp
// C library / SDK function - kept as asm stub for byte-matching
void strncmp() {
    // TODO: 224 bytes of runtime code
    // Calls: none
}

// 0x80243B6C (204 bytes)
// strncpy
// C library / SDK function - kept as asm stub for byte-matching
void strncpy() {
    // TODO: 204 bytes of runtime code
    // Calls: none
}

// 0x80243C38 (76 bytes)
// strrchr
// C library / SDK function - kept as asm stub for byte-matching
void strrchr() {
    // TODO: 76 bytes of runtime code
    // Calls: none
}

// 0x80243C84 (104 bytes)
// strstr
// C library / SDK function - kept as asm stub for byte-matching
void strstr() {
    // TODO: 104 bytes of runtime code
    // Calls: none
}

// 0x80243CEC (92 bytes)
// strround
// C library / SDK function - kept as asm stub for byte-matching
void strround() {
    // TODO: 92 bytes of runtime code
    // Calls: none
}

// 0x80243D48 (76 bytes)
// strrev
// C library / SDK function - kept as asm stub for byte-matching
void strrev() {
    // TODO: 76 bytes of runtime code
    // Calls: none
}

// 0x80243D94 (124 bytes)
// itoa
// C library / SDK function - kept as asm stub for byte-matching
void itoa() {
    // TODO: 124 bytes of runtime code
    // Calls: strrev
}

// 0x80243E10 (1256 bytes)
// fftoa
// C library / SDK function - kept as asm stub for byte-matching
void fftoa() {
    // TODO: 1256 bytes of runtime code
    // Calls: sn_floor, sn_fmod, strround, itoa
}

// 0x80244328 (212 bytes)
// _vfwrite
// C library / SDK function - kept as asm stub for byte-matching
void _vfwrite() {
    // TODO: 212 bytes of runtime code
    // Calls: write, write
}

// 0x802443FC (216 bytes)
// vfprintf
// C library / SDK function - kept as asm stub for byte-matching
void vfprintf() {
    // TODO: 216 bytes of runtime code
    // Calls: _vfprintf_r, _vfiprintf_r
}

// 0x802444D4 (5188 bytes)
// _vfprintf_r
// C library / SDK function - kept as asm stub for byte-matching
void _vfprintf_r() {
    // TODO: 5188 bytes of runtime code
    // Calls: localeconv, _mbtowc_r, memcpy, _vfwrite, sn_log10
}

// 0x80245918 (212 bytes)
// _vfwrite [2nd definition - renamed to avoid redefinition]
// C library / SDK function - kept as asm stub for byte-matching
static void _vfwrite_2() {
    // TODO: 212 bytes of runtime code
    // Calls: write, write
}

// 0x80245A28 (4852 bytes)
// _vfiprintf_r
// C library / SDK function - kept as asm stub for byte-matching
void _vfiprintf_r() {
    // TODO: 4852 bytes of runtime code
    // Calls: _mbtowc_r, memcpy, _vfwrite, memchr, strlen
}

// 0x80246D1C (436 bytes)
// _setlocale_r
// C library / SDK function - kept as asm stub for byte-matching
void _setlocale_r() {
    // TODO: 436 bytes of runtime code
    // Calls: strcmp, strcmp, strcpy, strcpy, strcmp
}

// 0x80246F30 (372 bytes)
// sn_floor
// C library / SDK function - kept as asm stub for byte-matching
void sn_floor() {
    // TODO: 372 bytes of runtime code
    // Calls: none
}

// 0x802470A4 (860 bytes)
// sn_fmod
// C library / SDK function - kept as asm stub for byte-matching
void sn_fmod() {
    // TODO: 860 bytes of runtime code
    // Calls: none
}

// 0x80247400 (764 bytes)
// sn_log
// C library / SDK function - kept as asm stub for byte-matching
void sn_log() {
    // TODO: 764 bytes of runtime code
    // Calls: none
}

// 0x802476FC (328 bytes)
// sn_log10
// C library / SDK function - kept as asm stub for byte-matching
void sn_log10() {
    // TODO: 328 bytes of runtime code
    // Calls: sn_log
}

// 0x80247844 (892 bytes)
// __sfvwrite
// C library / SDK function - kept as asm stub for byte-matching
void __sfvwrite() {
    // TODO: 892 bytes of runtime code
    // Calls: __swsetup, memmove, memmove, fflush, memmove
}

// 0x80247BC0 (232 bytes)
// __swsetup
// C library / SDK function - kept as asm stub for byte-matching
void __swsetup() {
    // TODO: 232 bytes of runtime code
    // Calls: _sn_sinit, __smakebuf
}

// 0x80247CA8 (796 bytes)
// _mbtowc_r
// C library / SDK function - kept as asm stub for byte-matching
void _mbtowc_r() {
    // TODO: 796 bytes of runtime code
    // Calls: strlen, strcmp, strcmp, strcmp
}

// 0x80247FC4 (192 bytes)
// memchr
// C library / SDK function - kept as asm stub for byte-matching
void memchr() {
    // TODO: 192 bytes of runtime code
    // Calls: none
}

// 0x80248084 (244 bytes)
// fflush
// C library / SDK function - kept as asm stub for byte-matching
void fflush() {
    // TODO: 244 bytes of runtime code
    // Calls: _fwalk, _sn_sinit
}

// 0x80248178 (92 bytes)
// snstd
// C library / SDK function - kept as asm stub for byte-matching
void snstd() {
    // TODO: 92 bytes of runtime code
    // Calls: none
}

// 0x802481D4 (176 bytes)
// _sn_sinit
// C library / SDK function - kept as asm stub for byte-matching
void _sn_sinit() {
    // TODO: 176 bytes of runtime code
    // Calls: snstd, snstd, snstd
}

// 0x80248284 (324 bytes)
// _sn_sfp
// C library / SDK function - kept as asm stub for byte-matching
void _sn_sfp() {
    // TODO: 324 bytes of runtime code
    // Calls: _sn_sinit
}

// 0x802483C8 (236 bytes)
// _fopen_r
// C library / SDK function - kept as asm stub for byte-matching
void _fopen_r() {
    // TODO: 236 bytes of runtime code
    // Calls: __sflags, _sn_sfp, _open_r, fseek
}

// 0x80248530 (996 bytes)
// fseek
// C library / SDK function - kept as asm stub for byte-matching
void fseek() {
    // TODO: 996 bytes of runtime code
    // Calls: _sn_sinit, fflush, fflush, __smakebuf, _fstat_r
}

// 0x80248914 (128 bytes)
// _fwalk
// C library / SDK function - kept as asm stub for byte-matching
void _fwalk() {
    // TODO: 128 bytes of runtime code
    // Calls: none
}

// 0x80248994 (216 bytes)
// __smakebuf
// C library / SDK function - kept as asm stub for byte-matching
void __smakebuf() {
    // TODO: 216 bytes of runtime code
    // Calls: _fstat_r
}

// 0x80248A8C (372 bytes)
// __srefill
// C library / SDK function - kept as asm stub for byte-matching
void __srefill() {
    // TODO: 372 bytes of runtime code
    // Calls: _sn_sinit, fflush, __smakebuf, _fwalk
}

// 0x80248C00 (100 bytes)
// __sread
// C library / SDK function - kept as asm stub for byte-matching
void __sread() {
    // TODO: 100 bytes of runtime code
    // Calls: _read_r
}

// 0x80248C64 (112 bytes)
// __swrite
// C library / SDK function - kept as asm stub for byte-matching
void __swrite() {
    // TODO: 112 bytes of runtime code
    // Calls: _lseek_r, _write_r
}

// 0x80248CD4 (100 bytes)
// __sseek
// C library / SDK function - kept as asm stub for byte-matching
void __sseek() {
    // TODO: 100 bytes of runtime code
    // Calls: _lseek_r
}

// 0x80248D60 (80 bytes)
// _close_r
// C library / SDK function - kept as asm stub for byte-matching
void _close_r() {
    // TODO: 80 bytes of runtime code
    // Calls: close
}

// 0x80248DB0 (88 bytes)
// _fstat_r
// C library / SDK function - kept as asm stub for byte-matching
void _fstat_r() {
    // TODO: 88 bytes of runtime code
    // Calls: fstat
}

// 0x80248E08 (88 bytes)
// _lseek_r
// C library / SDK function - kept as asm stub for byte-matching
void _lseek_r() {
    // TODO: 88 bytes of runtime code
    // Calls: lseek
}

// 0x80248E60 (92 bytes)
// _open_r
// C library / SDK function - kept as asm stub for byte-matching
void _open_r() {
    // TODO: 92 bytes of runtime code
    // Calls: open
}

// 0x80248EBC (88 bytes)
// _read_r
// C library / SDK function - kept as asm stub for byte-matching
void _read_r() {
    // TODO: 88 bytes of runtime code
    // Calls: read
}

// 0x80248F14 (88 bytes)
// _write_r
// C library / SDK function - kept as asm stub for byte-matching
void _write_r() {
    // TODO: 88 bytes of runtime code
    // Calls: write
}

// 0x80248F6C (156 bytes)
// __sflags
// C library / SDK function - kept as asm stub for byte-matching
void __sflags() {
    // TODO: 156 bytes of runtime code
    // Calls: none
}

// 0x802490C4 (1404 bytes)
// __divdi3
// C library / SDK function - kept as asm stub for byte-matching
void __divdi3() {
    // TODO: 1404 bytes of runtime code
    // Calls: none
}

// 0x80249648 (68 bytes)
// __fixsfdi
// C library / SDK function - kept as asm stub for byte-matching
void __fixsfdi() {
    // TODO: 68 bytes of runtime code
    // Calls: __fixunssfdi, __fixunssfdi
}

// 0x8024968C (440 bytes)
// __fixunssfdi
// C library / SDK function - kept as asm stub for byte-matching
void __fixunssfdi() {
    // TODO: 440 bytes of runtime code
    // Calls: __cmpdi2, __floatdidf, __floatdidf
}

// 0x80249844 (92 bytes)
// __floatdidf
// C library / SDK function - kept as asm stub for byte-matching
void __floatdidf() {
    // TODO: 92 bytes of runtime code
    // Calls: none
}

// 0x802498E0 (1332 bytes)
// __moddi3
// C library / SDK function - kept as asm stub for byte-matching
void __moddi3() {
    // TODO: 1332 bytes of runtime code
    // Calls: none
}

// 0x80249E34 (1252 bytes)
// __udivdi3
// C library / SDK function - kept as asm stub for byte-matching
void __udivdi3() {
    // TODO: 1252 bytes of runtime code
    // Calls: none
}

// 0x8024A318 (1176 bytes)
// __umoddi3
// C library / SDK function - kept as asm stub for byte-matching
void __umoddi3() {
    // TODO: 1176 bytes of runtime code
    // Calls: none
}

// 0x8024A8FC (136 bytes)
// new_eh_context
// C library / SDK function - kept as asm stub for byte-matching
void new_eh_context() {
    // TODO: 136 bytes of runtime code
    // Calls: OSPanic, __terminate, memset
}

// 0x8024AA14 (108 bytes)
// eh_context_static
// C library / SDK function - kept as asm stub for byte-matching
void eh_context_static() {
    // TODO: 108 bytes of runtime code
    // Calls: memset
}

// 0x8024AAB0 (436 bytes)
// __sjthrow
// C library / SDK function - kept as asm stub for byte-matching
void __sjthrow() {
    // TODO: 436 bytes of runtime code
    // Calls: __terminate, __terminate
}

// 0x8024AC64 (360 bytes)
// __sjpopnthrow
// C library / SDK function - kept as asm stub for byte-matching
void __sjpopnthrow() {
    // TODO: 360 bytes of runtime code
    // Calls: __terminate, __sjthrow
}

// 0x8024ADCC (100 bytes)
// __eh_rtime_match
// C library / SDK function - kept as asm stub for byte-matching
void __eh_rtime_match() {
    // TODO: 100 bytes of runtime code
    // Calls: __get_eh_info
}

// 0x8024B05C (296 bytes)
// __OSFPRInit
// C library / SDK function - kept as asm stub for byte-matching
void __OSFPRInit() {
    // TODO: 296 bytes of runtime code
    // Calls: none
}

// 0x8024B1D4 (312 bytes)
// ClearArena
// C library / SDK function - kept as asm stub for byte-matching
void ClearArena() {
    // TODO: 312 bytes of runtime code
    // Calls: OSGetResetCode, OSGetArenaHi, OSGetArenaLo, OSGetArenaLo, memset
}

// 0x8024B348 (1248 bytes)
// OSInit
// C library / SDK function - kept as asm stub for byte-matching
void OSInit() {
    // TODO: 1248 bytes of runtime code
    // Calls: __OSGetSystemTime, OSDisableInterrupts, __OSGetExecParams, PPCMtmmcr0, PPCMtmmcr1
}

// 0x8024B828 (640 bytes)
// OSExceptionInit
// C library / SDK function - kept as asm stub for byte-matching
void OSExceptionInit() {
    // TODO: 640 bytes of runtime code
    // Calls: DBPrintf, memcpy, DCFlushRangeNoSync, ICInvalidateRange, __DBIsExceptionMarked
}

// 0x8024BB00 (156 bytes)
// OSExceptionVector
// C library / SDK function - kept as asm stub for byte-matching
void OSExceptionVector() {
    // TODO: 156 bytes of runtime code
    // Calls: none
}

// 0x8024BB9C (88 bytes)
// OSDefaultExceptionHandler
// C library / SDK function - kept as asm stub for byte-matching
void OSDefaultExceptionHandler() {
    // TODO: 88 bytes of runtime code
    // Calls: none
}

// 0x8024BBF4 (84 bytes)
// __OSPSInit
// C library / SDK function - kept as asm stub for byte-matching
void __OSPSInit() {
    // TODO: 84 bytes of runtime code
    // Calls: PPCMfhid2, PPCMthid2, ICFlashInvalidate
}

// 0x8024BC88 (320 bytes)
// OSCheckAlarmQueue
// C library / SDK function - kept as asm stub for byte-matching
void OSCheckAlarmQueue() {
    // TODO: 320 bytes of runtime code
    // Calls: OSReport, OSReport, OSReport, OSReport, OSReport
}

// 0x8024BDC8 (152 bytes)
// SetTimer
// C library / SDK function - kept as asm stub for byte-matching
void SetTimer() {
    // TODO: 152 bytes of runtime code
    // Calls: __OSGetSystemTime, PPCMtdec, PPCMtdec, PPCMtdec
}

// 0x8024BE60 (88 bytes)
// OSInitAlarm
// C library / SDK function - kept as asm stub for byte-matching
void OSInitAlarm() {
    // TODO: 88 bytes of runtime code
    // Calls: __OSGetExceptionHandler, __OSDBJUMPEND, OSRegisterResetFunction
}

// 0x8024BEC8 (592 bytes)
// InsertAlarm
// C library / SDK function - kept as asm stub for byte-matching
void InsertAlarm() {
    // TODO: 592 bytes of runtime code
    // Calls: __OSGetSystemTime, __div2i, __OSGetSystemTime, PPCMtdec, PPCMtdec
}

// 0x8024C118 (104 bytes)
// OSSetAlarm
// C library / SDK function - kept as asm stub for byte-matching
void OSSetAlarm() {
    // TODO: 104 bytes of runtime code
    // Calls: OSDisableInterrupts, __OSGetSystemTime, InsertAlarm, OSRestoreInterrupts
}

// 0x8024C180 (112 bytes)
// OSSetAbsAlarm
// C library / SDK function - kept as asm stub for byte-matching
void OSSetAbsAlarm() {
    // TODO: 112 bytes of runtime code
    // Calls: OSDisableInterrupts, __OSTimeToSystemTime, InsertAlarm, OSRestoreInterrupts
}

// 0x8024C1F0 (124 bytes)
// OSSetPeriodicAlarm
// C library / SDK function - kept as asm stub for byte-matching
void OSSetPeriodicAlarm() {
    // TODO: 124 bytes of runtime code
    // Calls: OSDisableInterrupts, __OSTimeToSystemTime, InsertAlarm, OSRestoreInterrupts
}

// 0x8024C26C (284 bytes)
// OSCancelAlarm
// C library / SDK function - kept as asm stub for byte-matching
void OSCancelAlarm() {
    // TODO: 284 bytes of runtime code
    // Calls: OSDisableInterrupts, OSRestoreInterrupts, __OSGetSystemTime, PPCMtdec, PPCMtdec
}

// 0x8024C388 (560 bytes)
// DecrementerExceptionCallback
// C library / SDK function - kept as asm stub for byte-matching
void DecrementerExceptionCallback() {
    // TODO: 560 bytes of runtime code
    // Calls: __OSGetSystemTime, OSLoadContext, __OSGetSystemTime, PPCMtdec, PPCMtdec
}

// 0x8024C5B8 (80 bytes)
// DecrementerExceptionHandler
// C library / SDK function - kept as asm stub for byte-matching
void DecrementerExceptionHandler() {
    // TODO: 80 bytes of runtime code
    // Calls: none
}

// 0x8024C610 (176 bytes)
// OSCancelAlarms
// C library / SDK function - kept as asm stub for byte-matching
void OSCancelAlarms() {
    // TODO: 176 bytes of runtime code
    // Calls: OSDisableInterrupts, OSCancelAlarm, OSRestoreInterrupts
}

// 0x8024C6C0 (160 bytes)
// OnReset
// C library / SDK function - kept as asm stub for byte-matching
void OnReset() {
    // TODO: 160 bytes of runtime code
    // Calls: __DVDTestAlarm, OSCancelAlarm
}

// 0x8024C7CC (444 bytes)
// __OSInitAudioSystem
// C library / SDK function - kept as asm stub for byte-matching
void __OSInitAudioSystem() {
    // TODO: 444 bytes of runtime code
    // Calls: OSGetArenaHi, memcpy, memcpy, DCFlushRange, OSGetTick
}

// 0x8024C988 (216 bytes)
// unknown (last function in chunk, no symbol name)
// C library / SDK function - kept as asm stub for byte-matching
void _unknown_8024C988() {
    // TODO: 216 bytes of runtime code
    // Calls: none - likely SDK/OS initialization continuation
}
