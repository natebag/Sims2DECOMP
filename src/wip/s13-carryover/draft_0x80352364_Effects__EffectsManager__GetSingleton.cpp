// 0x80352364 (60B) Effects::EffectsManager::GetSingleton(void)
// Lazy singleton: if (!s_inst) s_inst = new EffectsManager(); return s_inst;
// Calls __builtin_new(28) for sizeof(EffectsManager).

extern void* __builtin_new(unsigned int);

namespace Effects {

class EffectsManager {
public:
    EffectsManager();
    static EffectsManager* GetSingleton();
};

extern EffectsManager* s_inst;

EffectsManager* EffectsManager::GetSingleton() {
    if (!s_inst) {
        s_inst = new EffectsManager();
    }
    return s_inst;
}

}  // namespace Effects
