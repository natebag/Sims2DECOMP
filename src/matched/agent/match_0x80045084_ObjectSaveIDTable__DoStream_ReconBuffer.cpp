// 0x80045084 ObjectSaveIDTable::DoStream(ReconBuffer (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 27,3; li 0,1; lwz 29,0x0(27); mr 30,4; stw 0,0xc(1); mr 3,30; addi 4,1,12; addis 28,29,1; bl _s80045084_0; addi 31,28,-32768; lwz 0,0xc(1); cmpwi 0,0; beq 0f; mr 3,30; bl _s80045084_1; 0:; mr 3,30; addi 4,1,8; li 5,1; bl _s80045084_2; li 0,0; stw 0,-32768(28); lha 9,0x8(1); cmpwi 9,0; beq 2f; 1:; addi 4,1,10; li 5,1; mr 3,30; bl _s80045084_3; lha 4,0xa(1); mr 3,27; bl _s80045084_4; lwz 9,0x0(31); addi 4,1,8; lhz 11,0x8(1); li 5,1; rlwinm 9,9,3,0,28; add 9,9,29; stw 3,0x4(9); mr 3,30; lwz 0,0x0(31); rlwinm 0,0,3,0,28; sthx 11,29,0; lwz 9,0x0(31); addi 9,9,1; stw 9,0x0(31); bl _s80045084_5; lha 0,0x8(1); cmpwi 0,0; bne 1b; 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s80045084_0();
extern "C" void _s80045084_1();
extern "C" void _s80045084_2();
extern "C" void _s80045084_3();
extern "C" void _s80045084_4();
extern "C" void _s80045084_5();
extern "C" void f_80045084() {}
