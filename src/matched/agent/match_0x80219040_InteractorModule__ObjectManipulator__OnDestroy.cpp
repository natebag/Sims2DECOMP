/* InteractorModule::ObjectManipulator::OnDestroy(void) at 0x80219040 (52B) */

struct IM_Viz_ObjManip_OD {
    void DestroyResources(struct IM_ObjManip_OD& m);
};

struct IM_ObjManip_OD {
    IM_Viz_ObjManip_OD* GetVisualizer();
    void OnDestroy();
};

void IM_ObjManip_OD::OnDestroy() {
    GetVisualizer()->DestroyResources(*this);
}
