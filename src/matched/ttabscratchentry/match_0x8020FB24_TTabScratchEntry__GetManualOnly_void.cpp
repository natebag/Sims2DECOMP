// 0x8020FB24 TTabScratchEntry::GetManualOnly(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8020FD28" lines="stw 0,0x4(31); lwz 9,0x4(29); addi 9,9,8; stw 9,0x4(29)"

struct TTabScratchEntry {
    void GetManualOnly();
};

void TTabScratchEntry::GetManualOnly() {
}
