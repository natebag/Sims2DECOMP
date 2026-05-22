// 0x801D6E68 PCTTarget::sell_dialog_selection_callback(int) (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; li 0,0; stw 0,0xf0(29); cmpwi 4,0; bne 3f; bl _s801D6E68_0; lwz 4,0x84(29); li 5,2; bl _s801D6E68_1; mr. 28,3; beq 3f; mr 3,28; bl _s801D6E68_2; lwz 31,0x0(3); cmpwi 31,0; beq 3f; lis 3,22797; ori 3,3,14928; bl _s801D6E68_3; li 3,0; bl _s801D6E68_4; lwz 9,0x4(31); mr 30,3; lwz 0,0x3cc(9); lha 3,0x3c8(9); mtspr 8,0; add 3,31,3; blrl; lis 9,-32697; add 4,30,3; lwz 0,0x6188(9); cmpwi 0,0; bne 0f; li 3,0; bl _s801D6E68_5; 0:; mr 3,29; bl _s801D6E68_6; stw 3,0x20c(29); lwz 9,0x4(31); lwz 0,0x424(9); lha 3,0x420(9); mtspr 8,0; add 3,31,3; blrl; xori 30,3,1; subfic 0,30,0; adde 30,0,30; mr 3,28; bl _s801D6E68_7; cmpwi 30,0; beq 1f; li 3,0; bl _s801D6E68_8; 1:; lwz 3,0x214(29); cmpwi 3,0; beq 2f; li 4,0; bl _s801D6E68_9; lwz 3,0x214(29); li 4,0; bl _s801D6E68_10; 2:; li 3,1; bl _s801D6E68_11; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801D6E68_0();
extern "C" void _s801D6E68_1();
extern "C" void _s801D6E68_2();
extern "C" void _s801D6E68_3();
extern "C" void _s801D6E68_4();
extern "C" void _s801D6E68_5();
extern "C" void _s801D6E68_6();
extern "C" void _s801D6E68_7();
extern "C" void _s801D6E68_8();
extern "C" void _s801D6E68_9();
extern "C" void _s801D6E68_10();
extern "C" void _s801D6E68_11();
extern "C" void f_801D6E68() {}
