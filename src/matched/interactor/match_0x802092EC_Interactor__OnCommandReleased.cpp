// 0x802092EC (104B) InteractorModule::Interactor::OnCommandReleased(InteractorModule::InteractorInputManager::InteractorCommand)
// Two-branch float-store pattern: cmd==7 resets m_field52/56, cmd==8 resets m_field60/64.
// Float constant (0.0f) loaded from non-SDA global (lis r9,-32704; lfs f0,-12724(r9)).
// stfs+lwz stack temp pattern forces GCC to store float bits via int into int-typed fields.
// addi r11,r1,8 gives GCC a second base for vals[1]; vals[0] accessed directly via r1+8.

namespace InteractorModule {

extern char kStickCenter[16];

struct Interactor {
    char pad[52];
    int m_field52;
    int m_field56;
    int m_field60;
    int m_field64;

    void OnCommandReleased(int cmd);
};

void Interactor::OnCommandReleased(int cmd) {
    if (cmd == 7) {
        volatile float vals[2];
        volatile float* p = vals;
        float v = *(float*)kStickCenter;
        p[1] = v;
        vals[0] = v;
        m_field56 = *(int*)&p[1];
        m_field52 = *(int*)&vals[0];
    } else if (cmd == 8) {
        volatile float vals[2];
        volatile float* p = vals;
        float v = *(float*)kStickCenter;
        p[1] = v;
        vals[0] = v;
        m_field64 = *(int*)&p[1];
        m_field60 = *(int*)&vals[0];
    }
}

}
