// cas.cpp - Decompiled small functions (<=64 bytes) from CAS object files
// Original object files:
//   casevent.obj, casgenetics.obj, caslistener.obj, casmediator.obj,
//   casscene.obj, casscenedefault.obj, casscenegamecube.obj,
//   cassimparts.obj, cassimstate.obj
//
// 61 small code functions identified from the DVD map file.
// 38 functions decompiled with C++ implementations below.
// 23 functions documented but left as comments (template instantiations,
// compiler-generated global constructors, sdata-returning getters,
// and functions requiring exact CasSimPartsS2C/CasScene internal layout).
// The original compiler (SN Systems ProDG) places the vtable pointer AFTER user
// data members, while GCC places it FIRST. This means all classes with virtual
// functions have different member offsets between our build and the original.
// All functions touching member offsets in virtual classes are marked NON_MATCHING.
//
// Compiler: devkitPPC GCC vs original SN Systems ProDG

#include "sim/cas.h"

// ============================================================================
// External function declarations
// ============================================================================

// CasSimRendererDynamic - subclass of CasSimRenderer
class CasSimRendererDynamic : public CasSimRenderer {
public:
    void GetIndexes(eBodyPartS2C part, unsigned char* a, unsigned char* b);
    void GetIndexes(eTattooTextureTypeS2C type, unsigned char* a, unsigned char* b);
};

// SimModel::GetGameStateModelID at 0x8007302c
extern unsigned int SimModel_GetGameStateModelID(unsigned int id, bool highRes);
// SimModel::GetGameStateTextureID at 0x80073090
extern unsigned int SimModel_GetGameStateTextureID(unsigned int id, bool highRes);


// ============================================================================
// ======== CASEVENT.OBJ =====================================================
// ============================================================================

// ============================================================================
// CasEvent::~CasEvent
// Address: 0x801603b8 | Size: 0x34 (52 bytes)
// NON_MATCHING - SN Systems vtable layout differs from GCC.
// Original stores vtable at +0x04, GCC stores at +0x00.
// Also uses deleting destructor pattern (r4 & 1 -> operator delete).
// ============================================================================
CasEvent::~CasEvent() {
}

// ============================================================================
// CasEvent::Log (base virtual)
// Address: part of CasEvent vtable | Size: 4 bytes (blr)
// MATCHING - empty function, just blr
// ============================================================================
void CasEvent::Log() const {
}


// ============================================================================
// ======== CASGENETICS.OBJ ==================================================
// ============================================================================

// ============================================================================
// CasGenetics::CasGenetics
// Address: 0x801603ec | Size: 0x38 (56 bytes)
// NON_MATCHING - Original uses a counted loop (r10=1, decrement) to zero
// 6 words across 2 iterations of 3 words each. GCC unrolls to individual stores.
// Original: stwu r1,-16(r1); li r10,1; mr r11,r3; li r0,0; loop of 3 stws
// ============================================================================
CasGenetics::CasGenetics() {
    m_unk00 = 0;
    m_unk04 = 0;
    m_unk08 = 0;
    m_unk0C = 0;
    m_unk10 = 0;
}

// ============================================================================
// CasGenetics::Grandparent::Grandparent
// Address: 0x80161984 | Size: 0x14 (20 bytes)
// MATCHING - mr r9,r3; li r0,0; stw r0,4(r9); stw r0,0(r9); blr
// ============================================================================
CasGenetics::Grandparent::Grandparent() {
    m_unk04 = 0;
    m_unk00 = 0;
}

// ============================================================================
// CasGenetics::FemaleInnerLayerTorsoLocked
// Address: 0x80161a00 | Size: 0x20 (32 bytes)
// NON_MATCHING - Original uses two cmpwi + beq branches.
// GCC generates branchless code with xori/cntlzw/or.
//
// Original:
//   cmpwi r4, 8; beq .ret_true; cmpwi r4, 11; bne .ret_false
//   li r3, 1; blr     // .ret_true
//   li r3, 0; blr     // .ret_false
// ============================================================================
bool CasGenetics::FemaleInnerLayerTorsoLocked(signed char part) {
    if (part == 8 || part == 11) {
        return true;
    }
    return false;
}

// ============================================================================
// EString::operator char* (instantiated in casgenetics.obj)
// Address: 0x803b0a6c | Size: 0x08 (8 bytes)
// MATCHING - lwz r3, 0(r3); blr
// Defined in core/e_string.cpp, not re-defined here.
// ============================================================================

// ============================================================================
// SimpleReconObject<CasGenetics>::~SimpleReconObject
// Address: 0x803b0a74 | Size: 0x20 (32 bytes)
// NON_MATCHING - Template instantiation. Calls ReconObject::~ReconObject.
// GCC vtable layout differs from SN Systems.
// ============================================================================

// ============================================================================
// SimpleReconObject<CasGenetics>::DoStream
// Address: 0x803b0a94 | Size: 0x24 (36 bytes)
// NON_MATCHING - Loads m_pObject (+0x04) and calls CasGenetics::DoStream.
// Template instantiation, vtable layout mismatch.
// ============================================================================

// ============================================================================
// SimpleReconObject<CasGenetics>::GetType
// Address: 0x803b0ab8 | Size: 0x08 (8 bytes)
// NON_MATCHING - Returns m_type at +0x08. Offset differs due to vtable position.
// Original: lwz r3, 8(r3); blr
// ============================================================================


// ============================================================================
// ======== CASLISTENER.OBJ ==================================================
// ============================================================================

// ============================================================================
// CasListener::CasListener
// Address: 0x80161b50 | Size: 0x1c (28 bytes)
// NON_MATCHING - SN Systems puts vtable at +0x04, m_pMediator at +0x00.
// GCC puts vtable at +0x00, m_pMediator at +0x04.
//
// Original:
//   lis r9, vtable_hi; mr r11, r3; addi r9, r9, vtable_lo
//   li r0, 0; stw r9, 4(r11); stw r0, 0(r11); blr
// Our GCC output:
//   lis r9, vtable_hi; li r10, 0; addi r9, r9, vtable_lo
//   stw r10, 4(r3); stw r9, 0(r3); blr
// ============================================================================
CasListener::CasListener() {
    m_pMediator = 0;
}

// ============================================================================
// CasListener::~CasListener
// Address: 0x80161b6c | Size: 0x34 (52 bytes)
// NON_MATCHING - Deleting destructor. Sets vtable, conditionally calls
// __builtin_delete. SN Systems vtable layout differs.
// ============================================================================
CasListener::~CasListener() {
}

// ============================================================================
// CasListener::SetMediator
// Address: 0x80161ba0 | Size: 0x08 (8 bytes)
// NON_MATCHING - Original: stw r4, 0(r3) (m_pMediator at +0x00)
//                GCC:      stw r4, 4(r3) (m_pMediator at +0x04, after vtable)
// ============================================================================
void CasListener::SetMediator(CasMediator* mediator) {
    m_pMediator = mediator;
}

// ============================================================================
// CasListener::GetMediator
// Address: 0x80161ba8 | Size: 0x08 (8 bytes)
// NON_MATCHING - Original: lwz r3, 0(r3) (m_pMediator at +0x00)
//                GCC:      lwz r3, 4(r3) (m_pMediator at +0x04)
// ============================================================================
CasMediator* CasListener::GetMediator() const {
    return m_pMediator;
}

// ============================================================================
// CasListener::HandleEventChangeFocus (empty virtual)
// Address: 0x80161bb0 | Size: 0x04 (4 bytes) - blr
// MATCHING
// ============================================================================
void CasListener::HandleEventChangeFocus(CasEventChangeFocus& event) {
}

// ============================================================================
// CasListener::HandleEventChangeSim (empty virtual)
// Address: 0x80161bb4 | Size: 0x04 (4 bytes) - blr
// MATCHING
// ============================================================================
void CasListener::HandleEventChangeSim(CasEventChangeSimS2C& event) {
}

// ============================================================================
// CasListener::HandleEventInitSim (empty virtual)
// Address: 0x80161bb8 | Size: 0x04 (4 bytes) - blr
// MATCHING
// ============================================================================
void CasListener::HandleEventInitSim(CasEventInitSim& event) {
}

// ============================================================================
// CasListener::HandleEventResetSim (empty virtual)
// Address: 0x80161bbc | Size: 0x04 (4 bytes) - blr
// MATCHING
// ============================================================================
void CasListener::HandleEventResetSim(CasEventResetSim& event) {
}

// ============================================================================
// CasListener::HandleEventStoreSim (empty virtual)
// Address: 0x80161bc0 | Size: 0x04 (4 bytes) - blr
// MATCHING
// ============================================================================
void CasListener::HandleEventStoreSim(CasEventStoreSim& event) {
}

// ============================================================================
// CasListener::HandleEventMorphSim (empty virtual)
// Address: 0x80161bc4 | Size: 0x04 (4 bytes) - blr
// MATCHING
// ============================================================================
void CasListener::HandleEventMorphSim(CasEventMorphSimS2C& event) {
}

// ============================================================================
// CasListener::HandleEventResetSimDraw (empty virtual)
// Address: 0x80161bc8 | Size: 0x04 (4 bytes) - blr
// MATCHING
// ============================================================================
void CasListener::HandleEventResetSimDraw(CasEventResetSimDraw& event) {
}


// ============================================================================
// ======== CASMEDIATOR.OBJ ==================================================
// ============================================================================

// ============================================================================
// CasMediator::GetNumListeners
// Address: 0x80162028 | Size: 0x08 (8 bytes)
// MATCHING - lwz r3, 8(r3); blr
// ============================================================================
u32 CasMediator::GetNumListeners() const {
    return m_numListeners;
}

// ============================================================================
// CasMediator::GetEditSimDescription
// Address: 0x801620d8 | Size: 0x1c (28 bytes)
// NON_MATCHING - Original: lwz; cmpwi; bne .has; li r3,0; blr; .has: addi; blr
// GCC generates beqlr instead of separate beq+blr pattern.
// ============================================================================
CasSimDescriptionS2C* CasMediator::GetEditSimDescription() {
    void* scene = m_pScene;
    if (scene == 0) {
        return 0;
    }
    return (CasSimDescriptionS2C*)((char*)scene + 8);
}

// ============================================================================
// CasMediator::GetNumBodyModels
// Address: 0x801620f4 | Size: 0x34 (52 bytes)
// NON_MATCHING - Original saves LR, does bl+blr. GCC tail-call optimizes to b.
// Original: stwu r1; mflr r0; stw r0; lwz r0,20(r3); li r3,0; cmpwi; beq .end;
//           mr r3,r0; bl GetNumBodyModels; .end: lwz r0; mtlr; addi r1; blr
// GCC: lwz r3,20(r3); cmpwi; beq .ret0; b GetNumBodyModels; .ret0: li r3,0; blr
// ============================================================================
u32 CasMediator::GetNumBodyModels(eBodyPartS2C part) const {
    CasSimRenderer* renderer = m_pSimRenderer;
    if (renderer == 0) {
        return 0;
    }
    return renderer->GetNumBodyModels(part);
}

// ============================================================================
// CasMediator::GetNumTattooTextures
// Address: 0x80162128 | Size: 0x34 (52 bytes)
// NON_MATCHING - Same tail-call optimization difference as GetNumBodyModels.
// ============================================================================
u32 CasMediator::GetNumTattooTextures(eTattooTextureTypeS2C type) const {
    CasSimRenderer* renderer = m_pSimRenderer;
    if (renderer == 0) {
        return 0;
    }
    return renderer->GetNumTattooTextures(type);
}

// ============================================================================
// CasMediator::GetIconTextureId
// Address: 0x8016215c | Size: 0x34 (52 bytes)
// NON_MATCHING - Same tail-call issue.
// ============================================================================
u32 CasMediator::GetIconTextureId(eBodyPartS2C part, unsigned int index) const {
    CasSimRenderer* renderer = m_pSimRenderer;
    if (renderer == 0) {
        return 0;
    }
    return renderer->GetIconTextureId(part, index);
}

// ============================================================================
// CasMediator::GetIconTattooTextureId
// Address: 0x80162190 | Size: 0x34 (52 bytes)
// NON_MATCHING - Same tail-call issue.
// ============================================================================
u32 CasMediator::GetIconTattooTextureId(eTattooTextureTypeS2C type, unsigned int index) const {
    CasSimRenderer* renderer = m_pSimRenderer;
    if (renderer == 0) {
        return 0;
    }
    return renderer->GetIconTattooTextureId(type, index);
}

// ============================================================================
// CasMediator::GetIndexes (eBodyPartS2C overload)
// Address: 0x801621c4 | Size: 0x34 (52 bytes)
// NON_MATCHING - Delegates to CasSimRendererDynamic::GetIndexes.
// Same tail-call pattern. Also has downcast to CasSimRendererDynamic.
// ============================================================================
void CasMediator::GetIndexes(eBodyPartS2C part, unsigned char* a, unsigned char* b) {
    CasSimRenderer* renderer = m_pSimRenderer;
    if (renderer == 0) {
        return;
    }
    ((CasSimRendererDynamic*)renderer)->GetIndexes(part, a, b);
}

// ============================================================================
// CasMediator::GetIndexes (eTattooTextureTypeS2C overload)
// Address: 0x801621f8 | Size: 0x34 (52 bytes)
// NON_MATCHING - Same pattern as above.
// ============================================================================
void CasMediator::GetIndexes(eTattooTextureTypeS2C type, unsigned char* a, unsigned char* b) {
    CasSimRenderer* renderer = m_pSimRenderer;
    if (renderer == 0) {
        return;
    }
    ((CasSimRendererDynamic*)renderer)->GetIndexes(type, a, b);
}

// ============================================================================
// CasMediator::DrawSim
// Address: 0x8016222c | Size: 0x40 (64 bytes)
// NON_MATCHING - Virtual dispatch through vtable with this-adjust.
// Original loads vtable, reads offset+function pointer, does blrl.
// GCC generates different virtual call code.
// ============================================================================
void CasMediator::DrawSim(ERC* rc) {
    CasSimRenderer* renderer = m_pSimRenderer;
    if (renderer == 0) {
        return;
    }
    renderer->Draw(rc);
}

// ============================================================================
// CasMediator::SetCasMode
// Address: 0x8016226c | Size: 0x2c (44 bytes)
// NON_MATCHING - Stores mode at +0x2C, then calls UIDB::UIDBSetInt with
// a static string key. GCC may inline or reorder.
// Original: stwu; mflr; stw; lis r9,"CasMode"; stw r4,44(r3);
//           addi r3,r9,lo; bl UIDBSetInt; lwz; mtlr; addi; blr
// ============================================================================
void CasMediator::SetCasMode(int mode) {
    m_casMode = mode;
    // UIDB::UIDBSetInt("CasMode", mode);  // At 0x803ef2f0
}

// ============================================================================
// CasMediator::SetControllerFilterId
// Address: 0x801622f4 | Size: 0x18 (24 bytes)
// NON_MATCHING - Original argument order is (id, slot) not (slot, id).
// Original: cmplwi r5,1; bgtlr; slwi r0,r5,2; addi r9,r3,0x20; stwx r4,r9,r0
// GCC uses different register allocation and adds addi for array offset.
// ============================================================================
void CasMediator::SetControllerFilterId(unsigned int slot, unsigned int id) {
    if (slot > 1) return;
    m_controllerFilterId[slot] = id;
}

// ============================================================================
// CasMediator::GetControllerFilterId
// Address: 0x8016230c | Size: 0x20 (32 bytes)
// NON_MATCHING - Same parameter/offset issue. Original: cmplwi r4,1; bgt;
// slwi r0,r4,2; addi r9,r3,0x20; lwzx r3,r9,r0; blr; li r3,0; blr
// GCC uses addi r4,r4,8 then slwi instead of direct +0x20 base.
// ============================================================================
u32 CasMediator::GetControllerFilterId(unsigned int slot) const {
    if (slot > 1) {
        return 0;
    }
    return m_controllerFilterId[slot];
}


// ============================================================================
// ======== CASSCENE.OBJ =====================================================
// ============================================================================

// ============================================================================
// CasScene::SetMediator
// Address: 0x801657d8 | Size: 0x08 (8 bytes)
// NON_MATCHING - Original stores at +0x00 (SN Systems vtable at +0x04).
// GCC stores at +0x04 (vtable at +0x00).
// Original: stw r4, 0(r3); blr
// ============================================================================
void CasScene::SetMediator(CasMediator* mediator) {
    m_pMediator = mediator;
}

// ============================================================================
// CasScene::SetCameraParams
// Address: 0x80165bcc | Size: 0x10 (16 bytes)
// NON_MATCHING - Member offsets differ due to vtable position.
// Original: stfs f3,0xB14(r3); stfs f1,0xABC(r3); stfs f2,0xB10(r3); blr
// ============================================================================
// void CasScene::SetCameraParams(float param1, float param2, float param3) {
//     // Stores at offsets 0xABC, 0xB10, 0xB14 relative to this
// }

// ============================================================================
// CasScene::GetCameraAngle
// Address: 0x80167238 | Size: 0x3c (60 bytes)
// NON_MATCHING - Copies two EVec3 structs from offsets 0xA90 and 0xA9C.
// Member offsets differ. Also struct copy ordering may differ.
// ============================================================================
// void CasScene::GetCameraAngle(EVec3* eye, EVec3* target) {
//     // word-by-word copy of EVec3 from this+0xA90 and this+0xA9C
// }

// ============================================================================
// CasScene::IsCameraMoving
// Address: 0x80167274 | Size: 0x3c (60 bytes)
// NON_MATCHING - Float comparisons with cror instruction pattern.
// GCC generates different branch/compare sequence for float inequality.
// ============================================================================
// bool CasScene::IsCameraMoving() {
//     // Checks floats at offsets 0xAA8 and 0xAAC against constants
// }

// ============================================================================
// CasScene::GetLights
// Address: 0x801672b0 | Size: 0x08 (8 bytes)
// NON_MATCHING - Returns this+8, but with SN Systems layout offset differs.
// Original: addi r3, r3, 8; blr
// ============================================================================
// void* CasScene::GetLights() {
//     return (void*)((char*)this + 8);
// }

// ============================================================================
// CasScene::Get3DWindow
// Address: 0x801672b8 | Size: 0x08 (8 bytes)
// NON_MATCHING - Returns member at +0xB18. Offset differs.
// Original: lwz r3, 0xB18(r3); blr
// ============================================================================
// void* CasScene::Get3DWindow() const {
//     return *(void**)((char*)this + 0xB18);
// }

// ============================================================================
// CasScene::GetRoomFromCameraAngle (base virtual)
// Address: 0x801672c0 | Size: 0x08 (8 bytes)
// MATCHING - li r3, 0; blr
// ============================================================================
unsigned int CasScene::GetRoomFromCameraAngle(unsigned int angle) const {
    return 0;
}

// ============================================================================
// CasScene::GetAmbientScoreName
// Address: 0x801672c8 | Size: 0x08 (8 bytes)
// NON_MATCHING - Returns static from sdata segment (r13-0x7B54).
// Would need linker-placed sdata symbol to match.
// Original: lwz r3, -31572(r13); blr
// ============================================================================
// const char* CasScene::GetAmbientScoreName() const {
//     return s_SCORE_NAME;
// }

// ============================================================================
// global constructors keyed to {anonymous}::SCORE_NAME (casscene.obj)
// Address: 0x801672d0 | Size: 0x2c (44 bytes)
// NON_MATCHING - Compiler-generated. Calls __static_initialization_and_destruction_0(1, 0xFFFF).
// ============================================================================


// ============================================================================
// ======== CASSCENEDEFAULT.OBJ ==============================================
// ============================================================================

// ============================================================================
// CasSceneDefault::CasSceneDefault
// Address: 0x801754d4 | Size: 0x3c (60 bytes)
// NON_MATCHING - Calls CasScene::CasScene(), then sets vtable to CasSceneDefault.
// SN Systems vtable layout and calling convention differ.
// ============================================================================
// (Cannot implement without matching CasScene::CasScene base call)

// ============================================================================
// CasSceneDefault::~CasSceneDefault
// Address: 0x80175510 | Size: 0x30 (48 bytes)
// NON_MATCHING - Sets vtable, calls CasScene::~CasScene.
// ============================================================================
// (Cannot implement without matching CasScene::~CasScene base call)

// ============================================================================
// CasSceneDefault::GetSceneName
// Address: 0x801755a4 | Size: 0x08 (8 bytes)
// NON_MATCHING - Returns static from sdata (r13-0x7B44).
// Original: lwz r3, -31556(r13); blr
// ============================================================================
// const char* CasSceneDefault::GetSceneName() const {
//     return s_SCENE_NAME;
// }

// ============================================================================
// CasSceneDefault::GetRoomModelId
// Address: 0x801755ac | Size: 0x18 (24 bytes)
// NON_MATCHING - Branch ordering differs. Original puts the common case
// (room==0 returns hash) first with beqlr, GCC puts comparison first.
// Original: lis r3,-27482; cmpwi r4,0; ori r3,r3,26543; beqlr; li r3,0; blr
// GCC:      cmpwi r4,0; beq .hash; li r3,0; blr; .hash: lis+ori r3,hash; blr
// ============================================================================
unsigned int CasSceneDefault::GetRoomModelId(RoomId roomId) const {
    if (roomId == 0) {
        return 0x94A667AF;
    }
    return 0;
}

// ============================================================================
// global constructors keyed to {anonymous}::SCENE_NAME (casscenedefault.obj)
// Address: 0x80175668 | Size: 0x2c (44 bytes)
// NON_MATCHING - Compiler-generated.
// ============================================================================


// ============================================================================
// ======== CASSCENEGAMECUBE.OBJ =============================================
// ============================================================================

// ============================================================================
// CasSceneGamecube::CasSceneGamecube
// Address: 0x80175694 | Size: 0x3c (60 bytes)
// NON_MATCHING - Same ctor pattern as CasSceneDefault.
// ============================================================================

// ============================================================================
// CasSceneGamecube::~CasSceneGamecube
// Address: 0x801756d0 | Size: 0x30 (48 bytes)
// NON_MATCHING - Same dtor pattern as CasSceneDefault.
// ============================================================================

// ============================================================================
// CasSceneGamecube::GetSceneName
// Address: 0x80175764 | Size: 0x08 (8 bytes)
// NON_MATCHING - Returns static from sdata (r13-0x7B40).
// ============================================================================

// ============================================================================
// CasSceneGamecube::GetRoomModelId
// Address: 0x8017576c | Size: 0x18 (24 bytes)
// NON_MATCHING - Same branch ordering issue as CasSceneDefault.
// ============================================================================
unsigned int CasSceneGamecube::GetRoomModelId(RoomId roomId) const {
    if (roomId == 0) {
        return 0x94A667AF;
    }
    return 0;
}

// ============================================================================
// CasSceneGamecube::GetRoomFromCameraAngle
// Address: 0x80175784 | Size: 0x08 (8 bytes)
// MATCHING - li r3, 0; blr
// ============================================================================
unsigned int CasSceneGamecube::GetRoomFromCameraAngle(unsigned int angle) const {
    return 0;
}

// ============================================================================
// global constructors keyed to {anonymous}::SCENE_NAME (casscenegamecube.obj)
// Address: 0x80175810 | Size: 0x2c (44 bytes)
// NON_MATCHING - Compiler-generated.
// ============================================================================


// ============================================================================
// ======== CASSIMPARTS.OBJ ==================================================
// ============================================================================

// ============================================================================
// CasSimPartsS2C::GetReflectionTextureID
// Address: 0x8016c82c | Size: 0x24 (36 bytes)
// NON_MATCHING - Wrapper that calls GetTextureID with r6=1 (reflection=true).
// GCC may tail-call optimize differently.
//
// Original: stwu; mflr; stw; li r6,1; bl GetTextureID; lwz; mtlr; addi; blr
// ============================================================================

// ============================================================================
// CasSimPartsS2C::OuterLayerTorsoRequiresFullTorsoMeshInMidLayer
// Address: 0x8016cd30 | Size: 0x28 (40 bytes)
// NON_MATCHING - Loads outer layer data from parts table (+0x04->+0x10),
// indexes by index*100, checks byte at +0x1C.
// GCC register allocation differs. Uses bnelr pattern.
//
// Original:
//   lwz r11, 4(r3); mulli r4, r4, 100; li r3, 1
//   lwz r9, 16(r11); add r9, r9, r4; lbz r0, 28(r9)
//   cmpwi r0, 0; bnelr; li r3, 0; blr
// ============================================================================

// ============================================================================
// CasSimPartsS2C::OuterLayerTorsoHidesMusicPlayer
// Address: 0x8016cd58 | Size: 0x28 (40 bytes)
// NON_MATCHING - Same pattern as above, checks byte at +0x1D instead.
// ============================================================================

// ============================================================================
// CasSimPartsS2C::GetGameStateModelID
// Address: 0x8016d508 | Size: 0x2c (44 bytes)
// NON_MATCHING - Loads gender from +0x0C, XORs with 1, calls
// SimModel::GetGameStateModelID(index, !gender).
//
// Original: stwu; mflr; stw; lwz r0,12(r3); mr r3,r4; xori r4,r0,1;
//           bl SimModel::GetGameStateModelID; lwz; mtlr; addi; blr
// ============================================================================

// ============================================================================
// CasSimPartsS2C::GetGameStateTextureID
// Address: 0x8016d534 | Size: 0x2c (44 bytes)
// NON_MATCHING - Same pattern as GetGameStateModelID for textures.
// ============================================================================


// ============================================================================
// ======== CASSIMSTATE.OBJ ==================================================
// ============================================================================

// ============================================================================
// CasSimState::~CasSimState
// Address: 0x80172d34 | Size: 0x34 (52 bytes)
// NON_MATCHING - Deleting destructor sets CasListener vtable at +0x04
// (SN Systems offset), conditionally calls operator delete.
// GCC puts vtable at +0x00.
// ============================================================================
CasSimState::~CasSimState() {
}

// ============================================================================
// CasSimState::GetSimDescription
// Address: 0x80175294 | Size: 0x08 (8 bytes)
// MATCHING - addi r3, r3, 8; blr
// Returns pointer to embedded CasSimDescriptionS2C at this+0x08.
// ============================================================================
CasSimDescriptionS2C* CasSimState::GetSimDescription() {
    return (CasSimDescriptionS2C*)((char*)this + 8);
}

// ============================================================================
// CasSimState::GetStoredSimDescription
// Address: 0x8017529c | Size: 0x08 (8 bytes)
// MATCHING - addi r3, r3, 0x12C; blr
// Returns pointer to second embedded CasSimDescriptionS2C at this+300.
// ============================================================================
CasSimDescriptionS2C* CasSimState::GetStoredSimDescription() {
    return (CasSimDescriptionS2C*)((char*)this + 0x12C);
}

// ============================================================================
// CasEventResetSimDraw::~CasEventResetSimDraw
// Address: 0x803b0ebc | Size: 0x30 (48 bytes)
// NON_MATCHING - Sets CasEventResetSimDraw vtable at +0x04 (SN Systems),
// then calls CasEvent::~CasEvent. GCC vtable layout differs.
// ============================================================================
CasEventResetSimDraw::~CasEventResetSimDraw() {
}

// ============================================================================
// CasEventResetSimDraw::Log
// Address: 0x803b0eec | Size: 0x40 (64 bytes)
// NON_MATCHING - Checks m_flag at +0x08, calls CasEventDummyPrintf.
// GCC generates different flag-to-int conversion (addic/subfe vs cmpwi/li).
//
// Original:
//   stwu; mflr; stw; lwz r0,8(r3); li r4,0; cmpwi r0,0; beq .skip;
//   li r4,1; .skip: lis r3,"fmt"; addi r3; crclr; bl CasEventDummyPrintf; ...
// GCC:
//   lwz r9,8(r3); lis r10,"fmt"; addi r3; addic r4,r9,-1; subfe r4,r4,r9;
//   crclr; b CasEventDummyPrintf
// ============================================================================
void CasEventResetSimDraw::Log() const {
    int arg = 0;
    if (m_flag != 0) {
        arg = 1;
    }
    CasEventDummyPrintf((char*)"CasEventResetSimDraw %d", arg);
}
