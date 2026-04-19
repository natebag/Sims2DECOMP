/* InteractorModule::SimInteractor::OnDestroy(void) at 0x8021D428 (52B) */

struct IM_Viz_SimIntr_OD {
    void DestroyResources(struct IM_SimIntr_OD& m);
};

struct IM_SimIntr_OD {
    IM_Viz_SimIntr_OD* GetVisualizer();
    void OnDestroy();
};

void IM_SimIntr_OD::OnDestroy() {
    GetVisualizer()->DestroyResources(*this);
}
