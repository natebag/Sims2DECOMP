// 0x803523A0 (40B) Effects::EffectsManager::Initialize(void)
// One-shot init: return 1 if first time and set flag; return 0 thereafter.
// SN pins `this` to r9 via `mr r9,r3` even with no other r3 use.

namespace Effects {

class EffectsManager {
public:
    int m_initialized;
    int Initialize();
};

int EffectsManager::Initialize() {
    register EffectsManager* self asm("r9") = this;
    if (self->m_initialized) return 0;
    self->m_initialized = 1;
    return 1;
}

}  // namespace Effects
