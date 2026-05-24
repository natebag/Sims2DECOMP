// 0x800F99E0 ObjectModuleImpl::GetGlobalRoutingSlot(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 4,4,60; lwz 3,0x2078(3); add 3,3,4"

struct ObjectModuleImpl {
    void GetGlobalRoutingSlot();
};

void ObjectModuleImpl::GetGlobalRoutingSlot() {
}
