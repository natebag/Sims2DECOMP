// 0x802CB914 EMutex::EMutex(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; addi 29,30,4; bl _s802CB914_0; lis 9,-32697; mr 3,29; addi 9,9,-24184; stw 9,0x0(30); bl _s802CB914_1; mr 3,29; li 4,1; li 5,-1; bl _s802CB914_2; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802CB914_0();
extern "C" void _s802CB914_1();
extern "C" void _s802CB914_2();
extern "C" void f_802CB914() {}
