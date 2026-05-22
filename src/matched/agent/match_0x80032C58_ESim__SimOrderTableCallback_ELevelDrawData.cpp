// 0x80032C58 ESim::SimOrderTableCallback(ELevelDrawData (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lwz 31,0x24(4); mr 28,3; lwz 27,0x98(28); lwz 0,0x528(31); cmpwi 0,0; beq 3f; lwz 6,0x358(31); cmpwi 6,0; li 30,0; beq 0f; lwz 30,0x18(6); 0:; lwz 29,0x344(31); cmpwi 29,0; beq 4f; cmpwi 30,0; beq 4f; lwz 0,0x62c(31); cmpwi 0,0; bne 2f; lwz 3,0x3d0(31); lwz 9,0x4(3); lha 0,0x218(9); lwz 9,0x21c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 1f; lwz 4,0x63c(31); mr 6,29; mr 7,30; mr 3,27; addi 4,4,104; li 5,0; li 8,0; bl _s80032C58_0; b 2f; 1:; lwz 4,0x63c(31); mr 5,29; mr 6,30; mr 3,27; addi 4,4,104; li 7,0; bl _s80032C58_1; 2:; lwz 0,0x52c(31); cmpwi 0,0; beq 3f; li 0,0; lwz 3,0x63c(31); stw 0,0x52c(31); bl _s80032C58_2; 3:; mr 3,31; mr 4,27; bl _s80032C58_3; li 0,0; stw 0,0xb8(28); stw 0,0xac(28); stw 0,0xb4(28); stw 0,0xa8(28); 4:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80032C58_0();
extern "C" void _s80032C58_1();
extern "C" void _s80032C58_2();
extern "C" void _s80032C58_3();
extern "C" void f_80032C58() {}
