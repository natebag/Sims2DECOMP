// 0x8035D028 operator<<(EStream (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 11,4; mr 30,3; lwz 9,0x54(11); mr 4,30; lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_8035D028() {}
