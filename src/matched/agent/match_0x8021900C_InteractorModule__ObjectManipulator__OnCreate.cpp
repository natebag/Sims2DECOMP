/* InteractorModule::ObjectManipulator::OnCreate(void) at 0x8021900C (52B) */

struct IM_Viz_ObjManip_OC {
    void CreateResources(struct IM_ObjManip_OC& m);
};

struct IM_ObjManip_OC {
    IM_Viz_ObjManip_OC* GetVisualizer();
    void OnCreate();
};

void IM_ObjManip_OC::OnCreate() {
    GetVisualizer()->CreateResources(*this);
}
