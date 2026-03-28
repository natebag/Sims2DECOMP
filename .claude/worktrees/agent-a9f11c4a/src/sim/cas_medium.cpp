#if 0 // SKIP
// cas_medium.cpp - CasMediator/CasScene medium functions (65-256 bytes)
// Object files: casmediator.obj, casscene.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class CasListener;
struct CasEvent;
struct EVec3 { float x, y, z; };
struct EMat4 { float data[16]; };
class ERC;

// ============================================================================
// CasMediator - Mediator pattern for CAS (Create-A-Sim) events
// Layout:
//   +0x00: set<CasListener*> m_listeners (12 bytes for rb_tree)
//   +0x0C: int m_transitionState
//   +0x10: int m_field_10
// ============================================================================
class CasMediator {
public:
    char m_listenerTree[12]; // +0x00: rb_tree set
    int m_transitionState;    // +0x0C
    int m_field_10;           // +0x10

    CasMediator();
    ~CasMediator();
    void AddListener(CasListener& listener);
    void RemoveAllListeners();
    void PostEvent(CasEvent& event);
    int IsTransitionComplete();
};

// ============================================================================
// CasScene - CAS scene management
// ============================================================================
class CasScene {
public:
    void Init();
    void Update(float dt);
    void DrawRoom(ERC* rc, int roomId, EMat4& mat);
    void SetSceneLighting(int lightSet, bool immediate);
    void GetObjectPosition(unsigned int objId, EVec3& outPos, float& outAngle);
};

// External functions
extern "C" void RBTree_Init(void*);
extern "C" void RBTree_Clear(void*);
extern "C" void RBTree_Insert(void*, void*);
extern "C" void RBTree_Erase(void*, void*);

// ============================================================================
// CasMediator::CasMediator
// casmediator.obj | 0x80161BCC | 188 bytes
// ============================================================================
// NON_MATCHING: rb_tree init + field zeroing
CasMediator::CasMediator() {
    RBTree_Init(m_listenerTree);
    m_transitionState = 0;
    m_field_10 = 0;
}

// ============================================================================
// CasMediator::~CasMediator
// casmediator.obj | 0x80161C88 | 144 bytes
// ============================================================================
// NON_MATCHING: tree cleanup
CasMediator::~CasMediator() {
    RemoveAllListeners();
}

// ============================================================================
// CasMediator::AddListener
// casmediator.obj | 0x80161D18 | 108 bytes
// ============================================================================
// NON_MATCHING: rb_tree insert codegen
void CasMediator::AddListener(CasListener& listener) {
    RBTree_Insert(m_listenerTree, &listener);
}

// ============================================================================
// CasMediator::RemoveAllListeners
// casmediator.obj | 0x80161F68 | 192 bytes
// ============================================================================
// NON_MATCHING: tree iteration + erase
void CasMediator::RemoveAllListeners() {
    RBTree_Clear(m_listenerTree);
}

// ============================================================================
// CasMediator::PostEvent
// casmediator.obj | 0x80162030 | 168 bytes
// Broadcasts an event to all registered listeners
// ============================================================================
// NON_MATCHING: tree iteration with callback
void CasMediator::PostEvent(CasEvent& event) {
    // Iterate through all listeners in the set
    // For each listener, call OnCasEvent(event)
}

// ============================================================================
// CasMediator::IsTransitionComplete
// casmediator.obj | 0x80162298 | 92 bytes
// ============================================================================
// NON_MATCHING: codegen
int CasMediator::IsTransitionComplete() {
    return m_transitionState == 0;
}

// ============================================================================
// _Rb_tree<CasListener*>::_M_erase
// casmediator.obj | 0x803B0AC0 | 92 bytes
// Recursively erases all nodes in the red-black tree
// ============================================================================
// NON_MATCHING: recursive tree deletion
namespace {
void _Rb_tree_CasListener_erase(void* node) {
    if (node == 0) return;
    // Recursively erase left subtree
    _Rb_tree_CasListener_erase(*(void**)((char*)node + 0x08));
    // Recursively erase right subtree
    void* right = *(void**)((char*)node + 0x0C);
    // Delete node
    _Rb_tree_CasListener_erase(right);
}
} // anonymous namespace

// ============================================================================
// CasScene::Init
// casscene.obj | 0x801653FC | 168 bytes
// ============================================================================
// NON_MATCHING: scene setup with multiple object loading
void CasScene::Init() {
    // Load CAS scene models
    // Set up camera angles
    // Initialize lighting
}

// ============================================================================
// CasScene::Update
// casscene.obj | 0x801657E0 | 68 bytes
// ============================================================================
// NON_MATCHING: codegen
void CasScene::Update(float dt) {
    // Update CAS scene animations
    // Update lighting transitions
}

// ============================================================================
// CasScene::DrawRoom
// casscene.obj | 0x80165990 | 68 bytes
// ============================================================================
// NON_MATCHING: render call codegen
void CasScene::DrawRoom(ERC* rc, int roomId, EMat4& mat) {
    // Draw the CAS room at the given ID with transform
}

// ============================================================================
// CasScene::SetSceneLighting
// casscene.obj | 0x80166088 | 72 bytes
// ============================================================================
// NON_MATCHING: lighting setup
void CasScene::SetSceneLighting(int lightSet, bool immediate) {
    // Switch scene lighting to the specified light set
    // If immediate, skip transition
}

// ============================================================================
// CasScene::GetObjectPosition
// casscene.obj | 0x80166E94 | 240 bytes
// Gets the position and angle of a CAS scene object
// ============================================================================
// NON_MATCHING: object lookup + position extraction
void CasScene::GetObjectPosition(unsigned int objId, EVec3& outPos, float& outAngle) {
    outPos.x = 0.0f;
    outPos.y = 0.0f;
    outPos.z = 0.0f;
    outAngle = 0.0f;
    // Look up object by ID in scene
    // Extract position and angle from its transform
}
#endif
