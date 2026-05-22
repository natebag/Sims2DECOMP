// 0x803082C4 EVibrate::StopAllVibration(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 31,0; 0:; rlwinm 4,31,0,24,31; mr 3,30; bl _s803082C4_0; mr 4,31; cmpwi 3,0; addi 31,31,1; beq 1f; lwz 3,-26524(13); bl _s803082C4_1; mr. 11,3; beq 1f; lwz 9,0x208(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; 1:; cmpwi 31,4; blt 0b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803082C4_0();
extern "C" void _s803082C4_1();
extern "C" void f_803082C4() {}
