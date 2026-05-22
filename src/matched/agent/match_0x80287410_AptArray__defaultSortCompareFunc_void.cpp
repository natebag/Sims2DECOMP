// 0x80287410 AptArray::defaultSortCompareFunc(void (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); lis 11,-32700; lwz 30,0x0(4); lhz 9,-6476(11); addi 0,11,-6476; lwz 3,0x0(3); addi 4,1,8; addi 9,9,2; stw 0,0x10(1); sth 9,-6476(11); stw 0,0x8(1); bl _s80287410_0; mr 3,30; addi 4,1,16; bl _s80287410_1; lwz 3,0x8(1); lwz 4,0x10(1); addi 3,3,8; addi 4,4,8; bl _s80287410_2; lwz 4,0x10(1); mr 30,3; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80287410_3; 0:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80287410_4; 1:; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s80287410_0();
extern "C" void _s80287410_1();
extern "C" void _s80287410_2();
extern "C" void _s80287410_3();
extern "C" void _s80287410_4();
extern "C" void f_80287410() {}
