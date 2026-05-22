// 0x80325358 EQuickdataManager::Reload(unsigned (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 31,3; li 0,0; stw 31,0x8(1); mr 29,4; li 4,-1; lwz 9,0x0(31); stw 0,0xc(1); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,31,3; blrl; mr 4,29; addi 5,1,12; addi 3,31,3336; bl _s80325358_0; lwz 11,0x8(1); lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; lwz 30,0xc(1); cmpwi 30,0; beq 1f; lwz 3,-22652(13); lwz 9,0x0(3); lha 0,0x108(9); lwz 9,0x10c(9); add 3,3,0; mtspr 8,9; blrl; mr 4,29; mr 3,31; addi 5,1,16; bl _s80325358_1; mr. 4,3; bne 0f; lwz 4,0x8(30); addi 5,1,20; addi 6,1,24; mr 3,31; bl _s80325358_2; mr 3,31; bl _s80325358_3; lwz 3,0x50(31); li 5,0; lwz 4,0x14(1); lwz 9,0x28(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; lwz 4,0x50(31); 0:; mr 3,30; bl _s80325358_4; lwz 3,-22652(13); lwz 9,0x0(3); lha 0,0x110(9); lwz 9,0x114(9); add 3,3,0; mtspr 8,9; blrl; 1:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s80325358_0();
extern "C" void _s80325358_1();
extern "C" void _s80325358_2();
extern "C" void _s80325358_3();
extern "C" void _s80325358_4();
extern "C" void f_80325358() {}
