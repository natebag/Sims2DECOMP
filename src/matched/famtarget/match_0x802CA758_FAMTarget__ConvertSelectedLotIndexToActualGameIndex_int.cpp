// 0x802CA758 FAMTarget::ConvertSelectedLotIndexToActualGameIndex(int) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 1,1,32"

struct FAMTarget {
    void ConvertSelectedLotIndexToActualGameIndex();
};

void FAMTarget::ConvertSelectedLotIndexToActualGameIndex() {
}
