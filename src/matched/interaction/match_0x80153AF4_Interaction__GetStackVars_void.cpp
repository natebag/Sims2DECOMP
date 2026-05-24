// 0x80153AF4 Interaction::GetStackVars(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_80153B40" lines="addi 30,30,20"

struct Interaction {
    void GetStackVars();
};

void Interaction::GetStackVars() {
}
