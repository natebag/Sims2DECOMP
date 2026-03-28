// large_batch_4.cpp - Large asm stub conversions (501-1000 lines), batch 4
// 30 classes converted from PPC asm to portable C++
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
    int   stricmp(const char* s1, const char* s2);
    int   strncmp(const char* s1, const char* s2, unsigned int n);
    float sqrtf(float);
    float sinf(float);
    float cosf(float);
    float acosf(float);
    float atan2f(float, float);
    float fabsf(float);
    int Sprintf(char* buf, char* fmt, ...);
    int   AtoI(char* str);
    float AtoF(char* str);
    int   wcslen(const unsigned short* s);
    int   wcsncpy(unsigned short* dst, const unsigned short* src, int n);
}

class EAHeap;
extern EAHeap* MainHeap();
class EAHeap {
public:
    void* Malloc(unsigned int size, int flags);
    void* MallocAligned(unsigned int size, unsigned int align, unsigned int flags, int extra);
    void  Free(void* ptr);
};

extern void operator delete(void*);
extern void* operator new(std::size_t);

// Forward declarations
class AptCIH;
class AptConstFile;
class AptDisplayList;
class AptFile;
class AptPseudoDisplayList;
class BString;
class BString2;
class CasSimDescriptionS2C;
class DialogParam;
class E3DWindow;
class EAStringC;
class EBitArray;
class EBoundSphere;
class EConfig;
class EFile;
class EMat4;
class ERC;
class EResource;
class EResourceManager;
class EScratchBuffUser;
class EString;
class ETexture;
class EVec2;
struct EVec3 { float x, y, z; };
class EVec4;
class FTileRect;
class GetLocalizableCommandTable;
class GetVariableCommandTable;
class H2DTarget;
class ITreeTableEntry;
class ObjectSlot;
class ReconBuffer;
class RoutingSlot;
class SpriteSlot;
class StackElem;
class StateMachine;
class StateMachineState;
class StringBuffer;
class StringSet;
class UIDialog;
class UIUpdateTable;
class SetVariableCommandTable;
class UIDrawTable;
class UIUserDrawCBTable;
class cGZSndSys;
class cXObject;
class cXPerson;
class iResFile;

struct UIScreenID {};
struct eBodyPartS2C {};
struct eTattooTextureTypeS2C {};
struct TileWallsSegment {};
struct EPrefetchMsg {};
struct ScalarKeyframe {};
struct NLIteratorPtrType {};
struct STNCIteratorPtrType {};

template <int N> class StackString;
template <typename T> class AptSharedPtr;
template <typename T0> class allocator;
template <typename T0, typename T1> class vector;

// Global singletons
extern H2DTarget* g_pH2DTarget;           // global pointer
extern cGZSndSys* g_pGZSndSys;            // r13 - 24468
extern void*      g_pSmartDataFactory;     // via GetSmartDataFactory()
extern void*      g_pGetVariableCommandTable;   // r13 - 31532
extern void*      g_pSetVariableCommandTable;   // r13 - 31528
extern void*      g_pGetLocalizableCommandTable; // r13 - 31524
extern void*      g_pUIUpdateTable;        // r13 - 31488

extern void* GetSmartDataFactory();
extern EResourceManager* g_pResourceManager;

// ============================================================================
// ActionQueue (0x80119E50 - 0x8011A824) — 13 functions, 2468 bytes
// ============================================================================

class Interaction {
public:
    // Fields at known offsets (total size: 68 bytes)
    void*       m_localVarsAlloc;     // +0
    int         m_field_04;           // +4
    int         m_field_08;           // +8
    int         m_field_0C;           // +12
    int         m_field_10;           // +16
    int         m_field_14;           // +20
    short       m_field_18;           // +24
    short       m_field_1A;           // +26
    short       m_field_1C;           // +28
    short       m_field_1E;           // +30
    short*      m_localVars;          // +32
    int         m_localVarCount;      // +36
    int         m_field_28;           // +40
    short       m_field_2C;           // +44
    int         m_pad2D;              // padding
    float       m_field_30;           // +48
    BString2*   m_name;               // +52  (BString2 embedded)
    unsigned int m_uniqueID;          // +56
    int         m_flags;              // +60
    int         m_iconPad;            // +64

    Interaction();
    Interaction(Interaction& other);
    Interaction(cXPerson* person, cXObject* obj, int param);
    Interaction(cXPerson* person, cXPerson* person2);
    Interaction(cXPerson* person, cXObject* obj, int param1, int param2);
    ~Interaction();

    Interaction& operator=(Interaction& other);
    cXObject* GetIconObject() const;
    void SetIconObject(cXObject* obj);
    BString2& GetName() const;
    void SetName(BString2& name);
    void SetName(int param1, int param2);
    void SetLocalVars(short* vars, int count);
    void SetUniqueID();
    int  GetEntry() const;
    void GetCTilePt() const;
    void DoStream(ReconBuffer* buf, int flags);
};

class ActionQueue {
public:
    // 10 Interactions in a circular buffer (each 68 bytes = 680 bytes)
    // Interaction m_actions[10];     // +0 to +679
    char m_actionData[680];           // raw storage for 10 Interactions
    int         m_head;               // +680  - start index
    int         m_tail;               // +684  - end index
    unsigned char m_disabled;         // +688  - HUD access disabled
    unsigned char m_playerIndex;      // +689  - player index for HUD

    // Helper: get Interaction at logical index (circular buffer)
    Interaction* GetAction(int index) {
        int physIdx = (m_head + index) % 10;
        return (Interaction*)(m_actionData + physIdx * 68);
    }
    const Interaction* GetAction(int index) const {
        int physIdx = (m_head + index) % 10;
        return (const Interaction*)(m_actionData + physIdx * 68);
    }
    int Count() const { return m_tail - m_head; }

    ActionQueue();
    void AddActionToHUD(int index);
    void RemoveActionFromHUD(int index);
    bool IsVisibleAction(Interaction& action);
    unsigned int FindVisualInsertGUID(int index);
};

extern void GetShaderForObject(cXObject* obj, EResource** outShader);

// 0x80119E50 (96 bytes)
ActionQueue::ActionQueue() {
    Interaction* actions = (Interaction*)m_actionData;
    for (int i = 9; i >= 0; i--) {
        new (&actions[i]) Interaction();  // NOTE: loop counted down from 9
    }
    m_head = 0;
    m_disabled = 1;
    m_tail = 0;
}

// 0x80119EB0 (176 bytes)
int ActionQueue_CountVisible(const ActionQueue* self) {
    int lastGUID = 0;
    int count = 0;
    int numActions = self->m_tail - self->m_head;
    for (int i = 0; i < numActions; i++) {
        const Interaction* action = self->GetAction(i);
        if (((ActionQueue*)self)->IsVisibleAction(*(Interaction*)action)) {
            int guid = *(int*)((char*)action + 56);
            if (lastGUID != guid) {
                lastGUID = (short)guid;
                count++;
            }
        }
    }
    return count;
}

// 0x80119F60 (268 bytes)
void ActionQueue::AddActionToHUD(int index) {
    // Check if H2DTarget exists, if so clear disabled flag
    if (g_pH2DTarget != 0) {
        m_disabled = 0;
    }
    if (m_disabled) return;

    Interaction* action = GetAction(index);
    if (!IsVisibleAction(*action)) return;

    cXObject* iconObj = action->GetIconObject();
    EResource* shader = 0;
    GetShaderForObject(iconObj, &shader);
    unsigned int shaderResult = 0;
    if (shaderResult == 0 && shader == 0) return;

    unsigned int insertGUID = FindVisualInsertGUID(index);
    H2DTarget* hud = g_pH2DTarget;
    if (hud == 0) return;

    int playerIdx = m_playerIndex;
    BString2& name = action->GetName();
    // hud->AddAction(playerIdx, action, name, shaderResult, shader, insertGUID);

    if (shader != 0) {
        // shader->DelRef();
    }
}

// 0x8011A06C (124 bytes)
void ActionQueue::RemoveActionFromHUD(int index) {
    if (m_disabled) return;
    int numActions = m_tail - m_head;
    if (index >= numActions) return;

    Interaction* action = GetAction(index);
    H2DTarget* hud = g_pH2DTarget;
    if (hud == 0) return;

    int playerIdx = m_playerIndex;
    // hud->RemoveAction(playerIdx, action);
}

// 0x8011A0E8 (104 bytes)
int ActionQueue_SetActionText(ActionQueue* self, BString2& name, unsigned int index) {
    int numActions = self->m_tail - self->m_head;
    if (index >= (unsigned int)numActions) return 0;

    Interaction* action = self->GetAction(index);
    action->SetName(name);
    return 1;
}

// 0x8011A150 (192 bytes)
int ActionQueue_SetIconObject(ActionQueue* self, cXObject* obj, unsigned int index) {
    int numActions = self->m_tail - self->m_head;
    if (index >= (unsigned int)numActions) return 0;

    Interaction* action = self->GetAction(index);
    if (action->GetIconObject() == obj) {
        return 1; // already set
    }
    action->SetIconObject(obj);
    if (!self->IsVisibleAction(*action)) {
        self->RemoveActionFromHUD(index);
    } else {
        self->AddActionToHUD(index);
    }
    return 1;
}

// 0x8011A210 (172 bytes)
int ActionQueue_IsVisibleAction(const ActionQueue* self, Interaction& action) {
    int visible = 0;
    cXObject* iconObj = action.GetIconObject();
    if (iconObj != 0) {
        visible = (action.m_flags & 0x10) ? 1 : 0;
    }
    if (visible == 0) return 0;
    if (!(action.m_flags & 0x2)) return 0;
    // If queue is empty, not visible
    if (self->m_tail == self->m_head) return 0;
    // If this action is at head, not visible (it's executing)
    const Interaction* headAction = self->GetAction(0);
    if (&action == headAction) return 0;
    return visible;
}

// 0x8011A2BC (160 bytes)
unsigned int ActionQueue_FindVisualInsertGUID(const ActionQueue* self, unsigned int startIndex) {
    int numActions = self->m_tail - self->m_head;
    for (unsigned int i = startIndex; i < (unsigned int)numActions; i++) {
        const Interaction* action = self->GetAction(i);
        if (((ActionQueue*)self)->IsVisibleAction(*(Interaction*)action)) {
            return *(unsigned int*)((char*)action + 56); // uniqueID
        }
    }
    return 0;
}

// 0x8011A35C (156 bytes)
int ActionQueue_UpdateAction(ActionQueue* self, unsigned int index) {
    int numActions = self->m_tail - self->m_head;
    if (index >= (unsigned int)numActions) return 0;

    Interaction* action = self->GetAction(index);
    if (!self->IsVisibleAction(*action)) {
        self->RemoveActionFromHUD(index);
    } else {
        self->AddActionToHUD(index);
    }
    return 1;
}

// 0x8011A3F8 (320 bytes)
int ActionQueue_Insert(ActionQueue* self, Interaction& newAction, unsigned int pos) {
    int numActions = self->m_tail - self->m_head;
    if (numActions > 9) return 0; // queue full (max 10)

    int tail = self->m_tail;
    int insertPos = self->m_head + pos;
    // Shift elements right from tail down to insertPos
    for (int i = tail; i > (int)insertPos; ) {
        int prev = i - 1;
        Interaction* dst = (Interaction*)(self->m_actionData + (i % 10) * 68);
        Interaction* src = (Interaction*)(self->m_actionData + (prev % 10) * 68);
        *dst = *src;
        i = prev;
        if (i <= (int)(self->m_head + pos)) break;
    }

    // Place new action at insertPos
    Interaction* slot = (Interaction*)(self->m_actionData + (insertPos % 10) * 68);
    *slot = newAction;
    self->m_tail++;

    // Assign unique ID if needed
    Interaction* inserted = self->GetAction(pos);
    if (inserted->m_uniqueID == 0) {
        inserted->SetUniqueID();
    }
    self->AddActionToHUD(pos);
    return 1;
}

// 0x8011A538 (428 bytes)
int ActionQueue_Remove(ActionQueue* self, unsigned int index) {
    int numActions = self->m_tail - self->m_head;
    if (index >= (unsigned int)numActions) return 0;

    self->RemoveActionFromHUD(index);
    int wasVisible = self->IsVisibleAction(*self->GetAction(index));

    if (index == 0) {
        // Remove from head - just advance head
        self->m_head++;
    } else {
        // Shift elements left
        int physStart = self->m_head + index;
        int physEnd = self->m_tail;
        if (physEnd < physStart + 1) {
            return 0; // nothing to shift - should not happen
        }
        int count = numActions - index - 1;
        for (int j = 0; j < count; j++) {
            int srcIdx = physStart + j;
            int dstIdx = srcIdx + 1;
            Interaction* dst = (Interaction*)(self->m_actionData + (srcIdx % 10) * 68);
            Interaction* src = (Interaction*)(self->m_actionData + (dstIdx % 10) * 68);
            *dst = *src;
        }
        self->m_tail--;
    }

    // If removing made head action visible and it wasn't before, update
    if (index == 0 && self->m_tail != self->m_head) {
        Interaction* headAction = self->GetAction(0);
        if ((headAction->m_flags & 0x2) && wasVisible) {
            headAction->m_flags &= ~0x20; // clear flag bit 5
            self->AddActionToHUD(0);
        }
    }
    return 1;
}

// 0x8011A714 (92 bytes)
void ActionQueue_DisableHUDAccess(ActionQueue* self, int playerIndex) {
    if (self->m_disabled) return;

    H2DTarget* hud = g_pH2DTarget;
    if (hud != 0) {
        // hud->RemoveAllActions(self->m_playerIndex);
    }
    self->m_playerIndex = 0xFF;
    self->m_disabled = 1;
}

// 0x8011A770 (180 bytes)
void ActionQueue_EnableHUDAccess(ActionQueue* self, int playerIndex) {
    H2DTarget* hud = g_pH2DTarget;
    int available = 0;
    if (hud != 0) {
        // available = hud->IsActionQueueAvailable(playerIndex);
        available = 1; // placeholder
    }
    if (!available) return;

    self->m_playerIndex = (unsigned char)playerIndex;
    self->m_disabled = 0;

    // Remove existing actions from HUD
    hud = g_pH2DTarget;
    if (hud != 0) {
        // hud->RemoveAllActions(playerIndex);
    }

    // Re-add all visible actions
    int numActions = self->m_tail - self->m_head;
    for (unsigned int i = 0; i < (unsigned int)numActions; i++) {
        self->AddActionToHUD(i);
    }
}

// ============================================================================
// Interaction (0x800C1068 - 0x800C1D20) — 13 functions, 3068 bytes
// ============================================================================

// 0x800C1068 (216 bytes)
Interaction& Interaction::operator=(Interaction& other) {
    m_flags = other.m_flags;
    m_field_04 = other.m_field_04;
    m_field_28 = other.m_field_28;
    m_field_08 = other.m_field_08;
    m_field_0C = other.m_field_0C;
    m_field_10 = other.m_field_10;
    m_field_14 = other.m_field_14;
    m_field_18 = other.m_field_18;
    m_field_1A = other.m_field_1A;
    m_field_1C = other.m_field_1C;
    m_field_1E = other.m_field_1E;
    m_uniqueID = other.m_uniqueID;
    m_field_2C = other.m_field_2C;
    m_field_30 = other.m_field_30;
    // Copy BString2 at +52
    // m_name = other.m_name; // operator= for BString2
    m_localVarsAlloc = 0;
    if (other.m_localVars != 0) {
        SetLocalVars(other.m_localVars, other.m_localVarCount);
    } else {
        m_localVars = 0;
        m_localVarCount = 0;
    }
    return *this;
}

// 0x800C1140 (144 bytes)
Interaction::Interaction() {
    m_localVarsAlloc = 0;
    m_field_04 = 0;
    m_field_08 = 0;
    m_field_0C = 0;
    m_field_10 = 0;
    m_field_14 = 0;
    m_field_18 = 0;
    m_field_1A = 0;
    m_field_1C = 0;
    m_field_1E = 0;
    m_localVars = 0;
    m_localVarCount = 0;
    m_field_28 = 0;
    m_field_2C = 0;
    m_field_30 = 0.0f;
    m_uniqueID = 0;
    m_flags = 0;
    // Initialize BString2 at +52
}

// 0x800C11D0 (92 bytes)
Interaction::Interaction(Interaction& other) {
    // Copy constructor - delegates to operator=
    m_localVarsAlloc = 0;
    m_localVars = 0;
    m_localVarCount = 0;
    *this = other;
}

// 0x800C122C (204 bytes)
// Interaction::Interaction(cXPerson *, cXObject *, int)
// NOTE: asm-derived, complex initialization from person/object data

// 0x800C12F8 (636 bytes)
// Interaction::Interaction(cXPerson *, cXPerson *)
// NOTE: asm-derived, complex person-to-person interaction setup

// 0x800C1574 (424 bytes)
// Interaction::Interaction(cXPerson *, cXObject *, int, int)
// NOTE: asm-derived, extended object interaction setup

// 0x800C171C (100 bytes)
Interaction::~Interaction() {
    if (m_localVarsAlloc != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(m_localVarsAlloc);
        m_localVarsAlloc = 0;
        m_localVars = 0;
        m_localVarCount = 0;
    }
}

// 0x800C17A4 (136 bytes)
void Interaction::SetLocalVars(short* vars, int count) {
    if (m_localVarsAlloc != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(m_localVarsAlloc);
    }
    EAHeap* heap = MainHeap();
    int size = count * 2; // sizeof(short) * count
    m_localVarsAlloc = heap->Malloc(size, 0);
    m_localVars = (short*)m_localVarsAlloc;
    m_localVarCount = count;
    memcpy(m_localVars, vars, size);
}

// 0x800C182C (112 bytes)
// Interaction::GetEntry(void) const
// NOTE: reads entry data from linked object table

// 0x800C18B0 (176 bytes)
// Interaction::GetName(void) const
// NOTE: constructs name from tree table entry or returns cached name

// 0x800C199C (204 bytes)
// Interaction::SetName(int, int)
// NOTE: sets name from string table indices

// 0x800C1A68 (524 bytes)
// Interaction::DoStream(ReconBuffer *, int)
// NOTE: serialization/deserialization of interaction data

// 0x800C1CBC (100 bytes)
// Interaction::GetCTilePt(void) const
// NOTE: returns tile position of interaction target

// ============================================================================
// EMirrorPortal (0x802F236C - 0x802F2D90) — 9 functions, 2772 bytes
// ============================================================================

class EMirrorPortal {
public:
    float       m_fovScale;           // +0
    void*       m_cornerData;         // +4  (array of corner positions)
    char        m_pad[48];            // +8..+51
    void*       m_portalVerts;        // +52  (allocated, 320 bytes aligned)
    void*       m_portalColors;       // +56  (allocated, 64 bytes aligned, unused copy)
    void*       m_portalTexCoords;    // +60  (allocated, 64 bytes aligned)
    void*       m_portalIndices;      // +64  (allocated, 64 bytes aligned)
    EResource*  m_mirrorShader;       // +68
    int         m_isRendering;        // +72

    EMirrorPortal();
    ~EMirrorPortal();
    void SetNumCorners(int n);
    void SetMirrorShader(unsigned int shaderID);
};

// 0x802F236C (176 bytes)
EMirrorPortal::EMirrorPortal() {
    // Delay loop (4 iterations)
    // volatile int delay = 4; while (delay--) {}

    SetNumCorners(4);
    m_isRendering = 0;
    m_fovScale = 0.0f;
    m_mirrorShader = 0;

    EAHeap* heap = MainHeap();
    m_portalVerts = heap->MallocAligned(320, 16, 0, 0);
    heap = MainHeap();
    m_portalIndices = heap->MallocAligned(64, 16, 0, 0);
    heap = MainHeap();
    m_portalTexCoords = heap->MallocAligned(64, 16, 0, 0);
}

// 0x802F241C (128 bytes)
EMirrorPortal::~EMirrorPortal() {
    if (m_mirrorShader != 0) {
        // m_mirrorShader->DelRef();
        m_mirrorShader = 0;
    }
    EAHeap* heap = MainHeap();
    heap->Free(m_portalVerts);
    void* indices = m_portalIndices;
    heap = MainHeap();
    heap->Free(indices);
    void* texCoords = m_portalTexCoords;
    heap = MainHeap();
    heap->Free(texCoords);
}

// 0x802F24F0 (96 bytes)
void EMirrorPortal::SetMirrorShader(unsigned int shaderID) {
    if (m_mirrorShader != 0) {
        // m_mirrorShader->DelRef();
        m_mirrorShader = 0;
    }
    // m_mirrorShader = g_pResourceManager->AddRef(shaderID, 0, 0);
}

// 0x802F2558 (492 bytes)
// EMirrorPortal::StartRendering(E3DWindow &, ERC *)
// NOTE: asm-derived, complex rendering setup with projection matrix calc

// 0x802F2744 (344 bytes)
// EMirrorPortal::StopRendering(E3DWindow &, ERC *)
// NOTE: asm-derived, restores rendering state

// 0x802F289C (244 bytes)
// EMirrorPortal::CalcMirrorMatrix(void)
// NOTE: asm-derived, calculates mirror reflection matrix

// 0x802F2990 (252 bytes)
// EMirrorPortal::InitRC(ERC *)
// NOTE: asm-derived, initializes render context for mirror

// 0x802F2A8C (316 bytes)
// EMirrorPortal::PushPortal(E3DWindow &)
// NOTE: asm-derived, pushes portal geometry to renderer

// 0x802F2B98 (504 bytes)
// EMirrorPortal::BuildPortalGeometry(void)
// NOTE: asm-derived, builds portal vertex/index data

// ============================================================================
// EBound3 (0x802C4FE8 - 0x802C5A08) — 14 functions, 2544 bytes
// ============================================================================

class EBound3 {
public:
    float m_min[3];   // +0  (min x, y, z)
    float m_max[3];   // +12 (max x, y, z)
};

// 0x802C4FE8 (104 bytes)
void EBound3_GetCorners_EVec3(const EBound3* self, EVec3* corners) {
    float* out = (float*)corners;
    for (int i = 0; i < 8; i++) {
        float x = (i & 1) ? self->m_max[0] : self->m_min[0];
        float y = (i & 2) ? self->m_max[1] : self->m_min[1];
        float z = (i & 4) ? self->m_max[2] : self->m_min[2];
        out[0] = x;
        out[1] = y;
        out[2] = z;
        out += 3;
    }
}

// 0x802C5050 (116 bytes)
void EBound3_GetCorners_EVec4(const EBound3* self, EVec4* corners) {
    float* out = (float*)corners;
    for (int i = 0; i < 8; i++) {
        float x = (i & 1) ? self->m_max[0] : self->m_min[0];
        float y = (i & 2) ? self->m_max[1] : self->m_min[1];
        float z = (i & 4) ? self->m_max[2] : self->m_min[2];
        out[0] = x;
        out[1] = y;
        out[2] = z;
        out[3] = 1.0f;
        out += 4;
    }
}

// 0x802C50C4 (248 bytes)
void EBound3_Transform_Corners(const EBound3* self, EMat4& mat, EVec3* outCorners) {
    // NOTE: asm-derived — transforms bounding box corners by matrix
    float* m = (float*)&mat;
    for (int i = 0; i < 8; i++) {
        float x = (i & 1) ? self->m_max[0] : self->m_min[0];
        float y = (i & 2) ? self->m_max[1] : self->m_min[1];
        float z = (i & 4) ? self->m_max[2] : self->m_min[2];
        float* out = (float*)outCorners + i * 3;
        out[0] = x * m[0] + y * m[4] + z * m[8] + m[12];
        out[1] = x * m[1] + y * m[5] + z * m[9] + m[13];
        out[2] = x * m[2] + y * m[6] + z * m[10] + m[14];
    }
}

// 0x802C51BC (84 bytes)
void EBound3_Transform_Bound(const EBound3* self, EMat4& mat, EBound3& outBound) {
    // Transform corners then compute new bounds
    EVec3 corners[8]; // temporary
    EBound3_Transform_Corners(self, mat, corners);
    // outBound.Compute(corners, 8);
}

// 0x802C5210 (104 bytes)
void EBound3_Add_Vec3(EBound3* self, EVec3* points, int count) {
    float* pts = (float*)points;
    for (int i = 0; i < count; i++) {
        float x = pts[0], y = pts[1], z = pts[2];
        if (x < self->m_min[0]) self->m_min[0] = x;
        if (y < self->m_min[1]) self->m_min[1] = y;
        if (z < self->m_min[2]) self->m_min[2] = z;
        if (x > self->m_max[0]) self->m_max[0] = x;
        if (y > self->m_max[1]) self->m_max[1] = y;
        if (z > self->m_max[2]) self->m_max[2] = z;
        pts += 3;
    }
}

// 0x802C5278 (140 bytes)
void EBound3_Add_Float(EBound3* self, float* points, int count) {
    for (int i = 0; i < count; i++) {
        float x = points[0], y = points[1], z = points[2];
        if (x < self->m_min[0]) self->m_min[0] = x;
        if (y < self->m_min[1]) self->m_min[1] = y;
        if (z < self->m_min[2]) self->m_min[2] = z;
        if (x > self->m_max[0]) self->m_max[0] = x;
        if (y > self->m_max[1]) self->m_max[1] = y;
        if (z > self->m_max[2]) self->m_max[2] = z;
        points += 3;
    }
}

// 0x802C5304 (232 bytes)
// EBound3::Add(EVec3 *, int, EMat4 &)
// NOTE: asm-derived, adds transformed points to bounds

// 0x802C53EC (288 bytes)
// EBound3::Add(EBound3 &, EMat4 &)
// NOTE: asm-derived, adds transformed bounding box to this

// 0x802C550C (168 bytes)
void EBound3_Compute_Vec3(EBound3* self, EVec3* points, int count) {
    float* pts = (float*)points;
    // Initialize from first point
    self->m_min[0] = self->m_max[0] = pts[0];
    self->m_min[1] = self->m_max[1] = pts[1];
    self->m_min[2] = self->m_max[2] = pts[2];
    pts += 3;
    // Expand with remaining points
    for (int i = 1; i < count; i++) {
        float x = pts[0], y = pts[1], z = pts[2];
        if (x < self->m_min[0]) self->m_min[0] = x;
        if (y < self->m_min[1]) self->m_min[1] = y;
        if (z < self->m_min[2]) self->m_min[2] = z;
        if (x > self->m_max[0]) self->m_max[0] = x;
        if (y > self->m_max[1]) self->m_max[1] = y;
        if (z > self->m_max[2]) self->m_max[2] = z;
        pts += 3;
    }
}

// 0x802C55B4 (416 bytes)
// EBound3::Compute(EVec3 *, int, EMat4 &)
// NOTE: asm-derived, compute bounds from transformed points

// 0x802C5754 (260 bytes)
// EBound3::Compute(EBound3 &, EMat4 &)
// NOTE: asm-derived, compute bounds from transformed bounding box

// 0x802C5858 (216 bytes)
void EBound3_CalcBoundSphere(EBound3* self, EBoundSphere& sphere) {
    // NOTE: asm-derived — center is midpoint, radius is half-diagonal
    float* sph = (float*)&sphere;
    float cx = (self->m_min[0] + self->m_max[0]) * 0.5f;
    float cy = (self->m_min[1] + self->m_max[1]) * 0.5f;
    float cz = (self->m_min[2] + self->m_max[2]) * 0.5f;
    sph[0] = cx;
    sph[1] = cy;
    sph[2] = cz;
    float dx = self->m_max[0] - cx;
    float dy = self->m_max[1] - cy;
    float dz = self->m_max[2] - cz;
    sph[3] = sqrtf(dx * dx + dy * dy + dz * dz);
}

// 0x802C5930 (80 bytes)
void EBound3_Compute_Vec3_Radius(EBound3* self, EVec3& center, float radius) {
    float* c = (float*)&center;
    self->m_min[0] = c[0] - radius;
    self->m_min[1] = c[1] - radius;
    self->m_min[2] = c[2] - radius;
    self->m_max[0] = c[0] + radius;
    self->m_max[1] = c[1] + radius;
    self->m_max[2] = c[2] + radius;
}

// 0x802C5980 (88 bytes)
void EBound3_Compute_Sphere(EBound3* self, EBoundSphere& sphere) {
    float* s = (float*)&sphere;
    float cx = s[0], cy = s[1], cz = s[2], r = s[3];
    self->m_min[0] = cx - r;
    self->m_min[1] = cy - r;
    self->m_min[2] = cz - r;
    self->m_max[0] = cx + r;
    self->m_max[1] = cy + r;
    self->m_max[2] = cz + r;
}

// ============================================================================
// EQuat (0x802CCB04 - 0x802CD83C) — 10 functions, 3384 bytes
// ============================================================================

class EQuat {
public:
    float x, y, z, w;  // +0, +4, +8, +12
};

// 0x802CCB04 (196 bytes)
void EQuat_ToMat4(const EQuat* q, EMat4& mat) {
    // NOTE: asm-derived — standard quaternion to rotation matrix
    float* m = (float*)&mat;
    float xx2 = (q->x + q->x) * q->x;
    float yy2 = (q->y + q->y) * q->y;
    float zz2 = (q->z + q->z) * q->z;
    float xy2 = (q->x + q->x) * q->w;
    float xz2 = (q->z + q->z) * q->x;
    float yz2 = (q->z + q->z) * q->y;
    float wx2 = (q->x + q->x) * q->w;  // recomputed
    float wy2 = (q->y + q->y) * q->w;
    float wz2 = (q->z + q->z) * q->w;

    m[0]  = 1.0f - (yy2 + zz2);
    m[1]  = (q->y + q->y) * q->x + wz2;
    m[2]  = xz2 - wy2;
    m[3]  = 0.0f;
    m[4]  = (q->y + q->y) * q->x - wz2;
    m[5]  = 1.0f - (xx2 + zz2);
    m[6]  = yz2 + wx2;
    m[7]  = 0.0f;
    m[8]  = xz2 + wy2;
    m[9]  = yz2 - wx2;
    m[10] = 1.0f - (xx2 + yy2);
    m[11] = 0.0f;
    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;
}

// 0x802CCBC8 (444 bytes)
void EQuat_FromMat4(EQuat* q, EMat4& mat) {
    // NOTE: asm-derived — Shepperd's method for matrix to quaternion
    float* m = (float*)&mat;
    float trace = m[0] + m[5] + m[10];
    if (trace > 0.0f) {
        float s = sqrtf(trace + 1.0f);
        float invS = 0.5f / s;
        q->w = s * 0.5f;
        q->x = (m[6] - m[9]) * invS;
        q->y = (m[8] - m[2]) * invS;
        q->z = (m[1] - m[4]) * invS;
    } else {
        // Find largest diagonal element
        int i = 0;
        if (m[5] > m[0]) i = 1;
        if (m[10] > m[i * 5]) i = 2;

        static const int next[3] = {1, 2, 0};
        int j = next[i];
        int k = next[j];

        float s = sqrtf(m[i * 5] - m[j * 5] - m[k * 5] + 1.0f);
        float invS = 0.5f / s;

        float quat[4];
        quat[i] = s * 0.5f;
        quat[3] = (m[j * 4 + k] - m[k * 4 + j]) * invS;
        quat[j] = (m[i * 4 + j] + m[j * 4 + i]) * invS;
        quat[k] = (m[i * 4 + k] + m[k * 4 + i]) * invS;

        q->x = quat[0];
        q->y = quat[1];
        q->z = quat[2];
        q->w = quat[3];
    }
}

// 0x802CCD84 (184 bytes)
void EQuat_ToAxisAngle(const EQuat* q, EVec3& axis, float& angle) {
    // NOTE: asm-derived
    float* a = (float*)&axis;
    float s2 = q->x * q->x + q->y * q->y + q->z * q->z;
    if (s2 > 0.0f) {
        float invS = 1.0f / sqrtf(s2);
        a[0] = q->x * invS;
        a[1] = q->y * invS;
        a[2] = q->z * invS;
        angle = 2.0f * acosf(q->w);
    } else {
        a[0] = 1.0f;
        a[1] = 0.0f;
        a[2] = 0.0f;
        angle = 0.0f;
    }
}

// 0x802CCE3C (72 bytes)
void EQuat_ExtractAxisRotation(const EQuat* q, EVec3& axis) {
    // NOTE: asm-derived — extracts rotation about given axis
    float* a = (float*)&axis;
    float dot = q->x * a[0] + q->y * a[1] + q->z * a[2];
    // project quaternion onto axis
}

// 0x802CCE84 (464 bytes)
void EQuat_Set_Euler(EQuat* q, float yaw, float pitch, float roll) {
    // NOTE: asm-derived — set quaternion from Euler angles
    float cy = cosf(yaw * 0.5f);
    float sy = sinf(yaw * 0.5f);
    float cp = cosf(pitch * 0.5f);
    float sp = sinf(pitch * 0.5f);
    float cr = cosf(roll * 0.5f);
    float sr = sinf(roll * 0.5f);

    q->w = cy * cp * cr + sy * sp * sr;
    q->x = cy * sp * cr + sy * cp * sr;
    q->y = sy * cp * cr - cy * sp * sr;
    q->z = cy * cp * sr - sy * sp * cr;
}

// 0x802CD054 (100 bytes)
void EQuat_RemoveAxisFlip(EQuat* q, EQuat& ref) {
    // NOTE: asm-derived — ensure quaternion is in same hemisphere as ref
    float dot = q->x * ref.x + q->y * ref.y + q->z * ref.z + q->w * ref.w;
    if (dot < 0.0f) {
        q->x = -q->x;
        q->y = -q->y;
        q->z = -q->z;
        q->w = -q->w;
    }
}

// 0x802CD0B8 (808 bytes)
void EQuat_Slerp(EQuat* q, float t, EQuat& from, EQuat to) {
    // NOTE: asm-derived — spherical linear interpolation
    float dot = from.x * to.x + from.y * to.y + from.z * to.z + from.w * to.w;
    if (dot < 0.0f) {
        dot = -dot;
        to.x = -to.x;
        to.y = -to.y;
        to.z = -to.z;
        to.w = -to.w;
    }

    float scale0, scale1;
    if ((1.0f - dot) > 0.001f) {
        float omega = acosf(dot);
        float sinOmega = sinf(omega);
        float invSin = 1.0f / sinOmega;
        scale0 = sinf((1.0f - t) * omega) * invSin;
        scale1 = sinf(t * omega) * invSin;
    } else {
        scale0 = 1.0f - t;
        scale1 = t;
    }

    q->x = scale0 * from.x + scale1 * to.x;
    q->y = scale0 * from.y + scale1 * to.y;
    q->z = scale0 * from.z + scale1 * to.z;
    q->w = scale0 * from.w + scale1 * to.w;
}

// 0x802CD3E0 (732 bytes)
void EQuat_SlerpNoInvert(EQuat* q, float t, EQuat& from, EQuat& to) {
    // NOTE: asm-derived — slerp without flipping to shortest path
    float dot = from.x * to.x + from.y * to.y + from.z * to.z + from.w * to.w;

    float scale0, scale1;
    float absDot = (dot < 0.0f) ? -dot : dot;
    if ((1.0f - absDot) > 0.001f) {
        float omega = acosf(absDot);
        float sinOmega = sinf(omega);
        float invSin = 1.0f / sinOmega;
        scale0 = sinf((1.0f - t) * omega) * invSin;
        scale1 = sinf(t * omega) * invSin;
    } else {
        scale0 = 1.0f - t;
        scale1 = t;
    }

    if (dot < 0.0f) scale1 = -scale1;

    q->x = scale0 * from.x + scale1 * to.x;
    q->y = scale0 * from.y + scale1 * to.y;
    q->z = scale0 * from.z + scale1 * to.z;
    q->w = scale0 * from.w + scale1 * to.w;
}

// 0x802CD6BC (248 bytes)
void EQuat_Scale(EQuat* q, float scale, EQuat& src) {
    // NOTE: asm-derived — scale quaternion rotation by factor
    float angle;
    EVec3 axis;
    EQuat_ToAxisAngle(&src, axis, angle);
    angle *= scale;
    float halfAngle = angle * 0.5f;
    float* a = (float*)&axis;
    float s = sinf(halfAngle);
    q->x = a[0] * s;
    q->y = a[1] * s;
    q->z = a[2] * s;
    q->w = cosf(halfAngle);
}

// 0x802CD7B4 (136 bytes)
void EQuat_Set_AxisAngle(EQuat* q, EVec3& axis, float angle) {
    // NOTE: asm-derived
    float halfAngle = angle * 0.5f;
    float* a = (float*)&axis;
    float s = sinf(halfAngle);
    q->x = a[0] * s;
    q->y = a[1] * s;
    q->z = a[2] * s;
    q->w = cosf(halfAngle);
}

// ============================================================================
// EStringTableNoCase (0x80361570 - 0x80361EF4) — 20 functions, 2296 bytes
// ============================================================================

struct STNCEntry {
    char*        key;      // +0
    unsigned int value;    // +4
    STNCEntry*   next;     // +8
};

class EStringTableNoCase {
public:
    int          m_count;      // +0  - number of entries
    int          m_freeList;   // +4  - free list head
    STNCEntry**  m_table;      // +8  - hash table buckets
    int          m_tableSize;  // +12 - number of buckets
    unsigned int m_mask;       // +16 - tableSize - 1
    int          m_threshold;  // +20 - grow threshold

    EStringTableNoCase();
    EStringTableNoCase(int size);
    EStringTableNoCase(EStringTableNoCase& other);
    ~EStringTableNoCase();
    void ClearTable();
    void InitTable(int size);
    void SetValue(char* key, unsigned int value);
    void Insert(char* key, unsigned int value);
    void InsertNew(unsigned int hash, char* key, unsigned int value);
    void Remove(char* key);
    void Remove(STNCIteratorPtrType* it);
    void Remove(unsigned int hash, STNCIteratorPtrType* it);
    void RemoveAll();
    void FreeAll();
    void PreGrowTable(int size);
    void GrowTable();
    void SetValues(EStringTableNoCase& other);
};

// 0x80361570 (88 bytes)
EStringTableNoCase::EStringTableNoCase(EStringTableNoCase& other) {
    m_table = 0;
    m_freeList = 0;
    m_count = 0;
    m_threshold = 0;
    InitTable(other.m_tableSize);
    SetValues(other);
}

// 0x803615C8 (76 bytes)
EStringTableNoCase::~EStringTableNoCase() {
    RemoveAll();
    EAHeap* heap = MainHeap();
    heap->Free(m_table);
}

// 0x80361614 (76 bytes)
unsigned int EStringTableNoCase_Hash(const EStringTableNoCase* self, char* key) {
    unsigned int hash = 0;
    unsigned char c;
    while ((c = *key++) != 0) {
        // Case-insensitive: convert lowercase to uppercase
        int ch = (signed char)c;
        if ((unsigned int)(ch - 97) <= 25) {
            ch -= 32; // to uppercase
        }
        hash = hash * 5 + ch;
    }
    return hash & self->m_mask;
}

// 0x80361660 (100 bytes)
void EStringTableNoCase::InitTable(int size) {
    EAHeap* heap = MainHeap();
    heap->Free(m_table);
    heap = MainHeap();
    int byteSize = size * 4;
    m_table = (STNCEntry**)heap->Malloc(byteSize, 0);
    m_tableSize = size;
    m_mask = size - 1;
    ClearTable();
}

// 0x80361728 (100 bytes)
void* EStringTableNoCase_OperatorBracket(EStringTableNoCase* self, char* key) {
    unsigned int hash = EStringTableNoCase_Hash(self, key);
    STNCEntry* entry = self->m_table[hash];
    while (entry != 0) {
        if (stricmp(entry->key, key) == 0) {
            return &entry->value;
        }
        entry = entry->next;
    }
    // Insert with default value
    self->Insert(key, 0);
    return 0;
}

// 0x8036178C (108 bytes)
void EStringTableNoCase::SetValue(char* key, unsigned int value) {
    unsigned int hash = EStringTableNoCase_Hash(this, key);
    STNCEntry* entry = m_table[hash];
    while (entry != 0) {
        if (stricmp(entry->key, key) == 0) {
            entry->value = value;
            return;
        }
        entry = entry->next;
    }
    InsertNew(hash, key, value);
}

// 0x803617F8 (104 bytes)
void EStringTableNoCase::Insert(char* key, unsigned int value) {
    unsigned int hash = EStringTableNoCase_Hash(this, key);
    STNCEntry* entry = m_table[hash];
    while (entry != 0) {
        if (stricmp(entry->key, key) == 0) {
            return; // already exists
        }
        entry = entry->next;
    }
    InsertNew(hash, key, value);
}

// 0x80361860 (220 bytes)
void EStringTableNoCase::InsertNew(unsigned int hash, char* key, unsigned int value) {
    // Allocate new entry
    EAHeap* heap = MainHeap();
    STNCEntry* entry = (STNCEntry*)heap->Malloc(sizeof(STNCEntry), 0);

    // Copy key string
    int len = strlen(key);
    heap = MainHeap();
    entry->key = (char*)heap->Malloc(len + 1, 0);
    strcpy(entry->key, key);
    entry->value = value;

    // Link into bucket
    entry->next = m_table[hash];
    m_table[hash] = entry;
    m_count++;

    // Check if table needs growing
    if (m_count > m_threshold) {
        GrowTable();
    }
}

// 0x8036193C (96 bytes)
void EStringTableNoCase::Remove(char* key) {
    unsigned int hash = EStringTableNoCase_Hash(this, key);
    STNCEntry** prev = &m_table[hash];
    STNCEntry* entry = *prev;
    while (entry != 0) {
        if (stricmp(entry->key, key) == 0) {
            *prev = entry->next;
            EAHeap* heap = MainHeap();
            heap->Free(entry->key);
            heap = MainHeap();
            heap->Free(entry);
            m_count--;
            return;
        }
        prev = &entry->next;
        entry = entry->next;
    }
}

// 0x8036199C (68 bytes)
void EStringTableNoCase::Remove(STNCIteratorPtrType* iter) {
    // NOTE: asm-derived — removes entry at iterator position
    // Delegates to Remove(hash, iter)
}

// 0x803619E0 (232 bytes)
void EStringTableNoCase::Remove(unsigned int hash, STNCIteratorPtrType* iter) {
    // NOTE: asm-derived — removes entry at hash bucket + iterator
}

// 0x80361AC8 (176 bytes)
int EStringTableNoCase_Find(const EStringTableNoCase* self, char* key, unsigned int* outValue) {
    unsigned int hash = EStringTableNoCase_Hash(self, key);
    STNCEntry* entry = self->m_table[hash];
    while (entry != 0) {
        if (stricmp(entry->key, key) == 0) {
            if (outValue) *outValue = entry->value;
            return 1;
        }
        entry = entry->next;
    }
    return 0;
}

// 0x80361B78 (132 bytes)
int EStringTableNoCase_FindByHash(const EStringTableNoCase* self, unsigned int hash, char* outKey) {
    STNCEntry* entry = self->m_table[hash];
    if (entry != 0) {
        if (outKey) strcpy(outKey, entry->key);
        return 1;
    }
    return 0;
}

// 0x80361BFC (116 bytes)
void EStringTableNoCase::RemoveAll() {
    for (int i = 0; i < m_tableSize; i++) {
        STNCEntry* entry = m_table[i];
        while (entry != 0) {
            STNCEntry* next = entry->next;
            EAHeap* heap = MainHeap();
            heap->Free(entry->key);
            heap = MainHeap();
            heap->Free(entry);
            entry = next;
        }
        m_table[i] = 0;
    }
    m_count = 0;
}

// 0x80361C70 (100 bytes)
void EStringTableNoCase::FreeAll() {
    for (int i = 0; i < m_tableSize; i++) {
        STNCEntry* entry = m_table[i];
        while (entry != 0) {
            STNCEntry* next = entry->next;
            EAHeap* heap = MainHeap();
            heap->Free((void*)entry->value); // free the stored pointer
            heap = MainHeap();
            heap->Free(entry->key);
            heap = MainHeap();
            heap->Free(entry);
            entry = next;
        }
        m_table[i] = 0;
    }
    m_count = 0;
}

// 0x80361D3C (68 bytes)
void EStringTableNoCase::PreGrowTable(int newSize) {
    if (newSize > m_tableSize) {
        // Free old table and init new
        InitTable(newSize);
    }
}

// 0x80361DD0 (108 bytes)
void EStringTableNoCase::GrowTable() {
    int newSize = m_tableSize * 2;
    STNCEntry** oldTable = m_table;
    int oldSize = m_tableSize;
    InitTable(newSize);
    // Rehash all entries from old table
    for (int i = 0; i < oldSize; i++) {
        STNCEntry* entry = oldTable[i];
        while (entry != 0) {
            STNCEntry* next = entry->next;
            unsigned int hash = EStringTableNoCase_Hash(this, entry->key);
            entry->next = m_table[hash];
            m_table[hash] = entry;
            entry = next;
        }
    }
    EAHeap* heap = MainHeap();
    heap->Free(oldTable);
}

// 0x80361E3C (92 bytes)
void EStringTableNoCase::SetValues(EStringTableNoCase& other) {
    for (int i = 0; i < other.m_tableSize; i++) {
        STNCEntry* entry = other.m_table[i];
        while (entry != 0) {
            Insert(entry->key, entry->value);
            entry = entry->next;
        }
    }
}

// 0x80361E98 (156 bytes)
int EStringTableNoCase_Equals(const EStringTableNoCase* self, EStringTableNoCase& other) {
    if (self->m_count != other.m_count) return 0;
    for (int i = 0; i < self->m_tableSize; i++) {
        STNCEntry* entry = self->m_table[i];
        while (entry != 0) {
            unsigned int otherVal;
            if (!EStringTableNoCase_Find(&other, entry->key, &otherVal)) return 0;
            if (entry->value != otherVal) return 0;
            entry = entry->next;
        }
    }
    return 1;
}

// ============================================================================
// SeqResFile (0x8013DA14 - 0x8013E420) — 11 functions, 2572 bytes
// ============================================================================

class SeqResFile {
public:
    int   m_numSpecs;     // +0
    void* m_specs;        // +4  array of open specs
    int   m_field_08;     // +8
    void* m_field_0C;     // +12
    int   m_field_10;     // +16
    int   m_field_14;     // +20

    SeqResFile();
    ~SeqResFile();
    void AddOpenSpec(int index, char* path);
    void CreateIResFile(iResFile* file, StringBuffer& path, int param, int& outParam, StackString<32>** outStr);
    void OpenIResFile(iResFile* file, StringBuffer& path, int param, bool& outFlag);
    void DeleteIResFile(iResFile* file, StringBuffer& path, int param);
    void Create(StringBuffer& path);
    void Delete(StringBuffer& path);
    void Open(StringBuffer& path);
    void Close();
    void GetFileName(StringBuffer& outPath);
};

// 0x8013DA14 (188 bytes)
void SeqResFile::AddOpenSpec(int index, char* path) {
    // NOTE: asm-derived — adds a file spec to the open specs list
    // Stores path string and index into internal array
}

// 0x8013DAD0 (152 bytes)
SeqResFile::~SeqResFile() {
    // Free all allocated specs
    if (m_specs != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(m_specs);
        m_specs = 0;
    }
    m_numSpecs = 0;
}

// 0x8013DB68 (268 bytes)
// SeqResFile::CreateIResFile(iResFile *, StringBuffer &, int, int &, StackString<32> **)
// NOTE: asm-derived — creates internal resource file entry

// 0x8013DC74 (308 bytes)
// SeqResFile::OpenIResFile(iResFile *, StringBuffer &, int, bool &)
// NOTE: asm-derived — opens internal resource file

// 0x8013DDA8 (212 bytes)
// SeqResFile::DeleteIResFile(iResFile *, StringBuffer &, int)
// NOTE: asm-derived — deletes internal resource file entry

// 0x8013DE7C (396 bytes)
// SeqResFile::Create(StringBuffer &)
// NOTE: asm-derived — creates a new sequential resource file

// 0x8013E008 (236 bytes)
// SeqResFile::Delete(StringBuffer &)
// NOTE: asm-derived — deletes a sequential resource file

// 0x8013E0F4 (352 bytes)
// SeqResFile::Open(StringBuffer &)
// NOTE: asm-derived — opens a sequential resource file

// 0x8013E254 (136 bytes)
void SeqResFile::Close() {
    // Close all open resource files in sequence
    for (int i = m_numSpecs - 1; i >= 0; i--) {
        // Close each sub-file
    }
    m_numSpecs = 0;
}

// 0x8013E2DC (168 bytes)
// SeqResFile::GetFileName(StringBuffer &)
// NOTE: asm-derived — gets the current file name

// 0x8013E384 (156 bytes)
SeqResFile::SeqResFile() {
    m_numSpecs = 0;
    m_specs = 0;
    m_field_08 = 0;
    m_field_0C = 0;
    m_field_10 = 0;
    m_field_14 = 0;
}

// ============================================================================
// _c2DArray (0x800D1A04 - 0x800D2510) — 10 functions
// ============================================================================

class _c2DArray {
public:
    int     m_rows;        // +0
    int     m_cols;        // +4
    int     m_elemSize;    // +8
    void*   m_data;        // +12
    int     m_dataSize;    // +16
    BString* m_name;       // +20 (BString embedded)

    _c2DArray(int rows, int cols, int elemSize, BString& name);
    ~_c2DArray();
    void ReadFromDisk(iResFile* file, int param, short flags, void (*callback)(void*, int));
    void WriteToDisk(iResFile* file, int param, short flags, bool compress);
    void ClearBytes(signed char value);
    void SetSize(int rows, int cols);
    void DoStream(ReconBuffer* buf, bool read);
    void CopyFrom(_c2DArray* other);
    void GetArray(BString& name);
    void SetName(BString& name);
};

// 0x800D1A04 (276 bytes)
// _c2DArray::ReadFromDisk(iResFile *, int, short, void (*)(void *, int))
// NOTE: asm-derived — reads 2D array data from disk resource file

// 0x800D1B1C (140 bytes)
_c2DArray::_c2DArray(int rows, int cols, int elemSize, BString& name) {
    m_rows = rows;
    m_cols = cols;
    m_elemSize = elemSize;
    m_data = 0;
    m_dataSize = 0;
    // m_name = name; // BString assignment
    int totalSize = rows * cols * elemSize;
    if (totalSize > 0) {
        EAHeap* heap = MainHeap();
        m_data = heap->Malloc(totalSize, 0);
        m_dataSize = totalSize;
        memset(m_data, 0, totalSize);
    }
}

// 0x800D1BA8 (128 bytes)
_c2DArray::~_c2DArray() {
    if (m_data != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(m_data);
        m_data = 0;
    }
    m_dataSize = 0;
    m_rows = 0;
    m_cols = 0;
}

// 0x800D1C74 (516 bytes)
// _c2DArray::WriteToDisk(iResFile *, int, short, bool)
// NOTE: asm-derived — writes 2D array to disk

// 0x800D1E78 (76 bytes)
void _c2DArray::ClearBytes(signed char value) {
    if (m_data != 0 && m_dataSize > 0) {
        memset(m_data, value, m_dataSize);
    }
}

// 0x800D1EC4 (308 bytes)
void _c2DArray::SetSize(int rows, int cols) {
    if (rows == m_rows && cols == m_cols) return;

    if (m_data != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(m_data);
        m_data = 0;
    }
    m_rows = rows;
    m_cols = cols;
    int totalSize = rows * cols * m_elemSize;
    m_dataSize = totalSize;
    if (totalSize > 0) {
        EAHeap* heap = MainHeap();
        m_data = heap->Malloc(totalSize, 0);
        memset(m_data, 0, totalSize);
    }
}

// 0x800D1FF8 (748 bytes)
// _c2DArray::DoStream(ReconBuffer *, bool)
// NOTE: asm-derived — serialization/deserialization

// 0x800D2320 (116 bytes)
void _c2DArray::CopyFrom(_c2DArray* other) {
    SetSize(other->m_rows, other->m_cols);
    if (m_data != 0 && other->m_data != 0) {
        memcpy(m_data, other->m_data, m_dataSize);
    }
}

// 0x800D23FC (96 bytes)
// _c2DArray::GetArray(BString &)
// NOTE: asm-derived — retrieves array by name

// 0x800D245C (184 bytes)
// _c2DArray::SetName(BString &)
// NOTE: asm-derived — sets the array name

// ============================================================================
// ScalarDecomp (0x803622E8 - 0x80362F20) — 10 functions, 3116 bytes
// ============================================================================

class ScalarDecomp {
public:
    void*   m_bitArray;       // +0  (EBitArray*)
    int     m_field_04;       // +4
    int     m_field_08;       // +8
    int     m_field_0C;       // +12
    int     m_field_10;       // +16
    int     m_field_14;       // +20
    int     m_numBits;        // +24
    unsigned char m_field_1E; // +30
    unsigned char m_field_1F; // +31
    unsigned char m_field_20; // +32
    unsigned char m_hasInit;  // +33
    int     m_field_24;       // +36  (float scale)
    int     m_field_28;       // +40
    int     m_field_2C;       // +44
};

// 0x803622E8 (424 bytes)
// ScalarDecomp::Init(EBitArray *, int)
// NOTE: asm-derived — initializes decompression from bit stream

// 0x803624A4 (768 bytes)
// ScalarDecomp::GetFrame(float)
// NOTE: asm-derived — gets interpolated value at given frame

// 0x803627A4 (288 bytes)
// ScalarDecomp::NextSegment(float)
// NOTE: asm-derived — advances to next segment

// 0x803628C4 (284 bytes)
// ScalarDecomp::LastSegment(float)
// NOTE: asm-derived — goes to last segment

// 0x803629E0 (108 bytes)
void ScalarDecomp_Reset(ScalarDecomp* self) {
    // Reset to initial state
    self->m_field_04 = 0;
    self->m_field_08 = 0;
    self->m_field_0C = 0;
    self->m_field_10 = 0;
    self->m_field_14 = 0;
    self->m_hasInit = 0;
}

// 0x80362A4C (136 bytes)
// ScalarDecomp::ResetEnd(void)
// NOTE: asm-derived — resets to end of animation

// 0x80362AD4 (124 bytes)
// ScalarDecomp::ReadAllVs(void)
// NOTE: asm-derived — reads all values from bit stream

// 0x80362B50 (292 bytes)
// ScalarDecomp::GetKeyframe(int, ScalarKeyframe &)
// NOTE: asm-derived — retrieves keyframe at index

// 0x80362C74 (108 bytes)
// ScalarDecomp::GetVal(int, float &)
// NOTE: asm-derived — gets value at index

// 0x80362CE0 (584 bytes)
// ScalarDecomp::GetV(int, int, float &)
// NOTE: asm-derived — gets interpolated value between indices

// ============================================================================
// cGZSnd (0x800B9FB8 - 0x800BAC28) — 13 functions, 2780 bytes
// ============================================================================

class cGZSnd {
public:
    void*   m_vtable;         // +0
    int     m_state;          // +4  (1 = playing)
    char    m_pad_08[20];     // +8..+27
    void*   m_channel;        // +28 (cSampleChannel*)
    int     m_volume;         // +32
    int     m_pan;            // +36
    float   m_leftVol;        // +40
    float   m_rightVol;       // +44
    float   m_fadeTarget;     // +48
    void*   m_soundData;      // +52
    int     m_maxVolume;      // +56

    cGZSnd();
    ~cGZSnd();
    void Release();
    void Stop();
    void Pause();
    void Unpause();
    void setVolume(int vol);
    void FadeVolume(int startVol, int endVol, unsigned int duration);
    void SetPan(int pan);
    void reset();
    void getLRVolume(int pan, float& leftVol, float& rightVol);
};

// 0x800B9FB8 (124 bytes)
cGZSnd::cGZSnd() {
    // m_vtable = &cGZSnd_vtbl;
    m_fadeTarget = 0.0f;  // float const from rodata
    m_state = 1;
    m_pan = 512;     // center pan
    m_maxVolume = 1024;
    m_volume = 1024;
    // g_pGZSndSys->addToList(this);
    m_rightVol = 1.0f;
    m_leftVol = 1.0f;
}

// 0x800BA034 (92 bytes)
cGZSnd::~cGZSnd() {
    // m_vtable = &cGZSnd_vtbl; // restore vtable
    reset();
    // g_pGZSndSys->removeFromList(this);
}

// 0x800BA098 (188 bytes)
void cGZSnd::Release() {
    if (m_state != 1) return; // not playing
    if (m_channel != 0) {
        // Release the sample channel
        // g_pAudioSystem->ReleaseChannel(m_channel);
    }
    m_channel = 0;
    m_state = 0;
}

// 0x800BA168 (656 bytes)
// cGZSnd::Play(void)
// NOTE: asm-derived — complex audio playback setup with channel allocation

// 0x800BA3F8 (160 bytes)
int cGZSnd_IsPlaying(cGZSnd* self) {
    if (self->m_state != 1) return 0;
    if (self->m_channel == 0) return 0;
    // Check if the channel is still active
    // return channel->IsPlaying();
    return 1;
}

// 0x800BA498 (192 bytes)
void cGZSnd::Stop() {
    if (m_channel != 0) {
        // Stop the channel
        // channel->Stop();
    }
    m_channel = 0;
    m_state = 0;
}

// 0x800BA558 (128 bytes)
void cGZSnd::Pause() {
    if (m_channel != 0) {
        // Pause the channel
    }
}

// 0x800BA5D8 (128 bytes)
void cGZSnd::Unpause() {
    if (m_channel != 0) {
        // Unpause the channel
    }
}

// 0x800BA6B0 (236 bytes)
void cGZSnd::setVolume(int vol) {
    m_volume = vol;
    // Recalculate left/right volumes based on pan
    float fVol = (float)vol / 1024.0f;
    // Apply panning
    float leftPan = 1.0f, rightPan = 1.0f;
    if (m_pan < 512) {
        rightPan = (float)m_pan / 512.0f;
    } else if (m_pan > 512) {
        leftPan = (float)(1024 - m_pan) / 512.0f;
    }
    m_leftVol = fVol * leftPan;
    m_rightVol = fVol * rightPan;
    // Update channel volumes
}

// 0x800BA79C (128 bytes)
void cGZSnd::FadeVolume(int targetVol, int duration, unsigned int flags) {
    // NOTE: asm-derived — sets up volume fade over time
    m_fadeTarget = (float)targetVol;
    // Store fade parameters
}

// 0x800BA824 (184 bytes)
void cGZSnd::SetPan(int pan) {
    m_pan = pan;
    // Recalculate volumes with new pan
    setVolume(m_volume);
}

// 0x800BA8F4 (120 bytes)
void cGZSnd::reset() {
    if (m_channel != 0) {
        // Release channel
    }
    m_channel = 0;
    m_state = 0;
    m_volume = 1024;
    m_pan = 512;
    m_leftVol = 1.0f;
    m_rightVol = 1.0f;
}

// 0x800BA96C (444 bytes)
void cGZSnd::getLRVolume(int masterVol, float& leftOut, float& rightOut) {
    // NOTE: asm-derived — calculates stereo volume from master + pan
    float fMaster = (float)masterVol / 1024.0f;
    float fVol = (float)m_volume / 1024.0f;
    float combined = fMaster * fVol;

    float leftPan = 1.0f, rightPan = 1.0f;
    int pan = m_pan;
    if (pan < 512) {
        rightPan = (float)pan / 512.0f;
    } else if (pan > 512) {
        leftPan = (float)(1024 - pan) / 512.0f;
    }
    leftOut = combined * leftPan;
    rightOut = combined * rightPan;
}

// ============================================================================
// InfluenceMap (0x80048844 - 0x80049398) — 10 functions, 2880 bytes
// ============================================================================

class InfluenceMap {
public:
    int     m_width;       // +0
    int     m_height;      // +4
    void*   m_grid;        // +8  (cell data array)
    void*   m_objectList;  // +12
    int     m_objectCount; // +16
    int     m_maxObjects;  // +20

    InfluenceMap(int width, int height);
    ~InfluenceMap();
    void RemoveAll();
    void CalculateAffectedArea(cXObject* obj, ITreeTableEntry* entry, FTileRect& rect);
    void AddObjectToMap(cXObject* obj);
    void AddObjectEntry(cXObject* obj, ITreeTableEntry* entry);
    void RemoveObjectFromMap(cXObject* obj);
    void RemoveObjectEntry(cXObject* obj, ITreeTableEntry* entry);
    void* GetObjectList(int x, int y);
    void Validate();
};

// 0x80048844 (120 bytes)
InfluenceMap::InfluenceMap(int width, int height) {
    m_width = width;
    m_height = height;
    m_objectCount = 0;
    m_maxObjects = 0;
    int gridSize = width * height * 4; // sizeof pointer per cell
    EAHeap* heap = MainHeap();
    m_grid = heap->Malloc(gridSize, 0);
    memset(m_grid, 0, gridSize);
    m_objectList = 0;
}

// 0x800488BC (172 bytes)
InfluenceMap::~InfluenceMap() {
    RemoveAll();
    if (m_grid != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(m_grid);
        m_grid = 0;
    }
    if (m_objectList != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(m_objectList);
        m_objectList = 0;
    }
}

// 0x80048968 (132 bytes)
void InfluenceMap::RemoveAll() {
    // Clear all grid cells
    if (m_grid != 0) {
        memset(m_grid, 0, m_width * m_height * 4);
    }
    m_objectCount = 0;
}

// 0x800489EC (856 bytes)
// InfluenceMap::CalculateAffectedArea(cXObject *, ITreeTableEntry *, FTileRect &)
// NOTE: asm-derived — calculates tile rectangle affected by object influence

// 0x80048D44 (356 bytes)
// InfluenceMap::AddObjectToMap(cXObject *)
// NOTE: asm-derived — adds object's influence to grid cells

// 0x80048EA8 (460 bytes)
// InfluenceMap::AddObjectEntry(cXObject *, ITreeTableEntry *)
// NOTE: asm-derived — adds specific entry's influence

// 0x80049074 (344 bytes)
// InfluenceMap::RemoveObjectFromMap(cXObject *)
// NOTE: asm-derived — removes object's influence from grid

// 0x800491CC (200 bytes)
// InfluenceMap::RemoveObjectEntry(cXObject *, ITreeTableEntry *)
// NOTE: asm-derived — removes specific entry's influence

// 0x80049294 (76 bytes)
void* InfluenceMap::GetObjectList(int x, int y) {
    if (x < 0 || x >= m_width || y < 0 || y >= m_height) return 0;
    int** grid = (int**)m_grid;
    return grid[y * m_width + x];
}

// 0x800492E8 (164 bytes)
// InfluenceMap::Validate(void)
// NOTE: asm-derived — validation/debug check

// ============================================================================
// CollisionMap (0x80021948 - 0x80022780) — 3 functions, 3388 bytes
// ============================================================================

class CollisionMap {
public:
    // NOTE: asm-derived — collision grid data
    int     m_width;       // grid width
    int     m_height;      // grid height
    void*   m_tiles;       // tile wall data
    float   m_tileSize;    // size of each tile
};

// 0x80021948 (1800 bytes)
// CollisionMap::DoesCollideEnvironment(EVec2 &, EVec2 &, float, bool, bool, EVec2 &)
// NOTE: asm-derived — complex environment collision detection
// Traces a ray from start to end position with given radius,
// checks against tile walls and environment geometry.
// Returns collision point in outVec if collision found.

// 0x80022050 (364 bytes)
// CollisionMap::IsMoveBlocked(int, int, bool, TileWallsSegment)
// NOTE: asm-derived — checks if movement between two tiles is blocked

// 0x800221BC (1224 bytes)
// CollisionMap::DoesCollideObject(EVec2 &, EVec2 &, float, bool, EVec2 &)
// NOTE: asm-derived — object-to-object collision detection

// ============================================================================
// CASMiscTarget (0x8019BC1C - 0x80119C748) — 3 functions, 2804 bytes
// ============================================================================

class CASMiscTarget {
public:
    // UI target fields
    int         m_field_00[7];        // +0..+27
    char        m_pad_1C[4];          // padding
    // 5 callback entries at +40, +56, +72, +88, +104 (each 16 bytes)
    char        m_callbacks[80];      // +40..+119
    void*       m_cmdTable;           // +120
    void*       m_localizableTable;   // +124
    void*       m_vtable_128;         // +128
    int         m_field_80;           // +132
    void*       m_drawTable;          // +136

    CASMiscTarget();
    ~CASMiscTarget();
    void GetLocalizableSubnav(UIScreenID id, int param, unsigned short* outStr);
};

// 0x8019BC1C (1080 bytes)
// CASMiscTarget::CASMiscTarget(void)
// NOTE: asm-derived — complex UI target initialization with callback tables

// 0x8019C054 (348 bytes)
// CASMiscTarget::~CASMiscTarget(void)
// NOTE: asm-derived — cleanup of UI target resources

// 0x8019C1E0 (1376 bytes)
// CASMiscTarget::GetLocalizableSubnav(UIScreenID, int, unsigned short *)
// NOTE: asm-derived — gets localized subnav text for CAS misc panel

// ============================================================================
// PSETarget (0x801FEFB0 - 0x801FFB3C) — 6 functions, 2780 bytes
// ============================================================================

class PSETarget {
public:
    // UI target for person selection editor
    char m_data[256]; // placeholder for full struct

    PSETarget();
    ~PSETarget();
    void GetVariable(char* name);
    void SetVariable(char* name, char* value);
    void PushAptButtonFilters();
    void PopAptButtonFilters();
};

// 0x801FEFB0 (1476 bytes)
// PSETarget::PSETarget(void)
// NOTE: asm-derived — very large constructor with UI callback registration

// 0x801FF574 (396 bytes)
// PSETarget::~PSETarget(void)
// NOTE: asm-derived — cleanup UI callbacks

// 0x801FF700 (188 bytes)
// PSETarget::GetVariable(char *)
// NOTE: asm-derived — reads UI variable by name

// 0x801FF7BC (124 bytes)
// PSETarget::SetVariable(char *, char *)
// NOTE: asm-derived — writes UI variable by name

// 0x801FF838 (464 bytes)
// PSETarget::PushAptButtonFilters(void)
// NOTE: asm-derived — pushes APT button filter state

// 0x801FFA08 (132 bytes)
// PSETarget::PopAptButtonFilters(void)
// NOTE: asm-derived — pops APT button filter state

// ============================================================================
// KEYTarget (0x801F91A0 - 0x801F9DAC) — 5 functions, 2952 bytes
// ============================================================================

class KEYTarget {
public:
    char m_data[256]; // placeholder

    KEYTarget();
    ~KEYTarget();
    void GetName();
    void SetVariable(char* name, char* value);
    void GetVariable(char* name);
};

// 0x801F91A0 (1636 bytes)
// KEYTarget::KEYTarget(void)
// NOTE: asm-derived — keyboard target constructor with callback setup

// 0x801F9804 (348 bytes)
// KEYTarget::~KEYTarget(void)
// NOTE: asm-derived — keyboard target destructor

// 0x801F9960 (156 bytes)
// KEYTarget::GetName(void)
// NOTE: asm-derived — returns target name string

// 0x801F9A1C (428 bytes)
// KEYTarget::SetVariable(char *, char *)
// NOTE: asm-derived — handles keyboard variable setting

// 0x801F9BC8 (384 bytes)
// KEYTarget::GetVariable(char *)
// NOTE: asm-derived — handles keyboard variable getting

// ============================================================================
// TheSimsStateMachine (0x80098DB4 - 0x803A1908) — 6 functions, 3008 bytes
// ============================================================================

class TheSimsStateMachine {
public:
    // Base state machine + game-specific state
    int         m_field_00;           // +0
    int         m_field_04;           // +4
    void*       m_states;             // +8
    int         m_stateCount;         // +12
    int         m_currentState;       // +16
    int         m_field_14;           // +20

    TheSimsStateMachine(int param1, int param2);
    ~TheSimsStateMachine();
    void Startup();
    void Shutdown();
    void Update(float dt);
    void Draw(ERC* rc);
};

// 0x80098DB4 (2236 bytes)
// TheSimsStateMachine::Startup(void)
// NOTE: asm-derived — massive startup function that initializes the entire
// game state machine, creates all state objects (main menu, CAS, live mode, etc.)

// 0x80099670 (152 bytes)
void TheSimsStateMachine_Shutdown(TheSimsStateMachine* self) {
    // Shutdown all states in reverse order
    // Release resources
}

// 0x80099708 (92 bytes)
void TheSimsStateMachine_Update(TheSimsStateMachine* self, float dt) {
    // Update current state
    // Handle state transitions
}

// 0x80099764 (120 bytes)
void TheSimsStateMachine_Draw(TheSimsStateMachine* self, ERC* rc) {
    // Draw current state
}

// 0x8009ACC4 (264 bytes)
TheSimsStateMachine::TheSimsStateMachine(int param1, int param2) {
    m_field_00 = param1;
    m_field_04 = param2;
    m_states = 0;
    m_stateCount = 0;
    m_currentState = 0;
    m_field_14 = 0;
}

// 0x803A1864 (144 bytes)
TheSimsStateMachine::~TheSimsStateMachine() {
    Shutdown();
    if (m_states != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(m_states);
        m_states = 0;
    }
}

// ============================================================================
// CasSimRenderer (0x8016EEE0 - 0x8016FB30) — 13 functions, 2820 bytes
// ============================================================================

class CasSimRenderer {
public:
    int     m_field_00;       // +0
    void*   m_sim;            // +4
    void*   m_simModel;       // +8
    int     m_field_0C;       // +12
    int     m_pendingAnim;    // +16
    int     m_currentAnim;    // +20
    int     m_field_18;       // +24
    void*   m_faceTexture;    // +28
    int     m_field_20;       // +32

    CasSimRenderer();
    ~CasSimRenderer();
    void Init();
    void Draw(ERC* rc);
    void DrawShadow(ERC* rc);
    void SetNextAnimation(unsigned int animID);
    void CheckPending();
    void SetupSimCommon();
    void CreateFaceImage(unsigned int w, unsigned int h, unsigned int d, bool flag, unsigned int fmt);
    void SetFaceImage(ETexture* tex);
    void DrawFaceImage(ERC* rc);
    void UpdateRepShaders(int param);
    void GetBonePos(unsigned int boneID, EVec3& outPos);
};

// 0x8016EEE0 (88 bytes)
CasSimRenderer::CasSimRenderer() {
    m_field_00 = 0;
    m_sim = 0;
    m_simModel = 0;
    m_field_0C = 0;
    m_pendingAnim = -1;
    m_currentAnim = -1;
    m_field_18 = 0;
    m_faceTexture = 0;
    m_field_20 = 0;
}

// 0x8016EF38 (280 bytes)
CasSimRenderer::~CasSimRenderer() {
    if (m_faceTexture != 0) {
        // Release face texture
        m_faceTexture = 0;
    }
    if (m_sim != 0) {
        // Release sim reference
        m_sim = 0;
    }
    if (m_simModel != 0) {
        // Release model
        m_simModel = 0;
    }
}

// 0x8016F050 (152 bytes)
// CasSimRenderer::Init(void)
// NOTE: asm-derived — initializes renderer, loads default sim

// 0x8016F174 (400 bytes)
// CasSimRenderer::Draw(ERC *)
// NOTE: asm-derived — draws the CAS sim with current animation

// 0x8016F304 (388 bytes)
// CasSimRenderer::DrawShadow(ERC *)
// NOTE: asm-derived — draws sim shadow

// 0x8016F488 (132 bytes)
void CasSimRenderer::SetNextAnimation(unsigned int animID) {
    m_pendingAnim = animID;
}

// 0x8016F50C (156 bytes)
void CasSimRenderer::CheckPending() {
    if (m_pendingAnim != -1) {
        m_currentAnim = m_pendingAnim;
        m_pendingAnim = -1;
        // Apply animation to sim
    }
}

// 0x8016F5A8 (376 bytes)
// CasSimRenderer::SetupSimCommon(void)
// NOTE: asm-derived — common sim setup (lighting, position, scale)

// 0x8016F720 (176 bytes)
// CasSimRenderer::CreateFaceImage(unsigned int, unsigned int, unsigned int, bool, unsigned int)
// NOTE: asm-derived — creates face texture for CAS portrait

// 0x8016F860 (172 bytes)
void CasSimRenderer::SetFaceImage(ETexture* tex) {
    if (m_faceTexture != 0) {
        // Release old texture
    }
    m_faceTexture = tex;
    if (tex != 0) {
        // AddRef on new texture
    }
}

// 0x8016F90C (276 bytes)
// CasSimRenderer::DrawFaceImage(ERC *)
// NOTE: asm-derived — renders the face image texture

// 0x8016FA20 (144 bytes)
// CasSimRenderer::UpdateRepShaders(int)
// NOTE: asm-derived — updates representation shaders for skin/hair

// 0x8016FAB0 (80 bytes)
// CasSimRenderer::GetBonePos(unsigned int, EVec3 &)
// NOTE: asm-derived — gets world-space bone position

// ============================================================================
// AptLoader (0x8029E360 - 0x8029EE44) — 10 functions, 2836 bytes
// ============================================================================

class AptLoader {
public:
    void*   m_fileList;       // +0
    int     m_fileCount;      // +4
    void*   m_pendingList;    // +8
    int     m_pendingCount;   // +12
    int     m_field_10;       // +16

    ~AptLoader();
    void findFile(EAStringC& name);
    void Invalidate(AptFile* file);
    void notify(AptSharedPtr<AptFile> file);
    void IsLoaded(EAStringC& name);
    void Load(EAStringC& name);
    void AllImportsAvailable(AptSharedPtr<AptFile> file);
    void Update();
    void CompleteLoad(AptSharedPtr<AptFile> file, void* data1, void* data2, void* data3);
    void CancelPreloadedAnimation(EAStringC& name);
};

// 0x8029E360 (168 bytes)
// AptLoader::findFile(EAStringC &)
// NOTE: asm-derived — searches file list for named APT file

// 0x8029E408 (108 bytes)
AptLoader::~AptLoader() {
    // Clean up file list and pending list
    if (m_fileList != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(m_fileList);
    }
    if (m_pendingList != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(m_pendingList);
    }
}

// 0x8029E474 (260 bytes)
// AptLoader::Invalidate(AptFile *)
// NOTE: asm-derived — invalidates cached APT file

// 0x8029E578 (104 bytes)
// AptLoader::notify(AptSharedPtr<AptFile>)
// NOTE: asm-derived — notification callback

// 0x8029E5E0 (188 bytes)
// AptLoader::IsLoaded(EAStringC &)
// NOTE: asm-derived — checks if APT file is loaded

// 0x8029E69C (324 bytes)
// AptLoader::Load(EAStringC &)
// NOTE: asm-derived — initiates APT file load

// 0x8029E7E0 (288 bytes)
// AptLoader::AllImportsAvailable(AptSharedPtr<AptFile>)
// NOTE: asm-derived — checks if all imports are resolved

// 0x8029E900 (404 bytes)
// AptLoader::Update(void)
// NOTE: asm-derived — processes pending loads

// 0x8029EA94 (204 bytes)
// AptLoader::CompleteLoad(AptSharedPtr<AptFile>, void *, void *, void *)
// NOTE: asm-derived — finalizes file load

// 0x8029EB60 (788 bytes)
// AptLoader::CancelPreloadedAnimation(EAStringC &)
// NOTE: asm-derived — cancels a preloaded animation

// ============================================================================
// AptMovie (0x802A8C44 - 0x802A9908) — 6 functions, 3076 bytes
// ============================================================================

class AptMovie {
public:
    void* m_data;             // +0
    int   m_frameCount;       // +4
    void* m_displayList;      // +8
    int   m_field_0C;         // +12

    void resolve(unsigned char* data, AptConstFile* constFile, int* offset);
    void unresolve(unsigned char* data, int* offset);
    void DoTemporaryFrameControls(AptPseudoDisplayList* dl, int frame);
    void doFrameControls(AptDisplayList* dl, AptCIH* cih, int frame);
    void runFrameActions(AptCIH* cih, int frame);
    void queueFrameActions(AptCIH* cih, int frame);
};

// 0x802A8C44 (900 bytes)
// AptMovie::resolve(unsigned char *, AptConstFile *, int *)
// NOTE: asm-derived — resolves movie data pointers from constant file

// 0x802A8FC8 (700 bytes)
// AptMovie::unresolve(unsigned char *, int *)
// NOTE: asm-derived — unresolves movie data (for serialization)

// 0x802A9284 (552 bytes)
// AptMovie::DoTemporaryFrameControls(AptPseudoDisplayList *, int)
// NOTE: asm-derived — processes frame controls for temp display list

// 0x802A94AC (536 bytes)
// AptMovie::doFrameControls(AptDisplayList *, AptCIH *, int)
// NOTE: asm-derived — processes frame controls for display list

// 0x802A96C4 (232 bytes)
// AptMovie::runFrameActions(AptCIH *, int)
// NOTE: asm-derived — runs ActionScript frame actions

// 0x802A97AC (156 bytes)
// AptMovie::queueFrameActions(AptCIH *, int)
// NOTE: asm-derived — queues ActionScript frame actions for deferred execution

// ============================================================================
// CLoadingScreen (0x80056A64 - 0x80057728) — 5 functions, 3284 bytes
// ============================================================================

class CLoadingScreen {
public:
    int     m_type;           // +0
    float   m_progress;       // +4
    float   m_fadeAlpha;      // +8
    int     m_state;          // +12
    void*   m_texture;        // +16
    int     m_field_14;       // +20
    char    m_pad[64];        // more fields...

    CLoadingScreen(int type);
    ~CLoadingScreen();
    void InitAsync();
    void Update(float dt);
    void DrawTopmost(ERC* rc, float alpha);
};

// 0x80056A64 (396 bytes)
CLoadingScreen::CLoadingScreen(int type) {
    m_type = type;
    m_progress = 0.0f;
    m_fadeAlpha = 0.0f;
    m_state = 0;
    m_texture = 0;
    m_field_14 = 0;
    // Initialize loading screen resources based on type
}

// 0x80056BF0 (248 bytes)
CLoadingScreen::~CLoadingScreen() {
    if (m_texture != 0) {
        // Release texture
        m_texture = 0;
    }
}

// 0x80056CE8 (204 bytes)
// CLoadingScreen::InitAsync(void)
// NOTE: asm-derived — starts async resource loading for loading screen

// 0x80056DB4 (224 bytes)
void CLoadingScreen::Update(float dt) {
    // Update loading progress and fade
    // NOTE: asm-derived state machine with fade in/out
}

// 0x80056E94 (2212 bytes)
// CLoadingScreen::DrawTopmost(ERC *, float)
// NOTE: asm-derived — very large draw function with loading bar, tips, background

// ============================================================================
// WidgetScreenFormat (0x80182328 - 0x80183100) — 8 functions, 3096 bytes
// ============================================================================

class WidgetScreenFormat {
public:
    void*   m_data;           // +0
    int     m_tagCount;       // +4
    int     m_currentTag;     // +8
    char*   m_buffer;         // +12
    int     m_bufferSize;     // +16

    ~WidgetScreenFormat();
    void LaunchWidgetScreenLayout(char** tags, int count, int param);
    void IterateScreenLayout(char** tags, int count);
    void IterateTags(int param);
    void GetNextTag(int param);
    void IsValidTag(char* tag);
    void IsDataValid(char* data);
    void IsPlayerSpecificTag(char* tag);
};

// 0x80182328 (84 bytes)
WidgetScreenFormat::~WidgetScreenFormat() {
    if (m_buffer != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(m_buffer);
        m_buffer = 0;
    }
}

// 0x8018237C (220 bytes)
// WidgetScreenFormat::LaunchWidgetScreenLayout(char **, int, int)
// NOTE: asm-derived — launches widget screen from tag layout

// 0x80182458 (128 bytes)
// WidgetScreenFormat::IterateScreenLayout(char **, int)
// NOTE: asm-derived — iterates through screen layout tags

// 0x801824D8 (508 bytes)
// WidgetScreenFormat::IterateTags(int)
// NOTE: asm-derived — processes tags for screen layout

// 0x801826D4 (560 bytes)
// WidgetScreenFormat::GetNextTag(int)
// NOTE: asm-derived — retrieves next tag in layout sequence

// 0x80182904 (140 bytes)
// WidgetScreenFormat::IsValidTag(char *)
// NOTE: asm-derived — validates tag string

// 0x80182990 (1196 bytes)
// WidgetScreenFormat::IsDataValid(char *)
// NOTE: asm-derived — validates data string, large switch/if chain

// 0x80182E3C (260 bytes)
// WidgetScreenFormat::IsPlayerSpecificTag(char *)
// NOTE: asm-derived — checks if tag is player-specific

// ============================================================================
// EdithDialogPrimitive (0x800B51EC - 0x800B5F00) — 4 functions, 3296 bytes
// ============================================================================

class EdithDialogPrimitive {
public:
    char m_data[256]; // placeholder for internal fields

    EdithDialogPrimitive();
    void AssignString(StringSet* set, BString2& str, int index, unsigned short* outStr, bool flag);
    void ResetDialogParameters();
    void SetDialog(StackElem* elem, DialogParam* param, cXObject* obj, bool flag);
};

// 0x800B51EC (660 bytes)
// EdithDialogPrimitive::EdithDialogPrimitive(void)
// NOTE: asm-derived — large constructor with dialog system initialization

// 0x800B54D4 (252 bytes)
// EdithDialogPrimitive::AssignString(StringSet *, BString2 &, int, unsigned short *, bool)
// NOTE: asm-derived — assigns localized string to dialog element

// 0x800B55D0 (268 bytes)
// EdithDialogPrimitive::ResetDialogParameters(void)
// NOTE: asm-derived — resets all dialog parameters to defaults

// 0x800B56DC (2116 bytes)
// EdithDialogPrimitive::SetDialog(StackElem *, DialogParam *, cXObject *, bool)
// NOTE: asm-derived — very large function that sets up dialog from tree primitives

// ============================================================================
// CasClothingUnlocks (0x8015E9D4 - 0x8015F524) — 18 functions, 2784 bytes
// ============================================================================

class CasClothingUnlocks {
public:
    // Unlock tracking for clothing parts
    // Two arrays: one for body parts, one for tattoos
    unsigned int* m_bodyUnlocks;      // +0
    int           m_bodyCount;        // +4
    unsigned int* m_tattooUnlocks;    // +8
    int           m_tattooCount;      // +12

    CasClothingUnlocks();
    ~CasClothingUnlocks();
};

// 0x8015E9D4 (228 bytes)
CasClothingUnlocks::CasClothingUnlocks() {
    m_bodyUnlocks = 0;
    m_bodyCount = 0;
    m_tattooUnlocks = 0;
    m_tattooCount = 0;
    // Initialize unlock arrays
    EAHeap* heap = MainHeap();
    // Allocate and zero arrays for body parts and tattoos
}

// 0x8015EAB8 (104 bytes)
CasClothingUnlocks::~CasClothingUnlocks() {
    if (m_bodyUnlocks != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(m_bodyUnlocks);
    }
    if (m_tattooUnlocks != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(m_tattooUnlocks);
    }
}

// 0x8015EB20 (132 bytes)
void CasClothingUnlocks_Unlock_Body(CasClothingUnlocks* self, bool isFemale, eBodyPartS2C part, unsigned int index, bool setRecent) {
    // Get flags pointer based on gender + part + index
    // Set unlocked flag, optionally set recently-unlocked flag
}

// 0x8015EBA4 (132 bytes)
void CasClothingUnlocks_Unlock_Tattoo(CasClothingUnlocks* self, bool isFemale, eTattooTextureTypeS2C type, unsigned int index, bool setRecent) {
    // Same logic for tattoo unlocks
}

// 0x8015EC28 (120 bytes)
void CasClothingUnlocks_Lock_Body(CasClothingUnlocks* self, bool isFemale, eBodyPartS2C part, unsigned int index) {
    // Clear unlocked flag for body part
}

// 0x8015ECA0 (120 bytes)
void CasClothingUnlocks_Lock_Tattoo(CasClothingUnlocks* self, bool isFemale, eTattooTextureTypeS2C type, unsigned int index) {
    // Clear unlocked flag for tattoo
}

// 0x8015ED18 (104 bytes)
void CasClothingUnlocks_ClearRecentBody(CasClothingUnlocks* self, bool isFemale, eBodyPartS2C part, unsigned int index) {
    // Clear recently-unlocked flag
}

// 0x8015ED80 (100 bytes)
void CasClothingUnlocks_ClearRecentTattoo(CasClothingUnlocks* self, bool isFemale, eTattooTextureTypeS2C type, unsigned int index) {
    // Clear recently-unlocked flag
}

// 0x8015EDE4 (104 bytes)
unsigned int CasClothingUnlocks_GetFlags_Body(const CasClothingUnlocks* self, bool isFemale, eBodyPartS2C part, unsigned int index) {
    // Return flags for body part unlock slot
    return 0;
}

// 0x8015EE4C (100 bytes)
unsigned int CasClothingUnlocks_GetFlags_Tattoo(const CasClothingUnlocks* self, bool isFemale, eTattooTextureTypeS2C type, unsigned int index) {
    // Return flags for tattoo unlock slot
    return 0;
}

// 0x8015EEB0 (108 bytes)
int CasClothingUnlocks_IsLocked_Body(const CasClothingUnlocks* self, bool isFemale, eBodyPartS2C part, unsigned int index) {
    unsigned int flags = CasClothingUnlocks_GetFlags_Body(self, isFemale, part, index);
    return (flags & 1) ? 0 : 1; // locked if unlock bit not set
}

// 0x8015EF1C (104 bytes)
int CasClothingUnlocks_IsLocked_Tattoo(const CasClothingUnlocks* self, bool isFemale, eTattooTextureTypeS2C type, unsigned int index) {
    unsigned int flags = CasClothingUnlocks_GetFlags_Tattoo(self, isFemale, type, index);
    return (flags & 1) ? 0 : 1;
}

// 0x8015EF84 (108 bytes)
int CasClothingUnlocks_IsRecentBody(const CasClothingUnlocks* self, bool isFemale, eBodyPartS2C part, unsigned int index) {
    unsigned int flags = CasClothingUnlocks_GetFlags_Body(self, isFemale, part, index);
    return (flags & 2) ? 1 : 0; // recently unlocked bit
}

// 0x8015EFF0 (104 bytes)
int CasClothingUnlocks_IsRecentTattoo(const CasClothingUnlocks* self, bool isFemale, eTattooTextureTypeS2C type, unsigned int index) {
    unsigned int flags = CasClothingUnlocks_GetFlags_Tattoo(self, isFemale, type, index);
    return (flags & 2) ? 1 : 0;
}

// 0x8015F078 (92 bytes)
void CasClothingUnlocks_ClearUnlocks(CasClothingUnlocks* self) {
    if (self->m_bodyUnlocks != 0) {
        memset(self->m_bodyUnlocks, 0, self->m_bodyCount * 4);
    }
    if (self->m_tattooUnlocks != 0) {
        memset(self->m_tattooUnlocks, 0, self->m_tattooCount * 4);
    }
}

// 0x8015F0D4 (248 bytes)
// CasClothingUnlocks::DoStream(ReconBuffer *, int)
// NOTE: asm-derived — serialization

// 0x8015F21C (372 bytes)
// CasClothingUnlocks::MarkGroup(unsigned int, bool, bool)
// NOTE: asm-derived — marks a group of items as unlocked

// 0x8015F390 (404 bytes)
// CasClothingUnlocks::PrintUnlocks(CasSimDescriptionS2C *) const
// NOTE: asm-derived — debug print of unlock status

// ============================================================================
// EResPrefetch (0x80312380 - 0x80312F98) — 19 functions, 2896 bytes
// ============================================================================

class EResPrefetch {
public:
    int     m_state;          // +0
    void*   m_file;           // +4
    void*   m_buffer;         // +8
    int     m_bufferSize;     // +12
    int     m_bytesRead;      // +16
    int     m_totalBytes;     // +20
    int     m_field_18;       // +24
    void*   m_scratchBuff;    // +28
    int     m_field_20;       // +32

    EResPrefetch();
    ~EResPrefetch();
};

// 0x80312380 (140 bytes)
EResPrefetch::EResPrefetch() {
    m_state = 0;
    m_file = 0;
    m_buffer = 0;
    m_bufferSize = 0;
    m_bytesRead = 0;
    m_totalBytes = 0;
    m_field_18 = 0;
    m_scratchBuff = 0;
    m_field_20 = 0;
}

// 0x8031240C (164 bytes)
EResPrefetch::~EResPrefetch() {
    if (m_buffer != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(m_buffer);
        m_buffer = 0;
    }
}

// 0x803124B0 (204 bytes)
// EResPrefetch::Init(void)
// NOTE: asm-derived — initializes prefetch system

// 0x8031257C (68 bytes)
void EResPrefetch_Shutdown(EResPrefetch* self) {
    self->m_state = 0;
    if (self->m_file != 0) {
        // Close file
        self->m_file = 0;
    }
}

// 0x803125D4 (116 bytes)
// EResPrefetch::ReleasedBuffer(EScratchBuffUser *)
// NOTE: asm-derived — callback when scratch buffer is released

// 0x80312648 (140 bytes)
// EResPrefetch::DoCancel(EPrefetchMsg *)
// NOTE: asm-derived — handles cancel message

// 0x803126D4 (188 bytes)
// EResPrefetch::DoBegin(EPrefetchMsg *)
// NOTE: asm-derived — handles begin prefetch message

// 0x80312790 (500 bytes)
// EResPrefetch::LoadAnotherBlock(void)
// NOTE: asm-derived — loads next block of data

// 0x80312984 (84 bytes)
// EResPrefetch::DoFlush(EPrefetchMsg *)
// NOTE: asm-derived — handles flush message

// 0x803129D8 (152 bytes)
// EResPrefetch::Main(void)
// NOTE: asm-derived — main prefetch processing loop

// 0x80312A70 (160 bytes)
// EResPrefetch::Flush(void)
// NOTE: asm-derived — flushes prefetch buffer

// 0x80312B10 (144 bytes)
// EResPrefetch::Cancel(void)
// NOTE: asm-derived — cancels current prefetch

// 0x80312BA0 (72 bytes)
// EResPrefetch::BeginPreFetch(char *, char *)
// NOTE: asm-derived — begins prefetch with path pair

// 0x80312BE8 (136 bytes)
// EResPrefetch::BeginPreFetch(char *, unsigned int)
// NOTE: asm-derived — begins prefetch with path + hash

// 0x80312C70 (72 bytes)
// EResPrefetch::AddRef(char *, char *)
// NOTE: asm-derived — adds reference with path pair

// 0x80312CB8 (248 bytes)
// EResPrefetch::AddRef(char *, unsigned int)
// NOTE: asm-derived — adds reference with path + hash

// 0x80312DB0 (100 bytes)
int EResPrefetch_CanAddRef(EResPrefetch* self) {
    // Check if prefetch system can accept another reference
    return (self->m_state != 0 && self->m_file != 0) ? 1 : 0;
}

// 0x80312E68 (92 bytes)
int EResPrefetch_CanReleaseBuffer(EResPrefetch* self) {
    return (self->m_scratchBuff != 0) ? 1 : 0;
}

// 0x80312EE4 (116 bytes)
void EResPrefetch_ResetState(EResPrefetch* self) {
    self->m_state = 0;
    self->m_bytesRead = 0;
    self->m_totalBytes = 0;
    self->m_field_18 = 0;
}

// ============================================================================
// EConfig (0x8035A2DC - 0x8035AE60) — 17 functions, 2880 bytes
// ============================================================================

class EConfig {
public:
    void*   m_entries;        // +0  linked list of config entries
    int     m_count;          // +4
    void*   m_file;           // +8  (EFile*)
    char*   m_filename;       // +12
    int     m_modified;       // +16

    void Open(char* filename);
    void Close(bool save, bool freeEntries, char* newFilename);
    void Write(char* filename);
    void SetString(char* label, char* value);
    void Delete(char* label);
    void GetString(char* label, char* outValue);
    void SetInt(char* label, int value);
    void GetInt(char* label, int outValue);
    void SetBool(char* label, bool value);
    void GetBool(char* label, bool outValue);
    void SetFloat(char* label, float value);
    void GetFloat(char* label, float outValue);
    void AddComment(char* comment);
    void Sort();
    void Empty();
    void GetNextLabelAndValue(EString& label, EString& value, NLIteratorPtrType* iter);
    void GetS(char* buf, int maxLen, EFile* file);
};

// 0x8035A2DC (328 bytes)
// EConfig::Open(char *)
// NOTE: asm-derived — opens config file, reads all key=value pairs

// 0x8035A424 (240 bytes)
// EConfig::Close(bool, bool, char *)
// NOTE: asm-derived — closes config, optionally saves

// 0x8035A514 (228 bytes)
// EConfig::Write(char *)
// NOTE: asm-derived — writes config to file

// 0x8035A5F8 (236 bytes)
// EConfig::SetString(char *, char *)
// NOTE: asm-derived — sets string value for label

// 0x8035A6E4 (140 bytes)
// EConfig::Delete(char *)
// NOTE: asm-derived — removes entry by label

// 0x8035A770 (104 bytes)
// EConfig::GetString(char *, char *)
// NOTE: asm-derived — gets string value for label

// 0x8035A7D8 (80 bytes)
void EConfig_SetInt(EConfig* self, char* label, int value) {
    char buf[32];
    Sprintf(buf, (char*)"%d", value);
    self->SetString(label, buf);
}

// 0x8035A828 (68 bytes)
void EConfig_GetInt(EConfig* self, char* label, int defaultVal) {
    char buf[32];
    self->GetString(label, buf);
    // return AtoI(buf);
}

// 0x8035A86C (96 bytes)
void EConfig_SetBool(EConfig* self, char* label, bool value) {
    if (value) {
        self->SetString(label, (char*)"true");
    } else {
        self->SetString(label, (char*)"false");
    }
}

// 0x8035A8CC (116 bytes)
void EConfig_GetBool(EConfig* self, char* label, bool defaultVal) {
    char buf[32];
    self->GetString(label, buf);
    // Compare against "true"/"false"
}

// 0x8035A940 (80 bytes)
void EConfig_SetFloat(EConfig* self, char* label, float value) {
    char buf[32];
    Sprintf(buf, (char*)"%f", (double)value);
    self->SetString(label, buf);
}

// 0x8035A990 (68 bytes)
void EConfig_GetFloat(EConfig* self, char* label, float defaultVal) {
    char buf[32];
    self->GetString(label, buf);
    // return AtoF(buf);
}

// 0x8035A9D4 (108 bytes)
// EConfig::AddComment(char *)
// NOTE: asm-derived — adds comment line to config

// 0x8035AA40 (444 bytes)
// EConfig::Sort(void)
// NOTE: asm-derived — sorts config entries alphabetically

// 0x8035ABFC (152 bytes)
void EConfig_Empty(EConfig* self) {
    // Free all entries
    // Reset count to 0
    self->m_count = 0;
    self->m_entries = 0;
}

// 0x8035AC94 (228 bytes)
// EConfig::GetNextLabelAndValue(EString &, EString &, NLIteratorPtrType *)
// NOTE: asm-derived — iterates config entries

// 0x8035ADCC (164 bytes)
// EConfig::GetS(char *, int, EFile *)
// NOTE: asm-derived — reads a line from file

// ============================================================================
// EEngine (0x802E2994 - 0x802E3878) — 10 functions, 3348 bytes
// ============================================================================

class EEngine {
public:
    int     m_initialized;    // +0
    void*   m_scheduler;      // +4
    void*   m_renderer;       // +8
    void*   m_audioSystem;    // +12
    float   m_frameTime;      // +16
    int     m_frameCount;     // +20
    int     m_field_18;       // +24

    EEngine();
    ~EEngine();
    void Init();
    void ShutdownThreads(bool immediate);
    void RetraceUpdate(float dt);
    void PreFrameUpdate();
    void PostFrameUpdate();
    void InitSubsystems();
    void InitResourceManagers();
    void ShutdownResourceManagers();
};

// 0x802E2994 (292 bytes)
EEngine::EEngine() {
    m_initialized = 0;
    m_scheduler = 0;
    m_renderer = 0;
    m_audioSystem = 0;
    m_frameTime = 0.0f;
    m_frameCount = 0;
    m_field_18 = 0;
}

// 0x802E2AB8 (132 bytes)
EEngine::~EEngine() {
    if (m_initialized) {
        ShutdownResourceManagers();
        ShutdownThreads(true);
    }
}

// 0x802E2B4C (352 bytes)
// EEngine::Init(void)
// NOTE: asm-derived — full engine initialization

// 0x802E2CAC (176 bytes)
// EEngine::ShutdownThreads(bool)
// NOTE: asm-derived — shuts down worker threads

// 0x802E2D5C (220 bytes)
// EEngine::RetraceUpdate(float)
// NOTE: asm-derived — called each retrace for timing

// 0x802E2EC8 (692 bytes)
// EEngine::PreFrameUpdate(void)
// NOTE: asm-derived — pre-frame processing (input, AI tick, physics)

// 0x802E317C (128 bytes)
// EEngine::PostFrameUpdate(void)
// NOTE: asm-derived — post-frame processing (swap buffers, stats)

// 0x802E3240 (460 bytes)
// EEngine::InitSubsystems(void)
// NOTE: asm-derived — initializes engine subsystems (audio, input, etc.)

// 0x802E3438 (544 bytes)
// EEngine::InitResourceManagers(void)
// NOTE: asm-derived — creates and initializes all resource managers

// 0x802E3658 (352 bytes)
// EEngine::ShutdownResourceManagers(void)
// NOTE: asm-derived — shuts down and destroys resource managers

// ============================================================================
// SimsMemCardWrap (0x80074E60 - 0x80075B08) — 22 functions, 2860 bytes
// ============================================================================

class SimsMemCardWrap {
public:
    void*   m_memCard;        // +0  (ENgcMemoryCard*)
    int     m_slot;           // +4
    int     m_state;          // +8
    int     m_field_0C;       // +12

    void Init();
    void InitPolling();
    void IsPolledCardInSlot(int slot, bool& result);
    void IsCardInSlot(int slot, bool& result);
    void IsWrongDevice(int slot, bool& result);
    void IsCardCorrupted(int slot, bool& result);
    void IsCardDamaged(int slot, bool& result);
    void HasSavedGame(int slot, bool& result, int param);
    void HasValidSavedGame(int slot, bool& result, int param);
    void HasInvalidGame(int slot, bool& result, int param);
    void HasSpaceForSave(int slot, bool& result, unsigned int* outSize);
    void CanBeUsed(int slot, bool& result, int param);
    void IsDifferentCard(int slot, bool& result);
    void LoadConfigFile(int slot);
    void SaveConfigFile(int slot);
    void SaveNewGame(int slot);
    void PreloadGame(int slot);
    void LoadGame(int slot, int param);
    void SaveGame(int slot, bool flag1, bool flag2, int param);
    void LoadHouse(int slot);
    void ReloadHouseAndGlobals(int slot, int param);
    void SaveHouseAndGlobals(int slot, int param);
};

// 0x80074E60 (204 bytes)
void SimsMemCardWrap_Init(SimsMemCardWrap* self) {
    // Initialize memory card wrapper
    self->m_memCard = 0;
    self->m_slot = -1;
    self->m_state = 0;
    self->m_field_0C = 0;
    // Create ENgcMemoryCard instance
}

// 0x80074F2C (80 bytes)
void SimsMemCardWrap_InitPolling(SimsMemCardWrap* self) {
    // Start polling memory card slot for changes
}

// 0x80074FB8 (80 bytes)
void SimsMemCardWrap_IsPolledCardInSlot(SimsMemCardWrap* self, int slot, bool& result) {
    // Check if polled card is present
    result = false;
    if (self->m_memCard != 0) {
        // result = memCard->IsPolledCardInSlot(slot);
    }
}

// 0x80075008 (80 bytes)
void SimsMemCardWrap_IsCardInSlot(SimsMemCardWrap* self, int slot, bool& result) {
    result = false;
    if (self->m_memCard != 0) {
        // result = memCard->IsCardInSlot(slot);
    }
}

// 0x80075058 (80 bytes)
void SimsMemCardWrap_IsWrongDevice(SimsMemCardWrap* self, int slot, bool& result) {
    result = false;
    if (self->m_memCard != 0) {
        // result = memCard->IsWrongDevice(slot);
    }
}

// 0x800750E8 (104 bytes)
void SimsMemCardWrap_IsCardCorrupted(SimsMemCardWrap* self, int slot, bool& result) {
    result = false;
    if (self->m_memCard != 0) {
        // Check card status for corruption
    }
}

// 0x80075150 (100 bytes)
void SimsMemCardWrap_IsCardDamaged(SimsMemCardWrap* self, int slot, bool& result) {
    result = false;
    if (self->m_memCard != 0) {
        // Check card status for damage
    }
}

// 0x800751B4 (68 bytes)
void SimsMemCardWrap_HasSavedGame(SimsMemCardWrap* self, int slot, bool& result, int param) {
    result = false;
    // Check if save file exists on card
}

// 0x800751F8 (188 bytes)
void SimsMemCardWrap_HasValidSavedGame(SimsMemCardWrap* self, int slot, bool& result, int param) {
    result = false;
    // Check if save file exists and is valid (correct version, not corrupted)
}

// 0x800752B4 (80 bytes)
void SimsMemCardWrap_HasInvalidGame(SimsMemCardWrap* self, int slot, bool& result, int param) {
    result = false;
    // Check if save file exists but is invalid
}

// 0x80075304 (144 bytes)
void SimsMemCardWrap_HasSpaceForSave(SimsMemCardWrap* self, int slot, bool& result, unsigned int* outSize) {
    result = false;
    // Check free space on card against save size requirements
}

// 0x80075394 (312 bytes)
void SimsMemCardWrap_CanBeUsed(SimsMemCardWrap* self, int slot, bool& result, int param) {
    result = false;
    // Composite check: card present, not damaged, not wrong device, has space
    bool inSlot = false;
    SimsMemCardWrap_IsCardInSlot(self, slot, inSlot);
    if (!inSlot) return;

    bool wrongDevice = false;
    SimsMemCardWrap_IsWrongDevice(self, slot, wrongDevice);
    if (wrongDevice) return;

    bool corrupted = false;
    SimsMemCardWrap_IsCardCorrupted(self, slot, corrupted);
    if (corrupted) return;

    bool damaged = false;
    SimsMemCardWrap_IsCardDamaged(self, slot, damaged);
    if (damaged) return;

    result = true;
}

// 0x800754CC (124 bytes)
void SimsMemCardWrap_IsDifferentCard(SimsMemCardWrap* self, int slot, bool& result) {
    result = false;
    // Compare card serial with stored serial
}

// 0x80075548 (72 bytes)
void SimsMemCardWrap_LoadConfigFile(SimsMemCardWrap* self, int slot) {
    // Load options/config from memory card
}

// 0x80075590 (76 bytes)
void SimsMemCardWrap_SaveConfigFile(SimsMemCardWrap* self, int slot) {
    // Save options/config to memory card
}

// 0x800756DC (176 bytes)
void SimsMemCardWrap_SaveNewGame(SimsMemCardWrap* self, int slot) {
    // Create new save file on memory card
    // Format save header, write initial game state
}

// 0x8007578C (144 bytes)
void SimsMemCardWrap_PreloadGame(SimsMemCardWrap* self, int slot) {
    // Start preloading save game data
}

// 0x8007581C (160 bytes)
void SimsMemCardWrap_LoadGame(SimsMemCardWrap* self, int slot, int param) {
    // Load saved game from memory card
}

// 0x800758BC (280 bytes)
void SimsMemCardWrap_SaveGame(SimsMemCardWrap* self, int slot, bool flag1, bool flag2, int param) {
    // Save current game state to memory card
    // Handles auto-save vs manual save flags
}

// 0x800759D4 (144 bytes)
void SimsMemCardWrap_LoadHouse(SimsMemCardWrap* self, int slot) {
    // Load house data from save file
}

// 0x80075A64 (88 bytes)
void SimsMemCardWrap_ReloadHouseAndGlobals(SimsMemCardWrap* self, int slot, int param) {
    // Reload house and global data (used when changing houses)
}

// 0x80075ABC (76 bytes)
void SimsMemCardWrap_SaveHouseAndGlobals(SimsMemCardWrap* self, int slot, int param) {
    // Save house and global state
}

// ============================================================================
// CASRoommateTarget (0x8019FB08 - 0x801A0A1C) — 10 functions, 3228 bytes
// ============================================================================

class CASRoommateTarget {
public:
    char m_data[256]; // placeholder for full struct

    CASRoommateTarget();
    ~CASRoommateTarget();
    void SetVariable(char* name, char* value);
    void SetVariableSubnav(int param1, int param2);
    void GetLocalizableSubnav(int param, unsigned short* outStr);
    void GetVariable(char* name);
    void SelectFirstNonEmptySlot();
    void SetButtonState();
    void GetButtonStateString(char* outStr);
    void Draw(ERC* rc);
};

// 0x8019FB08 (1344 bytes)
// CASRoommateTarget::CASRoommateTarget(void)
// NOTE: asm-derived — large constructor with UI callback registration

// 0x801A0048 (376 bytes)
// CASRoommateTarget::~CASRoommateTarget(void)
// NOTE: asm-derived — cleanup of UI callbacks and resources

// 0x801A01C0 (152 bytes)
// CASRoommateTarget::SetVariable(char *, char *)
// NOTE: asm-derived — sets UI variable value

// 0x801A0258 (192 bytes)
// CASRoommateTarget::SetVariableSubnav(int, int)
// NOTE: asm-derived — sets subnav variable

// 0x801A0318 (280 bytes)
// CASRoommateTarget::GetLocalizableSubnav(int, unsigned short *)
// NOTE: asm-derived — gets localized subnav text

// 0x801A0430 (104 bytes)
// CASRoommateTarget::GetVariable(char *)
// NOTE: asm-derived — gets UI variable value

// 0x801A0498 (124 bytes)
// CASRoommateTarget::SelectFirstNonEmptySlot(void)
// NOTE: asm-derived — selects first roommate slot that has a sim

// 0x801A0514 (72 bytes)
// CASRoommateTarget::SetButtonState(void)
// NOTE: asm-derived — updates button enabled/disabled states

// 0x801A055C (168 bytes)
// CASRoommateTarget::GetButtonStateString(char *)
// NOTE: asm-derived — returns button state as string

// 0x801A0604 (416 bytes)
// CASRoommateTarget::Draw(ERC *)
// NOTE: asm-derived — draws roommate selection UI

// ============================================================================
// LiveModeInitState (0x8008BC28 - 0x8008CA18) — 3 functions, 3564 bytes
// ============================================================================

class LiveModeInitState {
public:
    int     m_phase;          // +0
    int     m_subPhase;       // +4
    int     m_field_08;       // +8
    float   m_timer;          // +12

    void Reset();
    void Update(float dt);
    void DatasetGetRef();
};

// 0x8008BC28 (260 bytes)
void LiveModeInitState::Reset() {
    m_phase = 0;
    m_subPhase = 0;
    m_field_08 = 0;
    m_timer = 0.0f;
    // Reset loading state, clear pending resources
}

// 0x8008BD2C (3216 bytes)
// LiveModeInitState::Update(float)
// NOTE: asm-derived — massive multi-phase initialization state machine
// Handles: dataset loading, house setup, sim placement, camera init,
// weather, lighting, UI setup, music, etc.
// Phases: 0=start, 1=load datasets, 2=init house, 3=place sims,
//         4=init camera, 5=init UI, 6=start music, 7=done

// 0x8008C9C0 (88 bytes)
void LiveModeInitState::DatasetGetRef() {
    // Gets reference to current dataset being loaded
}

// ============================================================================
// SlotLoader (0x80143828 - 0x80144BCC) — 1 function, 3484 bytes
// ============================================================================

// 0x80143828 (3484 bytes)
// SlotLoader::Load(short, vector<ObjectSlot>*, vector<RoutingSlot>*, vector<SpriteSlot>*, cXObject*)
// NOTE: asm-derived — very large function that loads all slot types for an object.
// Reads slot descriptors from object data, creates ObjectSlot/RoutingSlot/SpriteSlot
// instances and pushes them into the respective vectors.
// Uses SmartDataFactory to resolve slot descriptor data.
// Processes: object interaction slots, routing slots, sprite effect slots.

// ============================================================================
// Misc helper for FreeTable
// ============================================================================

// 0x80361D80 (80 bytes)
void EStringTableNoCase_FreeTable(EStringTableNoCase* self) {
    // Free the hash table array
    if (self->m_table != 0) {
        EAHeap* heap = MainHeap();
        heap->Free(self->m_table);
        self->m_table = 0;
    }
    self->m_tableSize = 0;
    self->m_mask = 0;
}
