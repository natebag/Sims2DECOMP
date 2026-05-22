// 0x802C7F04 operator>>(EStream (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 5,0x4(4); lwz 9,0x18(30); lwz 4,0x0(4); lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_802C7F04() {}
