// 0x8021C1D4 InteractorModule::PlacementObject::CanObjectBeDestroyed (52b)

extern int CanObjectBeDestroyedTarget(void*);

struct PlacementObject {
    void* m_obj;
};

int PlacementObject_CanObjectBeDestroyed(PlacementObject* self) {
    void* p = self->m_obj;
    if (!p) return 0;
    return CanObjectBeDestroyedTarget(p);
}
