void *OM_GetMgr();
void OM_CreateVis(void *mgr, void *self);

struct ObjectManipulator_OnCreate_S {
    void OnCreate();
};

void ObjectManipulator_OnCreate_S::OnCreate() {
    void *mgr = OM_GetMgr();
    OM_CreateVis(mgr, this);
}
