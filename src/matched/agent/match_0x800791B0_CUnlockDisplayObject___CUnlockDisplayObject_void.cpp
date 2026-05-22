// 0x800791B0 CUnlockDisplayObject::~CUnlockDisplayObject(void) (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 9,-32698; lwz 11,0x1c(31); addi 9,9,-12984; mr 29,4; stw 9,0x84(31); cmpwi 11,0; beq 0f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x8(31); cmpwi 0,0; beq 3f; lwz 3,0x14(31); cmpwi 3,0; beq 1f; bl _s800791B0_0; b 2f; 1:; lis 3,-32692; lwz 4,0x2c(31); addi 3,3,-27556; bl _s800791B0_1; 2:; lwz 0,0x80(31); cmpwi 0,0; bne 3f; lis 3,-32693; lwz 4,0x34(31); addi 3,3,11064; bl _s800791B0_2; 3:; lwz 3,0x10(31); cmpwi 3,0; beq 5f; bl _s800791B0_3; lwz 3,0x10(31); cmpwi 3,0; beq 4f; li 4,3; bl _s800791B0_4; 4:; li 0,0; stw 0,0x10(31); 5:; lwz 30,0x24(31); cmpwi 30,0; beq 6f; bl _s800791B0_5; mr 4,30; bl _s800791B0_6; li 0,0; stw 0,0x24(31); 6:; andi. 0,29,1; beq 7f; mr 3,31; bl _s800791B0_7; 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800791B0_0();
extern "C" void _s800791B0_1();
extern "C" void _s800791B0_2();
extern "C" void _s800791B0_3();
extern "C" void _s800791B0_4();
extern "C" void _s800791B0_5();
extern "C" void _s800791B0_6();
extern "C" void _s800791B0_7();
extern "C" void f_800791B0() {}
