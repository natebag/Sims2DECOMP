// 0x803A70D4 void (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 29,5; subf 0,3,31; srawi 0,0,2; cmpwi 0,16; ble 0f; addi 30,3,64; mr 4,30; bl _s803A70D4_0; mr 3,30; mr 4,31; mr 6,29; li 5,0; bl _s803A70D4_1; b 1f; 0:; mr 4,31; mr 5,29; bl _s803A70D4_2; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803A70D4_0();
extern "C" void _s803A70D4_1();
extern "C" void _s803A70D4_2();
extern "C" void f_803A70D4() {}
