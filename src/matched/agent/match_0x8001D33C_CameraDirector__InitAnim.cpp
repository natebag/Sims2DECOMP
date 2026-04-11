// CameraDirector::InitAnim(int)
// Address: 0x8001D33C | Size: 44 bytes
// Pattern: wrapper calling EAnimController::Init

// Forward declarations
typedef unsigned int uint;
typedef int eAnimatedObjectType;

struct EAnimController {
    void* m_vtable;
    // ... other fields
};

struct CameraDirector {
    char pad[0x1A8];  // 424 bytes
    EAnimController m_animController;
};

// Function declaration for the external Init function
extern "C" void _ZN15EAnimController4InitEj19eAnimatedObjectTypej(EAnimController* self, uint, eAnimatedObjectType, uint);

void CameraDirector__InitAnim(CameraDirector* self, unsigned int param) {
    _ZN15EAnimController4InitEj19eAnimatedObjectTypej(&self->m_animController, param, (eAnimatedObjectType)2, 0);
}
