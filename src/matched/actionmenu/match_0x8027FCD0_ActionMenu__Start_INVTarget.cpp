// 0x8027FCD0 ActionMenu::Start(INVTarget (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"

struct ActionMenu {
    void Start_INVTarget();
};

void ActionMenu::Start_INVTarget() {
}
