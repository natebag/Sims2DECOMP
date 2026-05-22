// 0x8013EC20 LogPersonTracker::SamePerson(cXPerson (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 29,0; li 9,0; mr. 31,4; beq 0f; lwz 11,0x0(31); lwz 9,0x4(11); lwz 0,0x36c(9); lha 3,0x368(9); mtspr 8,0; add 3,11,3; blrl; bl _s8013EC20_0; lwz 11,0x0(31); mr 29,3; lwz 9,0x4(11); lha 3,0x328(9); lwz 0,0x32c(9); add 3,11,3; mtspr 8,0; blrl; mr 9,3; 0:; lwz 0,0x0(30); li 3,0; cmpw 29,0; bne 1f; lha 0,0x4(30); xor 3,9,0; subfic 11,3,0; adde 3,11,3; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8013EC20_0();
extern "C" void f_8013EC20() {}
