/* InteractorModule::SimInteractor::OnCreate(void) at 0x8021D3F4 (52B) */

struct IM_Viz_SimIntr_OC {
    void CreateResources(struct IM_SimIntr_OC& m);
};

struct IM_SimIntr_OC {
    IM_Viz_SimIntr_OC* GetVisualizer();
    void OnCreate();
};

void IM_SimIntr_OC::OnCreate() {
    GetVisualizer()->CreateResources(*this);
}
