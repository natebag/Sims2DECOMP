// 0x801C29C4 M2MTarget::IsItemEnabled(int) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x168(3); li 9,1; cmpwi 0,0; bne 0f; li 9,0; b 3f; 0:; lwz 0,0x10c(3); cmpwi 0,255; bne 1f; bl _s801C29C4_0; b 2f; 1:; lwz 0,0x110(3); cmpwi 0,255; bne 3f; bl _s801C29C4_1; 2:; mr 9,3; 3:; mr 3,9; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801C29C4_0();
extern "C" void _s801C29C4_1();
extern "C" void f_801C29C4() {}
