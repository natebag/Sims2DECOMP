// 0x8021F0C8 (16 bytes) - InteractorModule::SimInteractor::SetPlumbBobShadowSave(unsigned int)
// cmpwi r4, -1; beqlr; stw r4, 400(r3); blr  =>  if (val != -1) m_shadowSave = val;

struct SimInteractor_PS {
    char pad[0x190];
    unsigned int m_shadowSave;

    void SetPlumbBobShadowSave(unsigned int val);
};

void SimInteractor_PS::SetPlumbBobShadowSave(unsigned int val) {
    if (val == 0xFFFFFFFF) return;
    m_shadowSave = val;
}
