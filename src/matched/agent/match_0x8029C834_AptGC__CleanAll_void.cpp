// 0x8029C834 AptGC::CleanAll(void) (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 3,-27600(13); bl _s8029C834_0; lwz 3,-23016(13); bl _s8029C834_1; lwz 30,-27028(13); li 0,1; stw 0,-27028(13); mr. 31,3; beq 1f; 0:; lwz 9,0x8(31); lwz 0,0x5c(9); lha 3,0x58(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x8(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; lwz 3,-23016(13); mr 4,31; bl _s8029C834_2; mr. 31,3; bne 0b; 1:; lwz 3,-27600(13); stw 30,-27028(13); bl _s8029C834_3; lwz 3,-23016(13); bl _s8029C834_4; mr. 31,3; beq 3f; 2:; lwz 9,0x8(31); lha 3,0x50(9); lwz 0,0x54(9); add 3,31,3; mtspr 8,0; blrl; lwz 3,-23016(13); mr 4,31; bl _s8029C834_5; mr. 31,3; bne 2b; 3:; lwz 3,-27600(13); bl _s8029C834_6; bl _s8029C834_7; bl _s8029C834_8; bl _s8029C834_9; bl _s8029C834_10; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8029C834_0();
extern "C" void _s8029C834_1();
extern "C" void _s8029C834_2();
extern "C" void _s8029C834_3();
extern "C" void _s8029C834_4();
extern "C" void _s8029C834_5();
extern "C" void _s8029C834_6();
extern "C" void _s8029C834_7();
extern "C" void _s8029C834_8();
extern "C" void _s8029C834_9();
extern "C" void _s8029C834_10();
extern "C" void f_8029C834() {}
