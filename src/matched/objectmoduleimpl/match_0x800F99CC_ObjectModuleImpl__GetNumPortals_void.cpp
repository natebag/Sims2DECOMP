// 0x800F99CC ObjectModuleImpl::GetNumPortals(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x2068(3); lwz 3,0x206c(3); subf 3,0,3; srawi 3,3,2"

struct ObjectModuleImpl {
    void GetNumPortals();
};

void ObjectModuleImpl::GetNumPortals() {
}
