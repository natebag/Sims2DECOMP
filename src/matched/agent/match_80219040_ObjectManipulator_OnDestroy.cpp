void *OM_GetMgr2();
void OM_DestroyVis(void *mgr, void *self);

struct ObjectManipulator_OnDestroy_S {
    void OnDestroy();
};

void ObjectManipulator_OnDestroy_S::OnDestroy() {
    void *mgr = OM_GetMgr2();
    OM_DestroyVis(mgr, this);
}
