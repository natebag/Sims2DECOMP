// 0x8009EF30 BString::copy(char (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,6; mr 28,4; mr 31,5; bl _s8009EF30_0; cmplw 29,3; ble 0f; bl _s8009EF30_1; 0:; mr 3,30; bl _s8009EF30_2; subf 3,29,3; cmplw 31,3; ble 1f; mr 3,30; bl _s8009EF30_3; subf 31,29,3; 1:; mr 3,30; bl _s8009EF30_4; cmpwi 3,0; beq 2f; mr 3,30; bl _s8009EF30_5; add 4,3,29; mr 5,31; mr 3,28; bl _s8009EF30_6; 2:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8009EF30_0();
extern "C" void _s8009EF30_1();
extern "C" void _s8009EF30_2();
extern "C" void _s8009EF30_3();
extern "C" void _s8009EF30_4();
extern "C" void _s8009EF30_5();
extern "C" void _s8009EF30_6();
extern "C" void f_8009EF30() {}
