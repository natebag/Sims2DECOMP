// 0x8029AE18 AptDisplayList::removeObject(AptCIH (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr. 31,4; beq 1f; lwz 0,0x0(31); andis. 9,0,2048; beq 1f; lwz 11,0x48(31); cmpwi 11,0; beq 0f; lwz 9,0x8(11); addi 29,31,12; lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0xc(31); lis 9,-32700; addi 9,9,-6476; mr 30,3; cmpw 0,9; beq 0f; cmpwi 30,0; beq 0f; mr 4,29; bl _s8029AE18_0; cmpw 3,31; bne 0f; mr 3,30; mr 4,29; bl _s8029AE18_1; 0:; mr 3,31; bl _s8029AE18_2; mr 3,31; bl _s8029AE18_3; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8029AE18_0();
extern "C" void _s8029AE18_1();
extern "C" void _s8029AE18_2();
extern "C" void _s8029AE18_3();
extern "C" void f_8029AE18() {}
