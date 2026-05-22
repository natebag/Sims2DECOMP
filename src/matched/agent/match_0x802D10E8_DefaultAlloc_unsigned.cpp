// 0x802D10E8 DefaultAlloc(unsigned (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s802D10E8_0; mr 4,31; li 5,0; bl _s802D10E8_1; mr. 3,3; bne 0f; bl _s802D10E8_2; mr 4,31; li 5,0; bl _s802D10E8_3; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802D10E8_0();
extern "C" void _s802D10E8_1();
extern "C" void _s802D10E8_2();
extern "C" void _s802D10E8_3();
extern "C" void f_802D10E8() {}
