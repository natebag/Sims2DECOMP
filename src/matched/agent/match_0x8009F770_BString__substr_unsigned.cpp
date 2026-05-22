// 0x8009F770 BString::substr(unsigned (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,4; mr 29,3; mr 30,5; mr 27,6; mr 3,31; bl _s8009F770_0; cmplw 30,3; ble 0f; bl _s8009F770_1; 0:; mr 3,31; bl _s8009F770_2; cmpwi 3,0; beq 3f; mr 3,31; bl _s8009F770_3; add 28,3,30; mr 3,31; bl _s8009F770_4; subf 3,30,3; cmplw 27,3; ble 1f; mr 3,31; bl _s8009F770_5; subf 5,30,3; b 2f; 1:; mr 5,27; 2:; mr 4,28; mr 3,29; bl _s8009F770_6; b 4f; 3:; mr 3,29; bl _s8009F770_7; 4:; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8009F770_0();
extern "C" void _s8009F770_1();
extern "C" void _s8009F770_2();
extern "C" void _s8009F770_3();
extern "C" void _s8009F770_4();
extern "C" void _s8009F770_5();
extern "C" void _s8009F770_6();
extern "C" void _s8009F770_7();
extern "C" void f_8009F770() {}
