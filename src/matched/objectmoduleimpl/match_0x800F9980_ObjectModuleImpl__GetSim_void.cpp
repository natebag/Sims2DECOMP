// 0x800F9980 ObjectModuleImpl::GetSim(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-21496(13)"

struct ObjectModuleImpl {
    void GetSim();
};

void ObjectModuleImpl::GetSim() {
}
