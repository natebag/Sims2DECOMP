// 0x802094F0 (16 bytes) - InteractorModule::Interactor::AddIdleTime(float)
// lfs f0, 88(r3); fadds f0, f0, f1; stfs f0, 88(r3); blr  =>  m_idleTime += dt;

struct Interactor_IT {
    char pad[0x58];
    float m_idleTime;

    void AddIdleTime(float dt);
};

void Interactor_IT::AddIdleTime(float dt) {
    m_idleTime += dt;
}
