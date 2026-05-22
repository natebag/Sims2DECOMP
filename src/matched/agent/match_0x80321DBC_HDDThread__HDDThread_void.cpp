// 0x80321DBC HDDThread::HDDThread(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 29,31; addi 31,30,832; bl _s80321DBC_0; lis 9,-32697; addi 9,9,-18528; stw 9,0x338(30); 0:; mr 3,31; bl _s80321DBC_1; addi 31,31,20; cmpwi 29,0; addi 29,29,-1; bne 0b; li 0,0; li 9,1; stw 0,0x5c0(30); li 4,0; stw 9,0x5c4(30); li 5,28; stw 0,0x5c8(30); addi 3,30,1488; stw 0,0x5cc(30); bl _s80321DBC_2; li 4,0; li 5,28; addi 3,30,1516; bl _s80321DBC_3; li 4,0; li 5,28; addi 3,30,1544; bl _s80321DBC_4; addi 3,30,1572; li 4,0; li 5,28; bl _s80321DBC_5; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80321DBC_0();
extern "C" void _s80321DBC_1();
extern "C" void _s80321DBC_2();
extern "C" void _s80321DBC_3();
extern "C" void _s80321DBC_4();
extern "C" void _s80321DBC_5();
extern "C" void f_80321DBC() {}
