// 0x800F9928 ObjectModuleImpl::GetFolder(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-21508(13)"

struct ObjectModuleImpl {
    void GetFolder();
};

void ObjectModuleImpl::GetFolder() {
}
