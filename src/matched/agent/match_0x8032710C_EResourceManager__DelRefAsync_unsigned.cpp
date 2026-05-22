// 0x8032710C EResourceManager::DelRefAsync(unsigned (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lwz 11,-22652(13); mr 31,3; mr 30,4; cmpwi 11,0; beq 0f; lwz 9,0x0(11); mr 4,31; mr 5,30; lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; 0:; stw 31,0x8(1); li 0,0; li 4,-1; lwz 9,0x0(31); stw 0,0xc(1); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,31,3; blrl; mr 4,30; addi 3,31,3336; addi 5,1,12; bl _s8032710C_0; lwz 4,0xc(1); cmpwi 4,0; beq 1f; lha 0,0xc(4); cmpwi 0,0; beq 1f; lha 0,0xe(4); cmpwi 0,0; bne 1f; mr 3,31; li 5,1; bl _s8032710C_1; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; b 2f; 1:; lwz 11,0x8(1); lwz 9,0x0(11); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22652(13); mr 4,31; mr 5,30; lwz 9,0x0(11); lha 3,0x60(9); lwz 0,0x64(9); add 3,11,3; mtspr 8,0; blrl; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8032710C_0();
extern "C" void _s8032710C_1();
extern "C" void f_8032710C() {}
