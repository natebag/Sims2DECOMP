// 0x8014AD30 WantFear::Bookmark::IsDuplicateEvent(WantFear::Bookmark (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 3,0x4(31); bl _s8014AD30_0; lhz 30,0x0(3); lwz 3,0x4(29); bl _s8014AD30_1; lhz 0,0x0(3); li 3,0; cmpw 30,0; bne 0f; mr 3,31; bl _s8014AD30_2; mr 30,3; mr 3,29; bl _s8014AD30_3; xor 3,30,3; subfic 0,3,0; adde 3,0,3; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8014AD30_0();
extern "C" void _s8014AD30_1();
extern "C" void _s8014AD30_2();
extern "C" void _s8014AD30_3();
extern "C" void f_8014AD30() {}
