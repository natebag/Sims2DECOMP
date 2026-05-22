// 0x802A9848 AptMovie::labelToFrame(EAStringC (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x8(3); bl _s802A9848_0; mr. 0,3; li 3,-1; beq 0f; mr 3,0; bl _s802A9848_1; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802A9848_0();
extern "C" void _s802A9848_1();
extern "C" void f_802A9848() {}
