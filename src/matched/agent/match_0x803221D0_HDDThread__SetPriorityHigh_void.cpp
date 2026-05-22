// 0x803221D0 HDDThread::SetPriorityHigh(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lis 31,-32694; addi 3,31,-10620; bl _s803221D0_0; cmpwi 3,0; beq 0f; addi 3,31,-10620; bl _s803221D0_1; cmpwi 3,0; beq 0f; mr 3,30; li 4,23; bl _s803221D0_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803221D0_0();
extern "C" void _s803221D0_1();
extern "C" void _s803221D0_2();
extern "C" void f_803221D0() {}
