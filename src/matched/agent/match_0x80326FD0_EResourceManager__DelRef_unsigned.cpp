// 0x80326FD0 EResourceManager::DelRef(unsigned (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; li 0,0; stw 31,0x8(1); mr 30,4; li 4,-1; mr 29,5; lwz 9,0x0(31); stw 0,0xc(1); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,31,3; blrl; mr 4,30; addi 3,31,3336; addi 5,1,12; bl _s80326FD0_0; lwz 4,0xc(1); cmpwi 4,0; bne 0f; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; b 1f; 0:; mr 3,31; mr 5,29; bl _s80326FD0_1; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80326FD0_0();
extern "C" void _s80326FD0_1();
extern "C" void f_80326FD0() {}
