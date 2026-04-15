// 0x8021F0D8 InteractorModule::SimInteractor::GetPlumbBobShadowSave (20B)
// Atomic take-and-reset to -1

namespace InteractorModule {

struct SimInteractor {
    char pad[400];
    int m_plumbBobShadowSave;  // +400
    int GetPlumbBobShadowSave();
};

int SimInteractor::GetPlumbBobShadowSave() {
    int save = m_plumbBobShadowSave;
    m_plumbBobShadowSave = -1;
    return save;
}

}
