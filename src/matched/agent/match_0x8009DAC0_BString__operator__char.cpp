// 0x8009DAC0 BString::operator=(char) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; stb 4,0x8(1); bl _s8009DAC0_0; mr 29,3; cmpwi 29,1; bne 0f; mr 3,31; bl _s8009DAC0_1; cmplwi 3,1; ble 0f; mr 3,31; bl _s8009DAC0_2; lbz 0,0x8(1); stb 0,0x0(3); mr 3,31; bl _s8009DAC0_3; mr 30,3; bl _s8009DAC0_4; stb 3,0x1(30); lwz 9,0x0(31); stw 29,0x4(9); b 1f; 0:; mr 3,31; bl _s8009DAC0_5; bl _s8009DAC0_6; li 4,16; li 5,0; bl _s8009DAC0_7; lbz 4,0x8(1); li 5,1; extsb 4,4; bl _s8009DAC0_8; stw 3,0x0(31); 1:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8009DAC0_0();
extern "C" void _s8009DAC0_1();
extern "C" void _s8009DAC0_2();
extern "C" void _s8009DAC0_3();
extern "C" void _s8009DAC0_4();
extern "C" void _s8009DAC0_5();
extern "C" void _s8009DAC0_6();
extern "C" void _s8009DAC0_7();
extern "C" void _s8009DAC0_8();
extern "C" void f_8009DAC0() {}
