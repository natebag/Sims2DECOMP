// 0x8013EA18 LogPersonTracker::SameInteraction(Interaction (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; mr 30,3; mr 3,29; li 28,0; bl _s8013EA18_0; mr. 31,3; li 9,0; li 11,-1; beq 0f; lwz 9,0x4(31); lwz 0,0x36c(9); lha 3,0x368(9); mtspr 8,0; add 3,31,3; blrl; bl _s8013EA18_1; bl _s8013EA18_2; lwz 9,0x4(31); mr 28,3; lha 3,0x328(9); lwz 0,0x32c(9); add 3,31,3; mtspr 8,0; blrl; lwz 11,0x14(29); mr 9,3; 0:; lwz 0,0x8(30); li 3,0; cmpw 28,0; bne 1f; lha 0,0xc(30); cmpw 9,0; bne 1f; lwz 0,0x10(30); xor 3,11,0; subfic 9,3,0; adde 3,9,3; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8013EA18_0();
extern "C" void _s8013EA18_1();
extern "C" void _s8013EA18_2();
extern "C" void f_8013EA18() {}
