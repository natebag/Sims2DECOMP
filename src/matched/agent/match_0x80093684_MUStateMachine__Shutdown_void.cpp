// 0x80093684 MUStateMachine::Shutdown(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80093684_0; addi 3,30,60; bl _s80093684_1; mr 3,30; bl _s80093684_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80093684_0();
extern "C" void _s80093684_1();
extern "C" void _s80093684_2();
extern "C" void f_80093684() {}
