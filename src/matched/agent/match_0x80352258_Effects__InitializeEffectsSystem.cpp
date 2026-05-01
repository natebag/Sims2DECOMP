// 0x80352258 (72B) Effects::InitializeEffectsSystem(void)
// SDA-flag guarded init: if flag==0 → flag=1; InitEffectsMath(); FastParticleEmitter::InitModule();
// then GetSingleton()->Initialize(); else return 0.

namespace Effects {

void InitEffectsMath();

class FastParticleEmitter {
public:
    static void InitModule();
};

class EffectsManager {
public:
    static EffectsManager* GetSingleton();
    int Initialize();
};

extern int s_initFlag;

int InitializeEffectsSystem();

int InitializeEffectsSystem() {
    if (s_initFlag == 0) {
        s_initFlag = 1;
        InitEffectsMath();
        FastParticleEmitter::InitModule();
        return EffectsManager::GetSingleton()->Initialize();
    }
    return 0;
}

}  // namespace Effects
