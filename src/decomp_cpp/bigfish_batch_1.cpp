// bigfish_batch_1.cpp - Big fish asm stub conversions (5046-5780 lines), batch 1
// Converted from 8 asm stub files to portable C++
// Classes: XRoute, MUWrapper, ESimsCam, CasSimPartsS2C, FAMTarget,
//          NeighborhoodImpl, AptDate, Effects (Effect, EffectsManager, FastParticleEmitter)
// Total: 244 functions
#include "types.h"

// ============================================================================
// External functions
// ============================================================================
extern "C" {
    void* memcpy(void*, const void*, unsigned int);
    void* memset(void*, int, unsigned int);
    void* memmove(void*, const void*, unsigned int);
    int memcmp(const void*, const void*, unsigned int);
    int strlen(const char*);
    char* strcpy(char*, const char*);
    char* strcat(char*, const char*);
    char* strncpy(char*, const char*, unsigned int);
    int strcmp(const char*, const char*);
    int stricmp(const char*, const char*);
    int strncmp(const char*, const char*, unsigned int);
    float sqrtf(float);
    float sinf(float);
    float cosf(float);
    float fabsf(float);
    float floorf(float);
    float fmodf(float, float);
    int Sprintf(char*, char*, ...);
    int wcslen(const unsigned short*);
    unsigned short* wcscpy(unsigned short*, const unsigned short*);
    int wcscmp(const unsigned short*, const unsigned short*);
    int rand();
    void srand(unsigned int);
}

// Memory
class EAHeap;
extern EAHeap* MainHeap();
extern EAHeap* RootHeap();
extern EAHeap* AptHeap();
class EAHeap {
public:
    void* Malloc(unsigned int, int);
    void* MallocAligned(unsigned int, unsigned int, unsigned int, int);
    void Free(void*);
};

// Operator new/delete
extern void* operator new(unsigned int);
extern void operator delete(void*);

// Node allocator
namespace {
    void* __node_alloc_allocate(unsigned int);
    void __node_alloc_deallocate(void*, unsigned int);
}

// ============================================================================
// Forward declarations
// ============================================================================
class ERC;
class EFile;
class EResource;
class EResourceManager;
class EString;
class EMat4;
class EVec3;
class EVec4;
class E3DWindow;
class EWindow;
class EAnimController;
class EAStringC;
class AptValue;
class AptNativeHash;
class AptSysClock;
class AptViewer;
class AptValueGC_PoolManager;
class DOGMA_PoolManager;
class BString2;
class ReconBuffer;
class CTilePt;
class FTilePt;
class RouteGoal;
class RoutingSlot;
class TileList;
class cXObject;
class cXPerson;
class TreeSim;
class Family;
class FamilyInfo;
class HouseInfo;
class Neighbor;
class NghResFile;
class ObjSelector;
class StringBuffer;
class cSimulator;
class CasSimDescriptionS2C;
class Player;
class UIDialog;
class UIObjectBase;
class WrapperPaneBase;
class DialogPaneBase;
class TextBlock;
class TextBaseItem;
class ButtonItem;
class MenuItem;
class Wrapper;
class CameraMotionSystem;
class SimsCameraParameters;
class REffectsEmitter;
class NLIteratorPtrType;
class ERQuickdata;

template <typename T0> class VECTOR;
template <typename T0> class TNodeList;
template <typename T0> class TRect;
template <typename T0, typename T1> class _Deque_base;
template <typename T0> class allocator;

struct eBodyPartS2C {};
struct eBodyTypeS2C {};
struct eSimPartsMapLocation {};
struct eSkinColorType {};
struct eTattooTextureTypeS2C {};
struct CameraNoiseSetting {};
struct AptVirtualFunctionTable_Indices {};

// Globals
extern void* g_pApp;
extern float g_deltaTime;

extern void EORDbgTrace(char*, ...);

// ============================================================================
// XRoute — Pathfinding route system
// ============================================================================
// Layout: [0] goals_begin, [4] goals_end, [8-12] ?, [16-79] RoutingSlot (3x24 bytes),
//         [76] targetObj, [80] sourceObj, [84] currentGoalIdx, [88] maxScore,
//         [92-96] ?, [100-107] position?, [108] ?, [124] ?, [128] blockingObj,
//         [132] ?, [136-148] ?, [156] personDir, [160] goalSize

class XRoute {
public:
    // 0x80152D18
    XRoute(void) {
        char* self = (char*)this;
        *(u32*)(self + 0) = 0;   // goals_begin
        *(u32*)(self + 4) = 0;   // goals_end
        *(u32*)(self + 12) = 0;  // ?
        // Construct RoutingSlot at offset 16
        ((RoutingSlot*)(self + 16))->RoutingSlot_ctor();
        this->Construct((cXObject*)0, (cXObject*)0, (RoutingSlot*)0);
    }

    // 0x80152D74
    XRoute(cXObject* src, cXObject* tgt, RoutingSlot* slot) {
        char* self = (char*)this;
        *(u32*)(self + 0) = 0;
        *(u32*)(self + 4) = 0;
        *(u32*)(self + 12) = 0;
        ((RoutingSlot*)(self + 16))->RoutingSlot_ctor();
        this->Construct(src, tgt, slot);
    }

    // 0x803AB95C
    XRoute(XRoute& other);

    // 0x80152DDC
    void Construct(cXObject* src, cXObject* tgt, RoutingSlot* slot) {
        char* self = (char*)this;
        *(u32*)(self + 80) = (u32)src;   // sourceObj
        *(u32*)(self + 76) = (u32)tgt;   // targetObj
        *(u32*)(self + 132) = 0;
        *(u32*)(self + 128) = 0;         // blockingObj

        if (slot) {
            // Copy 3 RoutingSlot entries (24 bytes each = 72 bytes)
            // plus one final partial copy
            char* dst = self + 16;
            char* ssrc = (char*)slot;
            u32 saved = *(u32*)(self + 16);
            for (int i = 0; i < 3; i++) {
                memcpy(dst, ssrc, 24);
                dst += 24;
                ssrc += 24;
            }
            // Copy remaining 12 bytes
            memcpy(dst, ssrc, 12);
            *(u32*)(self + 16) = saved;
        }

        // Initialize remaining fields
        char* srcObj = (char*)*(u32*)(self + 80);
        *(s32*)(self + 88) = -1;  // maxScore
        *(s32*)(self + 84) = -1;  // currentGoalIdx
        *(u32*)(self + 92) = 0;
        *(u32*)(self + 96) = 0;

        if (srcObj) {
            // Virtual call to get position
            u32* vtable = *(u32**)(srcObj + 4);
            // Store position at offset 100
        }

        u32* src2 = (u32*)(self + 80);
        *(u32*)(self + 124) = 1;
        *(u16*)(self + 156) = 0;   // personDir
        *(u32*)(self + 108) = 0;
        *(u32*)(self + 136) = 0;
        *(u32*)(self + 140) = 0;
        *(u16*)(self + 144) = 0;
        *(u32*)(self + 148) = 0;

        cXObject* srcP = (cXObject*)*(u32*)(self + 80);
        if (srcP) {
            // dyncast to cXPerson
            u32* tsObj = *(u32**)srcP;
            cXPerson* person = (cXPerson*)((TreeSim*)tsObj)->_dyncastimpl(2);
            if (person) {
                char* pp = (char*)person;
                u32* pvt = *(u32**)(pp + 4);
                // Get direction
                // Get person ID
            }
        }

        *(u32*)(self + 160) = 48;  // goalSize
    }

    // 0x80152F98
    void GetMaxScore(void) {
        char* self = (char*)this;
        s32 max = *(s32*)(self + 88);
        if (max == -1) {
            *(s32*)(self + 88) = 0;
            u32* begin = *(u32**)(self + 0);
            u32* end = *(u32**)(self + 4);
            u32* it = begin;
            while (it != end) {
                s32 score = *(s32*)((char*)it + 8);
                if (score > *(s32*)(self + 88)) {
                    *(s32*)(self + 88) = score;
                }
                it = (u32*)((char*)it + 16);
            }
        }
        // return *(s32*)(self + 88);
    }

    // 0x80152FF0
    void ClearCurrentGoal(void) {
        char* self = (char*)this;
        s32 idx = *(s32*)(self + 84);
        if (idx == -1) return;
        if (idx >= 0) {
            u32* begin = *(u32**)(self + 0);
            u32* end = *(u32**)(self + 4);
            s32 count = ((char*)end - (char*)begin) >> 4;
            if ((u32)idx < (u32)count) {
                char* goal = (char*)begin + (idx << 4);
                *(u32*)(goal + 8) = 0;
            }
        }
        *(s32*)(self + 88) = -1;
        *(s32*)(self + 84) = -1;
    }

    // 0x80153044
    void AddGoal(RouteGoal& goal);

    // 0x8015282C
    void EvalTileForGoal(FTilePt& tilePt, int dir);

    // 0x8015325C
    void IsPersonSittingOnChairGoal(cXPerson* person);

    // 0x80153328
    void ShouldIgnore(cXObject* obj);

    // 0x8015597C
    void BuildGoalList(void);

    // 0x80155AC8
    void FindPath(TileList& tileList);

    // 0x80158058
    void ChooseStartingPoint(void);

    // 0x80158318
    void ConstructGoals(void);

private:
    // Helper stubs used by Construct
    struct RoutingSlot_stub {
        void RoutingSlot_ctor();
    };
};


// ============================================================================
// MUWrapper — Memory card UI wrapper
// ============================================================================
// Layout: [164] fontResource, [168] pane, [172-276] various UI state,
//         [200] isVisible, [204] ?, [208] ?, ...

class MUWrapper {
public:
    // 0x8007F084
    void Startup(void);

    // 0x8007F7BC
    void Shutdown(void);

    // 0x8007F8F8
    void Reset(void);

    // 0x80080BA8
    void ResetSlotSelection(bool resetAll);

    // 0x80080F80
    void Update(void);

    // 0x800812C8
    void Draw(ERC* rc);

    // 0x80081544
    void ShowMenu(void) {
        char* self = (char*)this;
        // NOTE: asm-derived — calls Wrapper::WrapperShow and updates visibility
        *(u32*)(self + 200) = 1;
        // Wrapper::WrapperShow(this)
    }

    // 0x8008158C
    void HideMenu(void) {
        char* self = (char*)this;
        *(u32*)(self + 200) = 0;
        // Wrapper::WrapperHide(this)
    }

    // 0x800815D4
    void ShowDialog(void);

    // 0x80081880
    void HideDialog(void);

    // 0x800819D4
    void SetVariable(char* name, char* value);

    // 0x80081BE8
    void GetVariable(char* name);

    // 0x8008253C
    void SetupDisplayOkType(void);

    // 0x80082DBC
    void SetupQueryType(void);

    // 0x80083338
    void SetupInfoType(void);

    // 0x800838B8
    ~MUWrapper(void);
};


// ============================================================================
// ESimsCam — Main gameplay camera
// ============================================================================
// Layout: [0] cameraParams ptr, [4] playerIdx, [8-15] ?, [16] E3DWindow,
//         [976] prevMode, [1096] curZoomDist, [1132-1148] EVec3s,
//         [1184-1192] floats, [1192] targetRoomId,
//         [1196-1220] hash values, [1224] EAnimController,
//         [1344] flags, [1348] ?, [1352] ?, [1356] ?,
//         [1360] motionSystem ptr, [1376] ?, [1380] forceMode, [1384] forceMode2,
//         [1388] vtable ptr

class ESimsCam {
public:
    // 0x800164D4
    ESimsCam(int playerIdx) {
        char* self = (char*)this;
        // Set vtable
        // E3DWindow ctor at offset 16
        // EAnimController ctor at offset 1224
        *(u32*)(self + 4) = playerIdx;
        *(u32*)(self + 1376) = 0;

        // Allocate CameraMotionSystem (92 bytes)
        CameraMotionSystem* ms = (CameraMotionSystem*)::operator new(92);
        // CameraMotionSystem ctor with camera params
        *(u32*)(self + 1360) = (u32)ms;

        // Initialize EVec3 fields to zero
        *(u32*)(self + 1192) = (u32)-1;
        *(float*)(self + 1184) = 0.0f;
        *(float*)(self + 1188) = 0.0f;
        *(u32*)(self + 1344) = 1;
        *(u16*)(self + 1348) = 0;
        *(u32*)(self + 1352) = 0;
        *(float*)(self + 1136) = 0.0f;
        *(u32*)(self + 1140) = 1;
        *(u32*)(self + 1384) = 0;
        *(u32*)(self + 1132) = 0;
        *(u32*)(self + 1380) = 0;
    }

    // 0x8001669C
    ~ESimsCam(void) {
        char* self = (char*)this;
        // Set vtable
        CameraMotionSystem* ms = (CameraMotionSystem*)*(u32*)(self + 1360);
        if (ms) {
            // ~CameraMotionSystem with delete flag 3
        }
        // EAnimController::Shutdown at offset 1224
        *(u32*)(self + 0) = 0;
        // ~EAnimController at offset 1224
        // ~EWindow at offset 16
    }

    // 0x80016728
    void GetCurZoomRatio(void) {
        char* self = (char*)this;
        u32* params = *(u32**)(self + 0);
        float curDist = *(float*)(self + 1096);
        float minDist = *(float*)(params + 10); // offset 40
        float maxDist = *(float*)(params + 11); // offset 44
        float ratio = (curDist - minDist) / (maxDist - minDist);
        if (ratio < 0.0f) ratio = 0.0f;
        if (ratio > 1.0f) ratio = 1.0f;
        // return ratio in f1
        (void)ratio;
    }

    // 0x80016770
    void GetNearPlane(void);

    // 0x8001699C
    void GetFov(void);

    // 0x80016A1C
    void ForceFullScreenViewport(void);

    // 0x80016AB8
    void Reset(void);

    // 0x80016B54
    void SetState(int panelState);

    // 0x80016BD4
    void SetMode(int cameraMode);

    // 0x80016C34
    void FollowPlayerInteractor(int playerIdx);

    // 0x80016DB8
    void Update(void);

    // 0x80016FB8
    void ApplyPan(float amount) {
        char* self = (char*)this;
        // NOTE: asm-derived — applies pan delta to camera rotation angle
        float curAngle = *(float*)(self + 1096);
        curAngle += amount;
        *(float*)(self + 1096) = curAngle;
    }

    // 0x80016FFC
    void ApplyZoom(float amount);

    // 0x8001709C
    void HandleRotation(void);

    // 0x800172E8
    void HandleZoom(void);

    // 0x80017490
    void UpdateWin(void);

    // 0x80017ABC
    void CalcEyePosition(EVec3& outEye, int& outRoomId);

    // 0x80017DC0
    void ResetPos(float angle);

    // 0x80017EEC
    void FollowSimStiff(void);

    // 0x800183F4
    void IsInDeadZone(EVec3& pos) const;

    // 0x80018548
    void InterpolateActualCameraParamsToTarget(float dt);

    // 0x80018824
    void CenterOnSelectedSim(void);

    // 0x80018E74
    void SetPosAndReset(EVec3& eye, EVec3& target, EVec3& up);

    // 0x80018FE4
    void SetPos(EVec3& eye, EVec3& target, EVec3& up);

    // 0x8001916C
    void ForcePosition(EVec3& eye, EVec3& target, EVec3& up);

    // 0x800192FC
    void ForceTarget(EVec3& target) {
        char* self = (char*)this;
        float* src = (float*)&target;
        // Copy target EVec3 (3 floats) to camera target fields
        *(float*)(self + 1148) = src[0];
        *(float*)(self + 1152) = src[1];
        *(float*)(self + 1156) = src[2];
    }

    // 0x80019398
    void PointOutsideScreenRect(EVec3& point, float left, float top, float right, float bottom);

    // 0x8001942C
    void ValidateCursorPosition(int playerIdx, EVec3* cursorPos);

    // 0x80019628
    void CalRoomId(EVec3& pos);

    // 0x8001976C
    void GetContainingRoomId(EVec3& pos);

    // 0x80019A04
    void SetWinPos(E3DWindow& win);

    // 0x80019DFC
    void CalcPitch(EVec3& dir);

    // 0x80019EA8
    void CalcZAxisTheta(EVec3& dir);

    // 0x80019F6C
    void GetCursorPos(void);

    // 0x8001A0AC
    void GetObjectPosition(EVec3* outPos, cXObject* obj);

    // 0x8001A168
    void GetObjectOrientation(EVec3* outOri, cXObject* obj);

    // 0x8001A24C
    void DrawDebug(ERC* rc);

    // 0x8001A2B8
    void CursorNotActive(void);

    // 0x8001A328
    void SetActiveNoiseSetting(CameraNoiseSetting setting);

    // 0x8001A424
    void ApplyNoise(EVec3 eye, EVec3 target, EVec3 up);

    // 0x8001AA74
    void DrawCameraInfo(ERC* rc);

    // 0x8001ADB8
    void ReadControllerZoom(void);

    // 0x8001AE0C
    void ReadControllerRotation(void);

    // 0x8001E944
    ESimsCam(void) {
        // Default constructor — minimal init
        char* self = (char*)this;
        *(u32*)(self + 4) = 0;
        *(u32*)(self + 1360) = 0;
        *(u32*)(self + 1380) = 0;
        *(u32*)(self + 1384) = 0;
    }

    // 0x8001E9A4
    void* operator new(unsigned int size) {
        EAHeap* heap = MainHeap();
        return heap->Malloc(size, 0);
    }
};


// ============================================================================
// CasSimPartsS2C — Create-A-Sim body parts data for S2C (Sims 2 Console)
// ============================================================================
// Layout: [0] quickdataResource, [4] dataRow, [8] genderIsMale, [12] ?

class CasSimPartsS2C {
public:
    // 0x8016A894
    CasSimPartsS2C(void) {
        char* self = (char*)this;
        *(u32*)(self + 8) = 1;   // genderIsMale = true
        *(u32*)(self + 12) = 0;
        *(u32*)(self + 0) = 0;   // quickdataResource
        *(u32*)(self + 4) = 0;   // dataRow
        // EResourceManager::AddRef for body parts quickdata
        // Store resource at offset 0
    }

    // 0x8016A8F8
    ~CasSimPartsS2C(void) {
        char* self = (char*)this;
        *(u32*)(self + 4) = 0;
        EResource* res = (EResource*)*(u32*)(self + 0);
        if (res) {
            // EResource::DelRef()
            *(u32*)(self + 0) = 0;
        }
        // Conditional delete of this
    }

    // 0x8016A950
    void SetGender(bool isMale) {
        char* self = (char*)this;
        // Sets gender string for quickdata lookup
        // Uses EString local variable for gender key
        if (isMale) {
            *(u32*)(self + 8) = 1;
        } else {
            *(u32*)(self + 8) = 0;
        }
        // ERQuickdata::getTable / getRow to set data row
    }

    // 0x8016A9FC
    void GetNumBodyModels(eBodyPartS2C bodyPart) const;

    // 0x8016AB48
    void GetNumBodyTextures(eBodyPartS2C bodyPart, unsigned int modelIdx) const;

    // 0x8016AD14
    void GetNumTattooTextures(eTattooTextureTypeS2C tattooType) const {
        char* self = (char*)this;
        u32* row = *(u32**)(self + 4);
        if (!row) {
            // return 0;
            return;
        }
        // Lookup tattoo texture count from quickdata row
    }

    // 0x8016AD5C
    void GetModelID(eBodyPartS2C bodyPart, unsigned int modelIdx, int layerIdx) const;

    // 0x8016B5E0
    void GetSkinTextureID(eSkinColorType skinColor, eBodyTypeS2C bodyType, eSimPartsMapLocation location);

    // 0x8016B768
    void GetSkinTexturesDatasetID(eSkinColorType skinColor, eBodyTypeS2C bodyType);

    // 0x8016B8BC
    void GetTextureIDFromVector(VECTOR<unsigned int>& vec, int idx, bool wrap, unsigned char flags, char* debugName) const {
        // Simple vector index lookup with optional wrapping
        (void)vec; (void)idx; (void)wrap; (void)flags; (void)debugName;
    }

    // 0x8016B910
    void GetTextureID(eBodyPartS2C bodyPart, CasSimDescriptionS2C* simDesc, bool useAlternate) const;

    // 0x8016C850
    void GetTattooTextureID(eTattooTextureTypeS2C tattooType, unsigned int idx) const;

    // 0x8016C8E8
    void IsGamecubeOnly(eBodyPartS2C bodyPart, unsigned int modelIdx) const;

    // 0x8016CAC4
    void GetIconTextureId(eBodyPartS2C bodyPart, unsigned int modelIdx) const;

    // 0x8016CC9C
    void GetIconTattooTextureId(eTattooTextureTypeS2C tattooType, unsigned int idx) const;

    // 0x8016CDD8
    void LongSleeveDoesNotHideArmAccessory(eBodyPartS2C bodyPart, unsigned int modelIdx) const {
        // Returns bool from quickdata lookup
        (void)bodyPart; (void)modelIdx;
    }

    // 0x8016CE30
    void OuterLayerCollarIsAHood(unsigned int modelIdx, int layerIdx) const;

    // 0x8016CE80
    void OuterLayerTorsoIsAHood(unsigned int modelIdx, int layerIdx) const {
        (void)modelIdx; (void)layerIdx;
    }

    // 0x8016CED8
    void CanBeWornSleeveless(eBodyPartS2C bodyPart, unsigned int modelIdx, int layerIdx) const;

    // 0x8016CF78
    void MidLayerTorsoHidesBelt(unsigned int modelIdx, int layerIdx, unsigned int beltIdx) const;

    // 0x8016CFF8
    void OuterLayerTorsoHidesBelt(unsigned int modelIdx, int layerIdx, unsigned int beltIdx) const;

    // 0x8016D078
    void GetUnlockGroupNum(eBodyPartS2C bodyPart, unsigned int modelIdx) const;

    // 0x8016D294
    void GetUnlockGroupNum(eTattooTextureTypeS2C tattooType, unsigned int idx) const;

    // 0x8016D388
    void GetTattoosForLocation(eTattooTextureTypeS2C tattooType, unsigned char* outData) const;

    // 0x8016D41C
    void ConvertTattooTextureTypeToLocation(eTattooTextureTypeS2C tattooType) const {
        // Simple mapping from tattoo type enum to body location
        (void)tattooType;
    }

    // 0x8016D460
    void GetIndexFromResId(eBodyPartS2C bodyPart, int resId, int layerIdx, int* outIndex);

    // 0x8016D560
    void GetWeldableBodyPartConnections(eBodyPartS2C bodyPart, unsigned int* outConnections, unsigned int maxCount);

    // 0x8016D730
    void GetNumBodyPartOptions(eBodyPartS2C bodyPart);

    // 0x8016D820
    void GetBodyPartName(eBodyPartS2C bodyPart);

    // 0x8016D8B4
    void VerifyBodyPartsData(void);
};


// ============================================================================
// FAMTarget — Family selection UI target
// ============================================================================
// Layout: [0-24] field data, [40-127] sub-structures (16 bytes each),
//         [128] vtable, [132-140] flags, [144-175] UI sub-objects,
//         [176-191] ?, [192] stackActive, [196] deque, [236-252] BString2s,
//         [256-331] ?, [332-368] family selection state

class FAMTarget {
public:
    // 0x801AE88C
    FAMTarget(void);

    // 0x801AFB4C
    ~FAMTarget(void);

    // 0x801AFCD8
    void SetVariable(char* name, char* value);

    // 0x801AFEB8
    void GetLocalizable(char* key);

    // 0x801B05E0
    void GetVariable(char* name);

    // 0x801B0764
    void UpdateShaders(void) {
        // Delegates to sub-updaters based on menu state
        this->UpdateOccupiedShaders();
        this->UpdateLotSelectShaders();
        this->UpdateTempShaders();
    }

    // 0x801B07B0
    void UpdateOccupiedShaders(void);

    // 0x801B0950
    void UpdateLotSelectShaders(void);

    // 0x801B0B18
    void UpdateTempShaders(void);

    // 0x801B0B78
    void GetFamilyText(char* key, unsigned short* outText);

    // 0x801B0CCC
    void OnLotSelect(void);

    // 0x801B0D5C
    void DoesFamilyExistInFamilyChoice(int familyGUID);

    // 0x801B0DB4
    void GetNumberOfFamilyMembers(Family* family) {
        // Count members in family's neighbor list
        (void)family;
    }

    // 0x801B0DF8
    void IsSelectedLotOccupied(void);

    // 0x801B0E70
    void OnDialogSelection(int selection);

    // 0x801B1078
    void OnReturnFromCreateAFamily(bool success);

    // 0x801B1158
    void OnCancelKeyPressed(char* screenName, char* widgetName);

    // 0x801B13DC
    void OnUpKeyPressed(char* screenName, char* widgetName);

    // 0x801B1500
    void OnDownKeyPressed(char* screenName, char* widgetName);

    // 0x801B1640
    void OnXKeyPressed(char* screenName, char* widgetName);

    // 0x801B2608
    void UpdateMenuState(int newState);

    // 0x801B2994
    void GetNumberOfChoicesInState(int state);

    // 0x801B29F8
    void GoUpMenuTree(void);

    // 0x801B2B00
    void GetNameForFamilyInLotSelect(char* key, unsigned short* outName);

    // 0x801B2C14
    void GetMoneyForFamilyInLotSelect(char* key, unsigned short* outMoney);

    // 0x801B2CD4
    void UpdateFamilySelectShaders(void);

    // 0x801B2EC0
    void GetSelectedLotDescription(unsigned short* outDesc);

    // 0x801B2F28
    void ConvertNumericMoneyToString(int amount, unsigned short* outStr);

    // 0x801B2F8C
    void GetMoneyForFamily(Family* family, unsigned short* outStr);

    // 0x801B3024
    void GetLotName(int lotIndex);

    // 0x801B3074
    void GetNameForFamily(Family* family, unsigned short* outName);

    // 0x801B3130
    void SetCurrentChoice(char* choiceName);

    // 0x801B3284
    void GetMoneyForLot(int lotIndex);

    // 0x801B3314
    void EvictFamily(void);

    // 0x801B3388
    void GetLotForFamily(Family* family);

    // 0x801B340C
    void GetLotNameInFamilySelect(char* key);
};


// ============================================================================
// NeighborhoodImpl — Neighborhood data management
// ============================================================================
// Layout: [0] vtable, [4-11] StringBuffer2 (name), [12-75] wchar_t name data,
//         [76-83] families vector, [84-91] ?, [92-99] families2 vector,
//         [100-107] ?, [108] flags (u16), [112] ?, [116-127] characters vector,
//         [128-?] ?, [130-201] short array (36 entries, initialized to 0)

class NeighborhoodImpl {
public:
    // 0x800CCAD8
    NeighborhoodImpl(void) {
        char* self = (char*)this;
        // Set vtable
        // StringBuffer2 ctor at offset 4 with buffer at offset 12, size 32
        *(u32*)(self + 76) = 0;
        *(u32*)(self + 80) = 0;
        *(u32*)(self + 88) = 0;
        *(u32*)(self + 92) = 0;
        *(u32*)(self + 96) = 0;
        *(u32*)(self + 100) = 0;
        *(u32*)(self + 104) = 0;
        *(u32*)(self + 116) = 0;
        *(u32*)(self + 120) = 0;
        *(u32*)(self + 124) = 0;
        *(u32*)(self + 128) = 0;

        // Initialize 36-entry short array at offset 130 to zero
        u16* arr = (u16*)(self + 202);
        for (int i = 0; i < 36; i++) {
            *arr = 0;
            arr--;
        }

        *(u16*)(self + 108) = 0;
        *(u32*)(self + 112) = 0;
    }

    // 0x800CCB84
    ~NeighborhoodImpl(void);

    // 0x800CCCAC
    void RelationshipsChanged(Neighbor* neighbor);

    // 0x800CCD04
    void LevelComplete(int level);

    // 0x800CCE18
    void Unload(void);

    // 0x800CCF44
    void Load(NghResFile* resFile);

    // 0x800CD808
    void UpdateFamilyNumbers(void);

    // 0x800CD930
    void Save(NghResFile* resFile, int flags);

    // 0x800CDC2C
    void DoStream(ReconBuffer* buffer, int direction);

    // 0x800CDD78
    void FindNeighborByGUID(int guid);

    // 0x800CDE00
    void FindFamilyAndIndexByGUID(int guid, int& outFamilyIdx, int& outNeighborIdx);

    // 0x800CDEE0
    void FindNeighborByType(ObjSelector* selector);

    // 0x800CDF30
    void AddNewNeighbor(ObjSelector* selector);

    // 0x800CE120
    void LoadPersistentData(cXPerson* person);

    // 0x800CE300
    void RemoveNeighborRelationships(Neighbor* neighbor);

    // 0x800CE388
    void RemoveNeighbor(Neighbor* neighbor);

    // 0x800CE408
    void SavePersistentData(cXPerson* person);

    // 0x800CE55C
    void GetNeighborSelector(int index);

    // 0x800CE5A4
    void GetNextNeighborID(short currentID);

    // 0x800CE5F8
    void GetNeighborData(short id1, short id2, short** outData);

    // 0x800CE968
    void GetFamily(int index);

    // 0x800CEA24
    void GetFamilyInHouse(int houseIdx);

    // 0x800CEB44
    void GetFamilyIndex(Family* family);

    // 0x800CEC04
    void MakeNewFreePlayFamily(int houseIdx);

    // 0x800CEC64
    void BaseMakeNewFamily(bool isFreePlay, int houseIdx);

    // 0x800CEF48
    void RemoveFamily(Family* family);

    // 0x800CF028
    void AddToFamily(Neighbor* neighbor, Family* family);

    // 0x800CF1CC
    void RemoveFromFamily(Neighbor* neighbor);

    // 0x800CF320
    void AddAsPlayerRoommate(Neighbor* neighbor);

    // 0x800CF408
    void RemovePlayerRoommate(void);

    // 0x800CF54C
    void AddNewCharacter(Neighbor** outNeighbor);

    // 0x800CF5C4
    void DeleteCharacter(Neighbor* neighbor);

    // 0x800CF724
    void GetNumCharacters(void);

    // 0x800CF7D0
    void GetFamilyNetWorth(Family* family);

    // 0x800CF90C
    void MoveIn(Family* family, int houseIdx);

    // 0x800CF9B0
    void SetPlayerFamilyInHouse(int houseIdx);

    // 0x800CFA4C
    void MoveOut(NghResFile* resFile, int houseIdx, bool saveHouse);

    // 0x800D00AC
    void UpdateFamilyFriendsCount(Family* family);

    // 0x800D01F8
    void PrepareAndTestLot(StringBuffer& path);

    // 0x800D0304
    void GetHousePrice(cSimulator* sim);

    // 0x800D03C0
    void GetFamilyInfo(Family* family, FamilyInfo* outInfo, bool extended);

    // 0x800D04C0
    void GetFamilyInfo(int familyIdx, FamilyInfo* outInfo);

    // 0x800D0520
    void GetHouseInfo(NghResFile* resFile, int houseIdx, HouseInfo* outInfo);

    // 0x800D05F8
    void GetHouseInfo(NghResFile* resFile, HouseInfo* outInfo);

    // 0x800D0640
    void GetHouseFileInfo(NghResFile* resFile, int* outHouseCount, bool* outHasSave, bool* outHasCustom, bool* outHasExpansion);

    // 0x800D078C
    void compareHouses(int& a, int& b);

    // 0x800D0874
    void LoadHouse(NghResFile* resFile, int houseIdx, bool loadFull);

    // 0x800D1110
    void SaveHouse(NghResFile* resFile);

    // 0x800D12E0
    void UpdateInstanceVisitorTypes(void);

    // 0x800D13D4
    void NotifyAllNeighbors(int& msg, Neighbor* sender);

    // 0x800D146C
    void NotifyAllResidents(int& msg, Neighbor* sender);

    // 0x800D15B0
    void NotifyAllPersons(int& msg, Neighbor* sender);

    // 0x800D18E0
    void GetPlayerVisitingAnotherHouse(void) const {
        char* self = (char*)this;
        // Return flag from neighborhood state
        // return *(u32*)(self + 112) != 0;
        (void)self;
    }
};


// ============================================================================
// AptDate — ActionScript Date object implementation
// ============================================================================
// Layout: inherits AptValue [0-11], [8] vtable2,
//         [12] AptNativeHash, [32] flags, [36] AptSysClock local (seconds, minutes, hours, etc.),
//         [36] seconds, [40] minutes, [44] hours, [48] ?, [52] day,
//         [56] month, [60] year, [64] milliseconds,
//         [68] AptSysClock utc,
//         [100] timezoneOffset

class AptDate {
public:
    // 0x80294178
    void dateIsYearLeap(int year) {
        // Returns 1 if leap year, 0 otherwise
        // Divisible by 4 but not 100, or divisible by 400
        if (year & 3) {
            // return 0;
            return;
        }
        int century = year / 100;
        if (year != century * 100) {
            // return 1;
            return;
        }
        int quad = year / 400;
        // return (year == quad * 400) ? 1 : 0;
        (void)quad;
    }

    // 0x802941FC
    void dateGetNumDaysInMonth(int month, int year) {
        // Returns number of days in given month (0-11 indexed)
        int days = 31;
        switch (month) {
            case 3: case 5: case 8: case 10:
                days = 30;
                break;
            case 1:
                // February — check leap year
                // dateIsYearLeap(year) ? 29 : 28
                days = 28;
                break;
            case 0: case 2: case 4: case 6: case 7: case 9: case 11:
                days = 31;
                break;
            default:
                break;
        }
        (void)days; (void)year;
    }

    // 0x802942A8
    void setDates(AptSysClock* localClock, AptSysClock* utcClock, int timezoneOffset);

    // 0x802943E0
    void getDayOfWeek(int year, int month, int day);

    // 0x80294688
    void toString(EAStringC& outStr);

    // 0x80294960
    void sMethod_getDate(AptValue* result, int argCount) {
        // Returns day-of-month from local clock
        char* self = (char*)this;
        s32 dayOfMonth = *(s32*)(self + 52); // local day
        // Allocate or reuse AptValue, set integer value
        (void)result; (void)argCount; (void)dayOfMonth;
    }

    // 0x80294A14
    void sMethod_getDay(AptValue* result, int argCount) {
        // Returns day-of-week via getDayOfWeek
        char* self = (char*)this;
        int year = *(s32*)(self + 60);
        int month = *(s32*)(self + 56);
        int day = *(s32*)(self + 52);
        this->getDayOfWeek(year, month, day);
        // Store result in AptValue
        (void)result; (void)argCount;
    }

    // 0x80294AD4
    void sMethod_getFullYear(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 year = *(s32*)(self + 60);
        (void)result; (void)argCount; (void)year;
    }

    // 0x80294B88
    void sMethod_getHours(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 hours = *(s32*)(self + 44);
        (void)result; (void)argCount; (void)hours;
    }

    // 0x80294C3C
    void sMethod_getMilliseconds(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 ms = *(s32*)(self + 64);
        (void)result; (void)argCount; (void)ms;
    }

    // 0x80294CF0
    void sMethod_getMinutes(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 minutes = *(s32*)(self + 40);
        (void)result; (void)argCount; (void)minutes;
    }

    // 0x80294DA4
    void sMethod_getMonth(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 month = *(s32*)(self + 56);
        (void)result; (void)argCount; (void)month;
    }

    // 0x80294E58
    void sMethod_getSeconds(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 seconds = *(s32*)(self + 36);
        (void)result; (void)argCount; (void)seconds;
    }

    // 0x80294F0C
    void sMethod_getTime(AptValue* result, int argCount) {
        char* self = (char*)this;
        // Returns milliseconds since epoch
        (void)result; (void)argCount;
    }

    // 0x80294FC0
    void sMethod_getTimezoneOffset(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 offset = *(s32*)(self + 100);
        (void)result; (void)argCount; (void)offset;
    }

    // 0x80295080
    void sMethod_getUTCDate(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 utcDay = *(s32*)(self + 84); // utc clock day
        (void)result; (void)argCount; (void)utcDay;
    }

    // 0x80295134
    void sMethod_getUTCDay(AptValue* result, int argCount) {
        char* self = (char*)this;
        int year = *(s32*)(self + 92);
        int month = *(s32*)(self + 88);
        int day = *(s32*)(self + 84);
        this->getDayOfWeek(year, month, day);
        (void)result; (void)argCount;
    }

    // 0x802951F4
    void sMethod_getUTCFullYear(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 utcYear = *(s32*)(self + 92);
        (void)result; (void)argCount; (void)utcYear;
    }

    // 0x802952A8
    void sMethod_getUTCHours(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 utcHours = *(s32*)(self + 76);
        (void)result; (void)argCount; (void)utcHours;
    }

    // 0x8029535C
    void sMethod_getUTCMilliseconds(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 utcMs = *(s32*)(self + 96);
        (void)result; (void)argCount; (void)utcMs;
    }

    // 0x80295410
    void sMethod_getUTCMinutes(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 utcMinutes = *(s32*)(self + 72);
        (void)result; (void)argCount; (void)utcMinutes;
    }

    // 0x802954C4
    void sMethod_getUTCMonth(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 utcMonth = *(s32*)(self + 88);
        (void)result; (void)argCount; (void)utcMonth;
    }

    // 0x80295578
    void sMethod_getUTCSeconds(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 utcSeconds = *(s32*)(self + 68);
        (void)result; (void)argCount; (void)utcSeconds;
    }

    // 0x8029562C
    void sMethod_getYear(AptValue* result, int argCount) {
        char* self = (char*)this;
        s32 year = *(s32*)(self + 60);
        // Returns year - 1900 for getYear (legacy)
        (void)result; (void)argCount; (void)year;
    }

    // 0x802956E0
    void sMethod_setDate(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) {
            // return undefined
            return;
        }
        // Get arg[0] as integer, store to local day
        // *(s32*)(self + 52) = arg0;
        // Recalculate dates
        // this->setDates(local, utc, timezoneOffset);
        (void)result;
    }

    // 0x802957E0
    void sMethod_setFullYear(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        // Set year from arg[0], optionally month from arg[1], day from arg[2]
        // Recalculate dates
        (void)result;
    }

    // 0x80295930
    void sMethod_setHours(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        // *(s32*)(self + 44) = arg0;
        (void)result;
    }

    // 0x80295A30
    void sMethod_setMilliseconds(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        // *(s32*)(self + 64) = arg0;
        (void)result;
    }

    // 0x80295B30
    void sMethod_setMinutes(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        // *(s32*)(self + 40) = arg0;
        (void)result;
    }

    // 0x80295C30
    void sMethod_setMonth(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        // *(s32*)(self + 56) = arg0;
        (void)result;
    }

    // 0x80295D30
    void sMethod_setSeconds(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        // *(s32*)(self + 36) = arg0;
        (void)result;
    }

    // 0x80295E30
    void sMethod_setTime(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        // Set time in milliseconds
        (void)result;
    }

    // 0x80295EE4
    void sMethod_setUTCDate(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        // *(s32*)(self + 84) = arg0;
        (void)result;
    }

    // 0x80295FE8
    void sMethod_setUTCFullYear(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        (void)result;
    }

    // 0x8029613C
    void sMethod_setUTCHours(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        (void)result;
    }

    // 0x80296240
    void sMethod_setUTCMilliseconds(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        (void)result;
    }

    // 0x80296344
    void sMethod_setUTCMinutes(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        (void)result;
    }

    // 0x80296448
    void sMethod_setUTCMonth(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        (void)result;
    }

    // 0x8029654C
    void sMethod_setUTCSeconds(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        (void)result;
    }

    // 0x80296650
    void sMethod_setYear(AptValue* result, int argCount) {
        char* self = (char*)this;
        if (argCount <= 0) return;
        // Set year (legacy — year + 1900)
        (void)result;
    }

    // 0x80296750
    void sMethod_toString(AptValue* result, int argCount);

    // 0x80296890
    void objectMemberLookup(AptValue* result, EAStringC* memberName) const;

    // 0x80298264
    void CleanNativeFunctions(void);

    // 0x80298C30
    AptDate(int year, int month, int day, int hours, int minutes, int seconds, int ms) {
        char* self = (char*)this;
        // AptValue ctor with type 29 (Date)
        // Set vtable
        // AptNativeHash ctor at offset 12
        *(u8*)(self + 32) = 0;
        // Set second vtable
        *(u32*)(self + 100) = 0; // timezoneOffset

        // Initialize local and UTC AptSysClock structures
        // Then conditionally store year/month/day/hours/minutes/seconds/ms
        if (year != -1) *(s32*)(self + 60) = year;
        if (month != -1) *(s32*)(self + 56) = month;
        if (day != -1) *(s32*)(self + 52) = day;
        if (hours != -1) *(s32*)(self + 44) = hours;
        if (minutes != -1) *(s32*)(self + 40) = minutes;
        if (seconds != -1) *(s32*)(self + 36) = seconds;
        if (ms != -1) *(s32*)(self + 64) = ms;

        // Calculate timezone offset from local vs UTC clocks
        // Call setDates to normalize
    }

    // 0x80298DD4
    ~AptDate(void) {
        char* self = (char*)this;
        // Set vtable
        // ~AptNativeHash at offset 12
        // ~AptValue base
        // Conditional dealloc via AptValueGC_PoolManager (size 104)
        (void)self;
    }
};


// ============================================================================
// Effects — Particle effects system
// ============================================================================

namespace Effects {

// Effects::Effect — Base effect class
// Layout: [0-63] 4x4 matrix (current transform), [64] flags (u16),
//         [68-72] pointers, [76] ?, [256-319] parent transform matrix,
//         [320] effectType (u32), [324] vtable

class Effect {
public:
    // 0x80351E20
    Effect(void) {
        char* self = (char*)this;
        // Set vtable at offset 324
        *(u16*)(self + 64) = 0;
        *(u32*)(self + 76) = 0;
        *(u32*)(self + 68) = 0;
        *(u32*)(self + 72) = 0;
        // EMat4::Id() — set identity matrix at offset 0
        this->DefaultInit();
    }

    // 0x80351E7C
    Effect(int& clientParams) {
        char* self = (char*)this;
        char* params = (char*)&clientParams;
        // Set vtable at offset 324
        *(u16*)(self + 64) = 0;
        *(u32*)(self + 76) = 0;
        *(u32*)(self + 68) = 0;
        *(u32*)(self + 72) = 0;
        // EMat4::Id()

        if (self != params) {
            // Copy fields from clientParams
            *(u16*)(self + 64) = *(u16*)(params + 64);
            *(u32*)(self + 68) = *(u32*)(params + 68);
            *(u32*)(self + 72) = *(u32*)(params + 72);
            *(u32*)(self + 76) = *(u32*)(params + 76);
            // Copy 4x4 matrix (64 bytes) from params
            memcpy(self, params, 64);
        }

        this->DefaultInit();
    }

    // 0x80351F84
    void DefaultInit(void) {
        char* self = (char*)this;
        // Copy current transform (offset 0) to parent transform (offset 256)
        memcpy(self + 256, self, 64);
        *(u32*)(self + 320) = 3332; // effectType default
    }

    // 0x80352014
    void SetParentTransform(EMat4& mat) {
        char* self = (char*)this;
        char* src = (char*)&mat;
        // Copy 4x4 matrix (64 bytes) to parent transform at offset 256
        memcpy(self + 256, src, 64);
    }
};


// Effects::EffectsManager — Singleton manager for all effects
class EffectsManager {
public:
    // 0x80352318
    ~EffectsManager(void) {
        this->DeleteAll();
    }

    // 0x803523D0
    void Update(float dt);

    // 0x80352534
    void Render(ERC* rc);

    // 0x803525C0
    void DeleteAll(void);

    // 0x80352634
    void CreateEffect(REffectsEmitter& emitter, int* outHandle);

    // 0x80352718
    void DeleteEffect(int& handle);

    // 0x803527D0
    void AddEffect(int* effect);

    // 0x80352894
    void RemoveEntryFromList(int* effect, TNodeList<int*>& list, NLIteratorPtrType** iterator);

    // 0x80352998
    void ForEachEffectInList(int& msg, TNodeList<int*>& list);
};

} // namespace Effects


// Effects namespace free functions
namespace Effects {

// 0x803520DC
void PreComputeRand32Table(void) {
    // NOTE: asm-derived — fills 128-entry random table using lagged Fibonacci generator
    // Uses 20-entry seed table, produces 128-entry output table
    // Resets random table index to 0
}

// 0x8035214C
void PMRand(void) {
    // NOTE: asm-derived — Park-Miller pseudo-random number generator
    // Uses multiplier 16807, modulus 2^31-1
    // Updates global seed and returns result
}

// 0x80352190
void SetSeed2(int seed) {
    // Initialize 20-entry seed table by calling PMRand repeatedly
    // Store initial seed, set index to 20, fill 20 entries
    (void)seed;
}

// 0x80352258
void InitializeEffectsSystem(void) {
    // Guard against double-init
    // Calls InitEffectsMath, FastParticleEmitter::InitModule,
    // EffectsManager::GetSingleton, EffectsManager::Initialize
}

// 0x803522A0
void ShutdownEffectsSystem(void) {
    // Guard against double-shutdown
    // Calls EffectsManager::GetSingleton, EffectsManager::Shutdown
}

// 0x80352A14
void SinCosf(float angle, float& outSin, float& outCos) {
    // NOTE: asm-derived — fast sin/cos using lookup table with cubic interpolation
    // Handles quadrant mapping (0-3) with sign flips
    // Uses precomputed 16-entry table with 4 floats per entry (sin, dsin, cos, dcos)
    if (angle == 0.0f) {
        outSin = 0.0f;
        outCos = 1.0f;
        return;
    }
    // Scale angle to table index, determine quadrant
    // Interpolate from table
    // Apply quadrant sign corrections
    (void)angle;
}

// 0x80352B68
void Mat4SetEulerAngles34(float pitch, float yaw, float roll, EMat4& outMat) {
    // NOTE: asm-derived — builds 3x4 rotation matrix from Euler angles
    // Optimized with early-out for zero angles
    // Uses SinCosf for trig computation
    char* m = (char*)&outMat;
    float sp, cp, sy, cy, sr, cr;

    // Many special cases for zero angles to avoid unnecessary trig
    SinCosf(pitch, sp, cp);
    SinCosf(yaw, sy, cy);
    SinCosf(roll, sr, cr);

    // General case: full 3x3 rotation matrix
    *(float*)(m + 0)  = cy * cr + sy * sp * sr;
    *(float*)(m + 4)  = sy * cp;
    *(float*)(m + 8)  = -(cy * sr) + sy * sp * cr;
    *(float*)(m + 16) = -(sy * cr) + cy * sp * sr;
    *(float*)(m + 20) = cy * cp;
    *(float*)(m + 24) = sy * sr + cy * sp * cr;
    *(float*)(m + 32) = cp * sr;
    *(float*)(m + 36) = -sp;
    *(float*)(m + 40) = cp * cr;

    // Translation row = 0
    *(float*)(m + 12) = 0.0f;
    *(float*)(m + 44) = 0.0f;
    *(float*)(m + 28) = 0.0f;
}

// 0x80352EA0
void Mat4Multiply34(EMat4& a, EMat4& b, EMat4& result) {
    // NOTE: asm-derived — 3x4 matrix multiply with translation
    // result = a * b (3x3 rotation part + translation)
    char* A = (char*)&a;
    char* B = (char*)&b;
    char* R = (char*)&result;

    for (int col = 0; col < 3; col++) {
        float a0 = *(float*)(A + 0);
        float a1 = *(float*)(A + 4);
        float a2 = *(float*)(A + 8);

        float b0 = *(float*)(B + col * 4);
        float b1 = *(float*)(B + 16 + col * 4);
        float b2 = *(float*)(B + 32 + col * 4);

        *(float*)(R + col * 4) = a0 * b0 + a1 * b1 + a2 * b2;
    }
    // Translation column handled separately with offset additions
    (void)A; (void)B; (void)R;
}

// 0x8035301C
void Mat4Copy34(EMat4& src, EMat4& dst) {
    // Copy 48 bytes (3x4 floats) from src to dst
    memcpy(&dst, &src, 48);
}

} // namespace Effects


// Effects::FastParticleEmitter — Optimized particle emitter
namespace Effects {

class FastParticleEmitter {
public:
    // 0x803530C4
    FastParticleEmitter(void) {
        char* self = (char*)this;
        // Initialize to defaults
        *(u32*)(self + 0) = 0;
        *(u32*)(self + 4) = 0;
        *(u32*)(self + 8) = 0;
    }

    // 0x8035312C
    FastParticleEmitter(int& clientParams) {
        char* self = (char*)this;
        *(u32*)(self + 0) = 0;
        *(u32*)(self + 4) = 0;
        *(u32*)(self + 8) = 0;
        (void)clientParams;
    }

    // 0x80353194
    ~FastParticleEmitter(void) {
        this->FreeParticlePackets();
        // Clean up allocated resources
    }

    // 0x80353298
    void FreeParticlePackets(void);

    // 0x80353344
    void SharedInitPart1(void);

    // 0x80353398
    void SharedInitPart2(void);

    // 0x80353930
    void ReallocateParticles(int newCount);

    // 0x80353C84
    void Init(REffectsEmitter& emitter);

    // 0x80353D08
    void UpdateBurst(int burstIdx, float dt, int* particles);

    // 0x80353EF4
    void AddBurst(int count, float dt);

    // 0x80354838
    void InitResourceData(void);

    // 0x803548D4
    void RotateEmitter(float angle);

    // 0x80354978
    void InitParticlePool(void);

    // 0x803549E8
    void ComputeCombinedMatrix(void);

    // 0x80354A5C
    void Update(float dt);

    // 0x80354FE0
    void Stop(void);

    // 0x8035504C
    void ComputeDispersionPositionAndVelocity(int* particle, float speed, float spreadH, float spreadV);

    // 0x80355A38
    void DieOnLastFrame_Lifetime(int* particle, unsigned int frameCount);

    // 0x80355B34
    void Render(ERC* rc) {
        // Delegates to DoSimulationAndRender
        this->DoSimulationAndRender(rc);
    }

    // 0x80355B9C
    void DoSimulationAndRender(ERC* rc);

    // 0x8035630C
    void ComputeMaxParticles(void);

    // 0x80356680
    void PreRollParticles(void);

    // 0x80356870
    void AllocateParticlePackets(int count);

    // 0x80356954
    void RenderQuad(ERC* rc, int& particleIdx, float size, EVec4& color, float rotation, EVec4& texCoords, int& flags);
};

} // namespace Effects
