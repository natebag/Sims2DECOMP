// 0x80116994 cHitMan::Init(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 0,0; stw 0,0x3c(31); li 30,-10; 0:; mr 4,30; mr 3,31; li 5,0; addi 30,30,1; bl _s80116994_0; cmpwi 30,1024; ble 0b; lwz 0,-24464(13); addi 9,31,16; li 11,0; li 30,1; stw 0,0x0(31); mr 3,9; stw 31,-24136(13); stw 11,0x4(9); stw 30,0x10(31); bl _s80116994_1; stw 30,0x1c(31); li 3,1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80116994_0();
extern "C" void _s80116994_1();
extern "C" void f_80116994() {}
