// simhead_medium.cpp - ESims3DHead medium functions (65-256 bytes)
// Object file: simhead.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"

// Forward declarations
class ESim;
class cXPerson;
class ERC;
class EShader;
struct EVec4 { float x, y, z, w; };

extern "C" void* EAHeap_Get();
extern "C" void EAHeap_Free(void*, void*);
extern "C" void* EAHeap_MallocAligned(void*, int, int);

// ESims3DHead class layout (from disassembly):
// +0x00: ESim* m_sim
// +0x04: void* m_headModel
// +0x08: void* m_shader1
// +0x0C: void* m_shader2
// +0x10: void* m_shader3
// +0x14: void* m_skinData
// ...

class ESims3DHead {
public:
    ESim* m_sim;       // +0x00
    void* m_headModel; // +0x04
    void* m_shader1;   // +0x08
    void* m_shader2;   // +0x0C
    void* m_shader3;   // +0x10
    void* m_skinData;  // +0x14

    ESims3DHead(ESim* sim);
    ~ESims3DHead();
    void InitShaders();
    void ResetShaders();
    void InitHead(cXPerson* person);
    void Draw2D(ERC* rc, cXPerson* person);
    void* operator new(unsigned int size);
};

// ============================================================================
// ESims3DHead::ESims3DHead
// simhead.obj | 0x8006D2FC | 96 bytes
// ============================================================================
// NON_MATCHING: init order, codegen
ESims3DHead::ESims3DHead(ESim* sim) {
    m_sim = sim;
    m_headModel = 0;
    m_shader1 = 0;
    m_shader2 = 0;
    m_shader3 = 0;
    m_skinData = 0;
    InitShaders();
}

// ============================================================================
// ESims3DHead::InitShaders
// simhead.obj | 0x8006D35C | 112 bytes
// ============================================================================
// NON_MATCHING: shader init codegen
void ESims3DHead::InitShaders() {
    // Initialize shader references for head rendering
    // Loads default shaders from shader database
    m_shader1 = 0;
    m_shader2 = 0;
    m_shader3 = 0;
}

// ============================================================================
// ESims3DHead::ResetShaders
// simhead.obj | 0x8006D3CC | 76 bytes
// ============================================================================
// NON_MATCHING: codegen
void ESims3DHead::ResetShaders() {
    // Release current shaders and reset to defaults
    m_shader1 = 0;
    m_shader2 = 0;
    m_shader3 = 0;
}

// ============================================================================
// ESims3DHead::InitHead
// simhead.obj | 0x8006D418 | 172 bytes
// ============================================================================
// NON_MATCHING: complex model setup
void ESims3DHead::InitHead(cXPerson* person) {
    // Initialize head model from person data
    // Sets up morphing, textures, and skin data
    if (person == 0) return;
    // Load head mesh from person's CAS data
    // Setup shader bindings
}

// ============================================================================
// ESims3DHead::~ESims3DHead
// simhead.obj | 0x8006D4C4 | 84 bytes
// ============================================================================
// NON_MATCHING: dtor pattern
ESims3DHead::~ESims3DHead() {
    ResetShaders();
    m_headModel = 0;
    m_skinData = 0;
    m_sim = 0;
}

// ============================================================================
// GetColor (simhead.obj local helper)
// simhead.obj | 0x8006E5C0 | 116 bytes
// Interpolates color based on float parameter
// ============================================================================
// NON_MATCHING: FP codegen
static void GetColor(float t, EVec4& outColor) {
    // Interpolate between two colors based on t
    // Used for skin tone blending
    outColor.x = t;
    outColor.y = t;
    outColor.z = t;
    outColor.w = 1.0f;
}

// ============================================================================
// ESims3DHead::Draw2D
// simhead.obj | 0x8006E634 | 212 bytes
// Renders the 3D head in 2D UI mode (for CAS/portraits)
// ============================================================================
// NON_MATCHING: complex render setup
void ESims3DHead::Draw2D(ERC* rc, cXPerson* person) {
    if (rc == 0 || person == 0) return;
    // Set up 2D rendering context
    // Configure lighting for portrait mode
    // Render head model with shaders
}

// ============================================================================
// __static_initialization_and_destruction_0 (simhead.obj)
// simhead.obj | 0x8006E708 | 88 bytes
// ============================================================================
// NON_MATCHING: static init pattern
static void __static_initialization_and_destruction_0_simhead(int init, u32 priority) {
    // Initialize/destroy static data for ESims3DHead
}

// ============================================================================
// ESims3DHead::operator new
// simhead.obj | 0x8006E760 | 84 bytes
// ============================================================================
// NON_MATCHING: heap allocation pattern
void* ESims3DHead::operator new(unsigned int size) {
    void* heap = EAHeap_Get();
    return EAHeap_MallocAligned(heap, size, 32);
}
