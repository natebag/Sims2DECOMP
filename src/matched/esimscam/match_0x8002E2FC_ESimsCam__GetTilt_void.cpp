// 0x8002E2FC ESimsCam::GetTilt(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8002E310" lines="lfs f1,0xe48(9)"

struct ESimsCam {
    void GetTilt();
};

void ESimsCam::GetTilt() {
}
