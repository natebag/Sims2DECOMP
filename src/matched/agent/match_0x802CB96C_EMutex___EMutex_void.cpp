// 0x802CB96C EMutex::~EMutex(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 30,3; mr 29,4; addi 9,9,-24184; addi 3,30,4; li 4,2; stw 9,0x0(30); bl _s802CB96C_0; mr 3,30; mr 4,29; bl _s802CB96C_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802CB96C_0();
extern "C" void _s802CB96C_1();
extern "C" void f_802CB96C() {}
