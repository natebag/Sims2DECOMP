// 0x8009D130 BString::compare_str(unsigned (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 27,4; mr 29,5; mr 31,6; mr 28,7; bl _s8009D130_0; cmplw 27,3; ble 0f; bl _s8009D130_1; 0:; cmplw 31,28; ble 1f; mr 31,28; 1:; mr 3,30; bl _s8009D130_2; cmpwi 3,0; bne 3f; cmpwi 29,0; beq 2f; bl _s8009D130_3; lbz 0,0x0(29); extsb 0,0; subf 3,0,3; b 4f; 2:; bl _s8009D130_4; b 4f; 3:; mr 3,30; bl _s8009D130_5; mr 4,29; mr 5,31; add 3,3,27; bl _s8009D130_6; mr. 3,3; bne 4f; mr 3,30; bl _s8009D130_7; subf 3,27,3; subf 3,28,3; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8009D130_0();
extern "C" void _s8009D130_1();
extern "C" void _s8009D130_2();
extern "C" void _s8009D130_3();
extern "C" void _s8009D130_4();
extern "C" void _s8009D130_5();
extern "C" void _s8009D130_6();
extern "C" void _s8009D130_7();
extern "C" void f_8009D130() {}
