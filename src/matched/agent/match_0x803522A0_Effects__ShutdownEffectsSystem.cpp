// 0x803522A0 (68B) Effects::ShutdownEffectsSystem(void)
// SDA-flag guarded shutdown: if flag==0 return 0; flag=0; GetSingleton()->Shutdown(); return 1.

namespace Effects {

class EffectsManager {
public:
    static EffectsManager* GetSingleton();
    void Shutdown();
};

extern int s_initFlag;

int ShutdownEffectsSystem();

int ShutdownEffectsSystem() {
    if (s_initFlag != 0) {
        s_initFlag = 0;
        EffectsManager::GetSingleton()->Shutdown();
        return 1;
    }
    return 0;
}

}  // namespace Effects
