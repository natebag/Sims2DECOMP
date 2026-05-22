// 0x8013FE84 cXPersonImpl::SetSimMemory(cXPerson (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,3; mr 29,4; lwz 11,0x4(28); mr 27,5; mr 26,6; lwz 9,0x4(11); lwz 0,0x1b4(9); lha 3,0x1b0(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x4(29); mr 30,3; lwz 0,0x1b4(9); lha 3,0x1b0(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x0(28); mr 5,3; mr 4,30; mr 6,27; lwz 11,0x58(9); mr 7,26; lwz 9,0x0(11); lha 3,0x1b8(9); lwz 0,0x1bc(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void f_8013FE84() {}
