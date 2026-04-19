/* InteractorModule::SocialModeInteractor::OnCreate(void) at 0x8021F198 (60B) */

struct IM_Viz_SocModeIntr_OC {
    void CreateResources(struct IM_SocModeIntr_OC& m);
};

struct IM_SocModeIntr_OC {
    char m_pad[96];
    short m_field60;
    IM_Viz_SocModeIntr_OC* GetVisualizer();
    void OnCreate();
};

void IM_SocModeIntr_OC::OnCreate() {
    GetVisualizer()->CreateResources(*this);
    m_field60 = -1;
}
