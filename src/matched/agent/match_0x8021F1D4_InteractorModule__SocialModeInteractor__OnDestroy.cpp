/* InteractorModule::SocialModeInteractor::OnDestroy(void) at 0x8021F1D4 (52B) */

struct IM_Viz_SocModeIntr_OD {
    void DestroyResources(struct IM_SocModeIntr_OD& m);
};

struct IM_SocModeIntr_OD {
    IM_Viz_SocModeIntr_OD* GetVisualizer();
    void OnDestroy();
};

void IM_SocModeIntr_OD::OnDestroy() {
    GetVisualizer()->DestroyResources(*this);
}
