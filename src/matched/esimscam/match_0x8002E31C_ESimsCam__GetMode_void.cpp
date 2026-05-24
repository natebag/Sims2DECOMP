// 0x8002E31C ESimsCam::GetMode(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 1,1,16"

struct ESimsCam {
    void GetMode();
};

void ESimsCam::GetMode() {
}
