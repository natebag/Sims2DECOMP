// 0x802C6760 operator>>(EFile (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,4; mr 30,3; lwz 9,0x0(29); lha 3,0x10(9); lwz 0,0x14(9); add 3,29,3; mtspr 8,0; blrl; mr 31,3; 0:; lwz 9,0x28(30); addi 4,1,8; li 5,2; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lhz 0,0x8(1); sth 0,0x16(31); lwz 31,0x18(31); cmpwi 31,0; bne 0b; lwz 9,0x0(29); mr 4,30; lha 3,0x48(9); lwz 0,0x4c(9); add 3,29,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void f_802C6760() {}
