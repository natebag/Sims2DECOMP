// 0x80095DC4 StateMachine::CallState(int) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s80095DC4_0; mr. 3,3; beq 0f; stw 3,0x84(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80095DC4_0();
extern "C" void f_80095DC4() {}
