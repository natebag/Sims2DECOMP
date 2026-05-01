// 0x80352364 (60B) Effects::EffectsManager::GetSingleton(void)
// Lazy singleton: SDA-loaded s_inst pointer; sizeof(EffectsManager) = 28.

extern void* __builtin_new(unsigned int);

namespace Effects {

class EffectsManager {
public:
    char m_data[28];
    EffectsManager();
    static EffectsManager* GetSingleton();
};

extern EffectsManager* s_inst;

EffectsManager* EffectsManager::GetSingleton() {
    if (s_inst == 0) {
        s_inst = new EffectsManager();
    }
    return s_inst;
}

}  // namespace Effects
