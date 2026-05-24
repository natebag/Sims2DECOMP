// 0x8022DD90 TreeTableQuickData::GetImplementation(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8022DDAC" lines="mr 11,3"

struct TreeTableQuickData {
    void GetImplementation();
};

void TreeTableQuickData::GetImplementation() {
}
