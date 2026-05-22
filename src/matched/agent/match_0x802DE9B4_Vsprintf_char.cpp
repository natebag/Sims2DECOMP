// 0x802DE9B4 Vsprintf(char (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 0,4; mr 6,5; lis 4,32767; mr 5,0; ori 4,4,65535; bl _s802DE9B4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802DE9B4_0();
extern "C" void f_802DE9B4() {}
