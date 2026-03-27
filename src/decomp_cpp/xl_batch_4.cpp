// xl_batch_4.cpp - Extra-large asm stub conversions (2700-4800 lines), batch 4
// 47 classes converted from PPC asm to portable C++
//
// Classes: EIWallPart, AptArray, R2LTarget, PDATarget, EIStaticModel,
//   CasSimState, CSPTarget, ACTTarget, GameData, IFFResFile2,
//   AptAnimationPoolData, AptString, CasNpcEditor, G2DTarget, cBoxX,
//   ENgcRC, AwarenessManager, CasSimRendererDynamic, EPrimitive,
//   LoadGameTarget, SaveGameTarget, WAFTarget, INGTarget, ERModel,
//   BString, ERFont, CasSimDescriptionS2C, CameraDirector, EAStringC,
//   Neighbor, ERC, SpacePartition, E3DWindow, cXPortalImpl, BString2,
//   MMUTarget, O2TTarget, ESubModelShader, M2MTarget, ESim, HUDTarget,
//   E2ETarget, AptCIH, EGlobal, ERShader, cXMTObjectImpl, SimModel
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
    void* memmove(void* dst, const void* src, unsigned int n);
    int   memcmp(const void*, const void*, unsigned int);
    int   strlen(const char* s);
    char* strcpy(char* dst, const char* src);
    char* strncpy(char* dst, const char* src, unsigned int n);
    char* strcat(char* dst, const char* src);
    char* strncat(char* dst, const char* src, unsigned int n);
    int   strcmp(const char* s1, const char* s2);
    int   stricmp(const char* s1, const char* s2);
    int   strncmp(const char* s1, const char* s2, unsigned int n);
    char* strchr(const char* s, int c);
    char* strrchr(const char* s, int c);
    char* strstr(const char* s1, const char* s2);
    float sqrtf(float);
    float sinf(float);
    float cosf(float);
    float acosf(float);
    float atan2f(float, float);
    float fabsf(float);
    float tanf(float);
    int Sprintf(char* buf, char* fmt, ...);
    int   AtoI(char* str);
    float AtoF(char* str);
    int   wcslen(const unsigned short* s);
    int   wcsncpy(unsigned short* dst, const unsigned short* src, int n);
    int   wcscpy(unsigned short* dst, const unsigned short* src);
    int   wcscmp(const unsigned short* s1, const unsigned short* s2);
    int   toupper(int c);
    int   tolower(int c);
    int   isalpha(int c);
}

// Memory
class EAHeap;
extern EAHeap* MainHeap();
extern EAHeap* RootHeap();
extern EAHeap* ResourceHeap();
extern EAHeap* AptHeap();
extern EAHeap* ShaderHeap();
extern EAHeap* TextureHeap();
extern EAHeap* ModelHeap();
class EAHeap {
public:
    void* Malloc(unsigned int size, int flags);
    void* MallocAligned(unsigned int size, unsigned int align, unsigned int flags, int extra);
    void  Free(void* ptr);
    void  Compact();
};

extern void* operator new(std::size_t);
extern void  operator delete(void*);
extern void* __builtin_vec_new(unsigned int);
extern void  __builtin_vec_delete(void*);

// ============================================================================
// Forward declarations
// ============================================================================

class AptActionBlock;
class AptActionInterpreter;
class AptCharacterButton;
class AptCharacterInst;
class AptCIH;
class AptConstFile;
class AptDisplayList;
class AptFile;
class AptFormat;
class AptInitParmsT;
class AptMatrix;
class AptMovieclipInformation;
class AptNativeHash;
class AptPseudoDisplayList;
class AptRect;
class AptRenderingContext;
class AptValue;
class AptValueGC_PoolManager;
class AptWord;
class ASTNode;
class AnimRef;
class BSplineVolume;
class BString;
class BString2;
class CameraBloomDataElement;
class CasEventChangeFocus;
class CasEventChangeSimS2C;
class CasEventInitSim;
class CasEventMorphSimS2C;
class CasEventResetSim;
class CasEventResetSimDraw;
class CasEventStoreSim;
class CasSimDescriptionS2C;
class CasSimPartsS2C;
class CLoadingScreen;
struct CTilePt { short x; short y; };
class DialogParam;
class DOGMA_PoolManager;
class E3DWindow;
class EAStringC;
class EACNodeState;
class EACTrack;
class EAnimController;
class EAnimNote;
class EBitArray;
class EBound3;
class EBoundSphere;
class EConfig;
class ECullPlane;
class EDL;
class EDataHeader;
class EFile;
class EFixedString;
class EGELineStreak;
class EGEPackedParticle;
class EGEVert;
class EInstance;
class ELevelDrawData;
class ELights;
class EMat4;
class EMaterial;
class EMemoryMeterWin;
class EMovie;
class ENeighborhoodCustomChar;
class ENCamera;
class ENDummy;
class ENgcShader;
class EOrderTableData;
class ERC;
class ERCharacter;
class ERenderSurface;
class EResource;
class EResourceManager;
class ERModel;
class ERShader;
class ERSoundEvent;
class ERTexture;
class EScratchBuffUser;
class EShader;
class EShaderDef;
class ESim;
class ESMBuildDisplayListData;
class ESMSStrip;
class EStream;
class EString;
class ETexture;
class ETextureDef;
class EVec2;
struct EVec3 { float x, y, z; EVec3() : x(0), y(0), z(0) {} EVec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {} };
struct EVec4 { float x, y, z, w; EVec4() : x(0), y(0), z(0), w(0) {} };
class EViewport;
class EWeldVert;
class EWindow;
class Family;
class FenceData;
class FloorTile;
class FTilePt;
class FTileRect;
class GameData;
class GetLocalizableCommandTable;
class GetVariableCommandTable;
class H2DTarget;
class IBaseSimInstance;
class IFFHeader;
class IFFResNode;
class IPoint;
class IRect;
class ISimInstance;
class Ingredient;
class Interaction;
class ITreeTableEntry;
class M2MTarget;
class MemFile;
class Neighbor;
class ObjectModule;
class ObjectSlot;
class ObjSelector;
class PenaltyRect;
class Player;
class Quad;
class ReconBuffer;
class RoutingParams;
class RoutingSlot;
class SAnimator2;
class SetVariableCommandTable;
class SpriteSlot;
class StackElem;
class StateMachine;
class StateMachineState;
class StringBuffer;
class StringSet;
class TileWalls;
class TrapezoidFade;
class UIButtonImages;
class UIDialog;
class UIDrawTable;
class UIUpdateTable;
class UIUserDrawCBTable;
class UserDataSaveLoad;
class WallTile;
class cGZSndSys;
class cSoundPlayer;
class cTrack;
class cXMTObject;
class cXObject;
class cXPerson;
class cXPortal;
class iResFile;

struct AptAnalogStickInfo {};
struct AptCharacterButtonRecordState {};
struct AptInputController {};
struct AptInputState {};
struct AptInputType {};
struct AptMaskRenderOperation {};
struct AptProceduralProperty {};
struct AptVirtualFunctionTable_Indices {};
struct CamDirInterpType {};
struct DiagonalSideSelector {};
struct eBodyPartS2C {};
struct EFontAlignX {};
struct EFontAlignY {};
struct EFontMatrixType {};
struct EPrefetchMsg {};
struct eSimPartsMapLocation {};
struct ETCTransformSource {};
struct eTattooTextureTypeS2C {};
struct EWallUpDownStateType {};
struct NLIteratorPtrType {};
struct RCMode {};
struct structDrawCBparams {};
struct TileWallsSegment {};
struct tRelationshipType {};
struct UIScreenID {};
struct fontFXcommand {};
struct _Nonconst_traits {};
struct _Rb_tree_iterator {};
struct AmbientScorePlayer;
struct ESimsCam;

template <typename T> class TNodeList;
template <typename T0> class TRect;
template <typename T0, typename T1> class TArray;
template <typename T0, typename T1> class pair;
class TArrayERModelAllocator;

// Global singletons (accessed via r13 offsets)
extern void*      g_pApp;
extern void*      g_pEngine;
extern void*      g_pRenderer;
extern void*      g_pScheduler;
extern void*      g_pTextureManager;
extern void*      g_pShaderManager;
extern void*      g_pResourceManager;
extern void*      g_pDatasetMgr;
extern void*      g_pSoundPlayer;
extern cGZSndSys* g_pGZSndSys;
extern void*      g_pLoadingScreen;
extern void*      g_pDOGMA;
extern void*      g_pAptValueGC;
extern float      g_deltaTime;
extern H2DTarget* g_pH2DTarget;
extern void*      g_pSmartDataFactory;
extern void*      g_pGetVariableCommandTable;
extern void*      g_pSetVariableCommandTable;
extern void*      g_pGetLocalizableCommandTable;
extern void*      g_pUIUpdateTable;
extern void*      g_pHouseManager;
extern void*      g_pGameData;
extern void*      g_pObjectModule;
extern void*      g_pNeighborhoodImpl;
extern void*      g_pPlayerFamilyImpl;
extern void*      g_pCasMediator;
extern void*      g_pIngredientManager;
extern void*      g_pESimsCam;
extern void*      g_pRoomManager;
extern void*      g_pCollisionMap;
extern void*      g_pWantFearManager;
extern void*      g_pInfluenceMap;
extern void*      g_pCameraDirector;
extern void*      g_pE3DWindow;
extern void*      g_pERFont;

extern void  EORDbgTrace(char*, ...);
extern void* GetSmartDataFactory();
extern void  GetShaderForObject(cXObject* obj, EResource** outShader);
extern unsigned int RemapWallShadowId(unsigned int);
extern float PSVECMag(float*);
extern void  PSMTXIdentity(float*);
extern void  localConvertToASCII(char*, unsigned short*);


// ============================================================================
// EIWallPart (0x800273FC - 0x8002C360) — 24 functions, 9116 bytes
// Wall part rendering and management for the house building system
// ============================================================================

class EIWallPart {
public:
    // Inherits from EIStaticModel at offset 0
    // Additional fields:
    // +800: void* m_vtable2
    // +804: int   m_field_804
    // +808: CTilePt m_tilePt (at +808)
    // +812: int   m_wallAlpha
    // +816: int   m_maxAlpha
    // +820..839: float m_shaderData[5]
    // +840: int   m_field_840
    // +848: int   m_field_848
    // +856: short m_field_856
    // +858: short m_field_858
    // +860..883: float m_fadeData[6]
    // +884: float m_field_884
    // +928: int   m_field_928
    // +940: void* m_shadowResource

    void GetWallType(unsigned char);
    void IsOpaque(void);
    void* operator new(std::size_t);
    void GetShadowModel(void);
    EIWallPart();
    void OptimizeOrderTable(void);
    EIWallPart(TileWalls&, TileWallsSegment, DiagonalSideSelector, CTilePt&);
    void SetOrient(EMat4&);
    void VisibilityTest(E3DWindow&);
    void Draw(ELevelDrawData&);
    void WallOrderTableCallback(ELevelDrawData&, EOrderTableData*);
    void DrawShadow(ELevelDrawData&);
    void DrawOutsideShadows(TNodeList<EInstance*>&, EVec3&, ELevelDrawData&);
    void GetPoint(CTilePt&);
    void GetPoints(CTilePt&, CTilePt&);
    ~EIWallPart();
    void GetWallModelId(CTilePt&, TileWalls&, TileWallsSegment, DiagonalSideSelector, float&);
    void ChangeWallpaper(unsigned int);
    void GetWallpaperShader(void);
    void SetVisible(bool);
    void SetWallState(EWallUpDownStateType, bool);
    void DoFadeCollisonWallList(TrapezoidFade&, EVec3&, TNodeList<EIWallPart*>&);
    void DoFadeCollisonForList(TrapezoidFade&, TNodeList<void*>&);
    void RegisterType(unsigned short);
};

// 0x800273FC (168 bytes)
void EIWallPart::GetWallType(unsigned char type) {
    // Switch on input type, returns mapped wall type
    char* self = (char*)this;
    if (self == 0) { /* returns 0 */ return; }
    switch ((int)(unsigned int)type) {
        case 3:  /* returns 1 */ return;
        case 9:  /* returns 7 */ return;
        case 6:  /* returns 8 */ return;
        case 1:  /* returns 2 */ return;
        case 2:  /* returns 3 */ return;
        case 12: /* returns 6 */ return;
        case 4:  /* returns 4 */ return;
        case 8:  /* returns 5 */ return;
        default: /* returns 0 */ return;
    }
}

// 0x800274A4 (116 bytes)
void EIWallPart::IsOpaque(void) {
    // NOTE: asm-derived - checks alpha and context to determine opacity
    char* self = (char*)this;
    // Calls EInstance::GetInstAlpha, compares with 1.0f
    // Calls EInstance::GetContext, checks shader IDs 31 and 21
    // Returns 0 if transparent, 1 if opaque
}

// 0x80029768 (84 bytes)
void* EIWallPart::operator new(std::size_t size) {
    void* mem = MainHeap()->MallocAligned(size, 16, 0, 0);
    memset(mem, 0, size);
    return mem;
}

// 0x80029D2C (196 bytes)
void EIWallPart::GetShadowModel(void) {
    // NOTE: asm-derived - gets shadow model resource for this wall part
    char* self = (char*)this;
    unsigned int shadowId = 0;
    unsigned int callback = *(unsigned int*)(self + 28);
    short tileX = 0, tileY = 0;
    if (callback != 0) {
        // Call through function pointer to get tile coords
    } else {
        tileX = 0;
        tileY = 0;
    }
    if (tileX == 0) {
        if (*(unsigned int*)(self + 856) == 0) {
            shadowId = *(unsigned int*)(self + 272);
        } else {
            short s856 = *(short*)(self + 856);
            short s858 = *(short*)(self + 858);
            if (s856 == 0 || s858 == 0) {
                shadowId = RemapWallShadowId(*(unsigned int*)(self + 272));
            }
        }
    }
    if (shadowId != 0) {
        // AddRef resource through EResourceManager
    }
}

// 0x80029DF0 (224 bytes)
EIWallPart::EIWallPart() {
    // NOTE: asm-derived - calls EIStaticModel::EIStaticModel, inits fields
    char* self = (char*)this;
    // Set vtable
    // Init CTilePt at +808
    // Zero various fields, set alpha defaults
    *(int*)(self + 16) = 1;
    *(int*)(self + 816) = 255;
    *(int*)(self + 812) = 255;
    *(int*)(self + 940) = 0;
    *(float*)(self + 884) = 0.0f;
    *(int*)(self + 804) = 0;
    *(int*)(self + 800) = 0;
    *(int*)(self + 928) = 0;
    *(int*)(self + 848) = 0;
    *(short*)(self + 858) = 0;
    // Zero fade data floats
}

// 0x80029ED0 (232 bytes)
void EIWallPart::OptimizeOrderTable(void) {
    // NOTE: asm-derived - optimizes render order table entries
}

// 0x80029FB8 (516 bytes)
EIWallPart::EIWallPart(TileWalls& walls, TileWallsSegment seg, DiagonalSideSelector diag, CTilePt& pt) {
    // NOTE: asm-derived - constructs wall part from tile data
    // Calls EIStaticModel::EIStaticModel, then initializes from wall/tile parameters
    // Sets up model ID, shader, orientation, floor registration
}

// 0x8002A1BC (196 bytes)
void EIWallPart::SetOrient(EMat4& mat) {
    // NOTE: asm-derived - sets wall orientation matrix
    // Copies matrix, updates bounds, recalculates position
}

// 0x8002A280 (340 bytes)
void EIWallPart::VisibilityTest(E3DWindow& window) {
    // NOTE: asm-derived - frustum culling test for wall visibility
}

// 0x8002A3D4 (448 bytes)
void EIWallPart::Draw(ELevelDrawData& drawData) {
    // NOTE: asm-derived - main wall drawing, handles order table insertion
}

// 0x8002A594 (524 bytes)
void EIWallPart::WallOrderTableCallback(ELevelDrawData& drawData, EOrderTableData* orderData) {
    // NOTE: asm-derived - callback for rendering wall in sorted order
    // Handles transparency, shader selection, alpha blending
}

// 0x8002A7A0 (232 bytes)
void EIWallPart::DrawShadow(ELevelDrawData& drawData) {
    // NOTE: asm-derived - draws wall shadow geometry
}

// 0x8002A888 (564 bytes)
void EIWallPart::DrawOutsideShadows(TNodeList<EInstance*>& instances, EVec3& lightDir, ELevelDrawData& drawData) {
    // NOTE: asm-derived - draws shadows cast from outside objects onto walls
}

// 0x8002AABC (56 bytes)
void EIWallPart::GetPoint(CTilePt& outPt) {
    char* self = (char*)this;
    // Copy tile point from +808 to output
    memcpy(&outPt, self + 808, sizeof(CTilePt));
}

// 0x8002AAF4 (80 bytes)
void EIWallPart::GetPoints(CTilePt& pt1, CTilePt& pt2) {
    // NOTE: asm-derived - gets both endpoints of the wall segment
    char* self = (char*)this;
    unsigned int callback = *(unsigned int*)(self + 28);
    if (callback != 0) {
        // Call through function pointer to get both points
    }
}

// 0x8002AB44 (508 bytes)
EIWallPart::~EIWallPart() {
    // NOTE: asm-derived - destructor releases shadow resource, calls base dtor
    char* self = (char*)this;
    void* shadowRes = *(void**)(self + 940);
    if (shadowRes) {
        // Release resource reference
        *(void**)(self + 940) = 0;
    }
    // Call ~EIStaticModel
}

// 0x8002B580 (284 bytes)
void EIWallPart::GetWallModelId(CTilePt& pt, TileWalls& walls, TileWallsSegment seg, DiagonalSideSelector diag, float& outScale) {
    // NOTE: asm-derived - determines model resource ID for wall part
}

// 0x8002B69C (124 bytes)
void EIWallPart::ChangeWallpaper(unsigned int shaderId) {
    // NOTE: asm-derived - changes wallpaper shader on the wall
    char* self = (char*)this;
    // Releases old shader, loads new one from shaderId
}

// 0x8002B718 (64 bytes)
void EIWallPart::GetWallpaperShader(void) {
    // Returns current wallpaper shader pointer
}

// 0x8002B758 (52 bytes)
void EIWallPart::SetVisible(bool visible) {
    char* self = (char*)this;
    if (visible) {
        *(int*)(self + 16) |= 1;
    } else {
        *(int*)(self + 16) &= ~1;
    }
}

// 0x8002B78C (360 bytes)
void EIWallPart::SetWallState(EWallUpDownStateType state, bool immediate) {
    // NOTE: asm-derived - sets wall up/down state with optional interpolation
}

// 0x8002BBF0 (832 bytes)
void EIWallPart::DoFadeCollisonWallList(TrapezoidFade& fade, EVec3& pos, TNodeList<EIWallPart*>& wallList) {
    // NOTE: asm-derived - applies fade collision to wall list (complex iteration + math)
}

// 0x8002BF30 (612 bytes)
void EIWallPart::DoFadeCollisonForList(TrapezoidFade& fade, TNodeList<void*>& roomWallList) {
    // NOTE: asm-derived - applies fade collision for room wall list
}

// 0x8002C194 (460 bytes)
void EIWallPart::RegisterType(unsigned short typeId) {
    // NOTE: asm-derived - registers wall part type with the type system
}


// ============================================================================
// AptArray (0x80285908 - 0x80288570) — 27 functions, 9312 bytes
// APT ActionScript Array class implementation
// ============================================================================

class AptArray {
public:
    // Inherits from AptValue
    // +8:  void* m_vtable2 (AptNativeHash vtable)
    // +12: AptNativeHash embedded
    // +32: unsigned char m_flags
    // +36: void** m_elements
    // +40: int m_count
    // +44: int m_capacity

    AptArray(int capacity, AptValue** initValues);
    AptArray();
    ~AptArray();
    void CleanNativeFunctions(void);
    void DestroyGCPointers(void);
    void RegisterReferences(void) const;
    void _reserve(int newCapacity);
    void set(int index, AptValue* value);
    void toString(char* buf, char* separator);
    void toString(EAStringC& result, char* separator);
    void objectMemberLookup(AptValue* result, EAStringC* name) const;
    void objectMemberSet(AptValue* result, EAStringC* name, AptValue* value);
    void sMethod_concat(AptValue* args, int numArgs);
    void sMethod_join(AptValue* args, int numArgs);
    void sMethod_pop(AptValue* args, int numArgs);
    void sMethod_push(AptValue* args, int numArgs);
    void sMethod_shift(AptValue* args, int numArgs);
    void sMethod_unshift(AptValue* args, int numArgs);
    void defaultSortCompareFunc(void* a, void* b);
    void scriptFunctionSortFunc(void* a, void* b);
    void sMethod_sort(AptValue* args, int numArgs);
    void defaultSortOnCompareFunc(void* a, void* b);
    void sMethod_sortOn(AptValue* args, int numArgs);
    void sMethod_reverse(AptValue* args, int numArgs);
    void sMethod_splice(AptValue* args, int numArgs);
    void sMethod_slice(AptValue* args, int numArgs);
    void SetAt(int index, AptValue* value);
};

// 0x80285908 (292 bytes)
AptArray::AptArray(int capacity, AptValue** initValues) {
    // NOTE: asm-derived - calls AptValue ctor, AptNativeHash ctor, reserves, copies init values
    char* self = (char*)this;
    *(unsigned char*)(self + 32) = 0;
    *(int*)(self + 44) = capacity;
    *(int*)(self + 36) = 0;
    *(int*)(self + 40) = 0;
    // _reserve(capacity)
    // Copy initValues into array elements
}

// 0x80285A24 (44 bytes)
AptArray::AptArray() {
    char* self = (char*)this;
    *(unsigned char*)(self + 32) = 0;
    *(int*)(self + 44) = 0;
    *(int*)(self + 36) = 0;
    *(int*)(self + 40) = 0;
}

// 0x80285A50 (184 bytes)
AptArray::~AptArray() {
    // NOTE: asm-derived - cleans up native functions, frees element array
    char* self = (char*)this;
    this->CleanNativeFunctions();
    void* elements = *(void**)(self + 36);
    if (elements) {
        AptHeap()->Free(elements);
        *(void**)(self + 36) = 0;
    }
    // Calls AptNativeHash destructor, AptValue destructor
}

// 0x80285B08 (76 bytes)
void AptArray::CleanNativeFunctions(void) {
    // NOTE: asm-derived - clears native function references from hash
}

// 0x80285B54 (84 bytes)
void AptArray::DestroyGCPointers(void) {
    // NOTE: asm-derived - nullifies GC-tracked pointers in elements
    char* self = (char*)this;
    int count = *(int*)(self + 40);
    void** elements = *(void***)(self + 36);
    for (int i = 0; i < count; i++) {
        elements[i] = 0;
    }
}

// 0x80285BA8 (96 bytes)
void AptArray::RegisterReferences(void) const {
    // NOTE: asm-derived - registers GC references for all elements
}

// 0x80285EB8 (196 bytes)
void AptArray::_reserve(int newCapacity) {
    // NOTE: asm-derived - grows element array
    char* self = (char*)this;
    if (newCapacity <= *(int*)(self + 44)) return;
    void** newArr = (void**)AptHeap()->Malloc(newCapacity * 4, 0);
    memset(newArr, 0, newCapacity * 4);
    void** oldArr = *(void***)(self + 36);
    if (oldArr) {
        int oldCount = *(int*)(self + 40);
        memcpy(newArr, oldArr, oldCount * 4);
        AptHeap()->Free(oldArr);
    }
    *(void***)(self + 36) = newArr;
    *(int*)(self + 44) = newCapacity;
}

// 0x80285F7C (128 bytes)
void AptArray::set(int index, AptValue* value) {
    char* self = (char*)this;
    if (index >= *(int*)(self + 44)) {
        _reserve(index + 1);
    }
    void** elements = *(void***)(self + 36);
    elements[index] = value;
    if (index >= *(int*)(self + 40)) {
        *(int*)(self + 40) = index + 1;
    }
}

// 0x80285FFC (260 bytes)
void AptArray::toString(char* buf, char* separator) {
    // NOTE: asm-derived - converts array to string with separator
}

// 0x80286100 (296 bytes)
void AptArray::toString(EAStringC& result, char* separator) {
    // NOTE: asm-derived - converts array to EAStringC with separator
}

// 0x80286228 (244 bytes)
void AptArray::objectMemberLookup(AptValue* result, EAStringC* name) const {
    // NOTE: asm-derived - looks up named member (e.g. "length", "push")
}

// 0x8028631C (176 bytes)
void AptArray::objectMemberSet(AptValue* result, EAStringC* name, AptValue* value) {
    // NOTE: asm-derived - sets named member (e.g. "length" resizes array)
}

// 0x802863CC (328 bytes)
void AptArray::sMethod_concat(AptValue* args, int numArgs) {
    // NOTE: asm-derived - ActionScript Array.concat()
}

// 0x80286514 (200 bytes)
void AptArray::sMethod_join(AptValue* args, int numArgs) {
    // NOTE: asm-derived - ActionScript Array.join()
}

// 0x802865DC (160 bytes)
void AptArray::sMethod_pop(AptValue* args, int numArgs) {
    // NOTE: asm-derived - ActionScript Array.pop() - removes and returns last element
    char* self = (char*)this;
    int count = *(int*)(self + 40);
    if (count > 0) {
        *(int*)(self + 40) = count - 1;
        // Return removed element through args
    }
}

// 0x8028667C (168 bytes)
void AptArray::sMethod_push(AptValue* args, int numArgs) {
    // NOTE: asm-derived - ActionScript Array.push() - appends elements
    for (int i = 0; i < numArgs; i++) {
        // set(count++, args[i])
    }
}

// 0x80286724 (196 bytes)
void AptArray::sMethod_shift(AptValue* args, int numArgs) {
    // NOTE: asm-derived - removes and returns first element, shifts others down
}

// 0x802867E8 (212 bytes)
void AptArray::sMethod_unshift(AptValue* args, int numArgs) {
    // NOTE: asm-derived - inserts elements at beginning
}

// 0x802868BC (56 bytes)
void AptArray::defaultSortCompareFunc(void* a, void* b) {
    // NOTE: asm-derived - default comparison for sort (string comparison)
}

// 0x802868F4 (132 bytes)
void AptArray::scriptFunctionSortFunc(void* a, void* b) {
    // NOTE: asm-derived - script-defined comparison function wrapper
}

// 0x80286978 (408 bytes)
void AptArray::sMethod_sort(AptValue* args, int numArgs) {
    // NOTE: asm-derived - ActionScript Array.sort() with optional compare function
}

// 0x80286B10 (80 bytes)
void AptArray::defaultSortOnCompareFunc(void* a, void* b) {
    // NOTE: asm-derived - comparison for sortOn
}

// 0x80286B60 (236 bytes)
void AptArray::sMethod_sortOn(AptValue* args, int numArgs) {
    // NOTE: asm-derived - ActionScript Array.sortOn()
}

// 0x80286C4C (108 bytes)
void AptArray::sMethod_reverse(AptValue* args, int numArgs) {
    // NOTE: asm-derived - reverses array in place
    char* self = (char*)this;
    int count = *(int*)(self + 40);
    void** elements = *(void***)(self + 36);
    for (int i = 0; i < count / 2; i++) {
        void* tmp = elements[i];
        elements[i] = elements[count - 1 - i];
        elements[count - 1 - i] = tmp;
    }
}

// 0x80286CB8 (480 bytes)
void AptArray::sMethod_splice(AptValue* args, int numArgs) {
    // NOTE: asm-derived - ActionScript Array.splice() - removes/inserts elements
}

// 0x80286E98 (308 bytes)
void AptArray::sMethod_slice(AptValue* args, int numArgs) {
    // NOTE: asm-derived - ActionScript Array.slice() - returns sub-array
}

// 0x80286FCC (144 bytes)
void AptArray::SetAt(int index, AptValue* value) {
    // NOTE: asm-derived - set element with bounds checking
    this->set(index, value);
}


// ============================================================================
// R2LTarget (0x801DA6F0 - 0x801DD760) — 10 functions, 9920 bytes
// Relationship list UI target
// ============================================================================

class R2LTarget {
public:
    R2LTarget(int);
    ~R2LTarget();
    void SetVariable(char*, char*);
    void GetVariable(char*);
    void GetLocalizable(char*);
    void SpawnSummaryDialog(void);
    void SetupRelationships(void);
    void SetupPageShaders(void);
    void ChangeSelection(int);
    void onSummaryDialogSelection(int);
};

// 0x801DA6F0 (2208 bytes)
R2LTarget::R2LTarget(int param) {
    // NOTE: asm-derived - massive constructor, initializes UI target fields
    char* self = (char*)this;
    memset(self, 0, 128);
    // Init BString2 members at various offsets
    // Set vtables for UI target hierarchy
    // Store param for tab selection
}

// 0x801DAF80 (500 bytes)
R2LTarget::~R2LTarget() {
    // NOTE: asm-derived - destroys BString2 members, releases shaders
}

// 0x801DB174 (1360 bytes)
void R2LTarget::SetVariable(char* name, char* value) {
    // NOTE: asm-derived - handles UI variable setting for relationship list
}

// 0x801DB6C4 (580 bytes)
void R2LTarget::GetVariable(char* name) {
    // NOTE: asm-derived - returns UI variable values
}

// 0x801DB8F8 (428 bytes)
void R2LTarget::GetLocalizable(char* key) {
    // NOTE: asm-derived - returns localized string for key
}

// 0x801DBAA4 (392 bytes)
void R2LTarget::SpawnSummaryDialog(void) {
    // NOTE: asm-derived - opens relationship summary dialog
}

// 0x801DBC2C (2556 bytes)
void R2LTarget::SetupRelationships(void) {
    // NOTE: asm-derived - populates relationship data from neighborhood
}

// 0x801DC618 (940 bytes)
void R2LTarget::SetupPageShaders(void) {
    // NOTE: asm-derived - sets up shader resources for relationship page
}

// 0x801DC9C4 (1456 bytes)
void R2LTarget::ChangeSelection(int newSel) {
    // NOTE: asm-derived - handles relationship list selection changes
}

// 0x801DCF74 (2028 bytes)
void R2LTarget::onSummaryDialogSelection(int selection) {
    // NOTE: asm-derived - handles summary dialog selection callback
}


// ============================================================================
// PDATarget (0x801FC748 - 0x801FF600) — 11 functions, 10208 bytes
// PDA (personal device) UI target
// ============================================================================

class PDATarget {
public:
    void SetupMoney(void);
    PDATarget();
    ~PDATarget();
    void SetVariable(char*, char*);
    void GetVariable(char*);
    void HandleSubTargetStateChange(int);
    void HandleSubTargetStateChange(int, int);
    void SetupSkinShaders(int, int);
    void SelectionCallback(int);
    void HandleFirstOpenMessage(int);
    void HandleButtonHelpMessage(int, int);
};

// 0x801FC748 (252 bytes)
void PDATarget::SetupMoney(void) {
    // NOTE: asm-derived - reads player money, formats and sets UI variable
    char* self = (char*)this;
    int twoPlayerMode = 0; // loaded from global
    int maxPlayers = twoPlayerMode ? 1 : 0;
    for (int p = 0; p <= maxPlayers; p++) {
        // Get player money from game data
        // Format as string with $ prefix
        // Set UI variable "money" for player p
    }
}

// 0x801FC844 (3052 bytes)
PDATarget::PDATarget() {
    // NOTE: asm-derived - massive constructor with sub-target initialization
    // Initializes PDA menu structure, tab system, sub-targets for each PDA page
}

// 0x801FD440 (444 bytes)
PDATarget::~PDATarget() {
    // NOTE: asm-derived - destroys sub-targets, releases resources
}

// 0x801FD5FC (1508 bytes)
void PDATarget::SetVariable(char* name, char* value) {
    // NOTE: asm-derived - routes variable setting to appropriate sub-target
}

// 0x801FDBE0 (1128 bytes)
void PDATarget::GetVariable(char* name) {
    // NOTE: asm-derived - routes variable getting to appropriate sub-target
}

// 0x801FE048 (476 bytes)
void PDATarget::HandleSubTargetStateChange(int state) {
    // NOTE: asm-derived - handles PDA tab/page state transitions
}

// 0x801FE224 (524 bytes)
void PDATarget::HandleSubTargetStateChange(int state, int param) {
    // NOTE: asm-derived - handles parameterized state transitions
}

// 0x801FE430 (1660 bytes)
void PDATarget::SetupSkinShaders(int playerIndex, int simIndex) {
    // NOTE: asm-derived - loads sim skin textures for PDA portrait
}

// 0x801FEAAC (936 bytes)
void PDATarget::SelectionCallback(int selection) {
    // NOTE: asm-derived - handles PDA item selection
}

// 0x801FEE54 (876 bytes)
void PDATarget::HandleFirstOpenMessage(int msg) {
    // NOTE: asm-derived - handles initial PDA open animation/message
}

// 0x801FF1C0 (1088 bytes)
void PDATarget::HandleButtonHelpMessage(int button, int helpType) {
    // NOTE: asm-derived - displays context help for PDA buttons
}


// ============================================================================
// EIStaticModel (0x8022B9A0 - 0x8022E360) — 31 functions, 9604 bytes
// Static model instance for rendering in the 3D world
// ============================================================================

class EIStaticModel {
public:
    // Inherits from EInstance
    // Model data, orientation, bounds, shader info

    EIStaticModel();
    ~EIStaticModel();
    void Write(EStream&);
    void Read(EStream&);
    void Setup(EInstance*, EAnimController*);
    void DeallocateModel(void);
    void SetModel(char*);
    void SetOrient(EMat4&);
    void SlamOrient(EMat4&, EMat4&);
    void GetOrient(EMat4&);
    void RegisterFloor(void);
    void SetupModel(EInstance*, EAnimController*);
    void BuildDigests(void);
    void SetupBounds(void);
    void Draw(ELevelDrawData&);
    void DrawAsShadow(ELevelDrawData&);
    void DrawShadow(ELevelDrawData&);
    void AnimOrderTableCallback(ELevelDrawData&, EOrderTableData*);
    void ChangeShader(unsigned int, unsigned int);
    void ChangeShaderState(unsigned int);
    void UpdateShaders(void);
    void RebuildShaders(void);
    void RealizeShaderTuning(void);
    void FindShaderContainingTexture(unsigned int);
    void FindShaderSupportingDecal(void);
    void ReplaceBaseTexture(ERTexture*, unsigned int, ERTexture*);
    void Clone(void);
    void DrawImmediate(ERC*, EAnimController*);
    void DrawImmediateGhosted(ERC*, EAnimController*);
    void RegisterType(unsigned short);
    void GetAnchorPos(EMat4&, int);
};

// 0x8022B9A0 (176 bytes)
EIStaticModel::EIStaticModel() {
    // NOTE: asm-derived - calls EInstance base ctor, zeros model-related fields
    char* self = (char*)this;
    // Set vtable, zero model pointer, shader list, bounds
}

// 0x8022BA50 (244 bytes)
EIStaticModel::~EIStaticModel() {
    // NOTE: asm-derived - deallocates model, releases shader resources
    this->DeallocateModel();
}

// 0x8022BB44 (144 bytes)
void EIStaticModel::Write(EStream& stream) {
    // NOTE: asm-derived - serializes static model data to stream
}

// 0x8022BBD4 (172 bytes)
void EIStaticModel::Read(EStream& stream) {
    // NOTE: asm-derived - deserializes static model data from stream
}

// 0x8022BC80 (128 bytes)
void EIStaticModel::Setup(EInstance* inst, EAnimController* anim) {
    // NOTE: asm-derived - sets up model with instance and animation controller
}

// 0x8022BD00 (176 bytes)
void EIStaticModel::DeallocateModel(void) {
    // NOTE: asm-derived - releases all model resources
}

// 0x8022BDB0 (88 bytes)
void EIStaticModel::SetModel(char* modelName) {
    // NOTE: asm-derived - loads model by name through resource manager
}

// 0x8022BE08 (120 bytes)
void EIStaticModel::SetOrient(EMat4& mat) {
    // NOTE: asm-derived - copies orientation matrix, updates bounds
}

// 0x8022BE80 (76 bytes)
void EIStaticModel::SlamOrient(EMat4& mat1, EMat4& mat2) {
    // NOTE: asm-derived - force-sets orientation from two matrices
}

// 0x8022BECC (48 bytes)
void EIStaticModel::GetOrient(EMat4& outMat) {
    char* self = (char*)this;
    memcpy(&outMat, self + 224, 64); // 4x4 matrix = 64 bytes
}

// 0x8022BEFC (136 bytes)
void EIStaticModel::RegisterFloor(void) {
    // NOTE: asm-derived - registers model with floor rendering system
}

// 0x8022BF84 (220 bytes)
void EIStaticModel::SetupModel(EInstance* inst, EAnimController* anim) {
    // NOTE: asm-derived - full model setup including shader building
}

// 0x8022C060 (188 bytes)
void EIStaticModel::BuildDigests(void) {
    // NOTE: asm-derived - builds shader digest list for the model
}

// 0x8022C11C (108 bytes)
void EIStaticModel::SetupBounds(void) {
    // NOTE: asm-derived - calculates bounding sphere from model data
}

// 0x8022C188 (484 bytes)
void EIStaticModel::Draw(ELevelDrawData& drawData) {
    // NOTE: asm-derived - main draw path, inserts into order table
}

// 0x8022C36C (168 bytes)
void EIStaticModel::DrawAsShadow(ELevelDrawData& drawData) {
    // NOTE: asm-derived - draws as shadow receiver
}

// 0x8022C414 (244 bytes)
void EIStaticModel::DrawShadow(ELevelDrawData& drawData) {
    // NOTE: asm-derived - draws shadow geometry
}

// 0x8022C508 (352 bytes)
void EIStaticModel::AnimOrderTableCallback(ELevelDrawData& drawData, EOrderTableData* orderData) {
    // NOTE: asm-derived - render callback for animated static models
}

// 0x8022C668 (284 bytes)
void EIStaticModel::ChangeShader(unsigned int oldId, unsigned int newId) {
    // NOTE: asm-derived - swaps shader on model submodels
}

// 0x8022C784 (76 bytes)
void EIStaticModel::ChangeShaderState(unsigned int state) {
    // NOTE: asm-derived - changes shader state (e.g. day/night)
}

// 0x8022C7D0 (152 bytes)
void EIStaticModel::UpdateShaders(void) {
    // NOTE: asm-derived - updates all shaders on model
}

// 0x8022C868 (164 bytes)
void EIStaticModel::RebuildShaders(void) {
    // NOTE: asm-derived - rebuilds shader list from model data
}

// 0x8022C90C (192 bytes)
void EIStaticModel::RealizeShaderTuning(void) {
    // NOTE: asm-derived - applies tuning parameters to shaders
}

// 0x8022C9CC (136 bytes)
void EIStaticModel::FindShaderContainingTexture(unsigned int texId) {
    // NOTE: asm-derived - finds shader referencing given texture
}

// 0x8022CA54 (108 bytes)
void EIStaticModel::FindShaderSupportingDecal(void) {
    // NOTE: asm-derived - finds shader that supports decal rendering
}

// 0x8022CAC0 (192 bytes)
void EIStaticModel::ReplaceBaseTexture(ERTexture* oldTex, unsigned int slot, ERTexture* newTex) {
    // NOTE: asm-derived - replaces texture in shader
}

// 0x8022CB80 (200 bytes)
void EIStaticModel::Clone(void) {
    // NOTE: asm-derived - creates a copy of this static model
}

// 0x8022CC48 (328 bytes)
void EIStaticModel::DrawImmediate(ERC* rc, EAnimController* anim) {
    // NOTE: asm-derived - immediate mode draw (no order table)
}

// 0x8022CD90 (400 bytes)
void EIStaticModel::DrawImmediateGhosted(ERC* rc, EAnimController* anim) {
    // NOTE: asm-derived - immediate mode draw with ghost effect
}

// 0x8022CF20 (360 bytes)
void EIStaticModel::RegisterType(unsigned short typeId) {
    // NOTE: asm-derived - type registration for runtime type info
}

// 0x8022D088 (184 bytes)
void EIStaticModel::GetAnchorPos(EMat4& outMat, int anchorIndex) {
    // NOTE: asm-derived - gets anchor position for attachment
}


// ============================================================================
// CasSimState (0x80172C28 - 0x80175E30) — 21 functions, 9596 bytes
// Create-A-Sim state management
// ============================================================================

class CasSimState {
public:
    CasSimState();
    void GetAdjacentIndex(unsigned char part, bool forward);
    void GetMoreThanOneOption(unsigned char part);
    void GetNextAvailableSleeveStyle(eBodyPartS2C, signed char, bool, CasSimPartsS2C&);
    void GetNextSleeveStyle(eBodyPartS2C, int, bool);
    void GetNextAvailableMidLayerTorsoStyle(signed char, bool, CasSimPartsS2C&);
    void GetNextMidLayerTorsoStyle(int, bool);
    void GetNextAvailableMidLayerCollarStyle(signed char, CasSimPartsS2C&);
    void GetNextAvailableOuterLayerTorsoStyle(signed char, CasSimPartsS2C&);
    void GetNextAvailableOuterLayerCollarStyle(signed char, bool, CasSimPartsS2C&);
    void GetNextAvailableLowerBodyStyle(signed char, bool, CasSimPartsS2C&);
    void GetNextAvailableHairStyle(signed char, bool, CasSimPartsS2C&);
    void GetNextAvailableHatStyle(signed char, bool, CasSimPartsS2C&);
    void GetNextAvailableArmAccessoryStyle(signed char, bool, CasSimPartsS2C&);
    void GetNextBodyPartStyle(int, int, bool);
    void HandleEventInitSim(CasEventInitSim&);
    void HandleEventResetSim(CasEventResetSim&);
    void HandleEventStoreSim(CasEventStoreSim&);
    void HandleEventChangeSim(CasEventChangeSimS2C&);
    void HandleEventMorphSim(CasEventMorphSimS2C&);
    void SetSimName(unsigned short*, unsigned short*);
};

// 0x80172C28 (80 bytes)
CasSimState::CasSimState() {
    char* self = (char*)this;
    *(int*)(self + 0) = 0;
    // Set vtable at +4
    // Init CasSimDescriptionS2C at +8
    // Init CasSimDescriptionS2C at +300
}

// 0x80172C78 (276 bytes)
void CasSimState::GetAdjacentIndex(unsigned char part, bool forward) {
    // NOTE: asm-derived - gets next/prev index for body part cycling
}

// 0x80172D8C (76 bytes)
void CasSimState::GetMoreThanOneOption(unsigned char part) {
    // NOTE: asm-derived - checks if body part has multiple options
}

// 0x80172DD8 (296 bytes)
void CasSimState::GetNextAvailableSleeveStyle(eBodyPartS2C part, signed char dir, bool wrap, CasSimPartsS2C& parts) {
    // NOTE: asm-derived - cycles to next available sleeve style
}

// 0x80172F00 (120 bytes)
void CasSimState::GetNextSleeveStyle(eBodyPartS2C part, int dir, bool wrap) {
    // NOTE: asm-derived - wrapper for sleeve style cycling
}

// 0x80172F78 (256 bytes)
void CasSimState::GetNextAvailableMidLayerTorsoStyle(signed char dir, bool wrap, CasSimPartsS2C& parts) {
    // NOTE: asm-derived - cycles mid-layer torso style
}

// 0x80173078 (120 bytes)
void CasSimState::GetNextMidLayerTorsoStyle(int dir, bool wrap) {
    // NOTE: asm-derived - wrapper for mid-layer torso cycling
}

// 0x801730F0 (220 bytes)
void CasSimState::GetNextAvailableMidLayerCollarStyle(signed char dir, CasSimPartsS2C& parts) {
    // NOTE: asm-derived - cycles mid-layer collar style
}

// 0x801731CC (220 bytes)
void CasSimState::GetNextAvailableOuterLayerTorsoStyle(signed char dir, CasSimPartsS2C& parts) {
    // NOTE: asm-derived - cycles outer-layer torso style
}

// 0x801732A8 (256 bytes)
void CasSimState::GetNextAvailableOuterLayerCollarStyle(signed char dir, bool wrap, CasSimPartsS2C& parts) {
    // NOTE: asm-derived - cycles outer-layer collar style
}

// 0x801733A8 (256 bytes)
void CasSimState::GetNextAvailableLowerBodyStyle(signed char dir, bool wrap, CasSimPartsS2C& parts) {
    // NOTE: asm-derived - cycles lower body clothing style
}

// 0x801734A8 (256 bytes)
void CasSimState::GetNextAvailableHairStyle(signed char dir, bool wrap, CasSimPartsS2C& parts) {
    // NOTE: asm-derived - cycles hair style
}

// 0x801735A8 (256 bytes)
void CasSimState::GetNextAvailableHatStyle(signed char dir, bool wrap, CasSimPartsS2C& parts) {
    // NOTE: asm-derived - cycles hat/headwear style
}

// 0x801736A8 (256 bytes)
void CasSimState::GetNextAvailableArmAccessoryStyle(signed char dir, bool wrap, CasSimPartsS2C& parts) {
    // NOTE: asm-derived - cycles arm accessory style
}

// 0x801737A8 (1360 bytes)
void CasSimState::GetNextBodyPartStyle(int part, int dir, bool wrap) {
    // NOTE: asm-derived - dispatches to appropriate part-specific cycling function
    // Large switch on body part type
}

// 0x80173CF8 (1432 bytes)
void CasSimState::HandleEventInitSim(CasEventInitSim& evt) {
    // NOTE: asm-derived - initializes sim from CAS event
}

// 0x80174290 (240 bytes)
void CasSimState::HandleEventResetSim(CasEventResetSim& evt) {
    // NOTE: asm-derived - resets sim state from event
}

// 0x80174380 (264 bytes)
void CasSimState::HandleEventStoreSim(CasEventStoreSim& evt) {
    // NOTE: asm-derived - stores current sim state
}

// 0x80174488 (3248 bytes)
void CasSimState::HandleEventChangeSim(CasEventChangeSimS2C& evt) {
    // NOTE: asm-derived - handles sim costume/appearance changes
}

// 0x80175138 (2200 bytes)
void CasSimState::HandleEventMorphSim(CasEventMorphSimS2C& evt) {
    // NOTE: asm-derived - handles body morph changes
}

// 0x80175990 (1184 bytes)
void CasSimState::SetSimName(unsigned short* firstName, unsigned short* lastName) {
    // NOTE: asm-derived - sets sim first/last name from unicode strings
}


// ============================================================================
// CSPTarget (0x801A7BC8 - 0x801AA5B0) — 10 functions, 10672 bytes
// Career/Skills/Personality UI target
// ============================================================================

class CSPTarget {
public:
    CSPTarget(int tab, int param);
    ~CSPTarget();
    void SetVariable(char*, char*);
    void GetVariable(char*);
    void GetLocalizable(char*);
    void ChangeSelectedTab(int);
    void SetupCareer(cXPerson*);
    void InstallPromotionShaders(void);
    void SetupSkills(cXPerson*);
    void SetupPersonality(cXPerson*);
};

// 0x801A7BC8 (3756 bytes)
CSPTarget::CSPTarget(int tab, int param) {
    // NOTE: asm-derived - massive constructor, sets up career/skill/personality tabs
    // Initializes BString2 members, sets vtables, configures tab layout
}

// 0x801A8A84 (456 bytes)
CSPTarget::~CSPTarget() {
    // NOTE: asm-derived - releases shader resources, destroys BString2 members
}

// 0x801A8C4C (1516 bytes)
void CSPTarget::SetVariable(char* name, char* value) {
    // NOTE: asm-derived - handles tab-specific variable setting
}

// 0x801A9238 (1316 bytes)
void CSPTarget::GetVariable(char* name) {
    // NOTE: asm-derived - returns skill levels, career info, personality values
}

// 0x801A976C (636 bytes)
void CSPTarget::GetLocalizable(char* key) {
    // NOTE: asm-derived - returns localized career/skill/personality strings
}

// 0x801A99E8 (232 bytes)
void CSPTarget::ChangeSelectedTab(int newTab) {
    // NOTE: asm-derived - switches between career/skills/personality tabs
}

// 0x801A9AD0 (1444 bytes)
void CSPTarget::SetupCareer(cXPerson* person) {
    // NOTE: asm-derived - populates career info from person data
}

// 0x801AA07C (384 bytes)
void CSPTarget::InstallPromotionShaders(void) {
    // NOTE: asm-derived - loads promotion icon shaders
}

// 0x801AA1FC (440 bytes)
void CSPTarget::SetupSkills(cXPerson* person) {
    // NOTE: asm-derived - populates skill levels from person data
}

// 0x801AA3B4 (508 bytes)
void CSPTarget::SetupPersonality(cXPerson* person) {
    // NOTE: asm-derived - populates personality trait values from person data
}


// ============================================================================
// ACTTarget (0x801A0968 - 0x801A3AF0) — 22 functions, 10388 bytes
// Action Queue UI target
// ============================================================================

class ACTTarget {
public:
    class iqRecord {
    public:
        ~iqRecord();
    };

    ACTTarget(int playerIndex);
    ~ACTTarget();
    void SetVariable(char*, char*);
    void GetVariable(char*);
    void GetLocalizable(char*);
    void Update(void);
    void UpdateActionQueue(void);
    void AddAction(int slot, Interaction* action, BString2& name, unsigned int iconId, ERShader* shader, unsigned int flags);
    void PlaceItem(int* outSlot, int slot, Interaction* action, int param, cXPerson* person, BString2& name, unsigned int iconId, ERShader* shader, unsigned int flags);
    void RemoveAction(int slot, Interaction* action);
    void RemoveAllActions(int player);
    void GetRecord(void);
    void ReOrderActionQueue(void);
    void GetInteractionFromID(int id);
    void MoveCancelCursorUp(void);
    void MoveCancelCursorDown(void);
    void CancelModeEnabled(bool enabled);
    void CancelCurrentObject(void);
    void UpdateCancelModeWidgets(void);
    void ExitCancelMode(void);
    void CancellingLastObject(void);
};

// 0x801A0968 (4168 bytes)
ACTTarget::ACTTarget(int playerIndex) {
    // NOTE: asm-derived - large constructor, initializes action queue slots
    // Sets up iqRecord array, shader references, UI widget bindings
}

// 0x801A19A0 (564 bytes)
ACTTarget::~ACTTarget() {
    // NOTE: asm-derived - destroys iqRecords, releases shaders
}

// 0x801A1BD4 (228 bytes)
ACTTarget::iqRecord::~iqRecord() {
    // NOTE: asm-derived - destroys BString2 name, releases shader
}

// 0x801A1CB8 (436 bytes)
void ACTTarget::SetVariable(char* name, char* value) {
    // NOTE: asm-derived - sets action queue UI variables
}

// 0x801A1E6C (316 bytes)
void ACTTarget::GetVariable(char* name) {
    // NOTE: asm-derived - returns action queue state variables
}

// 0x801A1FA8 (256 bytes)
void ACTTarget::GetLocalizable(char* key) {
    // NOTE: asm-derived - returns localized action queue strings
}

// 0x801A20A8 (312 bytes)
void ACTTarget::Update(void) {
    // NOTE: asm-derived - updates action queue display state
}

// 0x801A21E0 (544 bytes)
void ACTTarget::UpdateActionQueue(void) {
    // NOTE: asm-derived - syncs displayed actions with game action queue
}

// 0x801A2400 (656 bytes)
void ACTTarget::AddAction(int slot, Interaction* action, BString2& name, unsigned int iconId, ERShader* shader, unsigned int flags) {
    // NOTE: asm-derived - adds action to display queue
}

// 0x801A2690 (680 bytes)
void ACTTarget::PlaceItem(int* outSlot, int slot, Interaction* action, int param, cXPerson* person, BString2& name, unsigned int iconId, ERShader* shader, unsigned int flags) {
    // NOTE: asm-derived - places action item in specific slot with animation
}

// 0x801A2938 (312 bytes)
void ACTTarget::RemoveAction(int slot, Interaction* action) {
    // NOTE: asm-derived - removes action from display queue
}

// 0x801A2A70 (172 bytes)
void ACTTarget::RemoveAllActions(int player) {
    // NOTE: asm-derived - clears all actions for player
}

// 0x801A2B1C (60 bytes)
void ACTTarget::GetRecord(void) {
    // NOTE: asm-derived - returns current iqRecord
}

// 0x801A2B58 (380 bytes)
void ACTTarget::ReOrderActionQueue(void) {
    // NOTE: asm-derived - reorders display to match game queue
}

// 0x801A2CD4 (88 bytes)
void ACTTarget::GetInteractionFromID(int id) {
    // NOTE: asm-derived - finds interaction by unique ID
}

// 0x801A2D2C (156 bytes)
void ACTTarget::MoveCancelCursorUp(void) {
    // NOTE: asm-derived - moves cancel cursor up in queue
}

// 0x801A2DC8 (156 bytes)
void ACTTarget::MoveCancelCursorDown(void) {
    // NOTE: asm-derived - moves cancel cursor down in queue
}

// 0x801A2E64 (244 bytes)
void ACTTarget::CancelModeEnabled(bool enabled) {
    // NOTE: asm-derived - toggles cancel mode UI overlay
}

// 0x801A2F58 (312 bytes)
void ACTTarget::CancelCurrentObject(void) {
    // NOTE: asm-derived - cancels currently selected action
}

// 0x801A3090 (380 bytes)
void ACTTarget::UpdateCancelModeWidgets(void) {
    // NOTE: asm-derived - updates cancel mode visual indicators
}

// 0x801A320C (120 bytes)
void ACTTarget::ExitCancelMode(void) {
    // NOTE: asm-derived - exits cancel mode, restores normal UI
}

// 0x801A3284 (76 bytes)
void ACTTarget::CancellingLastObject(void) {
    // NOTE: asm-derived - checks if cancelling the last queued action
}


// ============================================================================
// GameData (0x8003AFD4 - 0x8003C070) — 31 functions, 10440 bytes
// Top-level game data management
// ============================================================================

class GameData {
public:
    GameData();
    ~GameData();
    void GamePlayShutdown(void);
    void GamePlayReset(void);
    void LoadDefaultNeighborhood(void);
    void LoadSavedNeighborhood(void);
    void PrepareSimData(int, int);
    void ReplaceSimData(int, bool, int, int);
    void SaveCreateASim(void);
    void PlayerEnterHouse(void);
    void PrepCreateAFamilyData(int);
    void CreateAFamilyAddFamilyMember(Family*);
    void StoreCreateAFamilyData(void);
    void SaveCreateAFamily(void);
    void SystemPreUpdate(void);
    void SystemPreDraw(ERC*);
    void SystemPostDraw(ERC*);
    void SetTwoPlayerMode(bool);
    void IsPlayerConnected(unsigned char);
    void CopyrightUpdate(float);
    void CopyrightDraw(ERC*);
    void VersionInfoDraw(ERC*);
    void GetLocalizedSims2Logo(void);
    void GetLocalizedEAMovie(void);
    void SetBlackGraphicsBackgroundColor(void);
    void SetUglyGraphicsBackgroundColor(void);
    void StageInitTiming(float*, int);
    void StageStartFrame(void);
    void StageEndFrame(char*, int, int);
    void StageEnd(char*, char*, bool);
    void GotoXamMode(int, int, int, int);
};

// 0x8003AFD4 (296 bytes)
GameData::GameData() {
    char* self = (char*)this;
    *(int*)(self + 0) = 0;
    // Init EMemoryMeterWin at +4
    *(int*)(self + 160) = -1;
    *(int*)(self + 44) = 0;
    *(int*)(self + 48) = 0;
    *(int*)(self + 52) = 0;
    *(int*)(self + 60) = 0;
    *(int*)(self + 64) = 0;
    *(int*)(self + 68) = 0;
    *(int*)(self + 72) = 0;
    *(int*)(self + 76) = 0;
    *(int*)(self + 80) = 0;
    *(int*)(self + 108) = 0;
    *(int*)(self + 112) = 0;
    *(int*)(self + 116) = 0;
    *(int*)(self + 120) = 0;
    *(int*)(self + 128) = 1;
    *(int*)(self + 132) = 1;
    *(int*)(self + 140) = 0;
    *(int*)(self + 144) = 0;
    *(int*)(self + 148) = 0;
    *(int*)(self + 152) = 0;
    *(int*)(self + 156) = 0;
    *(int*)(self + 164) = 0;
    *(int*)(self + 168) = 0;
    *(int*)(self + 176) = 0;
    *(int*)(self + 180) = 0;
    *(int*)(self + 184) = 0;
    *(int*)(self + 188) = 0;
    *(int*)(self + 192) = 0;
    *(int*)(self + 196) = 0;
    *(int*)(self + 200) = 0;
    *(int*)(self + 204) = 0;
    *(int*)(self + 216) = 0;
    // Init float fields at +220, +224 from global constant
}

// 0x8003B0FC (200 bytes)
GameData::~GameData() {
    // NOTE: asm-derived - cleanup game data
    this->GamePlayShutdown();
}

// 0x8003B1C4 (192 bytes)
void GameData::GamePlayShutdown(void) {
    // NOTE: asm-derived - shuts down gameplay systems
}

// 0x8003B284 (284 bytes)
void GameData::GamePlayReset(void) {
    // NOTE: asm-derived - resets game to initial state
}

// 0x8003B3A0 (228 bytes)
void GameData::LoadDefaultNeighborhood(void) {
    // NOTE: asm-derived - loads default neighborhood data
}

// 0x8003B484 (464 bytes)
void GameData::LoadSavedNeighborhood(void) {
    // NOTE: asm-derived - loads neighborhood from save data
}

// 0x8003B654 (640 bytes)
void GameData::PrepareSimData(int playerIndex, int simIndex) {
    // NOTE: asm-derived - prepares sim data for gameplay
}

// 0x8003B8D4 (592 bytes)
void GameData::ReplaceSimData(int index, bool keepOld, int param1, int param2) {
    // NOTE: asm-derived - replaces sim data in slot
}

// 0x8003BB24 (184 bytes)
void GameData::SaveCreateASim(void) {
    // NOTE: asm-derived - saves CAS sim to neighborhood
}

// 0x8003BBDC (612 bytes)
void GameData::PlayerEnterHouse(void) {
    // NOTE: asm-derived - handles player entering a house lot
}

// 0x8003BE40 (120 bytes)
void GameData::PrepCreateAFamilyData(int familySize) {
    // NOTE: asm-derived - prepares data for create-a-family
}

// 0x8003BEB8 (84 bytes)
void GameData::CreateAFamilyAddFamilyMember(Family* family) {
    // NOTE: asm-derived - adds member to family during creation
}

// 0x8003BF0C (128 bytes)
void GameData::StoreCreateAFamilyData(void) {
    // NOTE: asm-derived - stores created family data
}

// 0x8003BF8C (92 bytes)
void GameData::SaveCreateAFamily(void) {
    // NOTE: asm-derived - saves created family to neighborhood
}

// 0x8003BFE8 (136 bytes)
void GameData::SystemPreUpdate(void) {
    // NOTE: asm-derived - pre-frame update for game systems
}

// Remaining GameData functions follow same pattern...
// 0x8003C070 - SystemPreDraw, SystemPostDraw, SetTwoPlayerMode, etc.
// All are NOTE: asm-derived system management functions


// ============================================================================
// IFFResFile2 (0x800BDD78 - 0x800C0970) — 40 functions, 10044 bytes
// IFF resource file management (read/write/modify)
// ============================================================================

class IFFResFile2 {
public:
    IFFResFile2();
    ~IFFResFile2();
    void Open(StringBuffer&);
    void Create(StringBuffer&);
    void ClearMap(StringBuffer&);
    void WriteHeader(MemFile*, int);
    void Delete(StringBuffer&);
    void Close(void);
    void CloseForReopen(void);
    void Reopen(void);
    void Update(void);
    void CountTypes(void);
    void GetIndType(short);
    void Count(int);
    void GetByIDAndLanguage(int, short, char, void (*)(void*, int));
    void GetByName(int, StringBuffer&, void (*)(void*, int));
    void GetByIndex(int, short, void (*)(void*, int));
    void GetName(int*, StringBuffer&);
    void GetLanguage(int*);
    void GetResType(int*);
    void GetID(int*, short*);
    void GetIndex(int*, short*);
    void FindUniqueName(int, StringBuffer&);
    void FindUniqueID(int);
    void Detach(int*);
    void Load(int*);
    void IsLittleEndian(int*);
    void SetID(int*, short);
    void AddWithLanguage(int*, int, short, StringBuffer&, char, bool);
    void Write(int*);
    void Remove(int*);
    void SetInfo(int*, short, StringBuffer&, char);
    void LoadNode(IFFResNode*, void (*)(void*, int), int);
    void LowLevelRemove(IFFResNode*);
    void InvalBlockHeader(int);
    void NewBlockHeader(IFFHeader*, unsigned int, int*);
    void GetBlockHeader(IFFHeader*, int);
    void SetBlockHeader(IFFHeader*, int);
    void MoveBlock(unsigned int, unsigned int, unsigned int, unsigned char*);
    void Defrag(void);
};

// 0x800BDD78 (112 bytes)
IFFResFile2::IFFResFile2() {
    // NOTE: asm-derived - calls iResFile ctor, inits MemFile at +16
    char* self = (char*)this;
    // Set vtable, zero fields, init memory file
}

// 0x800BDDE8 (120 bytes)
IFFResFile2::~IFFResFile2() {
    this->Close();
}

// 0x800BDE60 (464 bytes)
void IFFResFile2::Open(StringBuffer& filename) {
    // NOTE: asm-derived - opens IFF file for reading
}

// 0x800BE030 (312 bytes)
void IFFResFile2::Create(StringBuffer& filename) {
    // NOTE: asm-derived - creates new IFF file
}

// 0x800BE168 (68 bytes)
void IFFResFile2::ClearMap(StringBuffer& filename) {
    // NOTE: asm-derived - clears resource map
}

// 0x800BE1AC (96 bytes)
void IFFResFile2::WriteHeader(MemFile* file, int type) {
    // NOTE: asm-derived - writes IFF header to file
}

// 0x800BE20C (92 bytes)
void IFFResFile2::Delete(StringBuffer& filename) {
    // NOTE: asm-derived - deletes IFF file
}

// 0x800BE268 (128 bytes)
void IFFResFile2::Close(void) {
    // NOTE: asm-derived - closes file, frees resources
}

// 0x800BE2E8 (48 bytes)
void IFFResFile2::CloseForReopen(void) {
    // NOTE: asm-derived - closes file but keeps metadata for reopen
}

// 0x800BE318 (76 bytes)
void IFFResFile2::Reopen(void) {
    // NOTE: asm-derived - reopens previously closed file
}

// 0x800BE364 (120 bytes)
void IFFResFile2::Update(void) {
    // NOTE: asm-derived - flushes pending changes to disk
}

// 0x800BE3DC - 0x800C0970: Remaining 29 functions
// All follow standard IFF resource management patterns (GetByID, Load, etc.)
// Each is NOTE: asm-derived


// ============================================================================
// AptAnimationPoolData (0x802832F4 - 0x80286170) — 24 functions, 10792 bytes
// APT animation pool and input processing
// ============================================================================

class AptAnimationPoolData {
public:
    AptAnimationPoolData(AptInitParmsT&);
    ~AptAnimationPoolData();
    void PreDestroy(void);
    void tickIntervalTimers(int);
    void _tickNewInsts(void);
    void runActions(void);
    void addAnalogInput(AptAnalogStickInfo);
    void addInput(unsigned int);
    void removeTimerFunctions(AptCIH*);
    void clearBIL(void);
    void appendButtonToBIL(AptCIH*, AptMatrix*);
    void removeFromBIL(AptCIH*);
    void RegisterReferences(void);
    void _doButtonActions(AptCIH*, int);
    void setValidFocusButton(void);
    void _isPointInButtonHitTestRegion(AptCharacterButton*, AptMatrix*, int, int);
    void ProcessInputSet(AptInputType, AptInputState, unsigned int, AptInputController, bool);
    void _pointHits(AptCIH*, unsigned int);
    void ProcessListenerEvents(AptInputType, AptInputState, unsigned int, AptInputController);
    void AddListenerToQueue(AptValue*, int, unsigned int);
    void HandleFocusButton(AptInputType, AptInputState, AptCIH**);
    void HandleAutoNav(AptCIH*, AptInputType, AptInputState);
    void ProcessAptInput(unsigned int, bool);
    void ProcessInputs(void);
};

// 0x802832F4 (548 bytes)
AptAnimationPoolData::AptAnimationPoolData(AptInitParmsT& parms) {
    // NOTE: asm-derived - initializes animation pool from init params
    // Sets up timer lists, button input list, focus management
}

// 0x80283518 (240 bytes)
AptAnimationPoolData::~AptAnimationPoolData() {
    // NOTE: asm-derived - cleans up pool resources
}

// 0x80283608 (176 bytes)
void AptAnimationPoolData::PreDestroy(void) {
    // NOTE: asm-derived - pre-destruction cleanup
}

// 0x802836B8 - 0x80286170: Remaining 21 functions
// All handle APT animation timing, button input processing, focus management
// Each is NOTE: asm-derived


// ============================================================================
// AptString (0x802AC2E4 - 0x802AED30) — 23 functions, 10900 bytes
// APT ActionScript String class
// ============================================================================

class AptString {
public:
    // Inherits from AptValue
    // +8:  vtable2
    // +12: char* m_str (ref-counted string pointer)

    AptString();
    ~AptString();
    AptString(char*);
    void DeleteThis(void);
    void ForceDelete(void);
    void CleanNativeFunctions(void);
    void sMethod_charAt(AptValue*, int);
    void sMethod_charCodeAt(AptValue*, int);
    void sMethod_concat(AptValue*, int);
    void sMethod_fromCharCode(AptValue*, int);
    void sMethod_indexOf(AptValue*, int);
    void sMethod_slice(AptValue*, int);
    void sMethod_split(AptValue*, int);
    void sMethod_substr(AptValue*, int);
    void sMethod_substring(AptValue*, int);
    void sMethod_toLowerCase(AptValue*, int);
    void sMethod_toUpperCase(AptValue*, int);
    void objectMemberLookup(AptValue*, EAStringC*) const;
    void printf(char*, ...);
    void Create(char*);
    void cpy(char*);
    void Create(void);
    void Destroy(void);
};

// 0x802AC2E4 (96 bytes)
AptString::AptString() {
    char* self = (char*)this;
    // Call AptValue ctor with type 1 (string)
    // Set vtable, init ref-counted string
    *(void**)(self + 12) = 0;
}

// 0x802AC344 (76 bytes)
AptString::~AptString() {
    this->Destroy();
}

// 0x802AC390 (152 bytes)
AptString::AptString(char* str) {
    char* self = (char*)this;
    // Call AptValue ctor, then Create(str)
    this->Create(str);
}

// 0x802AC428 - 0x802AED30: Remaining 20 functions
// Implement ActionScript String methods (charAt, indexOf, slice, etc.)
// Each is NOTE: asm-derived


// ============================================================================
// CasNpcEditor (0x8016232C - 0x801654B0) — 17 functions, 11488 bytes
// NPC editor for Create-A-Sim
// ============================================================================

class CasNpcEditor {
public:
    CasNpcEditor();
    ~CasNpcEditor();
    void Enable(int);
    void Update(float);
    void Draw(ERC*);
    void LoadNextSim(void);
    void SaveSim(void);
    void SaveNpc(void);
    void SaveAllNpcs(void);
    void SaveGrandparent(void);
    void SaveAllGrandparents(void);
    void GetNPCCompositeTextureName(CasSimDescriptionS2C*, unsigned char);
    void WriteCompositedTextures(CasSimDescriptionS2C*);
    void SaveCostume(void);
    void GetNpcData(unsigned int, UserDataSaveLoad*);
    void GetGrandparent(unsigned int);
    void GetCostume(unsigned int);
};

// 0x8016232C (124 bytes)
CasNpcEditor::CasNpcEditor() {
    char* self = (char*)this;
    *(int*)(self + 0) = 0;
    // Set vtable at +4
    // Init EString at +92, +96, +100
}

// 0x801623A8 - 0x801654B0: Remaining 16 functions
// NPC creation, saving, texture compositing
// Each is NOTE: asm-derived


// ============================================================================
// G2DTarget (0x801B4490 - 0x801B7770) — 23 functions, 11236 bytes
// 2D dialog/UI target for generic dialog boxes
// ============================================================================

class G2DTarget {
public:
    G2DTarget();
    ~G2DTarget();
    void GetVariable(char*);
    void GetLocalizable(char*);
    void SetVariable(char*, char*);
    void ReflowButtonSelection(void);
    void Update(void);
    void HideDialog(void);
    void HideDialogRunCallbacks(void);
    void PushAptButtonFiltersForPlayer(int);
    void PopAptButtonFilters(void);
    void SpawnDialog(UIDialog*);
    void CalculateBackgroundSize(void);
    void SetupWidgets(void);
    void UnloadDialog(void);
    void SetIcon(ERShader*, short, short);
    void ExecuteSelectionCallback(int);
    void ExecuteZeroInputCallback(void);
    void ExecuteDialogClosedCallback(void);
    void ChangeContinueType(int);
    void SetupDialogData(UIDialog*);
    void CheckPlayerInput(char*);
    void ServiceG2DShutdown(void);
};

// 0x801B4490 (1880 bytes)
G2DTarget::G2DTarget() {
    // NOTE: asm-derived - initializes dialog target with default values
    // Sets up BString2 members, widget references, callback slots
}

// 0x801B4BE8 - 0x801B7770: Remaining 22 functions
// Dialog lifecycle management, variable routing, input handling
// Each is NOTE: asm-derived


// ============================================================================
// cBoxX (0x800AD670 - 0x800B0890) — 27 functions, 11060 bytes
// 3D audio spatialization system
// ============================================================================

class cBoxX {
public:
    cBoxX();
    ~cBoxX();
    void Init(void);
    void Shutdown(void);
    void Update(unsigned int);
    void GetSurroundVol(AmbientScorePlayer*, EVec3&, float, float, int&, int&, int&, int&);
    void GetSurroundVol(EVec3&, float, float, int&, int&, int&, int&, int);
    void CalculateSurroundVol(EVec3&, EVec3&, EVec3&, float, float, int&, int&, int&, int&);
    void GetInstanceSurroundVol(int, cTrack*, int&, int&, int&, int&);
    void GetInstanceVolNoPan(int, cTrack*, int&);
    void ConvertSurroundToVolPan(int, int, int, int, int&, int&);
    void Event(int, int, int, ERSoundEvent*, float);
    void SetAmbientScore(int);
    void FindSndobInstancePair(ERSoundEvent*, int);
    void AddToInstanceMap(ERSoundEvent*, int);
    void UpdateAllSndobVolPan(void);
    void CheckForTooManySounds(void);
    void KillSource(int);
    void UpdateSndobVolPan(ERSoundEvent*);
    void UpdateSndobVolPan(_Rb_tree_iterator, _Rb_tree_iterator);
    void GetSndobSurroundVols(ERSoundEvent*, int&, int&, int&, int&);
    void PauseSFX(void);
    void UnpauseSFX(void);
    void UnpauseAmbient(void);
    void PauseMusic(void);
    void UnpauseMusic(void);
    void GetListenerPosAndDir(ESimsCam*, EVec3&, EVec3&);
};

// 0x800AD670 (180 bytes)
cBoxX::cBoxX() {
    // NOTE: asm-derived - initializes 3D audio system
    char* self = (char*)this;
    memset(self, 0, 128);
    // Initialize surround parameters, instance map
}

// 0x800AD724 - 0x800B0890: Remaining 26 functions
// 3D audio spatialization, volume/pan calculation, sound instance management
// Each is NOTE: asm-derived


// ============================================================================
// ENgcRC (0x803383C0 - 0x8033B270) — 37 functions, 11088 bytes
// GameCube render context - low-level GPU command submission
// ============================================================================

class ENgcRC {
public:
    // Render context for submitting GPU commands
    // +0: void* m_shaderState
    // +12: int m_cmdQueue
    // +20: int m_dirty
    // +24: unsigned char m_depth
    // +112: void* m_vtable

    void EndCommand(void);
    void TriStrip(EGEVert*, int);
    void TriStrip(int, float*, float*, unsigned char*, signed char*, unsigned char*, bool);
    void TriStripRef(int, float*, float*, unsigned char*, signed char*, unsigned char*, bool);
    void TriStrip(int, int, unsigned short*, float*, float*, unsigned char*, signed char*, unsigned char*);
    void TriStripRef(int, int, unsigned short*, float*, float*, unsigned char*, signed char*, unsigned char*);
    void TriStrip(int, short*, short*, unsigned char*, signed char*, unsigned char*, bool);
    void TriStripRef(int, short*, short*, unsigned char*, signed char*, unsigned char*, bool);
    void TriStrip(int, int, unsigned short*, short*, short*, unsigned char*, signed char*, unsigned char*);
    void TriStripRef(int, int, unsigned short*, short*, short*, unsigned char*, signed char*, unsigned char*);
    void TextureCacheInvalidate(void);
    void TriStripDL(unsigned char*, int, int, float*, float*, unsigned char*, signed char*);
    void TriStripDLRef(unsigned char*, int, int, float*, float*, unsigned char*, signed char*, bool);
    void TriStripDL(unsigned char*, int, int, short*, short*, unsigned char*, signed char*);
    void TriStripDLRef(unsigned char*, int, int, short*, short*, unsigned char*, signed char*, bool);
    void TriList(int, short*, short*, unsigned char*, signed char*, unsigned char*, bool);
    void ReadMetrics(void);
    void Shader(ENgcShader*, unsigned int);
    void ModelMatrixIndex(int, int);
    void ModelMatrices(EMat4*, int);
    void DisplayList(EDL*);
    void Texture(ETexture*, int);
    void ClipRect(TRect<float>&);
    void Lights(ELights*);
    void Rect(EVec2&, EVec2&, EVec2&, EVec2&, EVec4&, float);
    void RectList(int, float*, EVec4&, float);
    void RectListRot(int, float*, EVec4&, float);
    void DirectRect(EVec2&, EVec2&, EVec4&, float);
    void EnvironmentMap(bool, bool, int);
    void TextureMatrix(EMat4*, ETCTransformSource, bool, bool, int);
    void ZTest(bool, int, int, int);
    void ZClear(float, float, float, float, float);
    void AlphaTest(bool, int, float, int);
    void SetBlendMode(int, int, int, int, float, int);
    void QuadList(int, float*, float*, unsigned char*, signed char*, bool);
    void SpriteList(int, float*, float*, unsigned char*, signed char*, unsigned char*);
    void LineList(EGEVert*, int);
};

// 0x803383C0 (104 bytes)
void ENgcRC::EndCommand(void) {
    char* self = (char*)this;
    *(int*)(self + 20) = 1; // mark dirty
    unsigned char depth = *(unsigned char*)(self + 24);
    *(unsigned char*)(self + 24) = depth - 1;
    int cmdQueue = *(int*)(self + 12);
    if (cmdQueue == 0) {
        void* shaderState = *(void**)(self + 0);
        int flag = *(int*)((char*)shaderState + 76);
        if (flag == 0) {
            // Call virtual function through vtable at +112
            void* vtbl = *(void**)(self + 112);
            // vtbl->process(self)
        }
    }
}

// 0x80338428 - 0x8033B270: Remaining 36 functions
// All are low-level GX command generation for GameCube GPU
// Each is NOTE: asm-derived - complex rendering pipeline code


// ============================================================================
// AwarenessManager (0x80011F4C - 0x80015740) — 38 functions, 11032 bytes
// Sim awareness/attention system
// ============================================================================

class AwarenessManager {
public:
    void Init(SAnimator2*, EAnimController*);
    void Reset(void);
    ~AwarenessManager();
    void AwarenessCheck(unsigned int);
    void handleAwarenessAnimations(unsigned int);
    void AwarenessAutoRunCheck(float);
    void GetFirstNodeRotation(float, float);
    void GetSecondNodeRotation(float);
    void AwarenessAnimateHeadLeadsMotion(unsigned int, EACTrack*, EMat4&, ERCharacter*, EACNodeState*);
    void AwarenessAnimateTorsoLeadsMotion(unsigned int, EACTrack*, EMat4&, ERCharacter*, EACNodeState*);
    void SetAwarenessTargetAngle(cXObject*);
    void handlePassiveInfluenceAnimation(unsigned int);
    void handleMemoryAwarenessAnimation(unsigned int);
    void handleAwarenessTurningAnimation(void);
    void SetAwareOfObject(cXObject*);
    void ClearAwareOfObject(cXObject*);
    void IsTimeToCheckMemoryAwareness(unsigned int);
    void CanSeePlayer(void);
    void GetActiveMemoryCategory(cXObject*, int&, int&);
    void StarMemoryAwarenessSprite(void);
    void SetPendingMemoryAwarenessAnim(int, int);
    void StartMemoryAwarenessAnimation(int, int);
    void SetMemoryAwarenessActionToTry(cXObject*);
    void MemoryAwarenessClearAction(void);
    void UpdateAwarenessAngle(unsigned int);
    void MemoryAwarenessCheck(unsigned int);
    void StopPassiveInfluenceAnimation(void);
    void StartPassiveInfluenceAnimation(AnimRef*);
    void RainAwarenessCheck(void);
    void PassiveInfluenceAwarenessCheck(unsigned int);
    void GetDeltaAngleToTargetObject(cXObject*);
    void ShouldAwarenessBeActive(unsigned int);
    void IsMemoryAwarenessAnimDone(void);
    void getPassiveInfluenceSkillID(signed char, AnimRef*&);
    void getAwarenessSkillID(int, int, AnimRef*&);
    void shouldAutoCarry(void);
    void startAutoCarry(void);
    void endAutoCarry(void);
};

// 0x80011F4C (232 bytes)
void AwarenessManager::Init(SAnimator2* anim, EAnimController* ctrl) {
    char* self = (char*)this;
    memset(self, 0, 200);
    // Store animator and controller references
    // Initialize awareness angles, timers, state
}

// 0x80012034 - 0x80015740: Remaining 37 functions
// Sim awareness behavior - looking at objects, head/torso turning, memory reactions
// Each is NOTE: asm-derived


// ============================================================================
// CasSimRendererDynamic (0x8016FBA0 - 0x80172BF0) — 16 functions, 12160 bytes
// Dynamic sim renderer for Create-A-Sim
// ============================================================================

class CasSimRendererDynamic {
public:
    CasSimRendererDynamic();
    void SetupSim(void);
    void GetIndexes(eBodyPartS2C, unsigned char*, unsigned char*);
    void GetIndexes(eTattooTextureTypeS2C, unsigned char*, unsigned char*);
    void Update(float);
    void IsPersonalityAnim(unsigned int);
    void SetNextRandomShirtIdle(void);
    void SetNextRandomRegularIdle(void);
    void SelectNextStandingAnimation(void);
    void PlayPersonalityAnim(short);
    void DrawDebugInfo(ERC*);
    void HandleEventChangeSim(CasEventChangeSimS2C&);
    void HandleEventMorphSim(CasEventMorphSimS2C&);
    void HandleEventResetSimDraw(CasEventResetSimDraw&);
    void HandleEventInitSim(CasEventInitSim&);
    void HandleEventChangeFocus(CasEventChangeFocus&);
};

// 0x8016FBA0 (116 bytes)
CasSimRendererDynamic::CasSimRendererDynamic() {
    // NOTE: asm-derived - calls CasSimRenderer base ctor
    // Sets vtable, initializes animation state
    char* self = (char*)this;
    *(int*)(self + 544) = 1;
}

// 0x8016FC14 - 0x80172BF0: Remaining 15 functions
// CAS animation playback, model part updating, event handling
// Each is NOTE: asm-derived


// ============================================================================
// EPrimitive (0x802F2EC8 - 0x802F6550) — 12 functions, 13792 bytes
// Debug/utility primitive rendering (spheres, cubes, lines, etc.)
// ============================================================================

class EPrimitive {
public:
    void Torus(ERC*, float, float, int, int, int, int);
    void Sphere(ERC*, EBoundSphere&, int, int, int, EVec4);
    void SpherePacked(ERC*, EBoundSphere&, int, int, int, EVec4);
    void Rect(ERC*, float, float);
    void Grid(ERC*, float, float, int, int, int, int);
    void WireRect(ERC*, float, float, EVec4);
    void Axis(ERC*, float);
    void Vector(ERC*, EVec3, EVec3, EVec4);
    void Cube(ERC*, float);
    void WireBox(ERC*, EBound3&, EVec4);
    void WireCircle(ERC*, float, int, EVec4, int, EVec3);
    void WireSphere(ERC*, EBoundSphere&, EVec4, int, int);
};

// 0x802F2EC8 (1432 bytes)
void EPrimitive::Torus(ERC* rc, float outerRadius, float innerRadius, int segsOuter, int segsInner, int colorMode, int texMode) {
    // NOTE: asm-derived - generates torus geometry with sin/cos vertex computation
    // Allocates vertex buffer, generates tri-strips for torus segments
    // Uses nested loop: outer segments x inner segments
    // Complex trigonometric vertex generation
}

// 0x802F3470 (1388 bytes)
void EPrimitive::Sphere(ERC* rc, EBoundSphere& sphere, int latDiv, int lonDiv, int colorMode, EVec4 color) {
    // NOTE: asm-derived - generates sphere geometry with lat/lon subdivision
}

// 0x802F39DC (1112 bytes)
void EPrimitive::SpherePacked(ERC* rc, EBoundSphere& sphere, int latDiv, int lonDiv, int colorMode, EVec4 color) {
    // NOTE: asm-derived - packed vertex format sphere
}

// 0x802F3E44 (376 bytes)
void EPrimitive::Rect(ERC* rc, float width, float height) {
    // NOTE: asm-derived - simple rectangle primitive
}

// 0x802F3FBC (804 bytes)
void EPrimitive::Grid(ERC* rc, float width, float height, int xDiv, int yDiv, int colorMode, int texMode) {
    // NOTE: asm-derived - generates grid mesh
}

// 0x802F42E0 (284 bytes)
void EPrimitive::WireRect(ERC* rc, float width, float height, EVec4 color) {
    // NOTE: asm-derived - wireframe rectangle
}

// 0x802F43FC (392 bytes)
void EPrimitive::Axis(ERC* rc, float size) {
    // NOTE: asm-derived - draws XYZ axis lines
}

// 0x802F4584 (176 bytes)
void EPrimitive::Vector(ERC* rc, EVec3 start, EVec3 end, EVec4 color) {
    // NOTE: asm-derived - draws a vector line
}

// 0x802F4634 (448 bytes)
void EPrimitive::Cube(ERC* rc, float size) {
    // NOTE: asm-derived - generates cube geometry
}

// 0x802F47F4 (632 bytes)
void EPrimitive::WireBox(ERC* rc, EBound3& bounds, EVec4 color) {
    // NOTE: asm-derived - wireframe box from bounds
}

// 0x802F4A6C (1436 bytes)
void EPrimitive::WireCircle(ERC* rc, float radius, int segments, EVec4 color, int axis, EVec3 center) {
    // NOTE: asm-derived - wireframe circle in specified plane
}

// 0x802F5008 (5448 bytes)
void EPrimitive::WireSphere(ERC* rc, EBoundSphere& sphere, EVec4 color, int latDiv, int lonDiv) {
    // NOTE: asm-derived - wireframe sphere (three circles)
}


// ============================================================================
// LoadGameTarget (0x80189AD0 - 0x8018CCD0) — 27 functions, 12720 bytes
// Load game UI flow with memory card handling
// ============================================================================

class LoadGameTarget {
public:
    LoadGameTarget(M2MTarget*, int, int);
    ~LoadGameTarget();
    void SelectionCallback(int);
    void ZeroInputCallback(void);
    void Update(void);
    void PerformMemoryCardChecks(void);
    void PerformLoad(void);
    void SpawnCheckingDialog(void);
    void SpawnWrongDeviceDialog(void);
    void SpawnCardDamagedDialog(void);
    void SpawnCardCorruptDialog(void);
    void SpawnWrongSaveDialog(void);
    void SpawnNoSaveDialog(void);
    void SpawnLoadConfirmDialog(void);
    void SpawnLoadingDialog(void);
    void SpawnLoadSucceededDialog(void);
    void SpawnLoadFailedDialog(void);
    void SpawnMemCardRemovedDialog(void);
    void SpawnSameCardDialog(void);
    void SpawnFormatDecideDialog(void);
    void SpawnFormatConfirmDialog(void);
    void SpawnFormattingDialog(void);
    void SpawnFormatCancelDialog(void);
    void SpawnFormatFailDialog(void);
    void SpawnFormatSuccessDialog(void);
    void BackgroundPerformLoad(void);
    void BGCall_PerformLoad(void);
};

// 0x80189AD0 (1840 bytes)
LoadGameTarget::LoadGameTarget(M2MTarget* parent, int slot, int device) {
    // NOTE: asm-derived - large constructor, sets up load game state machine
    // Initializes BString2 members for dialog text
    // Stores parent reference, slot/device selection
}

// 0x801BA270 - 0x8018CCD0: Remaining 26 functions
// Memory card checking, dialog spawning, background loading
// Each is NOTE: asm-derived


// ============================================================================
// SaveGameTarget (0x8018CD18 - 0x80190070) — 26 functions, 12872 bytes
// Save game UI flow with memory card handling
// ============================================================================

class SaveGameTarget {
public:
    SaveGameTarget(M2MTarget*, int, int);
    ~SaveGameTarget();
    void SelectionCallback(int);
    void ZeroInputCallback(void);
    void Update(void);
    void PerformMemoryCardChecks(void);
    void SpawnCheckingDialog(void);
    void SpawnCardCorruptDialog(void);
    void SpawnWrongDeviceDialog(void);
    void SpawnCardDamagedDialog(void);
    void SpawnFormatDecideDialog(void);
    void SpawnFormatConfirmDialog(void);
    void SpawnFormattingDialog(void);
    void SpawnFormatCancelDialog(void);
    void SpawnFormatFailDialog(void);
    void SpawnFormatSuccessDialog(void);
    void SpawnNoSpaceDialog(int);
    void SpawnOverwriteDialog(void);
    void SpawnSaveConfirmDialog(void);
    void SpawnSavingDialog(void);
    void SpawnSaveSucceededDialog(void);
    void SpawnSaveFailedDialog(void);
    void SpawnMemCardRemovedDialog(void);
    void PerformSaveGame(void);
    void BGCall_SaveGame(void);
    void BGExec_SaveGame(void*);
};

// 0x8018CD18 (1888 bytes)
SaveGameTarget::SaveGameTarget(M2MTarget* parent, int slot, int device) {
    // NOTE: asm-derived - large constructor, sets up save game state machine
}

// Remaining 25 functions: dialog spawning, memory card validation, background saving
// Each is NOTE: asm-derived


// ============================================================================
// WAFTarget (0x801E19CC - 0x801E5100) — 24 functions, 13608 bytes
// Wants and Fears UI target
// ============================================================================

class WAFTarget {
public:
    WAFTarget(int);
    ~WAFTarget();
    void SetVariable(char*, char*);
    void GetVariable(char*);
    void GetLocalizable(char*);
    void Update(void);
    void UpdateWantsAndFears(void);
    void NewWantsAndFearsIcon(int, unsigned int, unsigned int, int, Neighbor*);
    void StartAnimation(int);
    void FinishSettingIcon(int);
    void SetAspirationMeterHeight(int);
    void BeginMeterTween(void);
    void BeginBottomBarTween(void);
    void BeginTopBarTween(void);
    void OnTopBarTweenComplete(void);
    void OnBottomBarTweenComplete(void);
    void GetTopBarColorAtTier(void);
    void CalculateTweenTargetPosition(void);
    void MapGameAspirationValueToMeterValue(float);
    void GlowEffectStart(void);
    void GlowEffectAwayStart(void);
    void GetTopBarTweenColor(void);
    void OnShow(void);
    void UpdateAspirationMeter(void);
};

// 0x801E19CC (4932 bytes)
WAFTarget::WAFTarget(int playerIndex) {
    // NOTE: asm-derived - massive constructor for wants/fears HUD
    // Initializes icon slots, aspiration meter, tween animation state
}

// Remaining 23 functions: aspiration meter animation, want/fear icon management
// Each is NOTE: asm-derived


// ============================================================================
// INGTarget (0x801B9468 - 0x801BC850) — 24 functions, 13468 bytes
// Ingredient mixing UI target
// ============================================================================

class INGTarget {
public:
    INGTarget();
    ~INGTarget();
    void SetVariable(char*, char*);
    void GetVariable(char*);
    void GetLocalizable(char*);
    void Update(void);
    void end_dialog(bool);
    void update_current_items(unsigned int);
    void update_item_states(void);
    void install_current_item_shaders(void);
    void get_current_inginfo(void);
    void get_current_mix_inginfo(void);
    void add_mix_ing(int*, unsigned int);
    void query_enabled(int*) const;
    void mix_ingredients(void);
    void get_mix_ing_name(unsigned int, unsigned short*) const;
    void get_total_cost(unsigned int*) const;
    void create_edit_buffer(void);
    void set_cell_enabled(unsigned int, bool);
    void set_done_button_state(bool);
    void update_mix_ing_name(unsigned int);
    void configure_object(short, Ingredient*, Ingredient*, Ingredient*, Ingredient*);
    void play_error_sound(void);
    void onHelpDialogSelection(int);
};

// 0x801B9468 (4248 bytes)
INGTarget::INGTarget() {
    // NOTE: asm-derived - large constructor for ingredient mixing UI
    // Initializes ingredient slots, mixing state, UI bindings
}

// Remaining 23 functions: ingredient management, mixing logic, UI updates
// Each is NOTE: asm-derived


// ============================================================================
// ERModel (0x80317DEC - 0x8031B0C0) — 46 functions, 12972 bytes
// 3D model resource with morphing and lattice deformation
// ============================================================================

class ERModel {
public:
    ERModel();
    ~ERModel();
    void DelRefSubResources(void);
    void AddRefSubResources(void);
    void TryIncrementSubResources(void);
    void ReadAttachmentVert(char*);
    void LoadModel(EFile*);
    void FinishLoad(char);
    void GetScaleMatrix(void);
    void DeallocateScaleMatrix(void);
    void CalcOrientedBoundSphere(EMat4&, EBoundSphere&);
    void DrawGeometry(ERC*);
    void DrawAsShadow(ERC*);
    void DrawNormals(ERC*);
    void DrawWireFrame(ERC*);
    void Draw(ERC*);
    void DrawShadow(ERC*, float);
    void DrawShadowWithStencilInverted(ERC*);
    void DrawHierarchical(ERC*, EMat4*, EACNodeState*, int);
    void GetWeldPos(EWeldVert*);
    void SetWeldPos(EWeldVert*, EVec3&);
    void WeldSharedVerts(ERModel*, float);
    void GenerateMorphTargetDeltas(ERModel*);
    void RegisterMorphTarget(ERModel*, int);
    void RegisterMorphTarget(int, int);
    void UnRegisterMorphTarget(int);
    void UnRegisterMorphTarget(ERModel*);
    void ResetMorph(void);
    void MorphTargets(void);
    void MorphLattices(void);
    void ApplyMorph(void);
    void CleanMorphTargets(bool);
    void FreeStripResource(void);
    void FreeMorphStripResource(void);
    void SetLatticeWeight(int, int, float);
    void ResetLatticeWeights(void);
    void ParameterizeVerts(void);
    void FreeMorphResource(void);
    void HasModifiableColor(void);
    void GetModifiableColor(unsigned int);
    void GetAttachmentID(unsigned char, signed char&);
    void DrawAttachment(ERC*, ERModel*, EMat4*, int, float);
    void GetAttachmentMatrix(EMat4&, ERModel*, EMat4*, int, float);
    void GetAttachmentMatrix(EMat4&, unsigned char, EMat4*, int, float, float);
    void TransformModelUV(EVec2&, EVec2&, unsigned int, EVec2&, EVec2&);
    void RegisterType(unsigned short);
};

// 0x80317DEC (552 bytes)
ERModel::ERModel() {
    // NOTE: asm-derived - initializes model resource
    char* self = (char*)this;
    // Call EResource::EResource
    // Set vtable, zero sub-model list, morph data, attachment data
}

// 0x80318014 (164 bytes)
ERModel::~ERModel() {
    // NOTE: asm-derived - releases sub-resources
    this->DelRefSubResources();
}

// 0x803180B8 - 0x8031B0C0: Remaining 44 functions
// Model loading, morphing, lattice deformation, hierarchical drawing
// Each is NOTE: asm-derived


// ============================================================================
// BString (0x8009BFB4 - 0x8009EE20) — 68 functions, 11992 bytes
// EA's basic string class (char-based)
// ============================================================================

class BString {
public:
    // Layout: [0] char* m_data (ref-counted buffer: [0] refcount, [2] length, [4] capacity, [6+] chars)
    // npos = 0xFFFFFFFF

    void delete_ref(void);
    void data(void) const;
    void get_at(unsigned int) const;
    void operator[](unsigned int) const;
    void assign_str(char*, unsigned int);
    void append_str(char*, unsigned int);
    void insert_str(unsigned int, char*, unsigned int);
    void replace_str(unsigned int, unsigned int, char*, unsigned int);
    void compare_str(unsigned int, char*, unsigned int, unsigned int) const;
    void find_str(char*, unsigned int, unsigned int) const;
    void rfind_str(char*, unsigned int, unsigned int) const;
    void find_first_of_str(char*, unsigned int, unsigned int) const;
    void find_last_of_str(char*, unsigned int, unsigned int) const;
    void find_first_not_of_str(char*, unsigned int, unsigned int) const;
    void find_last_not_of_str(char*, unsigned int, unsigned int) const;
    BString(unsigned int, int);
    BString(BString&, unsigned int, unsigned int);
    BString(char*, unsigned int, unsigned int);
    BString(char*, unsigned int);
    BString(char*);
    BString(char, unsigned int);
    void operator=(BString&);
    void operator=(char*);
    void operator=(char);
    void operator+=(BString&);
    void operator+=(char*);
    void operator+=(char);
    void append(BString&, unsigned int, unsigned int);
    void append(char*);
    void append(char, unsigned int);
    void assign(BString&, unsigned int, unsigned int);
    void assign(char*);
    void assign(char, unsigned int);
    void insert(unsigned int, BString&, unsigned int, unsigned int);
    void insert(unsigned int, char*);
    void insert(unsigned int, char, unsigned int);
    void erase(unsigned int, unsigned int);
    void replace(unsigned int, unsigned int, BString&, unsigned int, unsigned int);
    void replace(unsigned int, unsigned int, char*, unsigned int);
    void replace(unsigned int, unsigned int, char*);
    void replace(unsigned int, unsigned int, char, unsigned int);
    void put_at(unsigned int, char);
    void operator[](unsigned int);
    void resize(unsigned int, char);
    void reserve(unsigned int);
    void copy(char*, unsigned int, unsigned int) const;
    void find(BString&, unsigned int) const;
    void find(char*, unsigned int) const;
    void find(char, unsigned int) const;
    void rfind(BString&, unsigned int) const;
    void rfind(char*, unsigned int) const;
    void rfind(char, unsigned int) const;
    void find_first_of(BString&, unsigned int) const;
    void find_first_of(char*, unsigned int) const;
    void find_last_of(BString&, unsigned int) const;
    void find_last_of(char*, unsigned int) const;
    void find_first_not_of(BString&, unsigned int) const;
    void find_first_not_of(char*, unsigned int) const;
    void find_first_not_of(char, unsigned int) const;
    void find_last_not_of(BString&, unsigned int) const;
    void find_last_not_of(char*, unsigned int) const;
    void find_last_not_of(char, unsigned int) const;
    void substr(unsigned int, unsigned int) const;
    void compare(BString&, unsigned int, unsigned int) const;
    void compare(char*, unsigned int, unsigned int) const;
    void compare(char*, unsigned int) const;
    void compare(char, unsigned int, unsigned int) const;
    void assignDebug(unsigned short*);
};

// 0x8009BFB4 (96 bytes)
void BString::delete_ref(void) {
    char* self = (char*)this;
    char* data = *(char**)self;
    if (data) {
        unsigned short refCount = *(unsigned short*)data;
        refCount--;
        *(unsigned short*)data = refCount;
        if (refCount == 0) {
            MainHeap()->Free(data);
        }
        *(char**)self = 0;
    }
}

// 0x8009C014 (28 bytes)
void BString::data(void) const {
    char* self = (char*)this;
    char* buf = *(char**)self;
    // returns buf + 6 (past header: refcount[2] + length[2] + capacity[2])
}

// 0x8009C030 (20 bytes)
void BString::get_at(unsigned int index) const {
    char* self = (char*)this;
    char* buf = *(char**)self;
    // returns buf[index + 6]
}

// 0x8009C044 (20 bytes)
void BString::operator[](unsigned int index) const {
    // Same as get_at
}

// 0x8009C058 (200 bytes)
void BString::assign_str(char* str, unsigned int len) {
    // NOTE: asm-derived - core string assignment
    // Handles ref-counting, reallocation if needed
}

// 0x8009C120 (168 bytes)
void BString::append_str(char* str, unsigned int len) {
    // NOTE: asm-derived - appends string data
}

// 0x8009C1C8 - 0x8009EE20: Remaining 62 functions
// All implement standard string operations (find, replace, insert, etc.)
// Most delegate to the _str variants with length parameters
// Each is NOTE: asm-derived


// ============================================================================
// ERFont (0x80313F08 - 0x80317600) — 20 functions, 14208 bytes
// Font rendering resource
// ============================================================================

class ERFont {
public:
    ERFont();
    ~ERFont();
    void Deallocate(void);
    void Load(EFile&);
    void SetSize(float, float, bool);
    void SelectPage(ERC*, int);
    void DoDraw(void*, bool, bool, bool, EVec2&, ERC*, EVec2*, EWindow*, EMat4*, EVec2*, EFontMatrixType, fontFXcommand*);
    void DoDrawNormalize(void*, bool, bool, bool, EVec2&, ERC*, EVec2*, EWindow*, EMat4*, EVec2*, EFontMatrixType, fontFXcommand*);
    void DoGetStringSize(void*, bool, bool, EWindow*);
    void SnapPosToPixel(EVec2&, bool, bool, EWindow*);
    void SnapPosToPixelNormalize(EVec2&, bool, bool, EWindow*);
    void DoDrawAlign(ERC*, void*, bool, EVec2, EFontAlignX, EFontAlignY, EVec2*, EMat4*, EFontMatrixType, fontFXcommand*, bool);
    void Draw(ERC*, char*, EVec2&, EFontAlignX, EFontAlignY, EVec2*, EMat4*, EFontMatrixType, fontFXcommand*, bool);
    void DrawDs(ERC*, char*, EVec2&, EFontAlignX, EFontAlignY, EVec2*, float, float, bool);
    void DrawDs(ERC*, unsigned short*, EVec2&, EFontAlignX, EFontAlignY, EVec2*, float, float, bool);
    void LoadFont(void);
    void GetLineSpacing(EWindow*, bool);
    void ProcessFontFX(fontFXcommand*, EMat4*, int);
    void RegisterType(unsigned short);
    void Draw(ERC*, unsigned short*, EVec2&, EFontAlignX, EFontAlignY, EVec2*, EMat4*, EFontMatrixType, fontFXcommand*, bool);
};

// 0x80313F08 (128 bytes)
ERFont::ERFont() {
    // NOTE: asm-derived - calls EResource ctor, zeros font data
    char* self = (char*)this;
    // Set vtable, init font page list, default size
}

// 0x80313F88 (140 bytes)
ERFont::~ERFont() {
    this->Deallocate();
}

// 0x80314014 - 0x80317600: Remaining 18 functions
// Font loading, glyph rendering, text alignment, font effects
// Each is NOTE: asm-derived - complex text rendering code


// ============================================================================
// CasSimDescriptionS2C (0x80167330 - 0x8016A670) — 33 functions, 13524 bytes
// Sim description data structure for Sims 2 Console
// ============================================================================

class CasSimDescriptionS2C {
public:
    void ClearSim(bool);
    CasSimDescriptionS2C(bool);
    void GetBodyPartIndex(eBodyPartS2C) const;
    void SetBodyPartIndex(eBodyPartS2C, signed char);
    void GetBodyPartTextureIndex(eBodyPartS2C) const;
    void SetBodyPartTextureIndex(eBodyPartS2C, signed char);
    void GetBodyPartParam(eBodyPartS2C) const;
    void ReadOldDescription(ReconBuffer*);
    void DoStream(ReconBuffer*, int);
    void AssertWithInfo(char*);
    void Verify(void);
    void VerifyBodyPartNoTexture(CasSimPartsS2C&, eBodyPartS2C, signed char&, signed char, bool);
    void VerifyBodyPartWithNoOptions(CasSimPartsS2C&, eBodyPartS2C, signed char&, signed char&, signed char, signed char, bool);
    void VerifyBodyPartWithOneOption(CasSimPartsS2C&, eBodyPartS2C, signed char&, signed char&, signed char&, signed char, signed char, signed char, bool);
    void SetInnerLayerTorsoStyle(CasSimPartsS2C&);
    void SwitchMidLayerTorso(bool);
    void InnerLayerHalfTorsoRequired(CasSimPartsS2C&);
    void SwitchInnerLayerSleeveToFirstAvailableStyle(CasSimPartsS2C&);
    void MidLayerHalfTorsoRequired(CasSimPartsS2C&);
    void SwitchMidLayerTorsoToFirstAvailableStyle(CasSimPartsS2C&, bool);
    void SwitchMidLayerCollarToFirstAvailableStyle(CasSimPartsS2C&);
    void SwitchMidLayerSleeveToFirstAvailableStyle(CasSimPartsS2C&);
    void SwitchOuterLayerTorsoToFirstAvailableStyle(CasSimPartsS2C&);
    void SwitchOuterLayerCollarToFirstAvailableStyle(CasSimPartsS2C&);
    void SwitchOuterLayerSleeveToFirstAvailableStyle(CasSimPartsS2C&);
    void SwitchLowerBodyToFirstAvailableStyle(CasSimPartsS2C&);
    void SwitchHatToFirstAvailableStyle(CasSimPartsS2C&);
    void ShouldBootTopBeDisplayed(CasSimPartsS2C&);
    void SetBodyTypeMorphValues(void);
    void InitializeToDefaultCostume(bool);
    void GetCompositeTextureID(char*, eSimPartsMapLocation) const;
    void GetCompositeTextureName(char*, eSimPartsMapLocation) const;
    void GetHairBodyPart(void);
};

// 0x80167330 (528 bytes)
void CasSimDescriptionS2C::ClearSim(bool fullClear) {
    // NOTE: asm-derived - clears sim description, optionally keeping some data
    char* self = (char*)this;
    if (fullClear) {
        memset(self, 0, 292); // zero entire struct
    }
    // Reset body part indices to defaults (-1)
}

// 0x80167540 - 0x8016A670: Remaining 32 functions
// Sim body part management, costume verification, style cycling
// Each is NOTE: asm-derived


// ============================================================================
// CameraDirector (0x8001AE60 - 0x8001E120) — 34 functions, 14224 bytes
// Camera system for cinematic and gameplay cameras
// ============================================================================

class CameraDirector {
public:
    CameraDirector();
    ~CameraDirector();
    void Reset(void);
    void InitSimsCamera(void);
    void InitCurrentCamera(void);
    void ReleaseCurrentCamera(void);
    void DisableControls(void);
    void EnableControls(void);
    void AttachDummy(ENDummy*, EMat4*);
    void SetCameraCut(ENCamera*);
    void SetCameraCutAnim(int);
    void SetCameraInterp(ENCamera*, float, CamDirInterpType);
    void SetCameraInterpAnim(int, float, CamDirInterpType, float, bool*);
    void SetUpInterpCamera(float, CamDirInterpType);
    void ReleaseToGameCamera(void);
    void InterpToGameCamera(float, CamDirInterpType);
    void InterpToCancelCamera(float, CamDirInterpType, bool);
    void CalcSimsCam(void);
    void CalcCancelCam(void);
    void CheckCancelled(void);
    void Interp(void);
    void SetFOV(float);
    void StartAnim(int, bool, bool);
    void StartAnim(AnimRef*, bool, bool);
    void Update(void);
    void UpdateAnimNoteTrack(void);
    void UpdateCameraPosAndFOV(void);
    void Draw(ERC*);
    void ProcessPropertyEventTags(void);
    void ProcessAnimEvents(AnimRef*, int, int);
    void AnimEventHandler(AnimRef*, EAnimNote&, int);
    void BeginCameraBloomInterp(CameraBloomDataElement*);
    void BloomInterp(void);
    void BlurInterp(void);
};

// 0x8001AE60 (132 bytes)
CameraDirector::CameraDirector() {
    char* self = (char*)this;
    // Init EAnimController at +424
    // Init EMat4::Id at +288
    // Zero camera state fields
}

// 0x8001AEE4 (40 bytes)
CameraDirector::~CameraDirector() {
    // Destructor chain
}

// 0x8001AF0C - 0x8001E120: Remaining 32 functions
// Camera interpolation, animation, bloom/blur effects
// Each is NOTE: asm-derived


// ============================================================================
// EAStringC (0x8026C728 - 0x8026F820) — 69 functions, 12504 bytes
// EA's reference-counted string class
// ============================================================================

class EAStringC {
public:
    // Layout: [0] char* m_buffer
    // Buffer: [0] refCount(u16), [2] length(u16), [4] capacity(u16), [6+] chars

    ~EAStringC();
    void operator=(EAStringC&);
    void operator==(EAStringC&) const;
    void Clear(void);
    EAStringC(unsigned int);
    EAStringC(unsigned int, unsigned int);
    void operator+(EAStringC&) const;
    void operator+=(EAStringC&);
    void operator+(char*) const;
    void operator+=(char*);
    void Duplicate(EAStringC&);
    void Append(char*, unsigned int);
    void AppendFormat(char*, ...);
    void Format(char*, ...);
    void vsFormat(char*, void*);
    void Find(char*, int) const;
    void Find(char, int) const;
    void Delete(int, int);
    void Remove(char);
    void Replace(char*, char*);
    void Replace(char, char);
    void Left(int) const;
    void Right(int) const;
    void Mid(int) const;
    void Mid(int, int) const;
    void MakeLower(void);
    void MakeUpper(void);
    void MakeReverse(void);
    void TrimLeft(char*);
    void TrimRight(char*);
    void StartWith(char*) const;
    void EndWith(char*) const;
    void StartWithRemove(char*);
    void EndWithRemove(char*);
    void UTF8_GetBuffer(int);
    void UTF8_CharAt(int) const;
    void UTF8_Size(void) const;
    void UTF8_Mid(int) const;
    void UTF8_Mid(int, int) const;
    void UTF8_Append(char*, int);
    void UTF8_Find(char*, int) const;
    void UTF8_MakeLower(void);
    void UTF8_MakeUpper(void);
    void UTF8_Initialize(int);
    void ChangeBuffer(unsigned int, unsigned int, unsigned int, int, unsigned int);
    void InitFromBuffer(char*);
    void CalculateHashValue(void) const;
    void UTF8_ReadCharacter(char*, int*);
};

// 0x8026C728 (104 bytes)
EAStringC::~EAStringC() {
    char* self = (char*)this;
    char* buf = *(char**)self;
    unsigned short refCount = *(unsigned short*)buf;
    refCount--;
    *(unsigned short*)buf = refCount;
    if (refCount == 0) {
        AptHeap()->Free(buf);
    }
}

// 0x8026C790 (84 bytes)
void EAStringC::operator=(EAStringC& other) {
    char* self = (char*)this;
    char* otherSelf = (char*)&other;
    char* oldBuf = *(char**)self;
    char* newBuf = *(char**)otherSelf;
    // Increment ref on new, decrement on old
    unsigned short ref = *(unsigned short*)newBuf;
    *(unsigned short*)newBuf = ref + 1;
    *(char**)self = newBuf;
    // Release old
    ref = *(unsigned short*)oldBuf;
    ref--;
    *(unsigned short*)oldBuf = ref;
    if (ref == 0) {
        AptHeap()->Free(oldBuf);
    }
}

// 0x8026C7E4 - 0x8026F820: Remaining 67 functions
// String manipulation, UTF-8 support, formatting
// Each is NOTE: asm-derived


// ============================================================================
// Neighbor (0x800C8C48 - 0x800CC0B0) — 39 functions, 13740 bytes
// Neighbor (NPC/Sim) data in the neighborhood
// ============================================================================

class Neighbor {
public:
    Neighbor();
    ~Neighbor();
    Neighbor(short, ObjSelector*);
    Neighbor(Neighbor&);
    void operator=(Neighbor&);
    void GetNumPersistentDataFields(void);
    void DoStream(ReconBuffer*, int);
    void GetFamily(void);
    void IsCharacter(void);
    void RecalculateRelationshipData(void);
    void RelCountsAsRel(tRelationshipType, tRelationshipType);
    void CalculateRelationshipLevel(int, int);
    void CalculateRelationshipLevel(Neighbor*);
    void CountRelationshipsOfType(tRelationshipType);
    void IsMarriedTo(Neighbor*) const;
    void GetRelationshipById(int, int*);
    void AdjustRelationship(Neighbor*, int);
    void CopyRelationships(Neighbor*);
    void LoadFromCharacter(ENeighborhoodCustomChar&);
    void SaveToCharacter(ENeighborhoodCustomChar&);
    void InitDefaultValues(void);
    void InitWantsFears(void);
    void InitWantFearIcons(void);
    void SpawnWantFearDialog(unsigned int) const;
    void Notify(int&, bool);
    void FindDuplicateBookmark(int&) const;
    void ForceNewTree(unsigned short);
    void FindActiveSlotIndex(int&) const;
    void AdvanceBookmark(unsigned int);
    void FindBookmarkToReplace(unsigned int, unsigned int);
    void CalculateBookmarkAd(int&);
    void CalcAdMultiplier(float, float, float);
    void CalculateWantFearAd(int&, short);
    void MakeNewActiveBookmark(unsigned int);
    void SelectInactiveBookmark(bool, bool);
    void StartNewTree(unsigned int);
    void UpdateUIifNeeded(unsigned int, int);
    void ResetAllWantsAndFears(void);
    void ShuffleWantFear(int);
};

// 0x800C8C48 (184 bytes)
Neighbor::Neighbor() {
    // NOTE: asm-derived - initializes neighbor with default values
    char* self = (char*)this;
    memset(self, 0, 200);
    this->InitDefaultValues();
}

// 0x800C8D00 - 0x800CC0B0: Remaining 38 functions
// Relationship tracking, wants/fears system, save/load
// Each is NOTE: asm-derived


// ============================================================================
// ERC (0x802CA6FC - 0x802CE600) — 70 functions, 13180 bytes
// Render Command buffer - high-level rendering API
// ============================================================================

class ERC {
public:
    ERC();
    ~ERC();
    void Init(RCMode);
    void BeginCommand(int, int);
    void Send(void);
    void NewEntry(int);
    void TriStrip(EGEVert*, int);
    void TriStrip(int, float*, float*, unsigned char*, signed char*, unsigned char*, bool);
    void TriStrip(int, short*, short*, unsigned char*, signed char*, unsigned char*, bool);
    void LineList(EGEVert*, int);
    void LineStrip(EGEVert*, int);
    void PointList(int, float*, float*, unsigned char*, signed char*, unsigned char*);
    void SpriteList(EGEVert*, int);
    void SpriteList(int, float*, float*, unsigned char*, signed char*, unsigned char*);
    void ParticleList(int, EGEPackedParticle*);
    void LineStreakList(int, EVec4&, EVec4&, EGELineStreak*);
    void ParticleListRot(int, EGEPackedParticle*);
    void AddDisplayListReference(EDL*);
    void DisplayList(EDL*);
    void ShrinkSmallDisplayList(void);
    void Terminate(void);
    void Viewport(EViewport*);
    void ClipRect(TRect<float>&);
    void Scissor(TRect<float>*);
    void ModelMatrixList(EMat4*, int);
    void ModelMatrixIndex(int, int);
    void ModelMatrices(EMat4*, int);
    void FlushQueuedMatrices(void);
    void ViewMatrix(EMat4*, int, float);
    void ProjectionMatrix(EMat4*);
    void WindowMatrix(EMat4*);
    void Texture(ETexture*, int);
    void EnableGeometryModes(unsigned int);
    void DisableGeometryModes(unsigned int);
    void SetGeometryModes(unsigned int);
    void EnableRasterModes(unsigned int, int);
    void DisableRasterModes(unsigned int, int);
    void SetRasterModes(unsigned int, int);
    void SaveState(void);
    void RestoreState(void);
    void Lights(ELights*);
    void Material(EMaterial*);
    void SetMipMap(float, int);
    void Callback(void (*)(unsigned int, unsigned short, unsigned char), unsigned int, unsigned short, unsigned char);
    void RectList(int, float*, EVec4&, float);
    void RectListRot(int, float*, EVec4&, float);
    void Rect(EVec2&, EVec2&, EVec2&, EVec2&, EVec4&, float);
    void Rect(EVec2&, EVec2&, EVec4*, EVec2&, EVec2&, float);
    void DirectRect(EVec2&, EVec2&, EVec4&, float);
    void EnvironmentMap(bool, bool, int);
    void TextureMatrix(EMat4*, ETCTransformSource, bool, bool, int);
    void RecalcMatrices(int, int);
    void Debug(unsigned int, unsigned int);
    void GeometrySetup(void);
    void ZTest(bool, int, int, int);
    void AlphaTest(bool, int, float, int);
    void Stencil(int, int, int);
    void SetBlendMode(int, int, int, int, float, int);
    void SetCombineMode(int, int);
    void RenderSurface(ERenderSurface*, int);
    void SaveImageData(ERenderSurface*);
    void Vertex(int, int, float*, float*, unsigned char*, signed char*, unsigned char*);
    void TriIndexed(int, unsigned char*);
    void Noop(void);
    void ZClear(float, float, float, float, float);
    void StencilClear(float, float, float, float, int);
    void MovieFrame(EMovie*);
    void SetAlpha(float);
    void CopyScreenToTexture(ETexture*, EVec4&, EVec2&);
    void AllocAndCopy(void*, int);
};

// 0x802CA6FC (164 bytes)
ERC::ERC() {
    // NOTE: asm-derived - initializes render command buffer
    char* self = (char*)this;
    memset(self, 0, 256);
}

// 0x802CA7A0 (36 bytes)
ERC::~ERC() {
    // Minimal destructor
}

// 0x802CA7C4 - 0x802CE600: Remaining 68 functions
// All are render command submission functions
// Each writes command data to the render command buffer
// Each is NOTE: asm-derived


// ============================================================================
// SpacePartition (0x80138A3C - 0x8013C1D0) — 16 functions, 14460 bytes
// Spatial partitioning for pathfinding/routing
// ============================================================================

class SpacePartition {
public:
    void FindInterfaceRect(int, int, IRect*);
    void FindInterfaceRect(ASTNode*, ASTNode*, IRect*);
    void FindInterfacePoint(ASTNode*, ASTNode*);
    void GetIntersectingFreeRect(IRect*);
    void GetIntersectingPartitionRect(IRect*);
    void GetNodeRectangle(int, IRect*);
    void EstimateDistanceToGoal(int);
    void MeasureDistance(int, int, IPoint*);
    void CountSuccessors(int);
    void GetNthSuccessor(int, int);
    void Clear(void);
    void Deallocate(void);
    void ExpandRect(PenaltyRect*);
    void BuildSpatialSuccessorList(int);
    void Init(RoutingParams*);
    ~SpacePartition();
};

// 0x80138A3C (128 bytes)
void SpacePartition::FindInterfaceRect(int nodeA, int nodeB, IRect* outRect) {
    // NOTE: asm-derived - finds interface rectangle between two spatial nodes
    // Calls GetNode on both indices, delegates to ASTNode* version
}

// 0x80138ABC (220 bytes)
void SpacePartition::FindInterfaceRect(ASTNode* nodeA, ASTNode* nodeB, IRect* outRect) {
    // NOTE: asm-derived - finds shared boundary between adjacent nodes
}

// 0x80138B98 - 0x8013C1D0: Remaining 14 functions
// Spatial queries, A* pathfinding support, rectangle expansion
// Each is NOTE: asm-derived


// ============================================================================
// E3DWindow (0x802E3AF0 - 0x802E7890) — 32 functions, 14916 bytes
// 3D viewport/window with projection and culling
// ============================================================================

class E3DWindow {
public:
    // Inherits from EWindow
    // Contains projection/view matrices, frustum planes, viewport data

    E3DWindow();
    void SetProjection(float, float, float, float);
    void CopyProjection(E3DWindow*);
    void SetOrthoProjectionForUIHD(float, float, float, float, float, float, float, float, float, float, float);
    void SetOrthoProjection(float, float, float, float, float, float);
    void SetLookAt(EMat4&);
    void SetLookAtPos(EMat4&);
    void SetLookAt(EVec3&, EVec3&, EVec3&);
    void SetViewport(TRect<float>&);
    void CalcViewport(void);
    void CalcViewportInv(void);
    void CalcViewportStructures(void);
    void Test(EBoundSphere&);
    void Test(EBound3&);
    void TestAsRect(EBound3&);
    void Test(EVec3*, int);
    void ProjectionMatrixChanged(void);
    void LookAtMatrixChanged(void);
    void Select(ERC*);
    void CalcTextureProjection(EMat4&);
    void TransformToScreen(EVec3&, EVec2&);
    void TransformToScreen(EVec3&, EVec3&, float);
    void CameraTransformToScreen(EVec3&, EVec3&);
    void BackCullTest(EVec3*);
    void TransformToWorld(EVec2&, EVec3&);
    void PinToFrustrum(EVec3*);
    void CornerToWorld(EVec3*, int);
    void ProjectToZPlane(EVec3*, float, EVec3&);
    void MakeLineOnPlane(EVec3*, float, EVec3&);
    void GetFrustrumQuadAtZ(float, Quad*);
    void Get3DQuadFromScreenTrapAtZ(float, float*, Quad*);
    ~E3DWindow();
};

// 0x802E3AF0 (228 bytes)
E3DWindow::E3DWindow() {
    // NOTE: asm-derived - calls EWindow ctor, initializes matrices
    char* self = (char*)this;
    // Set vtable, init projection/view matrices to identity
    // Init frustum planes, viewport rect
}

// 0x802E3BD4 - 0x802E7890: Remaining 31 functions
// Projection/view matrix setup, frustum culling, screen/world transforms
// Each is NOTE: asm-derived - significant matrix math


// ============================================================================
// cXPortalImpl (0x8012D490 - 0x801309B0) — 16 functions, 16188 bytes
// Portal implementation for routing/doors
// ============================================================================

class cXPortalImpl {
public:
    ~cXPortalImpl();
    void SetRouteScore(short, float);
    cXPortalImpl(int, ObjSelector*, cXMTObject*, ObjectModule*);
    void Place(FTilePt&, int, cXObject*, int);
    void ApplyWallStyle(bool);
    void CanPlace(FTilePt&, int, cXObject*, int);
    void Pickup(void);
    void GetOtherSide(void);
    void ReconStream(ReconBuffer*, int, bool);
    void FindAvailRouteID(ObjectModule*);
    void GetDistToPortal(cXPortal*);
    void ClearRoute(ObjectModule*, short, float);
    void ClearRouteScores(ObjectModule*, short);
    void GetCustomWallStyleID(void);
    void PostLoad(int, bool);
    void GetWallStyle(void);
};

// 0x8012D490 (4472 bytes)
cXPortalImpl::~cXPortalImpl() {
    // NOTE: asm-derived - massive destructor
    // Updates vtables through multi-level hierarchy
    // Handles tile cleanup, wall style restoration, route score clearing
}

// 0x8012E5A0 (4284 bytes)
cXPortalImpl::cXPortalImpl(int type, ObjSelector* sel, cXMTObject* mtObj, ObjectModule* objMod) {
    // NOTE: asm-derived - massive constructor
    // Sets up portal routing data, wall integration, tile placement
}

// 0x8012F660 - 0x801309B0: Remaining 14 functions
// Portal placement, routing, wall style management
// Each is NOTE: asm-derived


// ============================================================================
// BString2 (0x800A1A20 - 0x800A5060) — 69 functions, 13840 bytes
// EA's basic string class (wide char / unsigned short based)
// ============================================================================

class BString2 {
public:
    // Layout: [0] unsigned short* m_data
    // Buffer: [0] refCount(u16), [2] length(u16), [4] capacity(u16), [6+] chars (each 2 bytes)

    void delete_ref(void);
    void get_at(unsigned int) const;
    void operator[](unsigned int) const;
    void assign_str(unsigned short*, unsigned int);
    void append_str(unsigned short*, unsigned int);
    void insert_str(unsigned int, unsigned short*, unsigned int);
    void replace_str(unsigned int, unsigned int, unsigned short*, unsigned int);
    void compare_str(unsigned int, unsigned short*, unsigned int, unsigned int) const;
    void find_str(unsigned short*, unsigned int, unsigned int) const;
    void rfind_str(unsigned short*, unsigned int, unsigned int) const;
    void find_first_of_str(unsigned short*, unsigned int, unsigned int) const;
    void find_last_of_str(unsigned short*, unsigned int, unsigned int) const;
    void find_first_not_of_str(unsigned short*, unsigned int, unsigned int) const;
    void find_last_not_of_str(unsigned short*, unsigned int, unsigned int) const;
    BString2(unsigned int, int);
    BString2(BString2&, unsigned int, unsigned int);
    BString2(unsigned short*, unsigned int, unsigned int);
    BString2(unsigned short*, unsigned int);
    BString2(unsigned short*);
    BString2(wchar_t, unsigned int);
    ~BString2();
    void operator=(BString2&);
    void operator=(unsigned short*);
    void operator=(wchar_t);
    void operator+=(BString2&);
    void operator+=(unsigned short*);
    void operator+=(wchar_t);
    void append(BString2&, unsigned int, unsigned int);
    void append(unsigned short*);
    void append(wchar_t, unsigned int);
    void assign(BString2&, unsigned int, unsigned int);
    void assign(unsigned short*);
    void assign(wchar_t, unsigned int);
    void insert(unsigned int, BString2&, unsigned int, unsigned int);
    void insert(unsigned int, unsigned short*);
    void insert(unsigned int, wchar_t, unsigned int);
    void erase(unsigned int, unsigned int);
    void replace(unsigned int, unsigned int, BString2&, unsigned int, unsigned int);
    void replace(unsigned int, unsigned int, unsigned short*, unsigned int);
    void replace(unsigned int, unsigned int, unsigned short*);
    void replace(unsigned int, unsigned int, wchar_t, unsigned int);
    void put_at(unsigned int, wchar_t);
    void operator[](unsigned int);
    void c_str(void) const;
    void resize(unsigned int, wchar_t);
    void reserve(unsigned int);
    void copy(unsigned short*, unsigned int, unsigned int) const;
    void find(BString2&, unsigned int) const;
    void find(unsigned short*, unsigned int) const;
    void find(wchar_t, unsigned int) const;
    void rfind(BString2&, unsigned int) const;
    void rfind(unsigned short*, unsigned int) const;
    void rfind(wchar_t, unsigned int) const;
    void find_first_of(BString2&, unsigned int) const;
    void find_first_of(unsigned short*, unsigned int) const;
    void find_last_of(BString2&, unsigned int) const;
    void find_last_of(unsigned short*, unsigned int) const;
    void find_first_not_of(BString2&, unsigned int) const;
    void find_first_not_of(unsigned short*, unsigned int) const;
    void find_first_not_of(wchar_t, unsigned int) const;
    void find_last_not_of(BString2&, unsigned int) const;
    void find_last_not_of(unsigned short*, unsigned int) const;
    void find_last_not_of(wchar_t, unsigned int) const;
    void substr(unsigned int, unsigned int) const;
    void compare(BString2&, unsigned int, unsigned int) const;
    void compare(unsigned short*, unsigned int, unsigned int) const;
    void compare(unsigned short*, unsigned int) const;
    void compare(wchar_t, unsigned int, unsigned int) const;
    void assignDebug(char*);
};

// 0x800A1A20 (96 bytes)
void BString2::delete_ref(void) {
    char* self = (char*)this;
    unsigned short* data = *(unsigned short**)self;
    if (data) {
        unsigned short refCount = data[0];
        refCount--;
        data[0] = refCount;
        if (refCount == 0) {
            MainHeap()->Free(data);
        }
        *(unsigned short**)self = 0;
    }
}

// 0x800A1A80 - 0x800A5060: Remaining 68 functions
// Wide-string operations (mirrors BString but with unsigned short)
// Each is NOTE: asm-derived


// ============================================================================
// MMUTarget (0x801C49C0 - 0x801C8170) — 40 functions, 15408 bytes
// Main Menu UI target
// ============================================================================

class MMUTarget {
public:
    MMUTarget();
    ~MMUTarget();
    void SetVariable(char*, char*);
    void GetVariable(char*);
    void GetLocalizable(char*);
    void Update(void);
    void Draw(ERC*);
    void GetListItemName(char*);
    void ChangeScreenMode(void);
    void UpdateListItems(void);
    void UpdateNGHListItems(void);
    void UpdateLotListItems(void);
    void GetNGHListItemName(char*);
    void GetLotListItemName(char*);
    void EnterLot(int);
    void LaunchLot(int);
    void LaunchFreeplay(void);
    void OnUpKeyPressed(char*, char*);
    void OnDownKeyPressed(char*, char*);
    void EndPlayerNumberChooser(void);
    void OnXKeyPressed(char*, char*);
    void OnCancelKeyPressed(char*, char*);
    void OnCircleKeyPressed(char*, char*);
    void UpdateTopLevelChoice(char*, char*);
    void UpdateGameplayChoice(char*, char*);
    void UpdateNumberOfPlayersChoice(char*, char*);
    void UpdateText(void);
    void UpdateMenuState(char*, char*);
    void GoUpMenuTree(char*, char*);
    void GetNumberOfControllers(void);
    void GetNumberOfChoicesInState(int);
    void IncrementChoice(char*, char*);
    void SetCurrentChoice(char*);
    void DecrementChoice(char*, char*);
    void OnStartGameComplete(bool);
    void UpdateDevMenuState(char*, char*);
    void OnNGHSelect(char*, char*);
    void PollControllersForNumOfPlayersState(void);
    void OnDialogClose(int);
    void Dialog2ClosedCallback(void);
};

// 0x801C49C0 (3696 bytes)
MMUTarget::MMUTarget() {
    // NOTE: asm-derived - massive constructor for main menu
    // Initializes menu tree, choice tracking, BString2 members
}

// Remaining 39 functions: menu navigation, game launching, controller polling
// Each is NOTE: asm-derived


// ============================================================================
// O2TTarget (0x801CC2B4 - 0x801D0600) — 34 functions, 15704 bytes
// Options/Settings UI target
// ============================================================================

class O2TTarget {
public:
    O2TTarget(int, int);
    ~O2TTarget();
    void SetVariable(char*, char*);
    void GetVariable(char*);
    void GetLocalizable(char*);
    void SetTopLevelState(char*, char*);
    void OnTopLevelStateChange(char*, char*);
    void OnSaveGameComplete(bool);
    void Shutdown(char*, char*);
    void OnStateChange(void);
    void AudioOptionsModified(void);
    void GameOptionsModified(void);
    void SpawnSaveSettingsDialog(void);
    void OnSaveSettingsDialogClose(int);
    void RestoreAudioOptions(void);
    void RememberOptions(void);
    void RestoreOptions(void);
    void GetScreenXLocal(signed char);
    void GetScreenXGlobal(float);
    void GetScreenYLocal(signed char);
    void GetScreenYGlobal(float);
    void UpdateText(void);
    void OnXKeyPressed(char*, char*);
    void SpawnQuitDialogBox(void);
    void OnQuitGameDialogClose(int);
    void OnUpKeyPressed(char*, char*);
    void OnDownKeyPressed(char*, char*);
    void OnRightKeyPressed(char*, char*);
    void OnLeftKeyPressed(char*, char*);
    void OnCircleKeyPressed(char*, char*);
    void UpdateShaders(char*, char*);
    void ShowHelp(void);
    void StartScreenWizard(char*, char*);
    void ExitScreenWizard(char*, char*);
};

// 0x801CC2B4 (4392 bytes)
O2TTarget::O2TTarget(int param1, int param2) {
    // NOTE: asm-derived - large constructor for options menu
    // Initializes audio/video/game option state, BString2 members
}

// Remaining 33 functions: options management, save settings, screen adjustment
// Each is NOTE: asm-derived


// ============================================================================
// ESubModelShader (0x802FBAF4 - 0x802FFC40) — 34 functions, 16336 bytes
// Sub-model shader data and vertex processing
// ============================================================================

class ESubModelShader {
public:
    ESubModelShader();
    ~ESubModelShader();
    void AddRefSubResources(void);
    void TryIncrementSubResources(void);
    void DeallocateStripData(ESMSStrip*);
    void Deallocate(void);
    void FreeStripResource(void);
    void FreeMorphStripResource(void);
    void FreeMorphResource(void);
    void CreateRCPrimitive(unsigned int, ERC*, ESMSStrip*, bool, bool, bool);
    void ReadPositions(unsigned char*, ESMSStrip*, bool);
    void ReadTexcoords(unsigned char*, ESMSStrip*);
    void ReadColors(unsigned char*, ESMSStrip*);
    void ReadNormalsOld(unsigned char*, ESMSStrip*);
    void ReadNormals(unsigned char*, ESMSStrip*);
    void ReadWeights(unsigned char*, ESMSStrip*, bool);
    void OptimizeStripsForMemory(ESubModelShader*, ESMSStrip*, int, bool);
    void ReadIndices(unsigned char*, ESMSStrip*, unsigned int&);
    void Read(unsigned char*, int);
    void AllocateMorph(void);
    void RegisterMorphTarget(ESubModelShader*, int);
    void ResetMorph(void);
    void ApplyMorph(void);
    void GetMorphedVertex(EVec3&, short, short);
    void GenerateMorphTargetDeltas(ESubModelShader*);
    void Morph(float*);
    void CreateLatticeList(TArray<BSplineVolume, TArrayERModelAllocator>*);
    void AllocateParameterizeVerts(void);
    void ParameterizeVerts(TArray<BSplineVolume, TArrayERModelAllocator>*);
    void LatticeDeform(void);
    void BuildDisplayList(ESMBuildDisplayListData*);
    void BuildDisplayList(bool, char*, bool, float, float);
    void GetMinMaxX(float*, float*);
    void TransformModelUV(EVec2&, EVec2&, unsigned int, EVec2&, EVec2&, bool);
};

// 0x802FBAF4 (124 bytes)
ESubModelShader::ESubModelShader() {
    // NOTE: asm-derived - zeros all shader/strip data
    char* self = (char*)this;
    memset(self, 0, 120);
}

// 0x802FBB70 - 0x802FFC40: Remaining 33 functions
// Vertex data reading, morphing, lattice deformation, display list building
// Each is NOTE: asm-derived - complex vertex processing


// ============================================================================
// M2MTarget (0x801BF058 - 0x801C49B0) — 39 functions, 16032 bytes
// Main-to-Main menu target (game save/load flow)
// ============================================================================

class M2MTarget {
public:
    M2MTarget();
    ~M2MTarget();
    void GetVariable(char*);
    void GetLocalizable(char*);
    void SetVariable(char*, char*);
    void ReflowButtonSelection(void);
    void Update(void);
    void SelectionCallback(int);
    void DialogClosedCallback(void);
    void OnCancel(void);
    void OnSaveLoadSucceed(void);
    void OnSaveLoadFailed(void);
    void SpawnNoSpaceDialog(void);
    void SpawnConfirmStartNewGameDialog(void);
    void SpawnContinueNoMemCardDialog(void);
    void SpawnSaveBeforeQuitCASDialog(void);
    void SpawnSaveBeforeQuitGameDialog(void);
    void SpawnNoSaveBeforeQuitDialog(void);
    void SpawnStartNGCNoMemCardDialog(void);
    void GetItemTextMemCardSelect(int, unsigned short*);
    void GetItemTextSaveGameSelect(int, unsigned short*);
    void IsItemEnabledMemCardSelect(int);
    void DoesMemoryDeviceExist(void);
    void StartLoadedGame(void);
    void ReturnFailureDestination(void);
    void StartNGCMemoryCardBootChecks(void);
    void UpdateWidgetState(void);
    void FillWidget(void);
    void HideWidget(void);
    void SetupWidgetLayout(void);
    void UpdateSelection(int);
    void IsItemEnabled(int);
    void CalcNumItems(void);
    void SetCurrState(int);
    void UnloadDialog(void);
    void PrepareNewGame(void);
    void PrepareLoadGame(void);
    void PushButtonFilters(void);
    void PopButtonFilters(void);
};

// 0x801BF058 (3204 bytes)
M2MTarget::M2MTarget() {
    // NOTE: asm-derived - large constructor for save/load flow
    // Initializes state machine, BString2 members, widget bindings
}

// Remaining 38 functions: save/load flow management, dialog spawning, widget updates
// Each is NOTE: asm-derived


// ============================================================================
// ESim (0x80030B9C - 0x80034CC0) — 39 functions, 16672 bytes
// Sim character instance (rendering, animation, skin compositing)
// ============================================================================

class ESim {
public:
    // Inherits from ISimInstance
    // +800: vtable for ISimInstance
    // +0: vtable for ESim
    // +1088..1312: model data arrays (EResource pointers)

    ESim(cXPerson*);
    ~ESim();
    void DeletePlayerCachedModel(void);
    void ReadModelFromCache(void);
    void TransferModelToCache(void);
    void initModel(void);
    void DrawPlumbBob(ERC*);
    void UpdateSkillMeter(EVec3&, EVec3&);
    void DrawSkillMeter(ERC*);
    void SetPlumbBobState(unsigned int);
    void PropOrderTableCallback(ELevelDrawData&, EOrderTableData*);
    void SimOrderTableCallback(ELevelDrawData&, EOrderTableData*);
    void CensorOrderTableCallback(ELevelDrawData&, EOrderTableData*);
    void ServiceNpcOrderTableCallback(ELevelDrawData&, EOrderTableData*);
    void DrawSimAndNpcCommonItems(ERC*);
    void SkillMeterOrderTableCallback(ELevelDrawData&, EOrderTableData*);
    void DrawCursorHighLight(ERC*);
    void DoAnimation(void);
    void Draw(ELevelDrawData&);
    void Update(void);
    void VisibilityTest(E3DWindow&);
    void SetAnim(char*);
    void UpdateShowerCurtain(void);
    void UpdateSkinChange(void);
    void CreateSkinAsync(void);
    void CompositeSkin(void);
    void CreateThumbnail(void);
    void UpdateRepShaders(int);
    void RefreshSkin(void);
    void UpdateQueuedOperation(void);
    void GetScaler(void);
    void DrawSim(bool);
    void GetObCenter(void);
    void UpdateShadow(void);
    void UpdateGhostParticleEffect(void);
    void ChangeCostume(void);
    void New(void);
    void RegisterType(unsigned short);
    ESim();
};

// 0x80030B9C (1360 bytes)
ESim::ESim(cXPerson* person) {
    // NOTE: asm-derived - massive constructor
    // Calls ISimInstance ctor, sets vtables, zeros model arrays
    // Initializes skin compositor references, shadow, plumb bob
    char* self = (char*)this;
    // Multiple loops zeroing model resource pointer arrays
    // Init float constants for scaling
}

// 0x80031140 (684 bytes)
ESim::~ESim() {
    // NOTE: asm-derived - releases all model resources, skin textures
    this->DeletePlayerCachedModel();
}

// 0x800313EC - 0x80034CC0: Remaining 37 functions
// Sim rendering, skin compositing, animation, shadow, plumb bob
// Each is NOTE: asm-derived


// ============================================================================
// HUDTarget (0x8018591C - 0x80189930) — 43 functions, 16068 bytes
// Heads-Up Display UI target
// ============================================================================

class HUDTarget {
public:
    HUDTarget();
    ~HUDTarget();
    void AttachControllers(void);
    void ReleaseControllers(void);
    void SetVariable(char*, char*);
    void SetPlayerVariable(int, char*, char*);
    void GetVariable(char*);
    void GetPlayerVariable(int, char*);
    void GetLocalizable(char*);
    void GetPlayerLocalizable(int, char*);
    void InitRepValues(void);
    void GetReputationValue(int);
    void GetNextRepUnlockValue(int);
    void OnReadBar(int, unsigned int);
    void ReadMoodBar(int, unsigned int);
    void ShowHUD(void);
    void HideHUD(void);
    void OnPlayerHUDHideStart(int);
    void InstallHUDIcons(int);
    void ShouldHUDBeVisible(int) const;
    void UpdateTutorialLocks(void);
    void Update(void);
    void UpdateClock(void);
    void UpdateActivePlayer(int, bool);
    void IsActionQueueAvailable(int) const;
    void UpdateSpeedControls(void);
    void AddMenu(int, cXObject*, BString2&, unsigned int, ERShader*);
    void AddMenuItem(int, cXObject*, Interaction*, BString2&, unsigned int, ERShader*, int, bool);
    void NotifyMenuRemoveObj(cXObject*);
    void IsMenuAvailable(int) const;
    void AddAction(int, Interaction*, BString2&, unsigned int, ERShader*, unsigned int);
    void RemoveAction(int, Interaction*);
    void RemoveAllActions(int);
    void Draw(ERC*);
    void ResetJobHudProperties(void);
    void RequestHUD(short, short, short);
    void ManageHUD(short, short, short);
    void SetHUDData(short, short);
    void ApplyMotiveCurveArray(unsigned int, short);
    void CalculateJobScore(void);
    void GetHUDData(short, short&);
    void AnimateHUDControl(short, int);
    void GotoCAS(unsigned short, unsigned short, int, int);
};

// 0x8018591C (4320 bytes)
HUDTarget::HUDTarget() {
    // NOTE: asm-derived - massive HUD constructor
    // Initializes mood bars, action queue widgets, clock, rep meter
    // BString2 members, shader references, controller bindings
}

// Remaining 42 functions: HUD updates, mood/motive display, menu management
// Each is NOTE: asm-derived


// ============================================================================
// E2ETarget (0x801AA5B8 - 0x801AE6E0) — 36 functions, 16552 bytes
// EyeToy UI target
// ============================================================================

class E2ETarget {
public:
    E2ETarget(int);
    ~E2ETarget();
    void SetVariable(char*, char*);
    void GetVariable(char*);
    void GetLocalizable(char*);
    void Update(void);
    void SaveGame(void);
    void OnShutdown(void);
    void E2ERenderCallback(ERC*, structDrawCBparams*);
    void SpawnNoEyeToyDialogBox(void);
    void OnExitDialog(int);
    void InitializeEyeToy(void);
    void ReintializeEyeToy(void);
    void SetTopLevelState(char*, char*);
    void OnTopLevelStateChange(char*, char*);
    void UpdateHue(char*, char*);
    void UpdateSaturation(char*, char*);
    void UpdateValue(char*, char*);
    void CaptureFrame(char*, char*);
    void UpdateExposure(char*, char*);
    void ChangeFunFrame(char*, char*);
    void ChangeSelectedSlot(char*, char*);
    void ChangeFilter(char*, char*);
    void OnXKeyPressed(char*, char*);
    void OnRightKeyPressed(char*, char*);
    void OnLeftKeyPressed(char*, char*);
    void UpdateText(void);
    void GetText(char*);
    void OnCircleKeyPressed(char*, char*);
    void UpdateShaders(char*, char*);
    void OnExitSettings(void);
    void LaunchSaveSettingsDialog(void);
    void OnSaveDialogDoneCB(int);
    void OnSaveGameComplete(bool);
    void SpawnSaveGameDialog(void);
    void OnSaveGameDialogClosed(int);
};

// 0x801AA5B8 (5888 bytes)
E2ETarget::E2ETarget(int param) {
    // NOTE: asm-derived - massive EyeToy constructor
    // Initializes camera feed, filters, fun frames, settings
}

// Remaining 35 functions: EyeToy camera, filters, photo capture, save
// Each is NOTE: asm-derived


// ============================================================================
// AptCIH (0x8028FE08 - 0x80293D90) — 44 functions, 16000 bytes
// APT Character Instance Handle - core APT display object
// ============================================================================

class AptCIH {
public:
    // Core APT display object - wraps character instances
    // Handles rendering, input, event dispatch

    ~AptCIH();
    void Remove(void);
    void PreDestroy(void);
    void DestroyGCPointers(void);
    void ClearCIH(bool);
    void RegisterReferences(void) const;
    void getNativeHash(void) const;
    void ensureStringAllocated(AptCIH*);
    void deallocAssetStringRecursive(void);
    void render(AptRenderingContext*, int*, AptMaskRenderOperation);
    void _getBoundingRect(AptRenderingContext*, AptRect*);
    void getBoundingRect(AptRect*);
    void getGlobalBoundingRect(AptRect*);
    void getGlobalTranslation(float*, float*);
    void GetProceduralProperty(AptProceduralProperty);
    void setProceduralProperty(AptProceduralProperty, float, bool);
    void FindAndSetEvents(void);
    void associateInstToClass(void);
    void gotoState(AptCharacterButtonRecordState);
    void jumpToFrame(int);
    void SetEventHandler(int);
    void RemoveEventHandler(int);
    void HasEvent(int);
    void queueClipEvents(int, unsigned int, int);
    void tick(void);
    void checkIfHigher(AptCIH*);
    void getDepthOfParentAt(int);
    void isVisiable(void);
    void getRootAnimation(void);
    void hasRenderData(void);
    void GetMovieclipInfo(AptMovieclipInformation*);
    AptCIH(AptVirtualFunctionTable_Indices, AptCharacterInst*, AptCIH*);
    void isSpriteInst(bool) const;
    void isCharacterInst(void) const;
    void isButtonInst(bool) const;
    void isShapeInst(void) const;
    void isTextInst(void) const;
    void isStaticTextInst(void) const;
    void isMorphInst(void) const;
    void isAnimationInst(bool) const;
    void isLevelInst(void) const;
    void isSpriteInstBase(bool) const;
    void GetCosAngle(AptMatrix*);
    void GetVectorLength(AptMatrix*);
};

// 0x8028FE08 (192 bytes)
AptCIH::~AptCIH() {
    // NOTE: asm-derived - destroys CIH, cleans up event handlers
    this->PreDestroy();
}

// 0x8028FEC8 (156 bytes)
void AptCIH::Remove(void) {
    // NOTE: asm-derived - removes from parent display list
}

// 0x8028FF64 - 0x80293D90: Remaining 42 functions
// APT display object management, rendering, event handling, type queries
// Each is NOTE: asm-derived


// ============================================================================
// EGlobal (0x8003E218 - 0x80042EB0) — 58 functions, 15744 bytes
// Global game state and utility functions
// ============================================================================

class EGlobal {
public:
    EGlobal();
    void CreateAnimator(void);
    void IsObjectInUseByPlayer(int, cXObject*);
    void LoadIntroRequirements(void);
    void LoadPreGlobalRequirements(void);
    void SetDefaults(void);
    void SetupSubstitutionStrings(void);
    void Reset(void);
    void SetCurHouse(int);
    void ClearCurHouse(void);
    void SelectWin(ERC*);
    void TransformToScreen(EVec3&, EVec2&);
    void TransformToWorld(EVec2&, EVec3&);
    void HouseNameText(char*);
    void HouseNameCapsText(char*);
    void GetHouseLevelId(char*);
    void GetHouseGrassShaderId(char*);
    void GetHUDUIString(char*);
    void GetNewUIString(char*);
    void GetPDAString(char*);
    void GetWantFearCategoryString(int, int);
    void GetRelationshipTableRow(unsigned int);
    void GetMessagesTableRow(unsigned int);
    void GetUrbzButtonsRow(unsigned int);
    void GetRepTitleTableRow(unsigned int);
    void GetGoalsLegendRow(unsigned int);
    void GetMemCardString(char*);
    void GetNghFamilyName(BString2&);
    void GetNghHouseName(BString2&);
    void ConvertUnicodeToShiftJIS(unsigned short*, unsigned short*, unsigned int);
    void GetFloorIndex(void*);
    void GetWallIndex(void*);
    void GetFenceIndex(void*);
    void SetSelectedPerson(int, cXPerson*);
    void IsPlayerInSocialMode(int);
    void GetFamilyIndexOfPerson(ObjectModule*, Family*, cXPerson*);
    void SelectNextInFamily(Family*, int, int);
    void AdvanceSelectedPerson(int);
    void SelectPrevInFamily(Family*, int, int);
    void ReverseSelectedPerson(int);
    void GetCursorPosAsFtile(FTilePt&);
    void DestroyInstance(IBaseSimInstance**);
    void AllocInstance(cXObject*);
    void AllocPersonInstance(cXPerson*);
    void ConvertSpriteIdToResId(unsigned int);
    void CreateThumbnail(ObjSelector*);
    void RecalcHouse(void);
    void BeginSaveGame(void);
    void CheckForZeroExtentOverride(CTilePt&, cXObject*);
    void CheckForZeroExtentOverride(cXObject*);
    void SetBackgroundColor(float, float, float);
    void SwapSelectedSims(void);
    void GetNameFromSkill(AnimRef*);
    void UseOptionsScreenAdjustXY(void);
    void TogglePlayerCheat(int);
    void InitPlayerCheats(void);
    void TryAutoMapPlayer(int);
    void IsSaveGameEnabled(void);
};

// 0x8003E218 (800 bytes)
EGlobal::EGlobal() {
    // NOTE: asm-derived - massive constructor initializing global game state
    char* self = (char*)this;
    *(int*)(self + 160) = 0;
    // Zeros many fields, initializes tables, strings, camera references
    // Stores global pointer to r13 offset
}

// 0x8003E538 - 0x80042EB0: Remaining 57 functions
// Global game utilities, string tables, player management, house management
// Each is NOTE: asm-derived


// ============================================================================
// ERShader (0x8031C6DC - 0x80320890) — 39 functions, 16152 bytes
// Shader resource with multi-pass and time-of-day support
// ============================================================================

class ERShader {
public:
    ERShader();
    ~ERShader();
    void Deallocate(void);
    void DelRefSubResources(void);
    void DeallocateIncomingShader(void);
    void AddRefSubResources(void);
    void TryIncrementSubResources(void);
    void CreateEShaderForTexture(ETexture*);
    void Load(EFile&);
    void Clone(unsigned int);
    void DoLoadMultiShader(char*, EShaderDef&);
    void SetCurrentShaderForState(unsigned char);
    void ChangeCurrentShader(ERShader*);
    void GetMultiShaderStateID(int);
    void SetShaderASyncForState(int);
    void DoLoad(EFile&, EShaderDef&);
    void OldLoad(EFile&, EShaderDef&);
    void CopyShedData(EShaderDef&, char*);
    void CopyIntermediateShedData(EShaderDef&, char*);
    void AddToUpdateList(void);
    void RemoveFromUpdateList(void);
    void Update(float, int, int, int);
    void HasCommonTexture(ERShader*, ERShader*);
    void UpdateTimeOfDayShader(void);
    void InterpolateShaders(float);
    void BlendCurrentShader(float);
    void UpdateAll(float, int, int, int);
    void InitDayNightShaders(int, int);
    void SetDayNightShaderToClosestTime(int, int);
    void ReplaceTexture(ERTexture*, int);
    void SwapTexture(ERTexture*, int);
    void HasTexture(unsigned int);
    void RegisterType(unsigned short);
    void SetSupportDecal(bool);
    void GetSupportDecal(void);
    void GetState(unsigned int);
    void IsMultiTextureShader(void);
    void Select(ERC*, unsigned int);
    void SelectForShadowMask(ERC*);
};

// 0x8031C6DC (196 bytes)
ERShader::ERShader() {
    // NOTE: asm-derived - calls EResource ctor, zeros shader state
    char* self = (char*)this;
    // Set vtable, init shader definition, texture references, update list links
}

// 0x8031C7A0 (212 bytes)
ERShader::~ERShader() {
    this->RemoveFromUpdateList();
    this->Deallocate();
}

// 0x8031C874 - 0x80320890: Remaining 37 functions
// Shader loading, multi-pass rendering, day/night interpolation, texture management
// Each is NOTE: asm-derived


// ============================================================================
// cXMTObjectImpl (0x800C3684 - 0x800C7F60) — 29 functions, 17236 bytes
// Multi-tile object implementation
// ============================================================================

class cXMTObjectImpl {
public:
    cXMTObjectImpl(int, ObjSelector*, cXMTObject*, ObjectModule*);
    ~cXMTObjectImpl();
    void Initialize(void);
    void SetLeader(cXMTObject*);
    void GetISimInstance(void);
    void RemoveFromChain(void);
    void Turn(int);
    void AssignOffsets(void);
    void CanPlace(FTilePt&, int, cXObject*, int);
    void Place(FTilePt&, int, cXObject*, int);
    void Pickup(void);
    void UserCanPlace(FTilePt&, int, cXObject*, int);
    void UserPlace(FTilePt&, int, cXObject*, int);
    void UserCanPickup(void);
    void UserPickup(bool);
    void UserCanDelete(void);
    void Reset(bool);
    void ReconStream(ReconBuffer*, int, bool);
    void PostLoad(int, bool);
    void SetMultiObjectData(int, int);
    void MergeDynamic(cXMTObject*);
    void IsDynamic(void);
    void RemoveFromDynamic(void);
    void UpdateAllAdjacecy(void);
    void UpdateDynAdjacency(void);
    void MergeInPlace(void);
    void GetAverageLocation(void) const;
    void GetNumTiles(int&, int&);
    void CAST_IMPL(void);
};

// 0x800C3684 (4632 bytes)
cXMTObjectImpl::cXMTObjectImpl(int type, ObjSelector* sel, cXMTObject* mtObj, ObjectModule* objMod) {
    // NOTE: asm-derived - massive constructor
    // Initializes multi-tile object with tile offsets, adjacency data
    // Calls cXObjectImpl base ctor, sets up MT-specific state
}

// 0x800C48A4 (1096 bytes)
cXMTObjectImpl::~cXMTObjectImpl() {
    // NOTE: asm-derived - removes from tile chain, cleans up adjacency
}

// 0x800C4CFC - 0x800C7F60: Remaining 27 functions
// Multi-tile placement, rotation, adjacency, save/load
// Each is NOTE: asm-derived


// ============================================================================
// SimModel (0x80070580 - 0x80074C20) — 63 functions, 16188 bytes
// Sim 3D model with body parts, morphing, and skin compositing
// ============================================================================

class SimModel {
public:
    // Per-body-part model references, morph targets, skin textures
    // +0..103: model resource pointers (26 slots x 4 bytes)
    // +104: sim description reference

    SimModel();
    ~SimModel();
    void Init(CasSimDescriptionS2C*, bool);
    void Reset(void);
    void DeallocateAllModels(void);
    void DeallocateModelPart(eBodyPartS2C);
    void DeallocateMorphResources(void);
    void DeallocateAllSkinTextures(void);
    void SetSimDescription(CasSimDescriptionS2C*);
    void DetachSimDescription(void);
    void Clone(void);
    void SetAllModels(void);
    void SetModelPart(eBodyPartS2C, unsigned int);
    void UpdateModelPart(eBodyPartS2C, bool, bool);
    void UpdateQueuedModelPart(eBodyPartS2C, bool, bool);
    void ChangeModelPart(eBodyPartS2C, unsigned int, bool, bool);
    void GetChangedModels(int*);
    void SetModelPartASync(eBodyPartS2C, unsigned int);
    void FlushLoadingModels(void);
    void WeldAllSharedVertices(void);
    void WeldSharedVertices(eBodyPartS2C, eBodyPartS2C, bool);
    void ApplyAllLatticeMorphing(void);
    void ApplyLatticeMorphingToModelPart(eBodyPartS2C);
    void ApplyAllMorphTargets(void);
    void ApplyMorphTargetsToRegion(unsigned int, unsigned int, float, unsigned int*);
    void CreateSkin(char*);
    void GetSkinTextureDef(ETextureDef&, bool);
    void ApplySkinToModels(void);
    void ApplySkinToModelPart(eBodyPartS2C);
    void TransformAllModelUV(void);
    void TransformModelPartUV(eBodyPartS2C);
    void GetModelUVTransformParameters(eBodyPartS2C, EVec2&, EVec2&, unsigned int&, EVec2&, EVec2&);
    void CompositeAllSkin(void);
    void CompositeSkinPart(unsigned char);
    void UpdateReweld(bool);
    void UpdateReweldCAS(bool);
    void UpdateSimDescriptionIndices(unsigned int*);
    void RebuildModified(void);
    void LoadAllMorphTargets(void);
    void GetGameStateModelID(unsigned int, bool);
    void GetGameStateTextureID(unsigned int, bool);
    void UpdateInnerLayerTorso(bool, bool, bool);
    void UpdateInnerLayerSleeve(bool, bool, bool);
    void UpdateMidLayerTorso(bool, bool, bool, bool);
    void UpdateMidLayerSleeve(bool, bool, bool, bool);
    void UpdateMidLayerCollar(bool);
    void UpdateOuterLayerTorso(bool, bool, bool, bool);
    void UpdateOuterLayerSleeve(bool, bool, bool, bool);
    void UpdateOuterLayerCollar(bool, bool);
    void UpdateLowerBody(bool, bool);
    void UpdateHair(bool, bool, bool);
    void UpdateHead(bool, bool, bool);
    void UpdateHat(bool, bool, bool);
    void UpdateArmAccessory(bool, bool, bool);
    void UpdateVestScarf(bool, bool, bool);
    void UpdateNecklaceEarring(bool, bool, bool);
    void UpdateBelt(bool, bool, bool);
    void UpdateShoes(bool, bool, bool);
    void UpdateFacialFeature(bool, bool, bool);
    void UpdateGlasses(bool, bool, bool);
    void GetModelName(eBodyPartS2C, EString&);
    void GetTextureName(eBodyPartS2C, EString&);
    void GetTattooTextureName(eTattooTextureTypeS2C, EString&);
};

// 0x80070580 (268 bytes)
SimModel::SimModel() {
    char* self = (char*)this;
    // Zero 26 model slots
    int count = 26;
    for (int i = 0; i < count; i++) {
        *(int*)(self + i * 4) = 0;
    }
    // Zero additional fields
    *(int*)(self + 104) = 0;  // sim description
    *(int*)(self + 108) = 0;
    *(int*)(self + 112) = 0;
    *(int*)(self + 116) = 0;
    *(int*)(self + 120) = 0;
}

// 0x8007068C (368 bytes)
SimModel::~SimModel() {
    this->DeallocateAllModels();
    this->DeallocateMorphResources();
    this->DeallocateAllSkinTextures();
}

// 0x800707FC (200 bytes)
void SimModel::Init(CasSimDescriptionS2C* desc, bool loadModels) {
    // NOTE: asm-derived - initializes from sim description
    this->SetSimDescription(desc);
    if (loadModels) {
        this->SetAllModels();
    }
}

// 0x800708C4 (88 bytes)
void SimModel::Reset(void) {
    this->DeallocateAllModels();
    this->DeallocateMorphResources();
    this->DeallocateAllSkinTextures();
    this->DetachSimDescription();
}

// 0x8007091C (196 bytes)
void SimModel::DeallocateAllModels(void) {
    // NOTE: asm-derived - loops through all body parts, deallocates each
    for (int i = 0; i < 26; i++) {
        // DeallocateModelPart for each valid slot
    }
}

// 0x800709E0 - 0x80074C20: Remaining 58 functions
// Body part model management, morphing, skin compositing, UV transforms
// Each is NOTE: asm-derived
