// 0x80095D08 StateMachine::Draw(ERC (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x94(3); cmpwi 0,0; beq 0f; addi 3,3,60; bl _s80095D08_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80095D08_0();
extern "C" void f_80095D08() {}
