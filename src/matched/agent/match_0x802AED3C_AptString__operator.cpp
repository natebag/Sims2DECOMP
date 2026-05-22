// 0x802AED3C AptString::operator (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 0,3; mr 5,4; lwz 3,-23020(13); mr 4,0; bl _s802AED3C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802AED3C_0();
extern "C" void f_802AED3C() {}
