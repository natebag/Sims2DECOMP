// 0x8009696C StateMachine::StateMachine(int, (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); lis 9,-32706; lis 11,-32698; lfs f0,-30480(9); mr 30,3; li 29,0; addi 11,11,-7936; li 0,-1; li 28,1; stw 4,0x0(30); addi 7,30,44; stw 11,0x18(30); addi 8,30,52; stw 5,0x1c(30); addi 9,30,60; stw 0,0xc(30); addi 11,30,84; stw 0,0x4(30); addi 10,30,100; stw 29,0x8(30); addi 5,30,116; stw 29,0x10(30); addi 6,30,124; stw 28,0x14(30); mr 3,11; stw 29,0x20(30); li 4,0; stw 29,0x24(30); stfs f0,0x28(30); stw 29,0x2c(30); stw 29,0x4(7); stw 29,0x4(8); stw 29,0x3c(30); stfs f0,0x14(9); stw 29,0x4(9); stw 29,0x8(9); stw 29,0xc(9); stfs f0,0x10(9); stw 29,0x54(30); stw 29,0x4(11); stw 29,0x8(11); stw 29,0xc(11); stw 29,0x64(30); stw 29,0xc(10); stw 29,0x4(10); stw 29,0x8(10); stw 29,0x4(5); stw 29,0x4(6); bl _s8009696C_0; stw 29,0x90(30); mr 3,30; stw 28,0x94(30); stw 29,0x84(30); stw 29,0x88(30); stw 29,0x8c(30); lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"

extern "C" void _s8009696C_0();

struct StateMachine {
    void StateMachine();
};

void StateMachine::StateMachine() {
}
