// 0x80338028 ENgcPerf::ReadMetrics(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,-26336(13); cmpwi 0,0; beq 2f; bl _s80338028_0; bl _s80338028_1; mr 31,3; bl _s80338028_2; mr 30,3; bl _s80338028_3; mr 29,3; bl _s80338028_4; lwz 0,-26332(13); lis 9,-32700; addi 9,9,10240; cmplw 30,31; rlwinm 0,0,6,0,25; ble 0f; mr 30,31; 0:; stwx 30,9,0; cmplw 3,29; addi 9,9,4; ble 1f; mr 3,29; 1:; stwx 3,9,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80338028_0();
extern "C" void _s80338028_1();
extern "C" void _s80338028_2();
extern "C" void _s80338028_3();
extern "C" void _s80338028_4();
extern "C" void f_80338028() {}
