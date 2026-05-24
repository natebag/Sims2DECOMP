// 0x8009625C StateMachine::PushStatus(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; li 3,24; bl _s8009625C_0; lis 9,-32706; addi 11,30,60; lfs f0,-30544(9); addi 5,30,84; lwz 9,0x4(11); addi 4,1,8; lwz 6,0x14(11); lwz 10,0x8(11); lwz 8,0xc(11); lwz 7,0x10(11); lwz 0,0x3c(30); stfs f0,0x14(3); stfs f0,0x10(3); stw 0,0x0(3); stw 9,0x4(3); stw 10,0x8(3); stw 8,0xc(3); stw 7,0x10(3); stw 6,0x14(3); stw 3,0x8(1); lwz 9,0x18(5); lwz 11,0x10(5); addi 9,9,-4; cmpw 11,9; beq 0f; stw 3,0x0(11); lwz 9,0x10(5); addi 9,9,4; stw 9,0x10(5); b 1f; 0:; mr 3,5; bl _s8009625C_1; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s8009625C_0();
extern "C" void _s8009625C_1();

struct StateMachine {
    void PushStatus();
};

void StateMachine::PushStatus() {
}
